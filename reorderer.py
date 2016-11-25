__fill__="\n\n####################\n\n"
__author__="CYbo"
__version__="1.0"
__desc__="Text crypter-decrypter \n"
__help__="<LETTER> <FUNCTION> \n E      used for encoding \n D     used for decoding \n e      used for exit \n h     generates this page \n q     same function as e \n s      if added to D or E it uses the local variable for storing the text \n"
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
def dereorderer(text,psw):
        if len(psw) < 4:
                return "ERROR"
                exit
        textfin=""
        if len(text)%2==0:
            ist=1
        else:
            ist=0
        textd=""
        for i in range(0, len(text)):
            textfin=textfin + chr(ord(text[i])-int(psw[0]))    
            textd=textd+chr(ord(textfin[i])-i+int(psw[3]))
        text=""
        for a in range(1, len(textd)+1):
            if ist==0:
                text=text+ chr(ord(textd[len(textd)-a])+int(psw[1]))
                ist=1
            else:
                text=text+ chr(ord(textd[len(textd)-a])+int(psw[2]))
                ist=0
        return text
tmp=""
while True:
        func=input("Insert command function:")
        if func[0] =='E':
                text=input("Insert the text:")
                psw=input("Insert the 4 pin digit:")
                print("Your initial text:" + text)
                enc=reorderer(text,psw)
                print("FINAL ENCODED:"+enc)
                if len(func)==2:
                        if func[1]=="s":
                                tmp=enc
                                print("The encoded text is stored in the local variable")
        elif func[0] == 'D':
                if len(func)==2:
                        if func[1]=='s':
                                text=tmp
                else:
                        text=input("Insert the text:")
                psw=input("Insert the 4 pin digit:")
                print("Your initial encoded text:" + text)
                print("FINAL DECODE:"+dereorderer(text,psw))
        elif func[0] == 'e' or func == 'q':
                print("Quitting...")
                break
        elif func[0]=='h':
                print(__fill__)
                print("Author: "+__author__)
                print("Version: "+__version__)
                print("Description:"+__desc__)
                print("Generated help page:\n\n"+__help__)
                print(__fill__)
        else:
                print("#Command not recognized try h for more info#")
exit()
