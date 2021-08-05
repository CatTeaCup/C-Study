#pragma once
#include<iostream>
#include"point.h"
using namespace std;

class Circle
{
private:
	int c_r;
	Point c_p;
public:
	void set_r(int r);
	int get_r();
	void set_p(Point p);
	Point get_p();
};