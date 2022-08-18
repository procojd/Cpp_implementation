#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;
void func(int x)
{
    lock_guard<mutex>gaurd(mtx);
    cout<<"thread id is :"<<this_thread::get_id()<<endl;
    for(int i=0;i<100;i++)
    {
        cout<<"thread"<<x<<" "<<i<<endl;
    }
}


int main()
{
    thread t1(func,1);
    thread t2(func,2);

    t1.join();
    t2.join();
    return 0;

}
// g++ -std=c++11 -pthread mutex.cpp -o mutex
// ./mutex