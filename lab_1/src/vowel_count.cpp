#include <string>
#include "include/vowel_count.h"

using namespace std;

int count_the_number_of_vowels(const string& input_string)
{
    int count = 0;
    for (char letter : input_string)
    {
        switch (tolower(letter))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
        }
    }
    return count;
}