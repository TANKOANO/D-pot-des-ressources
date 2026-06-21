#include "AlarmManager.h"


// Header code defined in the model

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__AlarmIsOn 1
#define STATE__AlarmIsOff 2
#define STATE__STOP__STATE 3

 request __req0__AlarmManager;
int *__params0__AlarmManager[1];
 request __req1__AlarmManager;
int *__params1__AlarmManager[1];
setOfRequests __list__AlarmManager;
pthread_cond_t __myCond__AlarmManager;
request *__returnRequest__AlarmManager;

void *mainFunc__AlarmManager(void *arg){
  int alarmDuration = 3;
  int timerValue_ = 0;
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__AlarmManager, NULL);
  
  fillListOfRequests(&__list__AlarmManager, __myname, &__myCond__AlarmManager, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      debug2Msg(__myname, "-> (=====) Entering state + AlarmIsOff");
      __currentState = STATE__AlarmIsOff;
      break;
      
      case STATE__AlarmIsOn: 
      traceStateEntering(__myname, "AlarmIsOn");
      makeNewRequest(&__req0__AlarmManager, 2208, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
      __req0__AlarmManager.syncChannel = &__AlarmManager_expire_alarmTimer__Timer_alarmTimer_AlarmManager_expire;
      addRequestToList(&__list__AlarmManager, &__req0__AlarmManager);
      makeNewRequest(&__req1__AlarmManager, 2151, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params1__AlarmManager);
      __req1__AlarmManager.syncChannel = &__MainController_highPressure__AlarmManager_highPressure;
      addRequestToList(&__list__AlarmManager, &__req1__AlarmManager);
      if (nbOfRequests(&__list__AlarmManager) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__AlarmManager = executeListOfRequests(&__list__AlarmManager);
      clearListOfRequests(&__list__AlarmManager);
      traceRequest(__myname, __returnRequest__AlarmManager);
       if (__returnRequest__AlarmManager == &__req0__AlarmManager) {
        makeNewRequest(&__req0__AlarmManager, 2148, SEND_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
        __req0__AlarmManager.syncChannel = &__AlarmManager_alarmOff__AlarmActuator_alarmOff;
        __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
        clearListOfRequests(&__list__AlarmManager);
        traceRequest(__myname, __returnRequest__AlarmManager);
        debug2Msg(__myname, "-> (=====) Entering state + AlarmIsOff");
        __currentState = STATE__AlarmIsOff;
        
      }
      else  if (__returnRequest__AlarmManager == &__req1__AlarmManager) {
        makeNewRequest(&__req0__AlarmManager, 2207, SEND_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
        __req0__AlarmManager.syncChannel = &__AlarmManager_reset_alarmTimer__Timer_alarmTimer_AlarmManager_reset;
        __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
        clearListOfRequests(&__list__AlarmManager);
        traceRequest(__myname, __returnRequest__AlarmManager);
        timerValue_ = alarmDuration;
        traceVariableModification("AlarmManager", "timerValue_", timerValue_,0);
        __params0__AlarmManager[0] = &timerValue_;
        makeNewRequest(&__req0__AlarmManager, 2203, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0__AlarmManager);
        __req0__AlarmManager.syncChannel = &__AlarmManager_set_alarmTimer__Timer_alarmTimer_AlarmManager_set;
        __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
        clearListOfRequests(&__list__AlarmManager);
        traceRequest(__myname, __returnRequest__AlarmManager);
        makeNewRequest(&__req0__AlarmManager, 2146, SEND_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
        __req0__AlarmManager.syncChannel = &__AlarmManager_alarmOn__AlarmActuator_alarmOn;
        __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
        clearListOfRequests(&__list__AlarmManager);
        traceRequest(__myname, __returnRequest__AlarmManager);
        debug2Msg(__myname, "-> (=====) Entering state + AlarmIsOn");
        __currentState = STATE__AlarmIsOn;
        
      }
      break;
      
      case STATE__AlarmIsOff: 
      traceStateEntering(__myname, "AlarmIsOff");
      makeNewRequest(&__req0__AlarmManager, 2155, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
      __req0__AlarmManager.syncChannel = &__MainController_highPressure__AlarmManager_highPressure;
      __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
      clearListOfRequests(&__list__AlarmManager);
      traceRequest(__myname, __returnRequest__AlarmManager);
      timerValue_ = alarmDuration;
      traceVariableModification("AlarmManager", "timerValue_", timerValue_,0);
      __params0__AlarmManager[0] = &timerValue_;
      makeNewRequest(&__req0__AlarmManager, 2209, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0__AlarmManager);
      __req0__AlarmManager.syncChannel = &__AlarmManager_set_alarmTimer__Timer_alarmTimer_AlarmManager_set;
      __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
      clearListOfRequests(&__list__AlarmManager);
      traceRequest(__myname, __returnRequest__AlarmManager);
      makeNewRequest(&__req0__AlarmManager, 2147, SEND_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmManager);
      __req0__AlarmManager.syncChannel = &__AlarmManager_alarmOn__AlarmActuator_alarmOn;
      __returnRequest__AlarmManager = executeOneRequest(&__list__AlarmManager, &__req0__AlarmManager);
      clearListOfRequests(&__list__AlarmManager);
      traceRequest(__myname, __returnRequest__AlarmManager);
      debug2Msg(__myname, "-> (=====) Entering state + AlarmIsOn");
      __currentState = STATE__AlarmIsOn;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

