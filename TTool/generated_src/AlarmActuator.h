#ifndef AlarmActuator_H
#define AlarmActuator_H
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "request.h"
#include "syncchannel.h"
#include "request_manager.h"
#include "debug.h"
#include "defs.h"
#include "mytimelib.h"
#include "random.h"
#include "tracemanager.h"
#include "main.h"

extern void *mainFunc__AlarmActuator(void *arg);
extern __attribute__((unused)) request __req0__AlarmActuator;
extern __attribute__((unused))int *__params0__AlarmActuator[0];
extern __attribute__((unused)) request __req1__AlarmActuator;
extern __attribute__((unused))int *__params1__AlarmActuator[0];
extern __attribute__((unused))setOfRequests __list__AlarmActuator;
extern __attribute__((unused))pthread_cond_t __myCond__AlarmActuator;
extern __attribute__((unused))request *__returnRequest__AlarmActuator;

#endif
