#include <Span.hpp>

#include <random>

static Span generateSpan(size_t count, int min, int max) {
  if (count == 0 || min > max) {
    throw std::invalid_argument("Invalid count or range!");
  } else {
    Span span(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    for (size_t i = 0; i < count; ++i) {
      span.addNumber(dist(gen));
    }
    return span;
  }
}

int main(void) {
  size_t count = 10; // 100000
  int min = -1000;   // int min = std::numeric_limits<int>::min();
  int max = 1000;    // int max = std::numeric_limits<int>::max();
  try {
    Span span = generateSpan(count, min, max);
    std::cout << "Shortest Span: " << span.shortestSpan() << "\n";
    std::cout << "Longest Span: " << span.longestSpan() << "\n";
  } catch (const std::invalid_argument &e) {
    std::cout << "Invalid argument: " << e.what() << "\n";
  } catch (const std::out_of_range &e) {
    std::cout << "Out of range: " << e.what() << "\n";
  } catch (const std::runtime_error &e) {
    std::cout << "Runtime error: " << e.what() << "\n";
  } catch (...) {
    std::cout << "Unexpected erro occured!\n";
  }
  return 0;
}
