#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    char board[16][16];
    cin >> s1 >> s2;
    for (int i = 0; i< 8; i++)
    {
        board[0][i*2] = s1[i];
        board[0][(i*2)+1] = s2[i];
    }
}