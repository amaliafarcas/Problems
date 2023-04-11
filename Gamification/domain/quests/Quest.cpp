//
// Created by Ama on 4/4/2023.
//


#include "Quest.h"

Quest::Quest(size_t id,
             const std::string &text,
             const std::string &date,
             const std::string &time, size_t tokens,
             const std::string &username, bool completed) :
             id(id),
             text(text),
             date(date),
             time(time),
             tokens(tokens),
             username(username),
             completed(completed) {}

Quest::~Quest() = default;

size_t Quest::getId() const {
    return id;
}

void Quest::setId(size_t id) {
    Quest::id = id;
}

const std::string &Quest::getText() const {
    return text;
}

void Quest::setText(const std::string &text) {
    Quest::text = text;
}

const std::string &Quest::getDate() const {
    return date;
}

void Quest::setDate(const std::string &date) {
    Quest::date = date;
}

const std::string &Quest::getTime() const {
    return time;
}

void Quest::setTime(const std::string &time) {
    Quest::time = time;
}

size_t Quest::getTokens() const {
    return tokens;
}

void Quest::setTokens(size_t tokens) {
    Quest::tokens = tokens;
}

const std::string &Quest::getUsername() const {
    return username;
}

void Quest::setUsername(const std::string &username) {
    Quest::username = username;
}

bool Quest::operator==(const Quest &rhs) const {
    return id == rhs.id &&
    text == rhs.text &&
    date == rhs.date &&
    time == rhs.time &&
    tokens == rhs.tokens &&
    username == rhs.username &&
    completed == rhs.completed;
}

bool Quest::operator!=(const Quest &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Quest &quest) {
    os << quest.id << " "
    << quest.text << " "
    << quest.date << " "
    << quest.time << " "
    << quest.tokens << " "
    << quest.username << " "
    << quest.completed << "\n";

    return os;
}

std::istream &operator>>(std::istream &is, Quest &quest) {
    return is >> quest.id >>
    quest.text >>
    quest.date >>
    quest.time >>
    quest.tokens >>
    quest.username >>
    quest.completed;
}

bool Quest::operator<=(const Quest& other) const {
    // Convert the date and time strings to actual dates and times
    std::tm date1{}, date2{}, time1{}, time2{};
    std::istringstream date_stream1(date), date_stream2(other.date);
    std::istringstream time_stream1(time), time_stream2(other.time);
    date_stream1 >> std::get_time(&date1, "%Y.%m.%d");
    date_stream2 >> std::get_time(&date2, "%Y.%m.%d");
    time_stream1 >> std::get_time(&time1, "%H:%M");
    time_stream2 >> std::get_time(&time2, "%H:%M");

    // Combine the dates and times and compare them
    std::time_t timestamp1 = std::mktime(&date1) + std::mktime(&time1);
    std::time_t timestamp2 = std::mktime(&date2) + std::mktime(&time2);
    return timestamp1 <= timestamp2;
}

bool Quest::isCompleted() const {
    return completed;
}

void Quest::setCompleted(bool completed) {
    Quest::completed = completed;
}

