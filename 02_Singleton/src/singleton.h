#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <pthread.h>

template<class T>

class Singleton
{
public:
    //这个一个外界能够访问的public的方法，在外界都能在全局获取到唯一的实例
    //template <typename T>
    static T* GetInstance(); 

//private下面的构造函数和拷贝构造函数必须要定义为私有，如果不定义C++的编译器是会默认的自己生成的着两个函数
private:
    //这是一个私有的构造函数，防止调用构造函数去构建更多的实例
    Singleton(); 
    
    //这是一个私有的拷贝构造函数，这个是防止调用拷贝构造函数去拷贝我们的实例，从而生成跟多的实例
    Singleton(const T& other);
   
   //这是一个静态的成员指针变量，就用它来保存唯一的实例
    static T* m_instance;
   
   //这是一个线程锁
   //static std::mutex m_mutex;
   static std::once_flag m_flag;
};


/*
class Test
{
public:
    Test(const std::string& name);
private:
    std::string m_sName;
};
*/
#endif //singleton
