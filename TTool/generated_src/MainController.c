#include "MainController.h"


// Header code defined in the model

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__LowPressure 1
#define STATE__HighPressure 2
#define STATE__choice__0 3
#define STATE__WaitFirstHighPressure 4
#define STATE__STOP__STATE 5

 request __req0__MainController;
int *__params0__MainController[1];
 request __req1__MainController;
int *__params1__MainController[1];
setOfRequests __list__MainController;
pthread_cond_t __myCond__MainController;
request *__returnRequest__MainController;

void *mainFunc__MainController(void *arg){
  int threshold = 20;
  int currentPressure = 0;
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__MainController, NULL);
  
  fillListOfRequests(&__list__MainController, __myname, &__myCond__MainController, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      debug2Msg(__myname, "-> (=====) Entering state + WaitFirstHighPressure");
      __currentState = STATE__WaitFirstHighPressure;
      break;
      
      case STATE__LowPressure: 
      traceStateEntering(__myname, "LowPressure");
      debug2Msg(__myname, "-> (=====) Entering state + WaitFirstHighPressure");
      __currentState = STATE__WaitFirstHighPressure;
      break;
      
      case STATE__HighPressure: 
      traceStateEntering(__myname, "HighPressure");
      makeNewRequest(&__req0__MainController, 2133, SEND_SYNC_REQUEST, 0, 0, 0, 0, __params0__MainController);
      __req0__MainController.syncChannel = &__MainController_highPressure__AlarmManager_highPressure;
      __returnRequest__MainController = executeOneRequest(&__list__MainController, &__req0__MainController);
      clearListOfRequests(&__list__MainController);
      traceRequest(__myname, __returnRequest__MainController);
      debug2Msg(__myname, "-> (=====) Entering state + WaitFirstHighPressure");
      __currentState = STATE__WaitFirstHighPressure;
      break;
      
      case STATE__choice__0: 
      traceStateEntering(__myname, "choice__0");
      if ((currentPressure)<(threshold)) {
        makeNewRequest(&__req0__MainController, 2141, IMMEDIATE, 0, 0, 0, 0, __params0__MainController);
        addRequestToList(&__list__MainController, &__req0__MainController);
      }
      if ((currentPressure)>=(threshold)) {
        makeNewRequest(&__req1__MainController, 2145, IMMEDIATE, 0, 0, 0, 0, __params1__MainController);
        addRequestToList(&__list__MainController, &__req1__MainController);
      }
      if (nbOfRequests(&__list__MainController) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__MainController = executeListOfRequests(&__list__MainController);
      clearListOfRequests(&__list__MainController);
      traceRequest(__myname, __returnRequest__MainController);
       if (__returnRequest__MainController == &__req0__MainController) {
        debug2Msg(__myname, "-> (=====) Entering state + LowPressure");
        __currentState = STATE__LowPressure;
        
      }
      else  if (__returnRequest__MainController == &__req1__MainController) {
        debug2Msg(__myname, "-> (=====) Entering state + HighPressure");
        __currentState = STATE__HighPressure;
        
      }
      break;
      
      case STATE__WaitFirstHighPressure: 
      traceStateEntering(__myname, "WaitFirstHighPressure");
      __params0__MainController[0] = &currentPressure;
      makeNewRequest(&__req0__MainController, 2135, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0__MainController);
      __req0__MainController.syncChannel = &__PressureSensor_pressureValue__MainController_pressureValue;
      __returnRequest__MainController = executeOneRequest(&__list__MainController, &__req0__MainController);
      clearListOfRequests(&__list__MainController);
      traceRequest(__myname, __returnRequest__MainController);
      debug2Msg(__myname, "-> (=====) Entering state + choice__0");
      __currentState = STATE__choice__0;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

