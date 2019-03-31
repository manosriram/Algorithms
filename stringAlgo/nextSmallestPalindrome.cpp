#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

/*  Case 1 : Even Length Digit.
            -> Middle Left Digit > Middle Right Digit.
            -> Middle Left Digit < Middle Right Digit.

    Case 2 : Odd Length Digit.
            -> Digit[middle - 1] > Digit[middle + 1]
            -> Digit[middle - 1] < Digit[middle + 1]
*/

// Return the length of the Number.
ll getLength(ll n)
{
  ll count = 0;
  while (n > 0)
  {
    count++;
    n /= 10;
  }
  return count;
}

ll getNextSmallestPal(ll n)
{
  ll temp = 0;
  int t;
  ll dup;
  ll len = getLength(n);
  ll first;

  // Divide the Number into Two Parts and store it in "temp"..
  for (t = 0; t < (len / 2); t++)
  {
    temp += (n % 10) * pow(10, t);
    n /= 10;
  }
  // Get the first element of temp.
  first = temp / pow(10, (len / 2) - 1);

  // If the length of the digit is even
  if (len % 2 == 0)
  {

    // if "Middle left Digit" is greater than the "Middle Right Digit".
    if (n % 10 > first)
    {
      ll overrider = 0;
      dup = n;

      // Reverse the first half and add it to the second half.
      for (t = 0; t < (len / 2); t++)
      {
        overrider += (n % 10) * pow(10, (len / 2) - t - 1);
        n /= 10;
      }

      dup *= pow(10, len / 2);
      dup += overrider;
    }

    // if "Middle Left Digit" is lesser than "Middle Right Digit".
    else if (n % 10 < first)
    {
      // Add one to the first part.
      n += 1;

      ll overrider = 0;
      dup = n;

      // Reverse the first half and add it to the second half.
      for (t = 0; t < (len / 2); t++)
      {
        overrider += (n % 10) * pow(10, (len / 2) - t - 1);
        n /= 10;
      }

      // Overriding reversed first part to the second part and then merging both parts.
      dup *= pow(10, len / 2);
      dup += overrider;
    }
  }

  // If the length of the digit is ODD.
  else
  {
    // get the last digit of the first digit of the number.
    ll mid = n % 10;
    dup = n;

    // Remove the last digit of n.
    n /= 10;

    // if Digit[middle - 1] > Digit[middle + 1]
    if (n % 10 > first)
    {
      ll overrider = 0;

      // Reverse the first half and then override it to the second half..
      for (t = 0; t < (len / 2); t++)
      {
        overrider += (n % 10) * pow(10, (len / 2) - t - 1);
        n /= 10;
      }

      // Overriding reversed first part to the second part and then merging both parts.
      dup *= pow(10, len / 2);
      dup += overrider;
    }

    // Digit[middle - 1] < Digit[middle + 1]
    else
    {
      ll overrider = 0;

      // Reverse the first half and then override it to the second half..
      for (t = 0; t < (len / 2); t++)
      {
        overrider += (n % 10) * pow(10, (len / 2) - t - 1);
        n /= 10;
      }

      // Overriding reversed first part to the second part and then merging both parts.
      dup *= pow(10, len / 2);
      dup += overrider;

      // Adding 1 to the Middle Element.
      dup += pow(10, len / 2);
    }
  }
  return dup;
}

// Checks if the every digit of the Number contains 9.
bool checkAllNines(ll n)
{
  while (n > 0)
  {
    if (n % 10 == 9)
    {
      n /= 10;
      continue;
    }

    else
      break;

    n /= 10;
  }
  return (n == 0) ? true : false;
}

int main()
{

  ll n;
  cin >> n;
  // If checkAllNines() returns "true", output the "number+2". Else, calculate the Next Smallest Palindrome.
  (checkAllNines(n)) ? cout << (n + 2) << '\n' : cout << getNextSmallestPal(n) << '\n';
}
