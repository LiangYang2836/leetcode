/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

"aadadaad"

 */

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

    	vector<int> count(26);
		for (int i = 0; i < s.size(); i++) {
			count[s[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (count[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
    	/*int index = -1;

    	map<char, int> map_s;
    	set<char> set_s;

    	for (string::size_type i = 0; i < s.size(); i++) {
    		if ((map_s.find(s[i]) == map_s.end()) && (set_s.find(s[i]) == set_s.end())) {
    			map_s[s[i]] = i;
    		} else {
    			map_s.erase(s[i]);
    			set_s.insert(s[i]);
    		}
    	}

    	for (map<char, int>::iterator iter = map_s.begin(); iter != map_s.end(); iter++) {
//    		cout << iter->first << " - " << iter->second << endl;
    		if (index == -1 || index > iter->second) {
    			index = iter->second;
    		}
    	}

    	return index;*/
    }
};

int main() {

	string s = "loveleetcode";
	Solution solution;
	int result = solution.firstUniqChar(s);
	cout << "result:" << result << endl;

	return 0;
}

