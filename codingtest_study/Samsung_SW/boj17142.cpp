#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int N, M, answer=INT32_MAX;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<int>> vis(50, vector<int>(50));
vector<pair<int, int>> virus;
vector<int> idxs(10);


void spread(vector<vector<int>>& board) {
	deque<pair<int, int>> dq;
	for (auto& r : vis) fill(r.begin(), r.end(), -1);
	for (int i=0; i<M; i++) {
		dq.push_back(virus[idxs[i]]);
		vis[virus[idxs[i]].first][virus[idxs[i]].second] = 0;
	}
	int cnt = 0;
	while (!dq.empty()) {
		pair<int, int> cur = dq.front();
		dq.pop_front();
		// if (board[cur.first][cur.second] == 2 && vis[cur.first][cur.second]) {
		// 	vis[cur.first][cur.second]--;
		// }
		if (board[cur.first][cur.second] == 0) cnt++;
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
			if (vis[nx][ny] >= 0 || board[nx][ny] == 1) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			if (board[nx][ny] == 2) {
				dq.push_front({nx, ny});
			} else {
				dq.push_back({nx, ny});
			}
		}
	}
	int day = 0;
	for (auto& r : vis) day = max(day, *max_element(r.begin(), r.end()));
	// if (day == 5) {
	// 	cout << "================\n";
	// 	for (int i=0; i<N; i++) {
	// 		for (int j=0; j<N; j++) cout << vis[i][j] << " ";
	// 		cout << "\n";
	// 	}
	// }
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (vis[i][j] == -1 && board[i][j] == 0) return ;
		}
	}
	answer = min(answer, day);
}

void dfs(int cnt, int idx, vector<vector<int>>& board) {
	if (cnt == M) {
		spread(board);
		return ;
	}
	for (int i=idx; i<virus.size(); i++) {
		idxs[cnt] = i;
		dfs(cnt+1, i+1, board);
	}
}

int main() {
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({i, j});
		}
	}
	dfs(0, 0, board);
	if (answer == INT32_MAX) answer = -1;
	cout << answer << "\n";
}