import socket
host = "127.0.0.1"
port = 6767
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
sock.connect((host,port))
while True:
    data = input("enter message for server")
    if data=="close":
        sock.close
        break;
    sock.sendto(bytes(data,"utf-8"),(host,port))