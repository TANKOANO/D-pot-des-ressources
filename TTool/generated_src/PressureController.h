#ifndef PressureController_H
#define PressureController_H
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

extern void *mainFunc__PressureController(void *arg);
extern __attribute__((unused)) request __req0__PressureController;
extern __attribute__((unused))int *__params0__PressureController[0];
extern __attribute__((unused))setOfRequests __list__PressureController;
extern __attribute__((unused))pthread_cond_t __myCond__PressureController;
extern __attribute__((unused))request *__returnRequest__PressureController;

#endif
