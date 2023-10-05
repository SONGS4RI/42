#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, K, answer;

unordered_map<pair<int, int>, vector<int>> um;

int main() {
	cin >> N >> K;
	vector<vector<int>> board(N, vector<int>(N));
	vector<int> dirs(K+1);
	vector<pair<int, int>> pos;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> board[i][j];
		}
	}
	int r, c, dir;
	for (int i=1; i<=K; i++) {
		cin >> r >> c >> dir;
		um[{r, c}].push_back(i);
		pos[i] = {r, c};
		dirs[i] = dir;
	}
	while (answer <= 1000) {
		// 구현
	}
	if (answer > 1000) answer = -1;
	cout << answer << "\n";
}