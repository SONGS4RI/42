#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, num, answer = INT32_MAX;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> stores, houses;
vector<vector<int>> board(50, vector<int>(50, -1));
queue<pair<int,int>> q;

void calChickenScore(vector<int>& vis) {
	for(auto& c : board) fill(c.begin(), c.end(), -1);
	while (!q.empty()) q.pop();
	for (auto& c : vis) {
		q.push(stores[c]);
		board[stores[c].first][stores[c].second] = 0;
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
			if (board[nx][ny] >= 0) continue;
			board[nx][ny] = board[cur.first][cur.second] + 1;
			q.push({nx, ny});
		}
	}
	int res = 0;
	for (auto& h : houses) {
		res += board[h.first][h.second];
	}
	answer = min(answer, res);
}

void chooseStores(int cnt, int idx, vector<int>& vis) {
	if (cnt == m) {
		calChickenScore(vis);
		return ;
	}
	for (int i=idx; i<stores.size(); i++) {
		vis[cnt] = i;
		chooseStores(cnt+1, i+1, vis);
	}
}

int main() {
	cin >> n >> m;
	vector<int> vis(m, 0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> num;
			if (num == 1) houses.push_back({i, j});
			else if (num == 2) stores.push_back({i, j});
		}
	}
	chooseStores(0, 0, vis);
	cout << answer << "\n";
}

/*

0 0 2 0 0
0 2 1 2 0
0 2 1 2 0
0 0 2 0 2
0 0 0 2 1

*/