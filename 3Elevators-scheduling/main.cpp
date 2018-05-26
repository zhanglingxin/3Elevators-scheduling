#include<iostream>
#include<cstdio>
#include<fstream>
#include <algorithm>
#include"elevector.h"
#include<stdlib.h>
int time1 = 0;
using namespace std;
int l1[3][1000], l2[3][1000], l3[3][1000];//三个电梯接受指令的数组
int ipt[3][1000];//所有电梯接受指令的数组；
elevector lift[4];
int nl[4] = { 0 };

// void dispatch2(int n[][], int row, int col);
// void dispatch2(vector<vector<int>> &n);

int main(int argc,char *argv[])
{
	FILE * output1, *output2, *output3,*input1;
	ofstream outfile1("output1.txt");
	ofstream outfile2("output2.txt");
	ofstream  outfile3("output3.txt");
	ifstream infile("input1.txt");
	if (argc == 3)
	{
		infile = ifstream(argv[1]);
	}
	if (argc == 5)
	{
		infile = ifstream(argv[1]);
		outfile1 = ofstream(argv[2]);
		outfile2 = ofstream(argv[3]);
		outfile3 = ofstream(argv[4]);
	}
	int n, i;
	int temp0=0, temp1=0, temp3=0;
	infile >> n;
	for (i = 0;i < n;i++)
	{
		infile >> ipt[0][i] >> ipt[1][i] >> ipt[2][i];
		if (ipt[1][i] != 1 && ipt[2][i] != 1)
		{

			if (ipt[1][i] % 2 == 0 && ipt[2][i] % 2 == 0)
			{
				l3[0][i] = ipt[0][i];
				l3[1][i] = ipt[1][i];
				l3[2][i] = ipt[2][i];
				nl[3]++;
			}
			else if ((ipt[1][i] % 2 != 0 && ipt[2][i] % 2 != 0))
			{
				l1[0][i] = ipt[0][i];
				l1[1][i] = ipt[1][i];
				l1[2][i] = ipt[2][i];
				nl[1]++;

			}
			else
			{
				l2[0][i] = ipt[0][i];
				l2[1][i] = ipt[1][i];
				l2[2][i] = ipt[2][i];
				nl[2]++;
			}
		}
		if (ipt[1][i] == 1 || ipt[2][i] == 1)
		{
			if (ipt[1][i]==1&&ipt[2][i]!=1)
			{
				if (ipt[2][i] % 2 == 0)
				{
					l2[1][i] = ipt[1][i];
					l2[2][i] = ipt[2][i];
					l2[0][i] = ipt[0][i];
					nl[2]++;
				}

				else
				{
					l1[2][i] = ipt[2][i];
					l1[1][i] = ipt[1][i];
					l1[0][i] = ipt[0][i];
					nl[1]++;
				}
			}
			else
			{

				if (ipt[1][i] % 2 == 0)
				{
					l2[1][i] = ipt[1][i];
					l2[2][i] = ipt[2][i];
					l2[0][i] = ipt[0][i];
					nl[2]++;
				}

				else
				{
					l1[2][i] = ipt[2][i];
					l1[1][i] = ipt[1][i];
					l1[0][i] = ipt[0][i];
					nl[1]++;
				}
			}
		}
	}

	for (i = 0;i < nl[1] - 1;i++)
	{
		if (l1[2][i] - l1[1][i]>0 && l1[2][i + 1] - l1[1][i + 1]>0)
			if (l1[0][i + 1] - l1[0][i] <= abs(l1[2][i] - l1[1][i]) && l1[2][i] == l1[2][i + 1])
				l1[2][i] = l1[1][i + 1];
		if (l1[2][i] - l1[1][i] < 0 && l1[2][i + 1] - l1[1][i + 1] < 0)
		{
			if (l1[0][i + 1] - l1[0][i] <= abs(l1[2][i] - l1[1][i]) && l1[2][i] == l1[2][i + 1])
				l1[2][i] = l1[1][i + 1];
		}
	}
		
	for (i = 0;i < nl[2] - 1;i++)
	{
		if (l2[2][i] - l2[1][i]>0 && l2[2][i + 1] - l2[1][i + 1]>0)
			if (l2[0][i + 1] - l2[0][i] <= abs(l2[2][i] - l2[1][i]) && l2[2][i] == l2[2][i + 1])
				l2[2][i] = l2[1][i + 1];
		if (l2[2][i] - l2[1][i] < 0 && l2[2][i + 1] - l2[1][i + 1] < 0)
		{
			if (l2[0][i + 1] - l2[0][i] <= abs(l2[2][i] - l2[1][i]) && l2[2][i] == l2[2][i + 1])
				l2[2][i] = l2[1][i + 1];
		}
	}
	for (i = 0;i < nl[3] - 1;i++)
	{
		if (l3[2][i] - l3[1][i]>0 && l3[2][i + 1] - l3[1][i + 1]>0)
			if (l3[0][i + 1] - l3[0][i] <= abs(l3[2][i] - l3[1][i]) && l3[2][i] == l3[2][i + 1])
				l3[2][i] = l3[1][i + 1];
		if (l3[2][i] - l3[1][i] < 0 && l3[2][i + 1] - l3[1][i + 1] < 0)
		{
			if (l3[0][i + 1] - l3[0][i] <= abs(l3[2][i] - l3[1][i]) && l3[2][i] == l3[2][i + 1])
				l3[2][i] = l3[1][i + 1];
		}
	}
	for (int j = 1;j <= 3;j++)
	{
		for (i = 0;i < nl[j];i++)
		{
			if (j == 1&&nl[1]!=0)
			{
				lift[j].requestTime = l1[0][i];
				lift[j].passengerFloor = l1[2][i];
				lift[j].targetFloor = l1[1][i];
				ofstream outfile1("output1.txt");
			}
			else if (j == 2&&nl[2]!=0)
			{
				lift[j].requestTime = l2[0][i];
				lift[j].passengerFloor = l2[2][i];
				lift[j].targetFloor = l2[1][i];
				ofstream outfile2("output2.txt");
			}
			else if (j == 3&&nl[3]!=0)
			{
				lift[j].requestTime = l3[0][i];
				lift[j].passengerFloor = l3[2][i];
				lift[j].targetFloor = l3[1][i];
				ofstream outfile3("output3.txt");
			}
			if (lift[j].floor != lift[j].targetFloor)
			{
				lift[j].goToFloor1(lift[j].passengerFloor, lift[j].targetFloor, lift[j].requestTime, &lift[j].time, &lift[j].floor);//电梯的运行
				if (j == 1)
					outfile1<< lift[j].time << " " << lift[j].floor<<endl;
				if(j==2)
					outfile2<< lift[j].time << " " << lift[j].floor<<endl;
				if(j==3)
					outfile3<< lift[j].time << " " << lift[j].floor<<endl;
				lift[j].stop(&lift[j].time);
			}
			lift[j].goToFloor2(lift[j].passengerFloor, lift[j].targetFloor, lift[j].requestTime, &lift[j].time, &lift[j].floor);
			if (j == 1)
				outfile1 << lift[j].time << " " << lift[j].floor<<endl;
			if (j == 2)
				outfile2 << lift[j].time << " " << lift[j].floor<<endl;
			if (j == 3)
				outfile3 << lift[j].time << " " << lift[j].floor<<endl;
			//printf("%d %d\n", lift[j].time, lift[j].floor);

			lift[j].stop(&lift[j].time);
		}
	}
	return 0;
}