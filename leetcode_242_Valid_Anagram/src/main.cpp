/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

    	int len_s = (int)s.size();
    	int len_t = (int)t.size();

    	if (len_s != len_t) {
    		return false;
    	}

    	bool result = true;

    	vector<int> count_s(26);
    	for (int i = 0; i < len_s; i++) {
    		count_s[s[i] - 'a']++;
    	}

    	vector<int> count_t(26);
    	for (int i = 0; i < len_t; i++) {
			count_t[t[i] - 'a']++;
		}

    	for (int i = 0; i < 26; i++) {
    		if (count_s[i] != count_t[i]) {
    			return false;
    		}
    	}

    	return result;

    }
};

int main() {

	string s = "rat";
	string t = "car";
	Solution solution;
	bool result = solution.isAnagram(s, t);
	cout << "result:" << result << endl;

	return 0;
}
