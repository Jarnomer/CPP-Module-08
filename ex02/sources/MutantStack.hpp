#pragma once

#include <iostream>
#include <stack>

template <typename T> class MutantStack : std::stack<T> {

public: // constructor
  MutantStack() : std::stack<T>() {
    std::cout << "Default constructor called\n";
  }

public: // copy constructor
  MutantStack(const MutantStack &other) = delete;

public: // copy assignment
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::cout << "Copy assignment called\n";
      std::stack<T>::operator=(other);
    }
    return *this;
  }

public: // deconstructor
  ~MutantStack() { std::cout << "Deconstructor called\n"; }
};
