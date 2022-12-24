/* 탑 */
/* 14:37 ~ 15:20, 16:30 ~  16:47*/
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n,num;
	stack< pair<int, int> > st;
	cin >> n;
	int arr[n];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		cin >> num;
		while(st.size() && st.top().first<num) st.pop();// 새로들어온 값이 스택 윗값보다 크다면 이전의 스택값들은 필요가 없다.
		if(st.size() && st.top().first >= num)
			arr[i] = st.top().second+1;// index + 1만큼 넣어준다.
		st.push(make_pair(num,i));
	}
	for(int i=0;i<n;i++) cout << arr[i]<< " ";
}