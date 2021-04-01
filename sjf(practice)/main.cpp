#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int p[n];
    int pa[n];
    int pb[n];
    cout<<"Enter the arrival time: ";
    for(int i=0;i<n;i++)
    {
        cin>>pa[i];
        p[i]=i+1;
    }
    cout<<"Enter the burst time : ";
    for(int i=0;i<n;i++)
    {
        cin>>pb[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(pa[i]>pa[j])
            {
                pa[i]=pa[i]+pa[j];
                pa[j]=pa[i]-pa[j];
                pa[i]=pa[i]-pa[j];

                p[i]=p[i]+p[j];
                p[j]=p[i]-p[j];
                p[i]=p[i]-p[j];

                pb[i]=pb[i]+pb[j];
                pb[j]=pb[i]-pb[j];
                pb[i]=pb[i]-pb[j];
            }
        }
    }
    int pct[n],done[n]={0};
    int ct=pa[0];
    int ptat[n]={0},pwt[n]={0};
    int complete=0;
    while(complete!=n)
    {
        int m=10000;
        int flag;
        for(int i=0;i<n;i++)
        {
            if(pa[i]<=ct&&pb[i]<m&&done[i]==0)
            {
                m=pb[i];
                flag=i;
            }
        }
        ct+=m;
        pct[flag]=ct;
        ptat[flag]=pct[flag]-pa[flag];
        pwt[flag]=ptat[flag]-pb[flag];
        done[flag]=1;
        complete++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(p[i]>p[j])
            {
                pa[i]=pa[i]+pa[j];
                pa[j]=pa[i]-pa[j];
                pa[i]=pa[i]-pa[j];

                p[i]=p[i]+p[j];
                p[j]=p[i]-p[j];
                p[i]=p[i]-p[j];

                pb[i]=pb[i]+pb[j];
                pb[j]=pb[i]-pb[j];
                pb[i]=pb[i]-pb[j];

                ptat[i]=ptat[i]+ptat[j];
                ptat[j]=ptat[i]-ptat[j];
                ptat[i]=ptat[i]-ptat[j];

                pwt[i]=pwt[i]+pwt[j];
                pwt[j]=pwt[i]-pwt[j];
                pwt[i]=pwt[i]-pwt[j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<"\t"<<pa[i]<<"\t"<<pb[i]<<"\t"<<ptat[i]<<"\t"<<pwt[i]<<endl;
    }
    return 0;
}
