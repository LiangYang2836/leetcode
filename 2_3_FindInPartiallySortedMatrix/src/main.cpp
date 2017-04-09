/*
 * main.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

bool find(int *matrix, int rows, int columns, int number) {

	bool found = false;

	int row = 0;
	int column = columns - 1;

	if (matrix != NULL && rows > 0 && columns > 0) {
		//	cout << row << "-" << column << "-" << matrix[row * columns + column] << endl;
		while (row < rows && column >= 0) {
			cout << row << " " << column << " " << *(matrix + row * columns + column) << endl;
			if (*(matrix + row * columns + column) == number) {
				found = true;
				break;
			} else if (*(matrix + row * columns + column) > number) {
				column--;
			} else {
				row++;
			}
		}
	}

	return found;
}

bool find_2(int *matrix, int rows, int columns, int number) {

	bool found = false;

	if (matrix != NULL) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (matrix[i * columns + j] == number) {
					cout << i << " " << j << " " << *(matrix + i * columns + j) << endl;
					found = true;
					break;
				} else if (matrix[i * columns + j] > number) {
					break;
				}
			}
		}
	}
	return found;
}

int main() {

	unsigned int row_num = 4;
	unsigned int column_num = 5;
	int matrix[row_num][column_num] = {{1, 2, 8, 9, 10},
						{2, 4, 9, 12, 15},
						{4, 7, 10, 13, 17},
						{6, 8, 11, 15, 20}};

	for (unsigned int i = 0; i < row_num; i++) {
		for (unsigned int j = 0; j < column_num; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	// yangliang
	// (int*) is very important! Or it will show errors.
	cout << find_2((int*)matrix, row_num, column_num, 7) << endl;


	return 0;
}


