#include<bits/stdc++.h>
using namespace std;
float fcfs_wt[10]={0}, fcfs_tat[10]={0},fcfs_awt=0,fcfs_atat=0;
float rr_wt[10]={0}, rr_tat[10]={0}, rr_awt=0, rr_atat=0;
float sjf_wt[10]={0}, sjf_tat[10]={0}, sjf_awt=0, sjf_atat=0;
float srtf_wt[10]={0}, srtf_tat[10]={0}, srtf_awt=0, srtf_atat=0;
struct process{
    int at;
    int id;
};
struct Comparetime {
    bool operator()(process const& p1, process const& p2)
    {
        if(p1.at != p2.at){
        return p1.at > p2.at;}
        else{
            return p1.id>p2.id;
        }
    }
};

void fcfs_compute(process p[], int bt[]){
    int ct=0;
    for(int i=0;i<10;i++){
        if(p[i].at<=ct){
            ct= ct + bt[p[i].id];
            fcfs_tat[p[i].id] = ct - p[i].at;
            fcfs_wt[p[i].id] = fcfs_tat[p[i].id] - bt[p[i].id];
        }
    }
}
void sjf_compute(process p[], int bt[]){

    int left = 10, ct=0;
    int vis[10]={0};
for(;left>0;){
    int min=10000;
    int flag;
    for(int i=0;i<10;i++){
        if(p[i].at <=ct && bt[p[i].id]<min && vis[p[i].id]==0){
            min = bt[p[i].id];
            flag=i;
        }
    }
    ct+=min;
    sjf_tat[p[flag].id]= ct - p[flag].at;
    sjf_wt[p[flag].id]=sjf_tat[p[flag].id] - bt[p[flag].id];
    vis[p[flag].id] = 1;
    left--;

}


}
void srtf_compute(process p[], int bt[]){
    int bt_temp[10];
    for(int i=0;i<10;i++){
        bt_temp[i]=bt[i];

    }
    int n=10;
    int left =10;
    int flag;
    int MAX_INT=1000000, ct=0;
    for(;left>0;){
    int temp = MAX_INT;

	for(int i=0;i<n;i++){
		if(bt_temp[p[i].id]>0 && ct>=p[i].at && bt_temp[p[i].id]<temp )
			{
                flag = i;
			    temp=bt_temp[p[i].id];
			}
	}
    ct++;
	bt_temp[p[flag].id]-=1;
	if(bt_temp[p[flag].id]==0){
		left=left-1;
        srtf_tat[p[flag].id]= ct - p[flag].at;
        srtf_wt[p[flag].id] = srtf_tat[p[flag].id] - bt[p[flag].id];
	}

}
}
void rr_compute(process p[], int bt[], int tq){

    int n=10, quantum_time;
int ariv[n], burst[n], burst_temp[n], cpu_ft[n]={0}, coml[n];
int vis[n]={0};
for(int i=0; i<n;i++){
ariv[p[i].id]=p[i].at;
}
for(int i=0;i<n;i++){
burst[i]= bt[i];
burst_temp[i]=burst[i];
}
quantum_time=tq;
queue <int>q;
q.push(0);
int l=1, left=n, ct=0;

while(left!=0){
int temp = q.front();
q.pop();
if(ariv[temp]<=ct){

  if(vis[temp]==0){cpu_ft[temp] = ct;vis[temp]=1;}

  if(burst_temp[temp]<=quantum_time){
	ct+= burst_temp[temp];
	coml[temp]=ct;
	left -=1;
	while(l<n){
		if(ct>=ariv[l]){
		q.push(l);
		l++;
		}else{break;}
	}
   }else{
	 ct+=quantum_time;
	 burst_temp[temp]-=quantum_time;
	 while(l<n){
		if(ct>=ariv[l]){
		q.push(l);
		l++;
		}else{break;}
	 }
	 q.push(temp);
 }

}else{
ct++;
}

}
for(int i=0;i<10;i++){
    rr_tat[i]=coml[i] - ariv[i];
    rr_wt[i]=coml[i] - ariv[i]- burst[i];
}



}

int main(){
process p[10];
int bt[]={10,12,8,11,3,15,16,12,7,5},tq;
int at[]={0,2,3,1,4,3,2,6,8,9};
priority_queue<process, vector<process>, Comparetime> Q;
for(int i=0;i<10;i++){
    p[i].at= at[i];
    p[i].id=i;
}

// for(int i=0;i<10;i++){
//     cin>>bt[i];
// }
// cin>>tq;
tq=2;

for (int i = 0; i <10; ++i) {
Q.push(p[i]);
}
for(int i=0;i<10;i++){
    p[i]=Q.top();
    Q.pop();
}
fcfs_compute(p,bt);
sjf_compute(p,bt);
srtf_compute(p,bt);
rr_compute(p,bt, tq);

cout<<"Process ID:"<<"\t FCFS_WT"<<"\t FCFS_TAT"<<"\t SJF_WT"<<"\t SJF_TAT"<<"\t RR_WT"<<"\t RR_TAT"<<"\t SRTF_WT"<<"\t SRTF_TAT\n";
for(int i=0;i<10;i++){
    cout<<i+1<<"\t\t"<<fcfs_wt[i]<<"\t"<<fcfs_tat[i]<<"\t"<<sjf_wt[i]<<"\t"<<sjf_tat[i]<<"\t"<<rr_wt[i]<<"\t"<<rr_tat[i]<<"\t"<<srtf_wt[i]<<"\t"<<srtf_tat[i]<<"\n";
}

float total_wtime[4]={0}, total_atime[4]={0};
for(int i=0;i<10;i++){
    total_wtime[0]+=fcfs_wt[i];
    total_atime[0]+=fcfs_tat[i];
    total_wtime[1]+=sjf_wt[i];
    total_atime[1]+=sjf_tat[i];
    total_wtime[2]+=srtf_wt[i];
    total_atime[2]+=srtf_tat[i];
    total_wtime[3]+=rr_wt[i];
    total_atime[3]+=rr_tat[i];
}
for(int i=0;i<4;i++){
    total_atime[i]=total_atime[i]/10;
    total_wtime[i]= total_wtime[i]/10;
}
fcfs_awt=total_wtime[0];
fcfs_atat=total_atime[0];

sjf_awt =total_wtime[1];
sjf_atat=total_atime[1];

rr_atat=total_atime[3];
rr_awt=total_wtime[3];

srtf_atat = total_atime[2];
srtf_awt = total_wtime[2];


cout<<"FCFS Average Weighting Time:"<<fcfs_awt<<"\t"<<"FCFS Average Turn around time:"<<fcfs_atat<<"\n";
cout<<"SFJ Average Weighting Time:"<<sjf_awt<<"\t"<<"SFJ Average Turn around time:"<<sjf_atat<<"\n";
cout<<"SRTF Average Weighting Time:"<<srtf_awt<<"\t"<<"SRTF Average Turn around time:"<<srtf_atat<<"\n";
cout<<"RR Average Weighting Time:"<<rr_awt<<"\t"<<"RR Average Turn around time:"<<rr_atat<<"\n";
}
