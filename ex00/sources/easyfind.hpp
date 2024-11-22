#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T> int easyfind(const T &container, int value) {
  auto it = std::find(std::begin(container), std::end(container), value);
  if (it != std::end(container)) {
    return *it;
  } else {
    throw std::runtime_error("Value not found!");
  }
}
