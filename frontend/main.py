import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QDialog, QApplication, QMessageBox
from PyQt5.uic import loadUi
import socket
import mysql.connector as con

import socket

def establish_connection():
    HOST = '127.0.0.1'
    PORT = 8080

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))

    print('Connected...')

    # s.send("Nima GAP".encode())

    return s

def send_request(data: str):
    s = establish_connection()

    s.send(data.encode())

    s_name = s.recv(1024)
    s_name = s_name.decode()

    print(f'RESPONSE: {s_name}')

    s.close()


def login(email: str, password: str):
    s = establish_connection()

    req = f'login {email} {password}'

    s.send(req.encode())

    s_res = s.recv(32)
    s_res = s_res.decode()

    # print(f'RESPONSE: {s_res}')

    s.close()

    return s_res

current_user_email = ""

class LoginApp(QDialog):
    def __init__(self):
        super(LoginApp, self).__init__()
        loadUi("login.ui", self)
        
        self.log_login_butt.clicked.connect(self.login)
        self.log_reg_butt.clicked.connect(self.show_reg)

    def login(self):
        email = self.log_email_line.text()
        password = self.log_pass_line.text()

        if email.strip() == "" or password.strip() == "":
            self.warning.setText("No empty fields are allowed")
            return
        

        res = login(email, password)

        self.log_email_line.setText("")
        self.log_pass_line.setText("")

        if res == "201":
            QMessageBox.information(self, "Login Ouput", "Welcome back!")
            global current_user_email
            current_user_email = email
            widget.setCurrentIndex(2)
        elif res == "403":
            self.warning.setText("Incorrect email or password")
        else:
            self.warning.setText("Server error")

        # if result:
        #     QMessageBox.information(self, "Login Ouput", "Welcome back!")
        #     global current_user_email
        #     current_user_email = email
        #     widget.setCurrentIndex(2)
        # else:
        #     self.warning.setText("Incorrect email or password")

    def show_reg(self):
        widget.setCurrentIndex(1)


class RegApp(QDialog):
    def __init__(self):
        super(RegApp, self).__init__()
        loadUi("signup.ui", self)

        self.reg_signup_butt.clicked.connect(self.register)
        self.reg_login_butt.clicked.connect(self.show_login)

    def register(self):
        f_name = self.first_name.text()
        l_name = self.last_lame.text()
        email = self.reg_email_line.text()
        password = self.reg_pass_1.text()
        confirm_password = self.reg_pass_2.text()

        credentials = [f_name, l_name, email, password, confirm_password]
        for item in credentials:
            if item.strip() == "":
                self.warning.setText("No empty fields are allowed")
                return
        
        if password != confirm_password:
            self.warning.setText("Passwords do not match")
            return
        
        db = con.connect(
            host="localhost", 
            user="test_user", 
            password="test_password", 
            db="test_db",
            auth_plugin='mysql_native_password'
        )

        cursor = db.cursor()
        cursor.execute(f"select * from users where email='{email}'")
        result = cursor.fetchone()

        self.first_name.setText("")
        self.last_lame.setText("")
        self.reg_email_line.setText("")
        self.reg_pass_1.setText("")
        self.reg_pass_2.setText("")

        if result:
            self.warning.setText("Account with this email already exists")
            return

        cursor.execute(f"insert into users (first_name, last_name, email, password)"
            f"values ('{f_name}','{l_name}','{email}', '{password}')")
        db.commit()
        
        QMessageBox.information(self, "Sign Up", "Account has been created! Log in.")
        widget.setCurrentIndex(0)

    def show_login(self):
        widget.setCurrentIndex(0)


class HomeApp(QDialog):
    def __init__(self):
        super(HomeApp, self).__init__()
        loadUi("home.ui", self)
        global current_user_email
        
        self.current_user.setText(current_user_email)
        self.logout_butt.clicked.connect(self.logout)
        self.clear_butt.clicked.connect(self.clear)
        self.submit_butt.clicked.connect(self.submit)

    def clear(self):
        self.input_text.setText("")

    def logout(self):
        self.input_text.setText("")
        self.plag_output.setText("")
        current_user_email = ""
        widget.setCurrentIndex(0)

    def submit(self):
        global current_user_email

        input_text = self.input_text.toPlainText()
        if input_text.strip() == "":
            return

        db = con.connect(
            host="localhost", 
            user="test_user", 
            password="test_password", 
            db="test_db",
            auth_plugin='mysql_native_password'
        )
        print("<<<<<<<<<<<<<<<<<<<<< ", current_user_email)
        cursor = db.cursor()
        cursor.execute(f"insert into papers (content, user_id) values "
            f"('{input_text}', (select id from users where email='{current_user_email}'))"
        )
        db.commit()

        # produce plagiarism info
        output = "adfsadf asdf asdf afd"
        self.plag_output.setText(output)
        

if __name__ == "__main__":

    # s = service.establish_connection()

    # service.send_request("Hello")
    
    # res = login("saidov", "sosecure")
    # print(res)

    app = QApplication(sys.argv)
    widget = QtWidgets.QStackedWidget()

    loginForm = LoginApp()
    regForm = RegApp()
    homePage = HomeApp()

    widget.addWidget(loginForm)
    widget.addWidget(regForm)
    widget.addWidget(homePage)

    widget.setCurrentIndex(0)
    widget.setFixedWidth(1000)
    widget.setFixedHeight(800)

    widget.show()
    app.exec_()
