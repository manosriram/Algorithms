#include <iostream>
using namespace std;

int checkPageHit(int a[], int d, int frames)
{
    for (int k = 0; k < frames; k++)
    {
        if (a[k] == d)
            return 1;
    }
    return 0;
}

int main()
{
    int frames, pages, t, i, temp;

    float pageHits = 0, pageFaults;

    cout << "Number of Pages : ";
    cin >> pages;
    cout << "Number of Frames : ";
    cin >> frames;

    int *a = new int[frames];
    int **block = new int *[frames];

    static int count = 0;
    for (t = 0; t < pages; t++)
    {
        block[t] = new int[pages];

        if (t < frames)
        {
            cin >> a[t];
            block[count][t] = a[t];
            continue;
        }
        else
        {
            if (count > frames)
                count = 0;
            cin >> temp;
            if (checkPageHit(a, temp, frames))
            {
                pageHits++;
                continue;
            }
            for (int k = 0; k < frames; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
            a[count] = temp;

            count++;
        }
    }

    for (int k = 0; k < frames; k++)
    {
        cout << a[k] << " ";
    }
    cout << '\n';
    cout << "Page Hits : " << pageHits << endl;
    cout << "Page Faults : " << (pages - pageHits) << endl;
    cout << "Hit Ratio : " << (pageHits / pages) * 100 << "%" << endl;
    cout << "Miss Ratio : " << float(float(float(pages - pageHits) / pages) * 100) << "%" << endl;
}