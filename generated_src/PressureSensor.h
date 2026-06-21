#ifndef PressureSensor_H
#define PressureSensor_H
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

extern void *mainFunc__PressureSensor(void *arg);
extern __attribute__((unused)) request __req0__PressureSensor;
extern __attribute__((unused))int *__params0__PressureSensor[1];
extern __attribute__((unused)) request __req1__PressureSensor;
extern __attribute__((unused))int *__params1__PressureSensor[1];
extern __attribute__((unused))setOfRequests __list__PressureSensor;
extern __attribute__((unused))pthread_cond_t __myCond__PressureSensor;
extern __attribute__((unused))request *__returnRequest__PressureSensor;

#endif
