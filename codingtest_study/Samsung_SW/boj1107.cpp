#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> button(10, true);
vector<int> answer(3, INT32_MAX);
int n, m;

int moveFromSmaller() {
	int channel = 0, cnt=0;

	while (channel < n) {
		
	}

	return cnt;
}

int moveFromBigger() {
	int channel = 0, cnt=0;

	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int num;
		cin >> num;
		button[num] = false;
	}
	answer[0] = abs(n - 100);// 채널 100 에서 직접 이동
	answer[1] = moveFromSmaller();
	answer[2] = moveFromBigger();

	cout << *min_element(answer.begin(), answer.end()) << "\n";
}
/*
0 1 2 3 4 5 6 7
80000

1. 100에서 직접 79900
2. 근접한데 작은 수 77777 (+2223)
3. 근접한데 큰 수 100000 (-20000)

*/