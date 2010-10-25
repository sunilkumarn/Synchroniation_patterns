 /* 'n' number of threads execute in parallel while the other following threads execute one by one only after the exit of the executed threads one by one */
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define up(sem) sem_post(&sem);
#define down(sem) sem_wait(&sem);
sem_t sem;
int val;
void* fun(int k)	
{
	down(sem);
	printf("Thread %d going to sleep \n",k);
	printf("Thread %d back from sleep \n",k);
	sleep(5);
	up(sem);
}
main()
{
	int i;
	pthread_t t[100];
	sem_init(&sem ,0 ,1);	
	for(i=0;i<10;i++)
		pthread_create(&t[i] ,0 ,fun ,i);
	while(1);
}

