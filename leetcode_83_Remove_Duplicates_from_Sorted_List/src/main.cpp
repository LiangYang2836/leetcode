/*
 * main.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: yl
 */

/*
 *
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {

    	if (head == NULL) {
    		return NULL;
    	}

    	ListNode *p_cur = head;
    	ListNode *p_next = head->next;
    	ListNode *p_tmp = NULL;
    	while (p_cur != NULL && p_next != NULL) {
    		if (p_cur->val != p_next->val) {
    			p_cur = p_next;
    			p_next = p_next->next;
    		} else {
    			p_tmp = p_next;
    			p_next = p_next->next;
    			p_cur->next = p_next;
    			delete p_tmp;
    		}
    	}

    	return head;

    	/*if (head == NULL) {
    		return NULL;
    	}

    	ListNode *p_new_head = NULL;
    	ListNode *p_new_tail = NULL;
    	while (head != NULL) {
    		if (p_new_tail == NULL) {
    			p_new_head = new ListNode(head->val);
    			p_new_tail = p_new_head;
    		} else {
    			if (p_new_tail->val < head->val) {
    				ListNode *tmp_node = new ListNode(head->val);
    				p_new_tail->next = tmp_node;
    				p_new_tail = p_new_tail->next;
    			}
    		}
    		head = head->next;
    	}

    	return p_new_head;*/
    }
};

int main() {

	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(4);
	ListNode *node6 = new ListNode(6);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	ListNode *node = node1;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Solution solution;
	node = solution.deleteDuplicates(node1);
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
