#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

const int CAPACITY=4;
int BUFFER[CAPACITY];

pthread_mutex_t mutex;
int count=0;

void*prod(void* arg) {
    int *prod=(int*)arg;

    while (*prod<CAPACITY) {
        pthread_mutex_lock(&mutex);
        if (count<CAPACITY) {
            int num=rand()%100;
            BUFFER[count]=num;
            (*prod)++;
            count++;
            cout<<"produced "<<num<<"\n";
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
    return NULL;
}

void* cons(void* arg) {
    int *cons=(int*)arg;
    while (*cons<CAPACITY) {
        pthread_mutex_lock(&mutex);
        if (count>0) {
            count--;
            cout<<"consumed "<<BUFFER[count]<<"\n";
            (*cons)++;
            BUFFER[count]=-1;
        }

        pthread_mutex_unlock(&mutex);
    }


    pthread_exit(NULL);
    return NULL;
}

int main() {
    int produced=0,consumed=0;
    pthread_t producer,consumer;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer,NULL,&prod,&produced);
    pthread_create(&consumer,NULL,&cons,&consumed);

    pthread_join(producer,NULL);
    pthread_join(consumer,NULL);

    pthread_mutex_destroy(&mutex);

    cout << "\nExecution finished! Final counter values:\n";
    cout << "Total produced: " << produced << "\n";
    cout << "Total consumed: " << consumed << "\n";

    return 0;
}

