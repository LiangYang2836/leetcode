/*
 * main.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: yl
 */

/*
 *
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <bitset>
using namespace std;

class Solution {
public:
	int countNum(int value) {
		int num = 0;

		for (int i = 0; i < 10; i++) {
			if ((value & 1) == 1) {
				num++;
			}

			value = value >> 1;
		}

		return num;

	}
    vector<string> readBinaryWatch(int num) {

    	vector<string> result;
    	char c_h[5];
    	char c_m[5];
    	string tmp_str;
    	bitset<10> set_one;
    	for (int h = 0; h < 12; h++) {
    		for (int m = 0; m < 60; m++) {
    			set_one = bitset<10>((h << 6) | m);
    			cout << set_one << endl;
    			if ((int)set_one.count() == num) {
    				sprintf(c_h, "%d", h);
    				if (m < 10) {
    					sprintf(c_m, "0%d", m);
    				} else {
    					sprintf(c_m, "%d", m);
    				}
    				tmp_str = "";
    				tmp_str += c_h;
    				tmp_str += ":";
    				tmp_str += c_m;
    				result.push_back(tmp_str);
    			}

    		}
    	}

    	return result;
    }
};

int main() {

	int num = 1;
	Solution solution;
	vector<string> result = solution.readBinaryWatch(num);

	for (vector<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}
