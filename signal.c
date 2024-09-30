#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int turing_flag = 0;  


void handle_signal(int sig) {
    if (sig == SIGALRM) {
        printf("Hello World!\n");
        turing_flag = 1;  
    }
}

int main() {
    
    signal(SIGALRM, handle_signal);

    
    alarm(5);

    
    while (1) {
        pause();  
        if (turing_flag) {
            printf("Turing was right!\n");
            turing_flag = 0;  
            alarm(5);  
        }
    }

    return 0;
}
