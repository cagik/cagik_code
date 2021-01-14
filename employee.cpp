#include "employee.h"

Employee::Employee(int id ,string name , int dId)
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