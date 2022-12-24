/* 덱 */
/* 16:09 ~  */
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, num;
	string s;
	deque<int> deq;
	cin >> n;
	while(n--)
	{
		cin >> s;
		if(s == "push_front")
		{
			cin >> num;
			deq.push_front(num);
		}
		else if(s == "push_back")
		{
			cin >> num;
			deq.push_back(num);
		}
		else if(s == "pop_front")
		{
			if(deq.empty()) cout << -1 << "\n";
			else
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}
		else if(s == "pop_back")
		{
			if(deq.empty()) cout << -1 << "\n";
			else
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}
		else if(s == "size") cout << deq.size() << "\n";
		else if(s == "empty") cout << deq.empty() << "\n";
		else if(s == "front")
		{
			if(deq.empty()) cout << -1 << "\n";
			else cout << deq.front() << "\n";
		}
		else if(s == "back")
		{
			if(deq.empty()) cout << -1 << "\n";
			else cout << deq.back() << "\n";
		}
	}
}