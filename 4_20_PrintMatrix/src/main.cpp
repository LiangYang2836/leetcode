/*
 * main.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

void PrintMatrix(int *matrix, int start_line_index,
		int start_column_index, int line_num, int column_num) {

//	cout << "start_line_index:" << start_line_index << endl;
//	cout << "start_column_index:" << start_column_index << endl;
//	cout << "line_num:" << line_num << endl;
//	cout << "column_num:" << column_num << endl;
//	cout << *(matrix + start_line_index * column_num + start_column_index) << endl;
	if (matrix == NULL) {
		return;
	}

	if (line_num <= 0 || column_num <= 0) {
		return;
	}

	int column_index = start_column_index;
	int line_index = start_line_index;
	for (; column_index < (start_column_index + column_num);
			column_index++) {
		cout << *(matrix + line_index * column_num + column_index) << " ";
	}
	cout << endl;

	if ((line_index + 1) >= line_num) {
		return;
	}


	line_index++;
	column_index--;

	for (; line_index < (start_line_index + line_num); line_index++) {
		cout << *(matrix +  line_index * column_num + column_index) << " ";
	}
	cout << endl;

	line_index--;
	column_index--;
	for (; column_index >=0; column_index--) {
		cout << *(matrix +  line_index * column_num + column_index) << " ";
	}
	cout << endl;

//	cout << "line_index:" << line_index << endl;
	if ((line_index - 1) <= start_line_index) {
		return;
	}

	line_index--;
	column_index++;
	for (; line_index > start_line_index; line_index--) {
		cout << *(matrix +  line_index * column_num + column_index) << " ";
	}
	cout << endl;

	start_line_index++;
	start_column_index++;
	line_num -= 2;
	column_num -= 2;

//	cout << "start_line_index:" << start_line_index << endl;
//	cout << "start_column_index:" << start_column_index << endl;
	int matrix_2[line_num][column_num];
	for (int i = start_line_index, ii = 0; i <= line_num; i++, ii++) {
		for (int j = start_column_index, jj = 0; j <= column_num; j++, jj++) {
			matrix_2[ii][jj] = *(matrix + i * (column_num + 2) + j);
		}
	}

	PrintMatrix((int*)matrix_2, 0, 0, line_num, column_num);
}

int main() {

//	const int line_num = 3;
//	const int column_num = 5;
//
//	int matrix[line_num][column_num] = {{1, 2, 3, 4, 5},
//										{6, 7, 8, 9, 10},
//										{11, 12, 13, 14, 15}};
	const int line_num = 5;
	const int column_num = 5;

	int matrix[line_num][column_num] = {{1, 2, 3, 4, 5},
										{6, 7, 8, 9, 10},
										{11, 12, 13, 14, 15},
										{16, 17, 18, 19, 20},
										{21, 22, 23, 24, 25}};
//
//	const int line_num = 1;
//	const int column_num = 5;
//
//	int matrix[line_num][column_num] = {{1, 2, 3, 4, 5}};

	PrintMatrix((int*)matrix, 0, 0, line_num, column_num);
	return 0;
}


