/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: yl
 */

/*
 *
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*class Solution {
public:
    void deleteNode(ListNode* node) {

    	ListNode* next = node->next;
		*node = *next;
		delete next;

    	if (node == NULL) {
    		return;
    	}

    	ListNode *pre_node = node;
    	ListNode *next_node = node->next;
    	while (next_node != NULL) {
    		node->val = next_node->val;
    		pre_node = node;
    		node = next_node;
    		next_node = node->next;
    	}
    	pre_node->next = NULL;
    	delete node;
    }
};*/


class Solution {
public:
    void deleteNode(ListNode* node) {

    	if (node == NULL || node->next == NULL) {
    		return;
    	}

    	ListNode *node_next = node->next;
    	node->val = node_next->val;
    	node->next = node_next->next;

    	delete node_next;
    }
};

int main() {

	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	ListNode *node = node1;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Solution solution;
	solution.deleteNode(node3);
	cout << "Fater:" << endl;
	node = node1;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	delete node1;
	delete node2;
	delete node3;
	delete node4;

	return 0;
}
