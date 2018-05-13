#pragma once
class elevector
{
public:
	bool onrun;
	int currentFloor;
	 int input[3];
	 int time;
	 int floor;
	 int passengerFloor ;
	 int targetFloor ;
	 int requestTime ;
	elevector(void );
	~elevector();
	void goToFloor1(int passengerFloor, int targetFloor, int requestTime, int *time, int* floor);
	void goToFloor2(int passengerFloor, int targetFloor, int requestTime, int *time, int* floor);
	void stop(int* time);


};

