#include <bits/stdc++.h> // ���� ��� (���̾��� ����� ���� �����ϰ��ִ�)
using namespace std; // (std Ŭ������ Ư���Լ����� ����ϰڴٴ� �ǹ�)
                     // ���� �̷��� ���������� std �Լ����� ����Ҷ� 
int main()           // ���� ���� ������ (::)�� ������־����
{                    // ex) std::cout
    int n, i;
    string s1,res;

    cin >> n;
    cin >> res;
    while(--n)
    {
        i = 0;
        cin >> s1;
        while(s1[i])
        {
            if(res[i] != s1[i])
                res[i] = '?';
            i++;
        }
    }
    cout << res << "\n";
    
}