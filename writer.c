#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex,wrt;
int data=0,readcount=0;

void*writer(void*arg)
{
	int id=*((int*)arg);
	sem_wait(&wrt);
	data++;
	printf("the data is written by writer with id %d is %d\n ",id,data);
	sem_post(&wrt);
}

void*reader(void*arg)
{
	int id=*((int*)arg);
	sem_wait(&mutex);
	readcount++;
	data++;
	if (readcount==1)
		sem_wait(&wrt);
	sem_post(&mutex);
	printf("\nThe data read by reader with id %d is %d\n",id,data);
	readcount--;
	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);
}

int main()
{
	int i;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_t rid[5],wid[5];
	for(i=0;i<2;i++)
		pthread_create(&wid[i],NULL,writer,&i);
	for(i=0;i<3;i++)
		pthread_create(&rid[i],NULL,reader,&i);
	for(i=0;i<2;i++)
		pthread_join(wid[i],NULL);
	for(i=0;i<3;i++)
		pthread_join(rid[i],NULL);
	printf("\nThe value of the shared resource at the end is: %d\n",data);
	return 0;
}
















