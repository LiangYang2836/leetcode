/*
 * main.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: yl
 */


/*
 *
 *
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Test Case
//[2,4,3]
//[5,6,4]

//[5]
//[5]

//[1, 8]
//[0]

//[0]
//[0]

#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* newListNode(const int value, int &i_over_take) {

		ListNode *list_node = NULL;
		if (value > 9) {
			list_node = new ListNode(value % 10);
			i_over_take = 1;
		} else {
			list_node = new ListNode(value);
			i_over_take = 0;
		}

		return list_node;
	}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    	ListNode *result_head = NULL;
    	ListNode *result_tail = NULL;
    	ListNode *list_node = NULL;
    	int i_over_take = 0;

    	while (l1 != NULL || l2 != NULL || i_over_take) {
    		int num_a = 0;
    		if (l1 != NULL) {
    			num_a = l1->val;
    		}

    		int num_b = 0;
    		if (l2 != NULL) {
    			num_b = l2->val;
			}

    		int sum = num_a + num_b + i_over_take;
    		list_node = newListNode(sum, i_over_take);
    		if (result_head == NULL) {
				result_head = list_node;
			}

			if (result_tail != NULL) {
				result_tail->next = list_node;
			}

			result_tail = list_node;

			if (l1 != NULL) {
				l1 = l1->next;
			}

			if (l2 != NULL) {
				l2 = l2->next;
			}

    	}

//    	while (l1 != NULL && l2 != NULL) {
//    		int tmp_result = l1->val + l2->val + i_over_take;
//
//    		list_node = newListNode(tmp_result, i_over_take);
//
//    		if (result_head == NULL) {
//    			result_head = list_node;
//    		}
//
//    		if (result_tail != NULL) {
//    			result_tail->next = list_node;
//    		}
//
//    		result_tail = list_node;
//
//    		l1 = l1->next;
//    		l2 = l2->next;
//    	}
//
//    	ListNode *tmp_list_node = NULL;
//    	if (l1 != NULL) {
//    		tmp_list_node = l1;
//    	}
//
//    	if (l2 != NULL) {
//    		tmp_list_node = l2;
//    	}
//
//    	while (tmp_list_node != NULL) {
//    		int tmp_result = tmp_list_node->val + i_over_take;
//
//    		list_node = newListNode(tmp_result, i_over_take);
//
//    		if (result_tail != NULL) {
//				result_tail->next = list_node;
//			}
//			result_tail = list_node;
//			tmp_list_node = tmp_list_node->next;
//    	}
//
//    	if (i_over_take == 1) {
//    		list_node = new ListNode(i_over_take);
//    		if (result_tail != NULL) {
//				result_tail->next = list_node;
//			}
//			result_tail = list_node;
//    	}


    	return result_head;
    }
};

int main () {

	Solution *solution = new Solution();


	int list_1[] = {1, 8};
	int list_2[] = {0};
//	if (test_code == 1) {
//		list_1[] = {2, 4, 3};
//		list_2[] = {5, 6, 4};
//	} else if (test_code == 2) {
//		list_1[] = {5};
//		list_2[] = {5};
//	} else if (test_code == 3) {
//		list_1[] = {1, 8};
//		list_2[] = {0};
//	} else if (test_code == 4) {
//		list_1[] = {0};
//		list_2[] = {0};
//	}

	int length_1 = sizeof(list_1) / sizeof(int);
	int length_2 = sizeof(list_2) / sizeof(int);

	ListNode *l1 = NULL;
	ListNode *l1_tail = NULL;
	for (int i = 0; i < length_1; i++) {
		ListNode *tmp_list_node = new ListNode(list_1[i]);
		if (l1 == NULL) {
			l1 = tmp_list_node;
		}

		if (l1_tail != NULL) {
			l1_tail->next = tmp_list_node;
		}

		l1_tail = tmp_list_node;
	}
//	while (l1 != NULL) {
//		cout << l1->val << "->";
//		l1 = l1->next;
//	}
//	cout << endl;

	ListNode *l2 = NULL;
	ListNode *l2_tail = NULL;
	for (int i = 0; i < length_2; i++) {
		ListNode *tmp_list_node = new ListNode(list_2[i]);
		if (l2 == NULL) {
			l2 = tmp_list_node;
		}

		if (l2_tail != NULL) {
			l2_tail->next = tmp_list_node;
		}

		l2_tail = tmp_list_node;
	}

//	while (l2 != NULL) {
//		cout << l2->val << "->";
//		l2 = l2->next;
//	}
//	cout << endl;

	ListNode *result = solution->addTwoNumbers(l1, l2);
//
	while (result != NULL) {
		cout << result->val << "->";
		result = result->next;
	}

	cout << endl;
	delete result;
	delete solution;

	return 0;
}
