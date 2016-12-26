import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
port=9009
s.connect((host,port))
while True:
                messg=s.recv(1024).decode('utf-8')
                print(messg)
input("Press enter to close...")
s.close()
