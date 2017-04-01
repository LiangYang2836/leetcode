/*
 * main.cpp
 *
 *  Created on: Mar 13, 2017
 *      Author: yl
 */



/*
 *
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

 */

#include <iostream>
#include <time.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

    	int dist = 0;

    	int xor_value = x ^ y;
//    	cout << "xor_value:" <<  xor_value<< endl;

    	while (xor_value != 0) {
    		if ((xor_value & 1) == 1) {
    			dist++;
    		}

    		xor_value = xor_value >> 1;
    	}

    	return dist;
    }
};

int main() {

	clock_t start_time = clock();
	Solution solution;
	int x = 1;
	int y = 4;
	int dist = solution.hammingDistance(x, y);

	cout << "dist:" << dist << endl;
	clock_t end_time = clock();
	//输出运行时间
	cout<< "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	return 0;
}
