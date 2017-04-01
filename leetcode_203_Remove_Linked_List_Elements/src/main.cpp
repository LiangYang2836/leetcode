/*
 * main.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: yl
 */

/*
 *
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5


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
    ListNode* removeElements(ListNode* head, int val) {

    	if (head == NULL) {
    		return NULL;
    	}

    	ListNode *cur_node = head;
    	ListNode *pre_node = head;
    	while (cur_node != NULL) {
    		if (cur_node->val == val) {
    			if (cur_node == head) {
					head = head->next;
					cur_node = head;
					delete pre_node;
					pre_node = head;
				} else {
					pre_node->next = cur_node->next;
					delete cur_node;
					cur_node = pre_node->next;
				}
    		} else {
    			pre_node = cur_node;
    			cur_node = cur_node->next;
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

	int arr[] = {1};
	int len = sizeof(arr) / sizeof(int);
	ListNode *head = CreateList(arr, len);

	ListNode *node = head;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	int val = 1;
	Solution solution;
	node = solution.removeElements(head, val);
	cout << "After:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Destroy(&head);

	node = head;

	cout << "After Destroy:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	return 0;
}
