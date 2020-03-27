#include<bits/stdc++.h>
using namespace std;
main(){
	int i,j,p;
	    float arr[25]={1,4,67,32,8,34,6,225,78,98,254,212,45,199,198,133,99,33,54,143,189,134};
        float arr1[25];
        float assign[25];
        float a1[25][16];

        float cluster[16] = {0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240};
        for(p=0;p<10;p++)
        {
            for (i = 0; i < 25; i++) {
                for (j = 0; j < 16; j++) {
                    a1[i][j] = (float) sqrt((arr[i] - cluster[j]) * (arr[i] - cluster[j]));
                }
            }
            for (i = 0; i < 25; i++) {
                int pos = 0;
                float min = 9999;
                for (j = 0; j < 16; j++) {
                    if (a1[i][j] <= min) {
                        min = a1[i][j];
                        pos = j;
                    }
                }
                assign[i] = pos;
            }

            for (i = 0; i < 16; i++) {
                float h = 0;
                int count = 0;
                for (j = 0; j < 25; j++) {
                    if (assign[j] == i) {
                        h += arr[j];
                        count++;
                    }
                }
                if(count!=0)
                    cluster[i] = (float)h / count;
            }
            printf("\n\n");
            printf("Cluster updated values : \n");
            for (i = 0; i < 16; i++) {
                printf("%0.2f\n",cluster[i]);
            }
        }
        printf("\n\n");
        printf("Final Cluster values : \n");
        for (i = 0; i < 16; i++) {
            printf("%0.2f\n",cluster[i]);
            }
        for (i = 0; i < 25; i++) {
            int pos = 0;
            float min = 9999;
            for (j = 0; j < 16; j++) {
                if (a1[i][j] <= min) {
                    min = a1[i][j];
                    pos = j;
                }
            }
            arr1[i]=pos;
        }
        for(i=0;i<25;i++){
            printf("%.f\t",arr1[i]);
        }
}
