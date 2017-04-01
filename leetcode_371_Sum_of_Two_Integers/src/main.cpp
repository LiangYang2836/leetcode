/*
 * main.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: yl
 */

/*
 *
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

1
2

2
3

20
30

-1
1
Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
 */


/*
 *
http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
Add two numbers without using arithmetic operators
Write a function Add() that returns sum of two integers. The function should not use any of the arithmetic operators (+, ++, –, -, .. etc).

Sum of two bits can be obtained by performing XOR (^) of the two bits. Carry bit can be obtained by performing AND (&) of two bits.
Above is simple Half Adder logic that can be used to add 2 single bits. We can extend this logic for integers. If x and y don’t have set bits at same position(s), then bitwise XOR (^) of x and y gives the sum of x and y. To incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and y gives all carry bits. We calculate (x & y) << 1 and add it to x ^ y to get the required result.

#include<stdio.h>

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        int carry = x & y;

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

int main()
{
    printf("%d", Add(15, 32));
    return 0;
}

Following is recursive implementation for the same approach.

int Add(int x, int y)
{
    if (y == 0)
        return x;
    else
        return Add( x ^ y, (x & y) << 1);
}
 */
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

//    	int sum = a;
    	int carry = 0;
		while (b != 0) {
			// carry now contains common set bits of x and y
			// carry的结果是所有的进位
			carry = a & b;

			// Sum of bits of x and y where at least one of the bits is not set
			// ^操作得到的是不考虑进位的和
			a = a ^ b;

			// Carry is shifted by one so that adding it to x gives the required sum
			// << 1操作是为了下一轮^操作把该轮所需要的进位加进去
			b = carry << 1;
		}

		return a;
//    	int result = 0;

//    	int over_take = 0;
//    	int loop_time = 0;
//    	while (a > 0 || b > 0) {
//    		cout << "================" << endl;
////    		cout << "a:" << (a >> 1) << endl;
////			cout << "b:" << (a >> 1) << endl;
//    		int a_t = a > 0 ? (a & 1) : 0;
//    		int b_t = b > 0 ? (b & 1) : 0;
//    		cout << "a_t:" << a_t << endl;
//			cout << "b_t:" << b_t << endl;
//    		int f = 0;
//    		if (a_t == 0 && b_t == 0) {
//    			if (over_take == 1) {
//    				f = 1;
//    			} else {
//    				f = 0;
//    			}
//    			over_take = 0;
//    		} else if (a_t == 1 && b_t == 1) {
//    			if (over_take == 1) {
//					f = 1;
//				} else {
//					f = 0;
//				}
//    			over_take = 1;
//    		} else {
//    			if (over_take == 1) {
//					f = 0;
//					over_take = 1;
//				} else {
//					f = 1;
//					over_take = 0;
//				}
//    		}
//
//    		result |= f << loop_time;
//    		loop_time++;
//    		cout << "result:" << result << endl;
//    		cout << "over_take:" << over_take << endl;
//    		a = a >> 1;
//    		b = b >> 1;
//    		cout << "a:" << a << endl;
//			cout << "b:" << b << endl;
//    	}
//
//    	if (over_take == 1) {
//    		result |= 1 << loop_time;
//    	}
////    	printf("0X%x\n", (~b + 1));
////    	cout << "result:" << result << endl;
//    	return result;
    }
};

int main() {

	Solution solution;
	int a = 20;
	int b = 30;
//	printf("0X%x\n", a);
//	printf("0X%x\n", (~b + 1));
	int result = solution.getSum(a, b);

	cout << "result:" << result << endl;
	return 0;
}
