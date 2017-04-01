/*
 * main.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: yl
 */

/*
 *
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.


[0, 1, 0, 3, 12]
[0, 0, 1]
[2, 1]

 */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    	if (nums.size() == 0 || nums.size() == 1) {
    		return;
    	}

//    	swap(nums[1], nums[2]);

    	vector<int>::iterator iter_i = nums.begin();
    	vector<int>::iterator iter_j = iter_i + 1;
    	while (iter_i != nums.end() && iter_j != nums.end()) {
    		while (iter_i != nums.end() && *iter_i != 0) {
    			iter_i++;
    		}

    		iter_j = iter_i + 1;
    		while (iter_j != nums.end() && *iter_j == 0) {
    			iter_j++;
    		}
    		if (iter_i != nums.end() && iter_j != nums.end()) {
				swap(*iter_i++, *iter_j++);
	//    		iter_i++;
	//    		iter_j++;
    		}
    	}
    }
};


int main() {

	Solution solution;

	int iarray[] = {2, 1};
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> nums(iarray, iarray + count);

//	for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
//		cout<< "1 nums: " << *iter << endl;
//	}

	solution.moveZeroes(nums);

	for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
		cout<< "2 nums: " << *iter << endl;
	}

	return 0;
}
