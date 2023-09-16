#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, answer_max = INT32_MIN, answer_min = INT32_MAX;
	cin >> n;
	vector<int> nums(n), oper(4);

	for (int i=0; i<n; i++) {
		cin >> nums[i];
	}
	for (int i=0; i<4; i++) {
		cin >> oper[i];
	}
	string opers = "";
	for (int i=0; i<4; i++) {
		for (int j=0; j<oper[i]; j++) {
			opers += i + '0';
		}
	}
	do {
		int res = nums[0];
		for (int i=0; i<n-1; i++) {
			if (opers[i] == '0') {
				res += nums[i+1];
			} else if (opers[i] == '1') {
				res -= nums[i+1];
			} else if (opers[i] == '2') {
				res *= nums[i+1];
			} else {
				res /= nums[i+1];
			}
		}
		answer_max = max(answer_max, res);
		answer_min = min(answer_min, res);
	} while (next_permutation(opers.begin(), opers.end()));
	cout << answer_max << "\n";
	cout << answer_min << "\n";
}