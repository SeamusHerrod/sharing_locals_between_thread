#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

    typedef struct thread_args {
    int tid;
    int inc;
    int loop;
} thread_args;

void *inc_count(void *arg)
{
    int* shared_local = (int*)arg;
    __atomic_add_fetch(shared_local,1, __ATOMIC_RELAXED);
    pthread_exit(NULL);
}

int main() {
    int count = 0;
    int *count_loc = &count;

    pthread_t thread; 
    pthread_create(&thread, NULL, inc_count, count_loc);
    pthread_join(thread, NULL);
    printf("count after thread: %d\n", count);


return 0;
}