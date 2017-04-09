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

void delete_node(ListNode **pListHead, ListNode *pToBeDeleted) {

	if (*pListHead == NULL or pToBeDeleted == NULL) {
		return;
	}

	if (*pListHead == pToBeDeleted) {
		*pListHead = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	} else if (pToBeDeleted->m_p_next != NULL) {
		ListNode *pToBeDeletedNext = pToBeDeleted->m_p_next;
		pToBeDeleted->m_value = pToBeDeletedNext->m_value;
		pToBeDeleted->m_p_next = pToBeDeletedNext->m_p_next;
		pToBeDeletedNext->m_p_next = NULL;
		delete pToBeDeletedNext;
	} else if (pToBeDeleted->m_p_next == NULL) {
		ListNode *pNode = *pListHead;
		while (pNode->m_p_next != pToBeDeleted) {
			pNode = pNode->m_p_next;
		}
		pNode->m_p_next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

int main() {

	ListNode *p_list_head = NULL;
	ListNode *p_list_tail = p_list_head;

	create_list(&p_list_head, &p_list_tail, 5);

	show_list(p_list_head);

	ListNode *p_list_to_be_deleted = p_list_head->m_p_next->m_p_next->m_p_next;

	delete_node(&p_list_head, p_list_to_be_deleted);

	show_list(p_list_head);

	destroy_list(&p_list_head);

	show_list(p_list_head);

	return 0;
}


