/**********************************************
 ******* g++ test.cpp -lpthread****************
 * *******************************************/
#include <iostream>
#include <pthread.h>
using namespace std;
template <class T>
class Singleton
{
public:
    Singleton()
    {

    }
    static T* GetInstance()
    {
       if(m_pInstance == NULL)
        {
            //pthread_mutex_t mutex;
            pthread_mutex_lock(&mutex);
            if(m_pInstance == NULL)
            {
                T* temp = new T;
                m_pInstance = temp;
            }
            pthread_mutex_unlock(&mutex);
        }
        return m_pInstance;
    }
private:
    static T* m_pInstance;
    static pthread_mutex_t mutex;
};

template<class T>
T* Singleton<T>::m_pInstance = NULL;

template<class T>
pthread_mutex_t Singleton<T>::mutex;

class Test:public Singleton<Test>
{
public:
    Test()
    {
        cout<<"Test::Test()."<<endl;
    }
};

void* thread1(void*)
{
    cout<<"In thread1."<<endl;
    Test* test1 = Test::GetInstance();
}

void* thread2(void *)
{
    cout<<"In thread2."<<endl;
    Test* test2 = Test::GetInstance();
}

int main()
{
    const unsigned int thread_num = 20;
    pthread_t thread_id[thread_num];
    for(unsigned int i = 0; i<thread_num;i++)
    {
        pthread_create(&thread_id[i], NULL, thread1, NULL);
    }
    for(unsigned int i = 0; i<thread_num;i++)
    {
        pthread_create(&thread_id[i], NULL, thread2, NULL);
    }
    sleep(1);
    return 0;
}
