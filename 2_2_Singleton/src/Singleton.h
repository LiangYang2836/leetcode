/*
 * Singleton.h
 *
 *  Created on: Mar 2, 2017
 *      Author: yl
 */

#ifndef SRC_SINGLETON_H_
#define SRC_SINGLETON_H_

class Singleton {

private:
	static Singleton* pInstance;
//	Singleton();
public:
	static Singleton* Instance();
	static void Destroy();
	static void Show();
	static int instance_num;
};



#endif /* SRC_SINGLETON_H_ */
