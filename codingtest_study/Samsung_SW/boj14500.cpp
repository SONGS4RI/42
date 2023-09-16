#include <iostream>
#include <vector>

using namespace std;

int n, m, answer = 0;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void tetro(int cnt, int res, int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& board) {
	if (cnt == 4) {
		answer = max(answer, res);
		return ;
	}
	for (int dir=0; dir<4; dir++) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		tetro(cnt+1, res + board[nx][ny], nx, ny, vis, board);
		vis[nx][ny] = false;
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	vector<vector<bool> > vis(n, vector<bool>(m, false));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			vis[i][j] = true;
			tetro(1, board[i][j], i, j, vis, board);
			vis[i][j] = false;

			if (i < n-2) {
				if (j >= 1) answer = max(answer, board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j-1]);
				if (j < m - 1) answer = max(answer, board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j+1]);
			}
			if (j < m-2) {
				if (i >= 1) answer = max(answer, board[i][j] + board[i][j+1] + board[i][j+2] + board[i-1][j+1]);
				if (i < n - 1) answer = max(answer, board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1]);
			}
		}
	}
	cout << answer << "\n";
}
