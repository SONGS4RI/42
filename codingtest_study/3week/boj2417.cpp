#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long res = (long long)ceil(sqrt(n));
    cout << res;
}