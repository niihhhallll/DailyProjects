#include <iostream>
#include <thread>

void print(int **ref) {
    std::cout << "there will be a segfault my guy. be happy!!!" << std::endl;
  std::cout << **ref << std::endl;
  return;
}
void makeitnull(int** ptr)
{
    *ptr = NULL;
    return;
}
int main() {
  std::cout << "[MAIN] Starting the child thread.\n";
  int a = 10;
  int *b = &a;
  std::thread worker(makeitnull,&b);
  std::thread hello(print,&b);
  worker.join();

  std::cout << "main finished." << std::endl;
  std::cout << a << std::endl;
  hello.join();
}
