//
// Created by abdul on 2023-09-29.
//


#ifndef PLANNERDATE_H
#define PLANNERDATE_H

#include "Date.h"
#include "Event.h"
#define MAX_ARRAY 365
class PlannerDate{
public:
    PlannerDate(Date d);

    ~PlannerDate();

    bool equals(PlannerDate &pd);

    bool equals(Date &d);

    bool lessThan(Date &d);

    bool lessThan(PlannerDate &d);

    bool hasEvent(const std::string& title);

    void print();

    Date getDate();

    bool addEvent(const string& title,const string& description, int startTime, int duration);

    bool hasConflict();
private:
    Date date;
    Event* eArray[MAX_ARRAY];
    int sizeEvent;

};


#endif
