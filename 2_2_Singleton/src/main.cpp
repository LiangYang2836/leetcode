/*
 * main.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: yl
 */

#include <iostream>
#include "Singleton.h"

using namespace std;

Singleton* Singleton::pInstance = NULL;
int Singleton::instance_num = 0;

Singleton* Singleton::Instance() {

	if (pInstance == NULL) {
		pInstance = new Singleton();
	}

	instance_num++;

	return pInstance;
}

void Singleton::Destroy() {
	if (pInstance != NULL) {
		instance_num--;
		delete pInstance;
		pInstance = NULL;
	}
}

void Singleton::Show() {
	cout << "instance_num:" << instance_num << endl;
}

int main() {

	Singleton* singleton_1 = Singleton::Instance();
	singleton_1->Show();
	Singleton* singleton_2 = Singleton::Instance();
	singleton_2->Show();
	singleton_1->Destroy();
	singleton_2->Show();
	singleton_2->Destroy();

	return 0;
}


