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
		if(st.size() && st.top().first < num)
			while(st.size() && st.top().first<num) st.pop();
		if(st.size() && st.top().first >= num)
			arr[i] = st.top().second+1;
		st.push(make_pair(num,i));
	}
	for(int i=0;i<n;i++) cout << arr[i]<< " ";
}