/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include <iostream>
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
    int maxDepth(TreeNode* root) {

    	int depth = 0;

    	if (root == NULL) {
    		return depth;
    	}

    	int left = maxDepth(root->left);
    	int right = maxDepth(root->right);

    	depth = (left > right ? left : right) + 1;
    	return depth;
    }
};

int main() {

	TreeNode *root = new TreeNode(0);
	TreeNode *left_1 = new TreeNode(1);
	TreeNode *right_1 = new TreeNode(2);
	root->left = left_1;
	root->right = right_1;

	TreeNode *left_2 = new TreeNode(3);
	TreeNode *right_2 = new TreeNode(4);
	left_1->left = left_2;
	left_1->right = right_2;

	TreeNode *right_3 = new TreeNode(5);
	left_2->right = right_3;

	Solution solution;
	int depth = solution.maxDepth(root);
	cout << "depth:" << depth << endl;

	delete root;
	delete left_1;
	delete right_1;
	delete left_2;
	delete right_2;
	delete right_3;
	return 0;
}
