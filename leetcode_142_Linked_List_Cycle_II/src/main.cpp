/*
 * main.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: yl
 */

/*
 *
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {

    	/*if (head == NULL || head->next == NULL) {
			return NULL;
		}

		ListNode *node_1 = head;
		ListNode *node_2 = head;

		while (node_2->next != NULL && node_2->next->next != NULL) {
			node_1 = node_1->next;
			node_2 = node_2->next->next;
			if (node_1 == node_2) {
				return node_1;
			}
		}


		return NULL;*/
    	/*if (head == NULL || head->next == NULL)
    	        return NULL;

		ListNode *slow  = head;
		ListNode *fast  = head;
		ListNode *entry = head;

		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {                      // there is a cycle
				while(slow != entry) {               // found the entry location
					slow  = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}
		return NULL;                                 // there has no cycle
		*/


    	if (head == NULL) {
    		return NULL;
    	}

    	ListNode *new_head = NULL;
    	set<ListNode *> set_listNode;
    	while (head != NULL) {
    		if (set_listNode.find(head) == set_listNode.end()) {
    			set_listNode.insert(head);
    		} else {
    			new_head = head;
    			break;
    		}
    		head = head->next;
    	}

    	return new_head;
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

	Solution solution;
	node = solution.detectCycle(head);
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
