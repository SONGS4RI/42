#include <iostream>
#include <vector>
using namespace std;

int n;
int x, y, d, g, cnt;
vector<vector<int>> board(101, vector<int>(101, 0));
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };

void drawDragonCurve(vector<int>& dirs) {
    int size = dirs.size();
    for (int i = size - 1; i >= 0; i--) {
        int temp = (dirs[i] + 1) % 4;
        x += dx[temp];
        y += dy[temp];
        board[x][y] = 1;
        dirs.push_back(temp);
    }
}

int main() {
    cin >> n;
    while (n--) {
        vector<int> dirs;
        cin >> x >> y >> d >> g;

        board[x][y] = 1;
        x += dx[d];
        y += dy[d];
        board[x][y] = 1;
        dirs.push_back(d);
        while (g-- >= 0) {
            drawDragonCurve(dirs);
        }
    }
   for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] && board[i + 1][j] == 1)
                cnt++;
        }
    }
    cout << cnt << endl;
}