import socket
import time

ip = "127.0.0.1"
port = 65432

def main():

  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    print("Connecting to {}:{} ...".format(ip, port))
    sock.connect((ip, port))
    print('reading')
    try:
      while True:
        try:
          s = bytearray(input(), "utf8")
          sock.sendall(s)
          data = sock.recv(1024)          
          print('Response:', data.decode('ascii'))
          time.sleep(0.3)
        except socket.error:
          pass
    except KeyboardInterrupt:
      sock.close()

if __name__ == '__main__':
  main()