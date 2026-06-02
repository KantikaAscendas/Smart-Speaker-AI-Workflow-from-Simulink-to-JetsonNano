/*
 * File: AudioSmartSpeakerOnJetsonNano_types.h
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

#ifndef AudioSmartSpeakerOnJetsonNano_types_h_
#define AudioSmartSpeakerOnJetsonNano_types_h_
#include "rtwtypes.h"
#include "MW_sox_audio_reader.h"
#include "arm_math.h"
#include "arm_math_memory.h"
#include "arm_math_types.h"
#include "arm_math_types_f16.h"
#include "basic_math_functions.h"
#include "bayes_functions.h"
#include "complex_math_functions.h"
#include "controller_functions.h"
#include "distance_functions.h"
#include "fast_math_functions.h"
#include "filtering_functions.h"
#include "filtering_functions_f16.h"
#include "interpolation_functions.h"
#include "matrix_functions.h"
#include "mw_arm_sos_f32T.h"
#include "none.h"
#include "quaternion_math_functions.h"
#include "statistics_functions.h"
#include "support_functions.h"
#include "svm_defines.h"
#include "svm_functions.h"
#include "transform_functions.h"
#include "utils.h"
#ifndef DEFINED_TYPEDEF_FOR_SpeechCommands_
#define DEFINED_TYPEDEF_FOR_SpeechCommands_

typedef enum {
  Silence = 0,                         /* Default value */
  Background,
  Down,
  Go,
  Left,
  No,
  Off,
  On,
  Right,
  Stop,
  Up,
  Yes,
  Unknown
} SpeechCommands;

#endif

#ifndef struct_tag_YZEgE1A4RMVFscisV5hkDC
#define struct_tag_YZEgE1A4RMVFscisV5hkDC

struct tag_YZEgE1A4RMVFscisV5hkDC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_YZEgE1A4RMVFscisV5hkDC */

#ifndef typedef_nvidiacoder_common_NvidiaALSAAudioCapture_AudioSmartSpeakerOnJetsonNano_T
#define typedef_nvidiacoder_common_NvidiaALSAAudioCapture_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_YZEgE1A4RMVFscisV5hkDC
  nvidiacoder_common_NvidiaALSAAudioCapture_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_nvidiacoder_common_NvidiaALSAAudioCapture_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_onjZG390WjbhkYDzuipMME
#define struct_tag_onjZG390WjbhkYDzuipMME

struct tag_onjZG390WjbhkYDzuipMME
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_onjZG390WjbhkYDzuipMME */

#ifndef typedef_nvidiacoder_common_NvidiaALSAAudioPlayback_AudioSmartSpeakerOnJetsonNano_T
#define typedef_nvidiacoder_common_NvidiaALSAAudioPlayback_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_onjZG390WjbhkYDzuipMME
  nvidiacoder_common_NvidiaALSAAudioPlayback_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_nvidiacoder_common_NvidiaALSAAudioPlayback_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_iMbAOdDsVapj6RGELKgQbD
#define struct_tag_iMbAOdDsVapj6RGELKgQbD

struct tag_iMbAOdDsVapj6RGELKgQbD
{
  int32_T S0_isInitialized;
  real32_T W0_InBuf[21];
  int32_T W1_InBufIdx;
  int32_T W2_ModuloIdx;
  int32_T W3_PrevNumChan;
  real32_T P0_FILTER[9261];
  int32_T P1_PolyphaseSelector[441];
  int32_T P2_StartIdx[160];
  int32_T P3_StopIdx[160];
  int32_T P4_IndexSelector[441];
};

#endif                                 /* struct_tag_iMbAOdDsVapj6RGELKgQbD */

#ifndef typedef_b_dsp_FIRRateConverter_0_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_dsp_FIRRateConverter_0_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_iMbAOdDsVapj6RGELKgQbD
  b_dsp_FIRRateConverter_0_AudioSmartSpeakerOnJetsonNano_T;

#endif    /* typedef_b_dsp_FIRRateConverter_0_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_KWeu2W9L0QBZZXK7dXxG3C
#define struct_tag_KWeu2W9L0QBZZXK7dXxG3C

