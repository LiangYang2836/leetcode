/*
 * main.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: yl
 */

#include <iostream>
#include <stack>
using namespace std;

bool CheckPushPopOrder(int *a_push, int *a_pop, int length) {

	if (a_push == NULL or a_pop == NULL or length <= 0) {
		return false;
	}

	bool ret = true;

	stack<int> stack;

	int index_push = 0;
	int index_pop = 0;

	int top_value = 0;
	bool flag = false;
	while (true) {
		cout << "=============" << endl;
		if (index_push < length) {
			stack.push(a_push[index_push]);
		}
		top_value = stack.top();
		cout << "a top_value:" << top_value << " a_pop[index_pop]:" << a_pop[index_pop] << endl;
		while (top_value != a_pop[index_pop]) {
			if ((index_push + 1) >= length) {
				flag = true;
				ret = false;
				break;
			}
			index_push++;
			stack.push(a_push[index_push]);
			top_value = stack.top();
			cout << "b top_value:" << top_value << " a_pop[index_pop]:" << a_pop[index_pop] << endl;
		}
		if (flag == true) {
			break;
		}
		cout << "c top_value:" << top_value << " a_pop[index_pop]:" << a_pop[index_pop] << endl;
		while (!stack.empty() && top_value ==  a_pop[index_pop]) {
			cout << "d top_value:" << top_value << " a_pop[index_pop]:" << a_pop[index_pop] << endl;
			stack.pop();
			if (stack.empty()) {
				flag = true;
				ret = true;
				break;
			}
			index_pop++;
			top_value = stack.top();
			cout << "e top_value:" << top_value << " a_pop[index_pop]:" << a_pop[index_pop] << endl;
			if (index_push >= length && top_value !=  a_pop[index_pop]) {
				flag = true;
				ret = false;
				break;
			}
		}

		if (flag == true) {
			break;
		}

		index_push++;
	}

	return ret;
}

int main() {

	const int length = 5;
	int a_push[] = {1, 2, 3, 4, 5};
	int a_pop[] = {4, 5, 3, 2, 1};
//	int a_pop[] = {4, 3, 5, 1, 2};

	bool ret = CheckPushPopOrder(a_push, a_pop, length);
	cout << ret << endl;
	return 0;
}


