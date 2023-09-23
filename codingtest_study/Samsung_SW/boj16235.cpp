#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m, k, answer;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin >> n >> m >> k;
	vector<vector<int>> A(n, vector<int>(n)), points(n, vector<int>(n, 5));
	vector<vector<deque<int>>> trees(n, vector<deque<int>>(n));
	for (int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
	int x, y, old;
	for (int i=0; i<m; i++) {
		cin >> x >> y >> old;
		trees[x-1][y-1].push_back(old);
	}
	while (k--) {
		//봄, 여름
		deque<pair<int,int> > q;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int rotten = 0;
				for (int k=0; k<trees[i][j].size(); k++) {
					if (trees[i][j][k] <= points[i][j]) {
						points[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
						if (trees[i][j][k]%5 == 0) {
							q.push_back({i, j});
						}
					} else {
						for (int l=k; l<trees[i][j].size(); l++) {
							rotten += trees[i][j][l]/2;
						}
						trees[i][j].erase(trees[i][j].begin()+k, trees[i][j].end());
						break;
					}
				}
				points[i][j] += rotten;
			}
		}
		//가을
		while (!q.empty()) {
			pair<int, int> cur = q.back();
			q.pop_back();
			for (int dir=0; dir<8; dir++) {
				int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
				if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
				trees[nx][ny].push_front(1);
			}
		}
		//겨울
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				points[i][j] += A[i][j];
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			answer += trees[i][j].size();
		}
	}
	cout << answer << "\n";
}