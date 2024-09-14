//
// Created by pinkod on 13.09.2024.
//

#ifndef CUST_ALLOCATION_FAULTS_HANDLE_H
#define CUST_ALLOCATION_FAULTS_HANDLE_H

#include <signal.h>

void setHandler(void (*handler)(int,siginfo_t *,void *));
void fault_handler(int signo, siginfo_t *info, void *extra);

#endif //CUST_ALLOCATION_FAULTS_HANDLE_H
