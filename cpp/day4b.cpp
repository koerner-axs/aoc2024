#include <bits/stdc++.h>

using namespace std;

bool match(int x, int y, const char* pattern, vector<vector<char>>& data)
{
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            char exp = pattern[j*3+i];
            if (exp != '.' && data[y+j][x+i] != exp)
            {
                return false;
            }
        }
    }
    return true;
}

int count_matches(int x, int y, vector<vector<char>>& data)
{
    int count = 0;
    count += match(x, y, "M.S.A.M.S", data);
    count += match(x, y, "M.M.A.S.S", data);
    count += match(x, y, "S.S.A.M.M", data);
    count += match(x, y, "S.M.A.S.M", data);
    return count;
}

int main()
{
    vector<string> lines;
    string line;
    int width = 0;
    while (getline(cin, line))
    {
        if (!line.empty())
        {
            width = line.size();
            lines.push_back(line);
        }
    }
    int height = lines.size();
    vector<vector<char>> padded(height + 2, vector<char>(width + 2));
    for (int y = 0; y < height; y ++)
    {
        for (int x = 0; x < width; x++)
        {
            padded[y][x] = lines[y][x];
        }
    }
    long countX_mas = 0;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            countX_mas += count_matches(x, y, padded);
        }
    }
    cout << height << " x " << width << endl;
    cout << "There are " << countX_mas << " X_MASes!" << endl;
    return 0;
}
