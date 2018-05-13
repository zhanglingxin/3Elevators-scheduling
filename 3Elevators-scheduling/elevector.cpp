#include "elevector.h"
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
void elevector::goToFloor1(int passengerFloor, int targetfloor, int requestTime, int *time, int* floor)
{
	int *nowTime;
	nowTime = time;
	if (requestTime > *nowTime)
		*time += (abs)(requestTime - *nowTime);
	*time += (abs)(*floor - targetfloor);
	*floor = targetfloor;
}
void elevector::goToFloor2(int passengerFloor, int targetfloor, int requestTime, int *time, int* floor)
{
	int *nowTime;
	nowTime = time;
	if(requestTime>*nowTime)
	*time += (abs)(requestTime-*nowTime);
	*time += (abs)(*floor - passengerFloor);
	*floor = passengerFloor;
}
void elevector::stop(int* time)
{
	*time += 1;
}
 elevector::elevector(void )
{
	 time = 0;
	 floor = 1;
}


elevector::~elevector()
{
}

