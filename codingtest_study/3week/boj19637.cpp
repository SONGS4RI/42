#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m, num;
	string s;
	cin >> n >> m;

	map<int, string>arr;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> num;
		arr.insert(pair<int, string>(num, s));
	}
	map<int, string>::iterator iter;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		iter = arr.lower_bound(num);//num보다 크거나 같은 첫번째 iter를 반환해준다.
		cout << iter->second << "\n";
	}
	return 0;
}