//
// Created by abdul on 2023-09-29.
//

#ifndef ASSIGNMENT1_PLANNER_H
#define ASSIGNMENT1_PLANNER_H


#include <string>
#include "Date.h"
#include "PlannerDate.h"
#define MAX_ARRAY 365

class Planner {

public:

    Planner();

    ~Planner();

    void addDailyEvent(string title, string description, Date& startDate, Date& endDate, int startTime, int duration);

    void addWeeklyEvent(string title, string description, Date& startDate, Date& endDate, int startTime, int duration);

    void addEvent(string title, string description, Date& date, int startTime, int duration);

    void printAllDates();

    void addWeeklyEvent(const string& s1, const string& s2, Date d1, Date d2 ,int i1,int i2);

    void printDate(Date& d);

    void printDatesWithConflict();

    void printDatesInRange(Date& startDate, Date& endDate);

    void printDatesWithEvent(const string& title);

    PlannerDate* getDate(Date& dd);
private:



    PlannerDate* pdArray[MAX_ARRAY];
    int sizePlannerDate;


};


#endif //ASSIGNMENT1_PLANNER_H
