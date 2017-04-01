/*
 * main.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    	if (l1 == NULL) {
    		return l2;
    	}

    	if (l2 == NULL) {
    		return l1;
    	}

    	ListNode *new_head = NULL;
    	ListNode *new_tail = NULL;
    	ListNode *cur_node = NULL;
    	while (l1 != NULL && l2 != NULL) {
    		if (l1->val < l2->val) {
    			cur_node = l1;
    			l1 = l1->next;
    		} else {
    			cur_node = l2;
    			l2 = l2->next;
    		}
    		if (new_tail == NULL) {
    			new_head = cur_node;
    			new_tail = new_head;
    		} else {
    			new_tail->next = cur_node;
    			new_tail = new_tail->next;
    			new_tail->next = NULL;
    		}
    	}

    	if (l1 != NULL) {
    		new_tail->next = l1;
    	}

    	if (l2 != NULL) {
    		new_tail->next = l2;
    	}

    	return new_head;
    }
};


int main() {

	ListNode *node11 = new ListNode(1);
	ListNode *node12 = new ListNode(3);
	ListNode *node13 = new ListNode(5);
	ListNode *node14 = new ListNode(7);
	node11->next = node12;
	node12->next = node13;
	node13->next = node14;

	ListNode *l1 = node11;

	cout << "l1:" << endl;
	while (l1 != NULL) {
		cout << l1->val << endl;
		l1 = l1->next;
	}

	l1 = node11;

	ListNode *node21 = new ListNode(2);
	ListNode *node22 = new ListNode(4);
	ListNode *node23 = new ListNode(6);
	ListNode *node24 = new ListNode(8);
	node21->next = node22;
	node22->next = node23;
	node23->next = node24;

	ListNode *l2 = node21;

	cout << "l2:" << endl;
	while (l2 != NULL) {
		cout << l2->val << endl;
		l2 = l2->next;
	}

	l2 = node21;
	Solution solution;
	ListNode *node = solution.mergeTwoLists(l1, l2);
	cout << "Sorted:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	delete node11;
	delete node12;
	delete node13;
	delete node14;
	delete node21;
	delete node22;
	delete node23;
	delete node24;

	return 0;
}

