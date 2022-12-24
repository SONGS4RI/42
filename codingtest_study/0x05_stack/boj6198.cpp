/* 탑 */
/* 12:42 ~ 13:08*/
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, num;
	long long ans=0;//롱롱 주의해야함
	stack<int> st;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		while(st.size() && st.top()<=num)
		{
			st.pop();
			ans+=st.size();
		}
		st.push(num);
	}
	if(st.size()) ans += ((st.size()-1)*st.size())/2;// 1~n-1까지의 합(내림차순으로 남기때문에)
	cout << ans << "\n";
}