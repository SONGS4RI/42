#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

unordered_map<int, vector<int> > um;
vector<int> res_dfs, res_bfs;

void dfs(int parent, vector<bool>& vis) {
	vis[parent] = true;
	res_dfs.push_back(parent);
	for (auto& c : um[parent]) {
		if (!vis[c]) {
			dfs(c, vis);
		}
	}
}

void bfs(int parent, vector<bool>& vis) {
	queue<int> q;
	q.push(parent);
	while (!q.empty()) {
		parent = q.front(); q.pop();
		if (vis[parent]) continue;
		vis[parent] = true;
		res_bfs.push_back(parent);
		for (auto& c : um[parent]) {
			if (!vis[c]) {
				q.push(c);
			}
		}
	}
}

int main() {
	int n, m, v, s, e;
	cin >> n >> m >> v;
	vector<bool> vis_dfs(n+1, false), vis_bfs(n+1, false);
	for (int i=0; i<m; i++) {
		cin >> s >> e;
		um[s].push_back(e);
		um[e].push_back(s);
	}

	for (auto& c : um) {
		sort(c.second.begin(), c.second.end());
	}

	//dfs
	dfs(v, vis_dfs);
	for (auto c : res_dfs) {
		cout << c << " ";
	}
	cout << "\n";
	//bfs
	bfs(v, vis_bfs);
	for (auto c : res_bfs) {
		cout << c << " ";
	}
	cout << "\n";
}