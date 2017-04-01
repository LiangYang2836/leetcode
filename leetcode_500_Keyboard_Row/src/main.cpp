/*
 * main.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: yl
 */

/*
 *
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//char keyboard[][3] = {{'q', 'w', 'e'}, {'a', 's', 'd'}, {'z', 'x', 'c'}};


class Solution {
public:
	Solution() {
		string keyboard_row_1 = "qwertyuiop";
		keyboard.push_back(keyboard_row_1);
		string keyboard_row_2 = "asdfghjkl";
		keyboard.push_back(keyboard_row_2);
		string keyboard_row_3 = "zxcvbnm";
		keyboard.push_back(keyboard_row_3);
	}

	void showKeyboard() {
		for (vector<string>::iterator iter = keyboard.begin(); iter != keyboard.end(); iter++) {
    		cout << *iter << endl;
		}
	}

	bool checkWord(string& word) {

		bool ret = false;

		for (vector<string>::iterator iter = keyboard.begin(); iter != keyboard.end(); iter++) {
			bool flag = false;
//			cout << *iter << endl;
			for (string::size_type i = 0; i < word.size(); i++) {
//				cout << (char)tolower(word[i]) << endl;
				if ((int)(*iter).find(tolower(word[i])) != -1) {
					flag = true;
				} else {
					flag = false;
				}
//				cout << "flag:" << flag << endl;
				if (!flag) {
					break;
				}
			}

			if (flag) {
				return true;
			}
		}

		return ret;
	}

    vector<string> findWords(vector<string>& words) {

    	vector<string> result;

    	for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
//    		cout << *iter << endl;
    		string word = *iter;
//    		cout << word << endl;
    		if (checkWord(word)) {
    			result.push_back(word);
    		}
    	}

    	return result;
    }

private:
    vector<string> keyboard;
};

int main() {

	vector<string> words;
	words.push_back("Hello");
	words.push_back("Alaska");
	words.push_back("Dad");
	words.push_back("Peace");

	Solution solution;
//	solution.showKeyboard();
	vector<string> result = solution.findWords(words);

	cout << "Results:" << endl;
	for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}
