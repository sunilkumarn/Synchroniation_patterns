/*Representing a queue with semaphores */
#include<pthread.h>
#include<semaphore.h>
#define up(sem) sem_post(&sem);
#define down(sem) sem_wait(&sem);
sem_t leader ,follower ;
int val1 , val2;
void* fun1(int i)
{
	up(leader);
	down(follower);	
	printf("%d dancing follower\n",i);
}
void *fun2(int i )
{
	up(follower);
	down(leader);
	printf("%d dancing leader\n",i);
}

main()
{
	int i;
	pthread_t t[10],t1,t2,t3,t4;
	sem_init(&leader ,0 ,0);
	sem_init(&follower ,0 ,0);
	pthread_create(&t1 ,0 ,fun1 , 1 );
	pthread_create(&t2 ,0 ,fun1 , 2 );
	pthread_create(&t3 ,0 ,fun2 , 1 );
	pthread_create(&t4 ,0 ,fun1 , 3 );
	pthread_create(&t4 ,0 ,fun1 , 4 );
	pthread_create(&t4 ,0 ,fun2 , 2 );
	while(1);
}



