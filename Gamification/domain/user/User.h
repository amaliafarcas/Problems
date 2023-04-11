//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_USER_H
#define INC_2023_INTERNSHIP_ACCESA_USER_H
#pragma once

#include "iostream"
#include "fstream"

class User {
private:
    std::string name;
    std::string password;

public:
    User() = default;

    User(const std::string &name, const std::string &password);

    virtual ~User();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    friend std::istream &operator>>(std::istream &is, User &p);

    bool operator==(const User &rhs) const;

    bool operator!=(const User &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const User &user);

};


#endif //INC_2023_INTERNSHIP_ACCESA_USER_H
