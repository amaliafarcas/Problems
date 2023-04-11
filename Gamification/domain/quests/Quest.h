//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_QUEST_H
#define INC_2023_INTERNSHIP_ACCESA_QUEST_H
#pragma once
#include "iostream"
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

class Quest {
private:
    size_t id;
    std::string text;
    std::string date;
    std::string time;
    size_t tokens;
    std::string username;
    bool completed;
public:
    Quest()=default;
    Quest(size_t id, const std::string &text, const std::string &date, const std::string &time, size_t tokens,
          const std::string &username, bool completed);

    virtual ~Quest();

    size_t getId() const;

    void setId(size_t id);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::string &getTime() const;

    void setTime(const std::string &time);

    size_t getTokens() const;

    void setTokens(size_t tokens);

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    bool isCompleted() const;

    void setCompleted(bool completed);

    bool operator==(const Quest &rhs) const;

    bool operator!=(const Quest &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Quest &quest);

    friend std::istream &operator>>(std::istream &is, Quest &quest);

    bool operator<=(const Quest& other) const;
};


#endif //INC_2023_INTERNSHIP_ACCESA_QUEST_H
