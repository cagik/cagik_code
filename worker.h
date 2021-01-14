#pragma once
#include <iostream>
#include <string>

using namespace std;

class worker
{
public:

	virtual void showInfo() = 0;
	
	virtual string getDeptName() = 0;


	int w_Id;
	string w_Name;
	int w_DeptId;
};


class Employee :public worker
{
public:
	Employee(int id, string name, int dId);

	void showInfo();

	string getDeptName();
};

class Manager :public worker
{
public:
	Manager(int id, string name, int dId);

	void showInfo();

	string getDeptName();
};

class Boss :public worker
{
public:
	Boss(int id, string name, int dId);

	void showInfo();

	string getDeptName();
};
