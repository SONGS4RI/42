#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, answer = INT32_MAX;

void dfs(int cnt, int idx, vector<bool>& vis, vector<vector<int> >& scores) {
	if (cnt == n/2) {
		int start=0, link=0;
		for (int i=1; i<=n; i++) {
			for (int j=i+1; j<=n; j++) {
				if (vis[i] && vis[j]) {
					start += scores[i][j] + scores[j][i];
				} else if (!vis[i] && !vis[j]) {
					link += scores[i][j] + scores[j][i];
				}
			}
		}
		answer = min(answer, abs(start - link));
		return ;
	}
	for (int i=idx; i<=n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(cnt+1, i+1, vis, scores);
			vis[i] = false;
		}
	}
}

int main() {
	cin >> n;
	vector<vector<int> > scores(n+1, vector<int>(n+1));
	vector<bool> vis(n+1, false);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> scores[i][j];
		}
	}
	dfs(0, 1, vis, scores);
	cout << answer << "\n";
}