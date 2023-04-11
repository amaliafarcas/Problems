//
// Created by Ama on 4/5/2023.
//

#include "UserStatus.h"

UserStatus::UserStatus(const std::string &username,
                       size_t tokens,
                       size_t score,
                       size_t questsPosted,
                       size_t questsSolved) :
                       username(username),
                       tokens(tokens),
                       score(score),
                       questsPosted(questsPosted),
                       questsSolved(questsSolved) {}

UserStatus::~UserStatus() = default;

const std::string &UserStatus::getUsername() const {
    return username;
}

void UserStatus::setUsername(const std::string &username) {
    UserStatus::username = username;
}

size_t UserStatus::getTokens() const {
    return tokens;
}

void UserStatus::setTokens(size_t tokens) {
    UserStatus::tokens = tokens;
}

size_t UserStatus::getScore() const {
    return score;
}

void UserStatus::setScore(size_t score) {
    UserStatus::score = score;
}

size_t UserStatus::getQuestsAsked() const {
    return questsPosted;
}

void UserStatus::setQuestsPosted(size_t questsPosted) {
    UserStatus::questsPosted = questsPosted;
}

size_t UserStatus::getQuestsSolved() const {
    return questsSolved;
}

void UserStatus::setQuestsSolved(size_t questsSolved) {
    UserStatus::questsSolved = questsSolved;
}

bool UserStatus::operator==(const UserStatus &rhs) const {
    return username == rhs.username &&
           tokens == rhs.tokens &&
           score == rhs.score &&
           questsPosted == rhs.questsPosted &&
           questsSolved == rhs.questsSolved;
}

bool UserStatus::operator!=(const UserStatus &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const UserStatus &status) {
    os << status.username << " "
    << status.tokens << " "
    << status.score<< " "
    << status.questsPosted << " "
    << status.questsSolved<<"\n";
    return os;
}

std::istream &operator>>(std::istream &is, UserStatus &status) {
    return is>>status.username>>
    status.tokens>>
    status.score>>
    status.questsPosted>>
    status.questsSolved;
}
