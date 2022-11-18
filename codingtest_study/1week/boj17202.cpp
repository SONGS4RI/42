#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    int board[16][16] ,res;

    cin >> s1 >> s2;
    for (int i = 0; i< 8; i++)
    {
        board[0][i*2] = s1[i] - '0';
        board[0][(i*2)+1] = s2[i] - '0';
    }
    for (int i = 1; i < 15; i++)
    {
        for(int j = 0; j < 16 - i; j++)
            board[i][j] = (board[i - 1][j] + board[i - 1][j+1]) % 10;
    }
    res = board[14][0]*10 + board[14][1];
    if (res > 9)
        cout << res << '\n';
    else
        cout << 0 << res << '\n';
}