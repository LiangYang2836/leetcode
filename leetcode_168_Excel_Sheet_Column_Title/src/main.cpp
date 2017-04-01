/*
 * main.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: yl
 */

/*
 *
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB


    53 -> BA
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {

    	string result = "";
    	stack<char> stack_char;
    	char c;
    	while (n > 0) {
    		n--;
    		c = 'A' + (n % 26);
    		stack_char.push(c);
    		n = n / 26;
    	}

    	while (!stack_char.empty()) {
    		result += stack_char.top();
    		stack_char.pop();
    	}

    	return result;
    }
};

int main() {

	int n = 26;

	Solution solution;
	string result = solution.convertToTitle(n);
	cout << "result:" << result << endl;
	return 0;
}
