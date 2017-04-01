/*
 * main.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: yl
 */



/*
 *
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {

    	if (head == NULL) {
    		return NULL;
    	}

    	if (head->next == NULL) {
    		return head;
    	}

    	ListNode *p_even_head = head->next;

    	ListNode *p_odd = head;
    	ListNode *p_odd_tail = head;
    	ListNode *p_even = p_even_head;

    	while (p_odd != NULL && p_even != NULL) {
    		p_odd->next = p_even->next;
    		p_odd_tail = p_odd;
    		p_odd = p_odd->next;

    		if (p_odd == NULL) {
    			break;
    		}

    		p_even->next = p_odd->next;
    		p_even = p_even->next;
    	}

    	if (p_even == NULL) {
    		p_odd->next = p_even_head;
    	}

    	if (p_odd == NULL) {
    		p_odd_tail->next = p_even_head;
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

	int arr[] = {1, 2, 3, 4, 5, 6};
	int len = sizeof(arr) / sizeof(int);
	ListNode *head = CreateList(arr, len);

	ListNode *node = head;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Solution solution;
	node = solution.oddEvenList(head);
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
