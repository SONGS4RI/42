/* 1로 만들기 */
/* 19:28 ~  20:00 */
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, cur;
	cin >> n;
	queue<int> q;
	q.push(1);
	int dp[n+1] = {0,};
	while(!q.empty()) // bfs방식으로 풀었다!
	{
		cur = q.front(); // 현재인덱스
		q.pop();
		int dx[3] = {cur*3, cur*2, cur+1};
		for(int dir=0;dir<3;dir++)
		{
			if(dx[dir]>n || dp[dx[dir]]) continue; // 범위를 넘어가거나 이미 접근한적 있다면
			if(dx[dir] == n) // 조건을 만족한다면
			{
				cout << dp[cur]+1 << "\n";
				exit(0);
			}
			dp[dx[dir]] = dp[cur]+1;
			q.push(dx[dir]);
		}
	}
	cout << 0 << "\n"; // n = 1일때 예외케이스!!!!
}