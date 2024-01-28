//
// Created by zhabkazhaba on 1/28/24.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <deque>
#include <fstream>

template<typename T>
void displayContainer(std::vector<T> container) {
    if (container.empty())
        exit(0);
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> container) {
    for (size_t i = 0; i < container.size(); ++i) {
        os << container[i] << " ";
    }
    return os;
}

template<typename T>
void displayContainer(std::deque<T> container) {
    if (container.empty())
        exit(0);
    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void sub1(std::vector<T> input) {
    std::cout << input;

    typename std::vector<T>::iterator iter1 = input.begin();
    typename std::vector<T>::iterator iter2 = input.end();
    std::reverse(iter1, iter2);
    std::cout << input;

    std::advance(iter1, std::distance(iter1,iter2)/2);
    std::replace(iter1, iter2, 2, 0);
    std::cout << input;
}

template <typename T>
void sub2(const std::vector<T> input) {
    std::cout << input;
    std::deque<T> deck(input.begin(), input.end());
    auto back_iter = std::back_inserter(deck);
    auto forward_iter = std::front_inserter(deck);
    std::fill_n(forward_iter, 3, 4);
    std::fill_n(back_iter, 3, -1);
    displayContainer<T>(deck);
}

template<typename T>
void sub3(const std::vector<T> input) {
    std::ifstream input_file("test.txt");
    std::vector<T> file_data((std::istream_iterator<T>(input_file)), std::istream_iterator<T>());
    std::cout << file_data;
    input_file.close();

    std::ofstream output_file("test.txt");
    std::copy(input.begin(), input.end(), std::ostream_iterator<T>(output_file, " "));
    output_file.close();
}

template<typename T>
void sub4(const std::vector<T> input) {
    typename std::vector<T>::iterator iter1 = input.begin();
    typename std::vector<T>::iterator iter2 = input.end();
    std::deque<T> deck(iter1, iter2);
}

template<typename T>
void sub5(const std::vector<T> input) {
    typename std::vector<T>::const_reverse_iterator iter1 = input.rbegin();
    typename std::vector<T>::const_reverse_iterator iter2 = input.rend();
    std::vector<T> reversed_input(iter1, iter2);
    std::cout << reversed_input;
}