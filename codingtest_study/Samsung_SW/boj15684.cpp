#include <iostream>
#include <vector>
using namespace std;

int n, m, h, answer = -1, a, b;

bool isAnswer(vector<vector<int>>& board) {
	for (int j=1; j<n+1; j++) {
		int cur = j;
		for (int i=1; i<h+1; i++) {
			if (board[i][cur]) {
				cur = board[i][cur];
			}
		}
		if (cur != j) return false;
	}
	return true;
}

void dfs(int cnt, int x, int y, vector<vector<int>>& board) {
	if (answer != -1 && cnt >= answer) return ;
	if (isAnswer(board)) {
		answer = cnt;
	}
	if (cnt == 3) return ;
	for (int i=x; i<h+1; i++) {
		int j = i == x ? y : 1;
		for (; j<n; j++) {
			if (!board[i][j] && !board[i][j+1]) {
				board[i][j] = j+1;
				board[i][j+1] = j;
				dfs(cnt+1, i, j+1, board);
				board[i][j] = 0;
				board[i][j+1] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m >> h;
	vector<vector<int>> board(h+1, vector<int>(n+1, 0));
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		board[a][b] = b+1;
		board[a][b+1] = b;
	}
	dfs(0, 1, 1, board);
	cout << answer << "\n";
}