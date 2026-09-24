#include <iostream>
#include <thread>
#include <memory>


void mem (std::unique_ptr<int>& a)
{
     a = nullptr;
     return;
}

void change(std::unique_ptr<int>& a)
{
    *a = 100;
    return;
}
int main()
{
    auto a = std::make_unique<int>(112);
    std::thread worker1(change,std::ref(a));
    std::thread worker2(mem,std::ref(a));

    // creates a race condition
    worker2.join();
    worker1.join();

    // segfault.
    std::cout << *a << std::endl;
    return 0;
}
