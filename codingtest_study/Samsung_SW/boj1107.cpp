#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<bool> button(10, true);
int answer;
int n, m, n_size;

void dfs(int cnt, int num) {
	if (cnt > 0) {
		answer = min(answer, cnt + abs(n - num));
	}
	if (cnt > n_size) return ;
	for (int i=0; i<10; i++) {
		if (button[i] && num <= n) {
			dfs(cnt+1, num*10+i);
		}
	}
}

int main() {
	cin >> n >> m;
	n_size = to_string(n).size();
	for (int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		button[tmp] = false;
	}
	answer = abs(n - 100);
	dfs(0, 0);
	cout << answer << "\n";
}