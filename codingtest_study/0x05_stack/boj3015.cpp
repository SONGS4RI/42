/* 오아시스 재결합 */
/* 13:09 ~  14:44(x)*/
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
    long long ans = 0;
    stack<pair<int,int> > st;
    while(n--){
        int cnt = 1, h;
		cin >> h;
        while(st.size() && st.top().first <= h)
		{
            ans += st.top().second; // h와 마주볼 수 있는 갯수를 더한다.
            if(st.top().first == h) cnt += st.top().second;
            st.pop();
        }
        if(st.size()) ans++;// st이 존재하면 h는 무조건 st.top()과 마주볼수있다.
        st.push(make_pair(h,cnt));// 여기서 바로 전사람이라는건 이전 사람이 중복키이던 아니던 무조건 바로직전키의 사람을 의미
    }
    cout << ans;
}
// 틀린코드
// int main()
// {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	int n,ans=0, num;
// 	stack<pair<int,int> > st;
// 	cin >> n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> num;
// 		int same = 1;
// 		while(st.size() && num >= st.top().first && same)
// 		{
// 			if(num==st.top().first)
// 			{
// 				st.top().second++;
// 				same = 0;
// 			}
// 			else
// 			{
// 				ans+=st.top().second;
// 				st.pop();
// 				ans++;
// 			}
// 			ans+=st.size();
// 		}
// 		if(same) st.push(make_pair(num,0));
// 	}
// 	if(st.size()) ans += ((st.size()-1)*st.size())/2;
// 	cout << ans << "\n";
// }
