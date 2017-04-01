/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

[1]

[3,2,3]
[3,3,4]
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

    	int result = 0;

    	map<int, int> map_nums;
    	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {

    		if (map_nums.find(*iter) == map_nums.end()) {
    			map_nums[*iter] = 1;
    		} else {
    			map_nums[*iter]++;
    		}
    	}

    	for (map<int, int>::iterator iter = map_nums.begin(); iter != map_nums.end(); iter++) {
    		cout << iter->first << " - " << iter->second << endl;
    		if (iter->second >= ((double)nums.size() / 2)) {
    			result = iter->first;
    		}
    	}

    	return result;
    }
};

int main() {

//	int array[] = {1, 2, 5, 6, 3, 5, 6, 6, 6, 6, 6, 6, 8, 7};
	int array[] = {3,3,4};
	size_t len = sizeof(array) / sizeof(int);
	vector<int> nums(array, array + len);
	Solution solution;
	int result = solution.majorityElement(nums);
	cout << "result:" << result << endl;

	return 0;
}
