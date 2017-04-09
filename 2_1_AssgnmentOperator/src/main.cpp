/*
 * main.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: yl
 */

/*#include <iostream>
#include <string.h>
using namespace std;

class CMyString {
public:

	CMyString(char*);
	CMyString(const CMyString&);
	~CMyString(void);

	void print_content();
	CMyString& operator =(const CMyString&);

private:
	char* m_pData;
};

CMyString::CMyString(char* pData = NULL) {
	m_pData = pData;
	if (pData != NULL) {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	} else {
		m_pData = NULL;
	}
}

CMyString::CMyString(const CMyString& str) {
	m_pData = str.m_pData;
}

CMyString::~CMyString(void) {
	delete[] m_pData;
	m_pData = NULL;
}

CMyString& CMyString::operator=(const CMyString& str) {

	if (this == &str) {
		return *this;
	}

	delete []m_pData;
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

void CMyString::print_content() {
	cout << m_pData << endl;
}

int main() {

	char tmp_str[] = "abcde";
	CMyString cms(tmp_str);
	cms.print_content();

	return 0;
}*/


#include <iostream>
#include <cstring>
#include "CMyString.h"
using namespace std;

CMyString::CMyString(char* pData = NULL) {
	if (pData != NULL) {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	} else {
		m_pData = NULL;
	}
}

CMyString::CMyString(const CMyString& str) {

	if (this != &str) {
		m_pData = str.m_pData;
	}

}

CMyString::~CMyString() {
	// yangliang
	// Release memory
	delete[] m_pData;
	m_pData = NULL;
}

void CMyString::print_content(const char* class_name = NULL) {
	if (m_pData != NULL) {
		cout << class_name << ":" << m_pData << endl;
	}
}

CMyString& CMyString::operator =(const CMyString& str) {
	cout << "operator =" << endl;
//	if (this != &str) {
//		CMyString tmp_cms(str);
//		char* tmp_pData = tmp_cms.m_pData;
//		tmp_cms.m_pData = m_pData;
//		m_pData = tmp_pData;
//	}

	if (this == &str) {
		return *this;
	}

	// yangliang
	// Release memory
	delete[] m_pData;
	m_pData = NULL;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

int main() {

	char tmp_str_1[] = "abcdef";
	CMyString cms_1(tmp_str_1);
	cms_1.print_content("cms_1");
	char tmp_str_2[] = "123456";
	CMyString cms_2(tmp_str_2);
	cms_2.print_content("cms_2");
	cms_2 = cms_1;
	cms_2.print_content("cms_2");

//	int val = 1024;
//	int *pi = &val;
//	cout << *pi << endl;
//	int **ppi = &pi;
//	cout << *ppi << endl;
//	int *pi2 = *ppi;
//	cout << *pi2 << endl;

	return 0;
}
