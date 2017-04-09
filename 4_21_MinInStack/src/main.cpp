/*
 * main.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: yl
 */

#include <iostream>
#include <stack>
using namespace std;

template <typename T> class StackWithMin {
public:
	void push(const T&);
	void pop();
	const T& min() const;

private:
	stack<T> m_stack_data;
	stack<T> m_stack_min;
};

template <typename T> void StackWithMin<T>::push(const T& value) {

	m_stack_data.push(value);

	if (m_stack_min.empty()) {
		m_stack_min.push(value);
	} else {
		int tmp_value = m_stack_min.top();
		if (tmp_value < value) {
			m_stack_min.push(tmp_value);
		} else {
			m_stack_min.push(value);
		}
	}
}

template <typename T> void StackWithMin<T>::pop() {

	if (m_stack_data.size() != m_stack_min.size()) {
		return;
	}

	if (!m_stack_data.empty()) {
		m_stack_data.pop();
	}

	if (!m_stack_min.empty()) {
		m_stack_min.pop();
	}
}

template <typename T> const T& StackWithMin<T>::min() const {

	return m_stack_min.top();

}

int main() {

	StackWithMin<int> swm;
	swm.push(3);
	cout << swm.min() << endl;
	swm.push(4);
	cout << swm.min() << endl;
	swm.push(2);
	cout << swm.min() << endl;
	swm.push(1);
	cout << swm.min() << endl;
	swm.pop();
	cout << swm.min() << endl;
	swm.pop();
	cout << swm.min() << endl;
	swm.push(0);
	cout << swm.min() << endl;

	return 0;
}


