#include <bits/stdc++.h>

using namespace std;

int main()
{
    long prod_sum = 0;
    string line;
    regex pattern("mul\\((\\d+),(\\d+)\\)");
    while (getline(cin, line))
    {
        smatch matches;
        while (regex_search(line, matches, pattern))
        {
            int a = stoi(matches[1].str());
            int b = stoi(matches[2].str());
            prod_sum += ((long) a) * b;
            line = matches.suffix().str();
        }
    }
    cout << prod_sum << endl;
    return 0;
}
