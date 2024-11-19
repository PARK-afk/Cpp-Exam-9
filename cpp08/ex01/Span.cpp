#include "Span.hpp"

Span::Span() : size(0) {
    arr.reserve(size);
}

Span::Span(unsigned int _size) : size(_size) {
    arr.reserve(size);
}

Span::Span(Span const &other) : size(other.size) {
    this->arr = other.arr;
}
Span::~Span() {}
Span &Span::operator=(Span const &other) {
    this->arr = other.arr;
    return *this;
}

void Span::addNumber(int num) {
    if (size <= arr.size()) {
        throw std::out_of_range("Index out of range ");
    }
    arr.push_back(num);
}

int Span::longestSpan()
{
    if (arr.size() <= 1) {
        throw std::out_of_range("Index out of range ");
    }
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    return max - min;
}

int Span::shortestSpan()
{
    if (arr.size() <= 1) {
        throw std::logic_error("error");
    }
    std::sort(arr.begin(), arr.end());
    int min = INT_MAX;
    for (unsigned int i = 1; i < size; i++) {
        int fMin = arr[i] - arr[i - 1];
        if (fMin < min) {
            min = fMin;
        }
    }
    return min;
}

unsigned int Span::getSize() const {
    return this->size;
}
