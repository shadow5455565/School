import socket
passw=6547

def reorderer(text,psw):
        if len(psw) < 4:
                return "ERROR"
                exit
        textfin=""
        ist=0
        textr=""
        for i in range(1, len(text)+1):
            if ist==0:
                textr= textr + chr(ord(text[len(text)-i])-int(psw[1]))
                ist=1
            else:
                textr= textr + chr(ord(text[len(text)-i])-int(psw[2]))
                ist=0
        text=""
        for a in range(0, len(textr)):
            text=text+ chr(ord(textr[a])+a-int(psw[3]))
            textfin=textfin + chr(ord(text[a])+int(psw[0]))
        return textfin

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host=socket.gethostname()
port=9009

try:
        s.connect((host,port))
        usr = input("Inserisci nome utente:")
        while True:
                text=input("Inserisci il messaggio:")
                texte=reorderer(text, passw)
                mex= "[" + usr + "]" + texte 
                s.send(mex.encode('ascii'))

        input("Press enter to close...")
        s.close()
except:
        print("Connection error, server may be down")
