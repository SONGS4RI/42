#include <iostream>
using namespace std;

int n,idx_del,vote_max,num;
int vote=0,idx=1;
pair<int,int> student[101]; // first가 득표수 seconed가 등록순서

int student_del(void)//가장 득표수가 적고 오래된 인덱스를 탐색
{
	int tmp,vote_min=1001;

	for(int i=1;i<=100;i++)
	{
		if(student[i].first)
		{
			if(vote_min > student[i].first)
			{
				vote_min = student[i].first;
				tmp = i;
			}
			else if(vote_min == student[i].first)
			{
				tmp = student[tmp].second > student[i].second ? i : tmp;
			}
		}
	}
	return (tmp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> vote_max;
	while(vote_max--)
	{
		cin >> num;
		if(n)// 액자가 존재할떄
		{
			if(!student[num].first)//새로운 후보
			{
				n--;
				student[num].second = idx++;			
			}
			student[num].first++;
		}
		else// 액자가 꽉차면 새로운 후보가 들어오면 항상 갱신해주어야 한다.
		{
			if(!student[num].first)
			{
				idx_del = student_del();
				student[idx_del].first = 0;
				student[idx_del].second = 0;
				student[num].second = idx++;				
			}
			student[num].first++;
		}
	}
	for(int i=1;i<=100;i++)
		if(student[i].first!=0) cout << i << " ";
}