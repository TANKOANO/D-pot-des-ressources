#include "Timer_alarmTimer_AlarmManager.h"


// Header code defined in the model

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__wait4set 1
#define STATE__wait4expire 2
#define STATE__STOP__STATE 3

 request __req0__Timer_alarmTimer_AlarmManager;
int *__params0__Timer_alarmTimer_AlarmManager[1];
 request __req1__Timer_alarmTimer_AlarmManager;
int *__params1__Timer_alarmTimer_AlarmManager[1];
 request __req2__Timer_alarmTimer_AlarmManager;
int *__params2__Timer_alarmTimer_AlarmManager[1];
setOfRequests __list__Timer_alarmTimer_AlarmManager;
pthread_cond_t __myCond__Timer_alarmTimer_AlarmManager;
request *__returnRequest__Timer_alarmTimer_AlarmManager;

void *mainFunc__Timer_alarmTimer_AlarmManager(void *arg){
  int value = 0;
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__Timer_alarmTimer_AlarmManager, NULL);
  
  fillListOfRequests(&__list__Timer_alarmTimer_AlarmManager, __myname, &__myCond__Timer_alarmTimer_AlarmManager, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      debug2Msg(__myname, "-> (=====) Entering state + wait4set");
      __currentState = STATE__wait4set;
      break;
      
      case STATE__wait4set: 
      traceStateEntering(__myname, "wait4set");
      __params0__Timer_alarmTimer_AlarmManager[0] = &value;
      makeNewRequest(&__req0__Timer_alarmTimer_AlarmManager, 2185, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0__Timer_alarmTimer_AlarmManager);
      __req0__Timer_alarmTimer_AlarmManager.syncChannel = &__AlarmManager_set_alarmTimer__Timer_alarmTimer_AlarmManager_set;
      addRequestToList(&__list__Timer_alarmTimer_AlarmManager, &__req0__Timer_alarmTimer_AlarmManager);
      makeNewRequest(&__req1__Timer_alarmTimer_AlarmManager, 2187, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params1__Timer_alarmTimer_AlarmManager);
      __req1__Timer_alarmTimer_AlarmManager.syncChannel = &__AlarmManager_reset_alarmTimer__Timer_alarmTimer_AlarmManager_reset;
      addRequestToList(&__list__Timer_alarmTimer_AlarmManager, &__req1__Timer_alarmTimer_AlarmManager);
      if (nbOfRequests(&__list__Timer_alarmTimer_AlarmManager) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__Timer_alarmTimer_AlarmManager = executeListOfRequests(&__list__Timer_alarmTimer_AlarmManager);
      clearListOfRequests(&__list__Timer_alarmTimer_AlarmManager);
      traceRequest(__myname, __returnRequest__Timer_alarmTimer_AlarmManager);
       if (__returnRequest__Timer_alarmTimer_AlarmManager == &__req0__Timer_alarmTimer_AlarmManager) {
        debug2Msg(__myname, "-> (=====) Entering state + wait4expire");
        __currentState = STATE__wait4expire;
        
      }
      else  if (__returnRequest__Timer_alarmTimer_AlarmManager == &__req1__Timer_alarmTimer_AlarmManager) {
        debug2Msg(__myname, "-> (=====) Entering state + wait4set");
        __currentState = STATE__wait4set;
        
      }
      break;
      
      case STATE__wait4expire: 
      traceStateEntering(__myname, "wait4expire");
      __params0__Timer_alarmTimer_AlarmManager[0] = &value;
      makeNewRequest(&__req0__Timer_alarmTimer_AlarmManager, 2186, RECEIVE_SYNC_REQUEST, 0, 0, 0, 1, __params0__Timer_alarmTimer_AlarmManager);
      __req0__Timer_alarmTimer_AlarmManager.syncChannel = &__AlarmManager_set_alarmTimer__Timer_alarmTimer_AlarmManager_set;
      addRequestToList(&__list__Timer_alarmTimer_AlarmManager, &__req0__Timer_alarmTimer_AlarmManager);
      makeNewRequest(&__req1__Timer_alarmTimer_AlarmManager, 2189, SEND_SYNC_REQUEST, 1, (value)*1000000, (value)*1000000, 0, __params1__Timer_alarmTimer_AlarmManager);
      __req1__Timer_alarmTimer_AlarmManager.syncChannel = &__AlarmManager_expire_alarmTimer__Timer_alarmTimer_AlarmManager_expire;
      addRequestToList(&__list__Timer_alarmTimer_AlarmManager, &__req1__Timer_alarmTimer_AlarmManager);
      makeNewRequest(&__req2__Timer_alarmTimer_AlarmManager, 2188, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params2__Timer_alarmTimer_AlarmManager);
      __req2__Timer_alarmTimer_AlarmManager.syncChannel = &__AlarmManager_reset_alarmTimer__Timer_alarmTimer_AlarmManager_reset;
      addRequestToList(&__list__Timer_alarmTimer_AlarmManager, &__req2__Timer_alarmTimer_AlarmManager);
      if (nbOfRequests(&__list__Timer_alarmTimer_AlarmManager) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__Timer_alarmTimer_AlarmManager = executeListOfRequests(&__list__Timer_alarmTimer_AlarmManager);
      clearListOfRequests(&__list__Timer_alarmTimer_AlarmManager);
      traceRequest(__myname, __returnRequest__Timer_alarmTimer_AlarmManager);
       if (__returnRequest__Timer_alarmTimer_AlarmManager == &__req0__Timer_alarmTimer_AlarmManager) {
        debug2Msg(__myname, "-> (=====) Entering state + wait4expire");
        __currentState = STATE__wait4expire;
        
      }
      else  if (__returnRequest__Timer_alarmTimer_AlarmManager == &__req1__Timer_alarmTimer_AlarmManager) {
        debug2Msg(__myname, "-> (=====) Entering state + wait4set");
        __currentState = STATE__wait4set;
        
      }
      else  if (__returnRequest__Timer_alarmTimer_AlarmManager == &__req2__Timer_alarmTimer_AlarmManager) {
        debug2Msg(__myname, "-> (=====) Entering state + wait4set");
        __currentState = STATE__wait4set;
        
      }
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

