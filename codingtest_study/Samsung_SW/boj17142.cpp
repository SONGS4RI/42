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


void spread(vector<vector<int>>& board) {// bfs
	deque<pair<int, int>> dq;
	for (auto& r : vis) fill(r.begin(), r.end(), -1);
	for (int i=0; i<M; i++) {
		dq.push_back(virus[idxs[i]]);
		vis[virus[idxs[i]].first][virus[idxs[i]].second] = 0;
	}
	while (!dq.empty()) {
		pair<int, int> cur = dq.front();
		dq.pop_front();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
			if (vis[nx][ny] >= 0 || board[nx][ny] == 1) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			dq.push_back({nx, ny});
		}
	}
	int day = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (vis[i][j] == -1 && board[i][j] == 0) return;// 빈공간인데 방문 못했다면
			if (board[i][j] == 2 && vis[i][j]) continue;// 비활성화 바이러스이면
            /*
            	비활성화 바이러스일때 넘기는 이유는 마지막 이동한 부분이 비활성화 바이러스인경우를 제외해주려했기 때문이다.
            */
			day = max(day, vis[i][j]);
		}
	}
	answer = min(answer, day);
}

void dfs(int cnt, int idx, vector<vector<int>>& board) {
	// 활성화 바이러스 골라주기
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