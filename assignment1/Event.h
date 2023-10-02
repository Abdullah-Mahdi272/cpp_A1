//
// Created by abdul on 2023-09-29.
//


#ifndef EVENT_H
#define EVENT_H

#include <iostream>
class Event {

public:

    void print();

    Event(const std::string& title, const std::string& description, int startTime, int duration);

    bool lessThan(Event& e);

    bool equals(Event& e);
    bool conflictsWith(Event& e);

private:

    std::string title;
    std::string description;
    int startTime;
    int duration;

};


#endif
