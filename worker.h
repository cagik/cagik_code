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

