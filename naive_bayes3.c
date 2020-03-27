#include<iostream.h>
using namespace std;

char s[8]={'M','M', 'M','M','F', 'F', 'F', 'F'};
float h[8]={6.01,5.92,5.58,5.92,5.01,5.50,5.42,5.57};
float w[8]={180,190,170,165,100,150,130,150};
float ft[8]={12,11,12,10,6,7,8,9};
float mh[2],vh[2],mw[2],vw[2],mft[2],vft[2];
float th=6;
float tw=130,tft=8;
float pm=0.5,phm,pwm,pftm,pf=0.5,phf,pwf,pftf;
float post[2];

float pdf(float m,float v,float r)
{
      float x,y,z,t;
      x=sqrt(2*3.14*v);
      y=pow((r-m),2);
      z=-(y/(2*v));
      t=pow(2.74,z);
      return t/x;
}

void calc(float m[],float v[],float p[])
{
     float x=0;
     int i;
     for(i=0;i<4;i++)
        x=x+p[i];
       m[0]=x/4;
       x=0;
   for(i=4;i<8;i++)
      x=x+p[i];
      m[1]=x/4;
      x=0;
for(i=0;i<4;i++)
   x=x+((m[0]-p[i]))*(m[0]-p[i]);
   v[0]=x/3;
   x=0;
for(i=4;i<8;i++)
  x=x+((m[1]-p[i])*(m[1]-p[i]));
  v[1]=x/3;
}
using namespace std;
int main()
{
   calc(mh,vh,h);
   calc(mw,vw,w);
   calc(mft,vft,ft);

  phm=pdf(mh[0],vh[0],th);
  pwm=pdf(mw[0],vw[0],tw);
  pftm=pdf(mft[0],vft[0],tft);
  phf=pdf(mh[1],vh[1],th);
  pwf=pdf(mw[1],vw[1],tw);
  pftf=pdf(mft[1],vft[1],tft);

  post[0]=pm*phm*pwm*pftm;
post[1]=pf*phf*pwf*pftf;
cout<<"Sex     Height    Weight   Footsize"<<endl;
for(int i=0;i<8;i++)
cout<<s[i]<<"      "<<h[i]<<"        "<<w[i]<<"        "<<ft[i]<<endl;
cout<<"Sex    Mheight      Vheight     Mweight      Vweight      Mfootsize     Vfootsize"<<endl;
cout<<" M     "<<mh[0]<<"       "<<vh[0]<<"     "<<mw[0]<<"        "<<vw[0]<<"     "<<mft[0]<<"     "<<vft[0]<<endl;
cout<<" F     "<<mh[1]<<"       "<<vh[1]<<"     "<<mw[1]<<"        "<<vw[1]<<"     "<<mft[1]<<"     "<<vft[1]<<endl;
cout<<" Test Case:"<<endl;
cout<<"Height     Weight     Footsize"<<endl;
cout<<th<<"         "<<tw<<"        "<<tft<<endl;
cout<<"Posterior(male):"<<post[0]<<endl;
cout<<"Posterior(female):"<<post[1]<<endl;
cout<<"The Candidate is "<<endl;
if(post[0]>post[1])
cout<<"MALE";
else
cout<<"FEMALE";
}
