#include <stdio.h>
#include <conio.h>
#include <math.h>
#define alpha .00000001
#define desired_error 0.10
#define no_of_sample 5

void testing();
float h[no_of_sample];
float  cal_h(int);
void w_initialisation();


int x[no_of_sample][2]= { {1000,2},{2000,4},{500,1}, {3000,2},{1500,3},{3500,7},{4500,9},{5000,10}, {5500,11},{6000,12}};


int test[no_of_sample][2]= { {1500,2}, {3000,3}};

float y[no_of_sample]={24,48,12,72,36,84,108,120,132,144};
float w[3];

void main()
{
  int i,j,k;
  float error=1;
  float t;
  w_initialisation();
   for(i=0; i < no_of_sample && error > desired_error; i++)
    {
     printf("\nH for Training sample %d= %f", i+1,cal_h(i));
     error= 0.5 * pow((h[i]-y[i]),2);
     printf("\nCost= %f",error);

     for(j=0; j < 3; j++)
       {
	 t=0.0;
       	 if(j==0)
       	   {
               for(k=0;k<no_of_sample;k++)
	          {
			        t=t+(y[k]-h[k])*1;
                    w[0]=w[0] + alpha * t;
	           }
	    }
	 else
              {
	       for(k=0;k<no_of_sample;k++)
		     {
                  	t=t+(y[k]-h[k])*x[k][j-1];
                    w[j]=w[j] + alpha * t;
	           }
               }
       }
       h[i]=cal_h(i);
      error= 0.5 * pow((h[i]-y[i]),2);
    }

   testing();
}

void testing()
{  int i,j;
   float test_y=0.0;
    for(i=0; i < 2; i++)
     {
       test_y=0.0;
       for(j=0; j < 3; j++)
        {
          if(j==0)
       	 { test_y=w[0];
	 }
	 else
            test_y= test_y + w[j] * test[i][j-1];
         }

      printf("\ntest_y=%f",test_y);
    }
}

float  cal_h( int i)
{
   int j;
   float temp=0.0;
   for(j=0; j < 3; j++)
   {
       if(j==0)
        {
          temp=w[0];
        }
       else
       {
        temp = temp + w[j]* x[i][j-1];
       }
   }
    h[i]=temp;
    printf("\n\n cal_h= %f  %f.........", temp,h[i]);
    return h[i];
}

void w_initialisation()
{
     w[0]= .001;
     w[1]= .0001;
     w[2]= .003;

}
