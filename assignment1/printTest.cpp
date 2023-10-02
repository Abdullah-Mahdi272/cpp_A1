#include <vector>
#include "Planner.h"

#include "Date.h"



int main() {
    Planner planner; // Create a Planner object
    Date date = Date();
    // Test addEvent
    planner.addEvent("Tutorial", "Program C++", date, 10, 2);
    planner.addEvent("Lecture", "Learn C++", date, 8, 2);
    planner.addEvent("Lab", "Ask questions", date, 6, 2);
    planner.addEvent("Assignment", "Make assignment - no segfaults", date, 9, 2);

    planner.getDate(date);

    planner.printAllDates();


    return 0;


}