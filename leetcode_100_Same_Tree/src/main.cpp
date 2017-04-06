/*
 * main.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

    	if (p == NULL && q == NULL) {
    		return true;
    	}

    	if (p == NULL || q == NULL) {
    		return false;
    	}

    	bool result = false;

    	if (p->val != q->val) {
    		return false;
    	} else {
    		result = isSameTree(p->left, q->left);
    		if (result) {
    			result = isSameTree(p->right, q->right);
    		}
    	}

    	return result;
    }
};


void pre_binary_tree(const TreeNode *root) {

	if (root != NULL) {
		cout << root->val << " ";
		pre_binary_tree(root->left);
		pre_binary_tree(root->right);
	}
}

void in_binary_tree(const TreeNode *root) {

	if (root != NULL) {
		in_binary_tree(root->left);
		cout << root->val << " ";
		in_binary_tree(root->right);
	}
}

void post_binary_tree(const TreeNode *root) {

	if (root != NULL) {
		post_binary_tree(root->left);
		post_binary_tree(root->right);
		cout << root->val << " ";
	}
}

TreeNode* construct_binary_tree(int *pre, int *in, int length) {

	if (pre == NULL || in == NULL || length == 0) {
		return NULL;
	}

	int first = pre[0];
	TreeNode *root = new TreeNode(first);

	int index = 0;
	for (; index < length; index++) {
		if (in[index] == first) {
			break;
		}
	}

	if (index < length) {
		root->val = first;
		root->left = construct_binary_tree(pre + 1, in, index);
		root->right = construct_binary_tree(pre + index + 1, in + index + 1, length - index - 1);
	}

	return root;

}

void display_binary_tree(const TreeNode *root) {

//	cout << __FUNCTION__ << endl;
	pre_binary_tree(root);
	cout << endl;
	in_binary_tree(root);
	cout << endl;
	post_binary_tree(root);
	cout << endl;
}

void destroy_binary_tree(TreeNode **root) {

	if (*root != NULL) {
		destroy_binary_tree(&(*root)->left);
		destroy_binary_tree(&(*root)->right);
		delete *root;
		*root = NULL;
	}
}


int main() {

	const int length = 8;
	int preorder[] = {1, 2, 9, 7, 3, 5, 6, 8};
	int inorder[] = {9, 7, 2, 1, 5, 3, 8, 6};

	TreeNode *root = construct_binary_tree(preorder, inorder, length);

	int preorder_2[] = {1, 2, 9, 7, 3, 5, 6, 8};
	int inorder_2[] = {9, 7, 2, 1, 5, 3, 8, 6};
	TreeNode *root_2 = construct_binary_tree(preorder_2, inorder_2, length);


	Solution solution;
	bool result = solution.isSameTree(root, root_2);
	cout << "result:" << result << endl;

	if (root != NULL) {
		cout << "Display Binary Tree." << endl;
		display_binary_tree(root);
		cout << "Destroy Binary Tree." << endl;
		destroy_binary_tree(&root);
		display_binary_tree(root);
	}

	if (root_2 != NULL) {
		cout << "Display Binary Tree." << endl;
		display_binary_tree(root_2);
		cout << "Destroy Binary Tree." << endl;
		destroy_binary_tree(&root_2);
		display_binary_tree(root_2);
	}

	return 0;
}

