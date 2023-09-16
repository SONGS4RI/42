#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
	int n, k, l, row, col;
	cin >> n >> k;
	vector<vector<int> > board(n, vector<int>(n, -1));
	for (int i=0; i<k; i++) {
		cin >> row >> col;
		board[row-1][col-1] = 4;// apple
	}
	queue<pair<int, char> > q;
	cin >> l;
	while (l--) {
		pair<int, char> p;
		cin >> p.first >> p.second;
		q.push(p);
	}
	int cur_time = 0, dir = 0;
	pair<int, int> head(0, 0), tail(0, 0);
	while (1) {
		if (!q.empty() && q.front().first == cur_time) {
			char ld = q.front().second; q.pop();
			dir = ld == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
		}
		board[head.first][head.second] = dir;

		int nx = head.first + dx[dir], ny = head.second + dy[dir];
		if (nx<0 || ny<0 || nx >= n || ny >= n) break;
		if (board[nx][ny] >= 0 && board[nx][ny] != 4) break;
		if (board[nx][ny] != 4) {
			int tail_dir = board[tail.first][tail.second];
			board[tail.first][tail.second] = -1;
			tail.first += dx[tail_dir];
			tail.second += dy[tail_dir];
		}
		board[nx][ny] = dir;
		head = {nx, ny};
		cur_time++;
	}
	cout << cur_time+1 << "\n";
}