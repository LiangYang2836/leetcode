/*
 * main.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: yl
 */


/*
 *
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

[1]
1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    	if (head == NULL) {
    		return NULL;
    	}

    	ListNode *p1 = head;
    	ListNode *p1_pre = p1;
    	ListNode *p2 = head;

    	for (int i = 0; i < n; i++) {
    		p2 = p2->next;
    	}

    	while (p2 != NULL) {
    		p1_pre = p1;
    		if (p1 != NULL) {
    			p1 = p1->next;
    		}

    		p2 = p2->next;
    	}

    	if (p1 == p1_pre) {
    		p1 = p1->next;
    		head = p1;
    		delete p1_pre;
    		p1_pre = p1;
    	} else if (p1 != NULL) {
    		p1_pre->next = p1->next;
			delete p1;
    	}


    	return head;
    }
};


ListNode* CreateList(int arr[], int len) {

	ListNode *head = NULL;
	ListNode *tail = NULL;
	for (int i = 0; i < len; i++) {
		ListNode *node = new ListNode(arr[i]);
		if (tail == NULL) {
			head = node;
			tail = head;
		} else {
			tail->next = node;
			tail = tail->next;
		}
	}

	return head;
}

void Destroy(ListNode **head) {
	while ((*head) != NULL) {
		(*head) = (*head)->next;
		delete (*head);
	}
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(int);
	ListNode *head = CreateList(arr, len);

	ListNode *node = head;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	int n = 5;
	Solution solution;
	node = solution.removeNthFromEnd(head, n);
	cout << "After:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Destroy(&head);

	node = head;

	cout << "After:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	return 0;
}

