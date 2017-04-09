/*
 * main.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: yl
 */


#include <iostream>
using namespace std;

struct BinaryTreeNode {
	int m_i_value;
	BinaryTreeNode* m_p_left;
	BinaryTreeNode* m_p_right;
};

void pre_binary_tree(const BinaryTreeNode *root) {

	if (root != NULL) {
		cout << root->m_i_value << " ";
		pre_binary_tree(root->m_p_left);
		pre_binary_tree(root->m_p_right);
	}
}

void in_binary_tree(const BinaryTreeNode *root) {

	if (root != NULL) {
		in_binary_tree(root->m_p_left);
		cout << root->m_i_value << " ";
		in_binary_tree(root->m_p_right);
	}
}

void post_binary_tree(const BinaryTreeNode *root) {

	if (root != NULL) {
		post_binary_tree(root->m_p_left);
		post_binary_tree(root->m_p_right);
		cout << root->m_i_value << " ";
	}
}

BinaryTreeNode* construct_binary_tree(int *pre, int *in, int length) {

	if (pre == NULL || in == NULL || length == 0) {
		return NULL;
	}

	BinaryTreeNode *root = new BinaryTreeNode();

	int first = pre[0];
	int index = 0;
	for (; index < length; index++) {
		if (in[index] == first) {
			break;
		}
	}

	if (index < length) {
		root->m_i_value = first;
		root->m_p_left = construct_binary_tree(pre + 1, in, index);
		root->m_p_right = construct_binary_tree(pre + index + 1, in + index + 1, length - index - 1);
	}

	return root;

}

void display_binary_tree(const BinaryTreeNode *root) {

	cout << __FUNCTION__ << endl;
	pre_binary_tree(root);
	cout << endl;
	in_binary_tree(root);
	cout << endl;
	post_binary_tree(root);
	cout << endl;
}

void destroy_binary_tree(BinaryTreeNode **root) {

	if (*root != NULL) {
		destroy_binary_tree(&(*root)->m_p_left);
		destroy_binary_tree(&(*root)->m_p_right);
		delete *root;
		*root = NULL;
	}
}


int main() {


//	const int length = 8;
//	int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
//	int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};

//	const int length = 5;
//	int preorder[length] = {1, 2, 3, 4, 5};
//	int inorder[length] = {5, 4, 3, 2, 1};

//	const int length = 7;
//	int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
//	int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

	const int length = 1;
	int preorder[length] = {2};
	int inorder[length] = {2};

	BinaryTreeNode *root = construct_binary_tree(preorder, inorder, length);

	if (root != NULL) {
		cout << "Display Binary Tree." << endl;
		display_binary_tree(root);
		cout << "Destroy Binary Tree." << endl;
		destroy_binary_tree(&root);
		display_binary_tree(root);

	}

	return 0;
}


