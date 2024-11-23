#include <MutantStack.hpp>

int main(void) {
  // std::stack<int> stack;
  // stack.begin();

  // MutantStack<int> mstack;
  // mstack.push(1);
  // mstack.push(2);
  // mstack.push(3);

  // std::cout << "Elements in MutantStack: ";
  // for (auto it = mstack.begin(); it != mstack.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
  // return 0;

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(42);
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  return 0;
}