struct tag_KWeu2W9L0QBZZXK7dXxG3C
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRRateConverter_0_AudioSmartSpeakerOnJetsonNano_T cSFunObject;
};

#endif                                 /* struct_tag_KWeu2W9L0QBZZXK7dXxG3C */

#ifndef typedef_b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_KWeu2W9L0QBZZXK7dXxG3C
  b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T;

#endif      /* typedef_b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_MVpwmBpxAlHGresAb2xqVB
#define struct_tag_MVpwmBpxAlHGresAb2xqVB

struct tag_MVpwmBpxAlHGresAb2xqVB
{
  int32_T isInitialized;
  real_T Tau;
  real_T SampleRate;
  real_T currentGain;
  real_T muteState;
  real_T Ts;
};

#endif                                 /* struct_tag_MVpwmBpxAlHGresAb2xqVB */

#ifndef typedef_SmoothedMute_AudioSmartSpeakerOnJetsonNano_T
#define typedef_SmoothedMute_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_MVpwmBpxAlHGresAb2xqVB
  SmoothedMute_AudioSmartSpeakerOnJetsonNano_T;

#endif                /* typedef_SmoothedMute_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_ADpSx6syocBzJfHBE2L32E
#define struct_tag_ADpSx6syocBzJfHBE2L32E

struct tag_ADpSx6syocBzJfHBE2L32E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  sox_format_t * SoxFileHandle;
  boolean_T SoxInitialized;
  real_T LoopCount;
};

#endif                                 /* struct_tag_ADpSx6syocBzJfHBE2L32E */

#ifndef typedef_nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T
#define typedef_nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_ADpSx6syocBzJfHBE2L32E
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_0EEDcy9QoRjWSM1DUzl1pB
#define struct_tag_0EEDcy9QoRjWSM1DUzl1pB

struct tag_0EEDcy9QoRjWSM1DUzl1pB
{
  int32_T S0_isInitialized;
  real32_T W0_FILT_STATES[12];
  int32_T W1_PreviousNumChannels;
  real32_T P0_ICRTP;
};

#endif                                 /* struct_tag_0EEDcy9QoRjWSM1DUzl1pB */

#ifndef typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_0EEDcy9QoRjWSM1DUzl1pB
  b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_T;

#endif           /* typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_hWA8qZ3M3idmVXlHbe5pUF
#define struct_tag_hWA8qZ3M3idmVXlHbe5pUF

struct tag_hWA8qZ3M3idmVXlHbe5pUF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_T cSFunObject;
};

#endif                                 /* struct_tag_hWA8qZ3M3idmVXlHbe5pUF */

#ifndef typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_hWA8qZ3M3idmVXlHbe5pUF
  b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_T;

#endif             /* typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_T */

/* Custom Type definition for MATLAB Function: '<S12>/MLFB' */
#ifndef struct_tag_fN5pBFPZa6Op9iVxn0kEeG
#define struct_tag_fN5pBFPZa6Op9iVxn0kEeG

struct tag_fN5pBFPZa6Op9iVxn0kEeG
{
  real32_T Data[12];
};

#endif                                 /* struct_tag_fN5pBFPZa6Op9iVxn0kEeG */

#ifndef typedef_dlarray_1_AudioSmartSpeakerOnJetsonNano_T
#define typedef_dlarray_1_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_fN5pBFPZa6Op9iVxn0kEeG
  dlarray_1_AudioSmartSpeakerOnJetsonNano_T;

#endif                   /* typedef_dlarray_1_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_AudioSmartSpeakerOnJetsonNano_T
#define typedef_cell_wrap_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T;

#endif                   /* typedef_cell_wrap_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_2qjC9WsHFZHGz2KYgC1RbE
#define struct_tag_2qjC9WsHFZHGz2KYgC1RbE

struct tag_2qjC9WsHFZHGz2KYgC1RbE
{
  int32_T S0_isInitialized;
  real32_T W0_FILT_STATES[40];
  int32_T W1_PreviousNumChannels;
  arm_biquad_cascade_df2T_instance_f32 S;
  real32_T pState[40];
  real32_T coefficients[50];
  real32_T U1[30];
  real32_T U2[30];
};

