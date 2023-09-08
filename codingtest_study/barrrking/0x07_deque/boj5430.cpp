/* AC */
/* 21:26 ~  23:13*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t,n,err,num=0;
	string s;
	char trash;
	cin >> t;
	while(t--)
	{
		deque<int> dq;
		cin >> s >> n >> trash;
		if(n>0)
		{
			while(n--)
			{
				cin >> num >> trash;
				dq.push_back(num);
			}
		}
		else cin >> trash;
		n = 0; err = 0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] =='R') n++;
			else if(s[i] == 'D' && dq.size())
			{
				if(n%2==0) dq.pop_front();
				else dq.pop_back();
			}
			else
			{
				cout << "error\n";
				err = 1;
				break;
			}
		}
		if(err) continue;
		cout << '[';
		if(n%2==0 && dq.size())
		{
			for(int i=0;i<dq.size()-1;i++) cout << dq[i] << ",";
			cout << dq[dq.size()-1];
		}
		else if(n%2==1 && dq.size())
		{
			for(int i=dq.size()-1;i>0;i--) cout << dq[i] << ",";
			cout << dq[0];
		}
		cout << "]\n";
	}
}