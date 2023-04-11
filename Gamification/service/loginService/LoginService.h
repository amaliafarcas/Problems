//
// Created by Ama on 4/10/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_LOGINSERVICE_H
#define INC_2023_INTERNSHIP_ACCESA_LOGINSERVICE_H
#pragma once

#include "../../repository/TemplatedRepository.h"

class LoginService {
private:
    TemplatedRepository<User> *users;
public:

    LoginService(TemplatedRepository<User> *users);

    virtual ~LoginService();

    bool validateUser(const User &possibleUser);
};


#endif //INC_2023_INTERNSHIP_ACCESA_LOGINSERVICE_H
