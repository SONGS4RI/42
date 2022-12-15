/* 제로 */
/* 14:11 ~ 14:18 */
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int k,num;
	stack<int> st;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		cin >> num;
		if(num) st.push(num);
		else st.pop();
	}
	num = 0;
	while(!st.empty())
	{
		num += st.top();
		st.pop();
	}
	cout << num << "\n";
}