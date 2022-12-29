/* 쇠막대기 */
/* 22:05 ~ 22:47 */
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	int ans=0, flag;
	cin >> s;
	stack<pair<char,int>> st;
	for (int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			flag = 1;//레이저가 나오는 부분인지 아닌지를 판별하기위해
			st.push({'(',st.size()});
		}
		else//
		{
			st.pop();
			if(flag && st.size())
			{
				ans += st.top().second+1;//곂쳐있는 판수만큼 +
				flag = 0;
			}
			else if(!flag) ans++;// 레이저로 끝난게아니라 판이 끝난거일때
		}
	}
	cout << ans << "\n";
}