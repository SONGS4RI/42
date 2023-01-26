/* 나이순 정렬 */
/* 13:50 ~  14:01 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(tuple<int,int,string> a, tuple<int,int,string> b)
{
	if(get<1>(a)!=get<1>(b)) return (get<1>(a) < get<1>(b));
	return (get<0>(a) < get<0>(b));
	/* 생각해보니 굳이 인덱스 순으로는 따로 정리안해줘도 된다. 기본적으로 입력받을때 인덱스 순서이기 때문 */
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	vector<tuple<int,int,string> > v; // 인덱스,나이,이름 순
	tuple<int,int,string> tmp;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> get<1>(tmp) >> get<2>(tmp); // 나이, 이름 저장
		get<0>(tmp) = i; // 인덱스 저장
		v.push_back(tmp);
	}
	sort(v.begin(),v.end(),compare);
	for(auto c:v) cout << get<1>(c) << " " << get<2>(c) << "\n";
}