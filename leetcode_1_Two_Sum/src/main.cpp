/*
 * main.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: yl
 */


/*
 *
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	map<int ,int> map_value_index;
    	vector<int> result;
    	int tmp_value;
    	for (vector<int>::size_type i = 0; i < nums.size(); i++) {
    		tmp_value = target - nums[i];
    		if (map_value_index.find(tmp_value) != map_value_index.end()) {
    			result.push_back(map_value_index[tmp_value]);
    			result.push_back(i);
    			return result;
    		}

    		map_value_index[nums[i]] = i;
    	}
//    	for (vector<int>::size_type i = 0; i < nums.size() - 1; i++) {
//    		for (vector<int>::size_type j = i + 1; j < nums.size(); j++) {
//    			if ((nums[i] + nums[j]) == target) {
//					result.push_back(i);
//					result.push_back(j);
//					return result;
//				}
//			}
//    	}
//        for (vector<int>::iterator iter = nums.begin(); iter != nums.end() - 1; iter++) {
//            for (vector<int>::iterator iter_2 = iter + 1; iter_2 != nums.end(); iter_2++) {
//            	if ((*iter + *iter_2) == target) {
//            		result.push_back(*iter);
//            		result.push_back(*iter_2);
//            		return result;
//            	}
//            }
//        }

        return result;
    }
};
void func(const int& v1, const int& v2)
{
    cout << v1 << ' ';
    cout << v2 << ' ';
}
int main() {

	vector<int> nums;
	nums.push_back(5);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(9);

	Solution *sulution = new Solution();
	vector<int> result = sulution->twoSum(nums, 10);
	if (!result.empty() && result.size() == 2) {
		cout << result[0] << " " << result[1] << endl;
	} else {
		cout << "No Match!" << endl;
	}
	delete sulution;

	int i=0;
	    func(++i,i++);

	return 0;
}


