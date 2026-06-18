#include <stdio.h>
#include <pthread.h>
#include <evl/thread.h>
#include <evl/clock.h>

void *task1_print(void * arg)
{
	evl_attach_self("task1");

	while(1)
	{
		printf("Hello, task1\n");
		evl_usleep(1000000);
	}
}

void *task2_print()
{
	evl_attach_self("task2");

	while(1)
	{
		printf("Hi, task2\n");
		evl_usleep(1000000);
	}
}

int main(void)
{
	pthread_t task1;
	pthread_t task2;

	pthread_create(&task1,NULL,task1_print,NULL);
	pthread_create(&task2,NULL,task2_print,NULL);

	pthread_join(task1,NULL);
	pthread_join(task2,NULL);

	return 0;
}
