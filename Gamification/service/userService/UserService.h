//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_USERSERVICE_H
#define INC_2023_INTERNSHIP_ACCESA_USERSERVICE_H
#pragma once

#include "iostream"
#include "vector"
#include "../../repository/TemplatedRepository.h"
#include "../../observer/Observer.h"


class UserService : public Subject {
public:
    UserService(TemplatedRepository<Quest>* quests, TemplatedRepository<UserStatus>* userStatus);

    ~UserService();

    void addQuest(int id, const std::string& text, const std::string& date, const std::string& time, const std::string& username, size_t tokens);

    std::vector<Quest> getAllQuests();

    std::vector<Quest> getUserQuests(const std::string& quest1);

    std::vector<Quest> getQuestsFeed(const std::string& name);

    UserStatus getUserStatus(const std::string& username);

    void deleteQuest(size_t id, const std::string &username);

    UserStatus updateUserStatus(const std::string& username, size_t tokens, size_t solvedQuest, size_t postedQuest, size_t rating);

    Quest answerQuest(const std::string& userAnswered, size_t questId);

private:
    TemplatedRepository<Quest>* quests;
    TemplatedRepository<UserStatus>* userStatus;

};


#endif //INC_2023_INTERNSHIP_ACCESA_USERSERVICE_H
