#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main()
{
    ll N, cn = 0;
    string S, T;
    char target;
    cin >> N;
    cin >> S >> T;

    target = S[0];
    char current = T[T.length() - 1];
    int now = 0;
    int rep = 0;

    while ((S[rep] == S[rep + 1]) && (rep < S.length()))
    {
        rep++;
    }

    while (target != current)
    {
        now++;
        current = T[T.length() - 1 - now];
    }
    cout << now + rep + 1 << endl;
}