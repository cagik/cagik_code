#include <iostream>
#include <string>
#include <fstream>

#include "workerManager.h"



using namespace std;



int main(){
	workManager wm;
	int choice = 0;

	while (1)
	{
		wm.showMenu();
		cout << "enter your request" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://exit
			wm.exitSystem();
			break;
		case 1://add
			wm.addWorker();
			break;
		case 2://display
			wm.showWorkerInfo();
			break;
		case 3://delete
			wm.deleteWorkerInfo();
			break;
		case 4://modify
			wm.modifyWorkerInfo();
			break;
		case 5://find
			wm.findWorker();
			break;
		case 6:
			wm.sortWorker();//sort
			break;
		case 7:
			wm.clearFile();//clear
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
