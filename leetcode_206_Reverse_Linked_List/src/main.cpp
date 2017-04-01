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
    ListNode* reverseList(ListNode* head) {

    	if (head == NULL) {
    		return NULL;
    	}

    	ListNode *p_pre = head;
    	head = head->next;
    	ListNode *p_next = NULL;
    	if (head != NULL) {
    		p_next = head->next;
    	}
    	p_pre->next = NULL;
    	while (head != NULL) {
//    		cout << "p_pre->val:" << p_pre->val << endl;
    		head->next = p_pre;
    		p_pre = head;
    		head = p_next;

    		if (head == NULL) {
    			break;
    		}
    		if (p_next != NULL) {
    			p_next = p_next->next;
    		}
    	}

    	return p_pre;
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
	node = solution.reverseList(node1);
	cout << "Fater:" << endl;
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

