#include <iostream>
#include <string.h>
using namespace std;

void permuteString(string originalString, string chosenString)
{
    // If there are no Characters to Explore (originalString is empty), then print the chosenString.
    if (originalString.empty())
    {
        cout << chosenString << endl;
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
            permuteString(originalString, chosenString);

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
    string originalString;
    cin >> originalString;

    permuteString(originalString, "");
}