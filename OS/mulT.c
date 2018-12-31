#include <stdio.h>
#include <pthread.h>

unsigned long int sum[4];

void threadFn(void *arg) {
    long id = (long) arg;
    int start = id * 2500000;
    int i=0;
    while(i<2500000) {
        sum[id] += i;
        i++;
    }
    return NULL;
}

int main() {
pthread_t t1,t2,t3,t4;
pthread_create(&t1,NULL,threadFn,(void *)0);
pthread_create(&t2,NULL,threadFn,(void *)1);
pthread_create(&t3,NULL,threadFn,(void *)2);
pthread_create(&t4,NULL,threadFn,(void *)3);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);

printf("%u \n", sum[0]+sum[1]+sum[2]+sum[3]);
return 0;
}