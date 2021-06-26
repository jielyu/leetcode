/*
#剑指Offer# Q02 单例
设计一个类，只允许生成该类的一个实例
*/
#include "leetcode.h"

namespace sword_p02
{

class Singleton{
	
private:
	static Singleton * pSingleton;
	Singleton(){}
	
public:
	static Singleton * getSingleton(){
		if(Singleton::pSingleton == NULL){
			Singleton::pSingleton = new Singleton();
		}
		return Singleton::pSingleton;
	}
	
	static void delSingleton(){
		delete Singleton::pSingleton;
		Singleton::pSingleton = NULL;
	}
};
    
} // namespace sp02
