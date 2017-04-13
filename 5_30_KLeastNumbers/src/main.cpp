/*
 * main.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: yl
 */


#include <iostream>
#include <set>
using namespace std;

void GetKLeastNumbers(int data[], int len, int k, multiset<int, greater<int> > &data_set) {

	if (data == NULL) {
		return;
	}

	if (len < 0 || k < 0 || len < k) {
		return;
	}

	for (int i = 0; i < len; i++) {
		if ((int)data_set.size() < k) {
			data_set.insert(data[i]);
		} else {
			multiset<int, greater<int> >::iterator it = data_set.begin();
			if ((*it) > data[i]) {
				data_set.erase(it);
				data_set.insert(data[i]);
			}
		}
	}

}


void GetKLargeNumbers(int data[], int len, int k, multiset<int> &data_set) {

	if (data == NULL) {
		return;
	}

	if (len < 0 || k < 0 || len < k) {
		return;
	}

	for (int i = 0; i < len; i++) {
		if ((int)data_set.size() < k) {
			data_set.insert(data[i]);
		} else {
			multiset<int>::iterator it = data_set.begin();
			if ((*it) < data[i]) {
				data_set.erase(it);
				data_set.insert(data[i]);
			}
		}
	}

}


int main() {

	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	int len = sizeof(data) / sizeof(int);
	multiset<int, greater<int> > data_set;
	GetKLeastNumbers(data, len, 5, data_set);
	for (multiset<int, greater<int> >::const_iterator it = data_set.begin(); it != data_set.end(); it++) {
		cout << *it << endl;
	}

	int data_2[] = {4, 5, 1, 6, 2, 7, 3, 8};
	cout << "=============" << endl;
	multiset<int> data_set_2;
	GetKLargeNumbers(data_2, len, 3, data_set_2);
	for (multiset<int>::const_iterator it = data_set_2.begin(); it != data_set_2.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

