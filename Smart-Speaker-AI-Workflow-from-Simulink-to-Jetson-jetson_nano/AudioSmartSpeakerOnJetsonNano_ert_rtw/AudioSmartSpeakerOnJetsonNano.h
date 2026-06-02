/*
 * File: AudioSmartSpeakerOnJetsonNano.h
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

#ifndef AudioSmartSpeakerOnJetsonNano_h_
#define AudioSmartSpeakerOnJetsonNano_h_
#ifndef AudioSmartSpeakerOnJetsonNano_COMMON_INCLUDES_
#define AudioSmartSpeakerOnJetsonNano_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                      /* AudioSmartSpeakerOnJetsonNano_COMMON_INCLUDES_ */

#include "AudioSmartSpeakerOnJetsonNano_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T obj_Data[34300];
  real_T MATLABSystem_o1[8820];        /* '<S3>/MATLAB System' */
  real_T dv[8820];
  real32_T b_obj_Data[12250];
  real32_T y[8822];
  int32_T buf[8820];
  real32_T xDB[8820];
  real32_T yG[8820];
  real32_T b[8820];
  real32_T MatrixConcatenate[8820];    /* '<Root>/Matrix Concatenate' */
  real32_T fv[8820];
  real32_T fv1[8820];
  real32_T U0[8820];
  real32_T fv2[8575];
  real32_T OutputBuffer[4900];         /* '<S10>/Output Buffer' */
  real32_T fv3[4900];
  real32_T inputsT_0_f1[4900];
  real32_T rtb_SampleRateConverter_m[4410];
  int16_T Cast1[8820];                 /* '<Root>/Cast1' */
  int16_T iv[8820];
  real32_T c_obj_Data[3575];
  real32_T fv4[3250];
  int32_T buf_c[1600];
  real32_T Gain[1600];
  real32_T fv5[1600];
  real32_T d_obj_Data[1183];
  real_T Volume;                       /* '<Root>/Volume Setting' */
  real_T Product[8820];                /* '<S4>/Product' */
  SpeechCommands Command;              /* '<S5>/MATLAB Function' */
  boolean_T Playing;                   /* '<Root>/Chart' */
} B_AudioSmartSpeakerOnJetsonNano_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_SampleRateConverter_AudioSmartSpeakerOnJetsonNano_T obj;/* '<Root>/Sample-Rate Converter' */
  audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T obj_e;/* '<S4>/Graphic EQ' */
  audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T obj_p;/* '<S4>/Multiband Parametric EQ' */
  audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T obj_m;/* '<S4>/Limiter' */
  SmoothedMute_AudioSmartSpeakerOnJetsonNano_T obj_i;/* '<S3>/MATLAB System' */
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T obj_po;/* '<S6>/Audio File Read6' */
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T obj_a;/* '<S6>/Audio File Read5' */
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T obj_ph;/* '<S6>/Audio File Read4' */
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T obj_k;/* '<S6>/Audio File Read' */
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T obj_l;/* '<S4>/Audio File Read1' */
  nvidiacoder_common_NvidiaALSAAudioCapture_AudioSmartSpeakerOnJetsonNano_T
    obj_ak;                            /* '<Root>/ALSA Audio Capture1' */
  nvidiacoder_common_NvidiaALSAAudioPlayback_AudioSmartSpeakerOnJetsonNano_T
    obj_lv;                            /* '<Root>/ALSA Audio Playback1' */
  real_T DiscreteFilter_states;        /* '<S2>/Discrete Filter' */
  real_T YBuffer[10];                  /* '<S5>/MATLAB Function' */
  real_T probBuffer[60];               /* '<S5>/MATLAB Function' */
  real32_T InputBuffer_CircBuf[3200];  /* '<S10>/Input Buffer' */
  real32_T OutputBuffer_CircBuf[9800]; /* '<S10>/Output Buffer' */
  int32_T InputBuffer_inBufPtrIdx;     /* '<S10>/Input Buffer' */
  int32_T InputBuffer_outBufPtrIdx;    /* '<S10>/Input Buffer' */
  int32_T OutputBuffer_inBufPtrIdx;    /* '<S10>/Output Buffer' */
  int32_T OutputBuffer_outBufPtrIdx;   /* '<S10>/Output Buffer' */
  uint32_T is_c5_AudioSmartSpeakerOnJetsonNano;/* '<Root>/Volume Setting' */
  uint32_T is_c1_AudioSmartSpeakerOnJetsonNano;/* '<Root>/Chart' */
  uint8_T is_active_c5_AudioSmartSpeakerOnJetsonNano;/* '<Root>/Volume Setting' */
  uint8_T temporalCounter_i1;          /* '<Root>/Volume Setting' */
  uint8_T is_active_c1_AudioSmartSpeakerOnJetsonNano;/* '<Root>/Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<S12>/MLFB' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S5>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S10>/Multi-Channel Reshaper' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S4>/db2mag' */
  boolean_T isInitialized;             /* '<S4>/Multiband Parametric EQ' */
  boolean_T isInitialized_i;           /* '<S4>/Multiband Parametric EQ' */
  boolean_T isInitialized_e;           /* '<S4>/Graphic EQ' */
  boolean_T isInitialized_n;           /* '<S4>/Graphic EQ' */
  boolean_T isInitialized_d;           /* '<Root>/Sample-Rate Converter' */
} DW_AudioSmartSpeakerOnJetsonNano_T;

