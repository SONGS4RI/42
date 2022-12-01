/*선분 위의 점*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, start, end;
	cin >> N >> M;
    vector<int> v;//자동으로 메모리가 할당되는 배열 이라고 생각하면 된다.
    for(int i=0; i<N; i++)
	{
        int inp;
		cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<M; i++)
	{
		cin >> start >> end;
        int first = lower_bound(v.begin(), v.end(), start) - v.begin();//start와 같거나 처음으로 큰수
        int second = upper_bound(v.begin(), v.end(), end) - v.begin();//end보다 처음으로 작은수
        cout<<second - first<<'\n';
    }
}