#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,pair<int,int>> &a,
              const pair<int,pair<int,int>> &b)
{
    return (a.second.first < b.second.first);
}

bool sortbyPid(const pair<int,pair<int,int>> &a,
              const pair<int,pair<int,int>> &b)
{
    return (a.first < b.first);
}

int main()
{

vector< pair< int, pair< int , int >  >  > v;
vector< pair< int, pair< int , int >  >  > final_ans;

int n,a_t,b_t,execute_time=0,t_q;

cout<<"enter no of processes ";
cin>>n;

for(int i=0;i<n;i++)
{
    cout<<"enter arrival time  and Brust time "<<endl;
    cin>>a_t>>b_t;
    execute_time+=b_t;
    v.push_back(make_pair(i,make_pair(a_t,b_t)));
        final_ans.push_back(make_pair(i,make_pair(a_t,b_t)));


}

cout<<"enter time quantum "<<endl;
cin>>t_q;


sort(v.begin(),v.end(),sortbysec);
sort(final_ans.begin(),final_ans.end(),sortbysec);


int current_index[n]={0};
current_index[0]=INT_MAX;

for(int i=0;i<v.size();i++)
{
     current_index[v[i].first]=i;
}


queue<int> q;
int current_push=0,current_execute=t_q;
int completion_time[n];
completion_time[0]=INT_MAX;
int time_completed=0;


while(execute_time)
{

/// elements which are ready to execute in ready queue
    while(current_push<=n)
    {
      //  cout<<"in while "<<endl;

        if(v[current_push].second.first<=current_execute)
        {
           // cout<<" pushed from while "<<v[current_push].first<<endl;
            q.push(v[current_push].first);
            current_push++;
        }
        else if(v[current_push].second.first>current_execute)
        {
            current_execute=t_q+current_execute;
            break;
        }
    }

    /// pop front element and run on processor
int running= q.front();
    q.pop();

int v_index=current_index[running];

/// BT is less than or equal to TQ
if(v[v_index].second.second <=t_q)
{
   // cout<<" from if "<<endl;
    execute_time=execute_time-v[v_index].second.second;
    time_completed+=v[v_index].second.second;

    /// only if it is not zero then update completion time
    if(v[v_index].second.second!=0)
    completion_time[running]=time_completed;

            v[v_index].second.second=0;
          //  cout<<"execution completed of "<<running<<endl;
}
else
{
    /// IF BT is grt than TQ then again push in queue
  //  cout<<"from else "<<endl;
    for(int i=0;i<t_q;i++)
    {
        v[v_index].second.second--;
        execute_time--;
        time_completed++;
    }
 //   cout<<" pushed remaining again "<<running<<endl;
    q.push(running);
}
//cout<<"completed time "<<time_completed<<endl;

}

cout<<" PID \t AT \t BT \t CT \t TT \t WT "<<endl;

int waiting[n];
int TT[n];


for(int i=0;i<final_ans.size();i++)
{
   TT[final_ans[i].first]= -final_ans[i].second.first + completion_time[final_ans[i].first];
   waiting[final_ans[i].first]= TT[final_ans[i].first]-final_ans[i].second.second;

}


for(int i=0;i<final_ans.size();i++)
{
cout<<final_ans[i].first<<" \t "<<final_ans[i].second.first<<" \t "<<final_ans[i].second.second<<" \t "
<<completion_time[final_ans[i].first]<<" \t "<<TT[final_ans[i].first]<<" \t "<< waiting[final_ans[i].first]<<endl;
}


    return 0;
}

