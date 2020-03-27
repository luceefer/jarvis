#include<bits/stdc++.h>
using namespace std;

float findw(int b[],int q,int w[],int n)
{
	int i,j,rt[n],time=0;
	float s=0;
	for(i=0;i<n;i++) rt[i]=b[i];
	while(1)
	{
		bool done=true;
		for(i=0;i<n;i++)
			if(rt[i]>0){
				done=false;
				if(rt[i]>q){
					time += q;
					rt[i] -= q;
				}
				else{
					time += rt[i];
					rt[i] = 0;
					w[i] = time - b[i];
					s += w[i];
				}
			}
		if(done==true)	break;
	}
	return s/n;
}
float findavgtt(int w[],int b[],int n,int tt[])
{	int i;float s=0;
	for(i=0;i<n;i++){
		tt[i]=b[i]+w[i];
		s+=tt[i];
	}
	return s/n;
}
int main()
{	int n,i,j;
	float avgtt=0,avgw=0;
	cout<<"Enter the number of process: "; cin>>n;
	int b[n],p[n],w[n],tt[n],q;
	cout<<"Enter the burst time for each process\n";
	for(i=0;i<n;i++){
		cin>>b[i];
		p[i]=i+1;
	}
	cout<<"Enter the time Quantum:   "; cin>>q;
	avgw=findw(b,q,w,n);
	avgtt=findavgtt(w,b,n,tt);
	cout<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
	for(i=0;i<n;i++)
		cout<<"P"<<p[i]<<"\t\t"<<b[i]<<"\t\t"<<w[i]<<"\t\t"<<tt[i]<<endl;
	cout<<"\nAverage Waiting Time: "<<avgw<<"ms\nAverage Turnaround Time: "<<avgtt<<"ms\n";
}
