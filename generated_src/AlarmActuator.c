#include "AlarmActuator.h"


// Header code defined in the model
/* sendDatagram est définie dans main.c (via le Global code of application
   de PressureSensor). On la déclare extern ici pour que AlarmActuator.c
   puisse l'appeler lors de l'édition de liens. */
extern void sendDatagram(char *data, int size);

void __userImplemented__AlarmActuator__setAlarm(bool onoff) {
      if (onoff) {
            printf("Alarm ON\n");
            sendDatagram("+", 1);
      } else {
            printf("Alarm OFF\n");
            sendDatagram("-", 1);
      }
}

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__AlarmOff 1
#define STATE__AlarmOn 2
#define STATE__WaitingForAlarmCommand 3
#define STATE__STOP__STATE 4

void AlarmActuator__setAlarm(bool onoff) {
  char my__attr[CHAR_ALLOC_SIZE];
  sprintf(my__attr, "%d",onoff);
  traceFunctionCall("AlarmActuator", "setAlarm", my__attr);
  debugMsg("-> ....() Executing method setAlarm");
  debugInt("Attribute onoff = ",onoff);
  __userImplemented__AlarmActuator__setAlarm(onoff);
}


 request __req0__AlarmActuator;
int *__params0__AlarmActuator[0];
 request __req1__AlarmActuator;
int *__params1__AlarmActuator[0];
setOfRequests __list__AlarmActuator;
pthread_cond_t __myCond__AlarmActuator;
request *__returnRequest__AlarmActuator;

void *mainFunc__AlarmActuator(void *arg){
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__AlarmActuator, NULL);
  
  fillListOfRequests(&__list__AlarmActuator, __myname, &__myCond__AlarmActuator, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      debug2Msg(__myname, "-> (=====) Entering state + WaitingForAlarmCommand");
      __currentState = STATE__WaitingForAlarmCommand;
      break;
      
      case STATE__AlarmOff: 
      traceStateEntering(__myname, "AlarmOff");
      AlarmActuator__setAlarm(false);
      debug2Msg(__myname, "-> (=====) Entering state + WaitingForAlarmCommand");
      __currentState = STATE__WaitingForAlarmCommand;
      break;
      
      case STATE__AlarmOn: 
      traceStateEntering(__myname, "AlarmOn");
      AlarmActuator__setAlarm(true);
      debug2Msg(__myname, "-> (=====) Entering state + WaitingForAlarmCommand");
      __currentState = STATE__WaitingForAlarmCommand;
      break;
      
      case STATE__WaitingForAlarmCommand: 
      traceStateEntering(__myname, "WaitingForAlarmCommand");
      makeNewRequest(&__req0__AlarmActuator, 2091, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params0__AlarmActuator);
      __req0__AlarmActuator.syncChannel = &__AlarmManager_alarmOn__AlarmActuator_alarmOn;
      addRequestToList(&__list__AlarmActuator, &__req0__AlarmActuator);
      makeNewRequest(&__req1__AlarmActuator, 2090, RECEIVE_SYNC_REQUEST, 0, 0, 0, 0, __params1__AlarmActuator);
      __req1__AlarmActuator.syncChannel = &__AlarmManager_alarmOff__AlarmActuator_alarmOff;
      addRequestToList(&__list__AlarmActuator, &__req1__AlarmActuator);
      if (nbOfRequests(&__list__AlarmActuator) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__AlarmActuator = executeListOfRequests(&__list__AlarmActuator);
      clearListOfRequests(&__list__AlarmActuator);
      traceRequest(__myname, __returnRequest__AlarmActuator);
       if (__returnRequest__AlarmActuator == &__req0__AlarmActuator) {
        debug2Msg(__myname, "-> (=====) Entering state + AlarmOn");
        __currentState = STATE__AlarmOn;
        
      }
      else  if (__returnRequest__AlarmActuator == &__req1__AlarmActuator) {
        debug2Msg(__myname, "-> (=====) Entering state + AlarmOff");
        __currentState = STATE__AlarmOff;
        
      }
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

