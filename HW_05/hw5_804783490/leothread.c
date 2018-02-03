//Name: Zhibang Chen
//UID: 804783490

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread(void *vargp);
int leoNum(int N);

struct argument {
    int N;
    int label;
};


int main(int argc, char const *argv[]) {
    struct argument arg;
    int N = atoi(argv[1]);
    if (N < 0) {
        printf("N cannot be negative.\n");
        exit(1);
    } else {
        arg.N = N;
        arg.label = 0;
        pthread_t tid;
        pthread_create(&tid, NULL, thread, (void *)&arg);
        pthread_join(tid, NULL);
        return 0;
    }
}

void *thread(void *arg) {
    pthread_t tid[2];
    struct argument *local;
    local = (struct argument *)arg;
    
    int localLabel = (*local).label;
    int localN = (*local).N;
    
    if (localN > 1) {
        struct argument arg1,arg2;
        arg1.N = localN-1;
        arg1.label = localLabel + 1;
        arg2.N = localN-2;
        arg2.label = localLabel + 1 + leoNum(localN-1);
        
        printf("(%d\n", localLabel);
        pthread_create(&tid[0], NULL, thread, (void *)&arg1);
        pthread_join(tid[0], NULL);
        pthread_create(&tid[1], NULL, thread, (void *)&arg2);
        pthread_join(tid[1], NULL);
        printf("%d)\n", localLabel);
    }else   printf("[%d]\n", localLabel);
    
    return NULL;
}

int leoNum(int N) {
    if(N == 1 || N == 0)    return 1;
    else if (N>1)   return leoNum(N-1) + leoNum(N-2) + 1;
    else    return 0;
}







