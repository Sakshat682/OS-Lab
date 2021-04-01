#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
struct process{
    int id;
    int atm;
    int bt;
    int ct;
    int tat;
    int wt;
    int st;
    int rt;
    int priority;
};
struct compare{
    bool operator()(process const& p1, process const& p2)
    {
        if(p1.atm != p2.atm){
        return p1.atm > p2.atm;}
        else{
            return p1.id>p2.id;
        }
    }
};
struct compareID{
    bool operator()(process const& p1, process const& p2)
    {
        return p1.id>p2.id;
    }
};


int main()
{
    int n;
    cout<<"Enter the number of process : ";
    cin>>n;
    process pr[n];
    int p[n];
    int pa[n];
    int pb[n];
    int pri[n];
    cout<<"Enter the arrival time of all processes : ";
    for(int i=0;i<n;i++)
    {
        cin>>pa[i];
        p[i]=i+1;
        pr[i].atm=pa[i];
        pr[i].id=p[i];
    }
    cout<<"Enter the burst time of all processes : ";
    for(int i=0;i<n;i++)
    {
        cin>>pb[i];
        pr[i].bt=pb[i];
    }
    cout<<"Enter the priority of all process : ";
    for(int i=0;i<n;i++)
    {
        cin>>pri[i];
        pr[i].priority=pri[i];
    }
    priority_queue<process,vector<process>,compare>Q;
    for(int i=0;i<n;i++)
    {
        Q.push(pr[i]);
    }
    int i=0;
    while(!Q.empty())
    {
        pr[i]=Q.top();
        Q.pop();
        i++;
    }
    for(int i=0;i<n;i++)
    {
        pb[i]=pr[i].bt;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        c+=pr[i].bt;
    }
    int done[n]={0};
    int cp=pr[0].atm;
    for(int i=0;i<n;i++)
    {
        pr[i].ct=pr[0].atm;
    }
    while(c--)
    {
        int m=0;
        int flag;
        for(int i=0;i<n;i++)
        {
            if(pr[i].atm<=cp&&pr[i].priority>m&&done[i]==0)
            {
                m=pr[i].priority;
                flag=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(done[i]==0)
            {
                pr[i].ct+=1;
            }
        }
        if(pr[flag].bt==pb[flag])
        {
             pr[flag].st=cp;
        }
        cp+=1;
        pr[flag].bt-=1;
        if(pr[flag].bt==0)
        {
            done[flag]=1;
        }
        if(done[flag]==1)
        {
            pr[flag].tat=pr[flag].ct-pr[flag].atm;
            pr[flag].wt=pr[flag].tat-pb[flag];
            pr[flag].rt=pr[flag].st-pr[flag].atm;
        }
    }
    for(int i=0;i<n;i++)
    {
        pr[i].bt=pb[i];
    }
    priority_queue<process,vector<process>,compareID>Q1;
    for(int i=0;i<n;i++)
    {
        Q1.push(pr[i]);
    }
    int j=0;
    while(!Q1.empty())
    {
        pr[j]=Q1.top();
        Q1.pop();
        j++;
    }
    cout<<"P_No\t"<<"AT\t"<<"BT\t"<<"Pr\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<pr[i].id<<"\t"<<pr[i].atm<<"\t"<<pr[i].bt<<"\t"<<pr[i].priority<<"\t"<<pr[i].ct<<"\t"<<pr[i].tat<<"\t"<<pr[i].wt<<"\t"<<pr[i].rt<<endl;
    }
    cout<<endl;
    float avg_tat=0;
    float avg_wt=0;
    float avg_rt=0;
    for(int i=0;i<n;i++)
    {
        avg_tat+=pr[i].tat;
        avg_wt+=pr[i].wt;
        avg_rt+=pr[i].rt;
    }
    avg_tat/=n;
    avg_wt/=n;
    avg_rt/=n;
    cout<<fixed<<setprecision(2)<<"Average turn Around Time is : "<<avg_tat<<endl;
    cout<<"Average Waiting Time is : "<<avg_wt<<endl;
    cout<<"Average Response Time is : "<<avg_rt<<endl;
    return 0;
}
