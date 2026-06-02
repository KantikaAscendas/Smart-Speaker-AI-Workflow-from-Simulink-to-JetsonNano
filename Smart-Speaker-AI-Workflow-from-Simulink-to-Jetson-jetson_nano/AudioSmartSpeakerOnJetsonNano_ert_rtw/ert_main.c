/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'AudioSmartSpeakerOnJetsonNano'.
 *
 * Model version                  : 13.16
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Tue May  5 16:51:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "AudioSmartSpeakerOnJetsonNano.h"
#include "AudioSmartSpeakerOnJetsonNano_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_mode.h"                  /* External mode header file */
#include "MW_nvidia_init.h"
#include "linuxTimeLogger.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int_T tid = *((int_T *) arg);
  int_T subRateId;
  subRateId = tid + 1;
  while (runModel) {
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)0;
    extmodeErrorCode_T extmodeError = EXTMODE_SUCCESS;
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    switch (subRateId) {
     case 0:
      extmodeTime = (extmodeSimulationTime_T)
        (((AudioSmartSpeakerOnJetsonNano_M->Timing.clockTick0 * 1) + 0));
      break;

     case 1:
      extmodeTime = (extmodeSimulationTime_T)
        (((AudioSmartSpeakerOnJetsonNano_M->Timing.clockTick1 * 10) + 0));
      break;
    }

    AudioSmartSpeakerOnJetsonNano_step(subRateId);

    /* Get model outputs here */
    extmodeError = extmodeEvent((extmodeEventId_T)(subRateId), extmodeTime);
    if (extmodeError != EXTMODE_SUCCESS) {
      /* Code to handle external mode event errors may be added here */
    }
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(AudioSmartSpeakerOnJetsonNano_M) == (NULL));
  while (runModel) {
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)0;
    extmodeErrorCode_T extmodeError = EXTMODE_SUCCESS;
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(AudioSmartSpeakerOnJetsonNano_M, 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    /* Run External Mode background activities */
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS && errorCode != EXTMODE_EMPTY) {
      /* Code to handle External Mode background task errors
         may be added here */
    }

    extmodeTime = (extmodeSimulationTime_T)
      (((AudioSmartSpeakerOnJetsonNano_M->Timing.clockTick0 * 1) + 0));
    AudioSmartSpeakerOnJetsonNano_step(0);

    /* Get model outputs here */
    extmodeError = extmodeEvent((extmodeEventId_T)(0), extmodeTime);
    if (extmodeError != EXTMODE_SUCCESS) {
      /* Code to handle external mode event errors may be added here */
    }

    stopRequested = !((rtmGetErrorStatus(AudioSmartSpeakerOnJetsonNano_M) ==
                       (NULL)));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(AudioSmartSpeakerOnJetsonNano_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  /* Terminate model */
  AudioSmartSpeakerOnJetsonNano_terminate();

  /* External Mode reset */
  extmodeReset();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
  subratePriority[0] = 39;
  mwNvidiaInit();
  rtmSetErrorStatus(AudioSmartSpeakerOnJetsonNano_M, 0);

  /* Parse External Mode command line arguments */
  errorCode = extmodeParseArgs(argc, (const char_T**)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  /* Initialize model */
  AudioSmartSpeakerOnJetsonNano_initialize();

  /* External Mode initialization */
  errorCode = extmodeInit(AudioSmartSpeakerOnJetsonNano_M->extModeInfo,
    (extmodeSimulationTime_T *)rteiGetPtrTFinalTicks
    (AudioSmartSpeakerOnJetsonNano_M->extModeInfo));
  if (errorCode != EXTMODE_SUCCESS) {
    return errorCode;
  }

  if (errorCode == EXTMODE_SUCCESS) {
    /* Wait until a Start or Stop Request has been received from the Host */
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(AudioSmartSpeakerOnJetsonNano_M, true);
    }
  }

  /* Call RTOS Initialization function */
  myRTOSInit(0.010000000000000002, 1);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
