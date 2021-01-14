#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

workManager::workManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{   
		this->m_EmployeeNum = 0;
		this->m_EmployeeArray = NULL;
		this->m_FileIsEmpty = 1;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmployeeNum = 0;
		this->m_EmployeeArray = NULL;
		this->m_FileIsEmpty = 1;
		ifs.close();
		return; 
	}

	this->m_EmployeeNum = this->getEmpNum();
	this->m_EmployeeArray = new worker*[this->m_EmployeeNum];
	this->init_Emp();
}

void workManager::showMenu()
{
	cout << "Welcome to the employee management system" << endl;
	cout << "0.exit" << endl;
	cout << "1.add worker information" << endl;
	cout << "2.display worker information" << endl;
	cout << "3.delete worker information" << endl;
	cout << "4.modify worker information" << endl;
	cout << "5.find worker information" << endl;
	cout << "6.sort worker information" << endl;
	cout << "7.clear all information" << endl;
	cout << endl;
}

void workManager::exitSystem()
{
	cout << "Welcome to use next time" << endl;
	system("pause");
	exit(0);
}

void workManager::addWorker()
{
	cout << "please enter the num of workers" << endl;
	
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmployeeNum + addNum;

		worker **newSpace = new worker*[newSize];

		if (this->m_EmployeeArray!=NULL)
		{
			for (int i = 0; i < this->m_EmployeeNum; i++)
			{
				newSpace[i] = this->m_EmployeeArray[i];
			}
		}

		for (int i = 0; i < addNum;i++ )
		{
			int id;
			string name;
			int depNum;

			cout << "please enter the id of No." << i + 1 << " worker" << endl;
			cin >> id;
			

			cout << "please enter the name of No." << i + 1 << " worker" << endl;
			cin >> name;

			cout << "please enter the department of No." << i + 1 << " worker" << endl;
			cout << "1:employee  2:manager  3:boss" << endl;
			cin >> depNum;

			worker *w = NULL;
			switch (depNum)
			{
			case 1:
				w = new Employee(id, name, 1);
                break;
			case 2:
				w = new Manager(id, name, 2);
				break;
			case 3:
				w = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmployeeNum + i] = w;
			
		}

		delete[]this->m_EmployeeArray;
		this->m_EmployeeArray = newSpace;
		this->m_EmployeeNum = newSize;
		this->m_FileIsEmpty = 0;
		cout << "success for adding " << addNum << " worker" << endl;
		this->saveInfo();
	}
	else
	{
		cout << "enter error" << endl;
	}
	system("pause");
	system("cls");
}

void workManager::saveInfo()
{
	ofstream ofs;
	ofs.open("empFile.txt", ios::out);
	for (int i = 0; i < this->m_EmployeeNum; i++)
	{
		ofs << this->m_EmployeeArray[i]->w_Id << " "
			<< this->m_EmployeeArray[i]->w_Name << " "
			<< this->m_EmployeeArray[i]->w_DeptId << endl;
	}
	ofs.close();
}

int workManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;

	int empNum = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		empNum++;
	}
	ifs.close();

	return empNum;
}

void workManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker *w = NULL;

		if (dId == 1)
		{
			w = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			w = new Manager(id, name, dId);
		}
		else
		{
			w = new Boss(id, name, dId);
		}

		this->m_EmployeeArray[index] = w;
		index++;
	}
}

void workManager::showWorkerInfo()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is empty" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmployeeNum; i++)
		{
			 this->m_EmployeeArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int workManager::isWorkerExist(int id)
{
	int index = -1;
	
	for (int i = 0; i < this->m_EmployeeNum; i++)
	{
		if (this->m_EmployeeArray[i]->w_Id == id)
		{
			index = i;
			
			break;
		}
	}

	return index;
}

void workManager::deleteWorkerInfo()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is empty" << endl;
		
		return;
	}

	cout << "please enter the worker's id" << endl;
	
	int id;
	cin >> id;
	
	if (this->isWorkerExist(id) == -1)
	{
		cout << "the woker doesn't exist" << endl;
	}
	else
	{
		for (int i = this->isWorkerExist(id); i < this->m_EmployeeNum-1; i++)// 记得-1，否则会操纵非法空间
		{
			this->m_EmployeeArray[i] = this->m_EmployeeArray[i + 1];
		}
		
		this->m_EmployeeNum--;
		
		this->saveInfo();
		
		cout << "delete success" << endl;
	}
	system("pause");
	system("cls");
}

