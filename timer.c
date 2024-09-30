#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_count = 0;  
time_t start_time;


void handle_alarm(int sig) {
    if (sig == SIGALRM) {
        printf("Hello World!\n");
        alarm_count++;  
        alarm(1);  
    }
}


void handle_sigint(int sig) {
    if (sig == SIGINT) {
        time_t end_time = time(NULL);  
        printf("\nProgram ran for %ld seconds\n", end_time - start_time);
        printf("Number of alarms: %d\n", alarm_count);
        exit(0); 
    }
}

int main() {
    
    start_time = time(NULL);

    
    signal(SIGALRM, handle_alarm);
    signal(SIGINT, handle_sigint);

    
    alarm(1);

    
    while (1) {
        pause();  
    }

    return 0;
}
