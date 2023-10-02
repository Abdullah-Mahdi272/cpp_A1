all: p1

p1: main.cc Date.o Event.o Planner.o PlannerDate.o
	g++ -o p1 main.cc Date.o Event.o Planner.o PlannerDate.o
Date.o: Date.cc Date.h
	g++ -c Date.cc
Event.o: Event.cc Event.h
	g++ -c Event.cc
Planner.o: Planner.cc Planner.h
	g++ -c Planner.cc
PlannerDate.o: PlannerDate.cc PlannerDate.h
	g++ -c PlannerDate.cc

clean:
	rm -f *.o p1

