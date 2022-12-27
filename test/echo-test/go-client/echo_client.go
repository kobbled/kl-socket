package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
	"time"
)

func main() {
	ip := "127.0.0.1"
	port := 65432

	// Connect to the server
	conn, err := net.Dial("tcp", fmt.Sprintf("%s: %d", ip, port))
	fmt.Printf("Connecting to %s:%d ... \n", ip, port)
	if err != nil {
		log.Println(err)
		return
	}
	defer conn.Close()

	fmt.Printf("reading... \n")

	for {
		//send keyboard input from a user to the server
		// read in input from stdin
		reader := bufio.NewReader(os.Stdin)
		text, _ := reader.ReadString('\n')

		// Send a message
		fmt.Fprintf(conn, text)

		// Receive and print the response
		response, err := bufio.NewReader(conn).ReadString('\n')
		if err != nil {
			fmt.Println(err)
			return
		}
		fmt.Print("response: ", response)

		time.Sleep(2 * time.Second)

		defer func() {
			if r := recover(); r != nil {
				log.Println("Error:", r)
			}
		}()
	}
}
