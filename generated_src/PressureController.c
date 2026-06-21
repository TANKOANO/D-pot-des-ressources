#include "PressureController.h"


// Header code defined in the model

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__STOP__STATE 1

 request __req0__PressureController;
int *__params0__PressureController[0];
setOfRequests __list__PressureController;
pthread_cond_t __myCond__PressureController;
request *__returnRequest__PressureController;

void *mainFunc__PressureController(void *arg){
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__PressureController, NULL);
  
  fillListOfRequests(&__list__PressureController, __myname, &__myCond__PressureController, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      __currentState = STATE__STOP__STATE;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

