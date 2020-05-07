#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool SORT_FUN(pair<int,int>&a,pair<int,int>&b)
{
    return a.first <b.first ;
}

int main()
{

int n,AT,BT,avg_wt=0;


cout<<"enter no of processes "<<endl;
cin>>n;

int CT[n];
int TT[n];
int WT[n];
vector<pair<int,int>>v;

for(int i=0;i<n;i++)
{
    cout<<"Enter AT and BT"<<endl;
    cin>>AT;
    cin>>BT;

    v.push_back(make_pair(AT,BT));
}

sort(v.begin(),v.end(),SORT_FUN);

for(int i=0;i<v.size();i++)
{
    cout<<v[i].first<<"   ";
    cout<<v[i].second;
    cout<<endl;
}

int total_time=0;

CT[0]=v[0].second;
total_time =v[0].second;
TT[0]=CT[0]-v[0].first;
WT[0] =CT[0]-v[0].second;
avg_wt=avg_wt+WT[0];

for(int i=1;i<v.size();i++)
{
if(v[i].first <total_time)
{
    CT[i] =total_time+v[i].second;
    TT[i]=CT[i]-v[i].first;
    WT[i] =TT[i]-v[i].second;

    total_time=total_time+v[i].second;
    avg_wt=avg_wt+WT[i];


}
else
{

        CT[i] =v[i].first+v[i].second;
        TT[i]=CT[i]-v[i].first;
        WT[i] =TT[i]-v[i].second;

    total_time=total_time+(v[i].first-total_time);
        avg_wt=avg_wt+WT[i];


}

}
cout<<"AT    "<<"BT    "<<"CT    "<<"TT    "<<"WT    "<<endl;

cout<<endl;
for(int i=0;i<v.size();i++)
{
    cout<<v[i].first<<"     ";
    cout<<v[i].second<<"    ";
    cout<<CT[i]<<"     ";
    cout<<TT[i]<<"    ";
    cout<<WT[i]<<"     ";
    cout<<endl;
}
cout<<endl;
cout<<"Avarage Waiting time is "<<avg_wt/n<<endl;

    return 0;
}
