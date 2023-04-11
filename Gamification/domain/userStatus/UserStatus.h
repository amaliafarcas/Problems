//
// Created by Ama on 4/5/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_USERSTATUS_H
#define INC_2023_INTERNSHIP_ACCESA_USERSTATUS_H

#include "iostream"

class UserStatus {
private:
    std::string username;
    size_t tokens;
    size_t score;
    size_t questsPosted;
    size_t questsSolved;
public:
    UserStatus() = default;

    UserStatus(const std::string &username, size_t tokens, size_t score, size_t questsPosted, size_t questsSolved);

    virtual ~UserStatus();

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    size_t getTokens() const;

    void setTokens(size_t tokens);

    size_t getScore() const;

    void setScore(size_t score);

    size_t getQuestsAsked() const;

    void setQuestsPosted(size_t questsPosted);

    size_t getQuestsSolved() const;

    void setQuestsSolved(size_t questsSolved);

    bool operator==(const UserStatus &rhs) const;

    bool operator!=(const UserStatus &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const UserStatus &status);

    friend std::istream &operator>>(std::istream &is, UserStatus &status);

};


#endif //INC_2023_INTERNSHIP_ACCESA_USERSTATUS_H
