/*
 * main.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: yl
 */

/*
 *
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {

    	string::size_type length = word.size();

		if (length <= 1) {
			return true;
		}

		string::size_type num_lower = 0;
		string::size_type num_upper = 0;
    	bool first_upper = false;

    	for (string::size_type i = 0; i < length; i++) {
    		if (word[i] >= 'a' && word[i] <= 'z') {
    			if (i == 0) {
    				first_upper = false;
    			}
				num_lower++;
			} else if (word[i] >= 'A' && word[i] <= 'Z') {
				if (i == 0) {
					first_upper = true;
				}
				num_upper++;
			}
    	}
//    	cout << "first_upper:" << first_upper << endl;
//    	cout << "num_upper:" << num_upper << endl;
    	if (num_lower == length || num_upper == length) {
    		return true;
    	} else {
    		if (!first_upper) {
    			if (num_upper > 0) {
    				return false;
    			}
    		} else {
    			if (num_upper <= 1) {
    				return true;
    			}
    		}
    	}

    	return false;
    	/*string::size_type length = word.size();

    	if (length <= 1) {
    		return true;
    	}

    	bool first_up = false;
    	bool all_lower = false;
    	bool all_upper = false;
    	for (string::size_type i = 0; i < length; i++) {
    		if (i == 0) {
    			if (word[i] >= 'a' && word[i] <= 'z') {
    				first_up = false;
    			} else if (word[i] >= 'A' && word[i] <= 'Z') {
    				first_up = true;
    			}
    		} else {
    			if (word[i] >= 'A' && word[i] <= 'Z') {
    				all_upper = true;
    			} else if (word[i] >= 'a' && word[i] <= 'z') {
    				all_lower = true;
    			}
    		}

    		if (!first_up) {
    			if (all_upper) {
    				return false;
    			}
    		} else {
    			if (all_upper == true && all_lower == true) {
    				return false;
    			}
    		}
    	}

    	if (!first_up) {
			if (all_lower && !all_upper) {
				return true;
			}
		} else {
			if (all_upper || all_lower) {
				return true;
			}
		}
    	return false;*/
    }
};

int main() {

	Solution solution;
	string word = "Google";

	bool result = solution.detectCapitalUse(word);

	cout << "result:" << result << endl;
	return 0;
}
