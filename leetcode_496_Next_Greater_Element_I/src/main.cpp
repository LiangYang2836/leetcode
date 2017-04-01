/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

    	vector<int> result;
    	int tmp_ret = -1;
    	bool found = false;
    	for (vector<int>::iterator iter_1 = findNums.begin(); iter_1 != findNums.end(); iter_1++) {
    		tmp_ret = -1;
    		found = false;
    		for (vector<int>::iterator iter_2 = nums.begin(); iter_2 != nums.end(); iter_2++) {
    			if ((*iter_1) == (*iter_2)) {
    				found = true;
    				continue;
    			}

    			if (found) {
    				if ((*iter_1) < (*iter_2)) {
    					tmp_ret = (*iter_2);
    					break;
    				}
    			}
    		}

    		result.push_back(tmp_ret);
    	}
    	return result;
    }
};

int main() {
	Solution solution;

	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(1);
	nums1.push_back(2);
	vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(3);
	nums2.push_back(4);
	nums2.push_back(2);

	vector<int> result = solution.nextGreaterElement(nums1, nums2);

	for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}
