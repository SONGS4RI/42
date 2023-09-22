#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> gear(4, vector<int>(8));

void dfs(int from, int idx, int rotate_dir) {
	if (idx > 0 && idx-1 != from && gear[idx-1][2] != gear[idx][6]) {
		dfs(idx, idx-1, -rotate_dir);
	}
	if (idx < 3 && idx+1 != from && gear[idx+1][6] != gear[idx][2]) {
		dfs(idx, idx+1, -rotate_dir);
	}
	if (rotate_dir == 1) {
		rotate(gear[idx].begin(), gear[idx].end()-1, gear[idx].end());
	} else {
		rotate(gear[idx].begin(), gear[idx].begin()+1, gear[idx].end());
	}
}

int main() {
	char c;
	for(int i=0; i<4; i++) {
		for (int j=0; j<8; j++) {
			cin >> c;
			gear[i][j] = c - '0';
		}
	}
	int n, idx, rotate_dir, answer=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> idx >> rotate_dir;
		dfs(idx-1, idx-1, rotate_dir);
	}

	answer = gear[0][0] + 2*gear[1][0] + 4*gear[2][0] + 8*gear[3][0];
	cout << answer << "\n";
}