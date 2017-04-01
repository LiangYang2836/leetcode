/*
 * main.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: yl
 */

/*
 *
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

    	vector<int> results;

    	int len = (int)nums.size();
    	int arr[len + 1] = {0};

    	for (int i = 0; i < len; i++) {
    		arr[nums[i]]++;
    	}

    	for (int i = 1; i <= len; i++) {
    		if (arr[i] == 0) {
    			results.push_back(i);
    		}
    	}

    	return results;
    }
};

int main() {

	int array[] = {4,3,2,7,8,2,3,1};
	size_t len = sizeof(array) / sizeof(int);
	vector<int> nums(array, array + len);

	Solution solution;
	vector<int> results = solution.findDisappearedNumbers(nums);

	for (vector<int>::iterator iter = results.begin(); iter != results.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}

