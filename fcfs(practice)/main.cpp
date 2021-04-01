#include <iostream>
#include <queue>
using namespace std;
struct process{
    int id;
    int atm;
    int bt;
    int ct;
    int tat;
    int wt;
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
    cin>>n;
    process pr[n];
    int p[n];
    int pa[n];
    int pb[n];
    cout<<"Enter the arrival time: ";
    for(int i=0;i<n;i++)
    {
        cin>>pa[i];
        p[i]=i+1;
        pr[i].atm=pa[i];
        pr[i].id=p[i];
    }
    cout<<"Enter the burst time : ";
    for(int i=0;i<n;i++)
    {
        cin>>pb[i];
        pr[i].bt=pb[i];
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
    int c=pr[0].atm;
    for(int i=0;i<n;i++)
    {
        c+=pr[i].bt;
        pr[i].ct=c;
        pr[i].tat=pr[i].ct-pr[i].atm;
        pr[i].wt=pr[i].tat-pr[i].bt;
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
    for(int i=0;i<n;i++)
    {
        cout<<pr[i].id<<"\t"<<pr[i].atm<<"\t"<<pr[i].bt<<"\t"<<pr[i].ct<<"\t"<<pr[i].tat<<"\t"<<pr[i].wt<<endl;
    }
    return 0;
}