#endif                                 /* struct_tag_2qjC9WsHFZHGz2KYgC1RbE */

#ifndef typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_d_T
#define typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_d_T

typedef struct tag_2qjC9WsHFZHGz2KYgC1RbE
  b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_d_T;

#endif         /* typedef_b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_d_T */

#ifndef struct_tag_0cKzrLQ7ZdxU40kn3z7OrB
#define struct_tag_0cKzrLQ7ZdxU40kn3z7OrB

struct tag_0cKzrLQ7ZdxU40kn3z7OrB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_SOSFilter_3_AudioSmartSpeakerOnJetsonNano_d_T cSFunObject;
};

#endif                                 /* struct_tag_0cKzrLQ7ZdxU40kn3z7OrB */

#ifndef typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_d_T
#define typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_d_T

typedef struct tag_0cKzrLQ7ZdxU40kn3z7OrB
  b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_d_T;

#endif           /* typedef_b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_d_T */

#ifndef struct_tag_oy8M31nNjaO7lCUgkHpFIH
#define struct_tag_oy8M31nNjaO7lCUgkHpFIH

struct tag_oy8M31nNjaO7lCUgkHpFIH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T pSampleRateInherit;
  real_T Threshold;
  real_T AttackTime;
  real_T ReleaseTime;
  real_T pNumChannels;
  real32_T pAlphaA;
  real32_T pAlphaR;
  real32_T pLevelDetectionState[2];
  real_T MakeUpGain;
  real_T KneeWidth;
  real32_T pMakeUpGain;
};

#endif                                 /* struct_tag_oy8M31nNjaO7lCUgkHpFIH */

#ifndef typedef_audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T
#define typedef_audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_oy8M31nNjaO7lCUgkHpFIH
  audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_4vfdbRDisNgBDKb5ilvU9C
#define struct_tag_4vfdbRDisNgBDKb5ilvU9C

struct tag_4vfdbRDisNgBDKb5ilvU9C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T inputVarSize;
  int32_T NumChannels;
  b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T *filt1;
  b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T coder_buffer_pobj0;
};

#endif                                 /* struct_tag_4vfdbRDisNgBDKb5ilvU9C */

#ifndef typedef_dsp_simulink_SampleRateConverter_AudioSmartSpeakerOnJetsonNano_T
#define typedef_dsp_simulink_SampleRateConverter_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_4vfdbRDisNgBDKb5ilvU9C
  dsp_simulink_SampleRateConverter_AudioSmartSpeakerOnJetsonNano_T;

#endif
  /* typedef_dsp_simulink_SampleRateConverter_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_RtMfRrkpmTYClbWOWZ8bt
#define struct_tag_RtMfRrkpmTYClbWOWZ8bt

struct tag_RtMfRrkpmTYClbWOWZ8bt
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T inputVarSize;
  real_T SampleRate;
  b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_d_T SOSFilterObj;
  real32_T NumMatrix[30];
  real32_T DenMatrix[30];
  real_T NumChannels;
  real_T privFrequencies[10];
  real_T privQualityFactors[10];
  real_T privPeakGains[10];
  boolean_T AreFiltersDesigned;
};

#endif                                 /* struct_tag_RtMfRrkpmTYClbWOWZ8bt */

#ifndef typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_RtMfRrkpmTYClbWOWZ8bt
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T;

#endif     /* typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_9eSP952j27vHugZeVUNwLD
#define struct_tag_9eSP952j27vHugZeVUNwLD

struct tag_9eSP952j27vHugZeVUNwLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T Gains[10];
  real_T SampleRate;
  boolean_T pIsGainInSync;
  real_T pGainCorrectionMatrix[100];
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *pMPEQ1;
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T coder_buffer_pobj0;
};

#endif                                 /* struct_tag_9eSP952j27vHugZeVUNwLD */

