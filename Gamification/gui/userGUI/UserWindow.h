//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_USERWINDOW_H
#define INC_2023_INTERNSHIP_ACCESA_USERWINDOW_H
#pragma once
#include <QWidget>
#include "../../service/userService/UserService.h"
#include "QMainWindow"
#include "ui_userwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QMainWindow, public Observer{
Q_OBJECT

public:
    explicit UserWindow(UserService* service, const User& user, QMainWindow *parent = nullptr);

    ~UserWindow() override;

    void update() override;

    int getSelectedIndex();

    void connectSignalsAndSlots();
    void populateUserQuestsList();
    void populateQuestsFeedList();
    void populateBadgesList();
    void populateTokens();
    void populateRating();

private:
    Ui::UserWindow ui;
    UserService* service;
    User user;

    void addQuest();

    int getSelectedIndex(QListWidget listWidget);

    static int getSelectedIndex(QListWidget *listWidget);

    void deleteUserQuest();

    void answerQuest();

    size_t generateQuestId();

    static std::basic_string<char> getLocalTime();

    void populateAskedQuests();

    void populateSolvedQuests();
};


#endif //INC_2023_INTERNSHIP_ACCESA_USERWINDOW_H
