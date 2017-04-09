/*
 * main.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

void replace_blank(const char *str_ori, char **str_new) {

	// yangliang
	// Check NULL is very important.
	if (str_ori == NULL) {
		return;
	}

	int str_ori_len = 0;

	const char *p_str_ori = str_ori;
	int blank_num = 0;
	while (*p_str_ori != '\0') {
//		cout << *p_str_ori << endl;
		if (*p_str_ori == ' ') {
			blank_num++;
		}
		p_str_ori++;
		str_ori_len++;
	}
	cout << str_ori_len << endl;
	cout << blank_num << endl;

	*str_new = new char[str_ori_len + 3 * blank_num + 1];
	char *p_str_new = *str_new;

	p_str_ori = str_ori;
	while (*p_str_ori != '\0') {
		if (*p_str_ori != ' ') {
			*p_str_new++ = *p_str_ori++;
		} else {
			*p_str_new++ = '%';
			*p_str_new++ = '2';
			*p_str_new++ = '0';
			p_str_ori++;
		}
	}
}

int main() {

	char str[] = "We are very very happy.";
	cout << str << endl;

	char *str_new = NULL;
	replace_blank(str, &str_new);
	cout << str_new << endl;
	delete str_new;
	str_new = NULL;
	return 0;
}


