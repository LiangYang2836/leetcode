/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

[1,2]
[3,9,20,null,null,15,7]
 */

#include <iostream>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool b_left = false) {

    	if (root == NULL) {
    		return 0;
    	}

    	int sum = 0;

    	if (b_left == true && root->left == NULL && root->right == NULL) {
    		return root->val;
    	}

    	sum += sumOfLeftLeaves(root->left, true);
    	sum += sumOfLeftLeaves(root->right, false);

    	return sum;
    }
};

int main() {

	TreeNode *root = new TreeNode(3);
	TreeNode *left_1 = new TreeNode(9);
	TreeNode *right_1 = new TreeNode(20);
	root->left = left_1;
	root->right = right_1;

	TreeNode *left_2 = new TreeNode(15);
	TreeNode *right_2 = new TreeNode(7);
	right_1->left = left_2;
	right_1->right = right_2;

	Solution solution;
	int sum = solution.sumOfLeftLeaves(root);
	cout << "sum:" << sum << endl;

	delete root;
	delete left_1;
	delete right_1;
	delete left_2;
	delete right_2;

	return 0;
}
