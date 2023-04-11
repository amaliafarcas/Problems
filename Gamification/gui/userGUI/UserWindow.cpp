//
// Created by Ama on 4/4/2023.
//


#include "UserWindow.h"
#include "QMessageBox"
#include "iostream"
#include <chrono>
#include <ctime>
#include <iomanip>


UserWindow::UserWindow(UserService *service, const User &user, QMainWindow *parent) :
                        service{service}, user{user}, QMainWindow{parent} {

    ui.setupUi(this);

    populateBadgesList();
    populateUserQuestsList();
    populateQuestsFeedList();
    populateTokens();
    //populateRating();
    populateAskedQuests();
    populateSolvedQuests();

    this->connectSignalsAndSlots();
}

UserWindow::~UserWindow() = default;

void UserWindow::update() {
    populateBadgesList();
    populateUserQuestsList();
    populateQuestsFeedList();
    populateTokens();
    //populateRating();
    populateAskedQuests();
    populateSolvedQuests();
}

void UserWindow::connectSignalsAndSlots() {
    QObject::connect(this->ui.pushButtonAddQuest,
                     &QPushButton::clicked,
                     this,
                     &UserWindow::addQuest);
    QObject::connect(this->ui.pushButtonDeleteQuest,
                     &QPushButton::clicked,
                     this,
                     &UserWindow::deleteUserQuest);
    QObject::connect(this->ui.pushButtonSolveQuest,
                     &QPushButton::clicked,
                     this,
                     &UserWindow::answerQuest);
}

int UserWindow::getSelectedIndex(QListWidget *listWidget) {
    QModelIndexList selectedIndices = listWidget->selectionModel()->selectedIndexes();

    if (selectedIndices.empty()) {
        return -1;
    }

    return selectedIndices.at(0).row();
}

void UserWindow::deleteUserQuest() {
    auto index = this->getSelectedIndex(this->ui.listWidgetUserQuests);

    if (index != -1) {
        Quest quest = service->getUserQuests(user.getName())[index];
        service->deleteQuest(quest.getId(), user.getName());
        this->update();
    }
}

void UserWindow::populateUserQuestsList() {
    this->ui.listWidgetUserQuests->clear();

    std::vector<Quest> quests = this->service->getUserQuests(user.getName());

    for (const auto &quest: quests) {
        QString questString = QString::fromStdString(
                std::to_string(
                        quest.getId()) + " " +
                            quest.getText() + " " +
                            quest.getDate() + " " +
                            quest.getTime() + " | Reward: " +
                            std::to_string(quest.getTokens()));

        this->ui.listWidgetUserQuests->addItem(questString);
    }
}

void UserWindow::populateQuestsFeedList() {
    this->ui.listWidgetFeedQuests->clear();

    std::vector<Quest> quests = this->service->getQuestsFeed(user.getName());
    for (const auto &quest: quests) {

        QString questString = QString::fromStdString(
                std::to_string(
                        quest.getId()) + " " +
                            quest.getText() + " " +
                            quest.getDate() + " " +
                            quest.getTime() + " | Reward: " +
                            std::to_string(quest.getTokens()));

        this->ui.listWidgetFeedQuests->addItem(questString);
    }
}

void UserWindow::populateBadgesList() {

    this->ui.listWidgetBadges->clear();

/*  std::vector<Quest> quests = this->service->getQuestsFeed(user.getName());
    for (const auto &quest: quests) {

        QString questString = QString::fromStdString(
                std::to_string(
                        quest.getId()) + " " +
                            quest.getText() + " " +
                            quest.getDate() + " " +
                            quest.getTime() + " | Reward: " +
                            std::to_string(quest.getTokens()));

        this->ui.listWidgetFeedQuests->addItem(questString);
    }*/
}

void UserWindow::populateTokens() {
    UserStatus status = service->getUserStatus(user.getName());
    this->ui.lineEditTokens->setText(QString::number(status.getTokens()));
    this->ui.lineEditTokens->setReadOnly(true);
}

void UserWindow::populateRating() {
    UserStatus status = service->getUserStatus(user.getName());
    this->ui.lineEditRating->setText(QString::number(status.getScore()));
    this->ui.lineEditRating->setReadOnly(true);
}

void UserWindow::populateAskedQuests() {
    UserStatus status = service->getUserStatus(user.getName());
    this->ui.lineEditAsked->setText(QString::number(status.getQuestsAsked()));
    this->ui.lineEditAsked->setReadOnly(true);
}

void UserWindow::populateSolvedQuests() {
    UserStatus status = service->getUserStatus(user.getName());
    this->ui.lineEditSolved->setText(QString::number(status.getQuestsSolved()));
    this->ui.lineEditSolved->setReadOnly(true);
}

void UserWindow::addQuest() {
    std::string text = this->ui.lineEditTextNewQuest->text().toStdString();
    int tokens = this->ui.lineEditTokensNewQuest->text().toInt();
    UserStatus status = service->getUserStatus(user.getName());

    if (text.empty()) {
        QMessageBox messageBox;
        messageBox.setText("Invalid! Empty text");
        messageBox.exec();
        return;
    }
    if (tokens <= 0) {
        QMessageBox messageBox;
        messageBox.setText("Invalid! You must give at least 1 token for this task");
        messageBox.exec();
        return;
    }
    if (tokens > status.getTokens()) {
        QMessageBox messageBox;
        messageBox.setText("Invalid! You don`t have enough tokens.");
        messageBox.exec();
        return;
    }

    std::string date_time = getLocalTime();
    // Extract the date and time from the string
    //std::string date = date_time.substr(0, 10); // first 10 characters
    //std::string time = date_time.substr(11, 5); // next 5 characters

    this->service->addQuest(generateQuestId(),
                            text,
                            date_time.substr(0, 10),
                            date_time.substr(11, 5),
                            user.getName(),
                            tokens);
    this->update();
}

std::string UserWindow::getLocalTime() {
    // Get the current time
    auto now = std::chrono::system_clock::now();

    // Convert the current time to a time_t object
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // Convert the time_t object to a string representation of the date and time
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%d.%m.%Y %H:%M");
    std::string date_time = ss.str();
    return date_time;
}

size_t UserWindow::generateQuestId() {
    int unique = 1;
    size_t questId;

    while (unique == 1) {
        unique = 0;
        questId = rand() % 10000 + 1;
        for (const auto &quest: service->getAllQuests()) {
            if (quest.getId() == questId) {
                unique = 1;
                break;
            }
        }
    }

    return questId;
}

void UserWindow::answerQuest() {
    auto index = this->getSelectedIndex(this->ui.listWidgetFeedQuests);

    if (index != -1) {
        Quest quest = service->getQuestsFeed(user.getName())[index];
        std::string text = this->ui.lineEditTextSolveQuest->text().toStdString();

        if (text.empty()) {
            QMessageBox messageBox;
            messageBox.setText("Invalid! Empty text");
            messageBox.exec();
            return;
        }

        this->service->answerQuest(this->user.getName(), quest.getId());
        this->update();
    }

}
