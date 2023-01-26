/* 국영수 */
/* 14:11 ~  14:21 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

int compare(tuple<string,int,int,int> a, tuple<string,int,int,int> b)
{
	if(get<1>(a) != get<1>(b)) return (get<1>(a) > get<1>(b)); // 국어 점수 내림차순
	if(get<2>(a) != get<2>(b)) return (get<2>(a) < get<2>(b)); // 영어 점수 오름차순
	if(get<3>(a) != get<3>(b)) return (get<3>(a) > get<3>(b)); // 수학 점수 내림차순
	return (get<0>(a) < get<0>(b));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	vector<tuple<string,int,int,int> > v;
	tuple<string,int,int,int> tmp;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> get<0>(tmp) >> get<1>(tmp) >> get<2>(tmp) >> get<3>(tmp); // 이름 , 국, 영, 수 입력받는다.
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),compare);
	for(auto c:v) cout << get<0>(c) << "\n";
}