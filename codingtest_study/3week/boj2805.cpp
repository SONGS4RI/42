/*나무 자르기*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long n, m, res = -1;
    long long start, end, mid, sum;
	vector<long long> v;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
	{
		cin >> sum;
		v.push_back(sum);
	}
    sort(v.begin(),v.end());
    start = 0;
    end = v[n - 1];

    while(start <= end){
        sum = 0;
        mid = (start + end) / 2;
		int idx = lower_bound(v.begin(),v.end(),mid)-v.begin();
        for(int i = idx ; i < n ; i++)
            if(v[i] - mid > 0) sum += v[i] - mid; //자른 나무 길이
        if(sum >= m)
		{
            start = mid + 1;
            if(mid > res) res = mid;
        }
        else end = mid - 1;
    }

    cout << res;

    return 0;
}