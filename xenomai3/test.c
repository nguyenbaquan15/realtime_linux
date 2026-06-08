#include <alchemy/task.h>
#include <stdio.h>

RT_TASK task1;
RT_TASK task2;


void task1_print(void *arg)
{
  while (1)
  {
	 printf("Hello Xenomai in task1\n");
	 rt_task_sleep(1000000000);
  }
}

void task2_print(void *arg)
{
  while (1)
  {
         printf("Hello Xenomai in task2\n");
         rt_task_sleep(1000000000);
  }

}

int main()
{

  rt_task_create(&task1, "task1", 0, 50, 0);
  rt_task_create(&task2, "task2", 0, 50, 0);


  rt_task_start(&task1, task1_print, NULL);
  rt_task_start(&task2, task2_print, NULL);

  pause();
}
