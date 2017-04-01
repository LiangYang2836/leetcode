/*
 * main.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: yl
 */

/*
 *
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	int partition(vector<int> &arr, int low, int high) {

		int position = 0;

		int tmp = 0;
		while (low < high) {
			tmp = arr[low];
			while (low < high && arr[high] > tmp) {
				high--;
			}

			if (low < high) {
				swap(arr[low++], arr[high]);
			}
			while (low < high && arr[low] < tmp) {
				low++;
			}
			if (low < high) {
				swap(arr[low], arr[high--]);
			}
		}

		arr[low] = tmp;
		position = low;

		return position;
	}

	void quickSort(vector<int> &arr, int low, int high) {
		int position = 0;
		if (low < high) {
			position = partition(arr, low, high);
			quickSort(arr, low, position - 1);
			quickSort(arr, position + 1, high);
		}

	}

	void sortArr(vector<int> &arr) {
		quickSort(arr, 0, (int)arr.size() - 1);
	}

	void showArr(vector<int> &arr) {
		for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
			cout << *iter << " ";
		}
		cout << endl;
	}

    int findContentChildren(vector<int>& g, vector<int>& s) {

    	int num = 0;

    	sortArr(g);
    	showArr(g);
    	sortArr(s);
    	showArr(s);

    	vector<int>::iterator iter_g = g.begin();
    	vector<int>::iterator iter_s = s.begin();

    	while (iter_g != g.end() && iter_s != s.end()) {

    		while (iter_s != s.end() && *iter_s < *iter_g) {
    			iter_s++;
    		}
    		if (iter_s == s.end() || *iter_s < *iter_g) {
    			break;
    		}
//    		cout << *iter_s << "/" << *iter_g << endl;
    		if (*iter_s >= *iter_g) {
    			num++;
    		}

    		iter_g++;
    		iter_s++;
//    		cout << num << endl;
    	}
//    	cout << num << endl;
    	return num;

    }
};

int main() {

	int array_1[] = {1, 2, 3};
	size_t len_1 = sizeof(array_1) / sizeof(int);
	vector<int> g(array_1, array_1 + len_1);

	int array_2[] = {1, 1};
	size_t len_2 = sizeof(array_2) / sizeof(int);
	vector<int> s(array_2, array_2 + len_2);

	Solution solution;

	int num = solution.findContentChildren(g, s);
	cout << num << endl;


	return 0;
}


