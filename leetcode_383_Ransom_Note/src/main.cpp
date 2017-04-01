/*
 * main.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: yl
 */

/*
 *
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

    	bool result = true;

    	int arr_letter[26] = {0};

    	int len_magazine = (int)magazine.size();
    	for (int i = 0; i < len_magazine; i++) {
    		arr_letter[magazine[i] - 'a']++;
    	}

    	int len_ransomNote = (int)ransomNote.size();
    	for (int i = 0; i < len_ransomNote; i++) {
    		arr_letter[ransomNote[i] - 'a']--;
    		if (arr_letter[ransomNote[i] - 'a'] < 0) {
    			return false;
    		}
    	}

    	return result;
    }
};

int main() {

	string ransomNote = "aa";
	string magazine = "ab";

	Solution solution;
	bool result = solution.canConstruct(ransomNote, magazine);
	cout << result << endl;

	return 0;
}
