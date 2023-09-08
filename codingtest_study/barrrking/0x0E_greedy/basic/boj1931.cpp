/* 회의실 배정 */
/* 14:41 ~  */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,res=1;
	pair<int,int> tmp;
	vector<pair<int,int>> v;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> tmp.second >> tmp.first; // 시작 끝시간을 바꿔서 넣어줬다
		v.push_back(tmp);
	}
	sort(v.begin(),v.end()); // 끝나는 시간을 기점으로 정렬
	int i=0, end;
	end = v[0].first; // 가장 처음 빨리 끝나는 회의
	for(i=1;i<n;i++)
	{
		if(v[i].second >= end) // 시작시간이 끝나는 시간보다 크거나 같다면
		{
			res++;
			end = v[i].first; // 이전 회의 끝난 시간 갱신
		}
	}
	cout << res << "\n";
}
