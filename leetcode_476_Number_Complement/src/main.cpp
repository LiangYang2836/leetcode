/*
 * main.cpp
 *
 *  Created on: Mar 13, 2017
 *      Author: yl
 */

/*
 *
 *
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

Input: 2
Output: 1

 */

#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
    	int ret = 0;
    	int tmp = 0;
    	int bit_index = 0;
    	while (num != 0) {
    		tmp = (num & 1) ^ 1;
    		ret = ret | (tmp << bit_index);
    		bit_index++;
    		num = num >> 1;
    	}

    	return ret;
    }
};

int main() {

	Solution solution;
	int num = 5;
	int ret = solution.findComplement(num);

	cout << "ret:" << ret << endl;
	return 0;
}
