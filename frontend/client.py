import socket 

def establish_connection():
    HOST = '127.0.0.1'
    PORT = 8080

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))

    print('Connected...')

    s.send("salom".encode())

    # msg_length = s.recv(64).decode()
    # msg = s.recv(msg_length).decode()


    # print(f'RESPONSE: {msg}')

    return s


establish_connection()