//
// Created by Ama on 4/9/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_TEMPLATEDREPOSITORY_H
#define INC_2023_INTERNSHIP_ACCESA_TEMPLATEDREPOSITORY_H


#pragma once

#include <vector>
#include <algorithm>
#include <fstream>
#include "../domain/badges/Badge.h"
#include "../domain/quests/Quest.h"
#include "../domain/user/User.h"
#include "../domain/userStatus/UserStatus.h"


template<typename T>
class TemplatedRepository {
public:
    TemplatedRepository(std::string filePath);

    ~TemplatedRepository() = default;

    std::vector<T> getAll();

    void addElement(T &elem);

    void removeElement(T &elem);

private:
    std::string filePath;
    std::vector<T> data;

    void writeFile();

    void readFile();

};

template<typename T>
inline TemplatedRepository<T>::TemplatedRepository(std::string filePath) :
        filePath{filePath} {
    this->readFile();
}

template<typename T>
inline std::vector<T> TemplatedRepository<T>::getAll() {
    return this->data;
}

template<typename T>
inline void TemplatedRepository<T>::addElement(T &elem) {
    this->data.push_back(elem);
    this->writeFile();
}

template<typename T>
inline void TemplatedRepository<T>::removeElement(T &elem) {
    auto find = std::find(this->data.begin(), this->data.end(), elem);
    if (find != this->data.end()) {
        data.erase(find);
        writeFile();
    }
}

template<typename T>
inline void TemplatedRepository<T>::writeFile() {
    std::ofstream outputFile;
    outputFile.open(filePath, std::ios::out);

    for (auto obj: this->data)
        outputFile << obj;

    outputFile.close();
}

template<typename T>
inline void TemplatedRepository<T>::readFile() {
    std::ifstream inputFile;
    inputFile.open(filePath, std::ios::in);

    T obj;

    while (inputFile >> obj)
        this->data.push_back(obj);

    inputFile.close();

}

#endif //INC_2023_INTERNSHIP_ACCESA_TEMPLATEDREPOSITORY_H
