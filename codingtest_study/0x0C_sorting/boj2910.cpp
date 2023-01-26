/* 빈도 정렬 */
/* 13:16 ~ 13:45 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int compare(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
	if(a.second.first != b.second.first) // 개수가 다르다면 개수가 많은 수가 먼저
		return (a.second.first>b.second.first);
	return (a.second.second < b.second.second); // 먼저들어온 인덱스 순으로
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,c,num;
	map<int,pair<int,int>> m; // m.first : 수, m.second.first : 수의 개수, m.second.second : 수의 첫등장 인덱스
	vector<pair<int,pair<int,int>> > v;
	cin >> n >> c;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		if(m.find(num)==m.end()) m[num].second = i; // 처음 map에 넣을때만 그때의 인덱스 저장
		m[num].first++; // 개수++
	}
	for(auto c : m) v.push_back(make_pair(c.first, c.second)); // 벡터에 복사
	sort(v.begin(),v.end(),compare);
	for(auto c : v)
		for(int i=0;i<c.second.first;i++) cout << c.first << " ";
}