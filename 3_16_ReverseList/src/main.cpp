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

void create_list(ListNode **p_list_head, ListNode **p_list_tail, const int length) {

	cout << __FUNCTION__ << endl;
	for (int i = 1; i < length; i++) {
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

ListNode* ReverseList(ListNode * p_list_head) {

	if (p_list_head == NULL) {
		return NULL;
	}

	ListNode *p_list_cur_head = p_list_head;
	int tmp_head_value = -1;
	ListNode *p_list_cur_tail = NULL;
	ListNode *p_list_cur_node = NULL;

	while (true) {

		tmp_head_value = p_list_cur_head->m_value;
		p_list_cur_node = p_list_head;

		if (p_list_cur_node == p_list_cur_tail) {
			break;
		}

		while (p_list_cur_node->m_p_next != NULL && p_list_cur_node->m_p_next != p_list_cur_tail) {
			p_list_cur_node->m_value = p_list_cur_node->m_p_next->m_value;
			p_list_cur_node = p_list_cur_node->m_p_next;
		}

		p_list_cur_tail = p_list_cur_node;

		p_list_cur_tail->m_value = tmp_head_value;
	}

	return p_list_cur_head;
}

ListNode* ReverseList2(ListNode *p_list_head) {

	ListNode *p_list_reversed_head = NULL;

	ListNode *p_list_cur = p_list_head;
	ListNode *p_list_pre = NULL;
	ListNode *p_list_next = NULL;

	while (p_list_cur != NULL) {
		p_list_next = p_list_cur->m_p_next;
		if (p_list_next == NULL) {
			p_list_reversed_head = p_list_cur;
		}
		p_list_cur->m_p_next = p_list_pre;
		p_list_pre = p_list_cur;
		p_list_cur = p_list_next;
	}

	return p_list_reversed_head;
}

int main() {

	ListNode *p_list_head = NULL;
	ListNode *p_list_tail = p_list_head;

	create_list(&p_list_head, &p_list_tail, 6);

	show_list(p_list_head);

	ListNode *reversed_list_head = ReverseList(p_list_head);
	show_list(reversed_list_head);

	destroy_list(&reversed_list_head);

	show_list(reversed_list_head);

	return 0;
}




