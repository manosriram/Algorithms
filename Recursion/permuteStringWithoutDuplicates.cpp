#include <iostream>
#include <string.h>
#include "unordered_set"
using namespace std;

void permuteString(string originalString, string chosenString, unordered_set<string> &alreadyPrinted)
{
    // If there are no Characters to Explore (originalString is empty), then Add the "chosenString" to the 'alreadyPrinted set' and the print the chosenString.
    if (originalString.empty())
    {
        std::unordered_set<std::string>::const_iterator got = alreadyPrinted.find(chosenString);

        if (got == alreadyPrinted.end())
        {
            cout << chosenString << endl;
            alreadyPrinted.insert(chosenString);
        }
    }
    else
    {
        for (int i = 0; i < originalString.length(); i++)
        {
            /* 
            Choose Character -  1. Insert character at position 'i' from originalString at the end of chosenString.
                                2. Erase the inserted character from the originalString.
            */
            char temp = originalString[i];
            chosenString += temp;
            originalString.erase(i, 1);

            // Explore Paths (Permute).
            permuteString(originalString, chosenString, alreadyPrinted);

            /* 
                BackTrack - 1. Insert the current character (temp) to the originalString at position 'i'.
                            2. Remove the last character from the chosenString. (We inserted the current character at the end while choosing the character.)
            */
            originalString.insert(i, 1, temp);
            chosenString.erase(chosenString.length() - 1, 1);
        }
    }
}

int main()
{
    unordered_set<string> alreadyPrinted;
    string originalString;
    cin >> originalString;

    permuteString(originalString, "", alreadyPrinted);
}