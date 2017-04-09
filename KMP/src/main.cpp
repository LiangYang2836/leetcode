/*
 * main.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: yl
 */



#include <iostream>
#include <string.h>
using namespace std;

void CalLPS(char *pat, int L, int *lps) {

	lps[0] = 0;
	int i = 1;
	int len = 0;
	while (i < L) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}

}

void KMPSearch(char *pat, char *txt) {

	int len_p = strlen(pat);
	int len_t = strlen(txt);
	cout << "len_p: " << len_p << endl;
	cout << "len_t: " << len_t << endl;
	int lps[len_p] = {0};

	CalLPS(pat, len_p, lps);
	for (int i = 0; i < len_p; i++) {
		cout << lps[i] << " ";
	}
	cout << endl;

	int i = 0;
	int j = 0;
	while (i < len_t) {
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}

		if (j == len_p) {
			cout << "Found pattern at index: " << (i - j) << endl;
			cout << j << endl;
			j = lps[j - 1];
			cout << j << endl;
		} else if (i < len_t && pat[j] != txt[i]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}

	}




}

int main() {

	char txt[] = "ABABDABACDABABCABABDE";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}


