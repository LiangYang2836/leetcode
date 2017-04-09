/*
 * main.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: yl
 */

#include <iostream>
#include <stack>
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

void MirrorOfBinaryTree(BinaryTreeNode *p_tree_root) {

	if (p_tree_root == NULL) {
		return;
	}

	BinaryTreeNode *p_tree_node = p_tree_root->m_p_left;
	p_tree_root->m_p_left = p_tree_root->m_p_right;
	p_tree_root->m_p_right = p_tree_node;

	MirrorOfBinaryTree(p_tree_root->m_p_left);
	MirrorOfBinaryTree(p_tree_root->m_p_right);

}

void SwitchLeftRight(BinaryTreeNode *p_tree_node) {

	if (p_tree_node == NULL) {
		return;
	}

	BinaryTreeNode *p_tree_tmp_node = p_tree_node->m_p_left;
	p_tree_node->m_p_left = p_tree_node->m_p_right;
	p_tree_node->m_p_right = p_tree_tmp_node;

}

void MirrorOfBinaryTreeLoop(BinaryTreeNode *p_tree_root) {

	if (p_tree_root == NULL) {
		return;
	}

	stack<BinaryTreeNode*> stack;
	BinaryTreeNode *p_tree_cur = p_tree_root;

	while (p_tree_cur != NULL || !stack.empty()) {

		while (p_tree_cur != NULL) {
			SwitchLeftRight(p_tree_cur);
//			cout << "left:" << p_tree_cur->m_i_value << endl;
			stack.push(p_tree_cur);
			p_tree_cur = p_tree_cur->m_p_left;
		}

		if (!stack.empty()) {
			p_tree_cur = stack.top();
			stack.pop();
			p_tree_cur = p_tree_cur->m_p_right;

		}
	}
}

int main() {

	const int length = 8;
	int preorder[] = {1, 2, 9, 7, 3, 5, 6, 8};
	int inorder[] = {9, 7, 2, 1, 5, 3, 8, 6};

	BinaryTreeNode *root = construct_binary_tree(preorder, inorder, length);

	if (root != NULL) {
		cout << "Display Binary Tree." << endl;
		display_binary_tree(root);

//		MirrorOfBinaryTree(root);
		MirrorOfBinaryTreeLoop(root);
		display_binary_tree(root);
		cout << "Destroy Binary Tree." << endl;
		destroy_binary_tree(&root);
		display_binary_tree(root);

	}

	return 0;
}


