/* 스택 수열 */
/* 14:25 ~ 14:59 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, idx=1, target=0;
	stack<int> st;
	vector<char> v;//+,-표시용으로 사용
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	while(target<n)
	{
		while(idx <= arr[target])//idx가 숫자 몇까지 넣었는지를 의미, target은 목표배열 인덱스
		{						 //arr[target]이 idx보다 작다는 것은 이미 스택안에 집어넣은 수라는 의미
			v.push_back('+');//주어진 배열 arr[target]과 같을떄까지 집어넣음
			st.push(idx++);
		}
		if(st.top()==arr[target])//스택 맨위가 arr[target]과 같으면 pop하고 target++;
		{
			v.push_back('-');
			st.pop();
			target++;
		}
		else break;//불가능한경우 종료 조건
	}
	if(st.empty())
		for(int i=0;i<v.size();i++) cout << v[i] << "\n";
	else cout << "NO\n";
}