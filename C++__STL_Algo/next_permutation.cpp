#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#include "unordered_set"
using namespace std;

int main() {
    unordered_set<string> dictionary = {"stop", "pots", "tops", "opts", "post", "spot"};

    string word = "stop";

    sort(word.begin(), word.end());

    do {
        cout << word << (dictionary.count (word) ? " Is a Word !\n" : "\n");
    } while (next_permutation(word.begin(), word.end()));

    return 0;
}