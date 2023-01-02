/* 숨바꼭질 */
/* 13:01 ~ 13:20 */
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,k,arr[100001]={0,},nx;
	int dx[2] = {-1,1};
	cin >> n >> k;
	if(n==k)
	{
		cout << "0\n";
		exit(0);
	}
	queue<int> q;
	q.push(n);
	arr[n] = 1;
	while(q.size())
	{
		int tmp = q.front();
		q.pop();
		for(int dir=0;dir<3;dir++)// for(int i : {tmp-1,tmp+1,tmp*2})이런형식으로 쓰면 줄여쓸수있다.
		{
			if(dir!=2) nx = tmp + dx[dir];
			else nx = tmp*2;
			if(nx<0 || nx>100000) continue;
			if(arr[nx]) continue;
			q.push(nx);
			arr[nx] = arr[tmp]+1;
			if(nx==k)
			{
				cout << arr[nx]-1 << "\n";
				exit(0);
			}
		}
	}
}