#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int n, l, r, answer;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
	cin >> n >> l >> r;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}
	unordered_map<int, int> um;
	while (1) {
		vector<vector<int>> vis(n, vector<int>(n, 0));
		um.clear();
		int union_idx = 1;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (!vis[i][j]) {
					int union_cnt = 1, union_sum = board[i][j];
					queue<pair<int, int>> q;
					q.push({i, j});
					vis[i][j] = union_idx;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int dir=0; dir<4; dir++) {
							int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
							if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
							int res = abs(board[cur.first][cur.second] - board[nx][ny]);
							if (vis[nx][ny] || res < l || res > r) continue;
							vis[nx][ny] = union_idx;
							union_cnt++;
							union_sum += board[nx][ny];
							q.push({nx, ny});
						}
					}
					um[union_idx] = union_sum / union_cnt;
					union_idx++;
				}
			}
		}
		if (union_idx == n*n+1) break ;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				board[i][j] = um[vis[i][j]];
			}
		}
		answer++;
	}

	cout << answer << "\n";
}