//
// Created by Ama on 4/4/2023.
//

/**

@file UserService.h
@brief This file contains the declaration of the UserService class. This class is responsible for managing and updating
   the status of users and their quests.
*/

#include "UserService.h"

UserService::UserService(TemplatedRepository<Quest> *quests, TemplatedRepository<UserStatus> *userStatus) :
        quests{quests}, userStatus{userStatus} {}

UserService::~UserService() = default;

void UserService::addQuest(int id,
                           const std::string &text,
                           const std::string &date,
                           const std::string &time,
                           const std::string &username,
                           size_t tokens) {

    Quest newQuest = Quest(id, text, date, time, tokens, username, false);
    this->quests->addElement(newQuest);
    this->updateUserStatus(username, -tokens, 0, 1, 0);
    this->notify();
}

UserStatus UserService::updateUserStatus(const std::string &username,
                                         size_t tokens,
                                         size_t solvedQuest,
                                         size_t postedQuest,
                                         size_t rating) {

    UserStatus status = getUserStatus(username);
    this->userStatus->removeElement(status);

    status.setUsername(status.getUsername());
    status.setTokens(status.getTokens() + tokens);
    status.setQuestsSolved(status.getQuestsSolved() + solvedQuest);
    status.setQuestsPosted(status.getQuestsAsked() + postedQuest);
    size_t score = (status.getScore() + rating) / status.getQuestsSolved();
    status.setScore(score);

    this->userStatus->addElement(status);
    this->notify();
    return status;
}

std::vector<Quest> UserService::getAllQuests() {
    return quests->getAll();
}

UserStatus UserService::getUserStatus(const std::string &username) {
    for (const auto &status: this->userStatus->getAll()) {
        if (status.getUsername() == username)
            return status;
    }
    throw std::runtime_error("User status not found.");
}

std::vector<Quest> UserService::getUserQuests(const std::string &quest1) {
    std::vector<Quest> myQuests;

    for (const auto &quest: getAllQuests()) {
        if (quest.getUsername() == quest1)
            myQuests.push_back(quest);
    }

    std::sort(myQuests.begin(), myQuests.end(), [](const Quest &quest1, const Quest &quest2) {
        return quest1 <= quest2;
    });

    return myQuests;
}

std::vector<Quest> UserService::getQuestsFeed(const std::string &name) {
    std::vector<Quest> feed;

    for (const auto &quest: getAllQuests()) {
        if (quest.getUsername() != name && !quest.isCompleted())
            feed.push_back(quest);
    }
    std::sort(feed.begin(), feed.end(), [](const Quest &quest1, const Quest &quest2) {
        return quest1 <= quest2;
    });

    return feed;
}

void UserService::deleteQuest(size_t id, const std::string &username) {
    Quest questDelete;
    for (const auto &quest: getUserQuests(username)) {
        if (quest.getId() == id) {
            questDelete = quest;
            break;
        }
    }

    this->quests->removeElement(questDelete);
    this->notify();
}

Quest UserService::answerQuest(const std::string &userAnswered, size_t questId) {
    Quest questAnswered;
    for (const auto &quest: getAllQuests()) {
        if (quest.getId() == questId) {
            questAnswered = quest;
            break;
        }
    }

    this->quests->removeElement(questAnswered);
    questAnswered.setCompleted(true);
    this->quests->addElement(questAnswered);
    this->updateUserStatus(userAnswered, questAnswered.getTokens(), 1, 0, 0);
    this->notify();
    return questAnswered;
}



