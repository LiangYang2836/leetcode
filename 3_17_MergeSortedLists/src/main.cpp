/*
 * main.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

typedef struct ListNode {

	int m_value;
	ListNode *m_p_next;

} ListNode;

void create_list(ListNode **p_list_head, ListNode **p_list_tail, const int length, const int step) {

	cout << __FUNCTION__ << endl;
	for (int i = step; i < length; i += 2) {
		if (*p_list_head == NULL) {
			*p_list_head = new ListNode();
			(*p_list_head)->m_value = i;
			(*p_list_head)->m_p_next = NULL;
			(*p_list_tail) = *p_list_head;
		} else {
			ListNode *tmp_node = new ListNode();
			tmp_node->m_value = i;
			tmp_node->m_p_next = NULL;
			(*p_list_tail)->m_p_next = tmp_node;
			(*p_list_tail) = tmp_node;
		}

	}
}

void show_list(const ListNode *p_list) {

	cout << __FUNCTION__ << endl;

	if (p_list == NULL) {
		return;
	}

	const ListNode *tmp_p_list = p_list;
	while (tmp_p_list != NULL) {
		cout << "tmp_p_list->m_value:" << tmp_p_list->m_value << endl;
		tmp_p_list = tmp_p_list->m_p_next;
	}
}

void destroy_list(ListNode **p_list) {

	cout << __FUNCTION__ << endl;
	ListNode *tmp_p_list_del = NULL;
	while (*p_list != NULL) {
		tmp_p_list_del = *p_list;
		*p_list = (*p_list)->m_p_next;
		cout << "tmp_p_list_del->m_value:" << tmp_p_list_del->m_value << endl;
		tmp_p_list_del->m_p_next = NULL;
		delete tmp_p_list_del;
		tmp_p_list_del = NULL;
	}

}

ListNode* MergeSortedLists(ListNode *p_list_head_1, ListNode *p_list_head_2) {

	ListNode *p_list_merged_head = NULL;

	if (p_list_head_1 == NULL) {
		p_list_merged_head = p_list_head_2;
	}

	if (p_list_head_2 == NULL) {
		p_list_merged_head = p_list_head_1;
	}

	ListNode *p_list_merged_cur = NULL;
	ListNode *p_list_small = NULL;
	while (p_list_head_1 != NULL && p_list_head_2 != NULL) {

		if (p_list_head_1->m_value < p_list_head_2->m_value) {
			p_list_small = p_list_head_1;
			p_list_head_1 = p_list_head_1->m_p_next;
		} else if (p_list_head_1->m_value >= p_list_head_2->m_value) {
			p_list_small = p_list_head_2;
			p_list_head_2 = p_list_head_2->m_p_next;
		}

		if (p_list_merged_cur != NULL) {
			p_list_merged_cur->m_p_next = p_list_small;
		}

		p_list_merged_cur = p_list_small;

		if (p_list_merged_head == NULL) {
			p_list_merged_head = p_list_merged_cur;
		}

	}

	if (p_list_head_1 != NULL) {
		p_list_merged_cur->m_p_next = p_list_head_1;
	}

	if (p_list_head_2 != NULL) {
		p_list_merged_cur->m_p_next = p_list_head_2;
	}

	return p_list_merged_head;
}

int main() {

	ListNode *p_list_head_1 = NULL;
	ListNode *p_list_tail_1 = p_list_head_1;

	create_list(&p_list_head_1, &p_list_tail_1, 10, 1);
	show_list(p_list_head_1);

	ListNode *p_list_head_2 = NULL;
	ListNode *p_list_tail_2 = p_list_head_2;

	create_list(&p_list_head_2, &p_list_tail_2, 20, 2);
	show_list(p_list_head_2);

	ListNode *p_list_merged_head = MergeSortedLists(p_list_head_1, p_list_head_2);
	show_list(p_list_merged_head);

	destroy_list(&p_list_merged_head);
	show_list(p_list_merged_head);

	return 0;
}


