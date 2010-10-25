/* Execute the statements A1 and B1 before the statements A2 and B2 are executed */
#include<pthread.h>
#include<semaphore.h>
#define up(sem) sem_post(&sem);
#define down(sem) sem_wait(&sem);
sem_t sem1 ,sem2 ;
char a[10]="random" ,b[10]="random";
int val1 , val2;
void* fun1()
{
	strcpy(a , "Hello ");    //A1
	up(sem1);
	down(sem2);	
	printf("%s\n" ,b);       //B2
}
void* fun2()
{
	strcpy(b , "World");	 //B1
	up(sem2);
	down(sem1);
	printf("%s\n" ,a);       //A2
}

main()
{
	pthread_t t1 ,t2;
	sem_init(&sem1 ,0 ,0);
	sem_init(&sem2 ,0 ,0);
	pthread_create(&t1 ,0 ,fun1 , 0 );
	pthread_create(&t2 ,0 ,fun2 , 0 );
	while(1);
}



