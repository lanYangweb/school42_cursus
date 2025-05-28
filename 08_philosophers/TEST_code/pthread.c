#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void *my_thread(void *mutex)
{
    printf("Hello from thread\n");
    pthread_mutex_lock(mutex);
    printf("Thread is running safely\n");
    pthread_mutex_unlock(mutex);
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    pthread_create(&thread, NULL, my_thread, &mutex);
    pthread_join(thread, NULL);
    printf("thread end.\n");
    return 0;
}
