#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<int> report)
{
    if (report.size() <= 2)
    {
        return true;
    }
    int diff = report[1] - report[0];
    if (abs(diff) > 3 || diff == 0)
    {
        return false;
    }
    bool ascending = diff > 0;
    for (int i = 2; i < report.size(); i++)
    {
        diff = report[i] - report[i-1];
        if (abs(diff) > 3 || (ascending ? diff <= 0 : diff >= 0))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string line;
    int safeReports = 0;
    while (getline(cin, line))
    {
        vector<int> in;
        int num;
        for (istringstream ss(line); ss >> num;)
        {
            in.push_back(num);
        }
        safeReports += isSafe(in);
    }
    cout << safeReports;
    return 0;
}
