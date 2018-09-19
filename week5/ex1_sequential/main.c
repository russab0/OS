#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define N 10
#define SLEEPING_TIME 2


struct S{
    int num;
    char *text;
};


void *print_str(void *ptr){
    struct S* msg = (struct S*) ptr;
	int num = msg->num;
	char *text = msg->text;
	printf("%d %s\n", num, text);
}


int main(){
	pthread_t thread1, thread2;

	for (int i = 0; i < N; i++){
        	struct S *msg = (struct S*) malloc(sizeof(struct S));
	        msg->num = i;
        	msg->text = "thread";

        	int tc = pthread_create(&thread1, NULL, print_str, (void*) msg);
        	printf("thread %d have been created\n", i);
        	sleep(SLEEPING_TIME);
	}

	return 0;
}
