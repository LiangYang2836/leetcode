/*
 * main.cpp
 *
 *  Created on: Apr 5, 2017
 *      Author: yl
 */

/*
 *
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
    	m_head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {

    	int result = m_head->val;
    	int index = 0;
    	ListNode *node = m_head->next;
    	int i = 1;
    	long pos_selected = 0;
    	while (node != NULL) {
//    		srand((unsigned)time(NULL));  //srand()函数产生一个以当前时间开始的随机种子
    		pos_selected = rand() % (i + 1);
//    		cout << "pos_selected:" << pos_selected << endl;
    		if (pos_selected == 0) {
    			result = node->val;
    		}
    		i++;
    		node = node->next;
    	}
    	return result;
    }

private:
    ListNode *m_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */


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

	Solution solution(head);
	for (int i = 0; i < 6; i++) {
		int result = solution.getRandom();
		cout << "result:" << result << endl;
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
