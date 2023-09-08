#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int answer = 0, n;

void dfs(int cnt, vector<vector<int> >& board) {
	if (cnt == 5) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				answer = max(answer, board[i][j]);
			}
		}
		return ;
	}

	vector<vector<int> > n_board(n, vector<int>(n));
	// U
	for (int j=0; j<n; j++) {
		deque<int> dq;
		bool flag = false;
		for (int i=0; i<n; i++) {
			if (!board[i][j]) continue;
			if (!flag) {
				dq.push_back(board[i][j]);
				flag = true;
			} else if (dq.back() == board[i][j]) {
				dq.back() *= 2;
				flag = false;
			} else {
				dq.push_back(board[i][j]);
			}
		}
		for (int i=0; i<n; i++) {
			if (!dq.empty()) {
				n_board[i][j] = dq.front();
				dq.pop_front();
			} else {
				n_board[i][j] = 0;
			}
		}
	}
	dfs(cnt+1, n_board);

	// D
	for (int j=0; j<n; j++) {
		deque<int> dq;
		bool flag = false;
		for (int i=n-1; i>=0; i--) {
			if (!board[i][j]) continue;
			if (!flag) {
				dq.push_back(board[i][j]);
				flag = true;
			} else if (dq.back() == board[i][j]) {
				dq.back() *= 2;
				flag = false;
			} else {
				dq.push_back(board[i][j]);
			}
		}
		for (int i=n-1; i>=0; i--) {
			if (!dq.empty()) {
				n_board[i][j] = dq.front();
				dq.pop_front();
			} else {
				n_board[i][j] = 0;
			}
		}
	}
	dfs(cnt+1, n_board);

	// L
	for (int i=0; i<n; i++) {
		deque<int> dq;
		bool flag = false;
		for (int j=0; j<n; j++) {
			if (!board[i][j]) continue;
			if (!flag) {
				dq.push_back(board[i][j]);
				flag = true;
			} else if (dq.back() == board[i][j]) {
				dq.back() *= 2;
				flag = false;
			} else {
				dq.push_back(board[i][j]);
			}
		}
		for (int j=0; j<n; j++) {
			if (!dq.empty()) {
				n_board[i][j] = dq.front();
				dq.pop_front();
			} else {
				n_board[i][j] = 0;
			}
		}
	}
	dfs(cnt+1, n_board);

	// R
	for (int i=0; i<n; i++) {
		deque<int> dq;
		bool flag = false;
		for (int j=n-1; j>=0; j--) {
			if (!board[i][j]) continue;
			if (!flag) {
				dq.push_back(board[i][j]);
				flag = true;
			} else if (dq.back() == board[i][j]) {
				dq.back() *= 2;
				flag = false;
			} else {
				dq.push_back(board[i][j]);
			}
		}
		for (int j=n-1; j>=0; j--) {
			if (!dq.empty()) {
				n_board[i][j] = dq.front();
				dq.pop_front();
			} else {
				n_board[i][j] = 0;
			}
		}
	}
	dfs(cnt+1, n_board);
}

int main() {
	cin >> n;
	vector<vector<int> > board(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, board);

	cout << answer << "\n";
}