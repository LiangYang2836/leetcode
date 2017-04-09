/*
 * main.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: yl
 */

#include <iostream>
#include <deque>
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

void PrintFromTopToBottom(BinaryTreeNode *p_tree_root) {

	cout << __FUNCTION__ << endl;
	if (p_tree_root == NULL) {
		return;
	}

	deque<BinaryTreeNode*> deque;
	deque.push_back(p_tree_root);
	BinaryTreeNode *p_tree_node = NULL;
	while (!deque.empty()) {
		p_tree_node = deque.front();
		deque.pop_front();
		if (p_tree_node != NULL) {
			cout << p_tree_node->m_i_value << " ";
		}

		if (p_tree_node->m_p_left != NULL) {
			deque.push_back(p_tree_node->m_p_left);
		}

		if (p_tree_node->m_p_right != NULL) {
			deque.push_back(p_tree_node->m_p_right);
		}
	}

	cout << endl;

}

int main() {

	const int length = 7;
	int preorder[] = {8, 6, 5, 7, 10, 9, 11};
	int inorder[] = {5, 6, 7, 8, 9, 10, 11};

	BinaryTreeNode *root = construct_binary_tree(preorder, inorder, length);
	display_binary_tree(root);

	PrintFromTopToBottom(root);

	destroy_binary_tree(&root);
	display_binary_tree(root);


	return 0;
}


