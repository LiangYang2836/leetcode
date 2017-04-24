/*
 * main.cpp
 *
 *  Created on: Apr 24, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* CreateTree(int arr[], int i, int len) {

	if (arr == NULL || i >= len) {
		return NULL;
	}

	TreeNode *node = new TreeNode();
	node->val = arr[i];
	node->left = CreateTree(arr, 2 * i + 1, len);
	node->right = CreateTree(arr, 2 * i + 2, len);
	return node;
}

void preOrder(TreeNode *root) {
	if (root != NULL) {
		cout << root->val << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int len = sizeof(arr) / sizeof(int);
	TreeNode* root = CreateTree(arr, 0, len);
	preOrder(root);
	return 0;
}

