/*
 * main.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: yl
 */

/*
 *
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    	bool result = false;

    	set<int> set_num;
    	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
    		if (set_num.find(*iter) == set_num.end()) {
    			set_num.insert(*iter);
    		} else {
    			return true;
    		}
    	}

    	return result;
    }
};

int main() {

	int arr[] = {1, 2, 3, 5, 6};
	size_t len = sizeof(arr) / sizeof(int);
	vector<int> nums(arr, arr + len);
	Solution solution;
	bool result = solution.containsDuplicate(nums);

	cout << result << endl;

	return 0;
}
