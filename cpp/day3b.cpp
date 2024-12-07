#include <bits/stdc++.h>

using namespace std;

int main()
{
    long prod_sum = 0;
    bool active = true;
    string line;
    regex pattern("do\\(\\)|don't\\(\\)|mul\\((\\d+),(\\d+)\\)");
    while (getline(cin, line))
    {
        smatch matches;
        while (regex_search(line, matches, pattern))
        {
            if (matches[0].str() == "do()")
            {
                active = true;
            }
            else if (matches[0].str() == "don't()")
            {
                active = false;
            }
            else if (active)
            {
                int a = stoi(matches[1].str());
                int b = stoi(matches[2].str());
                prod_sum += ((long) a) * b;
            }
            //cout << matches[0] << " " << active << " " << prod_sum << endl;
            line = matches.suffix().str();
        }
    }
    cout << prod_sum << endl;
    return 0;
}
