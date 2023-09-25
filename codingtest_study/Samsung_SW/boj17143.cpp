#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int R, C, M;
int r, c, s, d, z, answer;
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, 1, -1}, change_dir[5] = {0, 2, 1, 4, 3};

int main() {
	cin >> R >> C >> M;
	vector<vector<int>> board(R, vector<int>(C, 0)), moved(R, vector<int>(C));
	unordered_map<int, vector<int>> um;
	for (int i=1; i<=M; i++) {
		cin >> r >> c >> s >> d >> z;
		board[r-1][c-1] = i;
		um[i] = {s, d, z};
	}
	for (int j=0; j<C; j++) {
		// 잡고
		for (int i=0; i<R; i++) {
			if (board[i][j]) {
				answer += um[board[i][j]][2];
				um.erase(board[i][j]);
				board[i][j] = 0;
				break;
			}
		}
		// 이동
		for (auto& r : moved) fill(r.begin(), r.end(), 0);
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				int shark = board[i][j];
				if (shark) {
					int speed = um[shark][0], dir = um[shark][1];
					int x = i, y = j;
					speed %= dir <= 2 ? (R-1)*2 : (C-1)*2;
					while (speed--) {
						int nx = x + dx[dir], ny = y + dy[dir];
						if (nx<0 || ny<0 || nx>=R || ny>=C) {
							dir = change_dir[dir];
							nx = x + dx[dir];
							ny = y + dy[dir];
						}
						x = nx;
						y = ny;
					}
					if (moved[x][y] && um[shark][2] < um[moved[x][y]][2]) continue;
					moved[x][y] = shark;
					um[shark][1] = dir;
				}
			}
		}
		board = moved;
	}
	cout << answer << "\n";
}