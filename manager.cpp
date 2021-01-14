#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DeptId = dId;
}

void Manager::showInfo()
{
	cout << "worker id:" << this->w_Id << "\t worker name:" << this->w_Name << "\t department:" << this->getDeptName() << "\t finish the boss' task and give task to employee" << endl;
}

string Manager::getDeptName()
{
	return string("manager");
}