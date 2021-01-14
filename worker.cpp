#include "worker.h"

Employee::Employee(int id, string name, int dId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "worker id:" << this->w_Id << "\t worker name:" << this->w_Name << "\t department:" << this->getDeptName() << "\t finish the manager's task" << endl;
}

string Employee::getDeptName()
{
	return string("employee");
}

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

Boss::Boss(int id, string name, int dId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DeptId = dId;
}

void Boss::showInfo()
{
	cout << "worker id:" << this->w_Id << "\t worker name:" << this->w_Name << "\t department:" << this->getDeptName() << "\t manage all task" << endl;
}

string Boss::getDeptName()
{
	return string("boss");
}