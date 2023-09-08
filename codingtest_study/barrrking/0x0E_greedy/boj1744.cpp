/* 수 묶기 */
/* 14:13 ~  15:20 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int a, int b)
{
    return a>b;
}

void func(vector<int> v, int *ans)
{
    int tmp;
    for(int i=0;i<v.size();i++)
    {
        if(i%2==0) tmp = v[i]; // tmp에 넣어둔다
        /* 곱해줘야하는 수가 1이거나 tmp이 1이면 (양수일때 예외처리  ex 1 1이면 2가나와야함)*/
        else if(tmp == 1 || v[i]==1) *ans += tmp+v[i];
        else *ans += tmp*v[i]; // 곱해서 더해준다.
        if(i%2==0 && i==v.size()-1) *ans += tmp; // 자투리면 그냥 더해준다.
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n,ans; cin >> n;
    vector<int> v_minus,v_plus;
    for(int i=0;i<n;i++)
    {
        cin >> ans;
        if (ans<=0) v_minus.push_back(ans); // 음수거나 0이면
        else v_plus.push_back(ans); // 양수이면
    }
    sort(v_minus.begin(),v_minus.end()); // 오름차순 정렬
    sort(v_plus.begin(),v_plus.end(),compare); // 내림차순정렬
    ans = 0;
    func(v_minus, &ans);
    func(v_plus, &ans);
    cout << ans << "\n";
}