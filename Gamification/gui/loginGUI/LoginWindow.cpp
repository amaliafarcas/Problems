//
// Created by Ama on 4/10/2023.
//


#include <QMessageBox>
#include "LoginWindow.h"
#include "../userGUI/UserWindow.h"


LoginWindow::LoginWindow(UserService* service, LoginService* userService, QMainWindow *parent) :
       service{service},  userService{userService}, QMainWindow{parent}{

    ui.setupUi(this);
    connectSignalsAndSlots();
}

LoginWindow::~LoginWindow() = default;


void LoginWindow::connectSignalsAndSlots() {
    QObject::connect(this->ui.pushButtonLogIn,
                     &QPushButton::clicked,
                     this,
                     &LoginWindow::logIn);
}

void LoginWindow::logIn(){
    std::string username = this->ui.lineEditUsername->text().toStdString();
    std::string password = this->ui.lineEditPassword->text().toStdString();

    User user = User(username, password);

    if(userService->validateUser(user)) {
        auto *userWindow = new UserWindow{service, user};
        userWindow->setWindowTitle(QString::fromStdString(user.getName()));
        service->addObserver(userWindow);
        userWindow->show();

        this->ui.lineEditUsername->clear();
        this->ui.lineEditPassword->clear();
    }
    else{
        QMessageBox messageBox;
        messageBox.setText("Invalid! Incorrect credentials");
        messageBox.exec();
        return;
    }
}
