/* 부분수열의 합 */
/* 14:32 ~ 15:32 */
#include <iostream>
#include <vector>
using namespace std;

int n,s,num, ans = 0;
vector<pair<int,int> > v;

void dfs(int sum,int idx)
{
	if(sum == s && idx > 0) ans++; // 문제의 부분!!
	/*
		이 부분에서 조건을 만족한다고 리턴을 해버리면 뒷부분에 원소를 더한값이 조건을 만족하는 경우를 판단할 수 없게된다.
		예시로 5 0 0 0 0 0 0 이 테스트 케이스로 들어오게되었을때 답은 31이나와야하지만 이부분에서 함수를 종료시킨다면
		답은 5 가 나오게된다. 수열의 각 한 원소씩이 조건을 만족하기 때문이다.
	 */
	for(int i=idx;i<n;i++)
	{
		if(!v[i].second)
		{
			v[i].second = 1;
			dfs(sum+v[i].first,i+1); // 중복되어지는 선택을 방지하기 위해 인덱스를 매개변수로 전달한다.
			v[i].second = 0;
		}
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> s;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		v.push_back(make_pair(num,0)); // first = 값, second = 방문 체크용
	}
	dfs(0,0);
	cout << ans << "\n";
}