#ifndef typedef_b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T
#define typedef_b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_9eSP952j27vHugZeVUNwLD
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_kZjty0tvfzBUSuDXBx4JNB
#define struct_tag_kZjty0tvfzBUSuDXBx4JNB

struct tag_kZjty0tvfzBUSuDXBx4JNB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T inputVarSize;
  real_T pSampleRateDialog;
  real_T pNumChannels;
  real_T pGains[30];
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *pEQ;
  real_T Gain_31_5Hz;
  real_T Gain_63Hz;
  real_T Gain_125Hz;
  real_T Gain_250Hz;
  real_T Gain_500Hz;
  real_T Gain_1000Hz;
  real_T Gain_2000Hz;
  real_T Gain_4000Hz;
  real_T Gain_8000Hz;
  real_T Gain_16000Hz;
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T
    coder_buffer_pobj0;
};

#endif                                 /* struct_tag_kZjty0tvfzBUSuDXBx4JNB */

#ifndef typedef_audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T
#define typedef_audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_kZjty0tvfzBUSuDXBx4JNB
  audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T;

#endif    /* typedef_audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_ui1oiHRsFD1jfwgMjAOmLC
#define struct_tag_ui1oiHRsFD1jfwgMjAOmLC

struct tag_ui1oiHRsFD1jfwgMjAOmLC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T inputVarSize;
  real_T SampleRate;
  b_dsp_SOSFilter_AudioSmartSpeakerOnJetsonNano_T SOSFilterObj;
  real32_T NumMatrix[9];
  real32_T DenMatrix[9];
  real_T NumChannels;
  real_T privFrequencies[10];
  real_T privQualityFactors[10];
  real_T privPeakGains[10];
  boolean_T AreFiltersDesigned;
};

#endif                                 /* struct_tag_ui1oiHRsFD1jfwgMjAOmLC */

#ifndef typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_d_T
#define typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_d_T

typedef struct tag_ui1oiHRsFD1jfwgMjAOmLC
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_d_T;

#endif   /* typedef_b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_d_T */

#ifndef struct_tag_xbuFlbg5ScMEcJRu3AQCPH
#define struct_tag_xbuFlbg5ScMEcJRu3AQCPH

struct tag_xbuFlbg5ScMEcJRu3AQCPH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T pSampleRateDialog;
  real_T Frequencies[3];
  real_T QualityFactors[3];
  real_T PeakGains[3];
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_d_T pEQ;
};

#endif                                 /* struct_tag_xbuFlbg5ScMEcJRu3AQCPH */

#ifndef typedef_audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T
#define typedef_audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_xbuFlbg5ScMEcJRu3AQCPH
  audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T */

#ifndef struct_tag_CYZ41qSCL1o6vq5r1NLeeD
#define struct_tag_CYZ41qSCL1o6vq5r1NLeeD

struct tag_CYZ41qSCL1o6vq5r1NLeeD
{
  int32_T isInitialized;
  cell_wrap_AudioSmartSpeakerOnJetsonNano_T inputVarSize;
};

#endif                                 /* struct_tag_CYZ41qSCL1o6vq5r1NLeeD */

#ifndef typedef_audio_simulink_AuditorySpectrumExtractor_AudioSmartSpeakerOnJetsonNano_T
#define typedef_audio_simulink_AuditorySpectrumExtractor_AudioSmartSpeakerOnJetsonNano_T

typedef struct tag_CYZ41qSCL1o6vq5r1NLeeD
  audio_simulink_AuditorySpectrumExtractor_AudioSmartSpeakerOnJetsonNano_T;

#endif
/* typedef_audio_simulink_AuditorySpectrumExtractor_AudioSmartSpeakerOnJetsonNano_T */

/* Parameters (default storage) */
typedef struct P_AudioSmartSpeakerOnJetsonNano_T_
  P_AudioSmartSpeakerOnJetsonNano_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_AudioSmartSpeakerOnJetsonNano_T
  RT_MODEL_AudioSmartSpeakerOnJetsonNano_T;

#endif                              /* AudioSmartSpeakerOnJetsonNano_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
