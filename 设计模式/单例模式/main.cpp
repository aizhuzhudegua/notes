#include <iostream>

class TaskQueue
{
    public:
        TaskQueue(const TaskQueue& t) = delete;
        TaskQueue& operator=(const TaskQueue& t) = delete;

        static TaskQueue* getInstance()
        {
            return instance;
        }

        void print()
        {
            std::cout << "hello world" << std::endl;
        }
    private:
        TaskQueue() = default;
        static TaskQueue* instance;
};
// 初始化单例
TaskQueue* TaskQueue::instance = new TaskQueue;
// 静态成员在外部初始化是语法要求，但初始化实质算在作用域内操作，所以才能访问私有的构造函数

class Singleton_lazy{
    public:
        Singleton_lazy(const Singleton_lazy& t) = delete;
        Singleton_lazy& operator=(const Singleton_lazy& t) = delete;
        static Singleton_lazy* getInstance(){
            if(instance == nullptr){
                instance = new Singleton_lazy();
            }
            return instance;
        }
        void print()
        {
            std::cout << "hello world" << std::endl;
        }
    private:
        Singleton_lazy() = default;
        static Singleton_lazy* instance;
};
Singleton_lazy* Singleton_lazy::instance = NULL;

int main()
{
    Singleton_lazy* lazy = Singleton_lazy::getInstance();
    lazy->print();
}