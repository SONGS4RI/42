#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, res = -1;

pair<int,int> moveBall(int dir, int nx, int ny, char ball, vector<string>& board) {
	board[nx][ny] = '.';
	while (1) {
		nx += dx[dir];
		ny += dy[dir];
		if (board[nx][ny] == 'O') {
			return {nx, ny};
		}
		if (board[nx][ny] != '.') {
			break;
		}
	}
	board[nx - dx[dir]][ny - dy[dir]] = ball;
	return {nx - dx[dir], ny - dy[dir]};
}

void dfs(int cnt, pair<int,int> r_pos, pair<int,int> b_pos, vector<string>& board) {
	if (cnt > 9 || (res != -1 && cnt >= res)) return ;
	for (int dir=0; dir<4; dir++) {
		pair<int,int> r_npos, b_npos;
		if ((dir == 0 && r_pos.first > b_pos.first)   ||
			(dir == 1 && r_pos.second < b_pos.second) ||
			(dir == 2 && r_pos.first < b_pos.first)   ||
			(dir == 3 && r_pos.second > b_pos.second)) {
			b_npos = moveBall(dir, b_pos.first, b_pos.second, 'B', board);
			r_npos = moveBall(dir, r_pos.first, r_pos.second, 'R', board);
		} else {
			r_npos = moveBall(dir, r_pos.first, r_pos.second, 'R', board);
			b_npos = moveBall(dir, b_pos.first, b_pos.second, 'B', board);
		}
		if (r_pos == r_npos && b_pos == b_npos) continue;

		if (board[b_npos.first][b_npos.second] == 'O' && board[r_npos.first][r_npos.second] == 'O') {
			board[r_pos.first][r_pos.second] = 'R';
			board[b_pos.first][b_pos.second] = 'B';
			continue;
		}
		if (board[b_npos.first][b_npos.second] == 'O') {
			board[r_npos.first][r_npos.second] = '.';
			board[r_pos.first][r_pos.second] = 'R';
			board[b_pos.first][b_pos.second] = 'B';
			continue;
		}
		if (board[r_npos.first][r_npos.second] == 'O') {
			board[b_npos.first][b_npos.second] = '.';
			board[r_pos.first][r_pos.second] = 'R';
			board[b_pos.first][b_pos.second] = 'B';
			res = cnt + 1;
			break ;
		}

		dfs(cnt + 1, r_npos, b_npos, board);

		board[r_npos.first][r_npos.second] = '.';
		board[b_npos.first][b_npos.second] = '.';
		board[r_pos.first][r_pos.second] = 'R';
		board[b_pos.first][b_pos.second] = 'B';
	}
}

int main() {
	cin >> n >> m;
	vector<string> board(n, string(m, ' '));
	pair<int,int> r_pos, b_pos;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				r_pos = {i, j};
			} else if (board[i][j] == 'B') {
				b_pos = {i, j};
			}
		}
	}
	dfs(0, r_pos, b_pos, board);
	cout << res << "\n";
}