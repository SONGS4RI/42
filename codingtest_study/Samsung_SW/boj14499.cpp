#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

/*
  1
3 0 2
  4
  5
*/

void roll(vector<int>& dice, int dir) {
	string order;
	switch (dir) {
		case 1: order = "302";
			break;
		case 2: order = "203";
			break;
		case 3: order = "401";
			break;
		default: order = "104";// 4
			break;
	}
	int tmp = dice[5];
	dice[5] = dice[order[0] - '0'];
	dice[order[0] - '0'] = dice[order[1] - '0'];
	dice[order[1] - '0'] = dice[order[2] - '0'];
	dice[order[2] - '0'] = tmp;
}

int main() {
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	vector<vector<int> > board(n, vector<int>(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}
	int dir;
	vector<int> dice(6, 0);
	while (k--) {
		cin >> dir;
		int nx = x + dx[dir-1], ny = y + dy[dir-1];
		if (nx<0 || ny <0 || nx >= n || ny >= m) continue;
		roll(dice, dir);
		if (!board[nx][ny]) {
			board[nx][ny] = dice[0];
		} else {
			dice[0] = board[nx][ny];
			board[nx][ny] = 0;
		}
		cout << dice[5] << "\n";
		x = nx;
		y = ny;
	}
}