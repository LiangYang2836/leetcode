/*
 * main.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: yl
 */

/*
 *
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
 */

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {

    	int num = 0;

    	int len = (int)s.size();
    	for (int i = 0; i < len; i++) {
    		num *= 26;
    		num += (s[i] - 'A' + 1);
    	}

    	return num;
    }
};

int main() {

	string s = "ABB";
	Solution solution;
	int num = solution.titleToNumber(s);
	cout << num << endl;
	return num;

	return 0;
}
