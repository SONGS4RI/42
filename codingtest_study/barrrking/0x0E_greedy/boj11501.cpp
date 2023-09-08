/* 주식 */
/* 14:24 ~ 14:30 */
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t,n,mx;
	long long res;
    cin >> t;
    while (t--)
    {
		cin >> n;
		int arr[1000000] = {0,};
        mx = 0;
        res = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = n-1; i >= 0; i--) // 거꾸로 탐색하면서
        {
            mx = max(mx, arr[i]); // 최대값 갱신
            res += mx - arr[i]; // 차이값을 더해준다
        }
        cout << res << "\n";
    }
}

/* 주식 */
/* 13:34 ~ 14:24 */
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		vector<int> v;
		int n,num,num_max=0,arr[10001]={0,};
		long long ans = 0;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> num;
			arr[num]++; // 주식 가격별 개수 저장하는 배열
			v.push_back(num);
			num_max = max(num_max, num); // 현재 최대값(가장 가격이 높을때)
		}
		arr[num_max]--;
		for(auto c : v)
		{
			if(c != num_max) // 최대값아니면 값 차이값 더해줌
			{
				ans += num_max-c;
				arr[c]--; // 가격개수--
			}
			else
			{
				for(int i=num_max;i>=1;i--) // 새로운 최대가격 탐색
				{
					if (arr[i])
					{
						arr[i]--;
						num_max = i;
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
}
*/