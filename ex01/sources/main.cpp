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
  try {
    size_t count = 5; // size_t count = 100000;
    int min = -1000;  // int min = std::numeric_limits<int>::min();
    int max = 1000;   // int max = std::numeric_limits<int>::max();

    Span span = generateSpan(count, min, max);
    std::cout << "Random Shortest Span: " << span.shortestSpan() << "\n";
    std::cout << "Random Longest Span: " << span.longestSpan() << "\n";

    Span span2(3);
    // span2.shortestSpan(); // trigger exception
    span2.addNumber(5);
    // span2.longestSpan(); // trigger exception
    span2.addNumber(0);
    span2.addNumber(21);
    std::cout << "Predictable Shortest Span: " << span2.shortestSpan() << "\n";
    std::cout << "Predictable Longest Span: " << span2.longestSpan() << "\n";

    span2.addNumber(42); // trigger exception

  } catch (const std::invalid_argument &e) {
    std::cout << "Invalid argument: " << e.what() << "\n";
  } catch (const std::out_of_range &e) {
    std::cout << "Out of range: " << e.what() << "\n";
  } catch (const std::runtime_error &e) {
    std::cout << "Runtime error: " << e.what() << "\n";
  } catch (...) {
    std::cout << "Unexpected exception occured!\n";
  }
  return 0;
}
