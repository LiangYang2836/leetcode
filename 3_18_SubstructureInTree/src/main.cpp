/*
 * main.cpp
 *
 *  Created on: Mar 6, 2017
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

bool SourceIncludesDestination(BinaryTreeNode *root_source, BinaryTreeNode *root_destination) {


	if (root_destination == NULL) {
		return true;
	}

	if (root_source == NULL) {
		return false;
	}

	cout << __FUNCTION__ << root_source->m_i_value << "-" << root_destination->m_i_value << endl;
	bool b_include = false;

	if (root_source->m_i_value == root_destination->m_i_value) {
		b_include = SourceIncludesDestination(root_source->m_p_left, root_destination->m_p_left);
		if (b_include == true) {
			b_include = SourceIncludesDestination(root_source->m_p_right, root_destination->m_p_right);
		}
	}


	return b_include;
}

bool CheckSubTree(BinaryTreeNode *root_source, BinaryTreeNode *root_destination) {

	if (root_destination == NULL) {
		return true;
	}

	if (root_source == NULL) {
		return false;
	}

	cout << __FUNCTION__ << root_source->m_i_value << "-" << root_destination->m_i_value << endl;
	bool is_sub_tree = false;

	if (root_source->m_i_value == root_destination->m_i_value) {
		is_sub_tree = SourceIncludesDestination(root_source, root_destination);
	} else {
		is_sub_tree = CheckSubTree(root_source->m_p_left, root_destination);

		if (is_sub_tree == false) {
			CheckSubTree(root_source->m_p_right, root_destination);
		}
	}

	return is_sub_tree;

}

int main() {


	const int length_1 = 7;
	int preorder_1[] = {1, 2, 4, 5, 6, 7, 3};
	int inorder_1[] = {4, 2, 6, 5, 7, 1, 3};

//	const int length_2 = 3;
//	int preorder_2[] = {2, 4, 5};
//	int inorder_2[] = {4, 2, 5};

	const int length_2 = 5;
	int preorder_2[] = {2, 4, 5, 6, 7};
	int inorder_2[] = {4, 2, 6, 5, 7};

	BinaryTreeNode *root_1 = construct_binary_tree(preorder_1, inorder_1, length_1);
	display_binary_tree(root_1);
//	if (root_1 != NULL) {
//		cout << "Display Binary Tree." << endl;
//		display_binary_tree(root_1);
//		cout << "Destroy Binary Tree." << endl;
//		destroy_binary_tree(&root_1);
//		display_binary_tree(root_1);
//	}

	BinaryTreeNode *root_2 = construct_binary_tree(preorder_2, inorder_2, length_2);
	display_binary_tree(root_2);
//	if (root_2 != NULL) {
//		cout << "Display Binary Tree." << endl;
//		display_binary_tree(root_2);
//		cout << "Destroy Binary Tree." << endl;
//		destroy_binary_tree(&root_2);
//		display_binary_tree(root_2);
//
//	}

	if (root_1 != NULL && root_2 != NULL) {
		cout << CheckSubTree(root_1, root_2) << endl;
	}

	destroy_binary_tree(&root_1);
	display_binary_tree(root_1);
	destroy_binary_tree(&root_2);
	display_binary_tree(root_2);

	return 0;
}

