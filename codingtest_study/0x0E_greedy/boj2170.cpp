/* 선 긋기 */
/* 14:19 ~ 14:55 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, x, y; cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end());
	int end=v[0].second, ans = end - v[0].first;
	for(int i=1;i<n;i++)
	{
		if(v[i].second <= end) continue;
		else if(v[i].first <= end)
		{
			ans += v[i].second - end;
			end = v[i].second;
		}
		else
		{
			ans += v[i].second - v[i].first;
			end = v[i].second;
		}
	}
	cout << ans << "\n";
}
