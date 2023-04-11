//
// Created by Ama on 4/10/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_LOGINWINDOW_H
#define INC_2023_INTERNSHIP_ACCESA_LOGINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "ui_LoginWindow.h"
#include "../../service/userService/UserService.h"
#include "../../service/loginService/LoginService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow {
Q_OBJECT

public:
    explicit LoginWindow(UserService *service, LoginService *userService, QMainWindow *parent = nullptr);

    ~LoginWindow() override;

private:
    Ui::LoginWindow ui;
    UserService *service;
    LoginService *userService;

    void connectSignalsAndSlots();

    void logIn();
};


#endif //INC_2023_INTERNSHIP_ACCESA_LOGINWINDOW_H