/* Parameters (default storage) */
struct P_AudioSmartSpeakerOnJetsonNano_T_ {
  real_T GraphicEQ_Gain_1000;          /* Mask Parameter: GraphicEQ_Gain_1000
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_125;           /* Mask Parameter: GraphicEQ_Gain_125
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_16000;         /* Mask Parameter: GraphicEQ_Gain_16000
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_2000;          /* Mask Parameter: GraphicEQ_Gain_2000
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_250;           /* Mask Parameter: GraphicEQ_Gain_250
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_31_5;          /* Mask Parameter: GraphicEQ_Gain_31_5
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_4000;          /* Mask Parameter: GraphicEQ_Gain_4000
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_500;           /* Mask Parameter: GraphicEQ_Gain_500
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_63;            /* Mask Parameter: GraphicEQ_Gain_63
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T GraphicEQ_Gain_8000;          /* Mask Parameter: GraphicEQ_Gain_8000
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T SmoothedMute_tau;             /* Mask Parameter: SmoothedMute_tau
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T MATLABSystem_SampleRate;      /* Expression: 44100
                                        * Referenced by: '<S3>/MATLAB System'
                                        */
  real_T GraphicEQ_SampleRate;         /* Expression: SampleRate
                                        * Referenced by: '<S4>/Graphic EQ'
                                        */
  real_T Limiter_Threshold;            /* Expression: -6.500
                                        * Referenced by: '<S4>/Limiter'
                                        */
  real_T Limiter_KneeWidth;            /* Expression: 0.0
                                        * Referenced by: '<S4>/Limiter'
                                        */
  real_T Limiter_AttackTime;           /* Expression: 0.0
                                        * Referenced by: '<S4>/Limiter'
                                        */
  real_T Limiter_ReleaseTime;          /* Expression: 0.2
                                        * Referenced by: '<S4>/Limiter'
                                        */
  real_T Limiter_MakeUpGain;           /* Expression: 0.0
                                        * Referenced by: '<S4>/Limiter'
                                        */
  real_T MultibandParametricEQ_Frequencies[3];/* Expression: Frequencies
                                               * Referenced by: '<S4>/Multiband Parametric EQ'
                                               */
  real_T MultibandParametricEQ_QualityFactors[3];/* Expression: QualityFactors
                                                  * Referenced by: '<S4>/Multiband Parametric EQ'
                                                  */
  real_T MultibandParametricEQ_PeakGains[3];/* Expression: PeakGains
                                             * Referenced by: '<S4>/Multiband Parametric EQ'
                                             */
  real_T MultibandParametricEQ_SampleRate;/* Expression: SampleRate
                                           * Referenced by: '<S4>/Multiband Parametric EQ'
                                           */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  real_T Volume2dB_tableData[12];
                   /* Expression: [-70,-60,-50,-40,-35,-30,-25,-20,-15,-10,-5,0]
                    * Referenced by: '<S4>/Volume2dB'
                    */
  real_T Volume2dB_bp01Data[12];       /* Expression: [1:12]
                                        * Referenced by: '<S4>/Volume2dB'
                                        */
  real_T DiscreteFilter_NumCoef;       /* Expression: 0.02322/0.2
                                        * Referenced by: '<S2>/Discrete Filter'
                                        */
  real_T DiscreteFilter_DenCoef[2];    /* Expression: [1 (0.02322/0.2 -1)]
                                        * Referenced by: '<S2>/Discrete Filter'
                                        */
  real_T DiscreteFilter_InitialStates; /* Expression: 0
                                        * Referenced by: '<S2>/Discrete Filter'
                                        */
  real_T Word_Value;                   /* Expression: 5
                                        * Referenced by: '<Root>/Word'
                                        */
  real_T Multiply2_Gain;               /* Expression: 2^15
                                        * Referenced by: '<Root>/Multiply2'
                                        */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S4>/Multiply'
                                        */
  real32_T InputBuffer_ic;             /* Computed Parameter: InputBuffer_ic
                                        * Referenced by: '<S10>/Input Buffer'
                                        */
  real32_T OutputBuffer_ic;            /* Computed Parameter: OutputBuffer_ic
                                        * Referenced by: '<S10>/Output Buffer'
                                        */
  real32_T AddConstant_Bias;           /* Expression: single(1e-6)
                                        * Referenced by: '<S5>/Add Constant'
                                        */
  real32_T Multiply_Gain_o;            /* Computed Parameter: Multiply_Gain_o
                                        * Referenced by: '<Root>/Multiply'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S8>/Gain'
                                        */
  int16_T Constant_Value[1600]; /* Expression: int16(zeros(frameLengthSpeech,1))
                                 * Referenced by: '<S6>/Constant'
                                 */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_AudioSmartSpeakerOnJetsonNano_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_P;

/* Block signals (default storage) */
extern B_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_B;

/* Block states (default storage) */
extern DW_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_DW;

/* External function called from main */
extern void AudioSmartSpeakerOnJetsonNano_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void AudioSmartSpeakerOnJetsonNano_initialize(void);
extern void AudioSmartSpeakerOnJetsonNano_step0(void);/* Sample time: [0.01s, 0.0s] */
extern void AudioSmartSpeakerOnJetsonNano_step1(void);/* Sample time: [0.1s, 0.0s] */
extern void AudioSmartSpeakerOnJetsonNano_step(int_T tid);
extern void AudioSmartSpeakerOnJetsonNano_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AudioSmartSpeakerOnJetsonNano_T *const
  AudioSmartSpeakerOnJetsonNano_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AudioSmartSpeakerOnJetsonNano'
 * '<S1>'   : 'AudioSmartSpeakerOnJetsonNano/Chart'
 * '<S2>'   : 'AudioSmartSpeakerOnJetsonNano/Smooth'
 * '<S3>'   : 'AudioSmartSpeakerOnJetsonNano/Smoothed Mute'
 * '<S4>'   : 'AudioSmartSpeakerOnJetsonNano/Speaker Output Processing '
 * '<S5>'   : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer'
 * '<S6>'   : 'AudioSmartSpeakerOnJetsonNano/Voice Command'
 * '<S7>'   : 'AudioSmartSpeakerOnJetsonNano/Volume Setting'
 * '<S8>'   : 'AudioSmartSpeakerOnJetsonNano/dB Gain'
 * '<S9>'   : 'AudioSmartSpeakerOnJetsonNano/Speaker Output Processing /db2mag'
 * '<S10>'  : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer/Compute Spectrogram'
 * '<S11>'  : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer/MATLAB Function'
 * '<S12>'  : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer/Predict'
 * '<S13>'  : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer/Compute Spectrogram/Multi-Channel Reshaper'
 * '<S14>'  : 'AudioSmartSpeakerOnJetsonNano/Speech Command Recognizer/Predict/MLFB'
 */
#endif                                 /* AudioSmartSpeakerOnJetsonNano_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
