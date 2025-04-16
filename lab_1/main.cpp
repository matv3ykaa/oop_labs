#include <string>
#include <iostream>
#include "../include/vowel_count.h"

int main()
{
    std::string input_string = "";
    std::getline(std::cin, input_string);
    std::cout << count_the_number_of_vowels(input_string);
    return 0;
}