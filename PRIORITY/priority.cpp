#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool SORT_arriaval(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
{
    return a.second.first <b.second.first ;
}


int main()
{

int n,PRI,BT,PID,avg_wt=0,AT;


cout<<"enter no of processes "<<endl;
cin>>n;

vector<pair<int,pair<int,int>>>v;

int completion_time[n]={0};
int remain_time=0;

for(int i=0;i<n;i++)
{
    cout<<"Enter Priority and BT"<<endl;
    cin>>PRI;
    cin>>BT;
remain_time+=BT;

v.push_back(make_pair(i,(make_pair(PRI,BT))));
}

sort(v.begin(),v.end(),SORT_arriaval);



int completed_time=0;
int i=0;
while(remain_time)
{
PID= v[i].first;
BT=v[i].second.second;

completed_time+=BT;
remain_time-=BT;
cout<<"completed time "<<completed_time<<" for  id "<<PID<<endl;

completion_time[PID]=completed_time;

i++;

}

int TT[n];
int WT[n];


for(int i=0;i<v.size();i++)
{
     PID= v[i].first;
     BT= v[i].second.second;
     AT= 0;

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
