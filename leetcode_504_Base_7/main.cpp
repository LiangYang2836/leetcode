/*
 * main.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: yl
 */

/*
 *
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {

    	if (num == 0) {
    		return "0";
    	}
    	string result;
    	int flag = 0;
    	if (num < 0) {
    		flag = -1;
    		num *= -1;
    	}
    	stack<char> stack_num;
    	while (num > 0) {
//    		cout << (num % 7) << endl;
    		stack_num.push((num % 7) + '0');

    		num /= 7;
    	}

    	if (flag == -1) {
    		result += "-";
    	}

    	while (!stack_num.empty()) {
    		result += stack_num.top();
    		stack_num.pop();
    	}

    	return result;
    }
};

int main() {

	int num = -7;
	Solution solution;
	string result = solution.convertToBase7(num);
	cout << result << endl;
	return 0;
}
