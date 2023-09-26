#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int r,c,k,answer;
int r_size = 3, c_size = 3;
vector<vector<int>> A(100, vector<int>(100));
unordered_map<int, int> um;

bool compare(pair<int,int>& p_a, pair<int,int>& p_b) {
	if (p_a.second == p_b.second) return p_a.first < p_b.first;
	return p_a.second < p_b.second;
}

void sortArr() {
	int len = 0;
	for (int i=0; i<r_size; i++) {
		um.clear();
		for (int j=0; j<c_size; j++) {
			if (A[i][j]) um[A[i][j]]++;
		}
		vector<pair<int,int>> res;
		for (auto& num : um) {
			res.push_back({num.first, num.second});
		}
		sort(res.begin(), res.end(), compare);
		fill(A[i].begin(), A[i].end(), 0);
		for (int j=0; j<res.size(); j++) {
			if (j*2 >= 100) break;
			A[i][j*2] = res[j].first;
			A[i][j*2+1] = res[j].second;
		}
		len = max(len, static_cast<int>(res.size()*2));
	}
	if (len > 100) len = 100;
	c_size = len;
}

void flipArr() {
	int size = max(r_size, c_size);
	for (int i=0; i<size; i++) {
		for (int j=i+1; j<size; j++) {
			swap(A[i][j], A[j][i]);
		}
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cin >> A[i][j];
		}
	}
	r--; c--;
	while (A[r][c]!=k && answer <= 100) {
		bool flip = false;
		if (r_size < c_size) {
			flip = true;
			flipArr();
			swap(r_size, c_size);
		}
		sortArr();
		if (flip) {
			flipArr();
			swap(r_size, c_size);
		}
		answer++;
	}
	if (answer > 100) answer = -1;
	cout << answer << "\n";
}