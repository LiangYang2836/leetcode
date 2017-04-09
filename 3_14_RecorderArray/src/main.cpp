/*
 * main.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

bool CheckEven(int value) {
	if ((value & 1) == 0) {
		return true;
	}

	return false;
}

void Reorder(int *p_data, int length, bool (*func)(int)) {

	if (p_data == NULL || length == 0) {
		return;
	}

	int *p_head = p_data;
	int *p_tail = p_data + length - 1;
	while (p_head < p_tail) {
		while (p_head < p_tail && !func(*p_head)) {
			p_head++;
		}

		while (p_head < p_tail && func(*p_tail)) {
			p_tail--;
		}

		int tmp = *p_head;
		*p_head = *p_tail;
		*p_tail = tmp;
	}
}

void DisplayArray(int *p_data, int length) {

	if (p_data == NULL) {
		return;
	}

	for (int i = 0; i < length; i++) {
		cout << p_data[i];
	}
	cout << endl;
}

int main() {

	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int length = sizeof(data) / sizeof(int);
	DisplayArray(data, length);
	Reorder(data, length, CheckEven);
	DisplayArray(data, length);
	return 0;
}


