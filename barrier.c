/*Generalizing the solution to the 'rendezvous' pattern so that it could be applied on any
  number of threads */
#include<pthread.h>
#include<semaphore.h>
#define up(sem) sem_post(&sem);
#define down(sem) sem_wait(&sem);
sem_t mutex ,barrier ;
int val1 , val2 , count = 0 , n = 2;
void* fun1()
{
	strcpy(a , "Hello ");
	down(mutex);
		count = count + 1;
 	up(mutex);
	if (count == n )
		up(barrier);
	down(barrier);
	printf("%s\n" ,b);
	up(barrier);
}


void* fun2()
{
	strcpy(b , "world ");
	down(mutex);
		count = count + 1;
 	up(mutex);
	if (count == n )
		up(barrier);
	down(barrier);
	printf("%s\n" ,a);
	up(barrier);	
}

main()
{
	pthread_t t1 ,t2;
	sem_init(&mutex ,0 ,1);
	sem_init(&barrier ,0 ,0);
	pthread_create(&t1 ,0 ,fun1 , 0 );
	pthread_create(&t2 ,0 ,fun2 , 0 );
	while(1);
}



