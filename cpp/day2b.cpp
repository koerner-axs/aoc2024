#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<int> report, bool ascending, bool skipFirst)
{
    int badCount = 0;
    int prev = report[skipFirst ? 1 : 0];
    for (int i = 1 + skipFirst; i < report.size(); i++)
    {
        int diff = report[i] - prev;
        if (abs(diff) > 3 || (ascending ? diff <= 0 : diff >= 0))
        {
            badCount++;
        }
        else
        {
            prev = report[i];
        }
    }
    return skipFirst ? badCount == 0 : badCount <= 1;
}

bool isSafe(vector<int> report)
{
    if (report.size() < 2)
    {
        return true;
    }
    return isSafe(report, true, true) || isSafe(report, true, false) || isSafe(report, false, true) || isSafe(report, false, false);
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
