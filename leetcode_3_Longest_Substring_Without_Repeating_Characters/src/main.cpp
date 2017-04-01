/*
 * main.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: yl
 */

/*
 *
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question.

"c"

"aab"

"dvdf"

""
 */

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

//    	// 题意为求不包含重复字符的最长子串
//		// left用以记录合法的最远左边界位置，last记录字符上一次出现的位置
//		int ans = 0, left = 0, len = s.length();
//		int last[255];
//		memset(last, -1, sizeof(last));
//
//		for (int i = 0; i < len; i++) {
////			cout << "s[i]:" << s[i] << " last[(int)s[i]]:" << last[(int)s[i]] << endl;
//			// 上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
//			if (last[(int)s[i]] >= left) {
//				left = last[(int)s[i]] + 1;
//			}
//			last[(int)s[i]] = i;
//			ans = max(ans, i - left + 1);
//		}
//		return ans;

    	string::size_type str_size = s.length();

    	if (str_size == 0) {
    		return 0;
    	}

    	string::size_type str_max_index = 0;

    	string::size_type max_length = 0;
    	string::size_type tmp_length = 0;
    	string::size_type tmp_index = 0;
    	for (string::size_type i = 0, j = i + 1; j < str_size;) {
//    		cout << "i:" << i << " j:" << j << " s.substr(i, j - i):" << s.substr(i, j - i) << endl;
//    		cout << "s[j]:" << s[j] << endl;
    		if(max_length > str_size - i) {
				break;
			}
    		tmp_index = s.substr(i, j - i).find(s[j]);
//    		cout << "tmp_index:" << (int)tmp_index << endl;
    		if ((int)tmp_index == -1) {
    			tmp_length++;
//    			cout << "tmp_length:" << tmp_length << endl;
    			j++;
    		} else {
    			tmp_length++;
    			if (tmp_length > max_length) {
    				max_length = tmp_length;
    			}

//    			str_max_index = tmp_index;
    			tmp_length = 0;
    			i += tmp_index + 1;
    			j = i + 1;
//    			cout << "max_length:" << max_length << endl;
    		}
    	}
    	tmp_length++;
    	if (((int)max_length == 0) || (tmp_length > max_length)) {
    		max_length = tmp_length;
    	}

//    	cout << str_max << endl;
    	return (int)max_length;
    }
};

int main() {

	Solution solution;
	string s = "pwwkew";
	int length = solution.lengthOfLongestSubstring(s);

	cout << "length:" << length << endl;

	return 0;
}

