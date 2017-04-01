/*
 * main.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: yl
 */

/*
 *
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

[]
[]
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    	vector<int> result;
    	set<int> set_ret;
    	set<int> set_1;
    	for (vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++) {
    		set_1.insert(*iter);
    	}
    	set<int> set_2;
    	for (vector<int>::iterator iter = nums2.begin(); iter != nums2.end(); iter++) {
    		set_2.insert(*iter);
		}

    	for (set<int>::iterator iter = set_1.begin(); iter != set_1.end(); iter++) {
    		if (set_2.find(*iter) != set_2.end()) {
    			set_ret.insert(*iter);
    		}
    	}

    	for (set<int>::iterator iter = set_ret.begin(); iter != set_ret.end(); iter++) {
			result.push_back(*iter);
		}
    	return result;
    }
};

int main() {

	int array_1[] = {1, 2, 2, 1};
	size_t len_1 = sizeof(array_1) / sizeof(int);
	int array_2[] = {2, 2};
	size_t len_2 = sizeof(array_2) / sizeof(int);
	vector<int> nums1(array_1, array_1 + len_1);
	vector<int> nums2(array_2, array_2 + len_2);
	Solution solution;
	vector<int> result = solution.intersection(nums1, nums2);
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}

