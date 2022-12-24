/* 오큰수 */
/* 13:22 ~  13:59*/
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, num, idx=0;
	stack<pair<int,int>> st;
	cin >> n;
	int ans[n];
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<n;i++)
	{
		cin >> num;
		while(st.size() && st.top().first < num)
		{
			ans[st.top().second] = num;// top().second는 인덱스를 의미
			st.pop();
		}
		st.push({num,i});
	}
	for(int i=0;i<n;i++) cout << ans[i] << " ";
}