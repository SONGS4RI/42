/* 스택 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, num;
	stack<int> st;
	string s;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		if(s == "push")
		{
			cin >> num;
			st.push(num);
		}
		else if(s == "pop")
		{
			if(!st.empty())
			{
				cout << st.top() << "\n";
				st.pop();
			}
			else cout << "-1\n";
		}
		else if(s == "size") cout << st.size() << "\n";
		else if(s == "empty") cout << st.empty() << "\n";
		else if(s == "top")
		{
			if(!st.empty()) cout << st.top() << "\n";
			else cout << "-1\n";
		}
	}
}