/*
 * main.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: yl
 */


#include <iostream>
#include <string.h>
using namespace std;

bool increase_char(char *number) {
	bool flag = false;
	int over_take = 0;
	int len = strlen(number);

	for (int i = len - 1; i >= 0; i--) {
//		cout << "number[i]:" << number[i] << endl;
		int digit = number[i] - '0' + over_take;
		if (i == len - 1) {
			digit++;
		}

//		cout << "digit:" << digit << endl;
		if (digit > 9) {
			if (i == 0) {
				flag = true;
				break;
			}
			over_take = 1;
			number[i] = '0';
		} else {
			number[i] = digit + '0';
			break;
		}
	}

	return flag;
}

void print_number(const char *number) {

	int len = strlen(number);
	bool flag = false;
	for (int i = 0; i < len; i++) {
		if (number[i] != '0') {
			flag = true;
		}
		if (flag) {
			cout << number[i];
		}
	}

	cout << endl;
}

void print_1_to_N(unsigned int n) {

	char *number = new char[n + 1];
	memset(number, '0', n);

	while (!increase_char(number)) {
		print_number(number);
	}
	delete number;
	number = NULL;
}

void add_big_number(char *number_1, char *number_2) {

	int len_1 = strlen(number_1);
	int len_2 = strlen(number_2);
	int len_big = 0;
	int len_small = 0;
	char *big_number = NULL;
	char *small_number = NULL;
	if (len_1 > len_2) {
		big_number = number_1;
		small_number = number_2;
		len_big = len_1;
		len_small = len_2;

	} else {
		big_number = number_2;
		small_number = number_1;
		len_big = len_2;
		len_small = len_1;
	}

	cout << len_big << "-" << len_small << endl;
	char *result = new char[len_big + 2];
	memset(result, '0', len_big + 1);

	int index_big = len_big - 1;
	int index_small = len_small - 1;
	int index_result = len_big + 2 - 1;
	int over_take = 0;
	for (; index_small >= 0; index_big--, index_small--) {
		int dig_1 = big_number[index_big] - '0';
		int dig_2 = small_number[index_small] - '0';

		int ret = dig_1 + dig_2 + over_take;

		if (ret > 9) {
			over_take = 1;
			result[index_result--] = '0' + ret % 10;
		} else {
			over_take = 0;
			result[index_result--] = '0' + ret;
		}

	}

	for (; index_big >= 0; index_big--) {
		int dig_1 = big_number[index_big] - '0';
		int ret = dig_1 + over_take;
		cout << "ret:" << ret << endl;
		if (ret > 9) {
			over_take = 1;
			result[index_result--] = '0' + ret % 10;
		} else {
			over_take = 0;
			result[index_result--] = '0' + ret;
		}

	}
	result[index_result] += over_take;
	print_number(result);

	delete result;
	result = NULL;
}

int main() {

//	unsigned int n = 3;

//	print_1_to_N(n);

	char number_1[] = "12345678";
	char number_2[] = "99999999";
	add_big_number(number_1, number_2);
	return 0;
}


