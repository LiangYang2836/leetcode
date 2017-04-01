/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

""

" "


 */

#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

class Solution {
public:
    string reverseString(string s) {

//    	string::size_type len = s.size();
//
//    	if (len == 0 || len == 1) {
//    		return s;
//    	}
//
//    	string result = "";
//    	for (string::size_type i = 0; i < len; i++) {
//    		result.insert(0, 1, s[i]);
//    	}
//
//    	return result;

    	string::size_type len = s.size();

		if (len == 0 || len == 1) {
			return s;
		}
    	string::size_type begin = 0;
		string::size_type end = len - 1;

    	char tmp;
    	while (begin <= end) {
    		tmp = s[begin];
    		s[begin] = s[end];
    		s[end] = tmp;
    		begin++;
    		end--;
    	}

    	return s;
    }
};

int main() {

	Solution solution;
	string s = "abc";
	string result = solution.reverseString(s);
	cout << "result:" << result << endl;

	return 0;
}