void workManager::modifyWorkerInfo()
{
	cout << "please enter the worker's id" << endl;

	int id;
	cin >> id;

	int ret = this->isWorkerExist(id);
	if (ret == -1)
	{
		cout << "this worker doesn't exist" << endl;
	}
	else
	{
		delete this->m_EmployeeArray[ret];

		int newId;
		string newName;
		int newDepSelect;

		cout << "system has found this worker, please enter new id" << endl;
		cin >> newId;

		cout << "please enter new name" << endl;
		cin >> newName;

		cout << "please enter new department" << endl;
		cout << "1.employee    2.manager   3.boss" << endl;
		cin >> newDepSelect;

		worker *w=NULL;
		switch (newDepSelect)
		{
		case 1:
			w = new Employee(newId, newName, newDepSelect);
			break;
		case 2:
			w = new Manager(newId, newName, newDepSelect);
			break;
		case 3:
			w = new Boss(newId, newName, newDepSelect);
			break;
		default:
			break;
		}

		this->m_EmployeeArray[ret] = w;

		cout << "modify success" << endl;

		this->saveInfo();
	}

	system("pause");
	system("cls");
}

void workManager::findWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is empty" << endl;
	}
	else
	{
		cout << "please enter the way of finding: 1.Id 2.Name" << endl;
		int findSelect;
		cin >> findSelect;
		if (findSelect == 1)
		{
			cout << "please enter the ID that you want to find" << endl;
			int id;
			cin >> id;

			int ret = this->isWorkerExist(id);
			if (ret != -1)
			{
				cout << "system has found this worker:" << endl;
				this->m_EmployeeArray[ret]->showInfo();
			}
			else
			{
				cout << "this worker doesn't exist" << endl;
			}
		}
		else if (findSelect == 2)
		{ 
			cout << "please enter the name that you want to find" << endl;
			string name;
			cin >> name;

			bool findFlag = 0;
			for (int i = 0; i < this->m_EmployeeNum; i++)
			{
				if (this->m_EmployeeArray[i]->w_Name == name)
				{
					cout << "system has found" << endl;
					this->m_EmployeeArray[i]->showInfo();
					findFlag = 1;
				}
			}
			if (findFlag == 0)
			{
				cout << "this worker doesn't exist" << endl;
			}
		}
		else
		{
			cout << "enter error" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workManager::sortWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "file is empty" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "please select ways: 1.ascending order  2.Descending order" << endl;
		int sortSelect;
		cin >> sortSelect;
		
	
		for (int i = 0; i < this->m_EmployeeNum; i++)
		{   
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmployeeNum; j++)
			{
				if (sortSelect == 1)
				{
					if (this->m_EmployeeArray[i]->w_Id > this->m_EmployeeArray[j]->w_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmployeeArray[i]->w_Id < this->m_EmployeeArray[j]->w_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				worker *temp = this->m_EmployeeArray[i];
				this->m_EmployeeArray[i] = this->m_EmployeeArray[minOrMax];
				this->m_EmployeeArray[minOrMax] = temp;
			}
		}
		cout << "sort success" << endl;
		this->saveInfo();
		this->showWorkerInfo();
	}
}

void workManager::clearFile()
{
	cout << "sure for clearing?  1. Yes   2.No" << endl;
	int clearSelect;
	cin >> clearSelect;

	if (clearSelect == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmployeeArray != NULL)
		{
			for (int i = 0; i < this->m_EmployeeNum; i++)
			{   
				if (this->m_EmployeeArray[i] != NULL)
				{
					delete this->m_EmployeeArray[i];
				}
			}
			this->m_EmployeeNum = 0;
			delete[] this->m_EmployeeArray;
			this->m_EmployeeArray = NULL;
			this->m_FileIsEmpty = 0;
		}
		cout << "clear success" << endl;
	}
	system("pause");
	system("cls");
}

workManager::~workManager()
{
	if (this->m_EmployeeArray != NULL)
	{
		for (int i = 0; i < this->m_EmployeeNum; i++)
		{
			if (this->m_EmployeeArray[i] != NULL)
			{
				delete this->m_EmployeeArray[i];
			}
		}
		delete[] this->m_EmployeeArray;
		this->m_EmployeeArray = NULL;
	}
}

