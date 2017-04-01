/*
 * main.cpp
 *
 *  Created on: Mar 30, 2017
 *      Author: yl
 */

/*
 *
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {

    	if (head == NULL || head->next == NULL) {
    		return true;
    	}

    	bool result = true;
    	ListNode *low = head;
    	ListNode *high = head;
    	while (high->next != NULL && high->next->next != NULL) {
    		low = low->next;
    		high = high->next->next;
    	}
//1->2->3->4->3->2->1


//1->2->3->4  3<-2<-1
//         |        ^
//		   |--------|
//head              low
//    	low->next = reverseList(low->next);
//    	low = low->next;
// or
//1->2->3->4->3<-2<-1
//head             low
// Pay attention: reverseList(low->next)
    	low = reverseList(low->next);
    	while (low != NULL) {
    		if (head->val != low->val) {
    			return false;
    		}

    		head = head->next;
    		low = low->next;
    	}

    	return result;
    }

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

	int arr[] = {1, 2, 3, 5, 5, 2, 1};
	int len = sizeof(arr) / sizeof(int);
	ListNode *head = CreateList(arr, len);

	ListNode *node = head;

	cout << "Before:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	Solution solution;
	bool result = solution.isPalindrome(head);
	cout << "result:" << result << endl;

	Destroy(&head);

	node = head;

	cout << "After:" << endl;
	while (node != NULL) {
		cout << node->val << endl;
		node = node->next;
	}

	return 0;
}

