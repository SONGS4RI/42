#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, answer = INT32_MAX;
vector<vector<int>> cctv = {{0}, {0,2}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int getSafeArea(vector<vector<int> >& board) {
	int res = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!board[i][j]) res++;
		}
	}
	return res;
}

bool checkArea(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

vector<vector<int> > activateCCTV(int x, int y, vector<int> dirs, vector<vector<int> > board) {
	for (auto& dir : dirs) {
		int nx = x + dx[dir], ny = y + dy[dir];
		while (checkArea(nx, ny) && (board[nx][ny] != 6)) {
			if (!board[nx][ny]) board[nx][ny] = 7;
			nx += dx[dir];
			ny += dy[dir];
		}
	}
	return board;
}

void dfs(vector<vector<int> > board, queue<pair<int,int>> cctv_pos) {
	if (cctv_pos.empty()) {
		answer = min(answer, getSafeArea(board));
		return ;
	}
	pair<int, int> cur = cctv_pos.front();
	cctv_pos.pop();
	int cctv_num = board[cur.first][cur.second];
	vector<int> dirs = cctv[cctv_num-1];
	for (int i=0; i<4; i++) {
		if (cctv_num == 2 && i >= 2) continue;
		if (cctv_num == 5 && i >= 1) continue;
		for (auto& dir : dirs) {
			dir = (dir + 1) % 4;
		}
		dfs(activateCCTV(cur.first, cur.second, dirs, board), cctv_pos);
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	queue<pair<int,int>> cctv;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
			if (board[i][j] && board[i][j] != 6) {
				cctv.push({i, j});
			}
		}
	}
	dfs(board, cctv);
	cout << answer << "\n";
}