/* 공주님의 정원 */
/* 12:52 ~ */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		int ms,ds,me,de;
		cin >> ms >> ds >> me >> de;
		v.push_back(make_pair(ms*100+ds,me*100+de));
	}
	sort(v.begin(), v.end());
	int t = 301,res=0,idx=0;
	while (t<1201)
	{
		int nxt_t = t;
		for(int i=idx;i<n;i++)
		{
			if(v[i].first <= t && v[i].second > nxt_t) // 꽃이 피는 시간이 기준시간(이전에 피었던꽃 지는시간 t)보다 작거나 같고,
			{										   // 꽃이 지는 시간이 기준시간 또는 바꾸려는 시간(nxt_t) 보다 클때
				nxt_t = v[i].second;
				idx = i;
			}
			else if(v[i].first > t) break; // 꽃이 피는 시간이 지는 시간보다 늦게있을때
		}
		if (nxt_t == t) // 연결되지않는다면
		{
			cout << 0 << "\n";
			return 0;
		}
		t = nxt_t;
		res++;
	}
	cout << res << "\n";
}