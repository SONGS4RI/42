/* 멀티탭 스케줄링 */
/* 13:52 ~  */
#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

int a[105]; // 전기용품의 사용 순서
bool power[105]; // 해당 전기용품이 멀티탭에 꽂혀 있는가

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, ans=0, cnt=0; cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	for (int i = 1; i <= k; i++)
	{
		int cur = a[i];
		if (power[cur]) continue;
		if (cnt < n)
		{
			power[cur] = true;
			cnt++;
		}
		else
		{
			vector<pair<int, int> > idx;
			for (int x = 1; x <= k; x++)// 1 2 3 7
			{
				if (!power[x]) continue; // 안꽂혀있으면
				bool vis = false;
				for (int y = i + 1; y <= k; y++) // 뒤에 나올 수들
				{
					if (a[y] == x)
					{
						idx.push_back({y, x});
						vis = true;
						break;
					}
				}
				if (!vis) idx.push_back({k + 1, x}); // a에서 나오지 않으면 k + 1로 처리
			}
			sort(idx.begin(), idx.end(), greater<pair<int, int>>());
			int target = idx[0].Y; // 가장 늦게 사용할 전기용품을 뽑고 cur을 꽂으면 됨
			power[target] = false; ans++;
			power[cur] = true;
		}
	}
	cout << ans;
}