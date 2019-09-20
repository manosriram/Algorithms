#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#include "unordered_set"
#define sd std

int main() {
    sd::unordered_set<sd::string> dictionary = {"stop", "pots", "tops", "opts", "post", "spot"};

    sd::string word = "stop";

    sd::sort(word.begin(), word.end());

    do {
        sd::cout << word << (dictionary.count (word) ? " Is a Word !\n" : "\n");
    } while (next_permutation(word.begin(), word.end()));

    return 0;
}