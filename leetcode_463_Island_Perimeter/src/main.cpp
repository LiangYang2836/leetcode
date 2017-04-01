/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int checkPerimeter(vector< vector<int> >& grid, int index_row,
			int index_column, int row_num, int column_num) {
		int result = 0;

		if (grid[index_row][index_column] == 0) {
			return 0;
		}

		// Up
		if (((index_row - 1) < 0) || (grid[index_row - 1][index_column] == 0)) {
			result++;
		}

		// Down
		if (((index_row + 1) >= row_num) || (grid[index_row + 1][index_column] == 0)) {
			result++;
		}

		// Left
		if (((index_column - 1) < 0) || (grid[index_row][index_column - 1] == 0)) {
			result++;
		}

		// Right
		if (((index_column + 1) >= column_num) || (grid[index_row][index_column + 1] == 0)) {
			result++;
		}

		return result;
	}

    int islandPerimeter(vector< vector<int> >& grid) {

    	int result = 0;

    	int row_num = grid.size();
    	int column_num = grid[0].size();
    	cout << row_num << "-" << column_num << endl;
    	int index_row = 0;
    	int index_column = 0;
    	for (; index_row < row_num; index_row++) {
    		index_column = 0;
    		for (; index_column < column_num; index_column++) {
    			if (grid[index_row][index_column] == 1) {
    				result += checkPerimeter(grid, index_row, index_column, row_num, column_num);
    			}

			}
    	}

    	return result;
    }
};

int main() {

	vector< vector<int> > grid;
	vector<int> row_0;
	row_0.push_back(0);
	row_0.push_back(1);
	row_0.push_back(0);
	row_0.push_back(0);
	grid.push_back(row_0);
	vector<int> row_1;
	row_1.push_back(1);
	row_1.push_back(1);
	row_1.push_back(1);
	row_1.push_back(0);
	grid.push_back(row_1);
	vector<int> row_2;
	row_2.push_back(0);
	row_2.push_back(1);
	row_2.push_back(0);
	row_2.push_back(0);
	grid.push_back(row_2);
	vector<int> row_3;
	row_3.push_back(1);
	row_3.push_back(1);
	row_3.push_back(0);
	row_3.push_back(0);
	grid.push_back(row_3);
//	vector< vector<int> >::size_type row_num = grid.size();
//	vector< vector<int> >::size_type column_num = grid[0].size();
//	cout << row_num << "-" << column_num << endl;
//	for (vector< vector<int> >::iterator iter_1 = grid.begin(); iter_1 != grid.end(); iter_1++) {
//		for (vector<int>::iterator iter_2 = (*iter_1).begin(); iter_2 != (*iter_1).end(); iter_2++) {
//			cout << (*iter_2) << " ";
//		}
//		cout << endl;
//	}

	Solution solution;
	int result = solution.islandPerimeter(grid);
	cout << "result:" << result << endl;
	return 0;
}

