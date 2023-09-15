#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int answer = 0, n;

void dfs(int day, int income, vector<pair<int,int>>& schedule) {
	answer = max(answer, income);
	for (int i=day; i<n; i++) {
		int next_day = i + schedule[i].first;
		if (next_day > n) continue;
		dfs(next_day, income + schedule[i].second, schedule);
	}
}

int main() {
	cin >> n;
	vector<pair<int,int>> schedule(n);
	for (int i=0; i<n; i++) {
		cin >> schedule[i].first >> schedule[i].second;
	}
	dfs(0, 0, schedule);
	cout << answer << "\n";
}