/*
 * main.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: yl
 */

/*
 *
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

    	vector<int> results;
    	int index_low = 0;
    	int index_high = (int)numbers.size() - 1;
    	while ((numbers[index_low] + numbers[index_high]) != target) {
    		if ((numbers[index_low] + numbers[index_high]) < target) {
    			index_low++;
    		} else {
    			index_high--;
    		}
    	}
    	results.push_back(index_low + 1);
    	results.push_back(index_high + 1);
    	return results;

    	/*vector<int> results;
    	int length = (int)numbers.size();
    	int left = 0;
    	for (int i = 0; i < length - 1; i ++) {
    		left = target - numbers[i];
    		for (int j = i + 1; j < length; j++) {
    			if (left == numbers[j]) {
    				results.push_back(i + 1);
    				results.push_back(j + 1);
    				return results;
    			}
    		}
    	}

    	return results;*/
    }
};

int main() {

	int target = 9;
	int array[] = {2, 7, 11, 15};
	size_t length = sizeof(array) / sizeof(int);
	vector<int> nums(array, array + length);
	Solution solution;
	vector<int> results = solution.twoSum(nums, target);

	for (vector<int>::iterator iter = results.begin(); iter != results.end(); iter++) {
		cout << "indices:" << *iter << endl;
	}
	return 0;
}
