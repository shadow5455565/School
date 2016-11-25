import socket
import threading

class ThreadedServer(object):
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sock.bind((self.host, self.port))
        
    def listen(self):
        clients_lock=threading.Lock()
        clients = set()
        print("Listening on socket...")
        self.sock.listen(5)
        while True:
            client, address = self.sock.accept()
            print("Got a connection from %s" % str(address))
            with clients_lock:
                clients.add(client)
            threading.Thread(target = self.listenToClient,args = (client,address,clients,clients_lock)).start()

    def listenToClient(self, client, address, clients, clients_lock):
        size = 1024
        while True:
            try:
                data = client.recv(size)
                print("Recived client data from %s" + str(address))
                if data:
                    with clients_lock:
                        for c in clients:
                            c.sendall(data)
                else:
                    raise error('Client disconnected')
            except:
                client.close()
                return False

if __name__ == "__main__":
    port_num = input("Port? ")
    ThreadedServer('0.0.0.0',int(port_num)).listen()
