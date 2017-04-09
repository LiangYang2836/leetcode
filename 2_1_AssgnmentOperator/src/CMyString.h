/*
 * CMyString.h
 *
 *  Created on: Mar 1, 2017
 *      Author: yl
 */

#ifndef CMYSTRING_H_
#define CMYSTRING_H_

class CMyString {
public:
	CMyString(char*);
	CMyString(const CMyString&);
	~CMyString();

	void print_content(const char*);

	// yangliang
	// CMyString&
	// const CMyString&
	// return *this
	CMyString& operator =(const CMyString&);

private:
	char* m_pData;
};



#endif /* CMYSTRING_H_ */
