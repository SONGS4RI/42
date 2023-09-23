#include <iostream>
#include <vector>
using namespace std;

int n, x, y, d, g, answer;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
vector<vector<bool>> board(101, vector<bool>(101, false));

void drawDragonCurve(vector<int>& dirs) {
    for (int i=dirs.size()-1; i>=0; i--) {
        int dir = (dirs[i]+1)%4;
        dirs.push_back(dir);
        x += dx[dir];
        y += dy[dir];
        board[x][y] = true;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x >> y >> d >> g;
        board[x][y] = true;
        x += dx[d];
        y += dy[d];
        board[x][y] = true;
        vector<int> dirs = {d};
        while (g--) {
            drawDragonCurve(dirs);
        }
    }
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
}