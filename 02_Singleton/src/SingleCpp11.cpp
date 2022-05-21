/**********************************************
 ******* g++ *.cpp -std=c++11 -lpthread //(g++ versiton > 4.8)
 * *******************************************/
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <chrono>
template<class T>
class Singleton
{
public:
    Singleton()
    {

    }
    
    template <typename... Args>
    static T* GetInstance(Args&&... args)
    {
       if(m_pInstance == nullptr)  //double check
        {
            static std::mutex m_Mutex;
            std::lock_guard<std::mutex> lock(m_Mutex);
            if(m_pInstance == nullptr)
            {
               std::cout << "new T(...)" << std::endl;
               m_pInstance = new T(std::forward<Args>(args)...);
            }
        }
        return m_pInstance;
    }
private:
    static T* m_pInstance;
};

template<class T>
T* Singleton<T>::m_pInstance = nullptr;

class Test
{
public:
    Test(const std::string& name):m_sName(name)
    {
        std::cout<<"Test::Test(), name is:" << m_sName << std::endl;
    }
private:
    std::string m_sName;
};


int main()
{
    std::thread t1(std::bind([](std::string& name){return Singleton<Test>::GetInstance(name);}, std::string("Kevin") ));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t2(std::bind([](std::string& name){return Singleton<Test>::GetInstance(name);}, std::string("Kobe") ));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::thread t3(std::bind([](std::string& name){return Singleton<Test>::GetInstance(name);}, std::string("James") ));
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
