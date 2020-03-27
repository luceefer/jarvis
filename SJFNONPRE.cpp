#include<bits/stdc++.h>
using namespace std;

float findw(int b[],int a[],int w[],int n)
{
	int i,j,complete=0,rt[n],time=0,min=INT_MAX,index;
	float s=0;
	for(i=0;i<n;i++)
		rt[i] = b[i];
	while(complete!=n)
	{
		for(i=0;i<n;i++)
			if(a[i]<=time && rt[i]<min && rt[i]!=0)
				{	min=rt[i]; index=i;	}
		time++;
		rt[index]--;
		if(rt[index]==0){
			complete++;
			min=INT_MAX;
			w[index] = time - b[index]-a[index];
			if(w[index]<0)	w[index]=0;
			s += w[index];
		}
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
	cout<<"Enter the number of process.\n";
	cin>>n;
	int b[n],a[n],p[n],w[n],tt[n];
	cout<<"Enter the burst time for each process\n";
	for(i=0;i<n;i++){
		cin>>b[i];
		p[i]=i+1;
	}
	printf("Enter the arrival times of the processes.\n");
	for(i=0;i<n;i++)
		cin>>a[i];
	avgw=findw(b,a,w,n);
	avgtt=findavgtt(w,b,n,tt);
	cout<<"Process\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time"<<endl;
	for(i=0;i<n;i++)
		cout<<"P"<<p[i]<<"\t\t"<<b[i]<<"\t\t"<<a[i]<<"\t\t"<<w[i]<<"\t\t"<<tt[i]<<endl;
	cout<<"\nAverage Waiting Time: "<<avgw<<"ms\nAverage Turnaround Time: "<<avgtt<<"ms\n\nGantt Chart:\n";
}
