#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

#include "crest.h"
#include "../assert.h"

int x;

void *PrintHello(void *threadid) {
    long tid;
    tid = (long) threadid;
    if (x) {
        printf("a @ thread %ld\n", tid);
    } else {
        printf("b @ thread %ld\n", tid);
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    pthread_t threads[NUM_THREADS];

    long t;
    int rc;
    CREST_int(x);
    CREST_shared_int(x);
    CREST_shared_int(rc);
    //CREST_shared_int(t); // long ?
    t = 0;
    while (t < NUM_THREADS) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t);
        //assert(!rc);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            //exit(-1);
            pthread_exit(NULL);
        }
        t = t + 1;
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}

