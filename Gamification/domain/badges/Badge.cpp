//
// Created by Ama on 4/4/2023.
//

#include "../../domain/badges/Badge.h"

Badge::Badge(size_t id, const std::string &name) : id(id), name(name) {}

Badge::~Badge() {

}

size_t Badge::getId() const {
    return id;
}

void Badge::setId(size_t id) {
    Badge::id = id;
}

const std::string &Badge::getName() const {
    return name;
}

void Badge::setName(const std::string &name) {
    Badge::name = name;
}

bool Badge::operator==(const Badge &rhs) const {
    return id == rhs.id &&
           name == rhs.name;
}

bool Badge::operator!=(const Badge &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Badge &badge) {
    os << " " << badge.id << " " << badge.name<<"\n";
    return os;
}

std::istream &operator>>(std::istream &is, Badge &badge) {
    return is>>badge.id>>badge.name;
}
