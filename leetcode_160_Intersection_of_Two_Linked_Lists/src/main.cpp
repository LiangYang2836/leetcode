/*
 * main.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: yl
 */


/*
 *
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
	bool check(ListNode **head, set<ListNode*> &set_info) {

		bool found = false;

		if (set_info.find(*head) == set_info.end()) {
			if (*head != NULL) {
				set_info.insert(*head);
				*head = (*head)->next;
			}
		} else {
			found = true;
		}

		return found;
	}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    	if (headA == NULL || headB == NULL) {
    		return NULL;
    	}

    	ListNode *intersection_node = NULL;

    	set<ListNode*> set_listNode;
    	while (headA != NULL || headB != NULL) {
    		if (check(&headA, set_listNode)) {
    			return headA;
    		}

    		if (check(&headB, set_listNode)) {
				return headB;
			}
    		/*if (set_listNode.find(headA) == set_listNode.end()) {
    			if (headA != NULL) {
    				set_listNode.insert(headA);
    				headA = headA->next;
    			}
    		} else {
    			return headA;
    		}

    		if (set_listNode.find(headB) == set_listNode.end()) {
    			if (headB != NULL) {
					set_listNode.insert(headB);
					headB = headB->next;
    			}
			} else {
				return headB;
			}*/
    	}

    	return intersection_node;
    }
};

int main() {

	ListNode *node11 = new ListNode(1);
	ListNode *node12 = new ListNode(3);
	ListNode *node13 = new ListNode(5);
	ListNode *node14 = new ListNode(7);
	ListNode *node15 = new ListNode(9);
	node11->next = node12;
	node12->next = node13;
	node13->next = node14;
	node14->next = node15;

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
	node21->next = node22;
	node22->next = node23;
	node23->next = node13;

	ListNode *l2 = node21;

	cout << "l2:" << endl;
	while (l2 != NULL) {
		cout << l2->val << endl;
		l2 = l2->next;
	}

	l2 = node21;
	Solution solution;
	ListNode *node = solution.getIntersectionNode(l1, l2);
	cout << "IntersectionNode:" << endl;
	if (node != NULL) {
		cout << node->val << endl;
	}

	delete node11;
	delete node12;
	delete node13;
	delete node14;
	delete node15;
	delete node21;
	delete node22;
	delete node23;

	return 0;
}
