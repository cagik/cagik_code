#pragma once
#include <iostream>
#include <string>

#include "worker.h"

using namespace std;

class Boss :public worker
{
public:
	Boss(int id, string name, int dId);

	void showInfo();

	string getDeptName();
};