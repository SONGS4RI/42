#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m, answer, safe_begin = -3;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void spreadViruse(queue<pair<int,int> > virus, vector<vector<int> > board) {
	int safe_cnt = safe_begin;
	while (!virus.empty()) {
		pair<int ,int> cur = virus.front(); virus.pop();
		if (safe_cnt <= answer) return ;
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx<0 || ny<0 || nx >=n || ny>=m) continue;
			if (board[nx][ny]) continue;
			safe_cnt--;
			board[nx][ny] = 2;
			virus.push({nx, ny});
		}
	}

	answer = max(answer, safe_cnt);
}

void setWall(int cnt, int x, int y, queue<pair<int,int> >& virus, vector<vector<int> >& board) {
	if (cnt == 3) {
		spreadViruse(virus, board);
		return ;
	}

	for (int i=x; i<n; i++) {
		int j = i == x ? y : 0;
		for (; j<m; j++) {
			if (!board[i][j]) {
				board[i][j] = 1;
				setWall(cnt+1, x, y+1, virus, board);
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	queue<pair<int,int> > virus;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				safe_begin++;
			} else if (board[i][j] == 2) {
				virus.push({i, j});
			}
		}
	}
	setWall(0, 0, 0, virus, board);

	cout << answer <<"\n";
}