#include <stdio.h>
#include "threads/thread.h"

tid_t thread2_in_thread1;

void fn_thread2_test(void){
	printf("thread2 function\n");
}

void fn_thread_test(void){
	printf("thread name %s function execution\n", thread_name());

	thread2_in_thread1 = thread_create("test thread2", PRI_DEFAULT, fn_thread2_test, NULL);

	thread_join(thread2_in_thread1);
}

void synctest(void)
{
	struct thread* cur_thread = thread_current();

	tid_t thread1_tid = thread_create("test thread1", PRI_DEFAULT, fn_thread_test, NULL);

	thread_join(thread1_tid);

	printf("implement synchronize test!!!\n");
}
