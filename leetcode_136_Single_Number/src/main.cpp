/*
 * main.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: yl
 */

/*
 *
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	if (nums.empty()) {
    		return 0;
    	}
//		int first = nums[0];
		for(vector<int>::size_type i = 1; i < nums.size(); i++) {
//			cout << "nums[i]:" << nums[i] << endl;
			nums[0] = nums[0] ^ nums[i];
//			cout << "nums[0]:" << nums[0] << endl;
		}
		return nums[0];
    	/*int result = 0;

    	map<int, bool> map_value_times;
    	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
    		if (map_value_times.find(*iter) == map_value_times.end()) {
    			map_value_times[*iter] = true;
//    			map_value_times.insert(map<int, int>::value_type(*iter, 1));
//    			cout << "map_value_times[*iter]:" << map_value_times[*iter] << endl;
    		} else {
    			map_value_times.erase(*iter);
    		}
    	}

    	result = map_value_times.begin()->first;
//    	for (map<int, bool>::iterator iter = map_value_times.begin(); iter != map_value_times.end(); iter++) {
//    		cout << iter->first << " " << iter->second << endl;
//    		result = iter->first;
//    	}
    	return result;*/
    }
};

int main() {

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(5);

	Solution solution;
	cout << solution.singleNumber(nums) << endl;
	return 0;
}

