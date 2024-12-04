#include <bits/stdc++.h>

using namespace std;

int N = 1000;

int main()
{
    vector<int> l1;
    vector<int> l2;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        l1.push_back(a);
        l2.push_back(b);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    long sum = 0;
    for (int i = 0; i < N; i++)
    {
        long diff = abs(l1[i] - l2[i]);
        cout << l1[i] << " " << l2[i] << " diff=" << diff << endl;
        sum += diff;
    }
    cout << sum;
    return 0;
}
