/* 큐 */
/* 13:42 ~  14:05*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, num;
	string s;
	cin >> n;
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		if(s == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if(s == "pop" && q.size())
		{
			cout << q.front() << "\n";
			q.pop();
		}
		else if(s == "size") cout << q.size() << "\n";
		else if(s == "empty") cout << q.empty() << "\n";
		else if(s == "front" && q.size()) cout << q.front() << "\n";
		else if(s == "back" && q.size()) cout << q.back() << "\n";
		else cout << -1 << "\n";
	}
}