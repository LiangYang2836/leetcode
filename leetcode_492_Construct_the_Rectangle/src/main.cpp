/*
 * main.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: yl
 */

/*
 *
For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:

1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.
You need to output the length L and the width W of the web page you designed in sequence.
Example:
Input: 4
Output: [2, 2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1].
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.
Note:
The given area won't exceed 10,000,000 and is a positive integer
The web page's width and length you designed must be positive integers.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
    	/*
    	 *
    	  if (area <= 0) return vector<int> {};
        vector<int> res;
        int w = area;
        for (int i = 1; i * i <= area; ++i) {
            if (area % i == 0) w = i;
        }
        return vector<int> {area / w, w};
    	 */

    	if (area <= 0) {
    		return vector<int>();
    	}

    	vector<int> result;

    	int best_length = 0;
    	int best_width = 0;
    	int length_width_difference = -1;
    	int length = 0;
		int width = 0;
    	for (int i = area; i > 0; i--) {

    		if (area % i != 0) {
    			continue;
    		}

    		length = i;
    		width = area / i;

    		if (length < width) {
    			break;
    		} else {
    			if ((length_width_difference == -1) || (length_width_difference > (length - width))) {
    				length_width_difference = length - width;
    				best_length = length;
    				best_width = width;
    			}
    		}
    	}

    	result.push_back(best_length);
		result.push_back(best_width);
    	return result;
    }
};

int main() {

	Solution solution;

	vector<int> result = solution.constructRectangle(4);

	cout << result[0] << " " << result[1] << endl;

	return 0;
}

