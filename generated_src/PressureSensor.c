#include "PressureSensor.h"


// Header code defined in the model
/* Référence la variable globale 'pressure' définie dans main.c
   via le "Global code of application" du bloc PressureSensor.
   Pas de conflit de nom : la variable locale du bloc s'appelle
   désormais 'localPressure' (renommée dans les Attributes du modèle). */
extern int pressure;
extern pthread_mutex_t __pressureMutex;

int __userImplemented__PressureSensor__readingPressure() {
      /* Lecture protégée par mutex */
      pthread_mutex_lock(&__pressureMutex);
      int val = pressure;
      pthread_mutex_unlock(&__pressureMutex);
      return val;
}

bool __userImplemented__PressureSensor__isInCode() {
      return 1;
}

// End of header code defined in the model

#define STATE__START__STATE 0
#define STATE__SendingPressure 1
#define STATE__choice__0 2
#define STATE__WaitingForNextCycle 3
#define STATE__SensingPressure 4
#define STATE__STOP__STATE 5

int PressureSensor__readingPressure() {
  traceFunctionCall("PressureSensor", "readingPressure", "-");
  debugMsg("-> ....() Executing method readingPressure");
  return __userImplemented__PressureSensor__readingPressure();
}


bool PressureSensor__isInCode() {
  traceFunctionCall("PressureSensor", "isInCode", "-");
  debugMsg("-> ....() Executing method isInCode");
  return __userImplemented__PressureSensor__isInCode();
}


 request __req0__PressureSensor;
int *__params0__PressureSensor[1];
 request __req1__PressureSensor;
int *__params1__PressureSensor[1];
setOfRequests __list__PressureSensor;
pthread_cond_t __myCond__PressureSensor;
request *__returnRequest__PressureSensor;

void *mainFunc__PressureSensor(void *arg){
  bool branchToUse = false;
  int pressure = 0;
  
  int __currentState = STATE__START__STATE;
  
  char * __myname = (char *)arg;
  
  pthread_cond_init(&__myCond__PressureSensor, NULL);
  
  fillListOfRequests(&__list__PressureSensor, __myname, &__myCond__PressureSensor, &__mainMutex);
  //printf("my name = %s\n", __myname);
  
  /* Main loop on states */
  while(__currentState != STATE__STOP__STATE) {
    switch(__currentState) {
      case STATE__START__STATE: 
      traceStateEntering(__myname, "__StartState");
      debug2Msg(__myname, "-> (=====) Entering state + WaitingForNextCycle");
      __currentState = STATE__WaitingForNextCycle;
      break;
      
      case STATE__SendingPressure: 
      traceStateEntering(__myname, "SendingPressure");
      __params0__PressureSensor[0] = &pressure;
      makeNewRequest(&__req0__PressureSensor, 2110, SEND_SYNC_REQUEST, 0, 0, 0, 1, __params0__PressureSensor);
      __req0__PressureSensor.syncChannel = &__PressureSensor_pressureValue__MainController_pressureValue;
      __returnRequest__PressureSensor = executeOneRequest(&__list__PressureSensor, &__req0__PressureSensor);
      clearListOfRequests(&__list__PressureSensor);
      traceRequest(__myname, __returnRequest__PressureSensor);
      debug2Msg(__myname, "-> (=====) Entering state + WaitingForNextCycle");
      __currentState = STATE__WaitingForNextCycle;
      break;
      
      case STATE__choice__0: 
      traceStateEntering(__myname, "choice__0");
      if (!(branchToUse)) {
        makeNewRequest(&__req0__PressureSensor, 2116, IMMEDIATE, 0, 0, 0, 0, __params0__PressureSensor);
        addRequestToList(&__list__PressureSensor, &__req0__PressureSensor);
      }
      if (branchToUse) {
        makeNewRequest(&__req1__PressureSensor, 2124, IMMEDIATE, 0, 0, 0, 0, __params1__PressureSensor);
        addRequestToList(&__list__PressureSensor, &__req1__PressureSensor);
      }
      if (nbOfRequests(&__list__PressureSensor) == 0) {
        debug2Msg(__myname, "No possible request");
        __currentState = STATE__STOP__STATE;
        break;
      }
      __returnRequest__PressureSensor = executeListOfRequests(&__list__PressureSensor);
      clearListOfRequests(&__list__PressureSensor);
      traceRequest(__myname, __returnRequest__PressureSensor);
       if (__returnRequest__PressureSensor == &__req0__PressureSensor) {
        pressure = computeRandom(17, 23);
        debug2Msg(__myname, "-> (=====) Entering state + SendingPressure");
        __currentState = STATE__SendingPressure;
        
      }
      else  if (__returnRequest__PressureSensor == &__req1__PressureSensor) {
        pressure = PressureSensor__readingPressure();
        traceVariableModification("PressureSensor", "pressure", pressure,0);
        debug2Msg(__myname, "-> (=====) Entering state + SendingPressure");
        __currentState = STATE__SendingPressure;
        
      }
      break;
      
      case STATE__WaitingForNextCycle: 
      traceStateEntering(__myname, "WaitingForNextCycle");
      waitFor((1)*1000000, (1)*1000000);
      debug2Msg(__myname, "-> (=====) Entering state + SensingPressure");
      __currentState = STATE__SensingPressure;
      break;
      
      case STATE__SensingPressure: 
      traceStateEntering(__myname, "SensingPressure");
      branchToUse = PressureSensor__isInCode();
      traceVariableModification("PressureSensor", "branchToUse", branchToUse,1);
      debug2Msg(__myname, "-> (=====) Entering state + choice__0");
      __currentState = STATE__choice__0;
      break;
      
    }
  }
  //printf("Exiting = %s\n", __myname);
  return NULL;
}

