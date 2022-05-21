#include "singleton.h"

template <typename T>
T* Singleton<T>::m_instance = nullptr;

template <typename T>
Singleton<T>::Singleton(){}

template <typename T>
T* Singleton<T>::GetInstance(){
   
   /*
   //方法1:为单一线程下的方案
   //判断实例是否已经被构造
   if(m_instance==nullptr){
    //如果没有被构造的话，需要构造唯一的实例
     m_instance=new Singleton();
   } 
   */
   
   /*
    假如，我们使用方法1去实现双线程的单例模式，我们会发现，当我们运行到
    if(m_instance==nullptr)这个条件明显是成立的，那么就会去构造一个实例
    m_instance=new Singleton(),如果在构造实例的过程中，第二个线程也运行
    到了if(m_instance==nullptr)这个时候指针m_instance还没有被赋值，第二
    个线程也会运行到创建实例m_instance=new Singleton()这里来，那么现在问
    题：线程都构造了实例，已经违反了单例模式；所以方法1对于多线程失效。
    */

   /*
    *********************************************************
    此方法为多线程下的方案,也叫双检查锁,主要分为如下步骤：
    1）给实例分配内存
    2）在分配的内存上构造实例
    3）返回内存的指针，赋值给指针变量
    缺点：
    编译器和CPU为了执行的效率，把前后没有依赖关系的代码重新排序去运行，这个时候上面的三个运行顺序就会发生变化
    可能会变成1，3，2
    假设：
    第一个线程运行到了
    - m_instance=new
      Singleton();也就完成了上面的第一步同时也完成了上面的三步，返回指针并且把指针赋给了指针变量m_instance,
      这个时候指针变量m_instance已经是非空了，但是这个时候还没有去执行真正的给内存去赋值，第一线程运行完也就退出去了，
      第二个线程运行到第一次的判断：
     if(m_instance==nullptr)，这个时候发现变量m_instance已经被赋值了，这个时候就可以直接拿着m_instance这个指针变量去使用
     但是事实上变量还没有真正的被赋值，
    **********************************************************
   */
   /*
   //判断实例是否已经被构造
   if(m_instance==nullptr){
     std::lock_guard<std::mutex> lock(m_mutex);
     if(m_instance==nullptr){
     //如果没有被构造的话，需要构造唯一的实例
       m_instance=new Singleton();
     }  
   }
   */
   
   /*
    *方法3
    */
   std::call_once(m_flag,[&](){m_instance = new Singleton();});
   return m_instance;
}
