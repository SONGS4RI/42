/* 좋은 단어 */
/* 21:12 ~  21:28*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	int n,ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		stack<char> st;
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j] == 'A')
			{
				if(st.empty() || st.top()=='B') st.push('A');
				else if(st.top()=='A') st.pop();
			}
			else
			{
				if(st.empty() || st.top()=='A') st.push('B');
				else if(st.top()=='B') st.pop();
			}
		}
		if(st.empty()) ans++;
	}
	cout << ans << "\n";
}