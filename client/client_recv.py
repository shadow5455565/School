import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
port=9009
s.connect((host,port))
psw=input("Server password:")
s.send(psw.encode('ascii'))
messg=s.recv(1024).decode('ascii')
print(messg)
messg=s.recv(1024).decode('ascii')
print(messg)
while True:
                messg=s.recv(1024).decode('ascii')
                print(messg)
input("Press enter to close...")
s.close()
