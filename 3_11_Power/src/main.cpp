/*
 * main.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: yl
 */


#include <iostream>
using namespace std;

double cal(const double base, const int exponent) {

	double ret = 1.0;

	for (int i = 0; i < exponent; i++) {
		ret *= base;
	}

	return ret;
}

void power(const double base, const int exponent) {

	if (base == 0) {
		cout << "0" << endl;
	} else {
		double ret = 1.0;
		if (exponent > 0) {
			ret = cal(base, exponent);
		} else if (exponent < 0) {
			ret = 1.0 / cal(base, -1 * exponent);
		}

		cout << ret << endl;
	}
}

int main() {

	power(3, 2);
	power(2, 0);
	power(2, -2);
	power(0, 2);
	return 0;
}

