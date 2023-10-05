#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, answer;
int dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
int changed_dir[5] = {0, 2, 1, 4, 3};
bool finish = false;

int main() {
	cin >> N >> K;
	vector<vector<int>> board(N+1, vector<int>(N+1));
	vector<vector<vector<int>>> objs(N+1, vector<vector<int>>(N+1));
	vector<int> dirs(K+1);
	vector<pair<int, int>> pos(K+1);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> board[i][j];
		}
	}
	int r, c, dir;
	for (int i=1; i<=K; i++) {
		cin >> r >> c >> dir;
		objs[r][c].push_back(i);
		pos[i] = {r, c};
		dirs[i] = dir;
	}
	while (answer <= 1000 && !finish) {
		for(int i=1; i<=K; i++) {
			int cur_x = pos[i].first, cur_y = pos[i].second;
			int nx = cur_x + dx[dirs[i]], ny = cur_y + dy[dirs[i]];
			if (nx<=0 || ny<=0 || nx>N || ny>N || board[nx][ny]==2) {
				dirs[i] = changed_dir[dirs[i]];
				nx = cur_x + dx[dirs[i]];
				ny = cur_y + dy[dirs[i]];
				if (nx<=0 || ny<=0 || nx>N || ny>N || board[nx][ny]==2) {
					continue;
				}
			}
			vector<int>::iterator e = objs[cur_x][cur_y].end();
			vector<int>::iterator s = find(objs[cur_x][cur_y].begin(), e, i);
			int size = objs[nx][ny].size();
			objs[nx][ny].insert(objs[nx][ny].end(), s, e);
			if (board[nx][ny] == 1) {
				reverse(objs[nx][ny].begin() + size, objs[nx][ny].end());
			}
			for (auto iter = s; iter!=e; iter++) {
				pos[*iter] = {nx, ny};
			}
			if (objs[nx][ny].size() >= 4) {
				finish = true;
				break;
			}
			objs[cur_x][cur_y].erase(s, e);
		}
		answer++;
	}
	if (answer > 1000) answer = -1;
	cout << answer << "\n";
}