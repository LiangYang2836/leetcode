/*
 * main.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: yl
 */


#include <iostream>
using namespace std;

void PrintMatrix(int *matrix, const int lines, const int columns) {

	int line_index = 0;
	int column_index = 0;
	while (line_index < lines || column_index < columns) {
//		cout << "line_index:" << line_index << " column_index:" << column_index << endl;
		cout << *(matrix + line_index * columns + column_index) << " ";
		if (((line_index + column_index) & 1) == 0) {// up
			if ((line_index - 1) < 0) {
				if ((column_index + 1) < columns) {// First line
					column_index++;
				} else {// Up Right Corner
					line_index++;
				}
			} else if ((column_index + 1) >= columns) {// Last Column
				if ((line_index + 1) < lines) {
					line_index++;
				} else {// Down Right Corner
					break;
				}
			} else {
				line_index--;
				column_index++;
			}
		} else {// down
			if ((line_index + 1) >= lines) {
				if ((column_index + 1) < columns) {// Last Line
					column_index++;
				} else { // Down Right Corner
					break;
				}
			} else if ((column_index - 1) < 0) {
				if ((line_index + 1) < lines) { //  First Column
					line_index++;
				} else { // Down Left Corner
					column_index++;
				}
			} else {
				line_index++;
				column_index--;
			}
		}
	}
}

int main() {

	int line_nums = 5;
	int column_nums = 5;
	int matrix[line_nums][column_nums] = {0};
	for (int i = 0; i < line_nums; i++) {
		for (int j = 0; j < column_nums; j++) {
			matrix[i][j] = i * column_nums + (j + 1);
		}
	}

	for (int i = 0; i < line_nums; i++) {
		for (int j = 0; j < column_nums; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	PrintMatrix((int*)matrix, line_nums, column_nums);

	return 0;
}

