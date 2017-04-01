/*
 * main.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: yl
 */

/*
 *
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

"ccc"
3

"ababababa"
9
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

	void cal(int value, int &even_num, int &odd_num) {
		if (value % 2 == 0) {
			even_num += value;
		} else {
			even_num += value - 1;

			if (odd_num == 0) {
				odd_num = 1;
			}
		}
	}
    int longestPalindrome(string s) {

    	int length = 0;

    	int arr_low_letters[26] = {0};
    	int arr_up_letters[26] = {0};

    	int len = (int)s.size();

    	for (int i = 0; i < len; i++) {
    		if (s[i] >= 'a' && s[i] <= 'z') {
    			arr_low_letters[s[i] - 'a']++;
    		}
    		if (s[i] >= 'A' && s[i] <= 'Z') {
    			arr_up_letters[s[i] - 'A']++;
			}
    	}

    	int even_num = 0;
    	int odd_num = 0;
    	for (int i = 0; i < 26; i++) {
    		cal(arr_low_letters[i], even_num, odd_num);
    		cal(arr_up_letters[i], even_num, odd_num);
    	}

    	length += even_num + odd_num;

    	return length;
    }
};

int main() {

	string s = "ababababa";

	Solution solution;
	int length = solution.longestPalindrome(s);

	cout << "length:" << length << endl;

	return 0;
}
