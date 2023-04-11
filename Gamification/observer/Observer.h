//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_OBSERVER_H
#define INC_2023_INTERNSHIP_ACCESA_OBSERVER_H

#pragma once

#include <vector>
#include <sstream>
#include <algorithm>

class Observer {
public:
    virtual void update() = 0;

    ~Observer() = default;

private:
};

class Subject {
public:
    void addObserver(Observer *observer) {
        this->observers.push_back(observer);
    }

    void notify() {
        for (auto observer: this->observers)
            observer->update();
    }

    void deleteObserver(Observer *observer) {
        auto it = std::find(this->observers.begin(), this->observers.end(), observer);
        if (it != this->observers.end())
            this->observers.erase(it);
    }

private:
    std::vector<Observer *> observers;
};

#endif //INC_2023_INTERNSHIP_ACCESA_OBSERVER_H
