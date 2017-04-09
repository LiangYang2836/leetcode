/*
 * main.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: yl
 */


#include <iostream>
using namespace std;

int FindGreatestSumOfSubarray(int arr[], int len) {

	if (arr == NULL) {
		return -1;
	}

	int max_sum = 0;
	int cur_sum = 0;
	for (int i = 0; i < len; i++) {
		if (cur_sum <= 0) {
			cur_sum = arr[i];
		} else {
			cur_sum += arr[i];
		}

		if (max_sum < cur_sum) {
			max_sum = cur_sum;
		}
	}

	return max_sum;
}

int main() {

	int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int len = sizeof(arr) / sizeof(int);
	int sum = FindGreatestSumOfSubarray(arr, len);
	cout << "sum:" << sum << endl;
	return 0;
}

