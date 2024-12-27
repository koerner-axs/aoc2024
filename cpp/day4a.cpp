#include <bits/stdc++.h>

using namespace std;

const char* XMAS = "XMAS";

int match(int x, int y, int dx, int dy, vector<vector<char>>& data)
{
    int matches = 2;
    for (int i = 0; i < 4; i++)
    {
        if (data[y+i*dy][x+i*dx] != XMAS[i])
        {
            matches--;
            break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (data[y+i*dy][x+i*dx] != XMAS[3-i])
        {
            matches--;
            break;
        }
    }
    return matches;
}

int count_matches(int x, int y, vector<vector<char>>& data)
{
    int count = 0;
    count += match(x, y, 0, 1, data);
    count += match(x, y, -1, 1, data);
    count += match(x, y, 1, 1, data);
    count += match(x, y, 1, 0, data);
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
    vector<vector<char>> padded(height + 3, vector<char>(width + 6));
    for (int y = 0; y < height; y ++)
    {
        for (int x = 0; x < width; x++)
        {
            padded[y][x+3] = lines[y][x];
        }
    }
    long countXmas = 0;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            countXmas += count_matches(x + 3, y, padded);
        }
    }
    cout << height << " x " << width << endl;
    cout << "There are " << countXmas << " XMASes!" << endl;
    return 0;
}
