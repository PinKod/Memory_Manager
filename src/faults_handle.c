//
// Created by pinkod on 13.09.2024.
//
#include "include/faults_handle.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef MACOS
#include <signal.h>// Code for macOS
#endif

#ifdef LINUX
#include <sys/signal.h>// Code for Linux
#endif

#include "include/cust_allocation.h"

void setHandler(void (*handler)(int,siginfo_t *,void *));
void fault_handler(int signo, siginfo_t *info, void *extra);

void setHandler(void (*handler)(int,siginfo_t *,void *))
{
    struct sigaction action = {0};
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handler;

/*
    if (sigaction(SIGFPE, &action, NULL) == -1) {
        perror("sigfpe: sigaction");
        _exit(1);
    }
*/
//#ifdef DEBUG
    for(int i = 1; i <= 31; i++) {
        if(sigaction(i, &action, NULL) == -1) {
#ifdef DEBUG
            printf("sig%d: sigaction", i);
#endif
            exit(1);
        }
    }
//#endif
}

void fault_handler(int signo, siginfo_t *info, void *extra)
{
#ifdef DEBUG
    ucontext_t *p=(ucontext_t *)extra;
	int val;
	printf("Signal %d received from parent\n", signo);
	printf("siginfo address=%x\n",info->si_addr);

	val= p->uc_mcontext.arm_pc;

	printf("address = %x\n",val);
#endif
    cust_free();
    //printf("fault handle free\n");
    exit(1);
}

void handler() {
    setHandler(fault_handler);
}