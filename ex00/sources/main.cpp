#include <easyfind.hpp>

#include <array>
#include <iostream>
#include <vector>

int main(void) {
  try {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    int foundValue1 = easyfind(vec, 3);
    std::cout << "Found in vector: " << foundValue1 << std::endl;

    int foundValue2 = easyfind(arr, 50);
    std::cout << "Found in array: " << foundValue2 << std::endl;

    int foundValue3 = easyfind(vec, 42);
    std::cout << "Found in array: " << foundValue3 << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
