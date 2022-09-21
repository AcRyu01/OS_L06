#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum, msum;
void *runner(void *param);

int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, argv[1]);
	
	int p = atoi(argv[1]);		
	if(p>0){
		for(int i = 1; i<=p; i++){
			msum += i;
		}
	}


	pthread_join(tid, NULL);

	printf("csum = %d\n", csum);
	printf("msum = %d\n", msum);
	return 0;
}
void *runner(void *param){
	int p = atoi(param);
	if(p>0){
		for(int i = 1; i<=(p*2); i++){
			csum += i;
		}
	}
	pthread_exit(0);
}
