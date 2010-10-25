/*Extending the ' queue ' problem to make it an exclusive queue problem where each dancer 
  ' dances ' with its corresponding follower */
#include<pthread.h>
#include<semaphore.h>
#define up(sem) sem_post(&sem);
#define down(sem) sem_wait(&sem);
sem_t leader ,follower ,mutex , rendz;
int followers=0 , leaders=0;
void* fun1(int i)
{
	down(mutex);
	if (followers > 0)
	{
		followers -- ;
		up(follower);
	}
	else
	{
		leaders++;
		up(mutex);
		down(leader);
	}
	printf("%dth dancing leader\n",i);
	down(rendz);
	up(mutex);
}

void* fun2(int i)
{
	down(mutex);
	if (leaders > 0)
	{
		leaders -- ;
		up(leader);
	}
	else
	{
		followers++;
		up(mutex);
		down(follower);
	}
	printf("%dth dancing follower\n",i);
	up(rendz)
}

main()
{
	int i;
	pthread_t t1,t2,t3,t4;
	sem_init(&leader ,0 ,0);
	sem_init(&follower ,0 ,0);
	sem_init(&mutex ,0 ,1);
	sem_init(&rendz ,0 ,0);
	pthread_create(&t1 ,0 ,fun1 , 1 );
	pthread_create(&t2 ,0 ,fun1 , 2 );
	pthread_create(&t3 ,0 ,fun2 , 1 );
	pthread_create(&t4 ,0 ,fun1 , 3 );
	pthread_create(&t4 ,0 ,fun2 , 2 );
	while(1);
}



