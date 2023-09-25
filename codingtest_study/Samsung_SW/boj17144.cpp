#include <iostream>
#include <vector>
using namespace std;

int r, c, t, cw, ccw, answer;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
	cin >> r >> c >> t;
	vector<vector<int>> board(r, vector<int>(c));
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> board[i][j];
		}
		if (board[i][0] == -1 && !cw) {
			ccw = i;
			cw = i + 1;
		}
	}

	while (t--) {
		// spreading
		vector<vector<int>> spread(r, vector<int>(c, 0));
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (board[i][j] >= 5) {
					int spread_dir = 4;
					for (int dir=0; dir<4; dir++) {
						int nx = i + dx[dir], ny = j + dy[dir];
						if (nx<0 || ny<0 || nx>=r || ny>=c || board[nx][ny] == -1) {
							spread_dir--;
							continue;
						}
						spread[nx][ny] += board[i][j] / 5;
					}
					board[i][j] -= (board[i][j] / 5) * spread_dir;
				}
			}
		}
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				board[i][j] += spread[i][j];
			}
		}
		// ccw
		pair<int, int> cur = {ccw-1, 0};
		for (; cur.first > 0; cur.first--) board[cur.first][cur.second] = board[cur.first-1][cur.second];
		for (; cur.second < c-1; cur.second++) board[cur.first][cur.second] = board[cur.first][cur.second+1];
		for (; cur.first < ccw; cur.first++) board[cur.first][cur.second] = board[cur.first+1][cur.second];
		for (; cur.second > 1; cur.second--) board[cur.first][cur.second] = board[cur.first][cur.second-1];
		board[cur.first][cur.second] = 0;
		//cw
		cur = {cw+1, 0};
		for (; cur.first < r-1; cur.first++) board[cur.first][cur.second] = board[cur.first+1][cur.second];
		for (; cur.second < c-1; cur.second++) board[cur.first][cur.second] = board[cur.first][cur.second+1];
		for (; cur.first > cw; cur.first--) board[cur.first][cur.second] = board[cur.first-1][cur.second];
		for (; cur.second > 1; cur.second--) board[cur.first][cur.second] = board[cur.first][cur.second-1];
		board[cur.first][cur.second] = 0;
	}

	for (auto& r : board) {
		for (auto c : r) {
			if (c > 0) answer += c;
		}
	}
	cout << answer << "\n";
}