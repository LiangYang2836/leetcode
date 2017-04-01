/*
 * main.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: yl
 */

/*
 *
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

1->1
 */

#include <iostream>
#include <set>
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
    	ListNode *p_pre = head;
    	ListNode *p_tmp = NULL;
    	while (p_cur != NULL && p_cur->next != NULL) {
    		if (p_cur->val == p_cur->next->val) {
    			while (p_cur != NULL && p_cur->next != NULL && p_cur->val == p_cur->next->val) {
    				p_tmp = p_cur->next;
    				p_cur->next = p_cur->next->next;
    				delete p_tmp;
    			}
    			if (p_cur == head) {
    				head = p_cur->next;
    				p_pre = head;
    				delete p_cur;
    				p_cur = head;
    			} else {
    				p_pre->next = p_cur->next;
    				delete p_cur;
					p_cur = p_pre->next;
    			}
    		} else {
    			p_pre = p_cur;
    			p_cur = p_cur->next;
    		}
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

	int arr[] = {1, 1};
	int len = sizeof(arr) / sizeof(int);
	ListNode *head = CreateList(arr, len);

	ListNode *node = head;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Solution solution;
	node = solution.deleteDuplicates(head);
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

