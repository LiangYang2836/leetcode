/*
 * main.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: yl
 */

#include <iostream>
#include <stack>
using namespace std;


void appendTail(stack<int> *stack_1, int value) {

	stack_1->push(value);

}

void deleteHead(stack<int> *stack_1, stack<int> *stack_2) {

	if (stack_1->empty()) {
		cout << "Empty! Delete Failed." << endl;
		return;
	}

	while (stack_1->size() > 1) {
		stack_2->push(stack_1->top());
		stack_1->pop();
	}

	stack_1->pop();

	while (!stack_2->empty()) {
		int tmp_value = stack_2->top();
		stack_1->push(tmp_value);
		stack_2->pop();
	}

}

void display(stack<int> *stack_1, stack<int> *stack_2) {

	if (stack_1->empty()) {
		cout << "Empty!" << endl;
		return;
	}

	while (!stack_1->empty()) {
		stack_2->push(stack_1->top());
		stack_1->pop();
	}

	while (!stack_2->empty()) {
		int tmp_value = stack_2->top();
		cout << tmp_value << " ";
		stack_1->push(tmp_value);
		stack_2->pop();
	}

	cout << endl;

}

int main() {

	stack<int> stack_1;
	stack<int> stack_2;

	display(&stack_1, &stack_2);
	appendTail(&stack_1, 2);
	display(&stack_1, &stack_2);
	appendTail(&stack_1, 4);
	display(&stack_1, &stack_2);
	appendTail(&stack_1, 6);
	display(&stack_1, &stack_2);
	deleteHead(&stack_1, &stack_2);
	display(&stack_1, &stack_2);
	appendTail(&stack_1, 8);
	display(&stack_1, &stack_2);
	deleteHead(&stack_1, &stack_2);
	display(&stack_1, &stack_2);

	return 0;
}


