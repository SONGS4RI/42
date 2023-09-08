/* 1,2,3 더하기 */
/* 14:21 ~ 14:30 */
#include <iostream>
using namespace std;

int t,n,cnt,arr[3]={1,2,3};

void dfs(int sum)
{
	if(sum >= n)// 합이 같거나 넘어간다면
	{
		if(sum == n) cnt++;
		return;
	}
	for(int i=0;i<3;i++)
		dfs(sum+arr[i]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> t;
	while(t--)
	{
		cin >> n;
		cnt = 0; // 카운트 초기화
		dfs(0);
		cout << cnt << "\n";
	}
}

/*	다른 풀이
#include<iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int dp[11] = {1,2,4,};
	// 1=>1개, 2=>2개, 3=>4개 점화식 dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
    for(int i=4;i<=10;i++)
        dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
    int t;
    cin >> t;
    while(t--)
	{
        int n;
        cin >>n;
        cout << dp[n]<< "\n";
    }
}

*/