/*
 * File: AudioSmartSpeakerOnJetsonNano_private.h
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

#ifndef AudioSmartSpeakerOnJetsonNano_private_h_
#define AudioSmartSpeakerOnJetsonNano_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "AudioSmartSpeakerOnJetsonNano_types.h"
#include "AudioSmartSpeakerOnJetsonNano.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_hypotf_snf(real32_T u0, real32_T u1);
extern void microKernel9307911276855274595(int32_T K, const real32_T *A, int32_T
  LDA, const real32_T *B, real32_T *C);
extern void microKernel2865182207653473102(int32_T K, const real32_T *A, int32_T
  LDA, const real32_T *B, real32_T *C);
extern void macroKernel10151223486748942243(int32_T M, int32_T K, int32_T N,
  const real32_T *A, int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C,
  int32_T LDC);
extern void matrixMultiply10151223486748942243(int32_T M, int32_T K, int32_T N,
  int32_T blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A,
  const real32_T *B, real32_T *C);
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

#endif                            /* AudioSmartSpeakerOnJetsonNano_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
