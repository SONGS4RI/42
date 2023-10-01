#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, answer = INT32_MAX;
vector<vector<int>> board(21, vector<int>(21));

int getRes(int x, int y, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) { //1번 선거구
				population[0] += board[r][c];
			}
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) { //2번 선거구
				population[1] += board[r][c];
			}
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) { //3번 선거구
				population[2] += board[r][c];
			}
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) { //4번 선거구
				population[3] += board[r][c];
			}
			else { //5번 선거구
				population[4] += board[r][c];
			}
		}
	}

	sort(population.begin(), population.end());
	return population[4] - population[0];
}

int main() {
	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> board[x][y];
		}
	}

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					answer = min(answer, getRes(x, y, d1, d2));
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}