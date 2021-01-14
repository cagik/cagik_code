#include "boss.h"

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