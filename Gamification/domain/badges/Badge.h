//
// Created by Ama on 4/4/2023.
//

#ifndef INC_2023_INTERNSHIP_ACCESA_BADGE_H
#define INC_2023_INTERNSHIP_ACCESA_BADGE_H
#pragma once
#include "iostream"
#include "fstream"

class Badge {
private:
    size_t id;
    std::string name;

public:
    Badge() = default;
    Badge(size_t id, const std::string &name);

    virtual ~Badge();

    size_t getId() const;

    void setId(size_t id);

    const std::string &getName() const;

    void setName(const std::string &name);

    bool operator==(const Badge &rhs) const;

    bool operator!=(const Badge &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Badge &badge);

    friend std::istream &operator>>(std::istream &os, Badge &badge);
};


#endif //INC_2023_INTERNSHIP_ACCESA_BADGE_H
