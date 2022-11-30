#include <iostream>
<<<<<<< HEAD
=======
#include <algorithm>
#include <vector>
#include <string>
>>>>>>> 996a9c1afdea52f105efdfd1ba000f72264539de
using namespace std;
vector<int> v;
int n;

int find(int num) {
	int s = 0, e = n - 1;
	
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == num) return 1;
		
		if (v[mid] < num) {
			s = mid + 1;
		}
		else e = mid - 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	//int m; cin >> m;
	//for (int i = 0; i < m; i++) {
	//	int a; cin >> a;
	//	auto it = find(v.begin(), v.end(), a);
	//	if (it == v.end()) cout << 0 << "\n";
	//	else cout << 1 << "\n"; //it - v.begin()
	//}
	//시간초과

	sort(v.begin(), v.end());
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		cout << find(a) << "\n";
	}
}