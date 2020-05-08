
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
int a=0,b=10;

void *producer(void *pno)
{
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = a+ rand()%10; // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
sleep(5);
    }
}
void *consumer(void *cno)
{
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
sleep(5);
    }
}

int main()
{
int p_n,c_n;

printf("%s","enter no of producers ");
scanf("%d",&p_n);

printf("%s","enter no of consumers ");
scanf("%d",&c_n);

    pthread_t pro[p_n],con[c_n];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);



    int pro_no[p_n]; //Just used for numbering the producer and consumer
    int con_no[c_n];
        for(int i=0;i<p_n;i++)
{
 pro_no[i]=i+1;
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&pro_no[i]);
}


        for(int i=0;i<p_n;i++)
{
        con_no[i]=i+1;
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&con_no[i]);
}

        
        for(int i=0;i<p_n;i++)
                pthread_join(pro[i], NULL);
                
        for(int i=0;i<c_n;i++)
                pthread_join(con[i], NULL);


    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;

}

/// gcc foo.c -lpthread && ./a.out