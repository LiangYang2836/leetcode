/*
 * main.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: yl
 */

/*
 *
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

[1,1,1]

[1,2147483647]
 */

#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:

	bool check(vector<int>& nums) {
		bool result = true;

		int len = (int)nums.size();
		for (int i = 0; i < len - 1; i++) {
			if (nums[i] != nums[i + 1]) {
				return false;
			}
		}

		return result;
	}

    int minMoves(vector<int>& nums) {

    	if (check(nums)) {
			return 0;
		}

    	int num = 0;

    	int len = (int)nums.size();

    	while (true) {
    		int max = -1;
    		int max_index = 0;
    		for (int i = 0; i < len; i++) {
    			nums[i]++;
    			if (max == -1 || max < nums[i]) {
    				max = nums[i];
    				max_index = i;
    			}
    		}

//    		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
//    			cout << *iter << " ";
//    		}
//    		cout << endl;
    		num++;
    		nums[max_index]--;
    		if (check(nums)) {
				break;
			}
    	}

    	return num;
    }
};*/

/*
 *
 *
Adding 1 to n - 1 elements is the same as subtracting 1 from one element, w.r.t goal of making the elements in the array equal.
So, best way to do this is make all the elements in the array equal to the min element.
sum(array) - n * minimum



It is a math question
let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;

After, say m moves, we get all the numbers as x , and we will get the following equation

 sum + m * (n - 1) = x * n
and actually,

  x = minNum + m
and finally, we will get

  sum - minNum * n = m
So, it is clear and easy now.

 */
class Solution {
public:
    int minMoves(vector<int>& nums) {

    	int num = 0;

    	int len = (int)nums.size();
    	int min = nums[0];
    	for (int i = 0; i < len; i++) {
    		if (min > nums[i]) {
    			min = nums[i];
    		}
    	}

    	for (int i = 0; i < len; i++) {
    		num += (nums[i] - min);
    	}

    	return num;
    }
};


int main() {

	int array[] = {2,3,4,5};
	size_t len = sizeof(array) / sizeof(int);
	vector<int> nums(array, array + len);
	Solution solution;
	int num = solution.minMoves(nums);

	cout << "num:" << num << endl;

	return 0;
}
