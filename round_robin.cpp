#include<bits/stdc++.h>
using namespace std;
int main(){

int n, quantum_time;
cin>>n;
int ariv[n], burst[n], burst_temp[n], cpu_ft[n]={0}, coml[n];
int vis[n]={0};
for(int i=0; i<n;i++){
cin>>ariv[i];
}
for(int i=0;i<n;i++){
cin>>burst[i];
burst_temp[i]=burst[i];
}
cin>>quantum_time;
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

int ttat=0,twat=0;

for(int i=0;i<n;i++){
cout<<"Process "<<i<<":\n";
cout<<"Completetion time :"<<coml[i]<<"\n";
cout<<"Turn Around time :"<<coml[i] - ariv[i]<<"\n";
cout<<"Waiting Time :"<<coml[i] - ariv[i]- burst[i]<<"\n";
cout<<"Response Time:"<<cpu_ft[i]-ariv[i]<<"\n\n";
ttat+=coml[i] - ariv[i];
twat+=coml[i] - ariv[i] -burst[i];
}
float awat = (float)twat/(float)n;
float atat = (float)ttat/(float)n;

cout<<"Average Turn Around Time:"<<atat<<"\n";
cout<<"Average Weighting Time: "<<awat<<"\n";
return 0;
}
