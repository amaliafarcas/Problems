//
// Created by Ama on 4/4/2023.
//

#include "User.h"

User::User(const std::string &name,
           const std::string &password) :
           name(name),
           password(password) {}

User::~User() = default;

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    User::password = password;
}

std::istream &operator>>(std::istream &is, User &p) {
    return is >> p.name >> p.password;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << " " << user.name << " " << user.password << "\n";
    return os;
}

bool User::operator==(const User &rhs) const {
    return name == rhs.name && password == rhs.password;
}

bool User::operator!=(const User &rhs) const {
    return !(rhs == *this);
}

