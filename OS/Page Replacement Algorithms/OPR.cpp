#include <iostream>
using namespace std;

int optimizeFrame(int a[], int startIndex, int pages, int frames, int check[])
{
    int max = -1, cur, index;

    for (int j = 0; j < frames; j++)
    {
        cur = a[j];
        for (int k = startIndex; k < pages; k++)
        {
            if (cur == a[k])
            {
                check[j] = k;
                break;
            }
        }
    }

    for (int j = 0; j < frames; j++)
    {
        if (check[j] == -1)
            return j;

        if (check[j] > max)
        {
            max = check[j];
            index = j;
        }
    }
    return index;
}

int checkPageHit(int frame[], int d, int frames)
{
    for (int k = 0; k < frames; k++)
    {
        if (frame[k] == d)
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

    int *a = new int[pages];
    int *frame = new int[frames];
    int *check = new int[frames];

    for (t = 0; t < pages; t++)
        cin >> a[t];

    for (t = 0; t < frames; t++)
    {
        check[t] = -1;
    }

    static int count = 0;
    int replaceIndex;

    for (t = 0; t < pages; t++)
    {
        if (t < frames)
        {
            frame[t] = a[t];
            continue;
        }
        else
        {
            if (count > frames)
                count = 0;
            temp = a[t];
            if (checkPageHit(frame, temp, frames))
            {
                pageHits++;
                continue;
            }
            else
            {
                replaceIndex = optimizeFrame(a, t, pages, frames, check);
                frame[replaceIndex] = a[t];
                count++;
                continue;
            }
        }
    }
    cout << pageHits;
    cout << "Page Hits : " << pageHits << endl;
    cout << "Page Faults : " << (pages - pageHits) << endl;
    cout << "Hit Ratio : " << float(float(pageHits / pages)) * 100 << "%" << endl;
    cout << "Miss Ratio : " << float(float(float(pages - pageHits) / pages) * 100) << "%" << endl;
}