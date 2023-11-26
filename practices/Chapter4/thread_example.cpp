#include "thread_utils.h"

using namespace Common;
using namespace std::literals::chrono_literals;

auto dummyFunction(int a, int b, bool sleep) {
  std::cout << "dummyFunction(" << a << "," << b << ")" << std::endl;
  std::cout << "dummyFunction output=" << a + b << std::endl;
  if (sleep) {
    std::cout << "sleeping.." << std::endl;
    std::this_thread::sleep_for(5s);
  }
  std::cout << "dummyFunction done" << std::endl;
}

int main(int, char**) {
  auto t1 =
      createAndStartThread(-1, "dummyFunction1", dummyFunction, 12, 21, true);
  auto t2 =
      createAndStartThread(1, "dummyFunction2", dummyFunction, 15, 51, false);
  std::cout << "main waiting for threads to be done." << std::endl;
  t1->join();
  t2->join();
  std::cout << "main exiting." << std::endl;
  return 0;
}