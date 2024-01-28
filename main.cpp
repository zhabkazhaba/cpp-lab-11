#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "subs.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<int> nums;

    if (!input.empty()) {
        std::istringstream stream(input);
        int number;
        while (stream >> number) {
            nums.push_back(number);
        }
    }

    sub5(nums);
}
