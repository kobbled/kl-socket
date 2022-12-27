use std::io::{self, Read, Write};
use std::{thread, time::Duration};
use std::net::TcpStream;

fn main() -> io::Result<()> {
    let ip = "127.0.0.1";
    let port = 65432;

    // Connect to the server
    let mut stream = TcpStream::connect(format!("{}:{}", ip, port))?;
    //if stream is ok
    println!("Connected to {}:{}", ip, port);

    println!("reading...");
    // write a while true loop
    loop {
      //send keyboard input from a user to the server
      let mut input = String::new();
      io::stdin().read_line(&mut input)?;
      
      // Send the input to the server
      stream.write_all(input.as_bytes())?;

      //read the response from the server
      let mut buffer = [0; 1024];
      stream.read(&mut buffer)?;
      let response = String::from_utf8_lossy(&buffer[..]);
      println!("response: {}", response);

      thread::sleep(Duration::from_millis(500));
    }
}