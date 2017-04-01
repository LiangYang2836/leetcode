/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
	Solution() {
		buf_3 = "Fizz";
		buf_5 = "Buzz";
		buf_3_5 = "FizzBuzz";
	}

    vector<string> fizzBuzz(int n) {

    	vector<string> result;
    	char buf[10];

    	for (int i = 1; i <= n; i++) {
    		if (i % 15 == 0) {
    			result.push_back(buf_3_5);
    		} else if (i % 3 == 0) {
    			result.push_back(buf_3);
    		} else if (i % 5 == 0) {
    			result.push_back(buf_5);
    		} else {
    			sprintf(buf, "%d", i);
				result.push_back(buf);
    		}
//    		if (i % 3 == 0) {
//    			if (i % 5 == 0) {
//    				result.push_back(buf_3_5);
//    			} else {
//    				result.push_back(buf_3);
//    			}
//
//    		} else if (i % 5 == 0) {
//    			result.push_back(buf_5);
//    		} else {
//				sprintf(buf, "%d", i);
//    			result.push_back(buf);
//    		}
    	}

    	return result;
    }

private:
    string buf_3;
    string buf_5;
    string buf_3_5;
};

int main() {

	int n = 15;
	Solution solution;
	vector<string> result = solution.fizzBuzz(n);

	cout << "Result:" << endl;
	for (vector<string>::iterator iter = result.begin();
			iter != result.end(); iter++) {
		cout << *iter << endl;
	}
	return 0;
}


