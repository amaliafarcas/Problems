//
// Created by Ama on 4/10/2023.
//

/**
 @file LoginService.h
 @brief This file contains the declaration of the LoginService class.
 *This class is responsible for validating a user's
 *credentials by checking if the user exists in a given repository.
**/

#include "LoginService.h"

LoginService::LoginService(TemplatedRepository<User> *users) : users(users) {}

LoginService::~LoginService() {

}

bool LoginService::validateUser(const User& possibleUser) {
    for(const auto& user : users->getAll()){
        if(user == possibleUser){
            return true;
        }
    }

    return false;
}
