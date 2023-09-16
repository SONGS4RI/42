#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, cur_x, cur_y, cur_dir, answer;

bool isNotCleaned(vector<vector<int> >& board) {
	for (int dir=0; dir<4; dir++) {
		if (!board[cur_x + dx[dir]][cur_y + dy[dir]]) {
			return true;
		}
	}
	return false;
}

void dfs(vector<vector<int> >& board) {
	if (!board[cur_x][cur_y]) {
		board[cur_x][cur_y] = 2;
		answer++;
	}
	int nx, ny;
	if (isNotCleaned(board)) {
		cur_dir = (cur_dir + 3) % 4;
		nx = cur_x + dx[cur_dir];
		ny = cur_y + dy[cur_dir];
		if (!board[nx][ny]) {
			cur_x = nx;
			cur_y = ny;
		}
	} else {
		nx = cur_x - dx[cur_dir];
		ny = cur_y - dy[cur_dir];
		if (board[nx][ny] == 1) {
			return;
		}
		cur_x = nx;
		cur_y = ny;
	}
	dfs(board);
}

int main() {
	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	cin >> cur_x >> cur_y >> cur_dir;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	dfs(board);
	cout << answer << "\n";
}