#include <iostream>
#include <list>

using namespace std;

int main()
{
    int source, dest;
    int T, v, ed;

    cout << "Number of Vertices : ";
    cin >> v;
    cout << "Number of Edges : ";
    cin >> ed;

    list<int> *graph = new list<int>[v];
    list<int>::iterator i;

    for (int t = 0; t < ed; t++)
    {
        cout << "Enter Source and Dest. Vertices : ";
        cin >> source >> dest;
        graph[source].push_back(dest);
    }

    for (int t = 0; t < v; t++)
    {
        for (i = graph[t].begin(); *i != graph[t].size(); i++)
        {
            cout << *i << " --> ";
        }
        cout << endl;
    }
}