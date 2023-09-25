#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, baby_size = 2, eat_cnt, answer;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

pair<int, int> baby;

int main() {
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				board[i][j] = 0;
				baby = {i, j};
			}
		}
	}

	while (1) {
		vector<vector<int>> vis(n, vector<int>(n, -1));
		deque<pair<int, int>> dq = {baby};
		pair<int, int> cur, target = {INT32_MAX, INT32_MAX};
		int dist = INT32_MAX;
		vis[baby.first][baby.second] = 0;
		while (!dq.empty()) {
			cur = dq.back();
			dq.pop_back();
			for (int dir=0; dir<4; dir++) {
				int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
				if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
				if (vis[nx][ny]>=0 || board[nx][ny] > baby_size) continue;
				if (vis[cur.first][cur.second] + 1 > dist) continue;
				if (board[nx][ny] && board[nx][ny] != baby_size &&
					(target.first > nx || (target.first == nx && target.second > ny))) {
						dist = vis[cur.first][cur.second] + 1;
						target = {nx, ny};
				}
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				dq.push_front({nx, ny});
			}
		}
		if (dist == INT32_MAX) break;
		answer += dist;
		baby = target;
		board[baby.first][baby.second] = 0;
		if (++eat_cnt == baby_size) {
			baby_size++;
			eat_cnt = 0;
		}
	}
	cout << answer << "\n";
}