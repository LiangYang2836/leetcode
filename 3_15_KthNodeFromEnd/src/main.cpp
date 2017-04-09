/*
 * main.cpp
 *
 *  Created on: Mar 5, 2017
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

void DeleteKthNodeFromEnd(ListNode **p_list_head, int k) {

	if (*p_list_head == NULL || k == 0) {
		return;
	}

	ListNode *p_list_node_h = *p_list_head;
	ListNode *p_list_node_t = *p_list_head;

	int step = 0;
	while (p_list_node_t != NULL && step < k) {
		p_list_node_t = p_list_node_t->m_p_next;
		step++;
	}

	cout << "step:" << step << endl;
	ListNode *p_list_tmp = NULL;
	if (p_list_node_t == NULL) {
		cout << "NULL" << endl;
		if (step == k) {
			// Delete head
			p_list_tmp = *p_list_head;
			*p_list_head = (*p_list_head)->m_p_next;
			delete p_list_tmp;
			p_list_tmp = NULL;
		} else if (step < k) {
			cout << "The list is not longer than k." << endl;
		}
		return;
	}

	while (p_list_node_t->m_p_next != NULL) {
		p_list_node_t = p_list_node_t->m_p_next;
		p_list_node_h = p_list_node_h->m_p_next;
	}

	p_list_tmp = p_list_node_h->m_p_next;
	p_list_node_h->m_p_next = p_list_node_h->m_p_next->m_p_next;

	delete p_list_tmp;
	p_list_tmp = NULL;

}

ListNode* KthNodeFromEnd(ListNode *p_list_head, int k) {

	if (p_list_head == NULL || k == 0) {
		return NULL;
	}

	ListNode *p_list_node = p_list_head;
	ListNode *p_list_tail = p_list_head;
	int step = 0;
	while (p_list_tail != NULL && step < k - 1) {
		p_list_tail = p_list_tail->m_p_next;
		step++;
	}

	if (p_list_tail == NULL) {
		cout << "The list is no longer than k." << endl;
		return NULL;
	}

	while (p_list_tail->m_p_next != NULL) {
		p_list_tail = p_list_tail->m_p_next;
		p_list_node = p_list_node->m_p_next;
	}


	return p_list_node;
}

int main() {

	ListNode *p_list_head = NULL;
	ListNode *p_list_tail = p_list_head;

	create_list(&p_list_head, &p_list_tail, 6);

	show_list(p_list_head);

//	DeleteKthNodeFromEnd(&p_list_head, 9);

//	show_list(p_list_head);
	ListNode *p_list_node = KthNodeFromEnd(p_list_head, 6);
	if (p_list_node != NULL) {
		cout << p_list_node->m_value << endl;
	}

	destroy_list(&p_list_head);

	show_list(p_list_head);


	return 0;
}


