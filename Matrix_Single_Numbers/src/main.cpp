/*
 * main.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

void FindSingleOne(int arr[], const int len) {

	if (arr == NULL) {
		return;
	}

	int num = 0;
	for (int i = 0; i < len; i++) {
		num ^= arr[i];
	}

	cout << "Single One: " << num << endl;
}

void FindSingleTwo(int arr[], const int len) {

	if (arr == NULL) {
		return;
	}

	int num_all = 0;
	for (int i = 0; i < len; i++) {
		num_all ^= arr[i];
	}

//	cout << "num_all:" << num_all << endl;

	int first_one_index = 0;
	while (num_all != 0) {
		if ((num_all & 1) == 1) {
			break;
		}

		first_one_index++;
		num_all = num_all >> 1;
	}

//	cout << "first_one_index:" << first_one_index << endl;

	int num_1 = 0;
	int num_2 = 0;
	int flag = 1 << first_one_index;
//	cout << "flag:" << flag << endl;
	for (int i = 0; i < len; i++) {
//		cout << (arr[i] & flag) << endl;
		if ((arr[i] & flag) == 0) {
			num_1 ^= arr[i];
		} else {
			num_2 ^= arr[i];
		}
	}

	cout << "Single Two: " << num_1 << ", " << num_2 << endl;
}

void FindSingleOneFromN(int arr[], const int len, const int num) {

	if (arr == NULL) {
		return;
	}

	int bit_info[32] = {0};
	int tmp_arr_val = 0;
	for (int i = 0; i < len; i++) {
		tmp_arr_val = arr[i];
		for (int j = 0; j < 32; j++) {
			bit_info[j] += (tmp_arr_val & 1);
			tmp_arr_val = tmp_arr_val >> 1;
		}
	}

	int value = 0;
	for (int i = 0; i < 32; i++) {
		if ((bit_info[i] % num) != 0) {
			value |= 1 << i;
		}
	}

	cout << "Single One From " << num << ": " << value << endl;
}

int main() {
	int arr_1[] = {1, 1, 3, 3, 6, 2, 2};
	size_t len_1 = sizeof(arr_1) / sizeof(int);
	FindSingleOne(arr_1, len_1);

	int arr_2[] = {1, 1, 3, 6, 2, 2};
	size_t len_2 = sizeof(arr_2) / sizeof(int);
	FindSingleTwo(arr_2, len_2);

	int arr_n[] = {1, 5, 1, 5, 5, 9, 1, 1, 5, 1, 5};
	size_t len_n = sizeof(arr_n) / sizeof(int);
	FindSingleOneFromN(arr_n, len_n, 5);

	return 0;
}


