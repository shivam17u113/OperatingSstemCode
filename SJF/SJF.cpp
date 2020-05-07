#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool SORT_arriaval(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
{
    return a.second.first <b.second.first ;
}


bool SORT_brust(pair<int,int>&a,pair<int,int>&b)
{
    return a.second <b.second ;
}

bool SORT_PID(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
{
    return a.first <b.first ;
}

int main()
{

int n,AT,BT,PID,avg_wt=0;


cout<<"enter no of processes "<<endl;
cin>>n;

vector<pair<int,pair<int,int>>>v;
vector<pair<int,int>> s_b;

int completion_time[n]={0};
int remain_time=0;

for(int i=0;i<n;i++)
{
    cout<<"Enter AT and BT"<<endl;
    cin>>AT;
    cin>>BT;
remain_time+=BT;

v.push_back(make_pair(i,(make_pair(AT,BT))));
}

sort(v.begin(),v.end(),SORT_arriaval);

int first=v[0].second.first;
int last_inserted=0;

for(int i=0;i<v.size();i++)
{
    if(v[i].second.first <=first)
    {
        s_b.push_back(make_pair(v[i].first , v[i].second.second));
        last_inserted++;
    }
    else
    {
        break;
    }
}
sort(s_b.begin(),s_b.end(),SORT_brust);

for(int i=0;i<v.size();i++)
{
    cout<<v[i].first<<"\t"<<v[i].second.first<<"\t"<<v[i].second.second<<endl;
}

int completed_time=0;
while(remain_time)
{
sort(s_b.begin(),s_b.end(),SORT_brust);
PID= s_b[0].first;
BT=s_b[0].second;

s_b.erase(s_b.begin());
completed_time+=BT;
remain_time-=BT;
cout<<"completed time "<<completed_time<<" for  id "<<PID<<endl;

completion_time[PID]=completed_time;

for(int i= last_inserted ;i<v.size();i++)
{
    if(v[i].second.first<=completed_time)
    {
        s_b.push_back(make_pair(v[i].first , v[i].second.second));
        last_inserted++;
    }
}

}
cout<<endl;
sort(v.begin(),v.end(),SORT_PID);

int TT[n];
int WT[n];


for(int i=0;i<v.size();i++)
{
     PID= v[i].first;
     BT= v[i].second.second;
     AT= v[i].second.first;

     TT[PID]=  completion_time[PID]- AT;
     WT[PID]= TT[PID]-BT;
}

cout<<"PID \t AT \t BT \t CT \t TT \t WT"<<endl;

for(int i=0;i<v.size();i++)
{
      PID= v[i].first;
     BT= v[i].second.second;
     AT= v[i].second.first;

    cout<<PID<<" \t "<<AT<<" \t "<<BT
    <<" \t "<<completion_time[PID]<<" \t "<<TT[PID]<<" \t "<<WT[PID]<<endl;
}



    return 0;
}
