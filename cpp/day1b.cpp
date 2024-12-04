#include <bits/stdc++.h>

using namespace std;

int N = 1000;

int main()
{
    vector<int> l1;
    unordered_map<int, int> m2;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        l1.push_back(a);
        if (m2.count(b))
        {
            m2[b]++;
        }
        else
        {
            m2[b] = 1;
        }
    }
    sort(l1.begin(), l1.end());
    long similarity = 0;
    for (int i = 0; i < N; i++)
    {
        int left = l1[i];
        if (m2.count(left))
        {
            long cont = left * m2[left];
            cout << left << " countright=" << m2[left] << " cont=" << cont << endl;
            similarity += cont;
        }
    }
    cout << similarity;
    return 0;
}
