#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdint.h>  // For intptr_t
#include<unistd.h>  // For sleep function

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg)
{
    intptr_t f = (intptr_t)arg;  // Safer casting using intptr_t
    sem_wait(&mutex);
    rcount = rcount + 1;
    if (rcount == 1)
        sem_wait(&writeblock);  // Block writer if this is the first reader
    sem_post(&mutex);

    printf("Data read by the reader %ld is %d\n", f, data);
    sleep(1);

    sem_wait(&mutex);
    rcount = rcount - 1;
    if (rcount == 0)
        sem_post(&writeblock);  // Allow writer if this is the last reader
    sem_post(&mutex);
}

void *writer(void *arg)
{
    intptr_t f = (intptr_t)arg;  // Safer casting using intptr_t
    sem_wait(&writeblock);
    data++;
    printf("Data written by the writer %ld is %d\n", f, data);
    sleep(1);
    sem_post(&writeblock);
}

int main()
{
    int i, num_readers, num_writers;
    
    // Ask the user for the number of readers and writers
    printf("Enter the number of readers: ");
    scanf("%d", &num_readers);
    
    printf("Enter the number of writers: ");
    scanf("%d", &num_writers);

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);

    pthread_t rtid[num_readers], wtid[num_writers];

    // Create writer threads
    for (i = 0; i < num_writers; i++)  
    {
        pthread_create(&wtid[i], NULL, writer, (void *)(intptr_t)i);
    }

    // Create reader threads
    for (i = 0; i < num_readers; i++)  
    {
        pthread_create(&rtid[i], NULL, reader, (void *)(intptr_t)i);
    }

    // Wait for all threads to complete
    for (i = 0; i < num_writers; i++)  
    {
        pthread_join(wtid[i], NULL);
    }
    
    for (i = 0; i < num_readers; i++)  
    {
        pthread_join(rtid[i], NULL);
    }

    return 0;
}

