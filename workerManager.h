#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "worker.h"

#define FILENAME "empFile.txt"

using namespace std;

class workManager
{
public:
	workManager();

	void showMenu();

	void exitSystem();

	void addWorker();

	void saveInfo();

	int getEmpNum();

	void init_Emp();

	void showWorkerInfo();

	int isWorkerExist(int id);

	void modifyWorkerInfo();

	void deleteWorkerInfo();

	void findWorker();

	void sortWorker();

	void clearFile();

    ~workManager();

	int m_EmployeeNum;
	worker **m_EmployeeArray;
	bool m_FileIsEmpty;

};
//头文件里面