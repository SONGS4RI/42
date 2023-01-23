/* 카드 */
/* 14:14 ~ 15:22(x) */
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

long long compare(pair<long long, int> a, pair<long long, int> b)
{
	if(a.second == b.second) return (a.first < b.first); // 같을때는 사전순
	return (a.second>b.second); // 내림차순
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long n, num;
	map<long long, int> m; // map자료형은 key값과 value를 기본으로 받으며 기본적으로 key를 기준으로 정렬한다.
	vector<pair<long long, int>> v;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		m[num]++;
	}
	for(auto c : m) v.push_back({c.first, c.second});
	sort(v.begin(), v.end(), compare); // compare함수를 사용하여 정렬하기위해 vector로 옮겨준다.
	cout << v[0].first << "\n";
}