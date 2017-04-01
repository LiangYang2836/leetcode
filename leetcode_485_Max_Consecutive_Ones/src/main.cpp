/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

    	int cur_consecutive_ones = 0;
    	int max_consecutive_ones = 0;
    	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
    		if (*iter == 1) {
    			cur_consecutive_ones++;
    		} else {

    			if (cur_consecutive_ones > max_consecutive_ones) {
    				max_consecutive_ones = cur_consecutive_ones;
    			}

    			cur_consecutive_ones = 0;
    		}
    	}

    	if (cur_consecutive_ones > max_consecutive_ones) {
			max_consecutive_ones = cur_consecutive_ones;
		}

    	return max_consecutive_ones;
    }
};

int main() {

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);

	Solution solution;
	int max_consecutive_ones = solution.findMaxConsecutiveOnes(nums);
	cout << "max_consecutive_ones:" << max_consecutive_ones << endl;
	return 0;
}


