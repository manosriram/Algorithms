#include <iostream>
#define mod 1000000000
using namespace std;

long long countRectangles(int width, int height)
{
    if (width > height)
        swap(width, height);

    long long rectangles, squares, res;
    rectangles = ((width * (width + 1) * height * (height + 1)) / 4) % mod;
    squares = ((width * ((width + 1) * ((2 * width) + 1))) / 6 + (((height - width) * width * (width + 1))) / 2) % mod;
    res = (rectangles - squares) % mod;
    return (res % mod);
}

int main()
{

    int width, height;
    cin >> width >> height;

    cout << countRectangles(width, height) << '\n';
}