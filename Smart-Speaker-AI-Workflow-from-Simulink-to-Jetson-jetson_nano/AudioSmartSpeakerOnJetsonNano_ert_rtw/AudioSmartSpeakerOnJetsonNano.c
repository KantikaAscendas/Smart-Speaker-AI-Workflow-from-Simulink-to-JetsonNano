/*
 * File: AudioSmartSpeakerOnJetsonNano.c
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

#include "AudioSmartSpeakerOnJetsonNano.h"
#include "MW_alsa_audio.h"
#include "AudioSmartSpeakerOnJetsonNano_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "AudioSmartSpeakerOnJetsonNano_private.h"
#include "arm_math_memory.h"
#include "arm_math_types.h"
#include "basic_math_functions.h"
#include "complex_math_functions.h"
#include "fast_math_functions.h"
#include "mw_cmsis.h"
#include "none.h"
#include "utils.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "NEMath.h"
#include "arm_common_tables.h"
#include "arm_helium_utils.h"
#include "arm_math.h"
#include "arm_vec_math.h"
#include "bayes_functions.h"
#include "controller_functions.h"
#include "distance_functions.h"
#include "filtering_functions.h"
#include "interpolation_functions.h"
#include "matrix_functions.h"
#include "mw_cmsis_impl_cortexa.h"
#include "quaternion_math_functions.h"
#include "statistics_functions.h"
#include "support_functions.h"
#include "svm_defines.h"
#include "svm_functions.h"
#include "transform_functions.h"
#include "window_functions.h"
#include "MW_sox_audio_reader.h"
#include "arm_math_types_f16.h"
#include "filtering_functions_f16.h"
#include "mw_arm_sos_f32T.h"

/* Named constants for Chart: '<Root>/Chart' */
#define AudioSmartSpeakerOnJetsonNano_IN_Off (1U)
#define AudioSmartSpeakerOnJetsonNano_IN_Playing (2U)

/* Named constants for Chart: '<Root>/Volume Setting' */
#define AudioSmartSpeakerOnJetsonNano_IN_DecrementVolume (1U)
#define AudioSmartSpeakerOnJetsonNano_IN_IncrementVolume (2U)
#define AudioSmartSpeakerOnJetsonNano_IN_VolumeSteady (3U)

/* Block signals (default storage) */
B_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_B;

/* Block states (default storage) */
DW_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_DW;

/* Real-time model */
static RT_MODEL_AudioSmartSpeakerOnJetsonNano_T AudioSmartSpeakerOnJetsonNano_M_;
RT_MODEL_AudioSmartSpeakerOnJetsonNano_T *const AudioSmartSpeakerOnJetsonNano_M =
  &AudioSmartSpeakerOnJetsonNano_M_;

/* Forward declaration for local functions */
static void
  AudioSmartSpeakerOnJetsonNano_FFTImplementationCallback_doHalfLengthRadix2(
  const real32_T x[400], int32_T xoffInit, creal32_T y[512]);
static void AudioSmartSpeakerOnJetsonNano_convolutionKernel(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr);
static void AudioSmartSpeakerOnJetsonNano_convolution(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor);
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor(const
  real32_T X[4900], real32_T Z[34300]);
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict(const real32_T
  X_Data[34300], real32_T Z_Data[8575]);
static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_d(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr);
static void AudioSmartSpeakerOnJetsonNano_convolution_d(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor);
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d(const
  real32_T X[8575], real32_T Z[12250]);
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_h(const
  real32_T X_Data[12250], real32_T Z_Data[3250]);
static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_du(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr);
static void AudioSmartSpeakerOnJetsonNano_convolution_du(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor);
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3(const
  real32_T X[3250], real32_T Z[3575]);
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf(const
  real32_T X_Data[3575], real32_T Z_Data[1001]);
static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_duj(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr);
static void AudioSmartSpeakerOnJetsonNano_convolution_duj(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor);
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3f(
  const real32_T X[1001], real32_T Z[1001]);
static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_dujn(const real32_T *
  inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr);
static void AudioSmartSpeakerOnJetsonNano_convolution_dujn(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor);
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3fr(
  const real32_T X[1001], real32_T Z[1183]);
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf4(const
  real32_T X_Data[1183], real32_T Z_Data[91]);
static void AudioSmartSpeakerOnJetsonNano_SoftmaxLayer_predict(const real32_T
  X1_Data[12], real32_T Z1_Data[12]);
static void AudioSmartSpeakerOnJetsonNano_predict(const real32_T inputsT_0_f1
  [4900], real32_T outputs_0_f1[12]);
static void AudioSmartSpeakerOnJetsonNano_merge(int32_T idx[10], real_T x[10],
  int32_T offset, int32_T np, int32_T nq, int32_T iwork[10], real_T xwork[10]);
static void AudioSmartSpeakerOnJetsonNano_sort(real_T x[10]);
static void AudioSmartSpeakerOnJetsonNano_graphicEQ_setGainsToEQ
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj);
static void AudioSmartSpeakerOnJetsonNano_findHelper(const boolean_T x_data[],
  int32_T i_data[], int32_T *i_size);
static void AudioSmartSpeakerOnJetsonNano_designBandPassOctaveFilter(real32_T w0,
  real32_T BW, real32_T G, real32_T GB, real32_T B_data[], int32_T B_size[2],
  real32_T A_data[], int32_T A_size[2]);
static void AudioSmartSpeakerOnJetsonNano_all(const boolean_T x_data[],
  boolean_T y[2]);
static void AudioSmartSpeakerOnJetsonNano_designEachParamEQ(real32_T G, real32_T
  w0, real32_T BW, real32_T B_data[], int32_T B_size[2], real32_T A_data[],
  int32_T A_size[2]);
static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ(const
  real_T Wo[10], const real_T Q[10], real_T Fs, real32_T B[30], real32_T A[30]);
static void AudioSmartSpeakerOnJetsonNano_exp(const creal_T x_data[], const
  int32_T x_size[2], creal_T b_x_data[], int32_T b_x_size[2]);
static void AudioSmartSpeakerOnJetsonNano_binary_expand_op(creal32_T in1_data[],
  int32_T in1_size[2], const creal_T in2_data[], const int32_T in2_size[2],
  const real32_T in3[30], int32_T in4, int32_T in5);
static void AudioSmartSpeakerOnJetsonNano_binary_expand_op_2(creal32_T in1_data[],
  const int32_T in1_size[2], int32_T in2, int32_T in3, int32_T in4, const
  creal32_T in5_data[], const int32_T in5_size[2], const creal32_T in6_data[],
  const int32_T in6_size[2]);
static void AudioSmartSpeakerOnJetsonNano_inv(const real32_T x_data[], const
  int32_T x_size[2], real32_T y_data[], int32_T y_size[2]);
static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_d
  (real32_T Wo[10], const real_T G[10], const real_T Q[10], real32_T Fs,
   real32_T B[30], real32_T A[30]);
static void AudioSmartSpeakerOnJetsonNano_SystemCore_setup
  (b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *obj);
static void AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients(const
  real32_T u2[30], const real32_T u3[30], real32_T y[50]);
static void AudioSmartSpeakerOnJetsonNano_graphicEQ_stepImpl
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj, const real32_T
   u[8820], real32_T y[8820]);
static void AudioSmartSpeakerOnJetsonNano_SystemCore_step
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj, const real32_T
   varargin_1[8820], real32_T varargout_1[8820]);
static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_du
  (real32_T Wo[10], const real_T G[10], const real_T Q[10], real32_T Fs,
   real32_T B[9], real32_T A[9]);
static void AudioSmartSpeakerOnJetsonNano_SystemCore_step_d
  (audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj,
   const real32_T varargin_1[8820], real32_T varargout_1[8820]);
static void AudioSmartSpeakerOnJetsonNano_GraphicEQ_GraphicEQ
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj);
static void AudioSmartSpeakerOnJetsonNano_CompressorBase_setupImpl
  (audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T *obj);
static void rate_monotonic_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)/*MW:OvOk*/ numerator + 1U :
      (uint32_T)numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)/*MW:OvOk*/ denominator + 1U :
      (uint32_T)denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -/*MW:OvOk*/ ((int32_T)tempAbsQuotient) :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void AudioSmartSpeakerOnJetsonNano_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(AudioSmartSpeakerOnJetsonNano_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AudioSmartSpeakerOnJetsonNano_M->Timing.TaskCounters.TID[1])++;
  if ((AudioSmartSpeakerOnJetsonNano_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    AudioSmartSpeakerOnJetsonNano_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void
  AudioSmartSpeakerOnJetsonNano_FFTImplementationCallback_doHalfLengthRadix2(
  const real32_T x[400], int32_T xoffInit, creal32_T y[512])
{
  int32_T i;
  int32_T iDelta;
  int32_T iDelta2;
  int32_T iheight;
  int32_T ihi;
  int32_T istart;
  int32_T j;
  int32_T k;
  int32_T temp_re_tmp;
  real32_T temp2_im;
  real32_T temp2_re;
  real32_T temp_im;
  real32_T temp_re;
  real32_T temp_re_tmp_0;
  real32_T tmp;
  real32_T y_im_tmp;
  real32_T y_im_tmp_0;
  int16_T bitrevIndex;
  static const int16_T bitrevIndex_0[256] = { 1, 129, 65, 193, 33, 161, 97, 225,
    17, 145, 81, 209, 49, 177, 113, 241, 9, 137, 73, 201, 41, 169, 105, 233, 25,
    153, 89, 217, 57, 185, 121, 249, 5, 133, 69, 197, 37, 165, 101, 229, 21, 149,
    85, 213, 53, 181, 117, 245, 13, 141, 77, 205, 45, 173, 109, 237, 29, 157, 93,
    221, 61, 189, 125, 253, 3, 131, 67, 195, 35, 163, 99, 227, 19, 147, 83, 211,
    51, 179, 115, 243, 11, 139, 75, 203, 43, 171, 107, 235, 27, 155, 91, 219, 59,
    187, 123, 251, 7, 135, 71, 199, 39, 167, 103, 231, 23, 151, 87, 215, 55, 183,
    119, 247, 15, 143, 79, 207, 47, 175, 111, 239, 31, 159, 95, 223, 63, 191,
    127, 255, 2, 130, 66, 194, 34, 162, 98, 226, 18, 146, 82, 210, 50, 178, 114,
    242, 10, 138, 74, 202, 42, 170, 106, 234, 26, 154, 90, 218, 58, 186, 122,
    250, 6, 134, 70, 198, 38, 166, 102, 230, 22, 150, 86, 214, 54, 182, 118, 246,
    14, 142, 78, 206, 46, 174, 110, 238, 30, 158, 94, 222, 62, 190, 126, 254, 4,
    132, 68, 196, 36, 164, 100, 228, 20, 148, 84, 212, 52, 180, 116, 244, 12,
    140, 76, 204, 44, 172, 108, 236, 28, 156, 92, 220, 60, 188, 124, 252, 8, 136,
    72, 200, 40, 168, 104, 232, 24, 152, 88, 216, 56, 184, 120, 248, 16, 144, 80,
    208, 48, 176, 112, 240, 32, 160, 96, 224, 64, 192, 128, 256 };

  static const real32_T tmp_0[128] = { 1.0F, 0.9996988F, 0.99879545F,
    0.99729043F, 0.9951847F, 0.99247956F, 0.9891765F, 0.98527765F, 0.98078525F,
    0.9757021F, 0.97003126F, 0.96377605F, 0.95694035F, 0.94952816F, 0.94154406F,
    0.9329928F, 0.9238795F, 0.9142097F, 0.9039893F, 0.8932243F, 0.88192123F,
    0.87008697F, 0.8577286F, 0.8448536F, 0.8314696F, 0.8175848F, 0.8032075F,
    0.7883464F, 0.77301043F, 0.7572088F, 0.7409511F, 0.7242471F, 0.70710677F,
    0.68954057F, 0.671559F, 0.65317285F, 0.63439333F, 0.61523163F, 0.5956993F,
    0.5758082F, 0.55557024F, 0.53499764F, 0.51410276F, 0.49289823F, 0.47139674F,
    0.44961134F, 0.42755508F, 0.40524134F, 0.38268346F, 0.35989505F, 0.33688986F,
    0.31368175F, 0.29028466F, 0.26671278F, 0.2429802F, 0.21910124F, 0.19509032F,
    0.1709619F, 0.14673047F, 0.12241068F, 0.09801714F, 0.07356457F, 0.049067676F,
    0.024541229F, 0.0F, -0.024541229F, -0.049067676F, -0.07356457F, -0.09801714F,
    -0.12241068F, -0.14673047F, -0.1709619F, -0.19509032F, -0.21910124F,
    -0.2429802F, -0.26671278F, -0.29028466F, -0.31368175F, -0.33688986F,
    -0.35989505F, -0.38268346F, -0.40524134F, -0.42755508F, -0.44961134F,
    -0.47139674F, -0.49289823F, -0.51410276F, -0.53499764F, -0.55557024F,
    -0.5758082F, -0.5956993F, -0.61523163F, -0.63439333F, -0.65317285F,
    -0.671559F, -0.68954057F, -0.70710677F, -0.7242471F, -0.7409511F,
    -0.7572088F, -0.77301043F, -0.7883464F, -0.8032075F, -0.8175848F,
    -0.8314696F, -0.8448536F, -0.8577286F, -0.87008697F, -0.88192123F,
    -0.8932243F, -0.9039893F, -0.9142097F, -0.9238795F, -0.9329928F,
    -0.94154406F, -0.94952816F, -0.95694035F, -0.96377605F, -0.97003126F,
    -0.9757021F, -0.98078525F, -0.98527765F, -0.9891765F, -0.99247956F,
    -0.9951847F, -0.99729043F, -0.99879545F, -0.9996988F };

  static const real32_T tmp_1[128] = { 0.0F, -0.024541229F, -0.049067676F,
    -0.07356457F, -0.09801714F, -0.12241068F, -0.14673047F, -0.1709619F,
    -0.19509032F, -0.21910124F, -0.2429802F, -0.26671278F, -0.29028466F,
    -0.31368175F, -0.33688986F, -0.35989505F, -0.38268346F, -0.40524134F,
    -0.42755508F, -0.44961134F, -0.47139674F, -0.49289823F, -0.51410276F,
    -0.53499764F, -0.55557024F, -0.5758082F, -0.5956993F, -0.61523163F,
    -0.63439333F, -0.65317285F, -0.671559F, -0.68954057F, -0.70710677F,
    -0.7242471F, -0.7409511F, -0.7572088F, -0.77301043F, -0.7883464F,
    -0.8032075F, -0.8175848F, -0.8314696F, -0.8448536F, -0.8577286F,
    -0.87008697F, -0.88192123F, -0.8932243F, -0.9039893F, -0.9142097F,
    -0.9238795F, -0.9329928F, -0.94154406F, -0.94952816F, -0.95694035F,
    -0.96377605F, -0.97003126F, -0.9757021F, -0.98078525F, -0.98527765F,
    -0.9891765F, -0.99247956F, -0.9951847F, -0.99729043F, -0.99879545F,
    -0.9996988F, -1.0F, -0.9996988F, -0.99879545F, -0.99729043F, -0.9951847F,
    -0.99247956F, -0.9891765F, -0.98527765F, -0.98078525F, -0.9757021F,
    -0.97003126F, -0.96377605F, -0.95694035F, -0.94952816F, -0.94154406F,
    -0.9329928F, -0.9238795F, -0.9142097F, -0.9039893F, -0.8932243F,
    -0.88192123F, -0.87008697F, -0.8577286F, -0.8448536F, -0.8314696F,
    -0.8175848F, -0.8032075F, -0.7883464F, -0.77301043F, -0.7572088F,
    -0.7409511F, -0.7242471F, -0.70710677F, -0.68954057F, -0.671559F,
    -0.65317285F, -0.63439333F, -0.61523163F, -0.5956993F, -0.5758082F,
    -0.55557024F, -0.53499764F, -0.51410276F, -0.49289823F, -0.47139674F,
    -0.44961134F, -0.42755508F, -0.40524134F, -0.38268346F, -0.35989505F,
    -0.33688986F, -0.31368175F, -0.29028466F, -0.26671278F, -0.2429802F,
    -0.21910124F, -0.19509032F, -0.1709619F, -0.14673047F, -0.12241068F,
    -0.09801714F, -0.07356457F, -0.049067676F, -0.024541229F };

  static const int16_T tmp_2[256] = { 1, 256, 255, 254, 253, 252, 251, 250, 249,
    248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234,
    233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219,
    218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204,
    203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189,
    188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174,
    173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159,
    158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144,
    143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129,
    128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114,
    113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98,
    97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79,
    78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60,
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
    40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22,
    21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

  static const creal32_T reconVar1[256] = { { 1.0F,/* re */
      -1.0F                            /* im */
    }, { 0.9877285F,                   /* re */
      -0.9999247F                      /* im */
    }, { 0.97545874F,                  /* re */
      -0.9996988F                      /* im */
    }, { 0.96319276F,                  /* re */
      -0.9993224F                      /* im */
    }, { 0.9509323F,                   /* re */
      -0.99879545F                     /* im */
    }, { 0.9386793F,                   /* re */
      -0.9981181F                      /* im */
    }, { 0.9264354F,                   /* re */
      -0.99729043F                     /* im */
    }, { 0.9142027F,                   /* re */
      -0.9963126F                      /* im */
    }, { 0.90198284F,                  /* re */
      -0.9951847F                      /* im */
    }, { 0.8897778F,                   /* re */
      -0.993907F                       /* im */
    }, { 0.87758934F,                  /* re */
      -0.99247956F                     /* im */
    }, { 0.86541927F,                  /* re */
      -0.99090266F                     /* im */
    }, { 0.8532695F,                   /* re */
      -0.9891765F                      /* im */
    }, { 0.8411418F,                   /* re */
      -0.9873014F                      /* im */
    }, { 0.8290381F,                   /* re */
      -0.98527765F                     /* im */
    }, { 0.8169601F,                   /* re */
      -0.9831055F                      /* im */
    }, { 0.8049097F,                   /* re */
      -0.98078525F                     /* im */
    }, { 0.79288864F,                  /* re */
      -0.9783174F                      /* im */
    }, { 0.78089875F,                  /* re */
      -0.9757021F                      /* im */
    }, { 0.7689419F,                   /* re */
      -0.97293997F                     /* im */
    }, { 0.7570198F,                   /* re */
      -0.97003126F                     /* im */
    }, { 0.74513435F,                  /* re */
      -0.96697646F                     /* im */
    }, { 0.7332872F,                   /* re */
      -0.96377605F                     /* im */
    }, { 0.7214803F,                   /* re */
      -0.9604305F                      /* im */
    }, { 0.70971537F,                  /* re */
      -0.95694035F                     /* im */
    }, { 0.69799405F,                  /* re */
      -0.953306F                       /* im */
    }, { 0.6863183F,                   /* re */
      -0.94952816F                     /* im */
    }, { 0.67468965F,                  /* re */
      -0.9456073F                      /* im */
    }, { 0.66311014F,                  /* re */
      -0.94154406F                     /* im */
    }, { 0.6515813F,                   /* re */
      -0.937339F                       /* im */
    }, { 0.64010495F,                  /* re */
      -0.9329928F                      /* im */
    }, { 0.6286828F,                   /* re */
      -0.9285061F                      /* im */
    }, { 0.61731654F,                  /* re */
      -0.9238795F                      /* im */
    }, { 0.60600793F,                  /* re */
      -0.9191139F                      /* im */
    }, { 0.5947586F,                   /* re */
      -0.9142097F                      /* im */
    }, { 0.5835704F,                   /* re */
      -0.90916795F                     /* im */
    }, { 0.5724449F,                   /* re */
      -0.9039893F                      /* im */
    }, { 0.5613837F,                   /* re */
      -0.8986745F                      /* im */
    }, { 0.5503887F,                   /* re */
      -0.8932243F                      /* im */
    }, { 0.53946126F,                  /* re */
      -0.88763964F                     /* im */
    }, { 0.52860326F,                  /* re */
      -0.88192123F                     /* im */
    }, { 0.51781625F,                  /* re */
      -0.8760701F                      /* im */
    }, { 0.5071018F,                   /* re */
      -0.87008697F                     /* im */
    }, { 0.49646163F,                  /* re */
      -0.86397284F                     /* im */
    }, { 0.48589724F,                  /* re */
      -0.8577286F                      /* im */
    }, { 0.47541028F,                  /* re */
      -0.8513552F                      /* im */
    }, { 0.46500236F,                  /* re */
      -0.8448536F                      /* im */
    }, { 0.45467496F,                  /* re */
      -0.8382247F                      /* im */
    }, { 0.44442976F,                  /* re */
      -0.8314696F                      /* im */
    }, { 0.43426818F,                  /* re */
      -0.82458925F                     /* im */
    }, { 0.42419177F,                  /* re */
      -0.8175848F                      /* im */
    }, { 0.4142021F,                   /* re */
      -0.81045717F                     /* im */
    }, { 0.4043007F,                   /* re */
      -0.8032075F                      /* im */
    }, { 0.394489F,                    /* re */
      -0.7958369F                      /* im */
    }, { 0.38476837F,                  /* re */
      -0.7883464F                      /* im */
    }, { 0.3751405F,                   /* re */
      -0.7807372F                      /* im */
    }, { 0.36560667F,                  /* re */
      -0.77301043F                     /* im */
    }, { 0.35616845F,                  /* re */
      -0.76516724F                     /* im */
    }, { 0.34682715F,                  /* re */
      -0.7572088F                      /* im */
    }, { 0.3375842F,                   /* re */
      -0.7491364F                      /* im */
    }, { 0.32844102F,                  /* re */
      -0.7409511F                      /* im */
    }, { 0.319399F,                    /* re */
      -0.7326543F                      /* im */
    }, { 0.31045943F,                  /* re */
      -0.7242471F                      /* im */
    }, { 0.3016237F,                   /* re */
      -0.7157308F                      /* im */
    }, { 0.29289323F,                  /* re */
      -0.70710677F                     /* im */
    }, { 0.2842692F,                   /* re */
      -0.6983763F                      /* im */
    }, { 0.2757529F,                   /* re */
      -0.68954057F                     /* im */
    }, { 0.26734573F,                  /* re */
      -0.680601F                       /* im */
    }, { 0.25904888F,                  /* re */
      -0.671559F                       /* im */
    }, { 0.2508636F,                   /* re */
      -0.6624158F                      /* im */
    }, { 0.24279118F,                  /* re */
      -0.65317285F                     /* im */
    }, { 0.23483276F,                  /* re */
      -0.64383155F                     /* im */
    }, { 0.22698957F,                  /* re */
      -0.63439333F                     /* im */
    }, { 0.21926278F,                  /* re */
      -0.6248595F                      /* im */
    }, { 0.21165359F,                  /* re */
      -0.61523163F                     /* im */
    }, { 0.20416307F,                  /* re */
      -0.605511F                       /* im */
    }, { 0.19679248F,                  /* re */
      -0.5956993F                      /* im */
    }, { 0.18954283F,                  /* re */
      -0.5857979F                      /* im */
    }, { 0.18241519F,                  /* re */
      -0.5758082F                      /* im */
    }, { 0.17541075F,                  /* re */
      -0.5657318F                      /* im */
    }, { 0.1685304F,                   /* re */
      -0.55557024F                     /* im */
    }, { 0.16177529F,                  /* re */
      -0.54532504F                     /* im */
    }, { 0.15514642F,                  /* re */
      -0.53499764F                     /* im */
    }, { 0.1486448F,                   /* re */
      -0.5245897F                      /* im */
    }, { 0.1422714F,                   /* re */
      -0.51410276F                     /* im */
    }, { 0.13602716F,                  /* re */
      -0.50353837F                     /* im */
    }, { 0.12991303F,                  /* re */
      -0.49289823F                     /* im */
    }, { 0.12392992F,                  /* re */
      -0.48218375F                     /* im */
    }, { 0.11807877F,                  /* re */
      -0.47139674F                     /* im */
    }, { 0.11236036F,                  /* re */
      -0.46053872F                     /* im */
    }, { 0.1067757F,                   /* re */
      -0.44961134F                     /* im */
    }, { 0.10132551F,                  /* re */
      -0.43861625F                     /* im */
    }, { 0.096010685F,                 /* re */
      -0.42755508F                     /* im */
    }, { 0.090832055F,                 /* re */
      -0.41642958F                     /* im */
    }, { 0.08579028F,                  /* re */
      -0.40524134F                     /* im */
    }, { 0.080886126F,                 /* re */
      -0.39399207F                     /* im */
    }, { 0.076120496F,                 /* re */
      -0.38268346F                     /* im */
    }, { 0.07149392F,                  /* re */
      -0.3713172F                      /* im */
    }, { 0.067007184F,                 /* re */
      -0.35989505F                     /* im */
    }, { 0.06266099F,                  /* re */
      -0.34841868F                     /* im */
    }, { 0.058455944F,                 /* re */
      -0.33688986F                     /* im */
    }, { 0.054392695F,                 /* re */
      -0.32531032F                     /* im */
    }, { 0.050471842F,                 /* re */
      -0.31368175F                     /* im */
    }, { 0.04669398F,                  /* re */
      -0.30200595F                     /* im */
    }, { 0.043059647F,                 /* re */
      -0.29028466F                     /* im */
    }, { 0.039569497F,                 /* re */
      -0.2785197F                      /* im */
    }, { 0.036223948F,                 /* re */
      -0.26671278F                     /* im */
    }, { 0.033023536F,                 /* re */
      -0.25486568F                     /* im */
    }, { 0.029968739F,                 /* re */
      -0.2429802F                      /* im */
    }, { 0.027060032F,                 /* re */
      -0.23105812F                     /* im */
    }, { 0.024297893F,                 /* re */
      -0.21910124F                     /* im */
    }, { 0.02168262F,                  /* re */
      -0.20711139F                     /* im */
    }, { 0.01921475F,                  /* re */
      -0.19509032F                     /* im */
    }, { 0.01689452F,                  /* re */
      -0.18303989F                     /* im */
    }, { 0.014722347F,                 /* re */
      -0.1709619F                      /* im */
    }, { 0.012698591F,                 /* re */
      -0.15885815F                     /* im */
    }, { 0.010823488F,                 /* re */
      -0.14673047F                     /* im */
    }, { 0.009097338F,                 /* re */
      -0.13458072F                     /* im */
    }, { 0.0075204372F,                /* re */
      -0.12241068F                     /* im */
    }, { 0.006093025F,                 /* re */
      -0.110222206F                    /* im */
    }, { 0.0048152804F,                /* re */
      -0.09801714F                     /* im */
    }, { 0.0036873817F,                /* re */
      -0.08579732F                     /* im */
    }, { 0.0027095675F,                /* re */
      -0.07356457F                     /* im */
    }, { 0.0018818974F,                /* re */
      -0.06132074F                     /* im */
    }, { 0.0012045503F,                /* re */
      -0.049067676F                    /* im */
    }, { 0.0006775856F,                /* re */
      -0.036807224F                    /* im */
    }, { 0.00030118227F,               /* re */
      -0.024541229F                    /* im */
    }, { 7.5280666E-5F,                /* re */
      -0.012271538F                    /* im */
    }, { 0.0F,                         /* re */
      -0.0F                            /* im */
    }, { 7.5280666E-5F,                /* re */
      0.012271538F                     /* im */
    }, { 0.00030118227F,               /* re */
      0.024541229F                     /* im */
    }, { 0.0006775856F,                /* re */
      0.036807224F                     /* im */
    }, { 0.0012045503F,                /* re */
      0.049067676F                     /* im */
    }, { 0.0018818974F,                /* re */
      0.06132074F                      /* im */
    }, { 0.0027095675F,                /* re */
      0.07356457F                      /* im */
    }, { 0.0036873817F,                /* re */
      0.08579732F                      /* im */
    }, { 0.0048152804F,                /* re */
      0.09801714F                      /* im */
    }, { 0.006093025F,                 /* re */
      0.110222206F                     /* im */
    }, { 0.0075204372F,                /* re */
      0.12241068F                      /* im */
    }, { 0.009097338F,                 /* re */
      0.13458072F                      /* im */
    }, { 0.010823488F,                 /* re */
      0.14673047F                      /* im */
    }, { 0.012698591F,                 /* re */
      0.15885815F                      /* im */
    }, { 0.014722347F,                 /* re */
      0.1709619F                       /* im */
    }, { 0.01689452F,                  /* re */
      0.18303989F                      /* im */
    }, { 0.01921475F,                  /* re */
      0.19509032F                      /* im */
    }, { 0.02168262F,                  /* re */
      0.20711139F                      /* im */
    }, { 0.024297893F,                 /* re */
      0.21910124F                      /* im */
    }, { 0.027060032F,                 /* re */
      0.23105812F                      /* im */
    }, { 0.029968739F,                 /* re */
      0.2429802F                       /* im */
    }, { 0.033023536F,                 /* re */
      0.25486568F                      /* im */
    }, { 0.036223948F,                 /* re */
      0.26671278F                      /* im */
    }, { 0.039569497F,                 /* re */
      0.2785197F                       /* im */
    }, { 0.043059647F,                 /* re */
      0.29028466F                      /* im */
    }, { 0.04669398F,                  /* re */
      0.30200595F                      /* im */
    }, { 0.050471842F,                 /* re */
      0.31368175F                      /* im */
    }, { 0.054392695F,                 /* re */
      0.32531032F                      /* im */
    }, { 0.058455944F,                 /* re */
      0.33688986F                      /* im */
    }, { 0.06266099F,                  /* re */
      0.34841868F                      /* im */
    }, { 0.067007184F,                 /* re */
      0.35989505F                      /* im */
    }, { 0.07149392F,                  /* re */
      0.3713172F                       /* im */
    }, { 0.076120496F,                 /* re */
      0.38268346F                      /* im */
    }, { 0.080886126F,                 /* re */
      0.39399207F                      /* im */
    }, { 0.08579028F,                  /* re */
      0.40524134F                      /* im */
    }, { 0.090832055F,                 /* re */
      0.41642958F                      /* im */
    }, { 0.096010685F,                 /* re */
      0.42755508F                      /* im */
    }, { 0.10132551F,                  /* re */
      0.43861625F                      /* im */
    }, { 0.1067757F,                   /* re */
      0.44961134F                      /* im */
    }, { 0.11236036F,                  /* re */
      0.46053872F                      /* im */
    }, { 0.11807877F,                  /* re */
      0.47139674F                      /* im */
    }, { 0.12392992F,                  /* re */
      0.48218375F                      /* im */
    }, { 0.12991303F,                  /* re */
      0.49289823F                      /* im */
    }, { 0.13602716F,                  /* re */
      0.50353837F                      /* im */
    }, { 0.1422714F,                   /* re */
      0.51410276F                      /* im */
    }, { 0.1486448F,                   /* re */
      0.5245897F                       /* im */
    }, { 0.15514642F,                  /* re */
      0.53499764F                      /* im */
    }, { 0.16177529F,                  /* re */
      0.54532504F                      /* im */
    }, { 0.1685304F,                   /* re */
      0.55557024F                      /* im */
    }, { 0.17541075F,                  /* re */
      0.5657318F                       /* im */
    }, { 0.18241519F,                  /* re */
      0.5758082F                       /* im */
    }, { 0.18954283F,                  /* re */
      0.5857979F                       /* im */
    }, { 0.19679248F,                  /* re */
      0.5956993F                       /* im */
    }, { 0.20416307F,                  /* re */
      0.605511F                        /* im */
    }, { 0.21165359F,                  /* re */
      0.61523163F                      /* im */
    }, { 0.21926278F,                  /* re */
      0.6248595F                       /* im */
    }, { 0.22698957F,                  /* re */
      0.63439333F                      /* im */
    }, { 0.23483276F,                  /* re */
      0.64383155F                      /* im */
    }, { 0.24279118F,                  /* re */
      0.65317285F                      /* im */
    }, { 0.2508636F,                   /* re */
      0.6624158F                       /* im */
    }, { 0.25904888F,                  /* re */
      0.671559F                        /* im */
    }, { 0.26734573F,                  /* re */
      0.680601F                        /* im */
    }, { 0.2757529F,                   /* re */
      0.68954057F                      /* im */
    }, { 0.2842692F,                   /* re */
      0.6983763F                       /* im */
    }, { 0.29289323F,                  /* re */
      0.70710677F                      /* im */
    }, { 0.3016237F,                   /* re */
      0.7157308F                       /* im */
    }, { 0.31045943F,                  /* re */
      0.7242471F                       /* im */
    }, { 0.319399F,                    /* re */
      0.7326543F                       /* im */
    }, { 0.32844102F,                  /* re */
      0.7409511F                       /* im */
    }, { 0.3375842F,                   /* re */
      0.7491364F                       /* im */
    }, { 0.34682715F,                  /* re */
      0.7572088F                       /* im */
    }, { 0.35616845F,                  /* re */
      0.76516724F                      /* im */
    }, { 0.36560667F,                  /* re */
      0.77301043F                      /* im */
    }, { 0.3751405F,                   /* re */
      0.7807372F                       /* im */
    }, { 0.38476837F,                  /* re */
      0.7883464F                       /* im */
    }, { 0.394489F,                    /* re */
      0.7958369F                       /* im */
    }, { 0.4043007F,                   /* re */
      0.8032075F                       /* im */
    }, { 0.4142021F,                   /* re */
      0.81045717F                      /* im */
    }, { 0.42419177F,                  /* re */
      0.8175848F                       /* im */
    }, { 0.43426818F,                  /* re */
      0.82458925F                      /* im */
    }, { 0.44442976F,                  /* re */
      0.8314696F                       /* im */
    }, { 0.45467496F,                  /* re */
      0.8382247F                       /* im */
    }, { 0.46500236F,                  /* re */
      0.8448536F                       /* im */
    }, { 0.47541028F,                  /* re */
      0.8513552F                       /* im */
    }, { 0.48589724F,                  /* re */
      0.8577286F                       /* im */
    }, { 0.49646163F,                  /* re */
      0.86397284F                      /* im */
    }, { 0.5071018F,                   /* re */
      0.87008697F                      /* im */
    }, { 0.51781625F,                  /* re */
      0.8760701F                       /* im */
    }, { 0.52860326F,                  /* re */
      0.88192123F                      /* im */
    }, { 0.53946126F,                  /* re */
      0.88763964F                      /* im */
    }, { 0.5503887F,                   /* re */
      0.8932243F                       /* im */
    }, { 0.5613837F,                   /* re */
      0.8986745F                       /* im */
    }, { 0.5724449F,                   /* re */
      0.9039893F                       /* im */
    }, { 0.5835704F,                   /* re */
      0.90916795F                      /* im */
    }, { 0.5947586F,                   /* re */
      0.9142097F                       /* im */
    }, { 0.60600793F,                  /* re */
      0.9191139F                       /* im */
    }, { 0.61731654F,                  /* re */
      0.9238795F                       /* im */
    }, { 0.6286828F,                   /* re */
      0.9285061F                       /* im */
    }, { 0.64010495F,                  /* re */
      0.9329928F                       /* im */
    }, { 0.6515813F,                   /* re */
      0.937339F                        /* im */
    }, { 0.66311014F,                  /* re */
      0.94154406F                      /* im */
    }, { 0.67468965F,                  /* re */
      0.9456073F                       /* im */
    }, { 0.6863183F,                   /* re */
      0.94952816F                      /* im */
    }, { 0.69799405F,                  /* re */
      0.953306F                        /* im */
    }, { 0.70971537F,                  /* re */
      0.95694035F                      /* im */
    }, { 0.7214803F,                   /* re */
      0.9604305F                       /* im */
    }, { 0.7332872F,                   /* re */
      0.96377605F                      /* im */
    }, { 0.74513435F,                  /* re */
      0.96697646F                      /* im */
    }, { 0.7570198F,                   /* re */
      0.97003126F                      /* im */
    }, { 0.7689419F,                   /* re */
      0.97293997F                      /* im */
    }, { 0.78089875F,                  /* re */
      0.9757021F                       /* im */
    }, { 0.79288864F,                  /* re */
      0.9783174F                       /* im */
    }, { 0.8049097F,                   /* re */
      0.98078525F                      /* im */
    }, { 0.8169601F,                   /* re */
      0.9831055F                       /* im */
    }, { 0.8290381F,                   /* re */
      0.98527765F                      /* im */
    }, { 0.8411418F,                   /* re */
      0.9873014F                       /* im */
    }, { 0.8532695F,                   /* re */
      0.9891765F                       /* im */
    }, { 0.86541927F,                  /* re */
      0.99090266F                      /* im */
    }, { 0.87758934F,                  /* re */
      0.99247956F                      /* im */
    }, { 0.8897778F,                   /* re */
      0.993907F                        /* im */
    }, { 0.90198284F,                  /* re */
      0.9951847F                       /* im */
    }, { 0.9142027F,                   /* re */
      0.9963126F                       /* im */
    }, { 0.9264354F,                   /* re */
      0.99729043F                      /* im */
    }, { 0.9386793F,                   /* re */
      0.9981181F                       /* im */
    }, { 0.9509323F,                   /* re */
      0.99879545F                      /* im */
    }, { 0.96319276F,                  /* re */
      0.9993224F                       /* im */
    }, { 0.97545874F,                  /* re */
      0.9996988F                       /* im */
    }, { 0.9877285F,                   /* re */
      0.9999247F                       /* im */
    } };

  static const creal32_T reconVar2[256] = { { 1.0F,/* re */
      1.0F                             /* im */
    }, { 1.0122715F,                   /* re */
      0.9999247F                       /* im */
    }, { 1.0245413F,                   /* re */
      0.9996988F                       /* im */
    }, { 1.0368072F,                   /* re */
      0.9993224F                       /* im */
    }, { 1.0490677F,                   /* re */
      0.99879545F                      /* im */
    }, { 1.0613208F,                   /* re */
      0.9981181F                       /* im */
    }, { 1.0735645F,                   /* re */
      0.99729043F                      /* im */
    }, { 1.0857973F,                   /* re */
      0.9963126F                       /* im */
    }, { 1.0980171F,                   /* re */
      0.9951847F                       /* im */
    }, { 1.1102222F,                   /* re */
      0.993907F                        /* im */
    }, { 1.1224107F,                   /* re */
      0.99247956F                      /* im */
    }, { 1.1345807F,                   /* re */
      0.99090266F                      /* im */
    }, { 1.1467304F,                   /* re */
      0.9891765F                       /* im */
    }, { 1.1588582F,                   /* re */
      0.9873014F                       /* im */
    }, { 1.1709619F,                   /* re */
      0.98527765F                      /* im */
    }, { 1.1830399F,                   /* re */
      0.9831055F                       /* im */
    }, { 1.1950903F,                   /* re */
      0.98078525F                      /* im */
    }, { 1.2071114F,                   /* re */
      0.9783174F                       /* im */
    }, { 1.2191012F,                   /* re */
      0.9757021F                       /* im */
    }, { 1.2310581F,                   /* re */
      0.97293997F                      /* im */
    }, { 1.2429802F,                   /* re */
      0.97003126F                      /* im */
    }, { 1.2548656F,                   /* re */
      0.96697646F                      /* im */
    }, { 1.2667128F,                   /* re */
      0.96377605F                      /* im */
    }, { 1.2785196F,                   /* re */
      0.9604305F                       /* im */
    }, { 1.2902846F,                   /* re */
      0.95694035F                      /* im */
    }, { 1.302006F,                    /* re */
      0.953306F                        /* im */
    }, { 1.3136817F,                   /* re */
      0.94952816F                      /* im */
    }, { 1.3253103F,                   /* re */
      0.9456073F                       /* im */
    }, { 1.3368899F,                   /* re */
      0.94154406F                      /* im */
    }, { 1.3484187F,                   /* re */
      0.937339F                        /* im */
    }, { 1.359895F,                    /* re */
      0.9329928F                       /* im */
    }, { 1.3713171F,                   /* re */
      0.9285061F                       /* im */
    }, { 1.3826835F,                   /* re */
      0.9238795F                       /* im */
    }, { 1.3939921F,                   /* re */
      0.9191139F                       /* im */
    }, { 1.4052414F,                   /* re */
      0.9142097F                       /* im */
    }, { 1.4164295F,                   /* re */
      0.90916795F                      /* im */
    }, { 1.4275551F,                   /* re */
      0.9039893F                       /* im */
    }, { 1.4386163F,                   /* re */
      0.8986745F                       /* im */
    }, { 1.4496113F,                   /* re */
      0.8932243F                       /* im */
    }, { 1.4605387F,                   /* re */
      0.88763964F                      /* im */
    }, { 1.4713967F,                   /* re */
      0.88192123F                      /* im */
    }, { 1.4821837F,                   /* re */
      0.8760701F                       /* im */
    }, { 1.4928982F,                   /* re */
      0.87008697F                      /* im */
    }, { 1.5035384F,                   /* re */
      0.86397284F                      /* im */
    }, { 1.5141027F,                   /* re */
      0.8577286F                       /* im */
    }, { 1.5245898F,                   /* re */
      0.8513552F                       /* im */
    }, { 1.5349977F,                   /* re */
      0.8448536F                       /* im */
    }, { 1.545325F,                    /* re */
      0.8382247F                       /* im */
    }, { 1.5555702F,                   /* re */
      0.8314696F                       /* im */
    }, { 1.5657318F,                   /* re */
      0.82458925F                      /* im */
    }, { 1.5758083F,                   /* re */
      0.8175848F                       /* im */
    }, { 1.5857979F,                   /* re */
      0.81045717F                      /* im */
    }, { 1.5956993F,                   /* re */
      0.8032075F                       /* im */
    }, { 1.605511F,                    /* re */
      0.7958369F                       /* im */
    }, { 1.6152316F,                   /* re */
      0.7883464F                       /* im */
    }, { 1.6248596F,                   /* re */
      0.7807372F                       /* im */
    }, { 1.6343933F,                   /* re */
      0.77301043F                      /* im */
    }, { 1.6438315F,                   /* re */
      0.76516724F                      /* im */
    }, { 1.6531729F,                   /* re */
      0.7572088F                       /* im */
    }, { 1.6624157F,                   /* re */
      0.7491364F                       /* im */
    }, { 1.671559F,                    /* re */
      0.7409511F                       /* im */
    }, { 1.680601F,                    /* re */
      0.7326543F                       /* im */
    }, { 1.6895406F,                   /* re */
      0.7242471F                       /* im */
    }, { 1.6983763F,                   /* re */
      0.7157308F                       /* im */
    }, { 1.7071068F,                   /* re */
      0.70710677F                      /* im */
    }, { 1.7157308F,                   /* re */
      0.6983763F                       /* im */
    }, { 1.7242471F,                   /* re */
      0.68954057F                      /* im */
    }, { 1.7326543F,                   /* re */
      0.680601F                        /* im */
    }, { 1.7409511F,                   /* re */
      0.671559F                        /* im */
    }, { 1.7491364F,                   /* re */
      0.6624158F                       /* im */
    }, { 1.7572088F,                   /* re */
      0.65317285F                      /* im */
    }, { 1.7651672F,                   /* re */
      0.64383155F                      /* im */
    }, { 1.7730105F,                   /* re */
      0.63439333F                      /* im */
    }, { 1.7807372F,                   /* re */
      0.6248595F                       /* im */
    }, { 1.7883464F,                   /* re */
      0.61523163F                      /* im */
    }, { 1.7958369F,                   /* re */
      0.605511F                        /* im */
    }, { 1.8032075F,                   /* re */
      0.5956993F                       /* im */
    }, { 1.8104572F,                   /* re */
      0.5857979F                       /* im */
    }, { 1.8175848F,                   /* re */
      0.5758082F                       /* im */
    }, { 1.8245893F,                   /* re */
      0.5657318F                       /* im */
    }, { 1.8314695F,                   /* re */
      0.55557024F                      /* im */
    }, { 1.8382246F,                   /* re */
      0.54532504F                      /* im */
    }, { 1.8448536F,                   /* re */
      0.53499764F                      /* im */
    }, { 1.8513552F,                   /* re */
      0.5245897F                       /* im */
    }, { 1.8577286F,                   /* re */
      0.51410276F                      /* im */
    }, { 1.8639729F,                   /* re */
      0.50353837F                      /* im */
    }, { 1.8700869F,                   /* re */
      0.49289823F                      /* im */
    }, { 1.87607F,                     /* re */
      0.48218375F                      /* im */
    }, { 1.8819213F,                   /* re */
      0.47139674F                      /* im */
    }, { 1.8876396F,                   /* re */
      0.46053872F                      /* im */
    }, { 1.8932242F,                   /* re */
      0.44961134F                      /* im */
    }, { 1.8986745F,                   /* re */
      0.43861625F                      /* im */
    }, { 1.9039893F,                   /* re */
      0.42755508F                      /* im */
    }, { 1.909168F,                    /* re */
      0.41642958F                      /* im */
    }, { 1.9142097F,                   /* re */
      0.40524134F                      /* im */
    }, { 1.9191139F,                   /* re */
      0.39399207F                      /* im */
    }, { 1.9238795F,                   /* re */
      0.38268346F                      /* im */
    }, { 1.9285061F,                   /* re */
      0.3713172F                       /* im */
    }, { 1.9329928F,                   /* re */
      0.35989505F                      /* im */
    }, { 1.9373391F,                   /* re */
      0.34841868F                      /* im */
    }, { 1.941544F,                    /* re */
      0.33688986F                      /* im */
    }, { 1.9456073F,                   /* re */
      0.32531032F                      /* im */
    }, { 1.9495282F,                   /* re */
      0.31368175F                      /* im */
    }, { 1.953306F,                    /* re */
      0.30200595F                      /* im */
    }, { 1.9569404F,                   /* re */
      0.29028466F                      /* im */
    }, { 1.9604305F,                   /* re */
      0.2785197F                       /* im */
    }, { 1.9637761F,                   /* re */
      0.26671278F                      /* im */
    }, { 1.9669764F,                   /* re */
      0.25486568F                      /* im */
    }, { 1.9700313F,                   /* re */
      0.2429802F                       /* im */
    }, { 1.97294F,                     /* re */
      0.23105812F                      /* im */
    }, { 1.975702F,                    /* re */
      0.21910124F                      /* im */
    }, { 1.9783174F,                   /* re */
      0.20711139F                      /* im */
    }, { 1.9807853F,                   /* re */
      0.19509032F                      /* im */
    }, { 1.9831054F,                   /* re */
      0.18303989F                      /* im */
    }, { 1.9852777F,                   /* re */
      0.1709619F                       /* im */
    }, { 1.9873013F,                   /* re */
      0.15885815F                      /* im */
    }, { 1.9891765F,                   /* re */
      0.14673047F                      /* im */
    }, { 1.9909027F,                   /* re */
      0.13458072F                      /* im */
    }, { 1.9924796F,                   /* re */
      0.12241068F                      /* im */
    }, { 1.993907F,                    /* re */
      0.110222206F                     /* im */
    }, { 1.9951847F,                   /* re */
      0.09801714F                      /* im */
    }, { 1.9963126F,                   /* re */
      0.08579732F                      /* im */
    }, { 1.9972904F,                   /* re */
      0.07356457F                      /* im */
    }, { 1.9981182F,                   /* re */
      0.06132074F                      /* im */
    }, { 1.9987955F,                   /* re */
      0.049067676F                     /* im */
    }, { 1.9993224F,                   /* re */
      0.036807224F                     /* im */
    }, { 1.9996989F,                   /* re */
      0.024541229F                     /* im */
    }, { 1.9999247F,                   /* re */
      0.012271538F                     /* im */
    }, { 2.0F,                         /* re */
      0.0F                             /* im */
    }, { 1.9999247F,                   /* re */
      -0.012271538F                    /* im */
    }, { 1.9996989F,                   /* re */
      -0.024541229F                    /* im */
    }, { 1.9993224F,                   /* re */
      -0.036807224F                    /* im */
    }, { 1.9987955F,                   /* re */
      -0.049067676F                    /* im */
    }, { 1.9981182F,                   /* re */
      -0.06132074F                     /* im */
    }, { 1.9972904F,                   /* re */
      -0.07356457F                     /* im */
    }, { 1.9963126F,                   /* re */
      -0.08579732F                     /* im */
    }, { 1.9951847F,                   /* re */
      -0.09801714F                     /* im */
    }, { 1.993907F,                    /* re */
      -0.110222206F                    /* im */
    }, { 1.9924796F,                   /* re */
      -0.12241068F                     /* im */
    }, { 1.9909027F,                   /* re */
      -0.13458072F                     /* im */
    }, { 1.9891765F,                   /* re */
      -0.14673047F                     /* im */
    }, { 1.9873013F,                   /* re */
      -0.15885815F                     /* im */
    }, { 1.9852777F,                   /* re */
      -0.1709619F                      /* im */
    }, { 1.9831054F,                   /* re */
      -0.18303989F                     /* im */
    }, { 1.9807853F,                   /* re */
      -0.19509032F                     /* im */
    }, { 1.9783174F,                   /* re */
      -0.20711139F                     /* im */
    }, { 1.975702F,                    /* re */
      -0.21910124F                     /* im */
    }, { 1.97294F,                     /* re */
      -0.23105812F                     /* im */
    }, { 1.9700313F,                   /* re */
      -0.2429802F                      /* im */
    }, { 1.9669764F,                   /* re */
      -0.25486568F                     /* im */
    }, { 1.9637761F,                   /* re */
      -0.26671278F                     /* im */
    }, { 1.9604305F,                   /* re */
      -0.2785197F                      /* im */
    }, { 1.9569404F,                   /* re */
      -0.29028466F                     /* im */
    }, { 1.953306F,                    /* re */
      -0.30200595F                     /* im */
    }, { 1.9495282F,                   /* re */
      -0.31368175F                     /* im */
    }, { 1.9456073F,                   /* re */
      -0.32531032F                     /* im */
    }, { 1.941544F,                    /* re */
      -0.33688986F                     /* im */
    }, { 1.9373391F,                   /* re */
      -0.34841868F                     /* im */
    }, { 1.9329928F,                   /* re */
      -0.35989505F                     /* im */
    }, { 1.9285061F,                   /* re */
      -0.3713172F                      /* im */
    }, { 1.9238795F,                   /* re */
      -0.38268346F                     /* im */
    }, { 1.9191139F,                   /* re */
      -0.39399207F                     /* im */
    }, { 1.9142097F,                   /* re */
      -0.40524134F                     /* im */
    }, { 1.909168F,                    /* re */
      -0.41642958F                     /* im */
    }, { 1.9039893F,                   /* re */
      -0.42755508F                     /* im */
    }, { 1.8986745F,                   /* re */
      -0.43861625F                     /* im */
    }, { 1.8932242F,                   /* re */
      -0.44961134F                     /* im */
    }, { 1.8876396F,                   /* re */
      -0.46053872F                     /* im */
    }, { 1.8819213F,                   /* re */
      -0.47139674F                     /* im */
    }, { 1.87607F,                     /* re */
      -0.48218375F                     /* im */
    }, { 1.8700869F,                   /* re */
      -0.49289823F                     /* im */
    }, { 1.8639729F,                   /* re */
      -0.50353837F                     /* im */
    }, { 1.8577286F,                   /* re */
      -0.51410276F                     /* im */
    }, { 1.8513552F,                   /* re */
      -0.5245897F                      /* im */
    }, { 1.8448536F,                   /* re */
      -0.53499764F                     /* im */
    }, { 1.8382246F,                   /* re */
      -0.54532504F                     /* im */
    }, { 1.8314695F,                   /* re */
      -0.55557024F                     /* im */
    }, { 1.8245893F,                   /* re */
      -0.5657318F                      /* im */
    }, { 1.8175848F,                   /* re */
      -0.5758082F                      /* im */
    }, { 1.8104572F,                   /* re */
      -0.5857979F                      /* im */
    }, { 1.8032075F,                   /* re */
      -0.5956993F                      /* im */
    }, { 1.7958369F,                   /* re */
      -0.605511F                       /* im */
    }, { 1.7883464F,                   /* re */
      -0.61523163F                     /* im */
    }, { 1.7807372F,                   /* re */
      -0.6248595F                      /* im */
    }, { 1.7730105F,                   /* re */
      -0.63439333F                     /* im */
    }, { 1.7651672F,                   /* re */
      -0.64383155F                     /* im */
    }, { 1.7572088F,                   /* re */
      -0.65317285F                     /* im */
    }, { 1.7491364F,                   /* re */
      -0.6624158F                      /* im */
    }, { 1.7409511F,                   /* re */
      -0.671559F                       /* im */
    }, { 1.7326543F,                   /* re */
      -0.680601F                       /* im */
    }, { 1.7242471F,                   /* re */
      -0.68954057F                     /* im */
    }, { 1.7157308F,                   /* re */
      -0.6983763F                      /* im */
    }, { 1.7071068F,                   /* re */
      -0.70710677F                     /* im */
    }, { 1.6983763F,                   /* re */
      -0.7157308F                      /* im */
    }, { 1.6895406F,                   /* re */
      -0.7242471F                      /* im */
    }, { 1.680601F,                    /* re */
      -0.7326543F                      /* im */
    }, { 1.671559F,                    /* re */
      -0.7409511F                      /* im */
    }, { 1.6624157F,                   /* re */
      -0.7491364F                      /* im */
    }, { 1.6531729F,                   /* re */
      -0.7572088F                      /* im */
    }, { 1.6438315F,                   /* re */
      -0.76516724F                     /* im */
    }, { 1.6343933F,                   /* re */
      -0.77301043F                     /* im */
    }, { 1.6248596F,                   /* re */
      -0.7807372F                      /* im */
    }, { 1.6152316F,                   /* re */
      -0.7883464F                      /* im */
    }, { 1.605511F,                    /* re */
      -0.7958369F                      /* im */
    }, { 1.5956993F,                   /* re */
      -0.8032075F                      /* im */
    }, { 1.5857979F,                   /* re */
      -0.81045717F                     /* im */
    }, { 1.5758083F,                   /* re */
      -0.8175848F                      /* im */
    }, { 1.5657318F,                   /* re */
      -0.82458925F                     /* im */
    }, { 1.5555702F,                   /* re */
      -0.8314696F                      /* im */
    }, { 1.545325F,                    /* re */
      -0.8382247F                      /* im */
    }, { 1.5349977F,                   /* re */
      -0.8448536F                      /* im */
    }, { 1.5245898F,                   /* re */
      -0.8513552F                      /* im */
    }, { 1.5141027F,                   /* re */
      -0.8577286F                      /* im */
    }, { 1.5035384F,                   /* re */
      -0.86397284F                     /* im */
    }, { 1.4928982F,                   /* re */
      -0.87008697F                     /* im */
    }, { 1.4821837F,                   /* re */
      -0.8760701F                      /* im */
    }, { 1.4713967F,                   /* re */
      -0.88192123F                     /* im */
    }, { 1.4605387F,                   /* re */
      -0.88763964F                     /* im */
    }, { 1.4496113F,                   /* re */
      -0.8932243F                      /* im */
    }, { 1.4386163F,                   /* re */
      -0.8986745F                      /* im */
    }, { 1.4275551F,                   /* re */
      -0.9039893F                      /* im */
    }, { 1.4164295F,                   /* re */
      -0.90916795F                     /* im */
    }, { 1.4052414F,                   /* re */
      -0.9142097F                      /* im */
    }, { 1.3939921F,                   /* re */
      -0.9191139F                      /* im */
    }, { 1.3826835F,                   /* re */
      -0.9238795F                      /* im */
    }, { 1.3713171F,                   /* re */
      -0.9285061F                      /* im */
    }, { 1.359895F,                    /* re */
      -0.9329928F                      /* im */
    }, { 1.3484187F,                   /* re */
      -0.937339F                       /* im */
    }, { 1.3368899F,                   /* re */
      -0.94154406F                     /* im */
    }, { 1.3253103F,                   /* re */
      -0.9456073F                      /* im */
    }, { 1.3136817F,                   /* re */
      -0.94952816F                     /* im */
    }, { 1.302006F,                    /* re */
      -0.953306F                       /* im */
    }, { 1.2902846F,                   /* re */
      -0.95694035F                     /* im */
    }, { 1.2785196F,                   /* re */
      -0.9604305F                      /* im */
    }, { 1.2667128F,                   /* re */
      -0.96377605F                     /* im */
    }, { 1.2548656F,                   /* re */
      -0.96697646F                     /* im */
    }, { 1.2429802F,                   /* re */
      -0.97003126F                     /* im */
    }, { 1.2310581F,                   /* re */
      -0.97293997F                     /* im */
    }, { 1.2191012F,                   /* re */
      -0.9757021F                      /* im */
    }, { 1.2071114F,                   /* re */
      -0.9783174F                      /* im */
    }, { 1.1950903F,                   /* re */
      -0.98078525F                     /* im */
    }, { 1.1830399F,                   /* re */
      -0.9831055F                      /* im */
    }, { 1.1709619F,                   /* re */
      -0.98527765F                     /* im */
    }, { 1.1588582F,                   /* re */
      -0.9873014F                      /* im */
    }, { 1.1467304F,                   /* re */
      -0.9891765F                      /* im */
    }, { 1.1345807F,                   /* re */
      -0.99090266F                     /* im */
    }, { 1.1224107F,                   /* re */
      -0.99247956F                     /* im */
    }, { 1.1102222F,                   /* re */
      -0.993907F                       /* im */
    }, { 1.0980171F,                   /* re */
      -0.9951847F                      /* im */
    }, { 1.0857973F,                   /* re */
      -0.9963126F                      /* im */
    }, { 1.0735645F,                   /* re */
      -0.99729043F                     /* im */
    }, { 1.0613208F,                   /* re */
      -0.9981181F                      /* im */
    }, { 1.0490677F,                   /* re */
      -0.99879545F                     /* im */
    }, { 1.0368072F,                   /* re */
      -0.9993224F                      /* im */
    }, { 1.0245413F,                   /* re */
      -0.9996988F                      /* im */
    }, { 1.0122715F,                   /* re */
      -0.9999247F                      /* im */
    } };

  /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  memset(&y[0], 0, sizeof(creal32_T) << 9U);
  for (i = 0; i < 200; i++) {
    /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
    bitrevIndex = bitrevIndex_0[i];
    iDelta = (i << 1) + xoffInit;
    y[bitrevIndex - 1].re = x[iDelta];
    y[bitrevIndex - 1].im = x[iDelta + 1];
  }

  for (i = 0; i <= 254; i += 2) {
    temp_re = y[i + 1].re;
    temp2_re = y[i + 1].im;
    temp_im = y[i].re;
    temp2_im = y[i].im;

    /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
    y[i + 1].re = temp_im - temp_re;
    y[i + 1].im = temp2_im - temp2_re;
    y[i].re = temp_im + temp_re;
    y[i].im = temp2_im + temp2_re;
  }

  /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  iDelta = 2;
  iDelta2 = 4;
  k = 64;
  iheight = 253;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      temp_re_tmp = i + iDelta;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - temp_re;
      y[temp_re_tmp].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = k; j < 128; j += k) {
      temp2_re = tmp_0[j];
      temp2_im = tmp_1[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iDelta;
        temp_im = y[temp_re_tmp].im;
        temp_re_tmp_0 = y[temp_re_tmp].re;
        temp_re = temp_re_tmp_0 * temp2_re - temp_im * temp2_im;
        temp_im = temp_im * temp2_re + temp_re_tmp_0 * temp2_im;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += iDelta2;
      }

      istart++;
    }

    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }

  temp_re = y[0].re;
  temp_im = y[0].im;

  /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  temp2_re = -y[0].re + y[0].im;
  temp2_im = y[0].re - y[0].im;
  temp_re_tmp_0 = y[0].re - (-y[0].im);
  y[0].re = (temp_re_tmp_0 + temp_re_tmp_0) * 0.5F;
  y[0].im = (temp2_re + temp2_im) * 0.5F;
  y[256].re = (temp2_im + temp2_im) * 0.5F;
  y[256].im = ((temp_re + temp_im) + (-temp_re - temp_im)) * 0.5F;
  for (i = 0; i < 127; i++) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    iDelta = tmp_2[i + 1];
    temp2_re = y[iDelta - 1].re;
    temp2_im = y[iDelta - 1].im;
    y_im_tmp = reconVar1[i + 1].re;
    y_im_tmp_0 = reconVar1[i + 1].im;
    temp_re_tmp_0 = reconVar2[i + 1].im;
    tmp = reconVar2[i + 1].re;
    y[i + 1].re = ((temp_re * y_im_tmp - temp_im * y_im_tmp_0) + (tmp * temp2_re
      - temp_re_tmp_0 * -temp2_im)) * 0.5F;
    y[i + 1].im = ((temp_re_tmp_0 * temp2_re + tmp * -temp2_im) + (temp_re *
      y_im_tmp_0 + temp_im * y_im_tmp)) * 0.5F;
    y[i + 257].re = ((tmp * temp_re - temp_re_tmp_0 * temp_im) + (y_im_tmp *
      temp2_re - y_im_tmp_0 * -temp2_im)) * 0.5F;
    y[i + 257].im = ((temp_re_tmp_0 * temp_re + tmp * temp_im) + (y_im_tmp_0 *
      temp2_re + y_im_tmp * -temp2_im)) * 0.5F;
    temp_re_tmp_0 = reconVar1[iDelta - 1].im;
    tmp = reconVar1[iDelta - 1].re;
    y_im_tmp = reconVar2[iDelta - 1].im;
    y_im_tmp_0 = reconVar2[iDelta - 1].re;
    y[iDelta - 1].re = ((tmp * temp2_re - temp_re_tmp_0 * temp2_im) +
                        (y_im_tmp_0 * temp_re - y_im_tmp * -temp_im)) * 0.5F;
    y[iDelta - 1].im = ((temp_re_tmp_0 * temp2_re + tmp * temp2_im) + (y_im_tmp *
      temp_re + y_im_tmp_0 * -temp_im)) * 0.5F;
    y[iDelta + 255].re = ((y_im_tmp_0 * temp2_re - y_im_tmp * temp2_im) + (tmp *
      temp_re - temp_re_tmp_0 * -temp_im)) * 0.5F;
    y[iDelta + 255].im = ((y_im_tmp * temp2_re + y_im_tmp_0 * temp2_im) +
                          (temp_re_tmp_0 * temp_re + tmp * -temp_im)) * 0.5F;
  }

  temp_im = y[128].im;

  /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  y_im_tmp = y[128].im * 0.0F;
  y_im_tmp_0 = y[128].re * -0.0F;
  temp_re = y[128].re * 0.0F;
  temp_re_tmp_0 = y[128].re * 2.0F;
  tmp = -y[128].im * 0.0F;
  y[128].re = ((temp_re - y[128].im * -0.0F) + (temp_re_tmp_0 - tmp)) * 0.5F;
  y[128].im = ((-y[128].im * 2.0F + temp_re) + (y_im_tmp_0 + y_im_tmp)) * 0.5F;
  y[384].re = ((temp_re - -temp_im * -0.0F) + (temp_re_tmp_0 - y_im_tmp)) * 0.5F;
  y[384].im = ((temp_im * 2.0F + temp_re) + (y_im_tmp_0 + tmp)) * 0.5F;
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T b;
  real32_T y;
  a = (real32_T)fabs(u0);
  b = (real32_T)fabs(u1);
  if (a < b) {
    a /= b;
    y = (real32_T)sqrt(a * a + 1.0F) * b;
  } else if (a > b) {
    b /= a;
    y = (real32_T)sqrt(b * b + 1.0F) * a;
  } else if (rtIsNaNF(b)) {
    y = (rtNaNF);
  } else {
    y = a * 1.4142135F;
  }

  return y;
}

static void AudioSmartSpeakerOnJetsonNano_convolutionKernel(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr)
{
  int32_T idxToStrideInputBufferAlongHeight;
  int32_T idxToStrideInputBufferAlongWidth;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister0_0;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_2;
  real32_T outputRegister_3;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  if (!outputChannelTailCase) {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 98;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
        outputRegister_c = biasBufferPtr[13];
        outputRegister_d = biasBufferPtr[14];
        outputRegister_e = biasBufferPtr[15];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 4900];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 9800];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 14700];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 19600];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 24500];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 29400];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 34300];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 39200];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 44100];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 49000];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 53900];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 58800];
        outputRegister_c = outputBufferPtr[outputHeightBlockIdx + 63700];
        outputRegister_d = outputBufferPtr[outputHeightBlockIdx + 68600];
        outputRegister_e = outputBufferPtr[outputHeightBlockIdx + 73500];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 9] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 18] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 27] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 36] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 45] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 54] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 63] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 72] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 81] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 90] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 99] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 108] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 117] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 126] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 135] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 10] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 19] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 28] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 37] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 46] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 55] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 64] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 73] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 82] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 91] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 100] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 109] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 118] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 127] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 136] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 11] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 20] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 29] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 38] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 47] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 56] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 65] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 74] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 83] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 92] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 101] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 110] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 119] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 128] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 137] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 100;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4900] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 9800] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 14700] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 19600] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 19600] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 24500] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 24500] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 29400] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 29400] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 34300] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 34300] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 39200] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 39200] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 44100] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 44100] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 49000] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 49000] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 53900] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 53900] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 58800] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 58800] = 0.0F;
        }

        if (outputRegister_c >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 63700] = outputRegister_c;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 63700] = 0.0F;
        }

        if (outputRegister_d >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 68600] = outputRegister_d;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 68600] = 0.0F;
        }

        if (outputRegister_e >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 73500] = outputRegister_e;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 73500] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 19600] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 24500] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 29400] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 34300] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 39200] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 44100] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 49000] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 53900] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 58800] = outputRegister_b;
        outputBufferPtr[outputHeightBlockIdx + 63700] = outputRegister_c;
        outputBufferPtr[outputHeightBlockIdx + 68600] = outputRegister_d;
        outputBufferPtr[outputHeightBlockIdx + 73500] = outputRegister_e;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  } else {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 98;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 4900];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 9800];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 14700];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 19600];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 24500];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 29400];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 9] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 18] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 27] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 36] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 45] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 54] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 10] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 19] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 28] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 37] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 46] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 55] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 11] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 20] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 29] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 38] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 47] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 56] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 100;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4900] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 9800] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 14700] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 19600] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 19600] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 24500] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 24500] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 29400] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 29400] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 19600] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 24500] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 29400] = outputRegister_5;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolution(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[83200];
  static boolean_T bufferInitialized;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputBufferIdx;
  int32_T inputChannelMiniBlockIdx;
  int32_T inputHeightIdx;
  int32_T inputWidthIdx;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, (uint32_T)((int32_T)sizeof(real32_T)
            * 83200));
    bufferInitialized = true;
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 4900;
       fusedInputChannelMiniBlockIdx++) {
    inputChannelMiniBlockIdx = div_nde_s32_floor(fusedInputChannelMiniBlockIdx,
      4900);
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 4900;
    inputWidthIdx = div_nde_s32_floor(fusedInputWidthAndHeightIdx, 98);
    inputHeightIdx = fusedInputWidthAndHeightIdx % 98;
    fusedInputWidthAndHeightIdx = (inputWidthIdx * 98 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 4900;
    inputWidthIdx = (inputWidthIdx * 100 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 5200;
    for (inputChannelMiniBlockIdx = 1; inputChannelMiniBlockIdx < 2;
         inputChannelMiniBlockIdx++) {
      inputScratchpadBuffer[inputWidthIdx + 101] =
        inputTensor[fusedInputWidthAndHeightIdx];
      inputWidthIdx++;
    }
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 50;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (fusedInputChannelMiniBlockIdx, 50);
    inputChannelMiniBlockIdx = fusedInputChannelMiniBlockIdx % 50;
    inputWidthIdx = inputChannelMiniBlockIdx * 98 + fusedInputWidthAndHeightIdx *
      78400;
    inputHeightIdx = fusedInputWidthAndHeightIdx * 144;
    outputChannelTailCase = (fusedInputWidthAndHeightIdx == 0);
    inputBufferIdx = inputChannelMiniBlockIdx * 100;
    for (inputChannelMiniBlockIdx = 0; inputChannelMiniBlockIdx < 1;
         inputChannelMiniBlockIdx++) {
      AudioSmartSpeakerOnJetsonNano_convolutionKernel
        (&inputScratchpadBuffer[inputBufferIdx], &outputTensor[inputWidthIdx],
         &weightsTensor[inputHeightIdx], outputChannelTailCase, true, true,
         &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor(const
  real32_T X[4900], real32_T Z[34300])
{
  static const real32_T b[63] = { -0.5570794F, -0.19045515F, -0.26704764F,
    -0.34189942F, -0.3356419F, -0.093325675F, 0.7699648F, 0.7285407F, 0.6192163F,
    0.6930287F, -0.38019413F, -0.6337784F, 0.78522325F, -0.03469346F,
    -0.6515629F, 0.7066394F, 0.12687111F, -0.52627623F, 0.6953518F, 0.21574408F,
    0.13056254F, 0.4232645F, 0.15374492F, -0.20556554F, -0.1150499F, -0.376777F,
    -0.78324133F, 0.35276952F, 0.57453096F, 0.6667022F, -0.34206975F,
    -0.14821337F, 0.13067882F, -0.39134252F, -0.57457817F, -0.21917129F,
    0.11651491F, 0.055190828F, 0.004933906F, 0.1513801F, -0.0010350503F,
    0.1474813F, -0.17405756F, 0.04932674F, 0.17600363F, -0.10920221F,
    -0.20503998F, 0.40585113F, -0.76090455F, -0.062441766F, 0.94145054F,
    -0.78628045F, -0.25368345F, 0.9142439F, -0.019332016F, 0.16622332F,
    0.01957875F, 0.1855803F, 0.15225782F, -0.017602354F, 0.13314988F,
    0.043007635F, -0.049040936F };

  static const real32_T c[7] = { 0.5225658F, 0.25353035F, -0.12199755F,
    -0.038297445F, -0.057012893F, 0.2138719F, -0.039782986F };

  AudioSmartSpeakerOnJetsonNano_convolution(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict(const real32_T
  X_Data[34300], real32_T Z_Data[8575])
{
  int32_T b_filterWidthIdx;
  int32_T inputWidthIdx;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  int32_T tmp;
  int32_T tmp_0;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 7; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 25; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 49; outHeightIdx++) {
        opValue = -3.402823466E+38F;
        tmp = outHeightIdx << 1;
        tmp_0 = outWidthIdx << 1;
        if ((tmp + 4 <= 98) && (tmp_0 + 4 <= 50)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = ((tmp_0 + b_filterWidthIdx) * 98 + tmp) + 4900 *
              outChannelIdx;
            y = X_Data[inputWidthIdx];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx + 1];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx + 2];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = tmp_0 + b_filterWidthIdx;
            if (inputWidthIdx + 1 <= 50) {
              y = X_Data[(98 * inputWidthIdx + tmp) + 4900 * outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if (inputWidthIdx + 1 <= 50) {
              y = X_Data[((98 * inputWidthIdx + tmp) + 4900 * outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if ((tmp + 3 <= 98) && (inputWidthIdx + 1 <= 50)) {
              y = X_Data[((98 * inputWidthIdx + tmp) + 4900 * outChannelIdx) + 2];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        }

        Z_Data[(outHeightIdx + 49 * outWidthIdx) + 1225 * outChannelIdx] =
          opValue;
      }
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_d(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr)
{
  int32_T idxToStrideInputBufferAlongHeight;
  int32_T idxToStrideInputBufferAlongWidth;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister0_0;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_2;
  real32_T outputRegister_3;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  if (!outputChannelTailCase) {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 49;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
        outputRegister_c = biasBufferPtr[13];
        outputRegister_d = biasBufferPtr[14];
        outputRegister_e = biasBufferPtr[15];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 1225];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 2450];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 3675];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 4900];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 6125];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 7350];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 8575];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 9800];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 11025];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 12250];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 13475];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 14700];
        outputRegister_c = outputBufferPtr[outputHeightBlockIdx + 15925];
        outputRegister_d = outputBufferPtr[outputHeightBlockIdx + 17150];
        outputRegister_e = outputBufferPtr[outputHeightBlockIdx + 18375];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 63] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 126] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 189] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 252] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 315] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 378] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 441] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 504] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 567] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 630] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 693] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 756] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 819] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 882] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 945] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 64] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 127] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 190] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 253] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 316] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 379] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 442] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 505] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 568] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 631] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 694] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 757] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 820] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 883] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 946] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 65] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 128] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 191] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 254] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 317] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 380] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 443] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 506] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 569] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 632] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 695] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 758] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 821] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 884] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 947] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 51;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1225] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1225] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2450] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2450] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3675] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3675] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4900] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 6125] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 6125] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 7350] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 7350] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 8575] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 8575] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 9800] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 11025] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 11025] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 12250] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 12250] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 13475] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 13475] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 14700] = 0.0F;
        }

        if (outputRegister_c >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 15925] = outputRegister_c;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 15925] = 0.0F;
        }

        if (outputRegister_d >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 17150] = outputRegister_d;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 17150] = 0.0F;
        }

        if (outputRegister_e >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 18375] = outputRegister_e;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 18375] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 1225] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 2450] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 3675] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 6125] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 7350] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 8575] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 11025] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 12250] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 13475] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 14700] = outputRegister_b;
        outputBufferPtr[outputHeightBlockIdx + 15925] = outputRegister_c;
        outputBufferPtr[outputHeightBlockIdx + 17150] = outputRegister_d;
        outputBufferPtr[outputHeightBlockIdx + 18375] = outputRegister_e;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  } else {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 49;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 1225];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 2450];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 3675];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 4900];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 6125];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 7350];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 8575];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 9800];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 11025];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 63] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 126] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 189] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 252] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 315] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 378] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 441] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 504] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 567] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 64] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 127] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 190] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 253] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 316] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 379] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 442] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 505] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 568] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 65] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 128] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 191] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 254] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 317] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 380] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 443] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 506] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 569] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 51;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1225] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1225] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2450] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2450] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3675] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3675] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4900] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 6125] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 6125] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 7350] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 7350] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 8575] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 8575] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 9800] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 11025] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 11025] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 1225] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 2450] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 3675] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 4900] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 6125] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 7350] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 8575] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 9800] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 11025] = outputRegister_8;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolution_d(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[22032];
  static boolean_T bufferInitialized;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputBufferIdx;
  int32_T inputChannelMiniBlockIdx;
  int32_T inputHeightIdx;
  int32_T inputWidthIdx;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, (uint32_T)((int32_T)sizeof(real32_T)
            * 22032));
    bufferInitialized = true;
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 8575;
       fusedInputChannelMiniBlockIdx++) {
    inputChannelMiniBlockIdx = div_nde_s32_floor(fusedInputChannelMiniBlockIdx,
      1225);
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 1225;
    inputWidthIdx = div_nde_s32_floor(fusedInputWidthAndHeightIdx, 49);
    inputHeightIdx = fusedInputWidthAndHeightIdx % 49;
    fusedInputWidthAndHeightIdx = (inputWidthIdx * 49 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 1225;
    inputWidthIdx = (inputWidthIdx * 51 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 1377;
    for (inputChannelMiniBlockIdx = 1; inputChannelMiniBlockIdx < 2;
         inputChannelMiniBlockIdx++) {
      inputScratchpadBuffer[inputWidthIdx + 52] =
        inputTensor[fusedInputWidthAndHeightIdx];
      inputWidthIdx++;
    }
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 25;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (fusedInputChannelMiniBlockIdx, 25);
    inputChannelMiniBlockIdx = fusedInputChannelMiniBlockIdx % 25;
    inputWidthIdx = inputChannelMiniBlockIdx * 49 + fusedInputWidthAndHeightIdx *
      19600;
    inputHeightIdx = fusedInputWidthAndHeightIdx * 1008;
    outputChannelTailCase = (fusedInputWidthAndHeightIdx == 0);
    inputBufferIdx = inputChannelMiniBlockIdx * 51;
    for (inputChannelMiniBlockIdx = 0; inputChannelMiniBlockIdx < 7;
         inputChannelMiniBlockIdx++) {
      AudioSmartSpeakerOnJetsonNano_convolutionKernel_d
        (&inputScratchpadBuffer[inputBufferIdx + inputChannelMiniBlockIdx * 1377],
         &outputTensor[inputWidthIdx], &weightsTensor[inputHeightIdx +
         inputChannelMiniBlockIdx * 9], outputChannelTailCase,
         (inputChannelMiniBlockIdx == 0), (inputChannelMiniBlockIdx == 6),
         &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d(const
  real32_T X[8575], real32_T Z[12250])
{
  static const real32_T b[630] = { 0.0940503F, -0.008856015F, 0.089468114F,
    0.114783995F, -0.045922242F, -0.03422802F, 0.1695459F, -0.034107335F,
    -0.2219383F, -0.16421412F, -0.26470062F, -0.13931887F, -0.22591059F,
    -0.19387408F, -0.10699231F, -0.06409875F, -0.065236025F, 0.06759373F,
    -0.09204647F, -0.08986874F, -0.029413423F, -0.07714347F, -0.1307137F,
    0.2280785F, -0.07044676F, 0.14291175F, 0.12603737F, 0.066717F, -0.015571253F,
    0.024712304F, -0.1284608F, -0.13169616F, 0.13499129F, 0.05408417F,
    0.026724817F, 0.0537031F, 0.096370555F, 0.11312351F, 0.06589837F,
    0.0136883035F, -0.1263677F, 0.16880602F, 0.0026804407F, -0.023885816F,
    0.18729334F, 0.058104247F, -0.08241331F, 0.15989217F, 0.0666556F,
    0.066319674F, -0.021669827F, -0.13126355F, -0.15598813F, -0.107473284F,
    -0.11897934F, -0.06804849F, 0.06534332F, 0.049886115F, 0.06162073F,
    0.062469553F, 0.17515117F, 0.18575567F, 0.21590018F, -0.1453806F,
    0.022473706F, 0.048947643F, -0.014950207F, -0.1025349F, 0.07682141F,
    -0.01061679F, 0.10897759F, -0.07001385F, 0.095220335F, -0.029009745F,
    -0.019022059F, -0.17411569F, -0.13996327F, -0.013903443F, -0.00026803865F,
    -0.073803335F, 0.17783803F, 0.026485063F, -0.00060842815F, -0.03577075F,
    0.00094351015F, -0.20257081F, 0.048783857F, -0.0430971F, -0.08326553F,
    0.018012427F, -0.041897442F, -0.107477464F, 0.043450475F, -0.15567759F,
    -0.15903398F, 0.11835371F, -0.21892616F, 0.0039097145F, 0.015808174F,
    0.026211642F, 0.10953982F, 0.1399168F, -0.08170471F, 0.00921329F,
    0.013398971F, 0.13310122F, 0.14099781F, 0.015260102F, 0.06155929F,
    0.1265807F, 0.03455323F, 0.052965827F, 0.102453165F, 0.11106877F, 0.1512423F,
    0.051140584F, 0.015558289F, 0.05294735F, -0.06621876F, 0.125945F, -0.021007F,
    0.0625913F, 0.043629464F, -0.09480134F, 0.016004983F, -0.027395967F,
    -0.06586584F, -0.07278127F, -0.10257204F, 0.09020818F, 0.13164982F,
    -0.017371168F, 0.20434317F, -0.0045144833F, -0.13598725F, -0.048476785F,
    -0.027265806F, -0.027238457F, 0.05340132F, 0.0042618266F, 0.06579568F,
    0.20026447F, 0.19666977F, 0.13055862F, -0.12379877F, -0.10896119F,
    -0.13026299F, -0.09668431F, 0.02760793F, 0.11950076F, 0.20464869F,
    0.06902335F, -0.118385956F, -0.105886F, -0.13453135F, -0.13473399F,
    -0.1860838F, -0.1816916F, -0.08027825F, 0.014644059F, 0.008861761F,
    -0.012233015F, -0.15022537F, -0.06944397F, 0.02978944F, 0.076842755F,
    -0.006637082F, 0.031400632F, 0.033735584F, 0.025172561F, 0.09543505F,
    0.02130236F, 0.075837694F, 0.011318347F, 0.09714532F, -0.040535443F,
    -0.022350833F, 0.12585315F, -0.11237611F, -0.055546373F, -0.17411809F,
    0.027988737F, 0.04102215F, 0.061244816F, 0.0100738425F, -0.020806942F,
    0.1773371F, 0.22629523F, 0.03979466F, 0.19369942F, 0.04403375F, -0.2597015F,
    0.16149372F, -0.08214133F, -0.14299056F, 0.0072178026F, -0.10005065F,
    -0.1132358F, -0.13040255F, 0.08054259F, 0.018163253F, 0.07116547F,
    0.040380806F, 0.111652814F, 0.19215003F, 0.1010793F, 0.038209636F,
    -0.16959544F, 0.0062363134F, 0.12947083F, 0.12577601F, -0.017053252F,
    0.11858419F, 0.07336623F, 0.07377174F, 0.026973255F, -0.1367903F,
    0.042461768F, 0.063317224F, -0.08885636F, 0.02476347F, 0.01393053F,
    0.1292478F, -0.08038948F, -0.10053128F, -0.076117456F, -0.013149962F,
    -0.0800357F, 0.09546072F, 0.058780607F, -0.12639982F, -0.064036466F,
    -0.08619156F, -0.12701824F, 0.041002236F, 0.046371087F, -0.052375045F,
    0.0048446064F, -0.18666509F, 0.010559709F, -0.2102691F, -0.14621744F,
    -0.15771456F, 0.124190636F, 0.052135352F, -0.01805199F, 0.14145145F,
    -0.032615107F, 0.12990627F, 0.17481658F, -0.017935677F, -0.13238789F,
    0.04444614F, -0.059742007F, -0.20414916F, 0.01726915F, -0.19791129F,
    -0.14813305F, -0.16872384F, 0.02501041F, -0.122581996F, 0.07122706F,
    0.06619532F, 0.028300017F, 0.23312752F, 0.07843431F, -0.013447292F,
    0.047015425F, -0.07972762F, -0.08852974F, -0.07082276F, 0.20782799F,
    0.15060142F, 0.03342792F, -0.13082989F, 0.021355545F, 0.04188777F,
    -0.068787314F, -0.06737788F, 0.16602652F, 0.076549985F, 0.05634684F,
    0.03676688F, -0.04946106F, 0.030903783F, -0.06477091F, 0.09458722F,
    0.06733745F, -0.06561087F, -0.029403972F, -0.08584074F, 0.13209277F,
    0.04523108F, -0.116983764F, 0.039386123F, 0.012588953F, 0.07952141F,
    0.32268268F, -0.01953737F, -0.110778406F, 0.045336634F, -0.0740711F,
    -0.13715224F, -0.04534578F, 0.0324984F, -0.14375648F, 0.004798773F,
    0.11442643F, 0.11466499F, 0.12254134F, 0.063456535F, -0.12438859F,
    0.13695525F, -0.09941992F, 0.0105594685F, -0.078858145F, -0.011200756F,
    0.040989336F, -0.19461413F, -0.04743846F, 0.30093017F, -0.13547373F,
    -0.14518797F, 0.05808345F, 0.057580706F, 0.09037067F, 0.055381197F,
    -0.12928316F, -0.040268295F, 0.10670335F, -0.038046032F, -0.25176197F,
    -0.074249126F, 0.083857864F, -0.104913875F, -0.08999391F, 0.08221578F,
    -0.029440004F, -0.07416659F, -0.022325944F, -0.054772265F, -0.15401746F,
    0.12397547F, 0.05399781F, -0.1285638F, 0.18801884F, -0.0026624557F,
    0.011993905F, -0.03088737F, 0.13155147F, 0.0893035F, 0.13453208F,
    0.16110307F, -0.09233997F, 0.0098601F, 0.05809155F, 0.046591636F,
    -0.11419209F, 0.009268027F, 0.15238126F, 0.08826841F, 0.04428385F,
    -0.19290744F, 0.11987717F, 0.2112337F, 0.16659866F, -0.052112147F,
    0.04060871F, 0.2102484F, 0.05730921F, -0.062762775F, -0.009375904F,
    -0.00413585F, 0.080986924F, 0.012647528F, -0.24408928F, -0.043007825F,
    -0.02371405F, 0.008377223F, -0.033275504F, 0.029355377F, -0.15348704F,
    0.023743706F, 0.049543608F, -0.23340535F, 0.012187813F, 0.16291016F,
    0.102336526F, 0.022771472F, 0.070412084F, -0.021716518F, 0.024778865F,
    0.072833374F, -0.11935577F, -0.0131597025F, 0.09953603F, 0.025973786F,
    -0.067337F, -0.122685365F, 0.060682762F, -0.05958729F, -0.083408214F,
    0.0071271257F, 0.0520407F, -0.021195797F, -0.03900609F, -0.045585323F,
    -0.16131796F, 0.010213459F, -0.052268147F, -0.19484018F, 0.06882212F,
    0.012838419F, -0.15848286F, 0.17057285F, 0.081450745F, 0.013798467F,
    0.023673886F, 0.12702349F, 0.030561097F, 0.1325197F, 0.092713095F,
    0.03570518F, -0.04966945F, -0.17043845F, -0.12237975F, 0.038149834F,
    -0.13763322F, -0.110737704F, 0.073661976F, -0.07013866F, -0.07394338F,
    0.16173886F, 0.04133264F, -0.07108706F, 0.1256031F, 0.078080125F,
    -0.06757977F, 0.1239933F, 0.092131026F, 0.1088236F, -0.13503523F,
    -0.1384827F, 0.13327989F, -0.09704401F, -0.19079559F, -0.10355987F,
    0.10371876F, 0.030378617F, 0.008118058F, -0.08630233F, -0.017585281F,
    0.078470826F, -0.15763982F, -0.095927134F, -0.13401635F, -0.12736146F,
    -0.112129346F, -0.039767522F, 0.14269006F, 0.008985622F, -0.025968343F,
    -0.01598896F, -0.08775638F, -0.06761073F, -0.06006873F, 0.029629746F,
    -0.06534654F, 0.11606047F, 0.0402342F, 0.12807065F, -0.12168465F,
    0.07734972F, 0.08138649F, -0.00019791619F, -0.009047853F, -0.046380784F,
    0.19382104F, 0.16046451F, 0.0764469F, 0.081796795F, -0.032688543F,
    0.025306255F, -0.11149531F, 0.09687341F, -0.11584816F, 0.053243287F,
    0.17083651F, 0.09485967F, 0.10165612F, -0.07562158F, 0.11296825F,
    -0.1393622F, -0.19515248F, -0.09813947F, 0.1364677F, 0.22222054F,
    0.16873391F, -0.043181185F, 0.055073705F, -0.010756763F, -0.14048012F,
    0.0431792F, -0.09655642F, -0.07232524F, -0.17266946F, -0.068529256F,
    0.14870195F, -0.02312781F, -0.12344823F, 0.12718277F, 0.21039641F,
    0.21793029F, -0.09398081F, 0.04798254F, -0.02213032F, 0.026230607F,
    -0.019871218F, -0.041713465F, 0.12874067F, 0.03862918F, -0.011865171F,
    0.090939894F, 0.10620975F, 0.041571677F, -0.12109263F, 0.059617996F,
    0.0058232336F, 0.02140494F, -0.10319671F, -0.118172854F, 0.10594528F,
    0.14659674F, -0.021026878F, -0.05138102F, -0.05510327F, -0.09781825F,
    -0.006503569F, -0.014210261F, -0.17958069F, 0.019562626F, -0.0014340264F,
    0.06820238F, 0.02937424F, 0.019283878F, 0.024909286F, 0.044398546F,
    0.022511756F, 0.09604651F, -0.030395055F, -0.060516894F, -0.10093854F,
    -0.17492527F, -0.17282163F, -0.16258363F, 0.14599688F, -0.051609527F,
    -0.03651869F, -0.03792652F, -0.050769947F, 0.009312449F, -0.057956085F,
    -0.012870077F, 0.042695012F, 0.17849919F, 0.15905981F, 0.054798618F,
    -0.18383788F, 0.05562818F, 0.048068576F, -0.0042059426F, -0.12067368F,
    0.006952757F, 0.079862624F, 0.08612765F, 0.16458748F, -0.031435702F,
    -0.06613176F, 0.0138370935F, -0.009478411F, 0.092604525F, 0.12042226F,
    0.031542957F, 0.039353132F, 0.052260138F, 0.031764418F, -0.031852357F,
    -0.08437086F, -0.12592246F, -0.037003413F, -0.08028146F, -0.005143732F,
    -0.025252549F, -0.08401581F, -0.12722075F, -0.11551508F, -0.051878102F,
    -0.09851537F, -0.14267743F, 0.12428644F, -0.08833293F, 0.010300618F,
    0.047594484F, -0.11846583F, -0.08139862F, -0.097681895F, -0.050202314F,
    -0.13359497F, 0.019591914F, 0.008521953F, 0.020673772F, 0.0866569F,
    0.068946235F, 0.025353828F, 0.14341477F, 0.17531687F, 0.10126511F,
    0.012750097F, 0.1856175F, 0.05787126F, 0.05316885F, -0.077211045F,
    -0.045934267F, -0.013364274F, -0.081450626F, 0.05372619F, -0.047955427F,
    0.0519991F, 0.10396725F, 0.12577134F };

  static const real32_T c[10] = { 0.43634748F, -0.012724526F, -0.07967564F,
    0.3922272F, 0.23098F, -0.2691018F, 0.3270754F, 0.7129787F, 0.3248396F,
    -0.37177798F };

  AudioSmartSpeakerOnJetsonNano_convolution_d(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_h(const
  real32_T X_Data[12250], real32_T Z_Data[3250])
{
  int32_T b_filterWidthIdx;
  int32_T inputHeightIdx_tmp;
  int32_T inputWidthIdx;
  int32_T inputWidthIdx_tmp;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 10; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 13; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 25; outHeightIdx++) {
        inputWidthIdx_tmp = outWidthIdx << 1;
        inputHeightIdx_tmp = outHeightIdx << 1;
        opValue = -3.402823466E+38F;
        if ((inputHeightIdx_tmp > 0) && (inputWidthIdx_tmp > 0) &&
            (inputHeightIdx_tmp + 3 <= 49) && (inputWidthIdx_tmp + 3 <= 25)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = (((inputWidthIdx_tmp + b_filterWidthIdx) - 1) * 49 +
                             inputHeightIdx_tmp) + 1225 * outChannelIdx;
            y = X_Data[inputWidthIdx - 1];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx + 1];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = inputWidthIdx_tmp + b_filterWidthIdx;
            if ((inputHeightIdx_tmp > 0) && (inputWidthIdx > 0) &&
                (inputWidthIdx <= 25)) {
              y = X_Data[(((inputWidthIdx - 1) * 49 + inputHeightIdx_tmp) + 1225
                          * outChannelIdx) - 1];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputWidthIdx <= 25)) {
              y = X_Data[((inputWidthIdx - 1) * 49 + inputHeightIdx_tmp) + 1225 *
                outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputHeightIdx_tmp + 2 <= 49) &&
                (inputWidthIdx <= 25)) {
              y = X_Data[(((inputWidthIdx - 1) * 49 + inputHeightIdx_tmp) + 1225
                          * outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        }

        Z_Data[(outHeightIdx + 25 * outWidthIdx) + 325 * outChannelIdx] =
          opValue;
      }
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_du(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr)
{
  int32_T idxToStrideInputBufferAlongHeight;
  int32_T idxToStrideInputBufferAlongWidth;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister0_0;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_2;
  real32_T outputRegister_3;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  if (!outputChannelTailCase) {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 25;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
        outputRegister_c = biasBufferPtr[13];
        outputRegister_d = biasBufferPtr[14];
        outputRegister_e = biasBufferPtr[15];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 325];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 650];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 975];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 1300];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 1625];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 1950];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 2275];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 2600];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 2925];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 3250];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 3575];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 3900];
        outputRegister_c = outputBufferPtr[outputHeightBlockIdx + 4225];
        outputRegister_d = outputBufferPtr[outputHeightBlockIdx + 4550];
        outputRegister_e = outputBufferPtr[outputHeightBlockIdx + 4875];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 90] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 180] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 270] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 360] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 450] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 540] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 630] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 720] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 810] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 900] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 990] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1080] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1170] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1260] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1350] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 91] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 181] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 271] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 361] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 451] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 541] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 631] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 721] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 811] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 901] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 991] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1081] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1171] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1261] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1351] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 92] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 182] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 272] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 362] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 452] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 542] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 632] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 722] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 812] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 902] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 992] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1082] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1172] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1262] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1352] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 27;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 325] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 325] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 650] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 650] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 975] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 975] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1300] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1300] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1625] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1625] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1950] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1950] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2275] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2275] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2600] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2600] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2925] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2925] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3250] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3250] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3575] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3575] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3900] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3900] = 0.0F;
        }

        if (outputRegister_c >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4225] = outputRegister_c;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4225] = 0.0F;
        }

        if (outputRegister_d >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4550] = outputRegister_d;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4550] = 0.0F;
        }

        if (outputRegister_e >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 4875] = outputRegister_e;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 4875] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 325] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 650] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 975] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 1300] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 1625] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 1950] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 2275] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 2600] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 2925] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 3250] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 3575] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 3900] = outputRegister_b;
        outputBufferPtr[outputHeightBlockIdx + 4225] = outputRegister_c;
        outputBufferPtr[outputHeightBlockIdx + 4550] = outputRegister_d;
        outputBufferPtr[outputHeightBlockIdx + 4875] = outputRegister_e;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  } else {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 25;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 325];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 650];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 975];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 1300];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 1625];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 1950];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 2275];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 2600];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 2925];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 3250];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 90] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 180] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 270] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 360] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 450] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 540] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 630] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 720] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 810] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 900] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 91] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 181] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 271] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 361] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 451] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 541] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 631] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 721] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 811] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 901] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 92] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 182] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 272] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 362] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 452] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 542] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 632] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 722] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 812] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 902] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 27;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 325] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 325] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 650] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 650] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 975] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 975] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1300] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1300] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1625] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1625] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1950] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1950] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2275] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2275] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2600] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2600] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 2925] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 2925] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 3250] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 3250] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 325] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 650] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 975] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 1300] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 1625] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 1950] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 2275] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 2600] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 2925] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 3250] = outputRegister_9;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolution_du(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[6480];
  static boolean_T bufferInitialized;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputBufferIdx;
  int32_T inputChannelMiniBlockIdx;
  int32_T inputHeightIdx;
  int32_T inputWidthIdx;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, (uint32_T)((int32_T)sizeof(real32_T)
            * 6480));
    bufferInitialized = true;
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 3250;
       fusedInputChannelMiniBlockIdx++) {
    inputChannelMiniBlockIdx = div_nde_s32_floor(fusedInputChannelMiniBlockIdx,
      325);
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 325;
    inputWidthIdx = div_nde_s32_floor(fusedInputWidthAndHeightIdx, 25);
    inputHeightIdx = fusedInputWidthAndHeightIdx % 25;
    fusedInputWidthAndHeightIdx = (inputWidthIdx * 25 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 325;
    inputWidthIdx = (inputWidthIdx * 27 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 405;
    for (inputChannelMiniBlockIdx = 1; inputChannelMiniBlockIdx < 2;
         inputChannelMiniBlockIdx++) {
      inputScratchpadBuffer[inputWidthIdx + 28] =
        inputTensor[fusedInputWidthAndHeightIdx];
      inputWidthIdx++;
    }
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 13;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (fusedInputChannelMiniBlockIdx, 13);
    inputChannelMiniBlockIdx = fusedInputChannelMiniBlockIdx % 13;
    inputWidthIdx = inputChannelMiniBlockIdx * 25 + fusedInputWidthAndHeightIdx *
      5200;
    inputHeightIdx = fusedInputWidthAndHeightIdx * 1440;
    outputChannelTailCase = (fusedInputWidthAndHeightIdx == 0);
    inputBufferIdx = inputChannelMiniBlockIdx * 27;
    for (inputChannelMiniBlockIdx = 0; inputChannelMiniBlockIdx < 10;
         inputChannelMiniBlockIdx++) {
      AudioSmartSpeakerOnJetsonNano_convolutionKernel_du
        (&inputScratchpadBuffer[inputBufferIdx + inputChannelMiniBlockIdx * 405],
         &outputTensor[inputWidthIdx], &weightsTensor[inputHeightIdx +
         inputChannelMiniBlockIdx * 9], outputChannelTailCase,
         (inputChannelMiniBlockIdx == 0), (inputChannelMiniBlockIdx == 9),
         &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3(const
  real32_T X[3250], real32_T Z[3575])
{
  static const real32_T b[990] = { 0.14421856F, -0.04664429F, -0.0067649167F,
    0.17620727F, 0.042986788F, 0.10464861F, -0.118150234F, -0.010581502F,
    0.14980835F, -0.015014328F, -0.20481911F, -0.099330634F, -0.056755874F,
    0.00054357614F, -0.09166461F, 0.045213327F, -0.051761918F, 0.05937012F,
    -0.07075589F, -0.1128794F, -0.029712537F, -0.120302275F, -0.07249681F,
    0.08870925F, 0.19667189F, 0.034259528F, -0.17869061F, -0.053102244F,
    -0.04195543F, 0.09311868F, -0.036655042F, 0.03034664F, 0.06025377F,
    0.08165186F, -0.04472144F, -0.015800633F, -0.026658198F, 0.06162745F,
    -0.07482784F, -0.11075486F, -0.065817654F, -0.0145439925F, 0.029734857F,
    -0.112488136F, 0.08062761F, 0.021374293F, 0.015788876F, -0.047738068F,
    0.005126037F, 0.07675044F, 0.07274036F, -0.03089123F, 0.047420688F,
    0.075637735F, 0.13975336F, 0.30329433F, 0.046235785F, 0.041081227F,
    0.008473037F, 0.032580223F, -0.23541462F, -0.14020756F, -0.004576406F,
    0.08597949F, 0.12713838F, -0.07950942F, 0.07787713F, 0.07693866F,
    -0.010451739F, 0.03923944F, 0.073886864F, 0.025605766F, -0.06148306F,
    0.18471342F, 0.14520836F, -0.014590956F, -0.042945698F, -0.025181433F,
    0.10329717F, 0.055504695F, -0.036631312F, 0.09897408F, -0.14684336F,
    -0.20105946F, 0.055011634F, -0.13044266F, 0.044892237F, 0.060032997F,
    -0.08822692F, -0.07426565F, -0.14159821F, -0.09379736F, 0.018515792F,
    0.01933865F, -0.08453015F, 0.08218526F, -0.18873438F, -0.11008949F,
    0.06203455F, -0.17881659F, -0.0690949F, 0.10693622F, -0.051850524F,
    0.05290938F, -0.026297297F, 0.16727717F, 0.20925339F, 0.16498193F,
    0.027426384F, 0.018293312F, -0.023784162F, -0.030289272F, -0.05979118F,
    0.03862157F, -0.025468769F, 0.047854804F, 0.093538105F, -0.019790538F,
    0.051004842F, 0.052708544F, 0.20822592F, -0.015500648F, 0.011187887F,
    0.02541293F, -0.11339762F, -0.029265981F, -0.06626043F, -0.15276563F,
    -0.11530848F, -0.07209006F, 0.013651276F, -0.09149319F, 0.041330155F,
    -0.15704332F, -0.16157949F, -0.12649184F, -0.14154214F, -0.08287998F,
    0.030325232F, 0.04253297F, -0.014504567F, 0.17875543F, 0.122895494F,
    -0.110909685F, 0.17887536F, 0.116253115F, -0.114604F, 0.12059885F,
    -0.018891754F, 0.047394056F, -0.033734806F, -0.09069405F, -0.052812263F,
    -0.065883584F, -0.11555825F, 0.023188937F, 0.047161892F, -0.07502259F,
    -0.019976636F, -0.00016949435F, -0.16425698F, -0.1311069F, 0.019630438F,
    0.004038701F, -0.058968406F, -0.03235643F, -0.024001915F, -0.030605871F,
    -0.13036473F, -0.06390984F, 0.047102716F, -0.17031792F, 0.06296942F,
    0.10548897F, -0.08858877F, 0.05674465F, -0.0027048513F, -0.04572904F,
    0.22302984F, 0.14772478F, -0.0043444675F, 0.045251027F, 0.046607964F,
    0.075016156F, 0.024181278F, 0.10912602F, 0.02538302F, 0.00082023523F,
    -0.06029094F, 0.10057644F, 0.08664122F, -0.016174257F, 0.07851256F,
    0.009246383F, 0.039269146F, -0.09687251F, -0.054980118F, 0.0377307F,
    -0.1078444F, -0.052948277F, -0.12865306F, -0.014323647F, -0.059358228F,
    -0.0886668F, -0.043494124F, -0.043341927F, -0.082751565F, -0.058801256F,
    -0.062195387F, -0.1438329F, -0.0990448F, -0.031362113F, -0.043844175F,
    -0.042315036F, -0.030620143F, -0.096264936F, -0.048579164F, -0.016440948F,
    0.011926736F, -0.06892334F, 0.027464807F, 0.047332466F, 0.023813078F,
    -0.025687447F, 0.006653123F, 0.07176101F, 0.110017546F, 0.01291934F,
    0.07452456F, 0.078034095F, 0.13342077F, -0.020452628F, 0.0083288755F,
    0.08047248F, 0.034078028F, -0.06699848F, 0.011027824F, -0.020116733F,
    -0.0065358365F, -0.04685521F, 0.02941901F, -0.060218684F, -0.0045201546F,
    0.07736115F, 0.07564022F, 0.009700831F, 0.017759698F, 0.0541147F,
    -0.014171291F, 0.027403865F, 0.048433326F, 0.0556872F, -0.0113305235F,
    -0.072893865F, -0.06748895F, 0.06838891F, -0.034887575F, -0.1407567F,
    -0.00075404067F, 0.04613214F, -0.1140971F, 0.0013380933F, 0.029441766F,
    -0.032688957F, -0.04956197F, -0.029068593F, 0.05148093F, -0.10796644F,
    -0.1548749F, -0.053919554F, -0.0069779665F, -0.18352264F, -0.2498403F,
    -0.055698246F, -0.21061124F, -0.11386031F, -0.06055416F, 0.07202219F,
    -0.013982689F, 0.042828638F, -0.0369998F, -0.093639F, -0.046714056F,
    -0.044760313F, -0.045121245F, -0.07880428F, 0.048049606F, 0.022873104F,
    -0.1398477F, -0.028834444F, -0.04233779F, -0.061925128F, 0.025042057F,
    -0.0022948475F, -0.06533293F, -0.21214645F, 0.04012269F, 0.019289095F,
    -0.018007498F, 0.06445187F, 0.005014255F, -0.013793822F, 0.05643548F,
    0.035274275F, -0.15882154F, -0.020586139F, -0.04591643F, -0.073022805F,
    0.023781842F, 0.041177705F, -0.12954351F, -0.15797357F, -0.110489585F,
    -0.06007101F, -0.07011641F, 0.09852447F, -0.008481802F, -0.17918584F,
    0.09730162F, 0.22701304F, 0.05827696F, 0.0025129998F, 0.0030116336F,
    0.10791646F, 0.06651318F, 0.19941251F, -0.1120932F, 0.16810307F, 0.2905017F,
    0.25508612F, -0.03885747F, 0.014021814F, 0.28546947F, -0.115861624F,
    -0.045391995F, -0.11040922F, 0.18330929F, 0.09827707F, -0.15855365F,
    0.05906626F, 0.13597244F, -0.017516438F, -0.03481273F, 0.079629585F,
    -0.042104658F, -0.12644157F, 0.07163397F, 0.23920761F, -0.005338005F,
    -0.09203945F, -0.07309096F, -0.08474497F, 0.03716169F, -0.12239498F,
    0.07830006F, -0.049486827F, 0.034780774F, 0.10280726F, 0.0024455609F,
    -0.027516745F, 0.18152632F, -0.15251426F, -0.14235333F, 0.048485823F,
    -0.10574549F, -0.11149115F, 0.1187432F, -0.18033035F, -0.079780996F,
    0.005118214F, 0.01434196F, 0.09469393F, 0.0057480857F, -0.06047716F,
    0.05641464F, -0.085763F, -0.096053764F, -0.025277223F, -0.013468144F,
    0.025009481F, -0.011433933F, 0.07209682F, 0.17703412F, -0.05268126F,
    0.049248267F, 0.16549118F, 0.018003978F, 0.21998729F, 0.1849466F,
    0.048413437F, 0.18103471F, 0.17689052F, 0.03059326F, -0.012055761F,
    -0.07407291F, -0.08346855F, -0.013258568F, -0.11693316F, -0.0010145664F,
    -0.035659384F, 0.029749464F, 0.049271517F, -0.09763634F, -0.034155063F,
    -0.09174627F, -0.047889933F, -0.03342034F, 0.08122797F, 0.002383773F,
    0.06402562F, -0.17924921F, 0.0926256F, -0.0032029683F, -0.080183506F,
    0.039120603F, -0.105017595F, 0.012377003F, 0.04858739F, 0.058466557F,
    -0.123721264F, 0.012743721F, 0.18797259F, 0.051139597F, 0.11009034F,
    -0.06227438F, -0.016764095F, -0.041850105F, -0.005498937F, 0.04344302F,
    -0.032316078F, -0.16917229F, 0.11837617F, 0.11814357F, -0.05654975F,
    -0.031097542F, -0.03977523F, 0.00074629305F, 0.08083384F, -0.11928632F,
    0.15873632F, 0.15861109F, 0.007174856F, 0.0688762F, 0.100796F, -0.17788225F,
    0.059237294F, -0.073421165F, -0.18631713F, -0.14852019F, -0.004438989F,
    -0.024066452F, -0.17457424F, -0.1648296F, 0.16483997F, -0.08927368F,
    -0.106585175F, 0.22589408F, 0.06125737F, -0.0930313F, -0.07113362F,
    0.017872123F, 0.07988633F, -0.041982874F, 0.063581795F, 0.1042063F,
    -0.056808326F, 0.009178827F, 0.16113913F, -0.17505835F, -0.18200755F,
    -0.0040510194F, 0.04421766F, 0.053075463F, 0.08511929F, 0.10059012F,
    0.08690664F, 0.1532021F, 0.06666283F, 0.10104463F, 0.026333243F,
    -0.060545586F, 0.048031356F, -0.121204264F, 0.18455379F, 0.08597672F,
    -0.0012401171F, 0.08249418F, 0.01944839F, -0.11918316F, -0.058669765F,
    -0.00088334363F, -0.066181235F, 0.011803364F, 0.07469887F, 0.008125734F,
    0.012109493F, -0.036937468F, 0.0016537923F, -0.094038576F, 0.0119606415F,
    0.06338328F, -0.00326291F, 0.14326636F, 0.09488237F, 0.10607546F,
    0.03597438F, 0.06849839F, 0.049761612F, -0.00042864052F, -0.043092266F,
    0.0662518F, 0.12906815F, 0.17500012F, 0.019906636F, 0.057622947F,
    -0.039788812F, 0.016886331F, -0.008404433F, -0.1511637F, 0.05658207F,
    -0.022245605F, 0.030530185F, 0.0930496F, -0.020154819F, -0.07249455F,
    0.0063619055F, 0.027156044F, -0.018093903F, -0.010349391F, -0.10775862F,
    -0.13244769F, -0.01401194F, 0.025989942F, 0.08214033F, -0.06552653F,
    -0.0107931625F, -0.0044582225F, -0.02526963F, 0.0186965F, 0.12018522F,
    0.008781022F, -0.058260113F, 0.0928501F, -0.022196017F, -0.028737947F,
    -0.045704298F, -0.058275007F, -0.07450532F, -0.109186195F, 0.14915593F,
    0.027648192F, -0.02201284F, -0.018316098F, -0.11226761F, -0.17202772F,
    -0.0428513F, -0.11217017F, -0.0049567753F, 0.054351415F, 0.023570038F,
    -0.0763044F, 0.0047135693F, -0.021832688F, -0.05554009F, -0.16250458F,
    -0.16558513F, -0.12751731F, -0.09467636F, -0.042680096F, 0.008917853F,
    -0.086786F, -0.09810899F, 0.0009408142F, -0.06195561F, -0.16756606F,
    -0.114668444F, 0.04340353F, 0.07704048F, -0.098088756F, 0.026598345F,
    -0.039545864F, 0.0005013757F, -0.081813715F, -0.013730593F, -0.09487931F,
    0.0090866545F, -0.13491365F, -0.0684635F, 0.010010254F, 0.1397584F,
    -0.08521118F, 0.0017705126F, 0.20915118F, 0.26460758F, 0.13020426F,
    0.14698084F, 0.11538891F, 0.16633336F, 0.17514001F, 0.13439883F,
    -0.07596584F, 0.10732679F, 0.13740395F, -0.059843123F, -0.21037793F,
    0.019108841F, 0.058700126F, -0.07986248F, -0.077241145F, -0.0026659933F,
    0.070307896F, -0.01722943F, -0.09772756F, -0.08047055F, -0.13033205F,
    -0.09266446F, -0.12015222F, 0.10657702F, -0.14338152F, -0.17670415F,
    0.10569309F, 0.09853255F, 0.05744118F, -0.047440298F, 0.115775466F,
    -0.0035387203F, -0.1372993F, -0.07593716F, -0.058464907F, -0.0037224148F,
    -0.055881504F, 0.0225694F, 0.2205508F, 0.091178745F, 0.06190786F,
    0.106718935F, 0.24896728F, 0.23863572F, 0.086820245F, 0.10142599F,
    -0.06612897F, 0.10178162F, -0.09402814F, -0.045189753F, -0.008768523F,
    0.03711777F, 0.0040915846F, -0.13140184F, -0.083218925F, 0.07543376F,
    0.038028244F, -0.060747486F, 0.0047452007F, 0.07745661F, 0.05055434F,
    0.08660303F, -0.11797584F, -0.12992266F, -0.15612522F, 0.093122095F,
    -0.23622034F, 0.021803077F, 0.14742567F, 0.04580604F, 0.19905205F,
    0.23893651F, -0.061899144F, -0.16030253F, -0.11415296F, -0.12137338F,
    -0.13090546F, -0.09232552F, -0.12224808F, -0.0026483077F, 0.09936951F,
    0.113356486F, -0.06266384F, 0.01564382F, -0.0581775F, -0.052234437F,
    -0.09298492F, -0.10220227F, -0.08051615F, -0.017728083F, 0.008810679F,
    0.017180076F, -0.12376381F, -0.012099213F, -0.07569335F, -0.040456425F,
    0.024282778F, 0.041103605F, -0.037513368F, -0.0055486024F, -0.111433335F,
    -0.23187935F, 0.1739166F, -0.1346343F, 0.03843801F, -0.012180189F,
    -0.075102866F, -0.053233482F, 0.074931026F, -0.11158058F, -0.08697609F,
    0.0597898F, -0.025820443F, -0.22547245F, -0.11144875F, -0.16557683F,
    -0.19256324F, 0.109505564F, -0.01685135F, 0.00823861F, -0.033507798F,
    -0.10753428F, -0.047734376F, 0.041949034F, -0.079480514F, -0.016706537F,
    0.085921966F, 0.12740777F, 0.20808649F, 0.12213463F, 0.22786157F,
    0.16480233F, 0.109326534F, 0.008227359F, -0.1276306F, 0.12610985F,
    0.040984254F, 0.03780195F, 0.07434556F, 0.12113199F, -0.080157764F,
    0.08538089F, -0.049396157F, -0.084349796F, -0.13563573F, -0.013888582F,
    -0.04016739F, 0.07446237F, -0.07634073F, -0.02230049F, -0.13796377F,
    -0.21572578F, -0.14400977F, -0.040682044F, 0.029929651F, 0.03322125F,
    -0.03221706F, 0.0022532826F, -0.005537037F, 0.018717552F, -0.13571304F,
    -0.05247108F, -0.016527707F, -0.028548287F, 0.08718196F, 0.015456878F,
    0.06473142F, -0.015543629F, 0.05334575F, 0.11812813F, 0.08286025F,
    0.029082078F, -0.09676896F, -0.08542515F, 0.017796997F, -0.13526669F,
    -0.16215564F, -0.043729935F, -0.13232338F, -0.14509776F, -0.10701973F,
    -0.03087988F, 0.0652146F, -0.01084876F, -0.1016479F, 0.081948705F,
    -0.034404416F, -0.07271035F, 0.007201435F, 0.015830522F, -0.0947439F,
    0.036582816F, -0.14273015F, -0.06773747F, -0.04995592F, 0.12400902F,
    0.030444179F, 0.04399128F, -0.0013977633F, -0.0011123379F, -0.020181967F,
    0.09449782F, -0.03132989F, -0.10647414F, 0.0051660626F, -0.08648884F,
    0.058529656F, 0.11783847F, 0.010679866F, -0.01951848F, 0.11459168F,
    0.072766475F, -0.003757732F, 0.016179046F, -0.013555891F, -0.080963075F,
    0.050267234F, 0.16409369F, 0.08236579F, -0.011923842F, -0.043454524F,
    -0.04746901F, 0.039294768F, -0.08366393F, -0.09139259F, -0.037215337F,
    -0.1330327F, -0.16694789F, 0.097519375F, -0.03565687F, 0.033418786F,
    -0.03685313F, -0.0070667206F, 0.19869642F, -0.14867276F, -0.033993587F,
    -0.09826398F, 0.23154096F, -0.032247514F, 0.07354085F, 0.017362168F,
    -0.098998934F, -0.10924974F, -0.19362442F, -0.03449635F, 0.013143117F,
    0.2938765F, 0.15872012F, 0.072111085F, 0.2472475F, 0.10663731F,
    -0.070183694F, -0.113224044F, 0.024459474F, 0.09402788F, 0.12707616F,
    -0.06702152F, -0.015711604F, 0.11159287F, 0.007849831F, 0.17140587F,
    -0.04458049F, 0.039289284F, 0.0521107F, -0.060069766F, 0.09340975F,
    0.1708941F, -0.08917941F, 0.0023199585F, 0.2501487F, -0.10880044F,
    0.051814873F, 0.09186952F, -0.043326456F, 0.0011631001F, -0.009940896F,
    0.06433553F, -0.11956766F, -0.016512213F, 0.052896768F, 0.17667067F,
    0.0970289F, 0.004919637F, 0.030050445F, -0.066216126F, -0.23004556F,
    0.049188763F, 0.114187166F, -0.09990204F, -0.024299243F, -0.02037208F,
    -0.014388303F, -0.11950922F, 0.13733114F, 0.05066712F, -0.12276107F,
    0.076597124F, -0.11528966F, -0.20951277F, -0.13946362F, 0.020970404F,
    -0.013836503F, 0.05294352F, 0.0031903402F, -0.10610328F, 0.058743753F,
    0.023546854F, 0.07351179F, 0.020262556F, -0.050027512F, -0.07859535F,
    0.016672166F, -0.12102745F, 0.11859871F, 0.031209905F, 0.05824259F,
    0.110832505F, -0.08516778F, -0.0597814F, -0.005746073F, -0.07995054F,
    0.081315026F, 0.053138167F, -0.048280586F, -0.2037965F, -0.14956483F,
    -0.028407486F, 0.08958534F, 0.025868654F, -0.10628107F, 0.10092119F,
    0.1183092F, 0.0054408135F, -0.009801622F, -0.10795912F, 0.057055525F,
    -0.053762514F, -0.12674513F, -0.18175793F, -0.12517524F, -0.005181024F,
    0.061396953F, 0.039326195F, -0.02947757F, 0.09606315F, 0.005578972F,
    0.05353319F, 0.008839695F, 0.076804236F, 0.002444475F, -0.025095629F,
    0.08099463F, 0.08380483F, -0.016835805F, -0.22233936F, -0.06425286F,
    -0.09924501F, 0.2866978F, -0.065327086F, -0.26207587F, 0.033161297F,
    0.089600265F, 0.22182721F, -0.15333197F, -0.080263644F, -0.074706525F,
    0.111603394F, 0.14065401F, 0.034153905F, -0.04745461F, 0.17724442F,
    0.029595757F, 0.04225641F, 0.09788708F, 0.057573676F, -0.051535532F,
    -0.05789856F, 0.029939309F, -0.12473965F, -0.13256033F, 0.026052127F,
    -0.054171063F, -0.22865477F, 0.057338405F, -0.06034418F, 0.1992675F,
    0.22236036F, -0.0065535707F, 0.008940458F, -0.121955365F, -0.02392335F,
    -0.10395883F, -0.049135994F, 0.0722073F, 0.07183634F, 0.015741276F };

  static const real32_T c[11] = { -0.38790464F, 0.8211123F, 0.5726022F,
    0.45280027F, -0.31378704F, -0.6510777F, 1.3986807F, 1.276312F, 0.1908457F,
    -0.5982506F, 0.33607575F };

  AudioSmartSpeakerOnJetsonNano_convolution_du(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf(const
  real32_T X_Data[3575], real32_T Z_Data[1001])
{
  int32_T b_filterWidthIdx;
  int32_T inputHeightIdx_tmp;
  int32_T inputWidthIdx;
  int32_T inputWidthIdx_tmp;
  int32_T outChannelIdx;
  int32_T outHeightIdx;
  int32_T outWidthIdx;
  real32_T opValue;
  real32_T y;
  for (outChannelIdx = 0; outChannelIdx < 11; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 7; outWidthIdx++) {
      for (outHeightIdx = 0; outHeightIdx < 13; outHeightIdx++) {
        inputWidthIdx_tmp = outWidthIdx << 1;
        inputHeightIdx_tmp = outHeightIdx << 1;
        opValue = -3.402823466E+38F;
        if ((inputHeightIdx_tmp > 0) && (inputWidthIdx_tmp > 0) &&
            (inputHeightIdx_tmp + 3 <= 25) && (inputWidthIdx_tmp + 3 <= 13)) {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = (((inputWidthIdx_tmp + b_filterWidthIdx) - 1) * 25 +
                             inputHeightIdx_tmp) + 325 * outChannelIdx;
            y = X_Data[inputWidthIdx - 1];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            y = X_Data[inputWidthIdx + 1];
            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        } else {
          for (b_filterWidthIdx = 0; b_filterWidthIdx < 3; b_filterWidthIdx++) {
            inputWidthIdx = inputWidthIdx_tmp + b_filterWidthIdx;
            if ((inputHeightIdx_tmp > 0) && (inputWidthIdx > 0) &&
                (inputWidthIdx <= 13)) {
              y = X_Data[(((inputWidthIdx - 1) * 25 + inputHeightIdx_tmp) + 325 *
                          outChannelIdx) - 1];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputWidthIdx <= 13)) {
              y = X_Data[((inputWidthIdx - 1) * 25 + inputHeightIdx_tmp) + 325 *
                outChannelIdx];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }

            if ((inputWidthIdx > 0) && (inputHeightIdx_tmp + 2 <= 25) &&
                (inputWidthIdx <= 13)) {
              y = X_Data[(((inputWidthIdx - 1) * 25 + inputHeightIdx_tmp) + 325 *
                          outChannelIdx) + 1];
            } else {
              y = -3.402823466E+38F;
            }

            if (!(opValue >= y) && !rtIsNaNF(y)) {
              opValue = y;
            }
          }
        }

        Z_Data[(outHeightIdx + 13 * outWidthIdx) + 91 * outChannelIdx] = opValue;
      }
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_duj(const real32_T
  *inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr)
{
  int32_T idxToStrideInputBufferAlongHeight;
  int32_T idxToStrideInputBufferAlongWidth;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister0_0;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_2;
  real32_T outputRegister_3;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  if (!outputChannelTailCase) {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 13;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
        outputRegister_c = biasBufferPtr[13];
        outputRegister_d = biasBufferPtr[14];
        outputRegister_e = biasBufferPtr[15];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 91];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 182];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 273];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 364];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 455];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 546];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 637];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 728];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 819];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 910];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 1001];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 1092];
        outputRegister_c = outputBufferPtr[outputHeightBlockIdx + 1183];
        outputRegister_d = outputBufferPtr[outputHeightBlockIdx + 1274];
        outputRegister_e = outputBufferPtr[outputHeightBlockIdx + 1365];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 99] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 198] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 297] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 396] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 495] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 594] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 693] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 792] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 891] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 990] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1089] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1188] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1287] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1386] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1485] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 100] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 199] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 298] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 397] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 496] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 595] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 694] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 793] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 892] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 991] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1090] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1189] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1288] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1387] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1486] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 101] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 200] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 299] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 398] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 497] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 596] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 695] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 794] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 893] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 992] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1091] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1190] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1289] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1388] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1487] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 15;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 91] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 182] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 273] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 364] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 455] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 546] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 637] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 728] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 819] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 910] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1001] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1092] = 0.0F;
        }

        if (outputRegister_c >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1183] = outputRegister_c;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1183] = 0.0F;
        }

        if (outputRegister_d >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1274] = outputRegister_d;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1274] = 0.0F;
        }

        if (outputRegister_e >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1365] = outputRegister_e;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1365] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
        outputBufferPtr[outputHeightBlockIdx + 1183] = outputRegister_c;
        outputBufferPtr[outputHeightBlockIdx + 1274] = outputRegister_d;
        outputBufferPtr[outputHeightBlockIdx + 1365] = outputRegister_e;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  } else {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 13;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 91];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 182];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 273];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 364];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 455];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 546];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 637];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 728];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 819];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 910];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 99] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 198] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 297] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 396] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 495] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 594] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 693] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 792] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 891] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 990] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 100] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 199] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 298] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 397] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 496] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 595] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 694] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 793] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 892] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 991] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 101] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 200] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 299] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 398] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 497] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 596] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 695] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 794] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 893] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 992] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 15;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 91] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 182] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 273] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 364] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 455] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 546] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 637] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 728] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 819] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 910] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolution_duj(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[2160];
  static boolean_T bufferInitialized;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputBufferIdx;
  int32_T inputChannelMiniBlockIdx;
  int32_T inputHeightIdx;
  int32_T inputWidthIdx;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, (uint32_T)((int32_T)sizeof(real32_T)
            * 2160));
    bufferInitialized = true;
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 1001;
       fusedInputChannelMiniBlockIdx++) {
    inputChannelMiniBlockIdx = div_nde_s32_floor(fusedInputChannelMiniBlockIdx,
      91);
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 91;
    inputWidthIdx = div_nde_s32_floor(fusedInputWidthAndHeightIdx, 13);
    inputHeightIdx = fusedInputWidthAndHeightIdx % 13;
    fusedInputWidthAndHeightIdx = (inputWidthIdx * 13 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 91;
    inputWidthIdx = (inputWidthIdx * 15 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 135;
    for (inputChannelMiniBlockIdx = 1; inputChannelMiniBlockIdx < 2;
         inputChannelMiniBlockIdx++) {
      inputScratchpadBuffer[inputWidthIdx + 16] =
        inputTensor[fusedInputWidthAndHeightIdx];
      inputWidthIdx++;
    }
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 7;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (fusedInputChannelMiniBlockIdx, 7);
    inputChannelMiniBlockIdx = fusedInputChannelMiniBlockIdx % 7;
    inputWidthIdx = inputChannelMiniBlockIdx * 13 + fusedInputWidthAndHeightIdx *
      1456;
    inputHeightIdx = fusedInputWidthAndHeightIdx * 1584;
    outputChannelTailCase = (fusedInputWidthAndHeightIdx == 0);
    inputBufferIdx = inputChannelMiniBlockIdx * 15;
    for (inputChannelMiniBlockIdx = 0; inputChannelMiniBlockIdx < 11;
         inputChannelMiniBlockIdx++) {
      AudioSmartSpeakerOnJetsonNano_convolutionKernel_duj
        (&inputScratchpadBuffer[inputBufferIdx + inputChannelMiniBlockIdx * 135],
         &outputTensor[inputWidthIdx], &weightsTensor[inputHeightIdx +
         inputChannelMiniBlockIdx * 9], outputChannelTailCase,
         (inputChannelMiniBlockIdx == 0), (inputChannelMiniBlockIdx == 10),
         &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3f(
  const real32_T X[1001], real32_T Z[1001])
{
  static const real32_T b[1089] = { 0.09711253F, -0.11086318F, -0.06474234F,
    0.105377436F, 0.0055502267F, -0.10117063F, 0.11656466F, 0.11360576F,
    -0.031712417F, 0.02764758F, 0.009886848F, 0.12965377F, 0.020359866F,
    0.1428579F, 0.19855826F, -0.034394097F, -0.15299125F, -0.08057583F,
    0.1416601F, -0.015755802F, -0.078998476F, 0.105919026F, 0.022910897F,
    -0.059751347F, 0.026114944F, -0.03782368F, 0.04429408F, 0.09703F,
    -0.05509309F, 0.024832623F, -0.009415439F, 0.14391422F, 0.047038402F,
    -0.026060961F, 0.13975266F, 0.033880163F, 0.047081534F, 0.13322085F,
    0.03155944F, -0.011071558F, -0.013375127F, -0.035984594F, -0.056618646F,
    -0.1083152F, 0.026865246F, 0.05407226F, 0.022266142F, 0.0002788186F,
    0.063531935F, 0.06276228F, 0.07446473F, -0.027170394F, -0.07081678F,
    0.023195537F, 0.094072066F, 0.045593765F, -0.0010721408F, 0.061018612F,
    0.058237493F, -0.010727985F, -0.0629613F, 0.060406536F, -0.009274471F,
    0.167882F, 0.095698565F, -0.09003498F, 0.022515913F, -0.02571296F, 0.126696F,
    -0.08169413F, 0.003013663F, 0.27258813F, 0.1481772F, 0.008957274F,
    -0.08150794F, 0.08578102F, -0.079309076F, 0.011938935F, -0.098025635F,
    -0.096122585F, 0.1541358F, -0.16316214F, -0.1703739F, -0.11673839F,
    -0.08243338F, 0.0015157155F, -0.050656546F, 0.09764604F, -0.07816364F,
    -0.14122762F, -0.09688913F, -0.059819162F, 0.14994411F, -0.10972443F,
    -0.037459083F, 0.119981356F, 0.10396458F, -0.036951203F, -0.038878802F,
    -0.051388685F, -0.14361799F, 0.08961752F, -0.124221824F, -0.15447575F,
    0.041743718F, 0.08506239F, 0.14147903F, 0.05251551F, 0.0009949744F,
    0.1577538F, 0.10756486F, 0.021415249F, -0.027180407F, -0.1061943F,
    0.20845701F, -0.022220675F, -0.027599156F, 0.13514186F, -0.024999747F,
    -0.019639388F, -0.037974343F, -0.041682336F, -0.045478113F, 0.06295343F,
    -0.18123607F, -0.26744688F, 0.16481368F, 0.10597204F, -0.01776055F,
    -0.18827677F, -0.060992867F, 0.013783853F, 0.15434794F, 0.2997439F,
    0.10705046F, -0.018073099F, -0.038790375F, -0.14793913F, -0.023762977F,
    0.046364762F, -0.04847567F, -0.18148388F, 0.20358087F, 0.17353292F,
    0.02377384F, 0.08020369F, -0.025470331F, 0.030230345F, 0.0046236487F,
    0.07619927F, -0.0028660544F, -0.05299293F, -0.03272087F, 0.104117386F,
    -0.017557817F, -0.047144026F, -0.11941238F, 0.0923835F, -0.024788488F,
    0.12351244F, 0.0945007F, 0.038497243F, -0.008126699F, 0.0064810165F,
    0.1493485F, -0.040694337F, 0.014933782F, 0.08226059F, 0.27841285F,
    0.2536174F, 0.12070998F, -0.02138028F, 0.011352434F, 0.25251806F,
    0.018853243F, -0.04636796F, 0.06983875F, 0.038473584F, -0.21456236F,
    -0.10882336F, -0.11978007F, 0.002108419F, -0.09395513F, -0.1107969F,
    -0.0049623065F, -0.0129563445F, -0.19991481F, -0.11139076F, 0.14375475F,
    0.040216886F, -0.0700919F, 0.09141338F, 0.08213827F, -0.09088293F,
    0.01308773F, -0.16469656F, -0.07771795F, 0.039861247F, -0.060226258F,
    -0.027319482F, 0.02662954F, 0.030127091F, 0.007738378F, -0.11431339F,
    0.020442741F, -0.06130695F, 0.0018554057F, 0.06736352F, -0.006171223F,
    0.019415211F, 0.06639799F, 0.012729578F, 0.09961202F, -0.08854915F,
    -0.14866643F, 0.14135152F, 0.07461274F, 0.017304065F, -0.14378972F,
    0.039601725F, 0.012115301F, -0.030155934F, 0.047899812F, -0.17128584F,
    -0.08301621F, 0.15244801F, -0.023006225F, -0.06552517F, 0.029548686F,
    0.019364493F, -0.12182664F, -0.07652499F, -0.112794615F, 0.15062355F,
    0.051980603F, 0.14671065F, -0.22619326F, 0.0824475F, 0.14621274F,
    0.058628824F, 0.051384024F, -0.024644544F, 0.043846432F, 0.0802345F,
    0.0065156375F, 0.05783011F, 0.07166895F, 0.14034052F, 0.040823672F,
    -0.012227224F, 0.048121247F, 0.13634552F, -0.046727348F, -0.018890021F,
    -0.020433212F, -0.111743234F, -0.01157637F, -0.1498313F, -0.0040159426F,
    -0.11729094F, -0.060516737F, -0.02084229F, -0.038063005F, -0.12369126F,
    0.010704121F, -0.11075029F, -0.12477451F, 0.13844381F, 0.070802696F,
    0.008749295F, 0.010449969F, 0.04083572F, 0.043377534F, 0.18963915F,
    0.12018308F, -0.019111164F, -0.029793788F, -0.0032013122F, 0.021524785F,
    0.020530706F, -0.088895F, 0.05487111F, -0.20250972F, -0.10764835F,
    0.11145236F, -0.20470582F, -0.0050982893F, 0.1278236F, 0.040022746F,
    -0.057068564F, 0.12039798F, 0.044700645F, -0.021512307F, 0.024366809F,
    -0.049043808F, -0.024836035F, 0.026620714F, 0.20327748F, 0.12890425F,
    -0.14319928F, 0.07722219F, -0.056151096F, -0.034545425F, 0.039522037F,
    -0.056428127F, -0.06689103F, 0.031161021F, 0.073636815F, 0.08273043F,
    0.06753094F, 0.08054237F, -0.087088846F, -0.048696253F, -0.17860578F,
    -0.096032634F, 0.110865384F, -0.04856975F, 0.072616786F, -0.10097418F,
    -0.058245692F, 0.07239348F, -0.03229496F, -0.027712233F, -0.06907513F,
    -0.21540186F, -0.11860318F, 0.044477977F, -0.07183243F, -0.07053137F,
    -0.13319749F, -0.06352177F, -0.030179579F, -0.041274514F, -0.09700475F,
    0.18725684F, 0.12774128F, -0.017961329F, -0.061292566F, -0.041277874F,
    0.10622367F, 0.17514442F, -0.08398055F, -0.0598815F, -0.16051318F,
    -0.11923364F, 0.10987229F, 0.24477316F, 0.15894505F, 0.04713947F,
    -0.111081496F, -0.24540497F, -0.04847036F, 0.10284596F, -0.123150215F,
    -0.12286689F, -0.079573244F, 0.07230649F, 0.04373214F, -0.0856359F,
    0.12265583F, 0.028502444F, 0.07028421F, 0.017895563F, -0.1497684F,
    0.09717531F, 0.07415017F, -0.038541906F, 0.015697481F, 0.06703903F,
    0.3351132F, 0.13986382F, -0.19151936F, 0.07985324F, 0.02068685F, 0.15433352F,
    0.119862944F, 0.09793879F, 0.054260995F, -0.051488556F, 0.06621953F,
    -0.12441758F, 0.08880901F, 0.09154766F, -0.076041766F, -0.13566388F,
    -0.04036277F, -0.1256004F, -0.054373574F, -0.2537101F, -0.1552534F,
    0.324591F, 0.06151223F, -0.151439F, -0.15544209F, -0.0067784223F,
    0.045306534F, 0.011405584F, 0.06581017F, 0.0666451F, 0.064671844F,
    -0.120797165F, 0.024592292F, 0.064141065F, 0.03423276F, -0.025947F,
    -0.16730398F, -0.1501888F, 0.10081307F, -0.013532997F, -0.16283186F,
    -0.037797533F, -0.05039196F, -0.016634557F, -0.039288856F, 0.27177393F,
    0.044792417F, -0.18489943F, 0.021945588F, 0.020128958F, -0.06557493F,
    0.09300166F, -0.123680525F, -0.09778586F, 0.14629859F, -0.026592316F,
    -0.029426036F, 0.09365894F, 0.03363895F, 0.05423252F, 0.08044987F,
    0.0923908F, 0.15784653F, -0.023690796F, 0.01601612F, -0.026021324F,
    0.03197412F, -0.045190338F, -0.013276757F, 0.03416451F, 0.05539424F,
    0.034467F, -0.027456587F, 0.03492752F, -0.02896545F, -0.15202391F,
    -0.079741895F, -0.02038202F, -0.050780065F, -0.007826775F, 0.028692339F,
    0.08434831F, 0.07604086F, 0.027921656F, -0.059850913F, -0.13176288F,
    0.041808676F, 0.0960326F, 0.08965663F, 0.105500795F, -0.1957729F,
    0.03231681F, 0.21209809F, 0.042062044F, 0.16850004F, 0.1621619F, 0.03990674F,
    0.015984451F, 0.032259166F, 0.050413247F, 0.038411904F, -0.07539069F,
    -0.03414402F, -0.033645425F, 0.067828156F, -0.028110439F, -0.04541369F,
    0.11726542F, 0.060500495F, -0.080808826F, -0.096537F, 0.04275401F,
    0.005318925F, -0.01919288F, -0.0036252453F, 0.07438419F, 0.1335598F,
    0.025845574F, -0.0870554F, -0.095615275F, 0.06225286F, 0.08393799F,
    0.03185643F, -0.10861304F, -0.071835175F, 0.006973473F, -0.09000113F,
    0.12260051F, 0.18952277F, 0.05592272F, 0.005258258F, 0.08364026F,
    0.04568328F, -0.010207189F, -0.08760159F, 0.03524079F, 0.054531436F,
    -0.011193212F, 0.0059968443F, 0.12642986F, 0.21354598F, 0.08063217F,
    0.044351872F, -0.030336753F, -0.1073405F, -0.0647491F, -0.09935083F,
    -0.049219348F, 0.047686458F, -0.07755399F, -0.0052998583F, 0.07842913F,
    0.17547214F, 0.046722885F, 0.09368968F, 0.07372841F, 0.0024422498F,
    -0.07999693F, 0.032446492F, -0.005373808F, 0.022285044F, 0.02149928F,
    -0.048976563F, -0.007894928F, -0.13780876F, -0.04385461F, -0.1297098F,
    -0.043626375F, -0.012355705F, -0.049397934F, -0.15830302F, 0.029875197F,
    -0.015164054F, -0.18495941F, -0.03874376F, 0.138024F, -0.00020364873F,
    0.1059516F, 0.07286105F, 0.036820672F, 0.028597826F, 0.09845602F,
    0.12233717F, -0.02084113F, -0.18572292F, -0.09242213F, 0.008523955F,
    0.11888028F, 0.20836769F, 0.03321126F, 0.025625415F, 0.16511607F,
    -0.0129600605F, 0.039749384F, 0.19942322F, 0.0058911946F, -0.027515251F,
    -0.1930661F, -0.05593904F, 0.03466993F, 0.052003648F, -0.009741319F,
    -0.045270544F, 0.07970113F, 0.13137722F, 0.03614486F, 0.00047796822F,
    -0.09618545F, -0.13754573F, -0.06451252F, -0.05969103F, -0.04041551F,
    0.09984545F, 0.013952708F, -0.0005446156F, -0.0019787648F, 0.13731454F,
    0.14370398F, 0.023922589F, 0.0995039F, 0.034470893F, -0.035313703F,
    0.09085509F, -0.081131615F, -0.013621746F, 0.15640189F, 0.120585226F,
    -0.19606121F, 0.16702102F, -0.0033713493F, -0.11862911F, 0.0037854526F,
    -0.053716615F, 0.03693323F, -0.14687549F, -0.25806722F, 0.05293902F,
    -0.05720198F, -0.010389833F, 0.06778885F, -0.011202387F, -0.047478653F,
    0.044649158F, 0.1356109F, 0.018371416F, -0.08550287F, 0.24738728F,
    -0.017186075F, 0.0048823375F, 0.15275554F, 0.065545835F, 0.0016611954F,
    -0.040396105F, -0.02736702F, -0.028666304F, -0.0060738446F, 0.07341581F,
    0.06978671F, -0.04030359F, -0.13235304F, -0.103802755F, 0.026784793F,
    0.20391178F, 0.024007462F, -0.14982893F, 0.06847561F, 0.030186873F,
    -0.077390365F, 0.07634163F, -0.028004864F, -0.227412F, -0.05679386F,
    -0.057001837F, -0.13393869F, 0.052075405F, 0.06934246F, -0.019391455F,
    -0.06652347F, 0.16763958F, 0.0077905413F, 0.11920017F, -0.11514468F,
    0.08094562F, 0.103967674F, 0.020084066F, 0.110951796F, -0.09191411F,
    -0.026860809F, 0.120913595F, 0.08187074F, 0.036403235F, -0.10444545F,
    -0.10850301F, 0.04933781F, 0.008014405F, 0.060253106F, 0.08872836F,
    0.031118078F, 0.14271457F, -0.06607819F, -0.12248907F, -0.06727748F,
    0.0063899523F, 0.057735786F, 0.0015010914F, 0.16243976F, -0.10356275F,
    -0.050136574F, -0.036578048F, 0.0085876435F, -0.028389158F, -0.1534872F,
    0.03850738F, -0.08393584F, -0.0319479F, -0.035662886F, -0.10058038F,
    -0.09461834F, 0.025335655F, 0.03867541F, 0.041399807F, -0.07817348F,
    0.13206138F, -0.03599844F, -0.02829368F, 0.021321038F, -0.14483123F,
    0.03308516F, -0.022996921F, -0.0031172226F, 0.12014243F, -0.00986993F,
    0.04005866F, -0.131817F, -0.116072334F, 0.06695968F, -0.25797686F,
    -0.11637081F, -0.07746765F, -0.2108775F, 0.118658684F, 0.11688067F,
    0.29508728F, 0.016023647F, -0.07692408F, -0.023726678F, -0.16345677F,
    -0.026952446F, -0.05381224F, 0.12191102F, 0.053625483F, -0.06498873F,
    0.014915985F, -0.035646703F, 0.21685046F, 0.045140915F, 0.05160932F,
    -0.13128285F, -0.031922366F, 0.15927006F, 0.0010406905F, 0.052670747F,
    0.003870745F, -0.061041925F, -0.05129996F, 0.05966603F, -0.086477995F,
    0.23288323F, 0.013080751F, -0.060660128F, 0.09184952F, 0.07864321F,
    -0.01594436F, 0.18669817F, 0.03378993F, -0.08724901F, 0.030492624F,
    -0.14631833F, 0.17345311F, -0.05105466F, 0.022762286F, 0.14062344F,
    -0.045556296F, 0.07669359F, -0.16748293F, -0.11452806F, -0.058548898F,
    0.004404822F, 0.007818841F, -0.020040352F, 0.031103944F, -0.071975134F,
    -0.056748707F, 0.10184082F, 0.15931107F, -0.106259726F, 0.06076196F,
    0.12200043F, 0.036848318F, -0.27973333F, -0.20122938F, -0.11009452F,
    0.06952153F, 0.16472994F, 0.04755288F, 0.022400308F, 0.03921623F,
    0.0056223716F, 0.009946105F, -0.01976981F, -0.102368176F, -0.068929195F,
    -0.009883052F, 0.021273661F, 0.057333175F, 0.20638031F, 0.2200996F,
    -0.03945483F, 0.1998357F, 0.14044715F, 0.06911668F, 0.08490759F,
    -0.03621534F, 0.117367804F, 0.1125192F, 0.09680013F, -0.11239417F,
    0.045733064F, 0.09192988F, 0.0515006F, 0.0011535042F, 0.021139812F,
    -0.019038914F, 0.064994335F, -0.08359741F, 0.13715297F, -0.044869725F,
    -0.18004952F, 0.11771883F, -0.026424846F, -0.12616122F, 0.031825352F,
    -0.09432142F, -0.103359595F, -0.12010796F, -0.17313527F, -0.06369323F,
    0.0039761304F, 0.024541125F, -0.14861798F, 0.05454032F, 0.10992652F,
    0.11836221F, -0.17301942F, -0.20177819F, -0.07282589F, 0.0373697F,
    0.12758368F, 0.09362004F, -0.11026456F, -0.19633275F, -0.050362907F,
    -0.04978688F, -0.10078671F, 0.04670089F, 0.03536984F, 0.0034265409F,
    0.11909522F, 0.0419804F, -0.06280549F, 0.14155546F, 0.083459966F,
    -0.025060866F, -0.008537569F, 0.06043948F, -0.15972331F, -0.17283472F,
    -0.006600502F, -0.008922458F, 0.12522417F, -0.040847342F, -0.011149585F,
    -0.03361336F, 0.110058844F, 0.15254034F, -0.053373013F, 0.11190349F,
    -0.07442171F, 0.056056995F, -0.025982564F, 0.055301357F, 0.02131346F,
    0.06134033F, 0.009888466F, -0.076470666F, 0.059870772F, -0.03883695F,
    0.15822135F, 0.07157431F, -0.104384474F, -0.11424884F, 0.18119898F,
    -0.036558703F, -0.14666887F, -0.20140545F, -0.17081082F, -0.18681632F,
    -0.17635754F, 0.050450504F, 0.10518683F, 0.022027263F, 0.003537473F,
    -0.06224902F, -0.045337725F, 0.040707786F, -0.18226776F, 0.053174365F,
    -0.0257222F, -0.038972855F, -0.015449581F, -0.08053007F, -0.044081673F,
    0.057435207F, -0.1483138F, 0.035833247F, -0.028979812F, -0.03429089F,
    0.03584891F, 0.069607876F, 0.03542997F, 0.1293027F, 0.0011637683F,
    0.025452165F, 0.09033822F, -0.054683164F, 0.089240305F, -0.06558854F,
    0.16619699F, 0.065818004F, -0.050093275F, 0.07642201F, 0.016746406F,
    0.09507761F, 0.059145514F, 0.011950359F, 0.009774106F, 0.123121314F,
    0.08407904F, -0.1669393F, -0.021273855F, -0.0008017436F, -0.016826062F,
    0.058059003F, 0.057067968F, -0.054223366F, 0.031803247F, 0.030244805F,
    0.0732914F, -0.19672225F, -0.03895364F, -0.0012427507F, -0.072334915F,
    -0.05431509F, 0.096327394F, -0.15174964F, -0.037251636F, 0.11633623F,
    -0.058798347F, -0.10495625F, 0.0058253133F, -0.11350638F, -0.017112885F,
    0.008395482F, -0.05333972F, -0.0008567195F, 0.01374249F, -0.023993956F,
    -0.13972433F, -0.019054322F, 0.0699299F, -0.022068629F, -0.09415769F,
    -0.025781984F, -0.011409286F, 0.025448048F, 0.038963914F, 0.020602865F,
    0.084652565F, 0.014234212F, 0.061570067F, 0.02826103F, -0.042304255F,
    -0.01816113F, 0.12439111F, -0.1124338F, -0.0023487564F, 0.061273057F,
    -0.08943038F, -0.008449769F, 0.037355535F, 0.056289136F, 0.092171595F,
    0.07673346F, 0.018176885F, 0.05427627F, 0.043973595F, 0.037153825F,
    -0.08056983F, -0.05786356F, 0.06007739F, -0.1310462F, -0.07937966F,
    -0.004101292F, -0.010801245F, 0.0015359203F, -0.02747386F, 0.068394236F,
    0.12806916F, 0.0669267F, 0.10011531F, -0.025167637F, 0.0717556F,
    -0.07569873F, 0.020772312F, 0.022078423F, 0.12856251F, -0.037425052F,
    0.0432405F, -0.123060696F, 0.10600474F, -0.044590306F, -0.121235244F,
    -0.06610652F, 0.06380373F, 0.051322114F, 0.14774168F, -0.006808065F,
    0.0037578603F, 0.04084258F, 0.18513775F, 0.18996654F, -0.016921693F,
    -0.042175516F, -0.056920815F, -0.04466742F, -0.010565669F, -0.1714902F,
    -0.040540166F, 0.020356571F, 0.09238886F, 0.12025088F, -0.0051392494F,
    0.05114911F, 0.06866253F, -0.017476965F, -0.024292367F, -0.25813013F,
    -0.12393317F, -0.12501432F, -0.005934107F, -0.08240902F, -0.020479402F,
    -0.0072457623F, -0.11119195F, 0.03073433F, 0.043581966F, -0.0532474F,
    -0.07461753F, -0.18848978F, 0.028258774F, 0.025241211F, 0.042101976F,
    -0.015309001F, -0.005525229F, -0.053198855F, 0.21866253F, 0.14466366F,
    0.15875262F, -0.016117504F, -0.1300031F, -0.07788725F, 0.009458254F,
    -0.16807453F, -0.24286091F, -0.045094337F, -0.009282491F, 0.07153199F,
    -0.043432828F, -0.09729438F, 0.17975576F, -0.05440277F, 0.107567F,
    0.10811434F, 0.075242296F, 0.0476996F, -0.031457536F, 0.052377287F,
    -0.09257974F, 0.13405338F, -0.051561236F, 0.14973493F, 0.30857822F,
    -0.056121137F, 0.16513525F, 0.017739395F, -0.048329886F, -0.04090739F,
    -0.010455614F, -0.07932183F, -0.058251582F, 0.108871415F, -0.024097193F,
    -0.19794708F, -0.06672081F, -0.04298393F, 0.13143086F, -0.07662467F,
    0.06765517F, -0.052274488F, -0.09691757F };

  static const real32_T c[11] = { -1.059772F, -0.63609207F, -0.13613713F,
    0.095847234F, -0.820487F, -1.0055656F, -0.1007532F, -0.77645916F, 0.8591874F,
    -0.537867F, -0.037461877F };

  AudioSmartSpeakerOnJetsonNano_convolution_duj(&X[0], &Z[0], &b[0], &c[0]);
}

static void AudioSmartSpeakerOnJetsonNano_convolutionKernel_dujn(const real32_T *
  inputBufferPtr, real32_T *outputBufferPtr, const real32_T *weightsBufferPtr,
  boolean_T outputChannelTailCase, boolean_T
  canInitializeOutputRegistersWithBiasValues, boolean_T
  canApplyActivationOperation, const real32_T *biasBufferPtr)
{
  int32_T idxToStrideInputBufferAlongHeight;
  int32_T idxToStrideInputBufferAlongWidth;
  int32_T kernelWidthIdx;
  int32_T outputHeightBlockIdx;
  real32_T inputRegister0_0;
  real32_T outputRegister;
  real32_T outputRegister_0;
  real32_T outputRegister_1;
  real32_T outputRegister_2;
  real32_T outputRegister_3;
  real32_T outputRegister_4;
  real32_T outputRegister_5;
  real32_T outputRegister_6;
  real32_T outputRegister_7;
  real32_T outputRegister_8;
  real32_T outputRegister_9;
  real32_T outputRegister_a;
  real32_T outputRegister_b;
  real32_T outputRegister_c;
  real32_T outputRegister_d;
  real32_T outputRegister_e;
  if (!outputChannelTailCase) {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 13;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
        outputRegister_c = biasBufferPtr[13];
        outputRegister_d = biasBufferPtr[14];
        outputRegister_e = biasBufferPtr[15];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 91];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 182];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 273];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 364];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 455];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 546];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 637];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 728];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 819];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 910];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 1001];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 1092];
        outputRegister_c = outputBufferPtr[outputHeightBlockIdx + 1183];
        outputRegister_d = outputBufferPtr[outputHeightBlockIdx + 1274];
        outputRegister_e = outputBufferPtr[outputHeightBlockIdx + 1365];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 99] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 198] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 297] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 396] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 495] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 594] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 693] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 792] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 891] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 990] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1089] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1188] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1287] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1386] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1485] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 100] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 199] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 298] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 397] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 496] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 595] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 694] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 793] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 892] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 991] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1090] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1189] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1288] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1387] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1486] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 101] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 200] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 299] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 398] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 497] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 596] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 695] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 794] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 893] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 992] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1091] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1190] *
          inputRegister0_0;
        outputRegister_c += weightsBufferPtr[kernelWidthIdx * 3 + 1289] *
          inputRegister0_0;
        outputRegister_d += weightsBufferPtr[kernelWidthIdx * 3 + 1388] *
          inputRegister0_0;
        outputRegister_e += weightsBufferPtr[kernelWidthIdx * 3 + 1487] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 15;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 91] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 182] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 273] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 364] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 455] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 546] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 637] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 728] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 819] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 910] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1001] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1092] = 0.0F;
        }

        if (outputRegister_c >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1183] = outputRegister_c;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1183] = 0.0F;
        }

        if (outputRegister_d >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1274] = outputRegister_d;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1274] = 0.0F;
        }

        if (outputRegister_e >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1365] = outputRegister_e;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1365] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
        outputBufferPtr[outputHeightBlockIdx + 1183] = outputRegister_c;
        outputBufferPtr[outputHeightBlockIdx + 1274] = outputRegister_d;
        outputBufferPtr[outputHeightBlockIdx + 1365] = outputRegister_e;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  } else {
    idxToStrideInputBufferAlongHeight = 0;
    for (outputHeightBlockIdx = 0; outputHeightBlockIdx < 13;
         outputHeightBlockIdx++) {
      if (canInitializeOutputRegistersWithBiasValues) {
        outputRegister = biasBufferPtr[0];
        outputRegister_0 = biasBufferPtr[1];
        outputRegister_1 = biasBufferPtr[2];
        outputRegister_2 = biasBufferPtr[3];
        outputRegister_3 = biasBufferPtr[4];
        outputRegister_4 = biasBufferPtr[5];
        outputRegister_5 = biasBufferPtr[6];
        outputRegister_6 = biasBufferPtr[7];
        outputRegister_7 = biasBufferPtr[8];
        outputRegister_8 = biasBufferPtr[9];
        outputRegister_9 = biasBufferPtr[10];
        outputRegister_a = biasBufferPtr[11];
        outputRegister_b = biasBufferPtr[12];
      } else {
        outputRegister = outputBufferPtr[outputHeightBlockIdx];
        outputRegister_0 = outputBufferPtr[outputHeightBlockIdx + 91];
        outputRegister_1 = outputBufferPtr[outputHeightBlockIdx + 182];
        outputRegister_2 = outputBufferPtr[outputHeightBlockIdx + 273];
        outputRegister_3 = outputBufferPtr[outputHeightBlockIdx + 364];
        outputRegister_4 = outputBufferPtr[outputHeightBlockIdx + 455];
        outputRegister_5 = outputBufferPtr[outputHeightBlockIdx + 546];
        outputRegister_6 = outputBufferPtr[outputHeightBlockIdx + 637];
        outputRegister_7 = outputBufferPtr[outputHeightBlockIdx + 728];
        outputRegister_8 = outputBufferPtr[outputHeightBlockIdx + 819];
        outputRegister_9 = outputBufferPtr[outputHeightBlockIdx + 910];
        outputRegister_a = outputBufferPtr[outputHeightBlockIdx + 1001];
        outputRegister_b = outputBufferPtr[outputHeightBlockIdx + 1092];
      }

      idxToStrideInputBufferAlongWidth = idxToStrideInputBufferAlongHeight;
      for (kernelWidthIdx = 0; kernelWidthIdx < 3; kernelWidthIdx++) {
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 99] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 198] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 297] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 396] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 495] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 594] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 693] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 792] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 891] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 990] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1089] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1188] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 1];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 1] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 100] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 199] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 298] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 397] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 496] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 595] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 694] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 793] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 892] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 991] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1090] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1189] *
          inputRegister0_0;
        inputRegister0_0 = inputBufferPtr[idxToStrideInputBufferAlongWidth + 2];
        outputRegister += weightsBufferPtr[kernelWidthIdx * 3 + 2] *
          inputRegister0_0;
        outputRegister_0 += weightsBufferPtr[kernelWidthIdx * 3 + 101] *
          inputRegister0_0;
        outputRegister_1 += weightsBufferPtr[kernelWidthIdx * 3 + 200] *
          inputRegister0_0;
        outputRegister_2 += weightsBufferPtr[kernelWidthIdx * 3 + 299] *
          inputRegister0_0;
        outputRegister_3 += weightsBufferPtr[kernelWidthIdx * 3 + 398] *
          inputRegister0_0;
        outputRegister_4 += weightsBufferPtr[kernelWidthIdx * 3 + 497] *
          inputRegister0_0;
        outputRegister_5 += weightsBufferPtr[kernelWidthIdx * 3 + 596] *
          inputRegister0_0;
        outputRegister_6 += weightsBufferPtr[kernelWidthIdx * 3 + 695] *
          inputRegister0_0;
        outputRegister_7 += weightsBufferPtr[kernelWidthIdx * 3 + 794] *
          inputRegister0_0;
        outputRegister_8 += weightsBufferPtr[kernelWidthIdx * 3 + 893] *
          inputRegister0_0;
        outputRegister_9 += weightsBufferPtr[kernelWidthIdx * 3 + 992] *
          inputRegister0_0;
        outputRegister_a += weightsBufferPtr[kernelWidthIdx * 3 + 1091] *
          inputRegister0_0;
        outputRegister_b += weightsBufferPtr[kernelWidthIdx * 3 + 1190] *
          inputRegister0_0;
        idxToStrideInputBufferAlongWidth += 15;
      }

      if (canApplyActivationOperation) {
        if (outputRegister >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        } else {
          outputBufferPtr[outputHeightBlockIdx] = 0.0F;
        }

        if (outputRegister_0 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 91] = 0.0F;
        }

        if (outputRegister_1 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 182] = 0.0F;
        }

        if (outputRegister_2 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 273] = 0.0F;
        }

        if (outputRegister_3 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 364] = 0.0F;
        }

        if (outputRegister_4 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 455] = 0.0F;
        }

        if (outputRegister_5 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 546] = 0.0F;
        }

        if (outputRegister_6 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 637] = 0.0F;
        }

        if (outputRegister_7 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 728] = 0.0F;
        }

        if (outputRegister_8 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 819] = 0.0F;
        }

        if (outputRegister_9 >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 910] = 0.0F;
        }

        if (outputRegister_a >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1001] = 0.0F;
        }

        if (outputRegister_b >= 0.0F) {
          outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
        } else {
          outputBufferPtr[outputHeightBlockIdx + 1092] = 0.0F;
        }
      } else {
        outputBufferPtr[outputHeightBlockIdx] = outputRegister;
        outputBufferPtr[outputHeightBlockIdx + 91] = outputRegister_0;
        outputBufferPtr[outputHeightBlockIdx + 182] = outputRegister_1;
        outputBufferPtr[outputHeightBlockIdx + 273] = outputRegister_2;
        outputBufferPtr[outputHeightBlockIdx + 364] = outputRegister_3;
        outputBufferPtr[outputHeightBlockIdx + 455] = outputRegister_4;
        outputBufferPtr[outputHeightBlockIdx + 546] = outputRegister_5;
        outputBufferPtr[outputHeightBlockIdx + 637] = outputRegister_6;
        outputBufferPtr[outputHeightBlockIdx + 728] = outputRegister_7;
        outputBufferPtr[outputHeightBlockIdx + 819] = outputRegister_8;
        outputBufferPtr[outputHeightBlockIdx + 910] = outputRegister_9;
        outputBufferPtr[outputHeightBlockIdx + 1001] = outputRegister_a;
        outputBufferPtr[outputHeightBlockIdx + 1092] = outputRegister_b;
      }

      idxToStrideInputBufferAlongHeight++;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_convolution_dujn(const real32_T
  *inputTensor, real32_T *outputTensor, const real32_T *weightsTensor, const
  real32_T *biasTensor)
{
  static real32_T inputScratchpadBuffer[2160];
  static boolean_T bufferInitialized;
  int32_T fusedInputChannelMiniBlockIdx;
  int32_T fusedInputWidthAndHeightIdx;
  int32_T inputBufferIdx;
  int32_T inputChannelMiniBlockIdx;
  int32_T inputHeightIdx;
  int32_T inputWidthIdx;
  boolean_T outputChannelTailCase;
  if (!bufferInitialized) {
    memset(&inputScratchpadBuffer[0], 0, (uint32_T)((int32_T)sizeof(real32_T)
            * 2160));
    bufferInitialized = true;
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 1001;
       fusedInputChannelMiniBlockIdx++) {
    inputChannelMiniBlockIdx = div_nde_s32_floor(fusedInputChannelMiniBlockIdx,
      91);
    fusedInputWidthAndHeightIdx = fusedInputChannelMiniBlockIdx % 91;
    inputWidthIdx = div_nde_s32_floor(fusedInputWidthAndHeightIdx, 13);
    inputHeightIdx = fusedInputWidthAndHeightIdx % 13;
    fusedInputWidthAndHeightIdx = (inputWidthIdx * 13 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 91;
    inputWidthIdx = (inputWidthIdx * 15 + inputHeightIdx) +
      inputChannelMiniBlockIdx * 135;
    for (inputChannelMiniBlockIdx = 1; inputChannelMiniBlockIdx < 2;
         inputChannelMiniBlockIdx++) {
      inputScratchpadBuffer[inputWidthIdx + 16] =
        inputTensor[fusedInputWidthAndHeightIdx];
      inputWidthIdx++;
    }
  }

  for (fusedInputChannelMiniBlockIdx = 0; fusedInputChannelMiniBlockIdx < 7;
       fusedInputChannelMiniBlockIdx++) {
    fusedInputWidthAndHeightIdx = div_nde_s32_floor
      (fusedInputChannelMiniBlockIdx, 7);
    inputChannelMiniBlockIdx = fusedInputChannelMiniBlockIdx % 7;
    inputWidthIdx = inputChannelMiniBlockIdx * 13 + fusedInputWidthAndHeightIdx *
      1456;
    inputHeightIdx = fusedInputWidthAndHeightIdx * 1584;
    outputChannelTailCase = (fusedInputWidthAndHeightIdx == 0);
    inputBufferIdx = inputChannelMiniBlockIdx * 15;
    for (inputChannelMiniBlockIdx = 0; inputChannelMiniBlockIdx < 11;
         inputChannelMiniBlockIdx++) {
      AudioSmartSpeakerOnJetsonNano_convolutionKernel_dujn
        (&inputScratchpadBuffer[inputBufferIdx + inputChannelMiniBlockIdx * 135],
         &outputTensor[inputWidthIdx], &weightsTensor[inputHeightIdx +
         inputChannelMiniBlockIdx * 9], outputChannelTailCase,
         (inputChannelMiniBlockIdx == 0), (inputChannelMiniBlockIdx == 10),
         &biasTensor[fusedInputWidthAndHeightIdx << 4]);
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3fr(
  const real32_T X[1001], real32_T Z[1183])
{
  static const real32_T b[1287] = { -0.06831225F, -0.16714513F, 0.15000324F,
    0.17698252F, 0.44652873F, -0.031143235F, -0.13489056F, 0.13271761F,
    0.3868476F, 0.061938472F, 0.44774988F, -0.046388805F, -0.108988576F,
    0.47669783F, -0.12390971F, -0.25831318F, -0.4064452F, -0.1490907F,
    -0.13406429F, -0.21806742F, -0.062098023F, -0.004369201F, 0.18705158F,
    0.28612757F, 0.022112288F, 0.020861246F, 0.0015990424F, -0.18481496F,
    -0.08707902F, -0.029424315F, -0.014382256F, 0.027609002F, -0.27257547F,
    -0.051356416F, -0.23485422F, -0.43103656F, 0.123522654F, 0.12969373F,
    0.41408944F, -0.33735195F, -0.6512878F, -0.20661423F, -0.05906232F,
    -0.1266643F, 0.0394238F, 0.15168808F, -0.23242158F, -0.100837946F,
    -0.013461316F, -0.077096365F, -0.11473907F, -0.29738572F, -0.10570591F,
    0.10420975F, 0.056026943F, -0.21428503F, 0.29667675F, 0.31676444F,
    0.09432454F, -0.22951464F, -0.050259825F, -0.45426357F, -0.22250777F,
    -0.3372766F, -0.15816487F, -0.13252394F, -0.08159933F, 0.18035191F,
    0.03803231F, 0.30666894F, 0.11318146F, 0.009584599F, -0.09333405F,
    -0.07130205F, 0.26509234F, -0.021204382F, -0.1933201F, 0.11947238F,
    0.10375248F, -0.012869472F, -0.15283895F, 0.3780249F, 0.10542465F,
    -0.014778563F, 0.30740392F, -0.34342653F, -0.3282911F, 0.15814681F,
    -0.2407712F, 0.051462356F, 0.34250447F, 0.15498185F, 0.13169125F,
    0.37166324F, 0.19596992F, 0.19194455F, -0.047002494F, -0.15511137F,
    0.14729546F, -0.13586937F, -0.25038803F, -0.11538844F, 0.1542478F,
    -0.1298266F, 0.10936055F, 0.08422165F, 0.18956256F, 0.10111675F,
    -0.26755157F, -0.097916745F, 0.06765486F, -0.35597125F, 0.02421956F,
    0.28358582F, 0.09921089F, -0.22288048F, -0.38201678F, 0.029472586F,
    -0.050145928F, -0.028568612F, -0.103573315F, -0.06433376F, 0.17092398F,
    -0.115342356F, 0.12053056F, -0.14350663F, -0.10741406F, -0.017920539F,
    -0.04055003F, 0.08827196F, 0.044477843F, 0.10757157F, -0.07915117F,
    -0.30461168F, -0.29102767F, -0.16938047F, -0.07227144F, -0.05481631F,
    -0.00842533F, -0.11692568F, 0.14620419F, -0.12826589F, -0.20524064F,
    -0.036470447F, 0.13441049F, 0.190046F, 0.10420339F, 0.3739644F, 0.13851601F,
    -0.09882083F, -0.098485924F, 0.24821888F, -0.047279406F, -0.04929894F,
    0.13871679F, 0.02940718F, -0.24849355F, -0.1776396F, -0.026387755F,
    -0.021873457F, -0.103122324F, -0.083146125F, 0.12572145F, -0.098111905F,
    0.15015908F, 0.17670526F, -0.23449898F, -0.1389748F, -0.16734512F,
    0.02040149F, 0.027542466F, 0.11885375F, 0.10159427F, 0.12685002F,
    0.17116064F, 0.38499936F, 0.012840212F, -0.11988913F, -0.053200074F,
    -0.0021617603F, 0.24953753F, 0.19769445F, -0.09612583F, 0.12312853F,
    0.16053475F, 0.007395929F, 0.31351954F, 0.20423669F, -0.19676627F,
    0.30154192F, -0.16879548F, 0.19620115F, 0.18682206F, 0.177942F, 0.05969381F,
    -0.17552933F, -0.30368036F, -0.041254874F, -0.12822606F, -0.08966099F,
    -0.09223832F, 0.017952671F, 0.071052246F, 0.32861534F, 0.015118207F,
    0.10270525F, 0.08044024F, -0.041889187F, -0.2782698F, -0.4293872F,
    0.3154709F, 0.30769116F, 0.16578259F, -0.099782094F, 0.010711619F,
    -0.056586146F, 0.09068764F, -0.06305581F, -0.060057126F, -0.114128806F,
    0.04916074F, 0.08954696F, 0.118490495F, -0.031431112F, -0.37689966F,
    -0.13008541F, -0.020321013F, 0.0733526F, 0.13341707F, -0.15052877F,
    0.016585892F, -0.08734607F, 0.09004936F, 0.04310295F, -0.10120786F,
    -0.14448117F, 0.17797448F, -0.12628931F, -0.15164804F, -0.0011091257F,
    0.12919861F, 0.116501644F, 0.60513073F, 0.33541045F, 0.3218561F, 0.17420255F,
    -0.35041636F, -0.18280336F, -0.17204839F, -0.060422383F, -0.059923563F,
    0.029172447F, -0.040085215F, -0.30531105F, 0.3317994F, 0.0007064301F,
    0.16607262F, 0.098414116F, -0.04843214F, 0.046683412F, 0.037758663F,
    -0.13382258F, 0.2686729F, -0.20798708F, 0.052757908F, 0.010553815F,
    -0.2412525F, 0.018921318F, -0.008944818F, 0.15729284F, -0.101825625F,
    -0.25177246F, 0.50651926F, -0.1325229F, -0.19068782F, -0.06934686F,
    -0.0064133345F, -0.25773624F, -0.2496939F, -0.16157351F, 0.20989332F,
    -0.041782413F, 0.15434577F, -0.11197444F, 0.088839814F, -0.071378306F,
    0.166653F, -0.33241868F, 0.06288208F, -0.062283915F, -0.23420283F,
    -0.10793497F, -0.3664267F, 0.021005344F, -0.042423785F, 0.42539048F,
    0.35936204F, 0.111025535F, -0.037108384F, -0.12603262F, -0.29066542F,
    -0.14572012F, -0.28317547F, -0.15259561F, -0.064791456F, -0.07730601F,
    -0.06513654F, -0.0255689F, -0.028651696F, -0.025465311F, -0.096150756F,
    -0.032722432F, -0.022341715F, 0.16446789F, 0.19339162F, 0.22099014F,
    0.029226964F, -0.11561455F, -0.14813828F, -0.21156341F, -0.0898255F,
    0.12865247F, 0.06439782F, -0.09381577F, 0.19733746F, 0.30362156F, 0.1512367F,
    0.43676996F, 0.31600073F, 0.32845244F, -0.115227774F, -0.16887143F,
    0.029125407F, 0.18903224F, 0.025709106F, -0.12398611F, 0.016954608F,
    -0.02919779F, 0.15653005F, -0.06208767F, 0.014724482F, 0.0353563F,
    0.31309775F, 0.057081107F, -0.07649198F, 0.0028961508F, -0.17075649F,
    0.0012503376F, -0.12762623F, -0.008641149F, 0.046220522F, 0.27853385F,
    0.16995357F, 0.030041285F, 0.070567474F, -0.0873503F, 0.050795786F,
    0.013336442F, -0.20080353F, 0.05575071F, -0.19001912F, -0.1983203F,
    -0.264197F, 0.08158505F, 0.02147238F, -0.0064047324F, 0.097085066F,
    0.061141275F, -0.02638308F, -0.033290423F, -0.033068635F, 0.034650806F,
    0.19704244F, -0.18428949F, -0.03315224F, 0.29329702F, 0.33168188F,
    0.28248253F, -0.053555053F, -0.07596202F, -0.029937001F, -0.067961715F,
    0.0023020764F, -0.12313236F, 0.24540552F, 0.15340596F, 0.045460213F,
    0.27427623F, -0.094371416F, 0.14002073F, 0.36350337F, 0.060024228F,
    0.1633415F, -0.10887667F, -0.10629158F, 0.015815828F, 0.02819516F,
    0.24645716F, 0.17404154F, 0.01026513F, -0.15330988F, -0.09830821F,
    0.049669906F, -0.05735352F, -0.053210497F, -0.028339943F, -0.20566708F,
    -0.1301479F, -0.19646147F, -0.107767105F, -0.1202316F, 0.06835419F,
    0.10731139F, 0.25625685F, 0.07032539F, 0.07093043F, -0.053159915F,
    -0.10082764F, -0.14661816F, -0.026825879F, 0.02248259F, 0.15294684F,
    0.38721603F, 0.032408856F, 0.053535357F, -0.014473797F, -0.047951236F,
    -0.092931904F, -0.43341917F, -0.075043015F, -0.14928678F, -0.036554243F,
    0.2740289F, 0.27994817F, -0.07827678F, -0.06751937F, 0.009563564F,
    -0.106320046F, -0.15431704F, -0.11437083F, -0.095200524F, -0.07523866F,
    -0.26118314F, -0.111282185F, 0.1283237F, -0.28100127F, -0.14346336F,
    -0.24382503F, -0.049100157F, -0.13223526F, 0.091747805F, 0.48886862F,
    0.2568951F, 0.069456525F, 0.19645815F, -0.0016841424F, -0.23515116F,
    -0.1543874F, -0.104724355F, 0.017754838F, 0.13062237F, 0.32360604F,
    -0.04510347F, 0.029863648F, -0.054114383F, 0.07873326F, -0.00013999616F,
    0.11956441F, 0.16137332F, -0.13275298F, -0.103254765F, 0.22451904F,
    -0.194261F, 0.0875099F, -0.21037897F, 0.1519582F, 0.1554053F, -0.2467988F,
    -0.07525615F, 0.12629439F, -0.14265428F, 0.24303432F, -0.15885222F,
    0.397538F, 0.5004372F, -0.09571422F, 0.09211917F, 0.048788056F, 0.056439534F,
    0.23091982F, 0.11450713F, 0.0061481255F, -0.12791868F, -0.048045497F,
    0.06078317F, -0.20832658F, -0.19910231F, -0.026692342F, -0.13838115F,
    -0.29712912F, -0.14200447F, -0.22239709F, -0.05631804F, 0.03725821F,
    -0.24235716F, -0.27953765F, 0.08256543F, -0.25168768F, 0.25781327F,
    0.19582263F, -0.29180735F, -0.036937315F, 0.15113446F, -0.13027054F,
    0.40874803F, 0.6153168F, -0.07000303F, 0.06688103F, 0.33382398F,
    0.047871225F, -0.09445756F, -0.07799334F, 0.029159533F, 0.1761524F,
    -0.045983966F, -0.18852481F, 0.18800606F, -0.06817533F, -0.35799602F,
    -0.06993743F, -0.44840154F, -0.15140606F, -0.15494339F, 0.066192865F,
    -0.008372942F, -0.045389425F, 0.13589986F, 0.12654833F, 0.059554838F,
    -0.0034339216F, -0.16406095F, -0.02111307F, -0.15682667F, 0.15659076F,
    0.16572574F, -0.08383164F, 0.06784685F, 0.09464093F, -0.020403609F,
    0.0839956F, 0.13782884F, -0.10984092F, 0.011854414F, 0.31230468F,
    -0.014848904F, 0.0109978765F, 0.05379443F, -0.10832349F, 0.20315464F,
    -0.16622275F, -0.28621233F, 0.3705985F, 0.17328994F, -0.116592355F,
    -0.056559797F, -0.077639334F, -0.2940248F, -0.24059494F, -0.10447774F,
    -0.031623006F, 0.114725664F, 0.100311786F, -0.057137873F, -0.17606826F,
    -0.25526944F, 0.0046363533F, 0.40109056F, -0.023655692F, 0.045623414F,
    0.32998696F, 0.067863785F, -0.06383772F, -0.059022933F, -0.20329195F,
    -0.029698834F, -0.21653402F, -0.16325359F, -0.173839F, 0.16173075F,
    -0.061797034F, -0.052279297F, -0.012547941F, 0.083900146F, -0.048625235F,
    0.055896107F, 0.06386064F, -0.07113526F, 0.3067609F, 0.10540452F,
    -0.053202078F, 0.13513924F, -0.12325274F, -0.070782475F, -0.18480538F,
    0.053517316F, -0.034753695F, -0.18793432F, -0.11748349F, -0.11514865F,
    -0.08822548F, 0.28981602F, 0.23633306F, 0.029169964F, 0.27879858F,
    0.24306232F, 0.07461948F, -0.061447397F, 0.12447153F, -0.08921927F,
    -0.26839763F, -0.022006879F, -0.10610999F, -0.118112884F, -0.28572327F,
    -0.17670728F, -0.022790547F, -0.03123665F, -0.1322675F, -0.16901743F,
    0.12490602F, 0.22429603F, 0.0031615708F, -0.007994456F, 0.064847544F,
    -0.1942999F, -0.096368F, 0.38031283F, 0.26386362F, 0.05994416F, -0.13286507F,
    -0.0100524975F, 0.0154719455F, -0.22980274F, -0.0049995156F, -0.10262948F,
    0.068461776F, -0.06289981F, -0.10998034F, 0.3349225F, -0.00087632047F,
    0.039037134F, 0.40695935F, 0.24277973F, -0.05529422F, 0.049662746F,
    -0.1349095F, 0.03453947F, 0.045995735F, 0.05732664F, 0.059164774F,
    0.2491947F, 0.24417706F, 0.022772476F, 0.028048722F, -0.32964352F,
    -0.28626648F, -0.09080413F, -0.030937059F, 0.263463F, -0.14115953F,
    -0.1554541F, -0.27687222F, -0.2966043F, 0.049292084F, 0.19716224F,
    -0.044245392F, -0.04697352F, 0.005650873F, -0.17507127F, -0.063002154F,
    -0.019146191F, 0.17491819F, -0.10968965F, 0.022340775F, -0.045577597F,
    -0.03121406F, 0.029301813F, 0.039315153F, 0.16578814F, 0.05557315F,
    0.020658735F, 0.09274589F, 0.12614232F, 0.7839324F, 0.6845265F,
    -0.081622556F, 0.3102865F, 0.27843398F, 0.014705529F, -0.07665562F,
    -0.15333632F, 0.043831352F, -0.026575414F, 0.0961252F, 0.39158514F,
    0.23025331F, -0.0070822565F, 0.023382965F, 0.36765474F, 0.3668508F,
    0.5456977F, -0.3656522F, -0.028832618F, -0.08301327F, -0.22770655F,
    -0.31284156F, 0.013184246F, -0.124953784F, 0.031376604F, -0.3488988F,
    0.20138936F, -0.11451242F, -0.015723906F, 0.10577278F, -0.009592982F,
    0.04368943F, 0.2778736F, 0.0017264133F, -0.17902951F, 0.04234852F,
    0.062137764F, 0.011318297F, -0.31044048F, -0.07358853F, 0.15349254F,
    -0.32490677F, -0.037796874F, 0.03362412F, -0.015696889F, -0.054597113F,
    -0.14970537F, -0.27018088F, -0.042941384F, -0.07270518F, 0.18803458F,
    -0.011660939F, -0.0702641F, -0.057377353F, -0.1851047F, -0.007833809F,
    -0.40859023F, -0.26590353F, -0.03886649F, -0.045184318F, 0.14438333F,
    -0.07771795F, 0.19866905F, -0.17471796F, -0.0118489F, 0.0023517834F,
    -0.13918437F, 0.18604246F, 0.123112276F, -0.22315119F, -0.16831362F,
    -0.056914717F, 0.1339013F, 0.2941451F, -0.120629735F, -0.20089811F,
    -0.11829833F, 0.08989178F, 0.22888786F, 0.3846356F, -0.16083781F,
    -0.11634102F, 0.042563353F, 0.04422772F, -0.11363447F, -0.34749937F,
    -0.21101305F, -0.39067844F, 0.0013417692F, -0.05319678F, -0.14168803F,
    0.05545587F, -0.10997274F, -0.07704806F, 0.054242376F, -0.071473606F,
    -0.17715949F, -0.23805912F, -0.19705272F, 0.03708343F, 0.36452982F,
    0.29170197F, 0.28822184F, 0.11267806F, -0.15076737F, 0.0950185F,
    -0.14448899F, 0.13947164F, -0.18019739F, -0.18321526F, -0.1920505F,
    0.10051795F, 0.1831649F, 0.24295F, 0.109441556F, -0.31344274F, 0.066210054F,
    0.16774751F, -0.18477148F, -0.20120478F, -0.10800049F, 0.028590849F,
    -0.020739231F, -0.18674418F, -0.16394012F, -0.03521484F, 0.049139988F,
    0.19890669F, -0.0809529F, 0.15925165F, 0.19551334F, -0.018130848F,
    -0.18680488F, -0.28397688F, -0.1903219F, -0.27348554F, -0.22945292F,
    -0.0007535425F, 0.13359432F, 0.30888045F, 0.139983F, -0.09382685F,
    0.06313586F, 0.22618754F, 0.29921043F, -0.019973855F, 0.2559688F,
    -0.07161412F, -0.16308063F, -0.39926848F, -0.22695751F, -0.18985231F,
    -0.14927492F, 0.15079175F, 0.2580902F, -0.27108774F, 0.23480996F,
    0.009656811F, 0.10717602F, -0.1397242F, 0.06920281F, -0.19115569F,
    -0.3194289F, -0.255859F, 0.15679446F, -0.16838463F, -0.057221655F,
    0.21981516F, 0.3544887F, 0.44357097F, -0.14185688F, -0.11192423F,
    -0.013581778F, -0.049543027F, 0.43313485F, 0.15719502F, -0.124558255F,
    -0.46191826F, -0.19253455F, 0.19359286F, -0.09307333F, -0.13255858F,
    0.0874188F, -0.11210002F, -0.17386304F, 0.07083292F, 0.077077605F,
    -0.016060092F, -0.24050424F, -0.12479803F, -0.16829063F, -0.02054228F,
    0.20412289F, 0.19717886F, 0.050575998F, -0.045195762F, 0.10441171F,
    0.06263066F, 0.06968963F, -0.13445435F, -0.064114965F, 0.095168486F,
    0.022079816F, -0.10503035F, -0.06668142F, -0.28971565F, -0.15378492F,
    0.21496692F, 0.26006114F, 0.09816434F, 0.109802224F, 0.13723963F, 0.224843F,
    0.27438274F, -0.20818122F, -0.08134637F, -0.009972936F, -0.03524825F,
    0.117925934F, 0.041061122F, -0.10544253F, 0.045474075F, 0.058433633F,
    0.065463066F, 0.013164551F, -0.014093699F, -0.021587064F, -0.038167324F,
    -0.11043596F, -0.21447207F, 0.08548712F, -0.032617163F, 0.090978175F,
    -0.069375135F, -0.17101158F, -0.17612891F, -0.022370806F, 0.057604037F,
    0.08511728F, -0.070634864F, 0.27423492F, 0.05876526F, -0.094006136F,
    0.024204798F, 0.22667126F, -0.11381607F, -0.15436035F, 0.057529286F,
    0.100620285F, 0.1733937F, -0.0011004012F, -0.17877032F, 0.005996574F,
    -0.27406013F, -0.06889241F, 0.096756F, -0.06617799F, -0.014006046F,
    -0.1920119F, -0.33221442F, 0.073633276F, -0.226971F, -0.0665149F,
    0.19209959F, 0.13212961F, 0.23163731F, -0.056953102F, -0.14145724F,
    -0.13517654F, -0.053460218F, -0.042667944F, -0.030063283F, 0.045288358F,
    -0.3050432F, -0.18816447F, -0.10887971F, -0.102842025F, 0.0776704F,
    0.0379522F, 0.12035688F, -0.1464522F, 0.19740602F, 0.22604541F, -0.16248949F,
    0.29157662F, -0.19140427F, -0.14531451F, -0.14922957F, 0.030948626F,
    0.19510382F, 0.14023617F, 0.17784245F, 0.03398275F, 0.37284112F, 0.20113428F,
    0.010372345F, -0.15331589F, -0.023690823F, -0.11003459F, -0.24545534F,
    -0.16809426F, 0.1429876F, -0.031584777F, -0.19397074F, -0.17670667F,
    -0.025537204F, 0.35728753F, 0.62649363F, 0.14836243F, -0.19253743F,
    0.18192598F, -0.33629915F, -0.30877584F, 0.18978626F, -0.27684978F,
    -0.008459832F, -0.21417081F, 0.066685304F, 0.24235754F, 0.01995414F,
    0.16703403F, -0.06742156F, -0.13057908F, -0.04929876F, -0.11325663F,
    -0.30432504F, -0.04858975F, 0.056909513F, 0.0153057985F, -0.13455038F,
    -0.18338399F, -0.20110348F, 0.054841693F, 0.036720645F, -0.036714744F,
    -0.04340593F, 0.037791815F, -0.35898128F, -0.020361397F, -0.221237F,
    -0.27868167F, -0.11535817F, -0.078669414F, -0.033567443F, -0.15241615F,
    -0.13307717F, -0.043458793F, 0.16436435F, 0.28187346F, -0.12343F,
    -0.055525918F, -0.06430723F, -0.1654643F, -0.01123776F, 0.13295592F,
    -0.23705484F, 0.05697759F, 0.044144258F, 0.2628488F, 0.07662277F,
    0.09657273F, 0.052091755F, -0.028905442F, 0.08430138F, -0.019593807F,
    0.17463915F, -0.23641987F, -0.38891438F, 0.015803445F, -0.13045968F,
    0.13863781F, 0.08836631F, 0.18649706F, 0.117025554F, 0.030750697F,
    0.044087324F, 0.7262373F, 0.17715156F, 0.4092085F, 0.47464913F, -0.1455868F,
    0.2550871F, 0.30161187F, 0.050824683F, 0.21080238F, 0.010283327F,
    -0.031990733F, -0.34866354F, -0.20949085F, 0.053213652F, -0.2613338F,
    -0.121119104F, -0.077826336F, 0.1734016F, 0.0065075755F, -0.077653304F,
    0.047931176F, 0.07797008F, -0.15651914F, -0.24928844F, -0.15927376F,
    -0.31715566F, 0.022177864F, -0.050441932F, -0.12608297F, 0.042133167F,
    0.1191605F, 0.2510787F, 0.32776275F, 0.13346784F, 0.050695214F, 0.05870343F,
    -0.036136884F, 0.11755612F, 0.2315269F, -0.019863732F, -0.120508626F,
    -0.115466125F, -0.054531306F, 0.0059978776F, -0.23942162F, -0.21320048F,
    -0.067783475F, 0.16298968F, 0.04896055F, -0.06374837F, -0.24510299F,
    -0.12946527F, 0.050505977F, -0.31254002F, -0.20550907F, 0.15295663F,
    0.10559584F, -0.10863885F, 0.28222084F, 0.06928262F, 0.20011F, 0.40114653F,
    0.10289667F, -0.09295075F, -0.13152206F, 0.114004426F, 0.016617432F,
    0.06458957F, 0.014832218F, -0.082577206F, 0.14263703F, 0.11709059F,
    -0.06915831F, -0.011039204F, -0.0092066685F, 0.06571642F, 0.03092607F,
    -0.17391603F, -0.008113772F, -0.027284494F, -0.30682626F, -0.24885628F,
    -0.21813236F, 0.019337788F, 0.144637F, 0.18953092F, 0.30015126F, 0.08340275F,
    0.23407666F, -0.08872973F, -0.09364336F, 0.25862345F, 0.22087035F,
    0.31806454F, 0.17132424F, 0.41003484F, 0.4425186F, 0.27111524F, 0.2757548F,
    -0.035552427F, -0.06716676F, -0.2655202F, -0.09288911F, -0.3139815F,
    -0.2797401F, -0.10836715F, -0.39224806F, -0.12983038F, -0.08539957F,
    -0.045438305F, -0.24168338F, -0.09387618F, 0.31674883F, 0.02453249F,
    0.06441037F, 0.25753075F, 0.14258656F, -0.07047653F, 0.11868954F,
    0.05970397F, -0.0632534F, 0.37293166F, 0.3280806F, 0.16621742F, -0.12789266F,
    0.24154778F, -0.03151052F, 0.29545146F, -0.10450362F, -0.066438414F,
    -0.18694894F, -0.13281195F, 0.19598058F, -0.049767263F, 0.040746614F,
    -0.2683073F, 0.4338053F, 0.0155872125F, -0.12680854F, 0.31028315F,
    -0.0033881F, -0.042740908F, 0.023058126F, -0.29197904F, -0.21834047F,
    0.081593774F, -0.32895643F, -0.13083652F, -0.27039522F, -0.11389027F,
    -0.13912877F, 0.5415756F, 0.23246893F, 0.08386469F, 0.041367456F,
    0.31045902F, 0.12054174F, -0.25138712F, -0.032769565F, 0.38030398F,
    -0.16231161F, 0.09311284F, 0.0105818985F, -0.15266018F, -0.1427249F,
    0.029335713F, -0.1570965F, -0.11085039F, -0.058290794F, -0.37840223F,
    0.05022721F, -0.21695462F, -0.09052564F, 0.046620857F, 0.030672F,
    0.11887101F, 0.027767722F, 0.07569782F, -0.21325019F, 0.038621973F,
    0.18432611F, 0.44816852F, 0.21007478F, 0.06916376F, -0.18234463F,
    -0.25027993F, 0.10753188F, 0.2380044F, 0.07310617F, -0.07180831F,
    -0.5078282F, -0.17005147F, 0.19789211F, -0.26648518F, -0.026042175F,
    0.18834484F, 0.12732872F, 0.17584233F, -0.2594232F, -0.21764518F,
    -0.1740799F, -0.09205242F, 0.028430145F, -0.12357986F, 0.006896094F,
    -0.034612987F, 0.13304886F, -0.101031676F, 0.19860454F, -0.1422819F,
    -0.04491955F, 0.051151253F, 0.01250237F, 0.10134663F, -0.1910392F,
    -0.2548171F, 0.020570267F };

  static const real32_T c[13] = { -0.28643572F, -0.4446742F, -0.3260439F,
    -0.8755456F, -0.45949855F, 0.09697428F, -0.38351575F, -0.22367316F,
    -0.3962223F, -0.49432805F, -0.14280868F, -0.44314066F, -0.32282376F };

  AudioSmartSpeakerOnJetsonNano_convolution_dujn(&X[0], &Z[0], &b[0], &c[0]);
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf4(const
  real32_T X_Data[1183], real32_T Z_Data[91])
{
  int32_T filterHeightIdx;
  int32_T outChannelIdx;
  int32_T outWidthIdx;
  real32_T opValue;
  real32_T u1;
  for (outChannelIdx = 0; outChannelIdx < 13; outChannelIdx++) {
    for (outWidthIdx = 0; outWidthIdx < 7; outWidthIdx++) {
      opValue = -3.402823466E+38F;
      for (filterHeightIdx = 0; filterHeightIdx < 13; filterHeightIdx++) {
        u1 = X_Data[(13 * outWidthIdx + filterHeightIdx) + 91 * outChannelIdx];
        if (!(opValue >= u1) && !rtIsNaNF(u1)) {
          opValue = u1;
        }
      }

      Z_Data[outWidthIdx + 7 * outChannelIdx] = opValue;
    }
  }
}

void microKernel9307911276855274595(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C)
{
  int32_T idxA;
  int32_T idxB;
  int32_T k;
  real32_T c;
  idxA = 0;
  idxB = 0;
  c = C[0];
  for (k = 0; k < K; k++) {
    c += A[idxA] * B[idxB];
    idxA += LDA;
    idxB++;
  }

  C[0] = c;
}

void microKernel2865182207653473102(int32_T K, const real32_T *A, int32_T LDA,
  const real32_T *B, real32_T *C)
{
  int32_T idxA;
  int32_T idxB;
  int32_T k;
  real32_T bTemp;
  real32_T c;
  real32_T c_0;
  real32_T c_1;
  real32_T c_2;
  real32_T c_3;
  real32_T c_4;
  real32_T c_5;
  idxA = 1;
  idxB = 0;
  c = C[0];
  c_0 = C[1];
  c_1 = C[2];
  c_2 = C[3];
  c_3 = C[4];
  c_4 = C[5];
  c_5 = C[6];
  for (k = 0; k < K; k++) {
    bTemp = B[idxB];
    c += A[idxA - 1] * bTemp;
    c_0 += A[idxA] * bTemp;
    c_1 += A[idxA + 1] * bTemp;
    c_2 += A[idxA + 2] * bTemp;
    c_3 += A[idxA + 3] * bTemp;
    c_4 += A[idxA + 4] * bTemp;
    c_5 += A[idxA + 5] * bTemp;
    idxA += LDA;
    idxB++;
  }

  C[0] = c;
  C[1] = c_0;
  C[2] = c_1;
  C[3] = c_2;
  C[4] = c_3;
  C[5] = c_4;
  C[6] = c_5;
}

void macroKernel10151223486748942243(int32_T M, int32_T K, int32_T N, const
  real32_T *A, int32_T LDA, const real32_T *B, int32_T LDB, real32_T *C, int32_T
  LDC)
{
  int32_T i;
  int32_T idxA;
  int32_T idxB;
  int32_T idxC;
  int32_T j;
  j = 0;
  idxB = 0;
  while (j < N) {
    idxC = LDC * j;
    i = 0;
    idxA = 0;
    while (i <= M - 7) {
      microKernel2865182207653473102(K, &A[idxA], LDA, &B[idxB], &C[idxC]);
      idxA += 7;
      idxC += 7;
      i += 7;
    }

    while (i <= M - 1) {
      microKernel9307911276855274595(K, &A[idxA], LDA, &B[idxB], &C[idxC]);
      idxA++;
      idxC++;
      i++;
    }

    idxB += LDB;
    j++;
  }
}

void matrixMultiply10151223486748942243(int32_T M, int32_T K, int32_T N, int32_T
  blockSizeM, int32_T blockSizeK, int32_T blockSizeN, const real32_T *A, const
  real32_T *B, real32_T *C)
{
  int32_T K2;
  int32_T N2;
  int32_T i;
  int32_T i0;
  int32_T i0_ub;
  int32_T j1;
  int32_T k;
  int32_T k0;
  int32_T k0_ub;
  int32_T tmp;
  memset(C, 0, (uint32_T)(M * N * (int32_T)sizeof(real32_T)));
  if (blockSizeM >= M) {
    blockSizeM = M;
  } else {
    blockSizeM = div_nde_s32_floor(blockSizeM, 7) * 7;
    if (blockSizeM <= 0) {
      blockSizeM = 1;
    }
  }

  if (blockSizeN >= N) {
    blockSizeN = N;
  } else if (blockSizeN <= 0) {
    blockSizeN = 1;
  }

  i0_ub = div_s32_floor(M - 1, blockSizeM);
  k0_ub = div_s32_floor(K - 1, blockSizeK);
  for (j1 = 0; j1 < N; j1 += blockSizeN) {
    if (j1 > N - blockSizeN) {
      N2 = N - j1;
    } else {
      N2 = blockSizeN;
    }

    for (k0 = 1; k0 <= k0_ub + 1; k0++) {
      k = (k0 - 1) * blockSizeK;
      if (k > K - blockSizeK) {
        K2 = K - k;
      } else {
        K2 = blockSizeK;
      }

      for (i0 = 1; i0 <= i0_ub + 1; i0++) {
        i = (i0 - 1) * blockSizeM;
        if (i > M - blockSizeM) {
          tmp = M - i;
        } else {
          tmp = blockSizeM;
        }

        macroKernel10151223486748942243(tmp, K2, N2, &A[i + M * k], M, &B[k + K *
          j1], K, &C[i + M * j1], M);
      }
    }
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_SoftmaxLayer_predict(const real32_T
  X1_Data[12], real32_T Z1_Data[12])
{
  int32_T idx;
  int32_T k;
  real32_T X1_Data_0;
  real32_T maxVal;
  boolean_T exitg1;
  if (!rtIsNaNF(X1_Data[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while (!exitg1 && (k < 13)) {
      if (!rtIsNaNF(X1_Data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    maxVal = X1_Data[0];
  } else {
    maxVal = X1_Data[idx - 1];
    for (k = idx + 1; k < 13; k++) {
      X1_Data_0 = X1_Data[k - 1];
      if (maxVal < X1_Data_0) {
        maxVal = X1_Data_0;
      }
    }
  }

  for (idx = 0; idx < 12; idx++) {
    X1_Data_0 = X1_Data[idx] - maxVal;
    mw_arm_vexp_f32(&X1_Data_0, &Z1_Data[idx], 1U);
  }

  maxVal = Z1_Data[0];
  for (idx = 0; idx < 11; idx++) {
    maxVal += Z1_Data[idx + 1];
  }

  for (idx = 0; idx < 12; idx++) {
    Z1_Data[idx] /= maxVal;
  }
}

/* Function for MATLAB Function: '<S12>/MLFB' */
static void AudioSmartSpeakerOnJetsonNano_predict(const real32_T inputsT_0_f1
  [4900], real32_T outputs_0_f1[12])
{
  real32_T X[1001];
  static const real32_T b[1092] = { -0.017899578F, 0.019315077F, 0.012550192F,
    -0.046708927F, 0.052670367F, 0.12184583F, 0.1296649F, 0.075072475F,
    0.06443403F, 0.039362535F, -0.02227219F, 0.01277696F, -0.17330728F,
    -0.054119095F, -0.09407708F, 0.10259544F, -0.027764374F, 0.048287157F,
    -0.035223197F, -0.18484136F, 0.030653324F, 0.1994048F, -0.07547016F,
    -0.0634205F, -0.2775319F, -0.033643186F, -0.12946764F, 0.10347797F,
    -0.07106737F, 0.051087733F, 0.033263456F, -0.1693223F, -0.11941335F,
    -0.1010744F, 0.010533479F, -0.027957471F, -0.2766496F, -0.12852404F,
    0.059853777F, 0.029124042F, -0.020304803F, -0.17417471F, 0.1277385F,
    0.24595504F, -0.22146297F, -0.18144417F, 0.08217634F, 0.12843189F,
    -0.041664463F, -0.05765513F, -0.10313681F, -0.16502282F, -0.06364409F,
    0.029227868F, 0.0064951316F, 0.016264852F, -0.0022013464F, -0.17410463F,
    0.24618638F, 0.10400248F, 0.009950256F, -0.031655893F, -0.132883F,
    0.04876553F, -0.20554844F, -0.095814906F, -0.079189524F, 0.05085749F,
    0.40896314F, -0.1883922F, 0.16875388F, 0.06266335F, 0.10523112F,
    -0.09545541F, -0.14019309F, -0.0140357865F, 0.054155167F, 0.05464867F,
    -0.12997988F, 0.09459555F, 0.05392803F, -0.14730434F, 0.02911373F,
    0.039894465F, -0.31196433F, 0.097350806F, 0.19208269F, 0.095285274F,
    -0.15393977F, -0.009852105F, -0.15048398F, -0.11705141F, 0.09881292F,
    -0.12959045F, 0.04191981F, 0.078946054F, -0.080761656F, -0.067788444F,
    -0.20433505F, 0.009402003F, -0.16462944F, 0.2654209F, 0.24280867F,
    -0.09359841F, 0.08366472F, 0.22188929F, -0.20674993F, 0.032725543F,
    -0.25635183F, -0.14330487F, 0.26862144F, 0.0059198593F, -0.15944928F,
    0.24119149F, 0.257237F, -0.043590102F, -0.015984276F, 0.14976387F,
    -0.19147542F, 0.031477686F, -0.155091F, 0.15322521F, 0.24251835F,
    -0.20804237F, 0.14890838F, -0.015789965F, -0.006324652F, -0.13980106F,
    -0.032636635F, -0.19891946F, 0.09601894F, 0.107021175F, -0.25410467F,
    0.14987843F, -0.06153872F, 0.0537468F, -0.08716745F, -0.00012928528F,
    0.07627949F, -0.17261341F, -0.031394426F, -0.08274717F, 0.15266736F,
    0.0749055F, -0.06039384F, 0.2275171F, 0.10862764F, -0.021649737F,
    -0.19023375F, 0.053342864F, 0.12479588F, 0.1577281F, 0.034213047F,
    0.031765718F, 0.02104455F, -0.009503647F, 0.17049026F, -0.089175895F,
    0.06366479F, 0.09292362F, -0.012779717F, 0.047466297F, -0.02932312F,
    -0.10776565F, -0.028122405F, 0.0077937036F, 0.040171087F, 0.048337355F,
    -0.18710105F, 0.052071363F, 0.10491583F, 0.040260572F, 0.1715327F,
    -0.08765107F, -0.10181627F, 0.2601223F, -0.19360527F, -0.12651424F,
    0.1599871F, 0.02903019F, -0.2579891F, 0.102264106F, 0.115841836F,
    0.08004231F, 0.14477733F, -0.20196941F, -0.31457853F, 0.04657215F,
    0.107379764F, -0.113156796F, 0.07593287F, 0.040597476F, -0.16680492F,
    0.23616679F, -0.18010263F, 0.063471824F, 0.05629846F, 0.08416589F,
    0.08536995F, -0.011940103F, -0.056314953F, -0.11916453F, 0.034805115F,
    0.17499761F, -0.01958868F, -0.23471859F, 0.19927333F, 0.14338623F,
    -0.22101681F, 0.2115817F, 0.09956429F, 0.10301935F, -0.25742084F,
    0.03130924F, -0.11482052F, -0.078768015F, 0.09762104F, -0.13515164F,
    0.10992403F, -0.100100935F, 0.086093426F, -0.03439779F, -0.012366861F,
    0.11527879F, 0.1067928F, -0.081603415F, -0.033942338F, -0.06470487F,
    -0.1608345F, -0.01863563F, -0.15849572F, 0.051527184F, 0.20204285F,
    0.08784968F, 0.05864253F, -0.1132483F, 0.13498966F, 0.06004228F,
    0.089533925F, -0.073961474F, 0.019534247F, 0.25778368F, 0.16317226F,
    0.033809897F, -0.08404367F, 0.012278731F, -0.025149409F, -0.10744405F,
    -0.090042025F, 0.15178259F, -0.09786736F, -0.08750179F, -0.021514906F,
    0.21255067F, -0.083136186F, -0.09127135F, -0.05008897F, 0.059640132F,
    0.26777878F, -0.19837576F, 0.034633152F, -0.041608933F, -0.034070764F,
    0.01947375F, 0.028307846F, -0.101738736F, 0.0058117867F, 0.054823104F,
    -0.04351152F, -6.384124E-5F, 0.08512452F, -0.050773576F, 0.011018116F,
    -0.00035587332F, -0.13083467F, 0.16002941F, -0.12598753F, -0.0055824616F,
    0.22662258F, -0.073714934F, 0.26072973F, -0.20774543F, -0.05379359F,
    0.06846447F, -0.20492354F, -0.02949092F, 0.015588894F, 0.099123426F,
    -0.17572746F, 0.033553448F, 0.20960288F, -0.15487668F, 0.17239714F,
    -0.07018755F, -0.089522384F, -0.25272086F, -0.085521154F, 0.028182512F,
    0.06592132F, 0.031051978F, -0.12368987F, 0.07227395F, 0.1263731F,
    -0.28084308F, 0.07970743F, 0.19938128F, 0.06518275F, -0.3691664F,
    0.26278463F, 0.19753902F, -0.22253576F, -0.12560719F, -0.18808708F,
    0.18597554F, 0.04909262F, 0.05754776F, -0.030381808F, -0.045784026F,
    0.07184792F, -0.12539844F, 0.055540968F, -0.046584543F, -0.06869774F,
    0.014062646F, -0.15082777F, 0.0030694655F, -0.0022179093F, 0.07871108F,
    -0.011327211F, 0.14505707F, 0.11846111F, -0.088600285F, -0.009497326F,
    -0.16266102F, 0.025862975F, -0.10306861F, -0.0737007F, 0.084107354F,
    0.0224073F, -0.096373074F, -0.03517965F, 0.06517848F, 0.062267296F,
    0.032766204F, 0.09453872F, 0.14933392F, -0.17237997F, 0.063480884F,
    -0.16783483F, -0.042475298F, 0.01582049F, -0.0844509F, -0.03611392F,
    -0.0084908735F, 0.096043766F, -0.08571417F, 0.03028685F, 0.26052755F,
    -0.035714258F, 0.2752923F, -0.21124862F, -0.029419515F, -0.049080614F,
    0.26600376F, 0.22386533F, -0.05878626F, -0.07857628F, -0.19035073F,
    -0.08977408F, -0.0757978F, 0.26063472F, -0.05493439F, -0.2536398F,
    -0.021318262F, -0.036677092F, 0.08044239F, 0.11325645F, -0.1040115F,
    -0.07104657F, -0.08616577F, 0.017231919F, -0.056341197F, 0.13185188F,
    0.032792058F, -0.12688072F, -0.22112659F, -0.27160475F, 0.23600094F,
    -0.14097476F, 5.3655967E-5F, 0.23917165F, 0.28317532F, 0.15833274F,
    -0.101162255F, -0.025255492F, 0.21060975F, 0.022048648F, -0.035073955F,
    0.11985164F, -0.13752513F, -0.108716086F, 0.0053923493F, -0.04662502F,
    0.19466662F, 0.082094036F, 0.033649735F, -0.14625394F, 0.037843864F,
    -0.17042655F, 0.06757855F, -0.069372F, 0.058351878F, 0.029480394F,
    -0.11376474F, -0.074264556F, 0.20747021F, -0.052249733F, -0.11851103F,
    0.058893144F, 0.047623407F, 0.29405653F, -0.0783205F, -0.06408538F,
    -0.08132724F, 0.0027985284F, -0.0756436F, -0.036481597F, -0.058441784F,
    -0.14321773F, -0.117380515F, 0.008860612F, 0.06625137F, 0.13250588F,
    -0.080907695F, -0.21008886F, -0.1088686F, -0.06575603F, 0.2055571F,
    0.19276665F, -0.084018625F, 0.03394091F, 0.118017726F, -0.12692359F,
    -0.017964775F, -0.0738773F, -0.039745368F, 0.010332794F, 0.19650413F,
    -0.13754882F, -0.12051107F, -0.09331007F, -0.11669962F, 0.086943805F,
    0.18452777F, 0.056101624F, -0.07642304F, -0.09250291F, 0.018413486F,
    -0.104678765F, 0.24714994F, -0.10834387F, -0.13935867F, -0.057458255F,
    -0.07521594F, -0.19150735F, 0.030180102F, 0.037464958F, 0.061774697F,
    -0.10317843F, 0.0076518883F, -0.060207658F, 0.22638664F, 0.07126068F,
    0.11662142F, 0.018288808F, -0.047406845F, 0.07969001F, 0.2777536F,
    -0.23407868F, -0.06894434F, -0.029910475F, -0.019891221F, 0.008340022F,
    0.1347516F, 0.13323769F, -0.11275732F, -0.020445134F, 0.061173026F,
    -0.12590104F, 0.13314316F, -0.090162046F, -0.06586495F, 0.0011785703F,
    -0.08469247F, -0.08423464F, -0.07627102F, 0.04337321F, -0.1618551F,
    -0.13220859F, 0.07693633F, -0.06014373F, 0.12599088F, -0.19147007F,
    -0.053611543F, -0.037315227F, 0.0841232F, -0.084861934F, -0.1488075F,
    0.14171833F, 0.16885205F, 0.21300554F, 0.12777758F, -0.014980494F,
    0.10250653F, -0.07696865F, 0.16548915F, -0.09796849F, -0.16047786F,
    0.0806997F, 0.14309137F, 0.23905632F, -0.16273162F, -0.18788278F,
    0.23826498F, -0.15065134F, -0.11730008F, 0.0822445F, 0.0125345485F,
    -0.22478038F, 0.13896741F, -0.09495985F, 0.1316979F, 0.13702196F,
    -0.008758124F, -0.15574269F, -0.11189576F, 0.015924325F, -0.15328111F,
    0.11366293F, -0.09155424F, -0.21090706F, -0.2492849F, -0.27073985F,
    0.2832485F, -0.14395583F, 0.15007085F, 0.09415488F, 0.17254294F, -0.0581166F,
    0.003151023F, 0.077662125F, 0.12325932F, -0.058789484F, -0.1679884F,
    -0.15825468F, 0.08399768F, -0.23814219F, 0.0033006265F, -0.009622251F,
    0.1748534F, -0.01233062F, 0.011727865F, -0.07829173F, 0.02457687F,
    -0.14872026F, -0.14555985F, -0.1239643F, 0.13296276F, 0.09383348F,
    -0.05986398F, -0.0018139498F, 0.2526513F, -0.009351122F, 0.10610142F,
    0.0976829F, 0.069574766F, -0.09706745F, -0.14809388F, -0.066230364F,
    -0.09530249F, 0.04325033F, -0.08955504F, 0.08353175F, 0.12884751F,
    0.11654026F, 0.18886499F, -0.13211751F, -0.05003149F, 0.14088835F,
    0.18832624F, -0.04294186F, -0.043672264F, -0.073844746F, 0.061297033F,
    0.329855F, -0.09675707F, -0.010121279F, -0.09010794F, 0.033427406F,
    -0.03910343F, 0.23153639F, -0.07010068F, 0.08308541F, 0.15797734F,
    -0.0508888F, -0.029859083F, -0.0638039F, 0.26575834F, 0.018648518F,
    -0.1074025F, 0.007268407F, 0.09509259F, 0.19490412F, 0.12241719F,
    -0.0057900166F, -0.07222406F, -0.073041186F, -0.019150326F, -0.036063146F,
    0.01680096F, 0.15818793F, -0.019766033F, 0.0619922F, -0.058186308F,
    0.17964743F, -0.19174352F, 0.17857155F, -0.1286002F, 0.14215437F, 0.3085831F,
    -0.08765969F, -0.18145792F, -0.07994672F, 0.0006937074F, 0.11681476F,
    -0.028768582F, 0.22817713F, -0.13436271F, -0.056978244F, 0.040766843F,
    -0.087428935F, 0.3503192F, -0.09595937F, -0.06867909F, 0.03919987F,
    -0.109203376F, 0.100229815F, 0.1574465F, 0.039629098F, -0.041289013F,
    -0.1516901F, 0.008841259F, -0.19296117F, 0.08804203F, -0.215681F,
    0.028557396F, 0.03717157F, -0.25763273F, 0.101336464F, -0.0243281F,
    0.044069152F, -0.12770417F, -0.18737236F, 0.07478847F, -0.11320415F,
    0.18276528F, -0.15260234F, 0.22294073F, -0.017526448F, -0.18541993F,
    0.27697834F, 0.013518052F, -0.21338798F, 0.047960125F, 0.1171512F,
    0.097996525F, -0.06236901F, -0.121343516F, -0.14698409F, 0.13289262F,
    0.031653814F, -0.23494336F, 0.14857031F, -0.060084548F, -0.18850549F,
    0.20546049F, -0.0432423F, -0.09123213F, 0.18939744F, -0.009100126F,
    0.0024494946F, -0.07705793F, 0.18979615F, 0.042841196F, 0.0549661F,
    0.07882513F, -0.3122527F, -0.11339116F, -0.11203975F, 0.23848537F,
    0.2379541F, -0.0929829F, 0.04284199F, 0.03148715F, -0.17339684F,
    -0.02106941F, -0.010093846F, 0.082433455F, -0.20154531F, 0.06792919F,
    0.20419914F, -0.018510856F, -0.22568451F, 0.16879225F, 0.058707334F,
    0.06705632F, -0.089349434F, -0.021299658F, -0.12097993F, 0.11788479F,
    -0.035245467F, -0.01719459F, -0.11887805F, -0.059203487F, 0.027731076F,
    0.24601206F, 0.15799935F, 0.081378415F, -0.039392076F, 0.18371117F,
    -0.0966737F, -0.10876206F, 0.10766394F, 0.18018815F, 0.08358453F,
    -0.11101911F, 0.013521521F, -0.14622127F, -0.17377333F, -0.13898121F,
    -0.0843485F, -0.14088894F, 0.21011244F, -0.0060559954F, 0.08515102F,
    -0.0033347812F, -0.0074183415F, 0.18413803F, 0.01338105F, 0.04402331F,
    -0.0042528757F, -0.034950968F, -0.11723115F, -0.018889498F, 0.25533712F,
    -0.17267008F, -0.25192502F, 0.109472066F, 0.090964444F, -0.112076856F,
    0.07181475F, 0.052666847F, 0.08964193F, 0.18620265F, -0.017906722F,
    0.13975903F, -0.15811498F, 0.10599444F, -0.23101236F, 0.039915133F,
    0.14952983F, -0.09603838F, 0.16076452F, -0.19389224F, -0.19344537F,
    0.025585052F, 0.015436138F, -0.06743938F, -0.044312425F, 0.065602906F,
    -0.29409468F, 0.18349147F, 0.105628826F, -0.0927745F, 0.15060434F,
    -0.1708971F, -0.17153932F, -0.31538734F, 0.108734846F, -0.06990072F,
    0.113968596F, 0.102622904F, -0.06468512F, 0.035913996F, -0.16082212F,
    0.09802928F, -0.15321788F, -0.087709084F, 0.07923361F, -0.108765535F,
    0.18758728F, -0.020438276F, -0.14824574F, 0.13980004F, -0.024155656F,
    0.117690675F, 0.12664618F, -0.19203016F, -0.24565181F, 0.009388605F,
    -0.023144934F, 0.002651825F, 0.27875704F, -0.078789175F, -0.058031972F,
    0.06294627F, -0.08554871F, -0.041736867F, 0.021173803F, 0.010028647F,
    0.0052919355F, -0.12807956F, -0.060581915F, -0.12486859F, 0.3658239F,
    0.020315392F, 0.15617159F, 0.24899629F, -0.030297922F, -0.1134868F,
    -0.0846999F, -0.08806233F, 0.04066263F, 0.015336872F, 0.059098773F,
    -0.12149324F, -0.037888385F, 0.08262996F, -0.035738837F, -0.07592667F,
    0.22491966F, -0.10207417F, 0.045781434F, -0.014644959F, -0.038860492F,
    0.16312243F, 0.17071708F, 0.018839126F, -0.07150155F, 0.08998486F,
    -0.06715635F, -0.1635262F, 0.24716495F, 0.024066934F, 0.21149467F,
    -0.0014953343F, -0.1693239F, 0.077765115F, -0.031591285F, -0.058757827F,
    -0.0040554125F, 0.06369506F, 0.022285543F, -0.13315476F, 0.2954095F,
    0.05307708F, 0.08343778F, -0.103975944F, -0.16998558F, 0.042037304F,
    0.081675135F, -0.007997742F, 0.0907544F, -0.018214053F, -0.11002845F,
    0.06853679F, 0.28611115F, -0.012001596F, -0.027477363F, 0.006639852F,
    -0.11516691F, -0.15523772F, 0.0013360174F, 0.122629315F, -0.029766F,
    0.08972279F, -0.16196154F, 0.21268193F, 0.27610713F, 0.034784876F,
    -0.022524603F, -0.0886218F, 0.08121504F, -0.005697774F, 0.04810563F,
    -0.06543673F, 0.0026964277F, 0.094551355F, -0.22817363F, 0.15866269F,
    0.26091385F, -0.000658837F, -0.06495877F, -0.1320079F, 0.05584901F,
    0.018053338F, 0.0020310788F, -0.17208712F, 0.18572436F, 0.10191646F,
    -0.04584811F, 0.09752582F, 0.063631F, 0.01165677F, -0.028672485F,
    -0.16165233F, -0.06577386F, -0.013264141F, -0.09658453F, -0.026722103F,
    0.2602551F, 0.034228954F, 0.0064608115F, 0.11633211F, 0.15374404F,
    0.20515817F, 0.10889182F, -0.20806493F, 0.117230676F, -0.170586F,
    0.25329843F, 0.0714014F, -0.21942061F, -0.15356426F, -0.15476373F,
    0.14881916F, 0.06448374F, 0.22045141F, 0.07591521F, -0.24456085F,
    0.08245723F, -0.0014462373F, 0.21258879F, -0.1103276F, -0.047675513F,
    -0.14757371F, -0.23301984F, 0.063536204F, 0.39291242F, 0.22166279F,
    0.01272399F, -0.057148386F, 0.024803445F, -0.11265634F, -0.034582842F,
    -0.051992845F, -0.15632883F, -0.051515456F, -0.1669884F, 0.06912956F,
    0.37150866F, 0.06140873F, -0.06836532F, -0.038681034F, -0.17176022F,
    -0.05995276F, 0.10582306F, -0.12035383F, -0.0952925F, -0.10098949F,
    -0.016060553F, 0.07799629F, 0.32384074F, -0.109224975F, 0.029659389F,
    -0.1650538F, -0.00684838F, 0.03921703F, 0.13369364F, -0.037694704F,
    -0.099454105F, 0.02399215F, -0.022465155F, -0.009089718F, 0.3330189F,
    0.005140578F, -0.100526795F, -0.010766606F, -0.011792273F, -0.0897828F,
    -0.03205932F, 0.013199034F, -0.16913323F, -0.043584786F, 0.032322872F,
    -0.033002786F, 0.18290171F, -0.10384968F, -0.061255187F, -0.07294465F,
    -0.036425866F, -0.086335525F, 0.071645305F, -0.011224395F, -0.00091497484F,
    -0.08821964F, -0.08277107F, -0.067866534F, 0.13917251F, -0.019179374F,
    0.013912544F, 0.06287728F, -0.035629146F, -0.13589309F, -0.1977666F,
    0.100873925F, -0.045509644F, -0.12904185F, 0.16314097F, -0.14071256F,
    -0.0804935F, -0.14394152F, 0.1366774F, -0.050053254F, 0.077251084F,
    -0.082760155F, -0.07340178F, 0.12813641F, 0.08155154F, 0.14055647F,
    -0.028834121F, 0.056148365F, -0.13048701F, -0.29235137F, -0.019789828F,
    -0.10819906F, -0.039890397F, 0.09430538F, -0.35245684F, -0.12311232F,
    0.12580147F, 0.22182514F, -0.043618176F, -0.00028923404F, 0.00400384F,
    -0.029069588F, -0.095095985F, -0.037890937F, -0.11489256F, 0.16824256F,
    -0.07607322F, -0.004442557F, 0.2968777F, 0.30779067F, 0.0045674173F,
    0.05533018F, 0.06260089F, -0.081044056F, -0.20262484F, 0.06982034F,
    -0.20212017F, -0.21110281F, 0.08420855F, 0.19265395F, -0.10196296F,
    -0.030469833F, 0.067975044F, 0.27845582F, -0.06774222F, -0.03782174F,
    -0.064838424F, -0.005172573F, -0.056869797F, 0.018380169F, -0.09276989F,
    0.11558897F, -0.14028598F, -0.0069166347F, 0.12634149F, -0.0037355889F,
    -0.006251223F, -0.14399667F, 0.04739014F, -0.0457751F, -0.063203044F,
    -0.05538868F, -0.10779475F, 0.02064813F, 0.092397965F, 0.0077609615F,
    0.040819548F, -0.20894F };

  int32_T i;
  real32_T tmp_0[91];
  real32_T tmp[12];
  real32_T tmp_1[12];
  static const real32_T c[12] = { 0.37842864F, -0.09189245F, -0.029579159F,
    0.029765874F, -0.030765088F, -0.010814358F, -0.04495241F, -0.07802893F,
    -0.03958615F, 0.03292105F, -0.051812228F, -0.037514653F };

  real32_T tmp_2[1001];
  for (i = 0; i < 4900; i++) {
    AudioSmartSpeakerOnJetsonNano_B.inputsT_0_f1[i] = inputsT_0_f1[i] -
      -4.46151F;
  }

  AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor
    (AudioSmartSpeakerOnJetsonNano_B.inputsT_0_f1,
     AudioSmartSpeakerOnJetsonNano_B.obj_Data);
  AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict
    (AudioSmartSpeakerOnJetsonNano_B.obj_Data,
     AudioSmartSpeakerOnJetsonNano_B.fv2);
  AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d
    (AudioSmartSpeakerOnJetsonNano_B.fv2,
     AudioSmartSpeakerOnJetsonNano_B.b_obj_Data);
  AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_h
    (AudioSmartSpeakerOnJetsonNano_B.b_obj_Data,
     AudioSmartSpeakerOnJetsonNano_B.fv4);
  AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3
    (AudioSmartSpeakerOnJetsonNano_B.fv4,
     AudioSmartSpeakerOnJetsonNano_B.c_obj_Data);
  AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf
    (AudioSmartSpeakerOnJetsonNano_B.c_obj_Data, tmp_2);
  AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3f(tmp_2, X);
  AudioSmartSpeakerOnJetsonNano_conv2dDirectOptimizedColMajor_d3fr(X,
    AudioSmartSpeakerOnJetsonNano_B.d_obj_Data);
  AudioSmartSpeakerOnJetsonNano_Pooling2DLayer_predict_hf4
    (AudioSmartSpeakerOnJetsonNano_B.d_obj_Data, tmp_0);
  matrixMultiply10151223486748942243(12, 91, 1, 64, 64, 64, &b[0], &tmp_0[0],
    &tmp[0]);
  for (i = 0; i < 12; i++) {
    tmp_1[i] = tmp[i] + c[i];
  }

  AudioSmartSpeakerOnJetsonNano_SoftmaxLayer_predict(tmp_1, outputs_0_f1);
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void AudioSmartSpeakerOnJetsonNano_merge(int32_T idx[10], real_T x[10],
  int32_T offset, int32_T np, int32_T nq, int32_T iwork[10], real_T xwork[10])
{
  int32_T exitg1;
  int32_T iout;
  int32_T n;
  int32_T p;
  int32_T q;
  if ((np != 0) && (nq != 0)) {
    n = np + nq;
    for (q = 0; q < n; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n) {
          q++;
        } else {
          n = iout - p;
          for (q = p + 1; q <= np; q++) {
            iout = n + q;
            idx[iout] = iwork[q - 1];
            x[iout] = xwork[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for MATLAB Function: '<S5>/MATLAB Function' */
static void AudioSmartSpeakerOnJetsonNano_sort(real_T x[10])
{
  real_T xwork[10];
  real_T x4[4];
  real_T tmp;
  real_T tmp_0;
  int32_T idx[10];
  int32_T iwork[10];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ib;
  int32_T m;
  int32_T nNaNs;
  int32_T perm_0;
  int8_T idx4[4];
  int8_T perm[4];
  for (i = 0; i < 10; i++) {
    idx[i] = 0;
  }

  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  nNaNs = 0;
  ib = -1;
  for (m = 0; m < 10; m++) {
    if (rtIsNaN(x[m])) {
      idx[9 - nNaNs] = m + 1;
      xwork[9 - nNaNs] = x[m];
      nNaNs++;
    } else {
      ib++;
      idx4[ib] = (int8_T)(m + 1);
      x4[ib] = x[m];
      if (ib + 1 == 4) {
        ib = m - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[i3 - 1];
        if (tmp <= tmp_0) {
          if (x4[i2 - 1] <= tmp_0) {
            i = i1;
            perm_0 = i2;
            i1 = i3;
            i2 = i4;
          } else if (x4[i2 - 1] <= x4[i4 - 1]) {
            i = i1;
            perm_0 = i3;
            i1 = i2;
            i2 = i4;
          } else {
            i = i1;
            perm_0 = i3;
            i1 = i4;
          }
        } else if (tmp <= x4[i4 - 1]) {
          if (x4[i2 - 1] <= x4[i4 - 1]) {
            i = i3;
            perm_0 = i1;
            i1 = i2;
            i2 = i4;
          } else {
            i = i3;
            perm_0 = i1;
            i1 = i4;
          }
        } else {
          i = i3;
          perm_0 = i4;
        }

        idx[ib - 3] = idx4[i - 1];
        idx[ib - 2] = idx4[perm_0 - 1];
        idx[ib - 1] = idx4[i1 - 1];
        idx[ib] = idx4[i2 - 1];
        x[ib - 3] = x4[i - 1];
        x[ib - 2] = x4[perm_0 - 1];
        x[ib - 1] = x4[i1 - 1];
        x[ib] = x4[i2 - 1];
        ib = -1;
      }
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (m = 0; m <= ib; m++) {
      i = perm[m];
      i1 = ((m - nNaNs) - ib) + 9;
      idx[i1] = idx4[i - 1];
      x[i1] = x4[i - 1];
    }
  }

  m = (nNaNs >> 1) + 10;
  for (i = 0; i <= m - 11; i++) {
    ib = (i - nNaNs) + 10;
    i1 = idx[ib];
    idx[ib] = idx[9 - i];
    idx[9 - i] = i1;
    x[ib] = xwork[9 - i];
    x[9 - i] = xwork[ib];
  }

  if (((uint32_T)nNaNs & 1U) != 0U) {
    i = m - nNaNs;
    x[i] = xwork[i];
  }

  if (10 - nNaNs > 1) {
    for (i = 0; i < 10; i++) {
      iwork[i] = 0;
    }

    i = (10 - nNaNs) >> 2;
    m = 4;
    while (i > 1) {
      AudioSmartSpeakerOnJetsonNano_merge(idx, x, 0, m, m, iwork, xwork);
      m <<= 1;
      i = 1;
    }

    if (10 - nNaNs > m) {
      AudioSmartSpeakerOnJetsonNano_merge(idx, x, 0, m, 10 - (nNaNs + m), iwork,
        xwork);
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_graphicEQ_setGainsToEQ
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj)
{
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *obj_0;
  real_T gains_data[10];
  real_T gainvec[10];
  real_T b_value;
  int32_T i;
  int32_T trueCount;
  boolean_T flag;
  static const real_T cf[10] = { 31.6227766016838, 63.09573444801933,
    125.89254117941672, 251.188643150958, 501.18723362727235, 1000.0,
    1995.2623149688795, 3981.0717055349724, 7943.282347242814,
    15848.931924611134 };

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  b_value = obj->pSampleRateDialog;
  trueCount = 0;
  for (i = 0; i < 10; i++) {
    if (b_value / 2.0 >= cf[i]) {
      trueCount++;
    }
  }

  for (i = 0; i < trueCount; i++) {
    gains_data[i] = obj->pGains[i];
  }

  memset(&gainvec[0], 0, 10U * sizeof(real_T));
  if (trueCount - 1 >= 0) {
    memcpy(&gainvec[0], &gains_data[0], (uint32_T)trueCount * sizeof(real_T));
  }

  obj_0 = obj->pEQ;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  flag = (obj_0->isInitialized == 1);
  if (flag) {
    obj_0->TunablePropsChanged = true;
  }

  obj_0 = obj->pEQ;
  for (i = 0; i < 10; i++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_0->Gains[i] = gainvec[i];
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj_0->pIsGainInSync = false;
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

static void AudioSmartSpeakerOnJetsonNano_findHelper(const boolean_T x_data[],
  int32_T i_data[], int32_T *i_size)
{
  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  if (x_data[0]) {
    i_data[0] = 1;
    *i_size = 1;
  } else {
    *i_size = 0;
  }

  /* End of Start for MATLABSystem: '<S4>/Graphic EQ' */
}

static void AudioSmartSpeakerOnJetsonNano_designBandPassOctaveFilter(real32_T w0,
  real32_T BW, real32_T G, real32_T GB, real32_T B_data[], int32_T B_size[2],
  real32_T A_data[], int32_T A_size[2])
{
  int32_T B_data_tmp;
  int32_T tmp_data;
  int32_T tmp_size;
  real32_T Aa_data[3];
  real32_T Ahat_data[3];
  real32_T Ba_data[3];
  real32_T Bhat_data[3];
  real32_T Ba_data_tmp;
  real32_T Ba_data_tmp_0;
  real32_T Ba_data_tmp_1;
  real32_T Ba_data_tmp_2;
  real32_T Bhat_data_tmp;
  real32_T WB;
  real32_T a;
  real32_T a_tmp;
  boolean_T Ba_data_0;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  WB = (real32_T)tan(3.1415927F * BW / 2.0F);
  a = rt_powf_snf((real32_T)sqrt((G - GB) / (GB - 1.0F)), 1.0F);
  Ba_data[0] = rt_powf_snf(G, 0.5F) * WB;
  Ba_data[1] = a;
  Ba_data[2] = 0.0F;
  Aa_data[0] = WB;
  Aa_data[1] = a;
  Aa_data[2] = 0.0F;
  B_size[0] = 1;
  B_size[1] = 5;
  A_size[0] = 1;
  A_size[1] = 5;
  for (B_data_tmp = 0; B_data_tmp < 5; B_data_tmp++) {
    B_data[B_data_tmp] = 0.0F;
    A_data[B_data_tmp] = 0.0F;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  Bhat_data[0] = 0.0F;
  Ahat_data[0] = 0.0F;
  Bhat_data[1] = 0.0F;
  Ahat_data[1] = 0.0F;
  Bhat_data[2] = 0.0F;
  Ahat_data[2] = 0.0F;
  if (w0 == 0.0F) {
    WB = 1.0F;
  } else if (w0 == 1.0F) {
    WB = -1.0F;
  } else if (w0 == 0.5F) {
    WB = 0.0F;
  } else {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    WB = w0;
    if (w0 < 0.0F) {
      WB = -w0;
    }

    if (WB < 0.25F) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
       *  MATLABSystem: '<S4>/Multiband Parametric EQ'
       */
      WB = (real32_T)cos(WB * 3.1415927F);
    } else {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
       *  MATLABSystem: '<S4>/Multiband Parametric EQ'
       */
      WB -= (real32_T)floor(WB / 2.0F) * 2.0F;
      if (WB < 0.25F) {
        /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
         *  MATLABSystem: '<S4>/Multiband Parametric EQ'
         */
        WB = (real32_T)cos(WB * 3.1415927F);
      } else if (WB < 0.75F) {
        /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
         *  MATLABSystem: '<S4>/Multiband Parametric EQ'
         */
        WB = (real32_T)sin((0.5F - WB) * 3.1415927F);
      } else if (WB < 1.25F) {
        /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
         *  MATLABSystem: '<S4>/Multiband Parametric EQ'
         */
        WB = -(real32_T)cos((1.0F - WB) * 3.1415927F);
      } else if (WB < 1.75F) {
        /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
         *  MATLABSystem: '<S4>/Multiband Parametric EQ'
         */
        WB = (real32_T)sin((WB - 1.5F) * 3.1415927F);
      } else {
        /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
         *  MATLABSystem: '<S4>/Multiband Parametric EQ'
         */
        WB = (real32_T)cos((WB - 2.0F) * 3.1415927F);
      }
    }
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  Ba_data_tmp = Aa_data[1];
  Ba_data_tmp_0 = Ba_data[1];
  Ba_data_tmp_1 = Ba_data[2];
  Ba_data_tmp_2 = Aa_data[2];
  Ba_data_0 = (((Ba_data_tmp_0 != 0.0F) || (Ba_data_tmp != 0.0F)) &&
               ((Ba_data_tmp_1 == 0.0F) && (Ba_data_tmp_2 == 0.0F)));
  AudioSmartSpeakerOnJetsonNano_findHelper(&Ba_data_0, &tmp_data, &B_data_tmp);
  if (B_data_tmp != 0) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    a_tmp = Aa_data[0];
    a = a_tmp + Ba_data_tmp;

    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    Bhat_data_tmp = Ba_data[0];
    Bhat_data[0] = (Bhat_data_tmp + Ba_data_tmp_0) / a;
    Bhat_data[1] = (Bhat_data_tmp - Ba_data_tmp_0) / a;
    Ahat_data[0] = 1.0F;

    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    Ahat_data[1] = (a_tmp - Ba_data_tmp) / a;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  Ba_data_0 = ((Ba_data_tmp_1 != 0.0F) || (Ba_data_tmp_2 != 0.0F));
  AudioSmartSpeakerOnJetsonNano_findHelper(&Ba_data_0, &tmp_data, &tmp_size);
  if (tmp_size - 1 >= 0) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    a_tmp = Aa_data[0];
    a = (a_tmp + Ba_data_tmp) + Ba_data_tmp_2;

    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    Bhat_data_tmp = Ba_data[0];
    Bhat_data[0] = ((Bhat_data_tmp + Ba_data_tmp_0) + Ba_data_tmp_1) / a;
    Bhat_data[1] = (Bhat_data_tmp - Ba_data_tmp_1) * 2.0F / a;
    Bhat_data[2] = ((Bhat_data_tmp - Ba_data_tmp_0) + Ba_data_tmp_1) / a;
    Ahat_data[0] = 1.0F;

    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    Ahat_data[1] = (a_tmp - Ba_data_tmp_2) * 2.0F / a;
    Ahat_data[2] = ((a_tmp - Ba_data_tmp) + Ba_data_tmp_2) / a;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
   *  MATLABSystem: '<S4>/Multiband Parametric EQ'
   */
  if ((WB == 1.0F) || (WB == -1.0F)) {
    B_data[0] = Bhat_data[0];
    A_data[0] = Ahat_data[0];
    B_data[1] = Bhat_data[1];
    A_data[1] = Ahat_data[1];
    B_data[2] = Bhat_data[2];
    A_data[2] = Ahat_data[2];
    B_data[1] *= WB;
    A_data[1] *= WB;
  } else {
    if (B_data_tmp != 0) {
      Ba_data_tmp = Bhat_data[0];
      B_data[0] = Ba_data_tmp;
      Ba_data_tmp_0 = Bhat_data[1];
      B_data[1] = (Ba_data_tmp_0 - Ba_data_tmp) * WB;
      B_data[2] = -Ba_data_tmp_0;
      A_data[0] = 1.0F;
      Ba_data_tmp = Ahat_data[1];
      A_data[1] = (Ba_data_tmp - 1.0F) * WB;
      A_data[2] = -Ba_data_tmp;
    }

    if (tmp_size - 1 >= 0) {
      B_size[0] = 1;
      B_size[1] = 5;
      Ba_data_tmp = Bhat_data[0];
      B_data[0] = Ba_data_tmp;
      Ba_data_tmp_0 = Bhat_data[1];
      B_data[1] = (Ba_data_tmp_0 - 2.0F * Ba_data_tmp) * WB;
      a = WB * WB;
      Ba_data_tmp_1 = Bhat_data[2];
      B_data[2] = ((Ba_data_tmp - Ba_data_tmp_0) + Ba_data_tmp_1) * a -
        Ba_data_tmp_0;
      B_data[3] = (Ba_data_tmp_0 - 2.0F * Ba_data_tmp_1) * WB;
      B_data[4] = Ba_data_tmp_1;
      A_size[0] = 1;
      A_size[1] = 5;
      A_data[0] = 1.0F;
      Ba_data_tmp = Ahat_data[1];
      A_data[1] = (Ba_data_tmp - 2.0F) * WB;
      Ba_data_tmp_0 = Ahat_data[2];
      A_data[2] = ((1.0F - Ba_data_tmp) + Ba_data_tmp_0) * a - Ba_data_tmp;
      A_data[3] = (Ba_data_tmp - 2.0F * Ba_data_tmp_0) * WB;
      A_data[4] = Ba_data_tmp_0;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_all(const boolean_T x_data[],
  boolean_T y[2])
{
  int32_T i;
  int32_T i2;
  int32_T ix;
  boolean_T exitg1;
  y[0] = true;
  y[1] = true;
  i2 = 1;
  for (i = 0; i < 2; i++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    ix = i2;
    i2++;
    exitg1 = false;
    while (!exitg1 && (ix <= i2 - 1)) {
      if (!x_data[ix - 1]) {
        y[i] = false;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_designEachParamEQ(real32_T G, real32_T
  w0, real32_T BW, real32_T B_data[], int32_T B_size[2], real32_T A_data[],
  int32_T A_size[2])
{
  int32_T Af_size[2];
  int32_T Bf_size[2];
  int32_T b_k;
  real32_T Af_data[5];
  real32_T Bf_data[5];
  real32_T GB;
  real32_T Gsq;
  boolean_T Bf_data_0[2];
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  GB = G / 2.0F;
  if (rtIsInfF(G) && (G < 0.0F)) {
    GB = -3.0103002F;
  }

  B_size[0] = 3;
  B_size[1] = 1;
  B_data[1] = 0.0F;
  B_data[2] = 0.0F;
  B_data[0] = 1.0F;
  A_size[0] = 2;
  A_size[1] = 1;
  A_data[0] = 0.0F;
  A_data[1] = 0.0F;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if (!((real32_T)fabs(G) <= 1.1920929E-7F)) {
    Gsq = rt_powf_snf(10.0F, G / 10.0F);
    GB = rt_powf_snf(10.0F, GB / 10.0F);
    if (!((real32_T)fabs(Gsq - GB) <= 1.1920929E-7F) && !((real32_T)fabs(GB -
          1.0F) <= 1.1920929E-7F)) {
      AudioSmartSpeakerOnJetsonNano_designBandPassOctaveFilter(w0, BW, Gsq, GB,
        Bf_data, Bf_size, Af_data, Af_size);
      Bf_data_0[0] = (Bf_data[3] == 0.0F);
      Bf_data_0[1] = (Bf_data[4] == 0.0F);
      AudioSmartSpeakerOnJetsonNano_all(Bf_data_0, x);
      y = true;
      b_k = 0;
      exitg1 = false;
      while (!exitg1 && (b_k < 2)) {
        if (!x[b_k]) {
          y = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      guard1 = false;
      if (y) {
        Bf_data_0[0] = (Af_data[3] == 0.0F);
        Bf_data_0[1] = (Af_data[4] == 0.0F);
        AudioSmartSpeakerOnJetsonNano_all(Bf_data_0, x);
        y = true;
        b_k = 0;
        exitg1 = false;
        while (!exitg1 && (b_k < 2)) {
          if (!x[b_k]) {
            y = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }

        if (y) {
          B_data[0] = Bf_data[0];
          B_data[1] = Bf_data[1];
          B_data[2] = Bf_data[2];
          A_data[0] = Af_data[1];
          A_data[1] = Af_data[2];
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        B_data[0] = Bf_data[0];
        B_data[1] = Bf_data[1];
        B_data[2] = Bf_data[2];
        A_data[0] = Af_data[1];
        A_data[1] = Af_data[2];
      }
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ(const
  real_T Wo[10], const real_T Q[10], real_T Fs, real32_T B[30], real32_T A[30])
{
  int32_T b_size[2];
  int32_T c_size[2];
  int32_T B0_tmp;
  int32_T b_k;
  int32_T h;
  int32_T i;
  int32_T loop_ub;
  real32_T B0[30];
  real32_T A0[20];
  real32_T tmp[20];
  real32_T BW[10];
  real32_T b_Wo[10];
  real32_T b_data[3];
  real32_T c_data[2];
  real32_T BW_0;
  real32_T FN;
  real32_T b_Wo_0;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  FN = (real32_T)Fs / 2.0F;
  for (i = 0; i < 10; i++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    b_Wo_0 = (real32_T)Wo[i] / FN;
    b_Wo[i] = b_Wo_0;
    BW_0 = b_Wo_0 / (real32_T)Q[i];
    BW[i] = BW_0;
    if (b_Wo_0 > 1.0F) {
      b_Wo[i] = 1.0F;
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    if (BW_0 > 1.0F) {
      BW_0 = 1.0F;
      BW[i] = 1.0F;
    }

    if (BW_0 < 0.0F) {
      BW[i] = 0.0F;
    }
  }

  memset(&B0[0], 0, 30U * sizeof(real32_T));
  memset(&A0[0], 0, 20U * sizeof(real32_T));
  FN = 1.0F;
  for (b_k = 0; b_k < 10; b_k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    AudioSmartSpeakerOnJetsonNano_designEachParamEQ(10.0F, b_Wo[b_k], BW[b_k],
      b_data, b_size, c_data, c_size);
    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      h = 0;
    } else {
      i = (int32_T)FN - 1;
      h = (int32_T)((FN + 1.0F) - 1.0F);
    }

    loop_ub = h - i;
    for (h = 0; h < loop_ub; h++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      B0_tmp = (i + h) * 3;
      B0[B0_tmp] = b_data[3 * h];
      B0[B0_tmp + 1] = b_data[3 * h + 1];
      B0[B0_tmp + 2] = b_data[3 * h + 2];
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      h = 0;
    } else {
      i = (int32_T)FN - 1;
      h = (int32_T)((FN + 1.0F) - 1.0F);
    }

    loop_ub = h - i;
    for (h = 0; h < loop_ub; h++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      B0_tmp = (i + h) << 1;
      A0[B0_tmp] = c_data[h << 1];
      A0[B0_tmp + 1] = c_data[(h << 1) + 1];
    }

    FN++;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  mw_arm_mat_trans_f32(&B0[0], &B[0], 10U, 3U);
  mw_arm_mat_trans_f32(&A0[0], &tmp[0], 10U, 2U);
  for (h = 0; h < 10; h++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    A[h] = 1.0F;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  memcpy(&A[10], &tmp[0], 20U * sizeof(real32_T));
}

static void AudioSmartSpeakerOnJetsonNano_exp(const creal_T x_data[], const
  int32_T x_size[2], creal_T b_x_data[], int32_T b_x_size[2])
{
  real_T b_x_im;
  real_T r;
  int32_T b_k;
  int32_T loop_ub;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  b_x_size[0] = 1;
  loop_ub = x_size[1];
  b_x_size[1] = x_size[1];
  for (b_k = 0; b_k < loop_ub; b_k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    b_x_data[b_k] = x_data[b_k];
    r = b_x_data[b_k].re;
    b_x_im = b_x_data[b_k].im;
    if (r == 0.0) {
      b_x_data[b_k].re = cos(b_x_im);
      b_x_data[b_k].im = sin(b_x_im);
    } else if (b_x_im == 0.0) {
      b_x_data[b_k].re = exp(r);
      b_x_data[b_k].im = 0.0;
    } else if (rtIsInf(b_x_im) && rtIsInf(r) && (r < 0.0)) {
      b_x_data[b_k].re = 0.0;
      b_x_data[b_k].im = 0.0;
    } else {
      r = exp(r / 2.0);
      b_x_data[b_k].re = r * cos(b_x_im) * r;
      b_x_data[b_k].im = r * sin(b_x_im) * r;
    }
  }
}

static void AudioSmartSpeakerOnJetsonNano_binary_expand_op(creal32_T in1_data[],
  int32_T in1_size[2], const creal_T in2_data[], const int32_T in2_size[2],
  const real32_T in3[30], int32_T in4, int32_T in5)
{
  creal32_T in2_data_0[10];
  int32_T i;
  int32_T in2_re_tmp;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  real32_T in2_im;
  real32_T in2_re;
  real32_T in3_re;
  real32_T tmp;
  real32_T tmp_0;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  in3_re = in3[(3 * in4 + in5) + 1];
  loop_ub = in1_size[1] == 1 ? in2_size[1] : in1_size[1];
  stride_0_1 = (in2_size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_re_tmp = i * stride_0_1;

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    in2_re = (real32_T)in2_data[in2_re_tmp].re;
    in2_im = (real32_T)in2_data[in2_re_tmp].im;
    in2_re_tmp = i * stride_1_1;
    tmp = in1_data[in2_re_tmp].im;
    tmp_0 = in1_data[in2_re_tmp].re;
    in2_data_0[i].re = (tmp_0 * in2_re - tmp * in2_im) + in3_re;
    in2_data_0[i].im = tmp * in2_re + tmp_0 * in2_im;
  }

  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &in2_data_0[0], (uint32_T)loop_ub * sizeof(creal32_T));
  }
}

static void AudioSmartSpeakerOnJetsonNano_binary_expand_op_2(creal32_T in1_data[],
  const int32_T in1_size[2], int32_T in2, int32_T in3, int32_T in4, const
  creal32_T in5_data[], const int32_T in5_size[2], const creal32_T in6_data[],
  const int32_T in6_size[2])
{
  creal32_T in1_data_0[10];
  int32_T i;
  int32_T in1_re_tmp_tmp;
  int32_T in1_re_tmp_tmp_0;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;
  real32_T bim;
  real32_T in1_re;
  real32_T in1_re_tmp;
  real32_T in1_re_tmp_0;
  real32_T in1_re_tmp_1;
  real32_T in1_re_tmp_2;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if ((real_T)in4 + 1.0 < 1.0) {
    i = 0;
  } else {
    i = in4 + 1;
  }

  stride_0_0 = (i != 1);

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  stride_1_0 = (in5_size[1] != 1);
  stride_2_0 = (in6_size[1] != 1);
  for (i = 0; i < in2; i++) {
    in1_re_tmp_tmp = i * stride_0_0 + in1_size[0] * in3;
    in1_re_tmp = in1_data[in1_re_tmp_tmp].re;
    in1_re_tmp_tmp_0 = i * stride_1_0;
    in1_re_tmp_0 = in5_data[in1_re_tmp_tmp_0].im;
    in1_re_tmp_1 = in1_data[in1_re_tmp_tmp].im;
    in1_re_tmp_2 = in5_data[in1_re_tmp_tmp_0].re;
    in1_re = in1_re_tmp * in1_re_tmp_2 - in1_re_tmp_1 * in1_re_tmp_0;
    in1_re_tmp = in1_re_tmp * in1_re_tmp_0 + in1_re_tmp_1 * in1_re_tmp_2;
    in1_re_tmp_tmp = i * stride_2_0;
    in1_re_tmp_2 = in6_data[in1_re_tmp_tmp].re;
    in1_re_tmp_0 = in6_data[in1_re_tmp_tmp].im;
    if (in1_re_tmp_0 == 0.0F) {
      if (in1_re_tmp == 0.0F) {
        in1_data_0[i].re = in1_re / in1_re_tmp_2;
        in1_data_0[i].im = 0.0F;
      } else if (in1_re == 0.0F) {
        in1_data_0[i].re = 0.0F;
        in1_data_0[i].im = in1_re_tmp / in1_re_tmp_2;
      } else {
        in1_data_0[i].re = in1_re / in1_re_tmp_2;
        in1_data_0[i].im = in1_re_tmp / in1_re_tmp_2;
      }
    } else if (in1_re_tmp_2 == 0.0F) {
      if (in1_re == 0.0F) {
        in1_data_0[i].re = in1_re_tmp / in1_re_tmp_0;
        in1_data_0[i].im = 0.0F;
      } else if (in1_re_tmp == 0.0F) {
        in1_data_0[i].re = 0.0F;
        in1_data_0[i].im = -(in1_re / in1_re_tmp_0);
      } else {
        in1_data_0[i].re = in1_re_tmp / in1_re_tmp_0;
        in1_data_0[i].im = -(in1_re / in1_re_tmp_0);
      }
    } else {
      in1_re_tmp_1 = (real32_T)fabs(in1_re_tmp_2);
      bim = (real32_T)fabs(in1_re_tmp_0);
      if (in1_re_tmp_1 > bim) {
        in1_re_tmp_1 = in1_re_tmp_0 / in1_re_tmp_2;
        in1_re_tmp_0 = in1_re_tmp_1 * in1_re_tmp_0 + in1_re_tmp_2;
        in1_data_0[i].re = (in1_re_tmp_1 * in1_re_tmp + in1_re) / in1_re_tmp_0;
        in1_data_0[i].im = (in1_re_tmp - in1_re_tmp_1 * in1_re) / in1_re_tmp_0;
      } else if (bim == in1_re_tmp_1) {
        in1_re_tmp_2 = in1_re_tmp_2 > 0.0F ? 0.5F : -0.5F;
        in1_re_tmp_0 = in1_re_tmp_0 > 0.0F ? 0.5F : -0.5F;
        in1_data_0[i].re = (in1_re * in1_re_tmp_2 + in1_re_tmp * in1_re_tmp_0) /
          in1_re_tmp_1;
        in1_data_0[i].im = (in1_re_tmp * in1_re_tmp_2 - in1_re * in1_re_tmp_0) /
          in1_re_tmp_1;
      } else {
        in1_re_tmp_1 = in1_re_tmp_2 / in1_re_tmp_0;
        in1_re_tmp_0 += in1_re_tmp_1 * in1_re_tmp_2;
        in1_data_0[i].re = (in1_re_tmp_1 * in1_re + in1_re_tmp) / in1_re_tmp_0;
        in1_data_0[i].im = (in1_re_tmp_1 * in1_re_tmp - in1_re) / in1_re_tmp_0;
      }
    }
  }

  for (i = 0; i < in2; i++) {
    in1_data[i + in1_size[0] * in3] = in1_data_0[i];
  }
}

static void AudioSmartSpeakerOnJetsonNano_inv(const real32_T x_data[], const
  int32_T x_size[2], real32_T y_data[], int32_T y_size[2])
{
  int32_T a;
  int32_T c;
  int32_T c_0;
  int32_T c_A_size_idx_0;
  int32_T c_tmp;
  int32_T ijA;
  int32_T jA;
  int32_T jBcol;
  int32_T k;
  int32_T mmj;
  int32_T n;
  int32_T temp_tmp;
  int32_T yk;
  real32_T c_A_data[100];
  real32_T s;
  real32_T smax;
  int8_T b_ipiv_data[10];
  int8_T p_data[10];

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if ((x_size[0] == 0) || (x_size[1] == 0)) {
    y_size[0] = x_size[0];
    y_size[1] = x_size[1];
    yk = x_size[0] * x_size[1];
    if (yk - 1 >= 0) {
      memcpy(&y_data[0], &x_data[0], (uint32_T)yk * sizeof(real32_T));
    }
  } else {
    n = x_size[0];
    y_size[0] = x_size[0];
    y_size[1] = x_size[1];
    yk = x_size[0] * x_size[1];
    c_A_size_idx_0 = x_size[0];
    for (a = 0; a < yk; a++) {
      y_data[a] = 0.0F;
      c_A_data[a] = x_data[a];
    }

    b_ipiv_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      b_ipiv_data[k - 1] = (int8_T)yk;
    }

    if (x_size[0] - 1 <= x_size[0]) {
      jBcol = x_size[0] - 1;
    } else {
      jBcol = x_size[0];
    }

    for (yk = 0; yk < jBcol; yk++) {
      mmj = n - yk;
      c_tmp = (n + 1) * yk;
      c = c_tmp + 2;
      if (mmj < 1) {
        a = 0;
      } else {
        a = 1;
        if (mmj > 1) {
          smax = (real32_T)fabs(c_A_data[c_tmp]);
          for (k = 2; k <= mmj; k++) {
            s = (real32_T)fabs(c_A_data[(c_tmp + k) - 1]);
            if (s > smax) {
              a = k;
              smax = s;
            }
          }
        }
      }

      if (c_A_data[(c_tmp + a) - 1] != 0.0F) {
        if (a - 1 != 0) {
          jA = yk + a;
          b_ipiv_data[yk] = (int8_T)jA;
          for (k = 0; k < n; k++) {
            a = k * n;
            temp_tmp = a + yk;
            smax = c_A_data[temp_tmp];
            a = (a + jA) - 1;
            c_A_data[temp_tmp] = c_A_data[a];
            c_A_data[a] = smax;
          }
        }

        jA = (c_tmp + mmj) + 2;
        for (a = c; a <= jA - 2; a++) {
          c_A_data[a - 1] /= c_A_data[c_tmp];
        }
      }

      c = mmj - 2;
      a = c_tmp + n;
      jA = a + 1;
      for (k = 0; k <= c; k++) {
        smax = c_A_data[k * n + a];
        if (smax != 0.0F) {
          temp_tmp = jA + 1;
          c_0 = mmj + jA;
          for (ijA = temp_tmp; ijA < c_0; ijA++) {
            c_A_data[ijA - 1] += c_A_data[(c_tmp + ijA) - jA] * -smax;
          }
        }

        jA += n;
      }
    }

    p_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      p_data[k - 1] = (int8_T)yk;
    }

    for (yk = 0; yk < n; yk++) {
      jBcol = b_ipiv_data[yk];
      if (jBcol > yk + 1) {
        mmj = p_data[jBcol - 1];
        p_data[jBcol - 1] = p_data[yk];
        p_data[yk] = (int8_T)mmj;
      }
    }

    for (yk = 0; yk < n; yk++) {
      mmj = (p_data[yk] - 1) * y_size[0];
      y_data[yk + mmj] = 1.0F;
      for (k = yk + 1; k <= n; k++) {
        c_tmp = (k + mmj) - 1;
        if (y_data[c_tmp] != 0.0F) {
          for (a = k + 1; a <= n; a++) {
            ijA = (a + mmj) - 1;
            y_data[ijA] -= c_A_data[((k - 1) * c_A_size_idx_0 + a) - 1] *
              y_data[c_tmp];
          }
        }
      }
    }

    for (yk = 0; yk < n; yk++) {
      jBcol = n * yk - 1;
      for (k = n; k >= 1; k--) {
        mmj = (k - 1) * n - 1;
        a = k + jBcol;
        smax = y_data[a];
        if (smax != 0.0F) {
          y_data[a] = smax / c_A_data[k + mmj];
          jA = k - 1;
          for (c_tmp = 0; c_tmp < jA; c_tmp++) {
            c = (c_tmp + jBcol) + 1;
            y_data[c] -= c_A_data[(c_tmp + mmj) + 1] * y_data[a];
          }
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S4>/Graphic EQ' */
}

static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_d
  (real32_T Wo[10], const real_T G[10], const real_T Q[10], real32_T Fs,
   real32_T B[30], real32_T A[30])
{
  int32_T b_size[2];
  int32_T c_size[2];
  int32_T B0_tmp;
  int32_T b_k;
  int32_T h;
  int32_T i;
  int32_T loop_ub;
  real32_T B0[30];
  real32_T A0[20];
  real32_T tmp[20];
  real32_T BW[10];
  real32_T b_G[10];
  real32_T b_data[3];
  real32_T c_data[2];
  real32_T BW_0;
  real32_T FN;
  real32_T Wo_0;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  FN = Fs / 2.0F;
  for (i = 0; i < 10; i++) {
    b_G[i] = (real32_T)G[i];

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    Wo_0 = Wo[i] / FN;
    Wo[i] = Wo_0;
    BW_0 = Wo_0 / (real32_T)Q[i];
    BW[i] = BW_0;
    if (Wo_0 > 1.0F) {
      Wo[i] = 1.0F;
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    if (BW_0 > 1.0F) {
      BW_0 = 1.0F;
      BW[i] = 1.0F;
    }

    if (BW_0 < 0.0F) {
      BW[i] = 0.0F;
    }
  }

  memset(&B0[0], 0, 30U * sizeof(real32_T));
  memset(&A0[0], 0, 20U * sizeof(real32_T));
  FN = 1.0F;
  for (b_k = 0; b_k < 10; b_k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    AudioSmartSpeakerOnJetsonNano_designEachParamEQ(b_G[b_k], Wo[b_k], BW[b_k],
      b_data, b_size, c_data, c_size);
    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      h = 0;
    } else {
      i = (int32_T)FN - 1;
      h = (int32_T)((FN + 1.0F) - 1.0F);
    }

    loop_ub = h - i;
    for (h = 0; h < loop_ub; h++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      B0_tmp = (i + h) * 3;
      B0[B0_tmp] = b_data[3 * h];
      B0[B0_tmp + 1] = b_data[3 * h + 1];
      B0[B0_tmp + 2] = b_data[3 * h + 2];
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      h = 0;
    } else {
      i = (int32_T)FN - 1;
      h = (int32_T)((FN + 1.0F) - 1.0F);
    }

    loop_ub = h - i;
    for (h = 0; h < loop_ub; h++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      B0_tmp = (i + h) << 1;
      A0[B0_tmp] = c_data[h << 1];
      A0[B0_tmp + 1] = c_data[(h << 1) + 1];
    }

    FN++;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  mw_arm_mat_trans_f32(&B0[0], &B[0], 10U, 3U);
  mw_arm_mat_trans_f32(&A0[0], &tmp[0], 10U, 2U);
  for (h = 0; h < 10; h++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    A[h] = 1.0F;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  memcpy(&A[10], &tmp[0], 20U * sizeof(real32_T));
}

static void AudioSmartSpeakerOnJetsonNano_SystemCore_setup
  (b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *obj)
{
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj_0;
  creal_T s_data[10];
  creal_T tmp_data[10];
  creal32_T h_data[100];
  creal32_T g_data[10];
  creal32_T h_data_0[10];
  creal32_T y_data_0[10];
  real_T tmp_data_1[100];
  real_T b[10];
  real_T b_0[10];
  real_T digw_data[10];
  real_T varargin_12;
  int32_T b_idx;
  int32_T b_k;
  int32_T k;
  int32_T loop_ub;
  int32_T nz;
  int32_T tmp;
  real32_T tmp_data_0[100];
  real32_T y_data[100];
  real32_T A[30];
  real32_T A1[30];
  real32_T B[30];
  real32_T B1[30];
  real32_T minval[10];
  real32_T B_re;
  real32_T Fs;
  real32_T Nyquist;
  real32_T bim;
  real32_T g;
  real32_T g_0;
  int8_T m[2];
  boolean_T x[9];
  boolean_T flag;
  static const int16_T tmp_0[10] = { 100, 181, 325, 585, 1053, 1896, 3415, 6151,
    11078, 19953 };

  static const real32_T tmp_1[10] = { 31.622782F, 63.09574F, 125.89255F,
    251.18866F, 501.18726F, 1000.0F, 1995.2622F, 3981.0715F, 7943.2817F,
    15848.931F };

  static const real_T tmp_2[10] = { 31.62278175354004, 63.095741271972656,
    125.89254760742188, 251.18865966796875, 501.187255859375, 1000.0,
    1995.26220703125, 3981.071533203125, 7943.28173828125, 15848.9306640625 };

  static const real_T tmp_3[9] = { 44.66835921509632, 89.12509381337456,
    177.82794100389228, 354.8133892335755, 707.9457843841379, 1412.5375446227542,
    2818.382931264454, 5623.41325190349, 11220.184543019634 };

  static const real_T tmp_4[10] = { 31.6227766016838, 63.09573444801933,
    125.89254117941672, 251.188643150958, 501.18723362727235, 1000.0,
    1995.2623149688795, 3981.0717055349724, 7943.282347242814,
    15848.931924611134 };

  int32_T g_size[2];
  int32_T h_size[2];
  int32_T s_size[2];
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T y_size[2];
  boolean_T exitg1;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  varargin_12 = obj->SampleRate;
  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.privFrequencies[k] = tmp_0[k];
  }

  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.privQualityFactors[k] = 1.6;
  }

  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.privPeakGains[k] = 0.0;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj->coder_buffer_pobj0.isInitialized = 0;
  obj->coder_buffer_pobj0.isInitialized = 0;
  obj->coder_buffer_pobj0.SOSFilterObj.isInitialized = 0;
  obj->coder_buffer_pobj0.SOSFilterObj.isInitialized = 0;

  /* System object Constructor function: dsp.SOSFilter */
  obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  flag = (obj->coder_buffer_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.TunablePropsChanged = true;
  }

  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    digw_data[k] = obj->coder_buffer_pobj0.privFrequencies[k];
  }

  flag = true;
  b_k = 0;
  exitg1 = false;
  while (!exitg1 && (b_k < 10)) {
    if (!(digw_data[b_k] == tmp_1[b_k])) {
      flag = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (!flag) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    memcpy(&b_0[0], &tmp_2[0], 10U * sizeof(real_T));
    for (k = 0; k < 10; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      obj->coder_buffer_pobj0.privFrequencies[k] = b_0[k];
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  flag = (obj->coder_buffer_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.TunablePropsChanged = true;
  }

  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    digw_data[k] = obj->coder_buffer_pobj0.privQualityFactors[k];
  }

  flag = true;
  b_k = 0;
  exitg1 = false;
  while (!exitg1 && (b_k < 10)) {
    if (!(digw_data[b_k] == 1.4192615747451782)) {
      flag = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (!flag) {
    for (k = 0; k < 10; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      obj->coder_buffer_pobj0.privQualityFactors[k] = 1.4192615747451782;
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  flag = (obj->coder_buffer_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.TunablePropsChanged = true;
  }

  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    digw_data[k] = obj->coder_buffer_pobj0.privPeakGains[k];
  }

  flag = true;
  b_k = 0;
  exitg1 = false;
  while (!exitg1 && (b_k < 10)) {
    if (!(digw_data[b_k] == 0.0)) {
      flag = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (!flag) {
    for (k = 0; k < 10; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      obj->coder_buffer_pobj0.privPeakGains[k] = 0.0;
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  flag = (obj->coder_buffer_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj->coder_buffer_pobj0.TunablePropsChanged = true;
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj->coder_buffer_pobj0.SampleRate = varargin_12;
  obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  obj->coder_buffer_pobj0.NumChannels = -1.0;
  obj->coder_buffer_pobj0.AreFiltersDesigned = false;
  obj->coder_buffer_pobj0.matlabCodegenIsDeleted = false;
  obj->pMPEQ1 = &obj->coder_buffer_pobj0;
  obj->pIsGainInSync = false;
  if (!obj->pIsGainInSync) {
    obj_0 = obj->pMPEQ1;
    for (k = 0; k < 10; k++) {
      digw_data[k] = obj_0->privFrequencies[k];
    }

    obj_0 = obj->pMPEQ1;
    for (k = 0; k < 10; k++) {
      b_0[k] = obj_0->privQualityFactors[k];
    }

    AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ(digw_data, b_0,
      obj->SampleRate, B1, A1);
    mw_arm_mat_trans_f32(&B1[0], &B[0], 3U, 10U);
    mw_arm_mat_trans_f32(&A1[0], &A[0], 3U, 10U);
    varargin_12 = obj->SampleRate / 2.0;
    for (k = 0; k < 9; k++) {
      x[k] = (varargin_12 > tmp_3[k]);
    }

    nz = x[0] + 1;
    for (k = 0; k < 8; k++) {
      nz += x[k + 1];
    }

    h_size[0] = nz;
    h_size[1] = nz;
    loop_ub = nz * nz;
    for (k = 0; k < loop_ub; k++) {
      h_data[k].re = 1.0F;
      h_data[k].im = 0.0F;
    }

    for (b_idx = 0; b_idx < nz; b_idx++) {
      for (k = 0; k < nz; k++) {
        digw_data[k] = 6.283185307179586 * tmp_4[k] / obj->SampleRate;
      }

      tmp_size[0] = 1;
      tmp_size[1] = nz;
      for (k = 0; k < nz; k++) {
        varargin_12 = digw_data[k];
        tmp_data[k].re = varargin_12 * 0.0;
        tmp_data[k].im = varargin_12;
      }

      AudioSmartSpeakerOnJetsonNano_exp(tmp_data, tmp_size, s_data, s_size);
      tmp = s_size[1];
      g_size[0] = 1;
      g_size[1] = s_size[1];
      if (s_size[1] != 0) {
        g_size[0] = 1;
        g_size[1] = s_size[1];
        for (k = 0; k < tmp; k++) {
          g_data[k].re = B[3 * b_idx];
          g_data[k].im = 0.0F;
        }

        for (b_k = 0; b_k < 2; b_k++) {
          if (s_size[1] == g_size[1]) {
            B_re = B[(3 * b_idx + b_k) + 1];
            loop_ub = s_size[1] - 1;
            g_size[0] = 1;
            g_size[1] = s_size[1];
            for (k = 0; k <= loop_ub; k++) {
              Fs = (real32_T)s_data[k].re;
              Nyquist = (real32_T)s_data[k].im;
              g = g_data[k].im;
              g_0 = g_data[k].re;
              g_data[k].re = (Fs * g_0 - Nyquist * g) + B_re;
              g_data[k].im = Fs * g + Nyquist * g_0;
            }
          } else {
            AudioSmartSpeakerOnJetsonNano_binary_expand_op(g_data, g_size,
              s_data, s_size, B, b_idx, b_k);
          }
        }
      }

      y_size[0] = 1;
      y_size[1] = s_size[1];
      if (s_size[1] != 0) {
        y_size[0] = 1;
        y_size[1] = s_size[1];
        for (k = 0; k < tmp; k++) {
          y_data_0[k].re = A[3 * b_idx];
          y_data_0[k].im = 0.0F;
        }

        for (b_k = 0; b_k < 2; b_k++) {
          if (s_size[1] == y_size[1]) {
            g = A[(3 * b_idx + b_k) + 1];
            loop_ub = s_size[1] - 1;
            y_size[0] = 1;
            y_size[1] = s_size[1];
            for (k = 0; k <= loop_ub; k++) {
              Fs = (real32_T)s_data[k].re;
              Nyquist = (real32_T)s_data[k].im;
              g_0 = y_data_0[k].im;
              B_re = y_data_0[k].re;
              y_data_0[k].re = (Fs * B_re - Nyquist * g_0) + g;
              y_data_0[k].im = Fs * g_0 + Nyquist * B_re;
            }
          } else {
            AudioSmartSpeakerOnJetsonNano_binary_expand_op(y_data_0, y_size,
              s_data, s_size, A, b_idx, b_k);
          }
        }
      }

      if ((nz == g_size[1]) && ((nz == 1 ? g_size[1] : nz) == y_size[1])) {
        for (k = 0; k < nz; k++) {
          b_k = h_size[0] * b_idx + k;
          Nyquist = h_data[b_k].re;
          B_re = h_data[b_k].im;
          g = g_data[k].re;
          g_0 = g_data[k].im;
          Fs = Nyquist * g - B_re * g_0;
          Nyquist = Nyquist * g_0 + B_re * g;
          B_re = y_data_0[k].re;
          g = y_data_0[k].im;
          if (g == 0.0F) {
            if (Nyquist == 0.0F) {
              h_data_0[k].re = Fs / B_re;
              h_data_0[k].im = 0.0F;
            } else if (Fs == 0.0F) {
              h_data_0[k].re = 0.0F;
              h_data_0[k].im = Nyquist / B_re;
            } else {
              h_data_0[k].re = Fs / B_re;
              h_data_0[k].im = Nyquist / B_re;
            }
          } else if (B_re == 0.0F) {
            if (Fs == 0.0F) {
              h_data_0[k].re = Nyquist / g;
              h_data_0[k].im = 0.0F;
            } else if (Nyquist == 0.0F) {
              h_data_0[k].re = 0.0F;
              h_data_0[k].im = -(Fs / g);
            } else {
              h_data_0[k].re = Nyquist / g;
              h_data_0[k].im = -(Fs / g);
            }
          } else {
            g_0 = (real32_T)fabs(B_re);
            bim = (real32_T)fabs(g);
            if (g_0 > bim) {
              g_0 = g / B_re;
              g = g_0 * g + B_re;
              h_data_0[k].re = (g_0 * Nyquist + Fs) / g;
              h_data_0[k].im = (Nyquist - g_0 * Fs) / g;
            } else if (bim == g_0) {
              B_re = B_re > 0.0F ? 0.5F : -0.5F;
              g = g > 0.0F ? 0.5F : -0.5F;
              h_data_0[k].re = (Fs * B_re + Nyquist * g) / g_0;
              h_data_0[k].im = (Nyquist * B_re - Fs * g) / g_0;
            } else {
              g_0 = B_re / g;
              g += g_0 * B_re;
              h_data_0[k].re = (g_0 * Fs + Nyquist) / g;
              h_data_0[k].im = (g_0 * Nyquist - Fs) / g;
            }
          }

          h_data[b_k] = h_data_0[k];
        }
      } else {
        AudioSmartSpeakerOnJetsonNano_binary_expand_op_2(h_data, h_size, nz,
          b_idx, nz - 1, g_data, g_size, y_data_0, y_size);
      }
    }

    loop_ub = h_size[0] * h_size[1];
    for (b_k = 0; b_k < loop_ub; b_k++) {
      y_data[b_k] = rt_hypotf_snf(h_data[b_k].re, h_data[b_k].im);
      y_data[b_k] = (real32_T)log10(y_data[b_k]);
    }

    for (k = 0; k < 100; k++) {
      obj->pGainCorrectionMatrix[k] = 0.0;
    }

    tmp_size_0[0] = h_size[0];
    tmp_size_0[1] = h_size[1];
    for (k = 0; k < loop_ub; k++) {
      tmp_data_0[k] = y_data[k] * 20.0F;
    }

    AudioSmartSpeakerOnJetsonNano_inv(tmp_data_0, tmp_size_0, y_data, y_size);
    loop_ub = y_size[1];
    tmp = y_size[1];
    b_idx = y_size[0];
    for (k = 0; k < b_idx; k++) {
      for (b_k = 0; b_k < loop_ub; b_k++) {
        tmp_data_1[b_k + tmp * k] = y_data[y_size[0] * b_k + k];
      }
    }

    m[0] = (int8_T)nz;
    for (k = 0; k < nz; k++) {
      for (b_k = 0; b_k < nz; b_k++) {
        obj->pGainCorrectionMatrix[b_k + 10 * k] = tmp_data_1[m[0] * k + b_k];
      }
    }

    for (k = 0; k < 10; k++) {
      b_0[k] = obj->Gains[k];
    }

    for (k = 0; k < 100; k++) {
      tmp_data_1[k] = obj->pGainCorrectionMatrix[k];
    }

    for (k = 0; k < 10; k++) {
      varargin_12 = 0.0;
      for (b_k = 0; b_k < 10; b_k++) {
        varargin_12 += tmp_data_1[10 * k + b_k] * (10.0 * b_0[b_k]);
      }

      b[k] = varargin_12;
    }

    obj_0 = obj->pMPEQ1;
    flag = (obj_0->isInitialized == 1);
    if (flag) {
      obj_0->TunablePropsChanged = true;
    }

    obj_0 = obj->pMPEQ1;
    for (k = 0; k < 10; k++) {
      digw_data[k] = obj_0->privPeakGains[k];
    }

    flag = true;
    b_k = 0;
    exitg1 = false;
    while (!exitg1 && (b_k < 10)) {
      if (!(digw_data[b_k] == b[b_k])) {
        flag = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (!flag) {
      memcpy(&b_0[0], &b[0], 10U * sizeof(real_T));
      for (k = 0; k < 10; k++) {
        obj_0->privPeakGains[k] = b_0[k];
      }

      obj_0->AreFiltersDesigned = false;
    }

    if (obj->pMPEQ1->SampleRate != obj->SampleRate) {
      obj_0 = obj->pMPEQ1;
      flag = (obj_0->isInitialized == 1);
      if (flag) {
        obj_0->TunablePropsChanged = true;
      }

      obj_0 = obj->pMPEQ1;
      varargin_12 = obj->SampleRate;
      obj_0->SampleRate = varargin_12;
      obj_0->AreFiltersDesigned = false;
    }

    obj->pIsGainInSync = true;
  }

  obj_0 = obj->pMPEQ1;
  obj_0->isSetupComplete = false;
  obj_0->isInitialized = 1;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj_0->NumChannels = 2.0;
  Fs = (real32_T)obj_0->SampleRate;
  Nyquist = Fs / 2.0F;
  for (k = 0; k < 10; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    b_0[k] = obj_0->privFrequencies[k];
  }

  for (b_k = 0; b_k < 10; b_k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    g = (real32_T)b_0[b_k];
    if ((Nyquist <= g) || rtIsNaNF(g)) {
      minval[b_k] = Nyquist;
    } else {
      minval[b_k] = g;
    }
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_d(minval,
    obj_0->privPeakGains, obj_0->privQualityFactors, Fs, B1, A);
  for (k = 0; k < 30; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_0->NumMatrix[k] = B1[k];
  }

  for (k = 0; k < 30; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_0->DenMatrix[k] = A[k];
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj_0->AreFiltersDesigned = true;
  obj_0->isSetupComplete = true;
  obj_0->TunablePropsChanged = false;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients(const
  real32_T u2[30], const real32_T u3[30], real32_T y[50])
{
  int32_T b_i;
  int32_T y_tmp;
  int32_T y_tmp_0;
  real32_T b_denumValues[30];
  real32_T b_numValues[30];
  real32_T tmp_0[3];
  real32_T tmp;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  mw_arm_mat_trans_f32((real32_T *)&u2[0], &b_numValues[0], 3U, 10U);
  mw_arm_mat_trans_f32((real32_T *)&u3[0], &b_denumValues[0], 3U, 10U);
  for (b_i = 0; b_i < 10; b_i++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    tmp = -1.0F;
    mw_arm_scalar_mult_vector_f32(&tmp, &b_denumValues[3 * b_i], &tmp_0[0], 3U);
    b_denumValues[3 * b_i] = tmp_0[0];
    b_denumValues[3 * b_i + 1] = tmp_0[1];
    b_denumValues[3 * b_i + 2] = tmp_0[2];
  }

  for (b_i = 0; b_i < 10; b_i++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    y[5 * b_i] = b_numValues[3 * b_i];
    y_tmp = 3 * b_i + 1;
    y[5 * b_i + 1] = b_numValues[y_tmp];
    y_tmp_0 = 3 * b_i + 2;
    y[5 * b_i + 2] = b_numValues[y_tmp_0];
    y[5 * b_i + 3] = b_denumValues[y_tmp];
    y[5 * b_i + 4] = b_denumValues[y_tmp_0];
  }
}

static void AudioSmartSpeakerOnJetsonNano_graphicEQ_stepImpl
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj, const real32_T
   u[8820], real32_T y[8820])
{
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *obj_0;
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj_1;
  creal_T s_data[10];
  creal_T tmp_data[10];
  creal32_T h_data[100];
  creal32_T g_data[10];
  creal32_T h_data_0[10];
  creal32_T y_data_0[10];
  real_T tmp_data_1[100];
  real_T b[10];
  real_T b_value[10];
  real_T digw_data[10];
  real_T obj_2;
  int32_T b_idx;
  int32_T b_k;
  int32_T k;
  int32_T loop_ub;
  int32_T nz;
  int32_T tmp_0;
  real32_T tmp_data_0[100];
  real32_T y_data[100];
  real32_T tmp[50];
  real32_T A[30];
  real32_T A1[30];
  real32_T B[30];
  real32_T B1[30];
  real32_T minval[10];
  real32_T B_re;
  real32_T Fs;
  real32_T Nyquist;
  real32_T bim;
  real32_T g;
  real32_T g_0;
  int8_T m[2];
  boolean_T x[9];
  boolean_T flag;
  static const real_T tmp_1[9] = { 44.66835921509632, 89.12509381337456,
    177.82794100389228, 354.8133892335755, 707.9457843841379, 1412.5375446227542,
    2818.382931264454, 5623.41325190349, 11220.184543019634 };

  static const real_T tmp_2[10] = { 31.6227766016838, 63.09573444801933,
    125.89254117941672, 251.188643150958, 501.18723362727235, 1000.0,
    1995.2623149688795, 3981.0717055349724, 7943.282347242814,
    15848.931924611134 };

  int32_T g_size[2];
  int32_T h_size[2];
  int32_T s_size[2];
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T y_size[2];
  boolean_T exitg1;
  obj_0 = obj->pEQ;
  if (obj_0->isInitialized != 1) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    AudioSmartSpeakerOnJetsonNano_SystemCore_setup(obj_0);
    obj_1 = obj_0->pMPEQ1;
    if ((obj_1->isInitialized == 1) && (obj_1->SOSFilterObj.isInitialized == 1))
    {
      /* System object Initialization function: dsp.SOSFilter */
      AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
        (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
         tmp);
      for (k = 0; k < 50; k++) {
        obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
      }

      AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
        (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
         tmp);
      for (k = 0; k < 50; k++) {
        obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
      }

      mw_arm_biquad_cascade_df2T_init_f32(&obj_1->SOSFilterObj.cSFunObject.S,
        10U, &obj_1->SOSFilterObj.cSFunObject.coefficients[0],
        &obj_1->SOSFilterObj.cSFunObject.pState[0], 2U, 2U);
    }
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if (obj_0->TunablePropsChanged) {
    obj_0->TunablePropsChanged = false;
    if (!obj_0->pIsGainInSync) {
      obj_1 = obj_0->pMPEQ1;
      for (k = 0; k < 10; k++) {
        digw_data[k] = obj_1->privFrequencies[k];
      }

      obj_1 = obj_0->pMPEQ1;
      for (k = 0; k < 10; k++) {
        b_value[k] = obj_1->privQualityFactors[k];
      }

      AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ(digw_data,
        b_value, obj_0->SampleRate, B1, A1);
      mw_arm_mat_trans_f32(&B1[0], &B[0], 3U, 10U);
      mw_arm_mat_trans_f32(&A1[0], &A[0], 3U, 10U);
      obj_2 = obj_0->SampleRate / 2.0;
      for (k = 0; k < 9; k++) {
        x[k] = (obj_2 > tmp_1[k]);
      }

      nz = x[0] + 1;
      for (k = 0; k < 8; k++) {
        nz += x[k + 1];
      }

      h_size[0] = nz;
      h_size[1] = nz;
      loop_ub = nz * nz;
      for (k = 0; k < loop_ub; k++) {
        h_data[k].re = 1.0F;
        h_data[k].im = 0.0F;
      }

      for (b_idx = 0; b_idx < nz; b_idx++) {
        for (k = 0; k < nz; k++) {
          digw_data[k] = 6.283185307179586 * tmp_2[k] / obj_0->SampleRate;
        }

        tmp_size[0] = 1;
        tmp_size[1] = nz;
        for (k = 0; k < nz; k++) {
          obj_2 = digw_data[k];
          tmp_data[k].re = obj_2 * 0.0;
          tmp_data[k].im = obj_2;
        }

        AudioSmartSpeakerOnJetsonNano_exp(tmp_data, tmp_size, s_data, s_size);
        tmp_0 = s_size[1];
        g_size[0] = 1;
        g_size[1] = s_size[1];
        if (s_size[1] != 0) {
          g_size[0] = 1;
          g_size[1] = s_size[1];
          for (k = 0; k < tmp_0; k++) {
            g_data[k].re = B[3 * b_idx];
            g_data[k].im = 0.0F;
          }

          for (b_k = 0; b_k < 2; b_k++) {
            if (s_size[1] == g_size[1]) {
              B_re = B[(3 * b_idx + b_k) + 1];
              loop_ub = s_size[1] - 1;
              g_size[0] = 1;
              g_size[1] = s_size[1];
              for (k = 0; k <= loop_ub; k++) {
                Fs = (real32_T)s_data[k].re;
                Nyquist = (real32_T)s_data[k].im;
                g = g_data[k].im;
                g_0 = g_data[k].re;
                g_data[k].re = (Fs * g_0 - Nyquist * g) + B_re;
                g_data[k].im = Fs * g + Nyquist * g_0;
              }
            } else {
              AudioSmartSpeakerOnJetsonNano_binary_expand_op(g_data, g_size,
                s_data, s_size, B, b_idx, b_k);
            }
          }
        }

        y_size[0] = 1;
        y_size[1] = s_size[1];
        if (s_size[1] != 0) {
          y_size[0] = 1;
          y_size[1] = s_size[1];
          for (k = 0; k < tmp_0; k++) {
            y_data_0[k].re = A[3 * b_idx];
            y_data_0[k].im = 0.0F;
          }

          for (b_k = 0; b_k < 2; b_k++) {
            if (s_size[1] == y_size[1]) {
              g = A[(3 * b_idx + b_k) + 1];
              loop_ub = s_size[1] - 1;
              y_size[0] = 1;
              y_size[1] = s_size[1];
              for (k = 0; k <= loop_ub; k++) {
                Fs = (real32_T)s_data[k].re;
                Nyquist = (real32_T)s_data[k].im;
                g_0 = y_data_0[k].im;
                B_re = y_data_0[k].re;
                y_data_0[k].re = (Fs * B_re - Nyquist * g_0) + g;
                y_data_0[k].im = Fs * g_0 + Nyquist * B_re;
              }
            } else {
              AudioSmartSpeakerOnJetsonNano_binary_expand_op(y_data_0, y_size,
                s_data, s_size, A, b_idx, b_k);
            }
          }
        }

        if ((nz == g_size[1]) && ((nz == 1 ? g_size[1] : nz) == y_size[1])) {
          for (k = 0; k < nz; k++) {
            b_k = h_size[0] * b_idx + k;
            Nyquist = h_data[b_k].re;
            B_re = h_data[b_k].im;
            g = g_data[k].re;
            g_0 = g_data[k].im;
            Fs = Nyquist * g - B_re * g_0;
            Nyquist = Nyquist * g_0 + B_re * g;
            B_re = y_data_0[k].re;
            g = y_data_0[k].im;
            if (g == 0.0F) {
              if (Nyquist == 0.0F) {
                h_data_0[k].re = Fs / B_re;
                h_data_0[k].im = 0.0F;
              } else if (Fs == 0.0F) {
                h_data_0[k].re = 0.0F;
                h_data_0[k].im = Nyquist / B_re;
              } else {
                h_data_0[k].re = Fs / B_re;
                h_data_0[k].im = Nyquist / B_re;
              }
            } else if (B_re == 0.0F) {
              if (Fs == 0.0F) {
                h_data_0[k].re = Nyquist / g;
                h_data_0[k].im = 0.0F;
              } else if (Nyquist == 0.0F) {
                h_data_0[k].re = 0.0F;
                h_data_0[k].im = -(Fs / g);
              } else {
                h_data_0[k].re = Nyquist / g;
                h_data_0[k].im = -(Fs / g);
              }
            } else {
              g_0 = (real32_T)fabs(B_re);
              bim = (real32_T)fabs(g);
              if (g_0 > bim) {
                g_0 = g / B_re;
                g = g_0 * g + B_re;
                h_data_0[k].re = (g_0 * Nyquist + Fs) / g;
                h_data_0[k].im = (Nyquist - g_0 * Fs) / g;
              } else if (bim == g_0) {
                B_re = B_re > 0.0F ? 0.5F : -0.5F;
                g = g > 0.0F ? 0.5F : -0.5F;
                h_data_0[k].re = (Fs * B_re + Nyquist * g) / g_0;
                h_data_0[k].im = (Nyquist * B_re - Fs * g) / g_0;
              } else {
                g_0 = B_re / g;
                g += g_0 * B_re;
                h_data_0[k].re = (g_0 * Fs + Nyquist) / g;
                h_data_0[k].im = (g_0 * Nyquist - Fs) / g;
              }
            }

            h_data[b_k] = h_data_0[k];
          }
        } else {
          AudioSmartSpeakerOnJetsonNano_binary_expand_op_2(h_data, h_size, nz,
            b_idx, nz - 1, g_data, g_size, y_data_0, y_size);
        }
      }

      b_idx = h_size[0] * h_size[1];
      for (b_k = 0; b_k < b_idx; b_k++) {
        y_data[b_k] = rt_hypotf_snf(h_data[b_k].re, h_data[b_k].im);
        y_data[b_k] = (real32_T)log10(y_data[b_k]);
      }

      for (k = 0; k < 100; k++) {
        obj_0->pGainCorrectionMatrix[k] = 0.0;
      }

      tmp_size_0[0] = h_size[0];
      tmp_size_0[1] = h_size[1];
      for (k = 0; k < b_idx; k++) {
        tmp_data_0[k] = y_data[k] * 20.0F;
      }

      AudioSmartSpeakerOnJetsonNano_inv(tmp_data_0, tmp_size_0, y_data, y_size);
      loop_ub = y_size[1];
      tmp_0 = y_size[1];
      b_idx = y_size[0];
      for (k = 0; k < b_idx; k++) {
        for (b_k = 0; b_k < loop_ub; b_k++) {
          tmp_data_1[b_k + tmp_0 * k] = y_data[y_size[0] * b_k + k];
        }
      }

      m[0] = (int8_T)nz;
      for (k = 0; k < nz; k++) {
        for (b_k = 0; b_k < nz; b_k++) {
          obj_0->pGainCorrectionMatrix[b_k + 10 * k] = tmp_data_1[m[0] * k + b_k];
        }
      }

      for (k = 0; k < 10; k++) {
        b_value[k] = obj_0->Gains[k];
      }

      for (k = 0; k < 100; k++) {
        tmp_data_1[k] = obj_0->pGainCorrectionMatrix[k];
      }

      for (k = 0; k < 10; k++) {
        obj_2 = 0.0;
        for (b_k = 0; b_k < 10; b_k++) {
          obj_2 += tmp_data_1[10 * k + b_k] * (10.0 * b_value[b_k]);
        }

        b[k] = obj_2;
      }

      obj_1 = obj_0->pMPEQ1;
      flag = (obj_1->isInitialized == 1);
      if (flag) {
        obj_1->TunablePropsChanged = true;
      }

      obj_1 = obj_0->pMPEQ1;
      for (k = 0; k < 10; k++) {
        digw_data[k] = obj_1->privPeakGains[k];
      }

      flag = true;
      b_k = 0;
      exitg1 = false;
      while (!exitg1 && (b_k < 10)) {
        if (!(digw_data[b_k] == b[b_k])) {
          flag = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (!flag) {
        memcpy(&b_value[0], &b[0], 10U * sizeof(real_T));
        for (k = 0; k < 10; k++) {
          obj_1->privPeakGains[k] = b_value[k];
        }

        obj_1->AreFiltersDesigned = false;
      }

      if (obj_0->pMPEQ1->SampleRate != obj_0->SampleRate) {
        obj_1 = obj_0->pMPEQ1;
        flag = (obj_1->isInitialized == 1);
        if (flag) {
          obj_1->TunablePropsChanged = true;
        }

        obj_1 = obj_0->pMPEQ1;
        obj_2 = obj_0->SampleRate;
        obj_1->SampleRate = obj_2;
        obj_1->AreFiltersDesigned = false;
      }

      obj_0->pIsGainInSync = true;
    }
  }

  obj_1 = obj_0->pMPEQ1;
  if (obj_1->isInitialized != 1) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_1->isSetupComplete = false;
    obj_1->isInitialized = 1;
    obj_1->NumChannels = 2.0;
    Fs = (real32_T)obj_1->SampleRate;
    Nyquist = Fs / 2.0F;
    for (k = 0; k < 10; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      b_value[k] = obj_1->privFrequencies[k];
    }

    for (b_k = 0; b_k < 10; b_k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      g = (real32_T)b_value[b_k];
      if ((Nyquist <= g) || rtIsNaNF(g)) {
        minval[b_k] = Nyquist;
      } else {
        minval[b_k] = g;
      }
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_d(minval,
      obj_1->privPeakGains, obj_1->privQualityFactors, Fs, B1, A);
    for (k = 0; k < 30; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      obj_1->NumMatrix[k] = B1[k];
    }

    for (k = 0; k < 30; k++) {
      /* Start for MATLABSystem: '<S4>/Graphic EQ' */
      obj_1->DenMatrix[k] = A[k];
    }

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_1->AreFiltersDesigned = true;
    obj_1->isSetupComplete = true;
    obj_1->TunablePropsChanged = false;
    if (obj_1->SOSFilterObj.isInitialized == 1) {
      /* System object Initialization function: dsp.SOSFilter */
      AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
        (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
         tmp);
      for (k = 0; k < 50; k++) {
        obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
      }

      AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
        (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
         tmp);
      for (k = 0; k < 50; k++) {
        obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
      }

      mw_arm_biquad_cascade_df2T_init_f32(&obj_1->SOSFilterObj.cSFunObject.S,
        10U, &obj_1->SOSFilterObj.cSFunObject.coefficients[0],
        &obj_1->SOSFilterObj.cSFunObject.pState[0], 2U, 2U);
    }
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if (obj_1->TunablePropsChanged) {
    obj_1->TunablePropsChanged = false;
    if (!obj_1->AreFiltersDesigned) {
      Fs = (real32_T)obj_1->SampleRate;
      Nyquist = Fs / 2.0F;
      for (k = 0; k < 10; k++) {
        b_value[k] = obj_1->privFrequencies[k];
      }

      for (b_k = 0; b_k < 10; b_k++) {
        g = (real32_T)b_value[b_k];
        if ((Nyquist <= g) || rtIsNaNF(g)) {
          minval[b_k] = Nyquist;
        } else {
          minval[b_k] = g;
        }
      }

      AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_d(minval,
        obj_1->privPeakGains, obj_1->privQualityFactors, Fs, B1, A);
      for (k = 0; k < 30; k++) {
        obj_1->NumMatrix[k] = B1[k];
      }

      for (k = 0; k < 30; k++) {
        obj_1->DenMatrix[k] = A[k];
      }

      obj_1->AreFiltersDesigned = true;
    }
  }

  for (k = 0; k < 30; k++) {
    B[k] = obj_1->NumMatrix[k];
  }

  for (k = 0; k < 30; k++) {
    A[k] = obj_1->DenMatrix[k];
  }

  if (obj_1->SOSFilterObj.isInitialized != 1) {
    obj_1->SOSFilterObj.isSetupComplete = false;
    obj_1->SOSFilterObj.isInitialized = 1;
    obj_1->SOSFilterObj.isSetupComplete = true;

    /* System object Initialization function: dsp.SOSFilter */
    AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
      (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
       tmp);
    for (k = 0; k < 50; k++) {
      obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
    }

    AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
      (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2,
       tmp);
    for (k = 0; k < 50; k++) {
      obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
    }

    mw_arm_biquad_cascade_df2T_init_f32(&obj_1->SOSFilterObj.cSFunObject.S, 10U,
      &obj_1->SOSFilterObj.cSFunObject.coefficients[0],
      &obj_1->SOSFilterObj.cSFunObject.pState[0], 2U, 2U);
  }

  memcpy(&AudioSmartSpeakerOnJetsonNano_B.U0[0], &u[0], 8820U * sizeof(real32_T));
  for (k = 0; k < 30; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_1->SOSFilterObj.cSFunObject.U2[k] = A[k];
  }

  for (k = 0; k < 30; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_1->SOSFilterObj.cSFunObject.U1[k] = B[k];
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  /* System object Outputs function: dsp.SOSFilter */
  AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
    (obj_1->SOSFilterObj.cSFunObject.U1, obj_1->SOSFilterObj.cSFunObject.U2, tmp);
  for (k = 0; k < 50; k++) {
    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    obj_1->SOSFilterObj.cSFunObject.coefficients[k] = tmp[k];
  }

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  mw_arm_biquad_cascade_df2T_f32(&obj_1->SOSFilterObj.cSFunObject.S,
    &AudioSmartSpeakerOnJetsonNano_B.U0[0], &y[0], 4410U, 2U,
    &obj_1->SOSFilterObj.cSFunObject.pState[0], 2U);
}

static void AudioSmartSpeakerOnJetsonNano_SystemCore_step
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj, const real32_T
   varargin_1[8820], real32_T varargout_1[8820])
{
  b_audio_internal_GraphicEQCascade_AudioSmartSpeakerOnJetsonNano_T *obj_0;
  real_T b_value;
  boolean_T flag;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj_0 = obj->pEQ;
    flag = (obj_0->isInitialized == 1);
    if (flag) {
      obj_0->TunablePropsChanged = true;
    }

    b_value = obj->pSampleRateDialog;
    obj_0 = obj->pEQ;
    obj_0->SampleRate = b_value;
    obj_0->pIsGainInSync = false;
    AudioSmartSpeakerOnJetsonNano_graphicEQ_setGainsToEQ(obj);
  }

  /* End of Start for MATLABSystem: '<S4>/Graphic EQ' */
  AudioSmartSpeakerOnJetsonNano_graphicEQ_stepImpl(obj, varargin_1, varargout_1);
}

static void AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_du
  (real32_T Wo[10], const real_T G[10], const real_T Q[10], real32_T Fs,
   real32_T B[9], real32_T A[9])
{
  int32_T Af_size[2];
  int32_T Bf_size[2];
  int32_T b_data_tmp;
  int32_T b_data_tmp_0;
  int32_T b_k;
  int32_T b_k_0;
  int32_T i;
  real32_T b_G[10];
  real32_T B0[9];
  real32_T A0[6];
  real32_T tmp[6];
  real32_T Af_data[5];
  real32_T Bf_data[5];
  real32_T BWnew[3];
  real32_T Wonew[3];
  real32_T b_data[3];
  real32_T options_Gain[3];
  real32_T c_data[2];
  real32_T FN;
  real32_T GB;
  real32_T Gsq;
  real32_T b_G_0;
  boolean_T Bf_data_0[2];
  boolean_T x[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  FN = Fs / 2.0F;
  for (b_k_0 = 0; b_k_0 < 10; b_k_0++) {
    b_G[b_k_0] = (real32_T)G[b_k_0];

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    Wo[b_k_0] /= FN;
  }

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  options_Gain[0] = (real32_T)G[0];
  Wonew[0] = Wo[0];

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  BWnew[0] = Wo[0] / (real32_T)Q[0];
  options_Gain[1] = (real32_T)G[1];
  Wonew[1] = Wo[1];

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  BWnew[1] = Wo[1] / (real32_T)Q[1];
  options_Gain[2] = (real32_T)G[2];
  Wonew[2] = Wo[2];

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  BWnew[2] = Wo[2] / (real32_T)Q[2];
  for (i = 0; i < 3; i++) {
    if (Wo[i] > 1.0F) {
      Wonew[i] = 1.0F;
    }

    FN = BWnew[i];
    if (FN > 1.0F) {
      FN = 1.0F;
      BWnew[i] = 1.0F;
    }

    if (FN < 0.0F) {
      BWnew[i] = 0.0F;
    }
  }

  for (b_k_0 = 0; b_k_0 < 9; b_k_0++) {
    B0[b_k_0] = 0.0F;
  }

  for (b_k_0 = 0; b_k_0 < 6; b_k_0++) {
    A0[b_k_0] = 0.0F;
  }

  FN = 1.0F;
  for (b_k = 0; b_k < 3; b_k++) {
    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    Gsq = options_Gain[b_k];
    GB = Gsq / 2.0F;
    b_G_0 = b_G[b_k];
    if (rtIsInfF(b_G_0) && (Gsq < 0.0F)) {
      GB = -3.0103002F;
    }

    b_data[1] = 0.0F;
    b_data[2] = 0.0F;
    b_data[0] = 1.0F;
    c_data[0] = 0.0F;
    c_data[1] = 0.0F;

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    if (!((real32_T)fabs(b_G_0) <= 1.1920929E-7F)) {
      Gsq = rt_powf_snf(10.0F, Gsq / 10.0F);
      GB = rt_powf_snf(10.0F, GB / 10.0F);
      if (!((real32_T)fabs(Gsq - GB) <= 1.1920929E-7F) && !((real32_T)fabs(GB -
            1.0F) <= 1.1920929E-7F)) {
        AudioSmartSpeakerOnJetsonNano_designBandPassOctaveFilter(Wonew[b_k],
          BWnew[b_k], Gsq, GB, Bf_data, Bf_size, Af_data, Af_size);
        Bf_data_0[0] = (Bf_data[3] == 0.0F);
        Bf_data_0[1] = (Bf_data[4] == 0.0F);
        AudioSmartSpeakerOnJetsonNano_all(Bf_data_0, x);
        y = true;
        b_k_0 = 0;
        exitg1 = false;
        while (!exitg1 && (b_k_0 < 2)) {
          if (!x[b_k_0]) {
            y = false;
            exitg1 = true;
          } else {
            b_k_0++;
          }
        }

        guard1 = false;
        if (y) {
          Bf_data_0[0] = (Af_data[3] == 0.0F);
          Bf_data_0[1] = (Af_data[4] == 0.0F);
          AudioSmartSpeakerOnJetsonNano_all(Bf_data_0, x);
          y = true;
          b_k_0 = 0;
          exitg1 = false;
          while (!exitg1 && (b_k_0 < 2)) {
            if (!x[b_k_0]) {
              y = false;
              exitg1 = true;
            } else {
              b_k_0++;
            }
          }

          if (y) {
            b_data[0] = Bf_data[0];
            b_data[1] = Bf_data[1];
            b_data[2] = Bf_data[2];
            c_data[0] = Af_data[1];
            c_data[1] = Af_data[2];
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          b_data[0] = Bf_data[0];
          b_data[1] = Bf_data[1];
          b_data[2] = Bf_data[2];
          c_data[0] = Af_data[1];
          c_data[1] = Af_data[2];
        }
      }
    }

    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      b_k_0 = 0;
    } else {
      i = (int32_T)FN - 1;
      b_k_0 = (int32_T)((FN + 1.0F) - 1.0F);
    }

    b_data_tmp_0 = b_k_0 - i;
    for (b_k_0 = 0; b_k_0 < b_data_tmp_0; b_k_0++) {
      /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
      b_data_tmp = (i + b_k_0) * 3;
      B0[b_data_tmp] = b_data[3 * b_k_0];
      B0[b_data_tmp + 1] = b_data[3 * b_k_0 + 1];
      B0[b_data_tmp + 2] = b_data[3 * b_k_0 + 2];
    }

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    if (FN > (FN + 1.0F) - 1.0F) {
      i = 0;
      b_k_0 = 0;
    } else {
      i = (int32_T)FN - 1;
      b_k_0 = (int32_T)((FN + 1.0F) - 1.0F);
    }

    b_data_tmp_0 = b_k_0 - i;
    for (b_k_0 = 0; b_k_0 < b_data_tmp_0; b_k_0++) {
      /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
      b_data_tmp = (i + b_k_0) << 1;
      A0[b_data_tmp] = c_data[b_k_0 << 1];
      A0[b_data_tmp + 1] = c_data[(b_k_0 << 1) + 1];
    }

    FN++;
  }

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  mw_arm_mat_trans_f32(&B0[0], &B[0], 3U, 3U);
  mw_arm_mat_trans_f32(&A0[0], &tmp[0], 3U, 2U);
  A[0] = 1.0F;
  A[1] = 1.0F;
  A[2] = 1.0F;
  for (b_k_0 = 0; b_k_0 < 6; b_k_0++) {
    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    A[b_k_0 + 3] = tmp[b_k_0];
  }
}

static void AudioSmartSpeakerOnJetsonNano_SystemCore_step_d
  (audio_simulink_MultibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj,
   const real32_T varargin_1[8820], real32_T varargout_1[8820])
{
  real_T b[10];
  int32_T b_k;
  int32_T i;
  int32_T memOffset;
  int32_T stageIn_tmp;
  real32_T minval[10];
  real32_T Nyquist;
  real32_T obj_pEQ;
  real32_T obj_pEQ_0;
  real32_T obj_pEQ_1;
  real32_T obj_pEQ_2;
  real32_T obj_pEQ_3;
  real32_T obj_pEQ_4;
  real32_T obj_pEQ_5;
  real32_T obj_pEQ_6;
  real32_T obj_pEQ_7;
  real32_T obj_pEQ_8;
  real32_T obj_pEQ_9;
  real32_T obj_pEQ_a;
  real32_T obj_pEQ_b;
  real32_T obj_pEQ_c;
  real32_T obj_pEQ_d;
  real32_T obj_pEQ_e;
  real32_T obj_pEQ_f;
  real32_T obj_pEQ_g;
  real32_T obj_pEQ_h;
  real32_T stageIn;
  real32_T stageOut;
  real32_T u1;
  boolean_T exitg1;
  boolean_T p;

  /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    if (obj->pEQ.isInitialized == 1) {
      obj->pEQ.TunablePropsChanged = true;
    }

    p = true;
    b_k = 0;
    exitg1 = false;
    while (!exitg1 && (b_k < 3)) {
      if (!(obj->pEQ.privFrequencies[b_k] == obj->Frequencies[b_k])) {
        p = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (!p) {
      memcpy(&b[0], &obj->pEQ.privFrequencies[0], 10U * sizeof(real_T));
      b[0] = obj->Frequencies[0];
      b[1] = obj->Frequencies[1];
      b[2] = obj->Frequencies[2];
      memcpy(&obj->pEQ.privFrequencies[0], &b[0], 10U * sizeof(real_T));
      obj->pEQ.AreFiltersDesigned = false;
    }

    if (obj->pEQ.isInitialized == 1) {
      obj->pEQ.TunablePropsChanged = true;
    }

    p = true;
    b_k = 0;
    exitg1 = false;
    while (!exitg1 && (b_k < 3)) {
      if (!(obj->pEQ.privQualityFactors[b_k] == obj->QualityFactors[b_k])) {
        p = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (!p) {
      memcpy(&b[0], &obj->pEQ.privQualityFactors[0], 10U * sizeof(real_T));
      b[0] = obj->QualityFactors[0];
      b[1] = obj->QualityFactors[1];
      b[2] = obj->QualityFactors[2];
      memcpy(&obj->pEQ.privQualityFactors[0], &b[0], 10U * sizeof(real_T));
      obj->pEQ.AreFiltersDesigned = false;
    }

    if (obj->pEQ.isInitialized == 1) {
      obj->pEQ.TunablePropsChanged = true;
    }

    p = true;
    b_k = 0;
    exitg1 = false;
    while (!exitg1 && (b_k < 3)) {
      if (!(obj->pEQ.privPeakGains[b_k] == obj->PeakGains[b_k])) {
        p = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (!p) {
      memcpy(&b[0], &obj->pEQ.privPeakGains[0], 10U * sizeof(real_T));
      b[0] = obj->PeakGains[0];
      b[1] = obj->PeakGains[1];
      b[2] = obj->PeakGains[2];
      memcpy(&obj->pEQ.privPeakGains[0], &b[0], 10U * sizeof(real_T));
      obj->pEQ.AreFiltersDesigned = false;
    }
  }

  if (obj->pEQ.isInitialized != 1) {
    obj->pEQ.isInitialized = 1;
    obj->pEQ.NumChannels = 2.0;
    Nyquist = (real32_T)obj->pEQ.SampleRate / 2.0F;
    for (b_k = 0; b_k < 10; b_k++) {
      u1 = (real32_T)obj->pEQ.privFrequencies[b_k];
      if ((Nyquist <= u1) || rtIsNaNF(u1)) {
        minval[b_k] = Nyquist;
      } else {
        minval[b_k] = u1;
      }
    }

    AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_du(minval,
      obj->pEQ.privPeakGains, obj->pEQ.privQualityFactors, (real32_T)
      obj->pEQ.SampleRate, obj->pEQ.NumMatrix, obj->pEQ.DenMatrix);
    obj->pEQ.AreFiltersDesigned = true;
    obj->pEQ.isSetupComplete = true;
    obj->pEQ.TunablePropsChanged = false;
    if (obj->pEQ.SOSFilterObj.isInitialized == 1) {
      /* System object Initialization function: dsp.SOSFilter */
      for (b_k = 0; b_k < 12; b_k++) {
        obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[b_k] =
          obj->pEQ.SOSFilterObj.cSFunObject.P0_ICRTP;
      }
    }
  }

  if (obj->pEQ.TunablePropsChanged) {
    obj->pEQ.TunablePropsChanged = false;
    if (!obj->pEQ.AreFiltersDesigned) {
      Nyquist = (real32_T)obj->pEQ.SampleRate / 2.0F;
      for (b_k = 0; b_k < 10; b_k++) {
        u1 = (real32_T)obj->pEQ.privFrequencies[b_k];
        if ((Nyquist <= u1) || rtIsNaNF(u1)) {
          minval[b_k] = Nyquist;
        } else {
          minval[b_k] = u1;
        }
      }

      AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_du(minval,
        obj->pEQ.privPeakGains, obj->pEQ.privQualityFactors, (real32_T)
        obj->pEQ.SampleRate, obj->pEQ.NumMatrix, obj->pEQ.DenMatrix);
      obj->pEQ.AreFiltersDesigned = true;
    }
  }

  if (obj->pEQ.SOSFilterObj.isInitialized != 1) {
    obj->pEQ.SOSFilterObj.isInitialized = 1;
    obj->pEQ.SOSFilterObj.isSetupComplete = true;

    /* System object Initialization function: dsp.SOSFilter */
    for (b_k = 0; b_k < 12; b_k++) {
      obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[b_k] =
        obj->pEQ.SOSFilterObj.cSFunObject.P0_ICRTP;
    }
  }

  /* System object Outputs function: dsp.SOSFilter */
  for (b_k = 0; b_k < 2; b_k++) {
    memOffset = 6 * b_k;

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    Nyquist = obj->pEQ.NumMatrix[0];
    u1 = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset];
    obj_pEQ = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 1];
    obj_pEQ_0 = obj->pEQ.NumMatrix[3];
    obj_pEQ_1 = obj->pEQ.DenMatrix[3];
    obj_pEQ_2 = obj->pEQ.NumMatrix[6];
    obj_pEQ_3 = obj->pEQ.DenMatrix[6];
    obj_pEQ_4 = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 2];
    obj_pEQ_5 = obj->pEQ.NumMatrix[1];
    obj_pEQ_6 = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 3];
    obj_pEQ_7 = obj->pEQ.NumMatrix[4];
    obj_pEQ_8 = obj->pEQ.DenMatrix[4];
    obj_pEQ_9 = obj->pEQ.NumMatrix[7];
    obj_pEQ_a = obj->pEQ.DenMatrix[7];
    obj_pEQ_b = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 4];
    obj_pEQ_c = obj->pEQ.NumMatrix[2];
    obj_pEQ_d = obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 5];
    obj_pEQ_e = obj->pEQ.NumMatrix[5];
    obj_pEQ_f = obj->pEQ.DenMatrix[5];
    obj_pEQ_g = obj->pEQ.NumMatrix[8];
    obj_pEQ_h = obj->pEQ.DenMatrix[8];
    for (i = 0; i < 4410; i++) {
      stageIn_tmp = b_k * 4410 + i;

      /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
      stageIn = varargin_1[stageIn_tmp];
      stageOut = Nyquist * stageIn + u1;
      u1 = (obj_pEQ_0 * stageIn + obj_pEQ) - obj_pEQ_1 * stageOut;
      obj_pEQ = obj_pEQ_2 * stageIn - obj_pEQ_3 * stageOut;
      stageIn = stageOut;

      /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
      stageOut = obj_pEQ_5 * stageOut + obj_pEQ_4;
      obj_pEQ_4 = (obj_pEQ_7 * stageIn + obj_pEQ_6) - obj_pEQ_8 * stageOut;
      obj_pEQ_6 = obj_pEQ_9 * stageIn - obj_pEQ_a * stageOut;
      stageIn = stageOut;

      /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
      stageOut = obj_pEQ_c * stageOut + obj_pEQ_b;
      obj_pEQ_b = (obj_pEQ_e * stageIn + obj_pEQ_d) - obj_pEQ_f * stageOut;
      obj_pEQ_d = obj_pEQ_g * stageIn - obj_pEQ_h * stageOut;
      varargout_1[stageIn_tmp] = stageOut;
    }

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 5] = obj_pEQ_d;
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 4] = obj_pEQ_b;
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 3] = obj_pEQ_6;
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 2] = obj_pEQ_4;
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset + 1] = obj_pEQ;
    obj->pEQ.SOSFilterObj.cSFunObject.W0_FILT_STATES[memOffset] = u1;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void AudioSmartSpeakerOnJetsonNano_GraphicEQ_GraphicEQ
  (audio_simulink_GraphicEQ_AudioSmartSpeakerOnJetsonNano_T *obj)
{
  obj->Gain_63Hz = 0.0;
  obj->Gain_125Hz = 0.0;
  obj->Gain_250Hz = 0.0;
  obj->Gain_500Hz = 0.0;
  obj->Gain_1000Hz = 0.0;
  obj->Gain_2000Hz = 0.0;
  obj->Gain_4000Hz = 0.0;
  obj->Gain_8000Hz = 0.0;
  obj->Gain_16000Hz = 0.0;

  /* Start for MATLABSystem: '<S4>/Graphic EQ' */
  obj->pNumChannels = -1.0;
  memset(&obj->pGains[0], 0, 30U * sizeof(real_T));
  obj->isInitialized = 0;
  obj->matlabCodegenIsDeleted = false;
}

static void AudioSmartSpeakerOnJetsonNano_CompressorBase_setupImpl
  (audio_simulink_DynamicRangeLimiter_AudioSmartSpeakerOnJetsonNano_T *obj)
{
  real32_T tmp;

  /* Start for MATLABSystem: '<S4>/Limiter' */
  obj->pSampleRateInherit = 44100.0;
  if (obj->AttackTime != 0.0) {
    tmp = -2.1972246F / ((real32_T)obj->AttackTime * (real32_T)
                         obj->pSampleRateInherit);
    mw_arm_vexp_f32(&tmp, &obj->pAlphaA, 1U);
  } else {
    obj->pAlphaA = 0.0F;
  }

  if (obj->ReleaseTime != 0.0) {
    tmp = -2.1972246F / ((real32_T)obj->ReleaseTime * (real32_T)
                         obj->pSampleRateInherit);
    mw_arm_vexp_f32(&tmp, &obj->pAlphaR, 1U);
  } else {
    obj->pAlphaR = 0.0F;
  }

  obj->pLevelDetectionState[0] = 0.0F;
  obj->pLevelDetectionState[1] = 0.0F;
  obj->pNumChannels = 2.0;

  /* End of Start for MATLABSystem: '<S4>/Limiter' */
  obj->pMakeUpGain = (real32_T)obj->MakeUpGain;
}

/* Model step function for TID0 */
void AudioSmartSpeakerOnJetsonNano_step0(void) /* Sample time: [0.01s, 0.0s] */
{
  int32_T currentOffset;
  int32_T i;
  int32_T nSamps;
  int32_T offsetFromMemBase;
  int32_T uyIdx;
  real32_T xw[400];
  real32_T Z[257];
  static const real32_T filterBank[12850] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.022785407F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.008617968F, 0.01745801F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01340112F, 0.0118881585F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.018358255F,
    0.006176974F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.02339464F, 0.0004463189F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.005996797F, 0.01836643F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.011552228F, 0.013601258F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.017136263F, 0.0083585465F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.02190866F, 0.0030706462F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.002578188F, 0.021718208F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.008620725F,
    0.015024113F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.014636622F, 0.008379636F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.020559045F, 0.0018495163F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.005058294F, 0.016772004F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.011967158F, 0.0093066655F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.018604683F, 0.0021284067F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005319955F, 0.014898331F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.012655505F,
    0.007065908F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0003851322F, 0.018851386F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.008261212F, 0.010518239F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.015634822F, 0.002695905F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0052178414F, 0.01268429F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.012909398F, 0.004577332F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0033361097F, 0.013748462F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.011222847F,
    0.005476067F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.002440938F, 0.013881144F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.010411607F, 0.005551146F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0023709731F, 0.013239189F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.010325417F, 0.0049484973F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0029781135F, 0.011966387F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0108268345F, 0.0038014182F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0041270317F,
    0.010193947F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.011790767F, 0.0022310494F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0056946995F, 0.008040967F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.013103991F, 0.00034685215F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0075699105F, 0.005614917F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0020358302F, 0.010882981F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0096528055F, 0.003012106F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0046409345F, 0.007777127F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.011854393F,
    0.00031816732F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0073268777F, 0.0046170563F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0027993617F, 0.008915946F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.010016939F, 0.0014763471F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.005937797F, 0.0053441646F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0018586562F, 0.009211983F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.008979347F, 0.0018888998F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005314428F, 0.0053589027F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0016495088F,
    0.008828905F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.008585263F, 0.0017067791F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.005302193F, 0.0048104683F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0020191234F, 0.007914158F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.008694225F, 0.0010653301F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0057623633F, 0.0038324988F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0028305016F, 0.0065996675F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.009180951F, 8.5004714E-5F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0065713404F,
    0.0025437847F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0039617303F, 0.0050025648F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0013521201F, 0.007461345F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0076199435F, 0.0010489855F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0053052655F, 0.003225896F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0029905871F, 0.005402806F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0006759089F, 0.007579717F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.006767219F, 0.0013593372F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.004721742F,
    0.0032793318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0026762653F, 0.0051993267F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0006307886F, 0.0071193213F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0064661806F, 0.0011664235F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.004665716F, 0.0028529384F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.002865252F, 0.004539453F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0010647879F, 0.006225968F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00657853F, 0.0006026906F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0050003836F,
    0.0020776913F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0034222372F, 0.0035526918F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0018440908F, 0.0050276923F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00026594437F, 0.006502693F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.005606239F, 0.0010676489F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.004229162F, 0.0023516784F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0028520848F, 0.003635708F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0014750076F, 0.0049197376F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 9.7930395E-5F, 0.006203767F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.005184266F,
    0.001033131F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.003988408F, 0.002145358F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0027925503F, 0.0032575845F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0015966927F, 0.004369811F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00040083504F, 0.005482038F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0051679974F, 0.0006370676F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.004134861F, 0.0015953324F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0031017242F, 0.0025535973F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0020685873F, 0.0035118621F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0010354506F,
    0.0044701267F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    2.3138707E-6F, 0.0054283915F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0045449147F, 0.0008190256F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.003657304F, 0.0016398897F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.002769693F, 0.0024607538F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0018820822F, 0.0032816178F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0009944713F, 0.004102482F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00010686034F, 0.004923346F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0043554055F,
    0.00061466405F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0035973813F, 0.0013134565F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0028393571F, 0.0020122488F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0020813327F, 0.0027110411F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0013233086F, 0.0034098334F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00056528434F, 0.004108626F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.004466203F, 0.00015023703F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0038230347F, 0.00074110227F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0031798661F,
    0.0013319675F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0025366978F, 0.0019228328F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0018935293F, 0.002513698F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0012503609F, 0.0031045633F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00060719246F, 0.0036954286F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0042229327F, 2.7741009E-5F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0036810501F, 0.0005236869F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0031391673F, 0.0010196328F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0025972845F,
    0.0015155786F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0020554017F, 0.0020115245F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0015135187F, 0.0025074703F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0009716359F, 0.0030034161F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0004297531F, 0.0034993622F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.003798935F, 8.544911E-5F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0033458807F, 0.0004983941F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0028928262F, 0.000911339F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0024397718F, 0.001324284F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0019867176F,
    0.001737229F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0015336631F, 0.0021501738F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0010806088F, 0.002563119F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0006275544F, 0.0029760639F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.00017450002F, 0.0033890088F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0033171168F, 0.00020954909F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.002941499F, 0.00055036996F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0025658815F,
    0.00089119084F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.002190264F, 0.0012320117F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0018146462F, 0.0015728326F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0014390287F, 0.0019136535F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.001063411F, 0.0022544742F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00068779336F, 0.0025952952F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00031217578F, 0.002936116F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0031672574F, 4.705212E-5F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0028587026F,
    0.00032563173F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.002550148F, 0.00060421135F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.002241593F, 0.00088279095F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0019330385F, 0.0011613705F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0016244837F, 0.0014399502F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.001315929F, 0.0017185297F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0010073743F, 0.0019971093F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0006988195F, 0.002275689F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0003902648F, 0.0025542686F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 8.171007E-5F, 0.002832848F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0027221658F,
    0.0001656185F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0024712703F, 0.00039089326F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0022203748F, 0.000616168F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0019694793F, 0.0008414428F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0017185839F, 0.0010667176F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0014676884F, 0.0012919923F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0012167929F, 0.001517267F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00096589734F, 0.0017425418F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00071500184F,
    0.0019678166F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00046410633F, 0.0021930912F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00021321083F, 0.002418366F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0025795063F, 2.703725E-5F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.002377789F, 0.00020704478F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0021760715F, 0.0003870523F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0019743543F, 0.00056705985F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0017726369F,
    0.0007470674F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0015709195F, 0.0009270749F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0013692022F, 0.0011070825F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0011674848F, 0.00128709F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0009657675F, 0.0014670976F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0007640501F, 0.001647105F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0005623328F, 0.0018271125F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00036061544F, 0.00200712F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00015889808F, 0.0021871277F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0022949297F,
    3.012731E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0021347844F, 0.00017205407F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.001974639F, 0.00031398085F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0018144938F, 0.0004559076F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0016543486F, 0.0005978344F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0014942032F, 0.00073976116F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0013340579F, 0.0008816879F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0011739127F, 0.0010236147F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0010137673F,
    0.0011655415F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00085362204F, 0.0013074683F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00069347676F, 0.001449395F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0005333315F, 0.0015913218F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0003731862F, 0.0017332486F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00021304088F, 0.0018751753F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 5.2895597E-5F, 0.002017102F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0019800316F,
    7.8934056E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0018546797F, 0.00019679843F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0017293277F, 0.00031466282F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0016039758F, 0.0004325272F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0014786237F, 0.00055039156F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0013532718F, 0.0006682559F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0012279198F, 0.0007861203F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0011025679F,
    0.00090398465F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0009772159F, 0.001021849F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.00085186394F, 0.0011397135F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.000726512F, 0.0012575778F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00060116005F, 0.0013754421F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00047580808F, 0.0014933065F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0003504561F, 0.0016111709F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00022510413F,
    0.0017290353F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    9.975217E-5F, 0.0018468996F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0019166912F, 2.3461589E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0017991619F, 0.00013834363F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0016816326F, 0.00025322568F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0015641033F, 0.00036810772F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.001446574F,
    0.00048298977F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0013290448F, 0.00059787184F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0012115155F, 0.00071275386F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0010939862F, 0.00082763593F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00097645697F, 0.00094251795F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00085892767F, 0.0010574F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00074139837F,
    0.001172282F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0006238691F, 0.0012871642F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0005063398F, 0.0014020462F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00038881056F, 0.0015169282F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0002712813F, 0.0016318102F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.000153752F, 0.0017466923F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 3.6222726E-5F, 0.0018615744F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0018207955F, 7.0052134E-5F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0017106684F,
    0.00017131306F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0016005414F, 0.000272574F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0014904144F, 0.00037383495F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0013802873F, 0.00047509588F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0012701603F, 0.0005763568F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0011600333F, 0.00067761773F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0010499062F, 0.0007788787F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00093977916F,
    0.0008801396F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0008296521F, 0.0009814005F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0007195251F, 0.0010826614F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00060939806F, 0.0011839224F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00049927103F, 0.0012851834F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00038914397F, 0.0013864442F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00027901694F,
    0.0014877052F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.00016888989F, 0.0015889661F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 5.8762846E-5F, 0.0016902271F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0017024672F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0016128636F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0015232601F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0014336566F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0013440531F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0012544495F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.001164846F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0010752424F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0009856389F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00089603534F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0008064318F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0007168283F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00062722474F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0005376212F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00044801767F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00035841414F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0002688106F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.00017920707F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 8.9603534E-5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  creal32_T tmp[512];
  real32_T rtb_InputBuffer[400];
  real32_T AuditorySpectrumExtractor[50];
  real32_T tmp_0[50];
  real32_T x;
  static const real32_T tmp_1[400] = { 0.0F, 6.168376E-5F, 0.0002467198F,
    0.0005550625F, 0.0009866358F, 0.0015413332F, 0.0022190176F, 0.0030195222F,
    0.0039426493F, 0.004988171F, 0.00615583F, 0.007445337F, 0.008856375F,
    0.010388595F, 0.012041619F, 0.01381504F, 0.015708419F, 0.017721292F,
    0.019853158F, 0.022103492F, 0.024471741F, 0.02695732F, 0.029559616F,
    0.032277986F, 0.03511176F, 0.038060233F, 0.041122686F, 0.044298362F,
    0.047586475F, 0.05098621F, 0.05449674F, 0.058117185F, 0.06184666F,
    0.065684244F, 0.069628984F, 0.07367992F, 0.07783604F, 0.082096316F,
    0.08645971F, 0.09092514F, 0.095491506F, 0.10015767F, 0.104922496F,
    0.1097848F, 0.11474338F, 0.11979701F, 0.12494446F, 0.13018446F, 0.13551569F,
    0.14093685F, 0.14644662F, 0.1520436F, 0.15772645F, 0.16349374F, 0.16934407F,
    0.17527598F, 0.181288F, 0.18737867F, 0.19354647F, 0.19978988F, 0.20610738F,
    0.21249737F, 0.21895832F, 0.22548859F, 0.2320866F, 0.23875071F, 0.24547929F,
    0.25227067F, 0.25912318F, 0.26603508F, 0.27300474F, 0.28003043F, 0.28711036F,
    0.29424283F, 0.30142605F, 0.30865827F, 0.31593773F, 0.32326257F, 0.33063105F,
    0.3380413F, 0.3454915F, 0.35297984F, 0.36050445F, 0.36806348F, 0.37565506F,
    0.38327733F, 0.3909284F, 0.39860636F, 0.40630934F, 0.41403544F, 0.42178276F,
    0.4295494F, 0.43733338F, 0.44513285F, 0.45294586F, 0.46077046F, 0.46860474F,
    0.47644678F, 0.48429462F, 0.49214634F, 0.5F, 0.5078537F, 0.5157054F,
    0.52355325F, 0.53139526F, 0.5392296F, 0.5470542F, 0.55486715F, 0.5626666F,
    0.5704506F, 0.5782172F, 0.58596456F, 0.59369063F, 0.60139364F, 0.6090716F,
    0.6167227F, 0.62434494F, 0.63193655F, 0.63949555F, 0.64702016F, 0.6545085F,
    0.6619587F, 0.669369F, 0.6767374F, 0.6840623F, 0.6913417F, 0.69857395F,
    0.7057572F, 0.7128897F, 0.7199696F, 0.7269952F, 0.7339649F, 0.74087685F,
    0.74772936F, 0.7545207F, 0.7612493F, 0.7679134F, 0.7745114F, 0.7810417F,
    0.78750265F, 0.7938926F, 0.8002101F, 0.8064535F, 0.81262136F, 0.818712F,
    0.824724F, 0.83065593F, 0.83650625F, 0.84227353F, 0.8479564F, 0.8535534F,
    0.85906315F, 0.8644843F, 0.8698155F, 0.87505555F, 0.880203F, 0.88525665F,
    0.8902152F, 0.8950775F, 0.8998423F, 0.9045085F, 0.90907484F, 0.9135403F,
    0.91790366F, 0.92216396F, 0.9263201F, 0.930371F, 0.93431574F, 0.9381533F,
    0.9418828F, 0.94550323F, 0.94901377F, 0.9524135F, 0.95570165F, 0.9588773F,
    0.96193975F, 0.9648882F, 0.967722F, 0.9704404F, 0.97304267F, 0.97552824F,
    0.9778965F, 0.9801468F, 0.9822787F, 0.98429155F, 0.98618495F, 0.9879584F,
    0.9896114F, 0.99114364F, 0.99255466F, 0.99384415F, 0.9950118F, 0.99605733F,
    0.9969805F, 0.997781F, 0.9984587F, 0.99901336F, 0.99944496F, 0.9997533F,
    0.9999383F, 1.0F, 0.9999383F, 0.9997533F, 0.99944496F, 0.99901336F,
    0.9984587F, 0.997781F, 0.9969805F, 0.99605733F, 0.9950118F, 0.99384415F,
    0.99255466F, 0.99114364F, 0.9896114F, 0.9879584F, 0.98618495F, 0.98429155F,
    0.9822787F, 0.9801468F, 0.9778965F, 0.97552824F, 0.97304267F, 0.9704404F,
    0.967722F, 0.9648882F, 0.96193975F, 0.9588773F, 0.95570165F, 0.9524135F,
    0.94901377F, 0.94550323F, 0.9418828F, 0.9381533F, 0.93431574F, 0.930371F,
    0.9263201F, 0.92216396F, 0.91790366F, 0.9135403F, 0.90907484F, 0.9045085F,
    0.8998423F, 0.8950775F, 0.8902152F, 0.88525665F, 0.880203F, 0.87505555F,
    0.8698155F, 0.8644843F, 0.85906315F, 0.8535534F, 0.8479564F, 0.84227353F,
    0.83650625F, 0.83065593F, 0.824724F, 0.818712F, 0.81262136F, 0.8064535F,
    0.8002101F, 0.7938926F, 0.78750265F, 0.7810417F, 0.7745114F, 0.7679134F,
    0.7612493F, 0.7545207F, 0.74772936F, 0.74087685F, 0.7339649F, 0.7269952F,
    0.7199696F, 0.7128897F, 0.7057572F, 0.69857395F, 0.6913417F, 0.6840623F,
    0.6767374F, 0.669369F, 0.6619587F, 0.6545085F, 0.64702016F, 0.63949555F,
    0.63193655F, 0.62434494F, 0.6167227F, 0.6090716F, 0.60139364F, 0.59369063F,
    0.58596456F, 0.5782172F, 0.5704506F, 0.5626666F, 0.55486715F, 0.5470542F,
    0.5392296F, 0.53139526F, 0.52355325F, 0.5157054F, 0.5078537F, 0.5F,
    0.49214634F, 0.48429462F, 0.47644678F, 0.46860474F, 0.46077046F, 0.45294586F,
    0.44513285F, 0.43733338F, 0.4295494F, 0.42178276F, 0.41403544F, 0.40630934F,
    0.39860636F, 0.3909284F, 0.38327733F, 0.37565506F, 0.36806348F, 0.36050445F,
    0.35297984F, 0.3454915F, 0.3380413F, 0.33063105F, 0.32326257F, 0.31593773F,
    0.30865827F, 0.30142605F, 0.29424283F, 0.28711036F, 0.28003043F, 0.27300474F,
    0.26603508F, 0.25912318F, 0.25227067F, 0.24547929F, 0.23875071F, 0.2320866F,
    0.22548859F, 0.21895832F, 0.21249737F, 0.20610738F, 0.19978988F, 0.19354647F,
    0.18737867F, 0.181288F, 0.17527598F, 0.16934407F, 0.16349374F, 0.15772645F,
    0.1520436F, 0.14644662F, 0.14093685F, 0.13551569F, 0.13018446F, 0.12494446F,
    0.11979701F, 0.11474338F, 0.1097848F, 0.104922496F, 0.10015767F,
    0.095491506F, 0.09092514F, 0.08645971F, 0.082096316F, 0.07783604F,
    0.07367992F, 0.069628984F, 0.065684244F, 0.06184666F, 0.058117185F,
    0.05449674F, 0.05098621F, 0.047586475F, 0.044298362F, 0.041122686F,
    0.038060233F, 0.03511176F, 0.032277986F, 0.029559616F, 0.02695732F,
    0.024471741F, 0.022103492F, 0.019853158F, 0.017721292F, 0.015708419F,
    0.01381504F, 0.012041619F, 0.010388595F, 0.008856375F, 0.007445337F,
    0.00615583F, 0.004988171F, 0.0039426493F, 0.0030195222F, 0.0022190176F,
    0.0015413332F, 0.0009866358F, 0.0005550625F, 0.0002467198F, 6.168376E-5F };

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Buffer: '<S10>/Input Buffer' */
  uyIdx = 0;
  currentOffset = AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_outBufPtrIdx -
    240;
  if (AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_outBufPtrIdx - 240 < 0) {
    currentOffset = AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_outBufPtrIdx +
      2960;
  }

  nSamps = 400;
  if (currentOffset > 2800) {
    for (i = 0; i < 3200 - currentOffset; i++) {
      rtb_InputBuffer[i] =
        AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_CircBuf[currentOffset + i];
    }

    uyIdx = 3200 - currentOffset;
    nSamps = currentOffset - 2800;
    currentOffset = 0;
  }

  for (i = 0; i < nSamps; i++) {
    rtb_InputBuffer[uyIdx + i] =
      AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_CircBuf[currentOffset + i];
  }

  currentOffset += nSamps;
  if (currentOffset == 3200) {
    currentOffset = 0;
  }

  AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_outBufPtrIdx = currentOffset;

  /* End of Buffer: '<S10>/Input Buffer' */

  /* MATLABSystem: '<S10>/Auditory Spectrum Extractor' incorporates:
   *  Buffer: '<S10>/Input Buffer'
   */
  for (nSamps = 0; nSamps < 400; nSamps++) {
    xw[nSamps] = rtb_InputBuffer[nSamps] * tmp_1[nSamps];
  }

  /* Start for MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  AudioSmartSpeakerOnJetsonNano_FFTImplementationCallback_doHalfLengthRadix2(xw,
    0, tmp);

  /* MATLABSystem: '<S10>/Auditory Spectrum Extractor' */
  for (nSamps = 0; nSamps < 257; nSamps++) {
    x = rt_hypotf_snf(tmp[nSamps].re, tmp[nSamps].im);
    Z[nSamps] = x * x;
  }

  memset(&AuditorySpectrumExtractor[0], 0, 50U * sizeof(real32_T));
  for (nSamps = 0; nSamps < 257; nSamps++) {
    mw_arm_scalar_mult_vector_f32(&Z[nSamps], (real32_T *)&filterBank[50 *
      nSamps], &tmp_0[0], 50U);
    for (i = 0; i < 50; i++) {
      AuditorySpectrumExtractor[i] += tmp_0[i];
    }
  }

  /* Buffer: '<S10>/Output Buffer' incorporates:
   *  MATLABSystem: '<S10>/Auditory Spectrum Extractor'
   */
  uyIdx = 0;
  for (currentOffset = 0; currentOffset < 50; currentOffset++) {
    nSamps = 1;
    offsetFromMemBase = currentOffset * 196 +
      AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx;
    if (AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx > 195) {
      uyIdx = (uyIdx - AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx)
        + 196;
      offsetFromMemBase = currentOffset * 196;
      nSamps = AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx - 195;
    }

    for (i = 0; i < nSamps; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_CircBuf[offsetFromMemBase +
        i] = AuditorySpectrumExtractor[uyIdx + i];
    }

    uyIdx += nSamps;
  }

  AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx++;
  if (AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx >= 196) {
    AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx -= 196;
  }

  /* End of Buffer: '<S10>/Output Buffer' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.010000000000000002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AudioSmartSpeakerOnJetsonNano_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void AudioSmartSpeakerOnJetsonNano_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  sox_format_t * hsox;
  b_dsp_FIRRateConverter_AudioSmartSpeakerOnJetsonNano_T *obj;
  dlarray_1_AudioSmartSpeakerOnJetsonNano_T dlArrayOutputs;
  nvidiacoder_common_NvidiaAudioFileRead_AudioSmartSpeakerOnJetsonNano_T *obj_0;
  real_T v[10];
  real_T maxProb;
  real_T mtmp;
  real_T y;
  int32_T chanIdx;
  int32_T coefPolyphaseOffset;
  int32_T currentOffset;
  int32_T ftmp;
  int32_T i;
  int32_T memIdx;
  int32_T outputStopIdx;
  int32_T uyIdx;
  real32_T alphaA;
  real32_T alphaR;
  real32_T dlArrayOutputs_0;
  real32_T u0;
  int16_T rtb_ALSAAudioCapture1[1600];
  int16_T rtb_AudioFileRead[1600];
  int16_T rtb_AudioFileRead4[1600];
  int16_T rtb_AudioFileRead5[1600];
  int16_T rtb_AudioFileRead6_0[1600];
  char_T b[11];
  boolean_T eoa;
  boolean_T rtb_NOT;
  static const char_T b_0[11] = "plughw:2,0";
  boolean_T exitg1;

  /* Buffer: '<S10>/Output Buffer' */
  uyIdx = 0;
  for (chanIdx = 0; chanIdx < 50; chanIdx++) {
    currentOffset = AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_outBufPtrIdx -
      88;
    if (AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_outBufPtrIdx - 88 < 0) {
      currentOffset = AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_outBufPtrIdx
        + 108;
    }

    ftmp = 98;
    if (currentOffset > 98) {
      memIdx = chanIdx * 196 + currentOffset;
      for (i = 0; i < 196 - currentOffset; i++) {
        AudioSmartSpeakerOnJetsonNano_B.OutputBuffer[uyIdx + i] =
          AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_CircBuf[memIdx + i];
      }

      uyIdx = (uyIdx - currentOffset) + 196;
      ftmp = currentOffset - 98;
      currentOffset = 0;
    }

    memIdx = chanIdx * 196 + currentOffset;
    for (i = 0; i < ftmp; i++) {
      AudioSmartSpeakerOnJetsonNano_B.OutputBuffer[uyIdx + i] =
        AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_CircBuf[memIdx + i];
    }

    uyIdx += ftmp;
    currentOffset += ftmp;
  }

  if (currentOffset == 196) {
    currentOffset = 0;
  }

  AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_outBufPtrIdx = currentOffset;

  /* End of Buffer: '<S10>/Output Buffer' */

  /* Bias: '<S5>/Add Constant' incorporates:
   *  Buffer: '<S10>/Output Buffer'
   *  MATLAB Function: '<S10>/Multi-Channel Reshaper'
   */
  mw_arm_vector_plus_scalar_f32(&AudioSmartSpeakerOnJetsonNano_B.OutputBuffer[0],
    &AudioSmartSpeakerOnJetsonNano_P.AddConstant_Bias,
    &AudioSmartSpeakerOnJetsonNano_B.fv3[0], 4900U);

  /* Math: '<S5>/Log10' incorporates:
   *  Bias: '<S5>/Add Constant'
   *
   * About '<S5>/Log10':
   *  Operator: log10
   */
  for (i = 0; i < 4900; i++) {
    AudioSmartSpeakerOnJetsonNano_B.OutputBuffer[i] = (real32_T)log10
      (AudioSmartSpeakerOnJetsonNano_B.fv3[i]);
  }

  /* End of Math: '<S5>/Log10' */

  /* MATLAB Function: '<S12>/MLFB' */
  AudioSmartSpeakerOnJetsonNano_predict
    (AudioSmartSpeakerOnJetsonNano_B.OutputBuffer, dlArrayOutputs.Data);

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S12>/MLFB'
   */
  if (!rtIsNaNF(dlArrayOutputs.Data[0])) {
    chanIdx = 1;
  } else {
    chanIdx = 0;
    i = 2;
    exitg1 = false;
    while (!exitg1 && (i < 13)) {
      if (!rtIsNaNF(dlArrayOutputs.Data[i - 1])) {
        chanIdx = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (chanIdx == 0) {
    ftmp = 1;
  } else {
    alphaR = dlArrayOutputs.Data[chanIdx - 1];
    ftmp = chanIdx;
    for (i = chanIdx + 1; i < 13; i++) {
      dlArrayOutputs_0 = dlArrayOutputs.Data[i - 1];
      if (alphaR < dlArrayOutputs_0) {
        alphaR = dlArrayOutputs_0;
        ftmp = i;
      }
    }
  }

  for (i = 0; i < 9; i++) {
    AudioSmartSpeakerOnJetsonNano_DW.YBuffer[i] =
      AudioSmartSpeakerOnJetsonNano_DW.YBuffer[i + 1];
  }

  AudioSmartSpeakerOnJetsonNano_DW.YBuffer[9] = ftmp;
  for (i = 0; i < 48; i++) {
    AudioSmartSpeakerOnJetsonNano_DW.probBuffer[i] =
      AudioSmartSpeakerOnJetsonNano_DW.probBuffer[i + 12];
  }

  for (i = 0; i < 12; i++) {
    AudioSmartSpeakerOnJetsonNano_DW.probBuffer[i + 48] = dlArrayOutputs.Data[i];
  }

  memcpy(&v[0], &AudioSmartSpeakerOnJetsonNano_DW.YBuffer[0], 10U * sizeof
         (real_T));
  AudioSmartSpeakerOnJetsonNano_sort(v);
  y = v[0];
  i = 1;
  mtmp = v[0];
  ftmp = 1;
  for (chanIdx = 0; chanIdx < 9; chanIdx++) {
    maxProb = v[chanIdx + 1];
    if (maxProb == mtmp) {
      ftmp++;
    } else {
      if (ftmp > i) {
        y = mtmp;
        i = ftmp;
      }

      mtmp = maxProb;
      ftmp = 1;
    }
  }

  if (ftmp > i) {
    y = mtmp;
    i = ftmp;
  }

  if (!rtIsNaN(AudioSmartSpeakerOnJetsonNano_DW.probBuffer[(int32_T)y - 1])) {
    ftmp = 1;
  } else {
    ftmp = 0;
    chanIdx = 2;
    exitg1 = false;
    while (!exitg1 && (chanIdx < 6)) {
      if (!rtIsNaN(AudioSmartSpeakerOnJetsonNano_DW.probBuffer[((chanIdx - 1) *
            12 + (int32_T)y) - 1])) {
        ftmp = chanIdx;
        exitg1 = true;
      } else {
        chanIdx++;
      }
    }
  }

  if (ftmp == 0) {
    maxProb = AudioSmartSpeakerOnJetsonNano_DW.probBuffer[(int32_T)y - 1];
  } else {
    maxProb = AudioSmartSpeakerOnJetsonNano_DW.probBuffer[((ftmp - 1) * 12 +
      (int32_T)y) - 1];
    for (chanIdx = ftmp + 1; chanIdx < 6; chanIdx++) {
      mtmp = AudioSmartSpeakerOnJetsonNano_DW.probBuffer[((chanIdx - 1) * 12 +
        (int32_T)y) - 1];
      if (maxProb < mtmp) {
        maxProb = mtmp;
      }
    }
  }

  if ((i > 2) && (maxProb > 0.5) && (y != (real_T)Background)) {
    if (y < 0.0) {
      y = ceil(y);
    } else {
      y = floor(y);
    }

    if (rtIsNaN(y) || rtIsInf(y)) {
      y = 0.0;
    } else {
      y = fmod(y, 4.294967296E+9);
    }

    i = y < 0.0 ? -(int32_T)(uint32_T)-y : (int32_T)(uint32_T)y;

    /* Initialize output value to default value for SpeechCommands (Silence) */
    AudioSmartSpeakerOnJetsonNano_B.Command = Silence;
    if ((i >= 0) && (i <= 12)) {
      /* Set output value to input value if it is a member of SpeechCommands */
      AudioSmartSpeakerOnJetsonNano_B.Command = (SpeechCommands)i;
    }
  } else {
    AudioSmartSpeakerOnJetsonNano_B.Command = Silence;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Chart: '<Root>/Chart' */
  if (AudioSmartSpeakerOnJetsonNano_DW.is_active_c1_AudioSmartSpeakerOnJetsonNano
      == 0) {
    AudioSmartSpeakerOnJetsonNano_DW.is_active_c1_AudioSmartSpeakerOnJetsonNano =
      1U;
    AudioSmartSpeakerOnJetsonNano_DW.is_c1_AudioSmartSpeakerOnJetsonNano =
      AudioSmartSpeakerOnJetsonNano_IN_Off;
  } else if
      (AudioSmartSpeakerOnJetsonNano_DW.is_c1_AudioSmartSpeakerOnJetsonNano ==
       AudioSmartSpeakerOnJetsonNano_IN_Off) {
    if (AudioSmartSpeakerOnJetsonNano_B.Command == Go) {
      AudioSmartSpeakerOnJetsonNano_B.Playing = true;
      AudioSmartSpeakerOnJetsonNano_DW.is_c1_AudioSmartSpeakerOnJetsonNano =
        AudioSmartSpeakerOnJetsonNano_IN_Playing;
    }

    /* case IN_Playing: */
  } else if (AudioSmartSpeakerOnJetsonNano_B.Command == Stop) {
    AudioSmartSpeakerOnJetsonNano_B.Playing = false;
    AudioSmartSpeakerOnJetsonNano_DW.is_c1_AudioSmartSpeakerOnJetsonNano =
      AudioSmartSpeakerOnJetsonNano_IN_Off;
  }

  /* End of Chart: '<Root>/Chart' */

  /* Logic: '<Root>/NOT' */
  rtb_NOT = !AudioSmartSpeakerOnJetsonNano_B.Playing;

  /* Chart: '<Root>/Volume Setting' */
  if (AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1 < 63) {
    AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1++;
  }

  if (AudioSmartSpeakerOnJetsonNano_DW.is_active_c5_AudioSmartSpeakerOnJetsonNano
      == 0) {
    AudioSmartSpeakerOnJetsonNano_DW.is_active_c5_AudioSmartSpeakerOnJetsonNano =
      1U;
    AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano =
      AudioSmartSpeakerOnJetsonNano_IN_VolumeSteady;
  } else {
    switch (AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano)
    {
     case AudioSmartSpeakerOnJetsonNano_IN_DecrementVolume:
      if (AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1 >= 40) {
        AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano =
          AudioSmartSpeakerOnJetsonNano_IN_VolumeSteady;
      }
      break;

     case AudioSmartSpeakerOnJetsonNano_IN_IncrementVolume:
      if (AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1 >= 40) {
        AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano =
          AudioSmartSpeakerOnJetsonNano_IN_VolumeSteady;
      }
      break;

     default:
      /* case IN_VolumeSteady: */
      switch (AudioSmartSpeakerOnJetsonNano_B.Command) {
       case Down:
        AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1 = 0U;
        AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano =
          AudioSmartSpeakerOnJetsonNano_IN_DecrementVolume;
        AudioSmartSpeakerOnJetsonNano_B.Volume--;
        break;

       case Up:
        AudioSmartSpeakerOnJetsonNano_DW.temporalCounter_i1 = 0U;
        AudioSmartSpeakerOnJetsonNano_DW.is_c5_AudioSmartSpeakerOnJetsonNano =
          AudioSmartSpeakerOnJetsonNano_IN_IncrementVolume;
        AudioSmartSpeakerOnJetsonNano_B.Volume++;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Volume Setting' */

  /* DiscreteFilter: '<S2>/Discrete Filter' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  AudioSmartSpeakerOnJetsonNano_DW.DiscreteFilter_states = ((real_T)
    AudioSmartSpeakerOnJetsonNano_B.Playing -
    AudioSmartSpeakerOnJetsonNano_P.DiscreteFilter_DenCoef[1] *
    AudioSmartSpeakerOnJetsonNano_DW.DiscreteFilter_states) /
    AudioSmartSpeakerOnJetsonNano_P.DiscreteFilter_DenCoef[0];

  /* Outputs for Enabled SubSystem: '<Root>/Speaker Output Processing ' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (AudioSmartSpeakerOnJetsonNano_P.DiscreteFilter_NumCoef *
      AudioSmartSpeakerOnJetsonNano_DW.DiscreteFilter_states > 0.0) {
    /* MATLABSystem: '<S4>/Audio File Read1' incorporates:
     *  MATLABSystem: '<S6>/Audio File Read'
     *  MATLABSystem: '<S6>/Audio File Read4'
     *  MATLABSystem: '<S6>/Audio File Read5'
     *  MATLABSystem: '<S6>/Audio File Read6'
     */
    obj_0 = &AudioSmartSpeakerOnJetsonNano_DW.obj_l;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxInitialized) {
      hsox = AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle;
      eoa = MW_sox_read(&hsox, &AudioSmartSpeakerOnJetsonNano_B.buf[0], 8820.0);
      if (eoa) {
        obj_0->SoxFileHandle = hsox;
        obj_0->LoopCount--;
      }

      for (i = 0; i < 8820; i++) {
        AudioSmartSpeakerOnJetsonNano_B.iv[i] = (int16_T)
          (AudioSmartSpeakerOnJetsonNano_B.buf[i] >> 16);
      }

      mw_arm_mat_trans_q15(&AudioSmartSpeakerOnJetsonNano_B.iv[0],
                           &AudioSmartSpeakerOnJetsonNano_B.Cast1[0], 4410U, 2U);
    } else {
      memset(&AudioSmartSpeakerOnJetsonNano_B.Cast1[0], 0, 8820U * sizeof
             (int16_T));
    }

    /* MATLABSystem: '<S4>/Graphic EQ' */
    y = AudioSmartSpeakerOnJetsonNano_DW.obj_e.pSampleRateDialog;
    if (y != AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_SampleRate) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.pSampleRateDialog =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_SampleRate;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_31_5) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_31_5;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_63) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_63;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_125) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_125;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_250) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_250;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_500) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_500;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_1000) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_1000;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_2000) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_2000;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_4000) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_4000;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_8000) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_8000;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz !=
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_16000) {
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz =
        AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_16000;
      eoa = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
      if (eoa) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
      }

      v[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
      v[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
      v[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
      v[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
      v[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
      v[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
      v[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
      v[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
      v[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
      v[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
             (real_T));
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &v[0], 10U *
             sizeof(real_T));
    }

    for (i = 0; i < 8820; i++) {
      /* Gain: '<S4>/Multiply' incorporates:
       *  DataTypeConversion: '<S4>/Cast To Single'
       *  MATLABSystem: '<S4>/Audio File Read1'
       */
      AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[i] =
        AudioSmartSpeakerOnJetsonNano_B.Cast1[i];
    }

    /* Gain: '<S4>/Multiply' incorporates:
     *  DataTypeConversion: '<S4>/Cast To Single'
     */
    mw_arm_scalar_mult_vector_f32(&AudioSmartSpeakerOnJetsonNano_P.Multiply_Gain,
      &AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[0],
      &AudioSmartSpeakerOnJetsonNano_B.fv[0], 8820U);

    /* MATLABSystem: '<S4>/Graphic EQ' incorporates:
     *  Gain: '<S4>/Multiply'
     */
    AudioSmartSpeakerOnJetsonNano_SystemCore_step
      (&AudioSmartSpeakerOnJetsonNano_DW.obj_e,
       AudioSmartSpeakerOnJetsonNano_B.fv,
       AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate);

    /* MATLABSystem: '<S4>/Multiband Parametric EQ' incorporates:
     *  MATLABSystem: '<S4>/Graphic EQ'
     */
    eoa = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[i] ==
            AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[i]))
      {
        eoa = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!eoa) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_p.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[0] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[0];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[1] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[1];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[2] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[2];
    }

    eoa = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[i] ==
            AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[
            i])) {
        eoa = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!eoa) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_p.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[0] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[0];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[1] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[1];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[2] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[2];
    }

    eoa = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[i] ==
            AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[i]))
      {
        eoa = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!eoa) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_p.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[0] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[0];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[1] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[1];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[2] =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[2];
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.pSampleRateDialog !=
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_SampleRate) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_p.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pSampleRateDialog =
        AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_SampleRate;
    }

    AudioSmartSpeakerOnJetsonNano_SystemCore_step_d
      (&AudioSmartSpeakerOnJetsonNano_DW.obj_p,
       AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate,
       AudioSmartSpeakerOnJetsonNano_B.fv);

    /* MATLABSystem: '<S4>/Limiter' incorporates:
     *  MATLABSystem: '<S4>/Multiband Parametric EQ'
     */
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold !=
        AudioSmartSpeakerOnJetsonNano_P.Limiter_Threshold) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold =
        AudioSmartSpeakerOnJetsonNano_P.Limiter_Threshold;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth !=
        AudioSmartSpeakerOnJetsonNano_P.Limiter_KneeWidth) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth =
        AudioSmartSpeakerOnJetsonNano_P.Limiter_KneeWidth;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime !=
        AudioSmartSpeakerOnJetsonNano_P.Limiter_AttackTime) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime =
        AudioSmartSpeakerOnJetsonNano_P.Limiter_AttackTime;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime !=
        AudioSmartSpeakerOnJetsonNano_P.Limiter_ReleaseTime) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime =
        AudioSmartSpeakerOnJetsonNano_P.Limiter_ReleaseTime;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.MakeUpGain !=
        AudioSmartSpeakerOnJetsonNano_P.Limiter_MakeUpGain) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = true;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.MakeUpGain =
        AudioSmartSpeakerOnJetsonNano_P.Limiter_MakeUpGain;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = false;
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime != 0.0) {
        alphaR = -2.1972246F / ((real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime * (real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.pSampleRateInherit);
        mw_arm_vexp_f32(&alphaR, &AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaA,
                        1U);
      } else {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaA = 0.0F;
      }

      if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime != 0.0) {
        alphaR = -2.1972246F / ((real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime * (real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.pSampleRateInherit);
        mw_arm_vexp_f32(&alphaR, &AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaR,
                        1U);
      } else {
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaR = 0.0F;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pMakeUpGain = (real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.MakeUpGain;
    }

    mw_arm_abs_f32(&AudioSmartSpeakerOnJetsonNano_B.fv[0],
                   &AudioSmartSpeakerOnJetsonNano_B.yG[0], 8820U);
    for (i = 0; i < 8820; i++) {
      u0 = AudioSmartSpeakerOnJetsonNano_B.yG[i];
      if (!(u0 >= 1.1920929E-7F)) {
        u0 = 1.1920929E-7F;
      }

      AudioSmartSpeakerOnJetsonNano_B.xDB[i] = (real32_T)log10(u0);
    }

    alphaR = 20.0F;
    mw_arm_scalar_mult_vector_f32(&alphaR, &AudioSmartSpeakerOnJetsonNano_B.xDB
      [0], &AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[0], 8820U);
    for (i = 0; i < 8820; i++) {
      alphaA = AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[i];
      AudioSmartSpeakerOnJetsonNano_B.yG[i] = alphaA;
      AudioSmartSpeakerOnJetsonNano_B.b[i] = alphaA - (real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold;
    }

    /* Start for MATLABSystem: '<S4>/Limiter' */
    alphaR = 2.0F;
    mw_arm_scalar_mult_vector_f32(&alphaR, &AudioSmartSpeakerOnJetsonNano_B.b[0],
      &AudioSmartSpeakerOnJetsonNano_B.xDB[0], 8820U);

    /* MATLABSystem: '<S4>/Limiter' */
    for (i = 0; i < 8820; i++) {
      if (AudioSmartSpeakerOnJetsonNano_B.xDB[i] > (real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth) {
        AudioSmartSpeakerOnJetsonNano_B.yG[i] = (real32_T)
          AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold;
      }
    }

    if ((real32_T)AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth != 0.0F) {
      alphaR = 2.0F;
      mw_arm_abs_f32(&AudioSmartSpeakerOnJetsonNano_B.b[0],
                     &AudioSmartSpeakerOnJetsonNano_B.xDB[0], 8820U);
      mw_arm_scalar_mult_vector_f32(&alphaR,
        &AudioSmartSpeakerOnJetsonNano_B.xDB[0],
        &AudioSmartSpeakerOnJetsonNano_B.fv1[0], 8820U);
      alphaR = (real32_T)AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth / 2.0F;
      u0 = 2.0F * (real32_T)AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth;
      for (i = 0; i < 8820; i++) {
        if (AudioSmartSpeakerOnJetsonNano_B.fv1[i] <= (real32_T)
            AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth) {
          alphaA = AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[i];
          dlArrayOutputs_0 = (alphaA - (real32_T)
                              AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold)
            + alphaR;
          AudioSmartSpeakerOnJetsonNano_B.yG[i] = alphaA - dlArrayOutputs_0 *
            dlArrayOutputs_0 / u0;
        }
      }
    }

    for (i = 0; i < 8820; i++) {
      AudioSmartSpeakerOnJetsonNano_B.yG[i] -=
        AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[i];
    }

    memset(&AudioSmartSpeakerOnJetsonNano_B.y[0], 0, 8822U * sizeof(real32_T));
    AudioSmartSpeakerOnJetsonNano_B.y[0] =
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pLevelDetectionState[0];
    AudioSmartSpeakerOnJetsonNano_B.y[4411] =
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pLevelDetectionState[1];
    alphaA = AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaA;
    alphaR = AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaR;
    for (chanIdx = 0; chanIdx < 4410; chanIdx++) {
      dlArrayOutputs_0 = AudioSmartSpeakerOnJetsonNano_B.yG[chanIdx];
      u0 = AudioSmartSpeakerOnJetsonNano_B.y[chanIdx];
      if (dlArrayOutputs_0 <= u0) {
        AudioSmartSpeakerOnJetsonNano_B.y[chanIdx + 1] = (1.0F - alphaA) *
          dlArrayOutputs_0 + alphaA * u0;
      } else {
        AudioSmartSpeakerOnJetsonNano_B.y[chanIdx + 1] = (1.0F - alphaR) *
          dlArrayOutputs_0 + alphaR * u0;
      }

      dlArrayOutputs_0 = AudioSmartSpeakerOnJetsonNano_B.yG[chanIdx + 4410];
      u0 = AudioSmartSpeakerOnJetsonNano_B.y[chanIdx + 4411];
      if (dlArrayOutputs_0 <= u0) {
        AudioSmartSpeakerOnJetsonNano_B.y[chanIdx + 4412] = (1.0F - alphaA) *
          dlArrayOutputs_0 + u0 * alphaA;
      } else {
        AudioSmartSpeakerOnJetsonNano_B.y[chanIdx + 4412] = (1.0F - alphaR) *
          dlArrayOutputs_0 + u0 * alphaR;
      }
    }

    for (chanIdx = 0; chanIdx < 2; chanIdx++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pLevelDetectionState[chanIdx] =
        AudioSmartSpeakerOnJetsonNano_B.y[4411 * chanIdx + 4410];
      memcpy(&AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[chanIdx * 4410],
             &AudioSmartSpeakerOnJetsonNano_B.y[chanIdx * 4411 + 1], 4410U *
             sizeof(real32_T));
    }

    mw_arm_vector_plus_scalar_f32
      (&AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[0],
       &AudioSmartSpeakerOnJetsonNano_DW.obj_m.pMakeUpGain,
       &AudioSmartSpeakerOnJetsonNano_B.xDB[0], 8820U);

    /* MATLAB Function: '<S4>/db2mag' incorporates:
     *  Lookup_n-D: '<S4>/Volume2dB'
     */
    y = 1.0 / rt_powd_snf(10.0, fabs(look1_binlxpw
      (AudioSmartSpeakerOnJetsonNano_B.Volume,
       AudioSmartSpeakerOnJetsonNano_P.Volume2dB_bp01Data,
       AudioSmartSpeakerOnJetsonNano_P.Volume2dB_tableData, 11U)) / 20.0);
    for (i = 0; i < 8820; i++) {
      /* Product: '<S4>/Product' incorporates:
       *  MATLABSystem: '<S4>/Limiter'
       *  MATLABSystem: '<S4>/Multiband Parametric EQ'
       * */
      AudioSmartSpeakerOnJetsonNano_B.Product[i] = rt_powf_snf(10.0F,
        AudioSmartSpeakerOnJetsonNano_B.xDB[i] / 20.0F) *
        AudioSmartSpeakerOnJetsonNano_B.fv[i] * y;
    }
  }

  /* End of DiscreteFilter: '<S2>/Discrete Filter' */
  /* End of Outputs for SubSystem: '<Root>/Speaker Output Processing ' */

  /* MATLABSystem: '<S3>/MATLAB System' incorporates:
   *  Product: '<S4>/Product'
   */
  if (AudioSmartSpeakerOnJetsonNano_DW.obj_i.Tau !=
      AudioSmartSpeakerOnJetsonNano_P.SmoothedMute_tau) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.Tau =
      AudioSmartSpeakerOnJetsonNano_P.SmoothedMute_tau;
  }

  if (AudioSmartSpeakerOnJetsonNano_DW.obj_i.SampleRate !=
      AudioSmartSpeakerOnJetsonNano_P.MATLABSystem_SampleRate) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.SampleRate =
      AudioSmartSpeakerOnJetsonNano_P.MATLABSystem_SampleRate;
  }

  /*  Implement algorithm. Calculate y as a function of */
  /*  input u and discrete states. */
  /*  Add some 1st order smoothing */
  /*  Tau = Time constant */
  /*  Ts = Time step */
  /*  a = Ts / (Tau + Ts) */
  if (rtb_NOT && (AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState == 0.0)) {
    /*  Not muted state, mute turned on */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 2.0;

    /*  Change to process of muting */
  } else if (rtb_NOT && (AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState == 3.0))
  {
    /*  Process of unmuting state, mute turned on */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 2.0;

    /*  Change to process of muting */
  } else if (!rtb_NOT && (AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState ==
                          1.0)) {
    /*  Muted state, mute turned off */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 3.0;

    /*  Change to process of unmuting */
  } else if (!rtb_NOT && (AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState ==
                          2.0)) {
    /*  Process of muting state, mute turned off */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 3.0;

    /*  Change to process of unmuting */
  }

  memset(&AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[0], 0, 8820U * sizeof
         (real_T));
  y = AudioSmartSpeakerOnJetsonNano_DW.obj_i.currentGain;
  switch ((int32_T)AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState) {
   case 0:
    /*  not muted */
    memcpy(&AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[0],
           &AudioSmartSpeakerOnJetsonNano_B.Product[0], 8820U * sizeof(real_T));

    /*  muted */
    break;

   case 1:
    /*  do nothing, we've already initialized y to zeros */
    /*  muting */
    break;

   case 2:
    mtmp = AudioSmartSpeakerOnJetsonNano_DW.obj_i.Ts /
      (AudioSmartSpeakerOnJetsonNano_DW.obj_i.Tau +
       AudioSmartSpeakerOnJetsonNano_DW.obj_i.Ts);
    for (chanIdx = 0; chanIdx < 4410; chanIdx++) {
      y *= 1.0 - mtmp;
      AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[chanIdx] =
        AudioSmartSpeakerOnJetsonNano_B.Product[chanIdx] * y;
      AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[chanIdx + 4410] =
        AudioSmartSpeakerOnJetsonNano_B.Product[chanIdx + 4410] * y;
    }

    /*  check to see if we're fully muted yet (-120db) */
    if (y < 1.0E-6) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 1.0;
    }

    /*  un-muting */
    break;

   case 3:
    mtmp = AudioSmartSpeakerOnJetsonNano_DW.obj_i.Ts /
      (AudioSmartSpeakerOnJetsonNano_DW.obj_i.Tau +
       AudioSmartSpeakerOnJetsonNano_DW.obj_i.Ts);
    for (i = 0; i < 4410; i++) {
      y = (1.0 - mtmp) * y + mtmp;
      AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[i] =
        AudioSmartSpeakerOnJetsonNano_B.Product[i] * y;
      AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[i + 4410] =
        AudioSmartSpeakerOnJetsonNano_B.Product[i + 4410] * y;
    }

    /*  check to see if we're fully un-muted yet */
    if (y > 0.999999) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 0.0;
    }
    break;
  }

  AudioSmartSpeakerOnJetsonNano_DW.obj_i.currentGain = y;

  /* End of MATLABSystem: '<S3>/MATLAB System' */

  /* MATLABSystem: '<Root>/ALSA Audio Capture1' */
  for (i = 0; i < 11; i++) {
    b[i] = b_0[i];
  }

  MW_AudioRead(&b[0], MW_AUDIO_16, &rtb_ALSAAudioCapture1[0]);

  /* End of MATLABSystem: '<Root>/ALSA Audio Capture1' */

  /* MATLABSystem: '<S6>/Audio File Read4' */
  obj_0 = &AudioSmartSpeakerOnJetsonNano_DW.obj_ph;
  if (AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxInitialized) {
    hsox = AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle;
    eoa = MW_sox_read(&hsox, &AudioSmartSpeakerOnJetsonNano_B.buf_c[0], 1600.0);
    if (eoa) {
      obj_0->SoxFileHandle = hsox;
      obj_0->LoopCount--;
    }

    /* MATLABSystem: '<S6>/Audio File Read4' incorporates:
     *  MATLABSystem: '<S4>/Audio File Read1'
     *  MATLABSystem: '<S6>/Audio File Read'
     *  MATLABSystem: '<S6>/Audio File Read5'
     *  MATLABSystem: '<S6>/Audio File Read6'
     */
    for (i = 0; i < 1600; i++) {
      rtb_AudioFileRead4[i] = (int16_T)(AudioSmartSpeakerOnJetsonNano_B.buf_c[i]
        >> 16);
    }
  } else {
    /* MATLABSystem: '<S6>/Audio File Read4' */
    memset(&rtb_AudioFileRead4[0], 0, 1600U * sizeof(int16_T));
  }

  /* End of MATLABSystem: '<S6>/Audio File Read4' */

  /* MATLABSystem: '<S6>/Audio File Read' */
  obj_0 = &AudioSmartSpeakerOnJetsonNano_DW.obj_k;
  if (AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxInitialized) {
    hsox = AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle;
    eoa = MW_sox_read(&hsox, &AudioSmartSpeakerOnJetsonNano_B.buf_c[0], 1600.0);
    if (eoa) {
      obj_0->SoxFileHandle = hsox;
      obj_0->LoopCount--;
    }

    /* MATLABSystem: '<S6>/Audio File Read' incorporates:
     *  MATLABSystem: '<S4>/Audio File Read1'
     *  MATLABSystem: '<S6>/Audio File Read4'
     *  MATLABSystem: '<S6>/Audio File Read5'
     *  MATLABSystem: '<S6>/Audio File Read6'
     */
    for (i = 0; i < 1600; i++) {
      rtb_AudioFileRead[i] = (int16_T)(AudioSmartSpeakerOnJetsonNano_B.buf_c[i] >>
        16);
    }
  } else {
    /* MATLABSystem: '<S6>/Audio File Read' */
    memset(&rtb_AudioFileRead[0], 0, 1600U * sizeof(int16_T));
  }

  /* End of MATLABSystem: '<S6>/Audio File Read' */

  /* MATLABSystem: '<S6>/Audio File Read5' */
  obj_0 = &AudioSmartSpeakerOnJetsonNano_DW.obj_a;
  if (AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxInitialized) {
    hsox = AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle;
    eoa = MW_sox_read(&hsox, &AudioSmartSpeakerOnJetsonNano_B.buf_c[0], 1600.0);
    if (eoa) {
      obj_0->SoxFileHandle = hsox;
      obj_0->LoopCount--;
    }

    /* MATLABSystem: '<S6>/Audio File Read5' incorporates:
     *  MATLABSystem: '<S4>/Audio File Read1'
     *  MATLABSystem: '<S6>/Audio File Read'
     *  MATLABSystem: '<S6>/Audio File Read4'
     *  MATLABSystem: '<S6>/Audio File Read6'
     */
    for (i = 0; i < 1600; i++) {
      rtb_AudioFileRead5[i] = (int16_T)(AudioSmartSpeakerOnJetsonNano_B.buf_c[i]
        >> 16);
    }
  } else {
    /* MATLABSystem: '<S6>/Audio File Read5' */
    memset(&rtb_AudioFileRead5[0], 0, 1600U * sizeof(int16_T));
  }

  /* End of MATLABSystem: '<S6>/Audio File Read5' */

  /* MATLABSystem: '<S6>/Audio File Read6' incorporates:
   *  MATLABSystem: '<S4>/Audio File Read1'
   *  MATLABSystem: '<S6>/Audio File Read'
   *  MATLABSystem: '<S6>/Audio File Read4'
   *  MATLABSystem: '<S6>/Audio File Read5'
   */
  obj_0 = &AudioSmartSpeakerOnJetsonNano_DW.obj_po;
  if (AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxInitialized) {
    hsox = AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle;
    eoa = MW_sox_read(&hsox, &AudioSmartSpeakerOnJetsonNano_B.buf_c[0], 1600.0);
    if (eoa) {
      obj_0->SoxFileHandle = hsox;
      obj_0->LoopCount--;
    }

    for (i = 0; i < 1600; i++) {
      rtb_AudioFileRead6_0[i] = (int16_T)
        (AudioSmartSpeakerOnJetsonNano_B.buf_c[i] >> 16);
    }
  } else {
    memset(&rtb_AudioFileRead6_0[0], 0, 1600U * sizeof(int16_T));
  }

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (AudioSmartSpeakerOnJetsonNano_P.ManualSwitch_CurrentSetting != 1) {
    /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Word'
     */
    switch ((int32_T)AudioSmartSpeakerOnJetsonNano_P.Word_Value) {
     case 1:
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  MATLABSystem: '<S6>/Audio File Read4'
       */
      memcpy(&rtb_ALSAAudioCapture1[0], &rtb_AudioFileRead4[0], 1600U * sizeof
             (int16_T));
      break;

     case 2:
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  MATLABSystem: '<S6>/Audio File Read'
       */
      memcpy(&rtb_ALSAAudioCapture1[0], &rtb_AudioFileRead[0], 1600U * sizeof
             (int16_T));
      break;

     case 3:
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  MATLABSystem: '<S6>/Audio File Read5'
       */
      memcpy(&rtb_ALSAAudioCapture1[0], &rtb_AudioFileRead5[0], 1600U * sizeof
             (int16_T));
      break;

     case 4:
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  MATLABSystem: '<S6>/Audio File Read6'
       */
      memcpy(&rtb_ALSAAudioCapture1[0], &rtb_AudioFileRead6_0[0], 1600U * sizeof
             (int16_T));
      break;

     default:
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<S6>/Constant'
       */
      memcpy(&rtb_ALSAAudioCapture1[0],
             &AudioSmartSpeakerOnJetsonNano_P.Constant_Value[0], 1600U * sizeof
             (int16_T));
      break;
    }

    /* End of MultiPortSwitch: '<S6>/Multiport Switch' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  for (i = 0; i < 1600; i++) {
    /* Gain: '<Root>/Multiply' incorporates:
     *  DataTypeConversion: '<Root>/Cast To Single'
     *  ManualSwitch: '<Root>/Manual Switch'
     */
    AudioSmartSpeakerOnJetsonNano_B.Gain[i] = rtb_ALSAAudioCapture1[i];
  }

  /* Gain: '<Root>/Multiply' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Single'
   */
  mw_arm_scalar_mult_vector_f32(&AudioSmartSpeakerOnJetsonNano_P.Multiply_Gain_o,
    &AudioSmartSpeakerOnJetsonNano_B.Gain[0],
    &AudioSmartSpeakerOnJetsonNano_B.fv5[0], 1600U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Gain: '<Root>/Multiply'
   */
  mw_arm_scalar_mult_vector_f32(&AudioSmartSpeakerOnJetsonNano_P.Gain_Gain,
    &AudioSmartSpeakerOnJetsonNano_B.fv5[0],
    &AudioSmartSpeakerOnJetsonNano_B.Gain[0], 1600U);

  /* MATLABSystem: '<Root>/Sample-Rate Converter' incorporates:
   *  Gain: '<S8>/Gain'
   */
  obj = AudioSmartSpeakerOnJetsonNano_DW.obj.filt1;
  if (AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isInitialized != 1) {
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isSetupComplete = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRRateConverter */
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W1_InBufIdx = 0;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W0_InBuf[0],
           0, 21U * sizeof(real32_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W2_ModuloIdx = 0;
  }

  /* System object Outputs function: dsp.FIRRateConverter */
  /* Determine the input and output frame sizes */
  uyIdx = 0;

  /* Update inBufIdx and inputChannelOffset for current channel */
  currentOffset =
    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W1_InBufIdx;
  memIdx = AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W2_ModuloIdx;
  for (ftmp = 0; ftmp < 1600; ftmp++) {
    i = obj->cSFunObject.P2_StartIdx[memIdx];
    outputStopIdx = obj->cSFunObject.P3_StopIdx[memIdx];
    memIdx = (memIdx + 1) % 160;

    /* Read input into inBufArray */
    obj->cSFunObject.W0_InBuf[currentOffset] =
      AudioSmartSpeakerOnJetsonNano_B.Gain[ftmp];

    /* Generate outputs (if any) for current input n */
    while (i < outputStopIdx) {
      u0 = 0.0F;
      coefPolyphaseOffset = obj->cSFunObject.P1_PolyphaseSelector[i] * 21;
      for (chanIdx = currentOffset; chanIdx < 21; chanIdx++) {
        alphaA = obj->cSFunObject.P0_FILTER[(coefPolyphaseOffset + chanIdx) -
          currentOffset] * obj->cSFunObject.W0_InBuf[chanIdx];
        u0 += alphaA;
      }

      for (chanIdx = 0; chanIdx < currentOffset; chanIdx++) {
        alphaA = obj->cSFunObject.P0_FILTER[((coefPolyphaseOffset -
          currentOffset) + chanIdx) + 21] * obj->cSFunObject.W0_InBuf[chanIdx];
        u0 += alphaA;
      }

      AudioSmartSpeakerOnJetsonNano_B.rtb_SampleRateConverter_m[uyIdx] = u0;
      uyIdx++;
      i++;
    }

    /* Decrement inBufIdx, wrap if necessary */
    if (currentOffset == 0) {
      currentOffset = 20;
    } else {
      currentOffset--;
    }
  }

  /* Update inBufIdx */
  obj->cSFunObject.W1_InBufIdx = currentOffset;
  obj->cSFunObject.W2_ModuloIdx = memIdx;

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Concatenate: '<Root>/Matrix Concatenate'
   *  Gain: '<Root>/Multiply2'
   */
  if (AudioSmartSpeakerOnJetsonNano_P.ManualSwitch1_CurrentSetting == 1) {
    /* SignalConversion generated from: '<Root>/Matrix Concatenate' incorporates:
     *  MATLABSystem: '<Root>/Sample-Rate Converter'
     */
    memcpy(&AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[4410],
           &AudioSmartSpeakerOnJetsonNano_B.rtb_SampleRateConverter_m[0], 4410U *
           sizeof(real32_T));

    /* SignalConversion generated from: '<Root>/Matrix Concatenate' incorporates:
     *  MATLABSystem: '<Root>/Sample-Rate Converter'
     */
    memcpy(&AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[0],
           &AudioSmartSpeakerOnJetsonNano_B.rtb_SampleRateConverter_m[0], 4410U *
           sizeof(real32_T));
    for (i = 0; i < 8820; i++) {
      AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[i] =
        AudioSmartSpeakerOnJetsonNano_B.MatrixConcatenate[i];
    }
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Gain: '<Root>/Multiply2' */
  mw_arm_scalar_mult_vector_f64(&AudioSmartSpeakerOnJetsonNano_P.Multiply2_Gain,
    &AudioSmartSpeakerOnJetsonNano_B.MATLABSystem_o1[0],
    &AudioSmartSpeakerOnJetsonNano_B.dv[0], 8820U);

  /* DataTypeConversion: '<Root>/Cast1' incorporates:
   *  Gain: '<Root>/Multiply2'
   */
  for (i = 0; i < 8820; i++) {
    y = floor(AudioSmartSpeakerOnJetsonNano_B.dv[i]);
    if (rtIsNaN(y) || rtIsInf(y)) {
      y = 0.0;
    } else {
      y = fmod(y, 65536.0);
    }

    AudioSmartSpeakerOnJetsonNano_B.Cast1[i] = (int16_T)(y < 0.0 ? (int32_T)
      (int16_T)-(int16_T)(uint16_T)-y : (int32_T)(int16_T)(uint16_T)y);
  }

  /* End of DataTypeConversion: '<Root>/Cast1' */

  /* MATLABSystem: '<Root>/ALSA Audio Playback1' incorporates:
   *  DataTypeConversion: '<Root>/Cast1'
   */
  for (i = 0; i < 11; i++) {
    b[i] = b_0[i];
  }

  MW_AudioWrite(&b[0], MW_AUDIO_16, &AudioSmartSpeakerOnJetsonNano_B.Cast1[0]);

  /* End of MATLABSystem: '<Root>/ALSA Audio Playback1' */

  /* Buffer: '<S10>/Input Buffer' incorporates:
   *  Gain: '<S8>/Gain'
   */
  chanIdx = 0;
  ftmp = 3200;
  uyIdx = AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx;
  if (AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx > 1600) {
    for (i = 0; i < 3200 -
         AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_CircBuf[AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx
        + i] = AudioSmartSpeakerOnJetsonNano_B.Gain[i];
    }

    chanIdx = 3200 - AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx;
    uyIdx = 0;
    ftmp = AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx;
  }

  for (i = 0; i < ftmp - 1600; i++) {
    AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_CircBuf[uyIdx + i] =
      AudioSmartSpeakerOnJetsonNano_B.Gain[chanIdx + i];
  }

  AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx += 1600;
  if (AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx >= 3200) {
    AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx -= 3200;
  }

  /* End of Buffer: '<S10>/Input Buffer' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  AudioSmartSpeakerOnJetsonNano_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void AudioSmartSpeakerOnJetsonNano_step(int_T tid)
{
  switch (tid) {
   case 0 :
    AudioSmartSpeakerOnJetsonNano_step0();
    break;

   case 1 :
    AudioSmartSpeakerOnJetsonNano_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void AudioSmartSpeakerOnJetsonNano_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(AudioSmartSpeakerOnJetsonNano_M, -1);

  /* External mode info */
  AudioSmartSpeakerOnJetsonNano_M->Sizes.checksums[0] = (3683147675U);
  AudioSmartSpeakerOnJetsonNano_M->Sizes.checksums[1] = (599013156U);
  AudioSmartSpeakerOnJetsonNano_M->Sizes.checksums[2] = (1794629669U);
  AudioSmartSpeakerOnJetsonNano_M->Sizes.checksums[3] = (3877866037U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    AudioSmartSpeakerOnJetsonNano_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AudioSmartSpeakerOnJetsonNano_M->extModeInfo,
      &AudioSmartSpeakerOnJetsonNano_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AudioSmartSpeakerOnJetsonNano_M->extModeInfo,
                        AudioSmartSpeakerOnJetsonNano_M->Sizes.checksums);
    rteiSetTFinalTicks(AudioSmartSpeakerOnJetsonNano_M->extModeInfo, -1);
  }

  {
    sox_format_t * nulHandle;
    b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj;
    real_T val[10];
    real_T Fs;
    int32_T i;
    real32_T tmp[50];
    real32_T minval[10];
    real32_T Nyquist;
    real32_T u1;
    char_T b_1[163];
    char_T b_0[161];
    char_T b_2[123];
    char_T b[11];
    boolean_T flag;
    static const char_T b_3[123] =
      "/home/demonvidia/MATLAB_ws/R2026a/C/Program_Files/MATLAB/R2026a/toolbox/audio/samples/RockGuitar-16-44p1-stereo-72secs.wav";
    static const int16_T tmp_0[10] = { 100, 181, 325, 585, 1053, 1896, 3415,
      6151, 11078, 19953 };

    static const char_T b_4[11] = "plughw:2,0";
    static const char_T b_5[161] =
      "/home/demonvidia/MATLAB_ws/R2026a/C/Users/KoayXianCong/Documents/MATLAB/Examples/R2026a/deeplearning_shared/AudioSmartSpeakerOnR"
      "aspberryPiSimulinkExample/go.wav";
    static const char_T b_6[163] =
      "/home/demonvidia/MATLAB_ws/R2026a/C/Users/KoayXianCong/Documents/MATLAB/Examples/R2026a/deeplearning_shared/AudioSmartSpeakerOnR"
      "aspberryPiSimulinkExample/stop.wav";
    static const char_T b_7[161] =
      "/home/demonvidia/MATLAB_ws/R2026a/C/Users/KoayXianCong/Documents/MATLAB/Examples/R2026a/deeplearning_shared/AudioSmartSpeakerOnR"
      "aspberryPiSimulinkExample/up.wav";
    static const char_T b_8[163] =
      "/home/demonvidia/MATLAB_ws/R2026a/C/Users/KoayXianCong/Documents/MATLAB/Examples/R2026a/deeplearning_shared/AudioSmartSpeakerOnR"
      "aspberryPiSimulinkExample/down.wav";
    static const real32_T tmp_1[9261] = { 1.0237989E-5F, -7.8361496E-5F,
      0.00026817233F, -0.0006838811F, 0.0014738301F, -0.0028475292F,
      0.0051323553F, -0.0089750625F, 0.016190866F, -0.035597738F, 0.99750346F,
      0.038669784F, -0.017020911F, 0.009372114F, -0.005361065F, 0.0029858316F,
      -0.0015557514F, 0.0007292389F, -0.00029058507F, 8.75769E-5F,
      -1.2901453E-5F, 9.7079555E-6F, -7.401811E-5F, 0.00025307058F,
      -0.0006450587F, 0.0013897436F, -0.0026845338F, 0.004838014F, -0.008460223F,
      0.015264931F, -0.03359223F, 0.9977883F, 0.036313802F, -0.016000371F,
      0.008812029F, -0.005040663F, 0.0028070775F, -0.0014623305F, 0.0006852481F,
      -0.00027292938F, 8.218335E-5F, -1.2067846E-5F, 9.1690135E-6F,
      -6.964096E-5F, 0.00023788202F, -0.0006060527F, 0.0013053128F,
      -0.0025209389F, 0.004542661F, -0.00794363F, 0.014335498F, -0.031575486F,
      0.998056F, 0.033967752F, -0.014982029F, 0.008252912F, -0.0047208155F,
      0.0026286708F, -0.0013691261F, 0.0006413844F, -0.00025534042F,
      7.681919E-5F, -1.1243598E-5F, 8.621138E-6F, -6.523013E-5F, 0.00022260712F,
      -0.0005668645F, 0.0012205411F, -0.002356751F, 0.0042463085F,
      -0.0074253078F, 0.013402606F, -0.029547539F, 0.9983064F, 0.03163168F,
      -0.013965925F, 0.007694789F, -0.004401538F, 0.0024506198F, -0.0012761429F,
      0.00059764966F, -0.0002378189F, 7.148459E-5F, -1.0428708E-5F, 8.064303E-6F,
      -6.0785715E-5F, 0.00020724644F, -0.00052749575F, 0.0011354319F,
      -0.0021919776F, 0.0039489707F, -0.0069052777F, 0.012466291F, -0.027508423F,
      0.9985396F, 0.029305631F, -0.012952106F, 0.0071376865F, -0.0040828465F,
      0.0022729337F, -0.0011833851F, 0.00055404595F, -0.00022036559F,
      6.617973E-5F, -9.623173E-6F, 7.4984846E-6F, -5.6307803E-5F, 0.00019180049F,
      -0.00048794795F, 0.0010499893F, -0.002026626F, 0.0036506604F,
      -0.006383562F, 0.01152659F, -0.025458172F, 0.9987556F, 0.026989656F,
      -0.011940615F, 0.0065816306F, -0.003764755F, 0.0020956204F, -0.0010908571F,
      0.0005105753F, -0.00020298119F, 6.090479E-5F, -8.826991E-6F, 6.9236585E-6F,
      -5.17965E-5F, 0.0001762698F, -0.00044822274F, 0.00096421636F,
      -0.0018607031F, 0.0033513908F, -0.0058601843F, 0.010583541F, -0.023396824F,
      0.99895424F, 0.024683798F, -0.010931496F, 0.0060266475F, -0.0034472803F,
      0.0019186888F, -0.0009985632F, 0.0004672396F, -0.00018566645F,
      5.5659948E-5F, -8.040157E-6F, 6.3398015E-6F, -4.7251917E-5F, 0.0001606549F,
      -0.00040832168F, 0.0008781171F, -0.0016942167F, 0.0030511753F,
      -0.0053351675F, 0.009637182F, -0.021324413F, 0.9991357F, 0.022388104F,
      -0.009924792F, 0.0054727634F, -0.0031304364F, 0.001742147F, -0.0009065079F,
      0.00042404077F, -0.00016842205F, 5.044537E-5F, -7.2626667E-6F,
      5.746892E-6F, -4.2674146E-5F, 0.00014495639F, -0.00036824634F,
      0.00079169514F, -0.001527174F, 0.0027500272F, -0.0048085344F, 0.008687549F,
      -0.019240974F, 0.9992999F, 0.020102622F, -0.008920547F, 0.004920004F,
      -0.0028142387F, 0.0015660037F, -0.00081469526F, 0.00038098078F,
      -0.00015124874F, 4.526123E-5F, -6.4945148E-6F, 5.1449074E-6F,
      -3.8063306E-5F, 0.00012917476F, -0.00032799836F, 0.0007049542F,
      -0.0013595825F, 0.0024479604F, -0.0042803083F, 0.0077346833F,
      -0.017146545F, 0.9994468F, 0.017827393F, -0.007918802F, 0.004368395F,
      -0.0024987026F, 0.001390267F, -0.0007231297F, 0.00033806157F,
      -0.00013414718F, 4.0107694E-5F, -5.735694E-6F, 4.533828E-6F,
      -3.3419503E-5F, 0.00011331062F, -0.00028757943F, 0.000617898F,
      -0.0011914496F, 0.0021449884F, -0.003750513F, 0.0067786216F, -0.015041161F,
      0.99957645F, 0.015562464F, -0.0069196033F, 0.0038179625F, -0.0021838427F,
      0.0012149453F, -0.00063181535F, 0.00029528502F, -0.00011711809F,
      3.498492E-5F, -4.9861974E-6F, 3.913632E-6F, -2.8742856E-5F, 9.736453E-5F,
      -0.00024699114F, 0.0005305304F, -0.0010227828F, 0.0018411248F,
      -0.003219172F, 0.005819403F, -0.012924863F, 0.9996888F, 0.013307878F,
      -0.005922991F, 0.0032687318F, -0.0018696738F, 0.0010400468F,
      -0.0005407565F, 0.000252653F, -0.00010016215F, 2.9893075E-5F,
      -4.2460165E-6F, 3.284302E-6F, -2.4033478E-5F, 8.1337064E-5F,
      -0.0002062352F, 0.00044285515F, -0.00085358974F, 0.0015363836F,
      -0.0026863087F, 0.0048570666F, -0.010797687F, 0.9997839F, 0.01106368F,
      -0.0049290084F, 0.0027207283F, -0.001556211F, 0.00086557976F,
      -0.00044995724F, 0.00021016739F, -8.328003E-5F, 2.4832312E-5F,
      -3.5151425E-6F, 2.645818E-6F, -1.9291494E-5F, 6.5228814E-5F,
      -0.00016531326F, 0.0003548761F, -0.00068387814F, 0.0012307785F,
      -0.0021519472F, 0.0038916513F, -0.008659672F, 0.99986166F, 0.008829912F,
      -0.003937697F, 0.0021739774F, -0.0012434691F, 0.0006915523F,
      -0.0003594218F, 0.00016783006F, -6.647241E-5F, 1.9802785E-5F,
      -2.7935655E-6F, 1.9981626E-6F, -1.4517026E-5F, 4.904038E-5F,
      -0.00012422707F, 0.00026659717F, -0.0005136556F, 0.0009243235F,
      -0.0016161114F, 0.002923197F, -0.0065108556F, 0.9999222F, 0.0066066184F,
      -0.002949099F, 0.001628504F, -0.00093146233F, 0.00051797257F,
      -0.00026915426F, 0.00012564284F, -4.9739938E-5F, 1.4804642E-5F,
      -2.0812747E-6F, 1.3413185E-6F, -9.710201E-6F, 3.2772357E-5F, -8.297829E-5F,
      0.00017802221F, -0.00034292985F, 0.0006170327F, -0.0010788254F,
      0.0019517436F, -0.0043512788F, 0.9999654F, 0.0043938407F, -0.0019632562F,
      0.0010843335F, -0.0006202056F, 0.00034484858F, -0.00017915874F,
      8.360755E-5F, -3.3083285E-5F, 9.838035E-6F, -1.3782585E-6F, 6.7526946E-7F,
      -4.871148E-6F, 1.6425358E-5F, -4.1568685E-5F, 8.915517E-5F,
      -0.00017170871F, 0.0003089201F, -0.0005401135F, 0.0009773312F,
      -0.0021809798F, 0.99999136F, 0.0021916204F, -0.0009802094F, 0.00054149056F,
      -0.00030971336F, 0.00017218842F, -8.943931E-5F, 4.1726005E-5F,
      -1.6503092E-5F, 4.9031073E-6F, -6.8450464E-7F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -6.8450464E-7F, 4.9031073E-6F,
      -1.6503092E-5F, 4.1726005E-5F, -8.943931E-5F, 0.00017218842F,
      -0.00030971336F, 0.00054149056F, -0.0009802094F, 0.0021916204F,
      0.99999136F, -0.0021809798F, 0.0009773312F, -0.0005401135F, 0.0003089201F,
      -0.00017170871F, 8.915517E-5F, -4.1568685E-5F, 1.6425358E-5F,
      -4.871148E-6F, 6.7526946E-7F, -1.3782585E-6F, 9.838035E-6F, -3.3083285E-5F,
      8.360755E-5F, -0.00017915874F, 0.00034484858F, -0.0006202056F,
      0.0010843335F, -0.0019632562F, 0.0043938407F, 0.9999654F, -0.0043512788F,
      0.0019517436F, -0.0010788254F, 0.0006170327F, -0.00034292985F,
      0.00017802221F, -8.297829E-5F, 3.2772357E-5F, -9.710201E-6F, 1.3413185E-6F,
      -2.0812747E-6F, 1.4804642E-5F, -4.9739938E-5F, 0.00012564284F,
      -0.00026915426F, 0.00051797257F, -0.00093146233F, 0.001628504F,
      -0.002949099F, 0.0066066184F, 0.9999222F, -0.0065108556F, 0.002923197F,
      -0.0016161114F, 0.0009243235F, -0.0005136556F, 0.00026659717F,
      -0.00012422707F, 4.904038E-5F, -1.4517026E-5F, 1.9981626E-6F,
      -2.7935655E-6F, 1.9802785E-5F, -6.647241E-5F, 0.00016783006F,
      -0.0003594218F, 0.0006915523F, -0.0012434691F, 0.0021739774F,
      -0.003937697F, 0.008829912F, 0.99986166F, -0.008659672F, 0.0038916513F,
      -0.0021519472F, 0.0012307785F, -0.00068387814F, 0.0003548761F,
      -0.00016531326F, 6.5228814E-5F, -1.9291494E-5F, 2.645818E-6F,
      -3.5151425E-6F, 2.4832312E-5F, -8.328003E-5F, 0.00021016739F,
      -0.00044995724F, 0.00086557976F, -0.001556211F, 0.0027207283F,
      -0.0049290084F, 0.01106368F, 0.9997839F, -0.010797687F, 0.0048570666F,
      -0.0026863087F, 0.0015363836F, -0.00085358974F, 0.00044285515F,
      -0.0002062352F, 8.1337064E-5F, -2.4033478E-5F, 3.284302E-6F,
      -4.2460165E-6F, 2.9893075E-5F, -0.00010016215F, 0.000252653F,
      -0.0005407565F, 0.0010400468F, -0.0018696738F, 0.0032687318F,
      -0.005922991F, 0.013307878F, 0.9996888F, -0.012924863F, 0.005819403F,
      -0.003219172F, 0.0018411248F, -0.0010227828F, 0.0005305304F,
      -0.00024699114F, 9.736453E-5F, -2.8742856E-5F, 3.913632E-6F,
      -4.9861974E-6F, 3.498492E-5F, -0.00011711809F, 0.00029528502F,
      -0.00063181535F, 0.0012149453F, -0.0021838427F, 0.0038179625F,
      -0.0069196033F, 0.015562464F, 0.99957645F, -0.015041161F, 0.0067786216F,
      -0.003750513F, 0.0021449884F, -0.0011914496F, 0.000617898F,
      -0.00028757943F, 0.00011331062F, -3.3419503E-5F, 4.533828E-6F,
      -5.735694E-6F, 4.0107694E-5F, -0.00013414718F, 0.00033806157F,
      -0.0007231297F, 0.001390267F, -0.0024987026F, 0.004368395F, -0.007918802F,
      0.017827393F, 0.9994468F, -0.017146545F, 0.0077346833F, -0.0042803083F,
      0.0024479604F, -0.0013595825F, 0.0007049542F, -0.00032799836F,
      0.00012917476F, -3.8063306E-5F, 5.1449074E-6F, -6.4945148E-6F,
      4.526123E-5F, -0.00015124874F, 0.00038098078F, -0.00081469526F,
      0.0015660037F, -0.0028142387F, 0.004920004F, -0.008920547F, 0.020102622F,
      0.9992999F, -0.019240974F, 0.008687549F, -0.0048085344F, 0.0027500272F,
      -0.001527174F, 0.00079169514F, -0.00036824634F, 0.00014495639F,
      -4.2674146E-5F, 5.746892E-6F, -7.2626667E-6F, 5.044537E-5F,
      -0.00016842205F, 0.00042404077F, -0.0009065079F, 0.001742147F,
      -0.0031304364F, 0.0054727634F, -0.009924792F, 0.022388104F, 0.9991357F,
      -0.021324413F, 0.009637182F, -0.0053351675F, 0.0030511753F, -0.0016942167F,
      0.0008781171F, -0.00040832168F, 0.0001606549F, -4.7251917E-5F,
      6.3398015E-6F, -8.040157E-6F, 5.5659948E-5F, -0.00018566645F,
      0.0004672396F, -0.0009985632F, 0.0019186888F, -0.0034472803F,
      0.0060266475F, -0.010931496F, 0.024683798F, 0.99895424F, -0.023396824F,
      0.010583541F, -0.0058601843F, 0.0033513908F, -0.0018607031F,
      0.00096421636F, -0.00044822274F, 0.0001762698F, -5.17965E-5F,
      6.9236585E-6F, -8.826991E-6F, 6.090479E-5F, -0.00020298119F, 0.0005105753F,
      -0.0010908571F, 0.0020956204F, -0.003764755F, 0.0065816306F, -0.011940615F,
      0.026989656F, 0.9987556F, -0.025458172F, 0.01152659F, -0.006383562F,
      0.0036506604F, -0.002026626F, 0.0010499893F, -0.00048794795F,
      0.00019180049F, -5.6307803E-5F, 7.4984846E-6F, -9.623173E-6F, 6.617973E-5F,
      -0.00022036559F, 0.00055404595F, -0.0011833851F, 0.0022729337F,
      -0.0040828465F, 0.0071376865F, -0.012952106F, 0.029305631F, 0.9985396F,
      -0.027508423F, 0.012466291F, -0.0069052777F, 0.0039489707F, -0.0021919776F,
      0.0011354319F, -0.00052749575F, 0.00020724644F, -6.0785715E-5F,
      8.064303E-6F, -1.0428708E-5F, 7.148459E-5F, -0.0002378189F, 0.00059764966F,
      -0.0012761429F, 0.0024506198F, -0.004401538F, 0.007694789F, -0.013965925F,
      0.03163168F, 0.9983064F, -0.029547539F, 0.013402606F, -0.0074253078F,
      0.0042463085F, -0.002356751F, 0.0012205411F, -0.0005668645F,
      0.00022260712F, -6.523013E-5F, 8.621138E-6F, -1.1243598E-5F, 7.681919E-5F,
      -0.00025534042F, 0.0006413844F, -0.0013691261F, 0.0026286708F,
      -0.0047208155F, 0.008252912F, -0.014982029F, 0.033967752F, 0.998056F,
      -0.031575486F, 0.014335498F, -0.00794363F, 0.004542661F, -0.0025209389F,
      0.0013053128F, -0.0006060527F, 0.00023788202F, -6.964096E-5F,
      9.1690135E-6F, -1.2067846E-5F, 8.218335E-5F, -0.00027292938F,
      0.0006852481F, -0.0014623305F, 0.0028070775F, -0.005040663F, 0.008812029F,
      -0.016000371F, 0.036313802F, 0.9977883F, -0.03359223F, 0.015264931F,
      -0.008460223F, 0.004838014F, -0.0026845338F, 0.0013897436F, -0.0006450587F,
      0.00025307058F, -7.401811E-5F, 9.7079555E-6F, -1.2901453E-5F, 8.75769E-5F,
      -0.00029058507F, 0.0007292389F, -0.0015557514F, 0.0029858316F,
      -0.005361065F, 0.009372114F, -0.017020911F, 0.038669784F, 0.99750346F,
      -0.035597738F, 0.016190866F, -0.0089750625F, 0.0051323553F, -0.0028475292F,
      0.0014738301F, -0.0006838811F, 0.00026817233F, -7.8361496E-5F,
      1.0237989E-5F, -1.3744419E-5F, 9.2999624E-5F, -0.00030830668F,
      0.00077335467F, -0.0016493846F, 0.0031649244F, -0.005682006F, 0.009933139F,
      -0.0180436F, 0.041035645F, 0.9972013F, -0.037591975F, 0.01711327F,
      -0.009488126F, 0.0054256716F, -0.0030099174F, 0.0015575686F,
      -0.00072251837F, 0.00028318673F, -8.267101E-5F, 0.0F, -1.4596744E-5F,
      9.845135E-5F, -0.00032609355F, 0.0008175935F, -0.0017432255F,
      0.0033443475F, -0.0060034706F, 0.01049508F, -0.019068394F, 0.04341134F,
      0.996882F, -0.03957491F, 0.018032104F, -0.0099993935F, 0.00571795F,
      -0.003171692F, 0.0016409556F, -0.00076096895F, 0.00029811333F,
      -8.694657E-5F, 0.0F, -1.5458427E-5F, 0.00010393188F, -0.00034394482F,
      0.0008619531F, -0.0018372696F, 0.0035240918F, -0.0063254433F, 0.011057906F,
      -0.02009525F, 0.045796823F, 0.99654555F, -0.041546505F, 0.018947335F,
      -0.010508842F, 0.0060091782F, -0.0033328452F, 0.0017239876F,
      -0.00079923146F, 0.0003129516F, -9.1188114E-5F, 0.0F, -1.6329464E-5F,
      0.000109441025F, -0.00036185974F, 0.0009064317F, -0.0019315125F,
      0.0037041486F, -0.006647908F, 0.0116215935F, -0.021124119F, 0.04819204F,
      0.9961919F, -0.043506738F, 0.019858923F, -0.011016448F, 0.006299343F,
      -0.0034933707F, 0.0018066614F, -0.00083730434F, 0.00032770107F,
      -9.5395546E-5F, 0.0F, -1.7209855E-5F, 0.000114978575F, -0.00037983755F,
      0.0009510271F, -0.0020259495F, 0.0038845092F, -0.006970849F, 0.012186115F,
      -0.022154959F, 0.05059694F, 0.99582106F, -0.045455568F, 0.020766838F,
      -0.0115221925F, 0.006588432F, -0.0036532616F, 0.0018889734F,
      -0.0008751862F, 0.00034236128F, -9.956879E-5F, 0.0F, -1.8099594E-5F,
      0.000120544326F, -0.00039787745F, 0.0009957372F, -0.002120576F,
      0.004065165F, -0.0072942507F, 0.012751441F, -0.023187723F, 0.05301148F,
      0.9954331F, -0.047392968F, 0.02167104F, -0.012026052F, 0.006876433F,
      -0.003812511F, 0.0019709202F, -0.0009128756F, 0.00035693173F,
      -0.00010370777F, 0.0F, -1.8998673E-5F, 0.00012613808F, -0.00041597863F,
      0.0010405598F, -0.0022153878F, 0.0042461064F, -0.0076180967F, 0.013317547F,
      -0.024222365F, 0.0554356F, 0.99502796F, -0.049318906F, 0.022571497F,
      -0.012528006F, 0.0071633323F, -0.003971112F, 0.0020524987F,
      -0.00095037103F, 0.00037141202F, -0.00010781242F, 0.0F, -1.9907091E-5F,
      0.00013175963F, -0.00043414033F, 0.0010854929F, -0.0023103796F,
      0.0044273245F, -0.007942371F, 0.013884404F, -0.025258837F, 0.05786926F,
      0.99460566F, -0.051233355F, 0.023468176F, -0.013028034F, 0.0074491194F,
      -0.0041290578F, 0.0021337057F, -0.0009876713F, 0.00038580166F,
      -0.00011188267F, 0.0F, -2.0824838E-5F, 0.00013740876F, -0.0004523617F,
      0.0011305343F, -0.0024055475F, 0.0046088113F, -0.008267059F, 0.014451984F,
      -0.026297094F, 0.060312398F, 0.9941663F, -0.05313628F, 0.024361039F,
      -0.013526113F, 0.007733781F, -0.0042863423F, 0.0022145375F, -0.0010247749F,
      0.0004001002F, -0.000115918454F, 0.0F, -2.1751908E-5F, 0.00014308524F,
      -0.0004706419F, 0.0011756821F, -0.0025008863F, 0.004790557F, -0.008592143F,
      0.0150202615F, -0.02733709F, 0.062764965F, 0.9937098F, -0.05502766F,
      0.025250055F, -0.014022224F, 0.008017304F, -0.004442958F, 0.002294991F,
      -0.0010616805F, 0.0004143072F, -0.00011991971F, 0.0F, -2.2688291E-5F,
      0.00014878888F, -0.0004889802F, 0.0012209337F, -0.0025963916F,
      0.0049725533F, -0.008917606F, 0.0155892065F, -0.028378777F, 0.06522691F,
      0.99323624F, -0.056907456F, 0.02613519F, -0.014516344F, 0.008299679F,
      -0.0045988993F, 0.002375063F, -0.0010983867F, 0.00042842227F,
      -0.00012388638F, 0.0F, -2.3633978E-5F, 0.00015451942F, -0.0005073757F,
      0.0012662873F, -0.0026920584F, 0.00515479F, -0.009243435F, 0.016158793F,
      -0.029422106F, 0.06769818F, 0.9927456F, -0.058775645F, 0.027016409F,
      -0.015008454F, 0.008580891F, -0.004754159F, 0.0024547505F, -0.0011348922F,
      0.00044244496F, -0.00012781839F, 0.0F, -2.4588959E-5F, 0.00016027669F,
      -0.0005258275F, 0.0013117405F, -0.0027878822F, 0.005337259F,
      -0.0095696105F, 0.016728992F, -0.030467035F, 0.070178725F, 0.99223787F,
      -0.060632203F, 0.02789368F, -0.015498534F, 0.008860931F, -0.004908731F,
      0.00253405F, -0.0011711956F, 0.00045637487F, -0.00013171571F, 0.0F,
      -2.555322E-5F, 0.00016606042F, -0.0005443349F, 0.0013572912F,
      -0.0028838583F, 0.0055199503F, -0.009896118F, 0.017299775F, -0.031513512F,
      0.07266849F, 0.99171317F, -0.062477093F, 0.02876697F, -0.015986562F,
      0.009139786F, -0.0050626094F, 0.0026129587F, -0.0012072959F,
      0.00047021158F, -0.00013557827F, 0.0F, -2.6526748E-5F, 0.00017187039F,
      -0.00056289695F, 0.0014029372F, -0.0029799817F, 0.005702855F,
      -0.010222941F, 0.017871115F, -0.03256149F, 0.07516742F, 0.99117136F,
      -0.0643103F, 0.029636247F, -0.016472518F, 0.009417443F, -0.005215787F,
      0.0026914736F, -0.0012431915F, 0.00048395473F, -0.00013940604F, 0.0F,
      -2.7509534E-5F, 0.00017770636F, -0.00058151275F, 0.0014486762F,
      -0.0030762476F, 0.0058859643F, -0.010550062F, 0.018442985F, -0.03361092F,
      0.077675454F, 0.99061257F, -0.066131786F, 0.03050148F, -0.016956385F,
      0.009693891F, -0.005368258F, 0.0027695913F, -0.0012788813F, 0.0004976039F,
      -0.00014319895F, 0.0F, -2.8501558E-5F, 0.0001835681F, -0.0006001816F,
      0.0014945059F, -0.0031726514F, 0.0060692686F, -0.010877465F, 0.019015353F,
      -0.034661755F, 0.08019255F, 0.9900368F, -0.06794153F, 0.031362634F,
      -0.01743814F, 0.00996912F, -0.0055200155F, 0.0028473088F, -0.001314364F,
      0.00051115867F, -0.00014695698F, 0.0F, -2.950281E-5F, 0.00018945537F,
      -0.00061890244F, 0.0015404242F, -0.003269188F, 0.006252758F, -0.011205133F,
      0.019588195F, -0.03571395F, 0.08271865F, 0.9894441F, -0.069739506F,
      0.03221968F, -0.017917763F, 0.010243117F, -0.005671054F, 0.0029246234F,
      -0.0013496383F, 0.0005246187F, -0.00015068008F, 0.0F, -3.0513267E-5F,
      0.00019536795F, -0.0006376745F, 0.0015864287F, -0.0033658526F,
      0.006436425F, -0.011533051F, 0.020161478F, -0.03676745F, 0.085253686F,
      0.9888344F, -0.07152569F, 0.033072583F, -0.018395238F, 0.010515871F,
      -0.0058213677F, 0.003001532F, -0.0013847031F, 0.0005379837F,
      -0.0001543682F, 0.0F, -3.1532916E-5F, 0.00020130555F, -0.00065649685F,
      0.0016325173F, -0.0034626406F, 0.006620258F, -0.0118612F, 0.020735176F,
      -0.03782221F, 0.08779761F, 0.9882077F, -0.07330006F, 0.033921316F,
      -0.018870542F, 0.010787372F, -0.0059709502F, 0.0030780316F, -0.0014195571F,
      0.0005512532F, -0.00015802131F, 0.0F, -3.2561737E-5F, 0.00020726793F,
      -0.0006753686F, 0.0016786875F, -0.0035595465F, 0.006804249F, -0.012189565F,
      0.021309258F, -0.03887818F, 0.090350375F, 0.9875642F, -0.07506259F,
      0.034765847F, -0.019343656F, 0.011057607F, -0.006119795F, 0.0031541195F,
      -0.0014541993F, 0.0005644269F, -0.0001616394F, 0.0F, -3.3599714E-5F,
      0.00021325487F, -0.0006942889F, 0.0017249371F, -0.003656566F, 0.006988388F,
      -0.012518129F, 0.0218837F, -0.039935313F, 0.092911914F, 0.9869037F,
      -0.07681325F, 0.035606146F, -0.019814564F, 0.011326565F, -0.006267897F,
      0.0032297925F, -0.0014886284F, 0.0005775044F, -0.00016522242F, 0.0F,
      -3.464682E-5F, 0.00021926609F, -0.0007132567F, 0.0017712638F,
      -0.0037536935F, 0.0071726656F, -0.012846874F, 0.02245847F, -0.040993556F,
      0.09548217F, 0.98622644F, -0.07855202F, 0.036442183F, -0.020283243F,
      0.011594238F, -0.00641525F, 0.0033050482F, -0.0015228433F, 0.00059048546F,
      -0.00016877033F, 0.0F, -3.5703037E-5F, 0.00022530134F, -0.00073227123F,
      0.0018176651F, -0.0038509245F, 0.0073570726F, -0.013175785F, 0.023033537F,
      -0.04205286F, 0.098061085F, 0.9855323F, -0.08027889F, 0.037273925F,
      -0.020749679F, 0.011860612F, -0.006561848F, 0.0033798835F, -0.0015568427F,
      0.00060336967F, -0.00017228312F, 0.0F, -3.6768346E-5F, 0.00023136035F,
      -0.0007513315F, 0.0018641389F, -0.0039482536F, 0.0075415988F,
      -0.013504843F, 0.023608875F, -0.04311318F, 0.10064861F, 0.98482126F,
      -0.08199382F, 0.038101345F, -0.021213848F, 0.0121256765F, -0.006707685F,
      0.0034542955F, -0.0015906256F, 0.00061615667F, -0.00017576078F, 0.0F,
      -3.7842718E-5F, 0.00023744286F, -0.00077043666F, 0.0019106827F,
      -0.0040456764F, 0.0077262353F, -0.013834032F, 0.024184454F, -0.04417446F,
      0.10324468F, 0.9840935F, -0.0836968F, 0.03892441F, -0.021675736F,
      0.012389422F, -0.006852756F, 0.0035282818F, -0.0016241911F, 0.0006288463F,
      -0.00017920327F, 0.0F, -3.892613E-5F, 0.0002435486F, -0.00078958564F,
      0.001957294F, -0.0041431873F, 0.007910972F, -0.014163336F, 0.024760244F,
      -0.04523665F, 0.10584923F, 0.9833489F, -0.085387796F, 0.0397431F,
      -0.022135323F, 0.012651838F, -0.006997055F, 0.0036018395F, -0.0016575378F,
      0.0006414381F, -0.00018261059F, 0.0F, -4.0018556E-5F, 0.0002496773F,
      -0.0008087776F, 0.0020039708F, -0.0042407815F, 0.0080958F, -0.014492735F,
      0.025336217F, -0.046299703F, 0.10846221F, 0.9825876F, -0.0870668F,
      0.040557377F, -0.022592591F, 0.012912914F, -0.007140576F, 0.0036749663F,
      -0.0016906647F, 0.0006539319F, -0.0001859827F, 0.0F, -4.111997E-5F,
      0.0002558287F, -0.00082801154F, 0.0020507101F, -0.0043384535F,
      0.008280708F, -0.014822215F, 0.025912344F, -0.04736357F, 0.11108355F,
      0.9818095F, -0.088733785F, 0.041367218F, -0.023047524F, 0.013172639F,
      -0.007283314F, 0.003747659F, -0.001723571F, 0.00066632725F,
      -0.00018931963F, 0.0F, -4.2230346E-5F, 0.0002620025F, -0.00084728654F,
      0.0020975103F, -0.004436199F, 0.00846569F, -0.015151757F, 0.026488593F,
      -0.048428196F, 0.11371321F, 0.9810147F, -0.09038873F, 0.042172592F,
      -0.0235001F, 0.013431002F, -0.0074252635F, 0.0038199152F, -0.0017562554F,
      0.00067862397F, -0.00019262133F, 0.0F, -4.334965E-5F, 0.0002681984F,
      -0.00086660165F, 0.0021443684F, -0.004534012F, 0.008650731F, -0.015481344F,
      0.027064936F, -0.049493533F, 0.11635111F, 0.9802033F, -0.09203162F,
      0.04297347F, -0.023950305F, 0.013687995F, -0.007566419F, 0.0038917325F,
      -0.0017887169F, 0.00069082173F, -0.00019588781F, 0.0F, -4.447786E-5F,
      0.00027441618F, -0.0008859559F, 0.0021912819F, -0.004631888F, 0.008835825F,
      -0.015810959F, 0.027641343F, -0.050559524F, 0.1189972F, 0.9793752F,
      -0.09366244F, 0.04376983F, -0.024398122F, 0.013943607F, -0.007706775F,
      0.003963108F, -0.0018209547F, 0.00070292037F, -0.00019911908F, 0.0F,
      -4.5614943E-5F, 0.0002806555F, -0.0009053482F, 0.0022382487F,
      -0.0047298213F, 0.009020962F, -0.016140586F, 0.028217785F, -0.051626127F,
      0.12165142F, 0.9785304F, -0.09528116F, 0.044561636F, -0.024843529F,
      0.014197826F, -0.007846327F, 0.00403404F, -0.0018529677F, 0.0007149195F,
      -0.00020231512F, 0.0F, -4.6760862E-5F, 0.00028691613F, -0.0009247777F,
      0.0022852663F, -0.004827807F, 0.00920613F, -0.016470203F, 0.028794233F,
      -0.05269328F, 0.1243137F, 0.97766906F, -0.096887775F, 0.045348868F,
      -0.025286514F, 0.014450646F, -0.007985068F, 0.004104525F, -0.0018847549F,
      0.0007268189F, -0.00020547592F, 0.0F, -4.791559E-5F, 0.0002931977F,
      -0.00094424334F, 0.002332332F, -0.0049258405F, 0.009391321F, -0.016799798F,
      0.029370654F, -0.053760946F, 0.12698399F, 0.97679114F, -0.09848225F,
      0.0461315F, -0.02572706F, 0.014702054F, -0.008122994F, 0.0041745612F,
      -0.0019163153F, 0.0007386184F, -0.00020860152F, 0.0F, -4.9079088E-5F,
      0.00029949998F, -0.0009637442F, 0.0023794437F, -0.0050239153F,
      0.009576525F, -0.017129352F, 0.02994702F, -0.054829057F, 0.1296622F,
      0.97589666F, -0.10006459F, 0.0469095F, -0.026165146F, 0.014952041F,
      -0.0082601F, 0.004244146F, -0.001947648F, 0.0007503176F, -0.00021169189F,
      0.0F, -5.0251325E-5F, 0.0003058226F, -0.0009832792F, 0.0024265985F,
      -0.0051220274F, 0.009761731F, -0.017458845F, 0.030523302F, -0.05589757F,
      0.13234831F, 0.97498566F, -0.101634756F, 0.047682844F, -0.026600758F,
      0.015200599F, -0.008396381F, 0.004313277F, -0.0019787522F, 0.0007619164F,
      -0.00021474707F, 0.0F, -5.1432267E-5F, 0.00031216536F, -0.0010028473F,
      0.0024737942F, -0.0052201706F, 0.00994693F, -0.017788263F, 0.031099468F,
      -0.05696643F, 0.13504224F, 0.97405815F, -0.103192754F, 0.04845151F,
      -0.02703388F, 0.015447717F, -0.008531831F, 0.004381952F, -0.002009627F,
      0.00077341456F, -0.00021776704F, 0.0F, -5.2621872E-5F, 0.0003185279F,
      -0.0010224476F, 0.002521028F, -0.0053183404F, 0.010132113F, -0.018117586F,
      0.031675488F, -0.05803559F, 0.1377439F, 0.9731142F, -0.10473855F,
      0.04921547F, -0.027464496F, 0.015693385F, -0.0086664455F, 0.004450168F,
      -0.0020402714F, 0.0007848118F, -0.00022075184F, 0.0F, -5.3820102E-5F,
      0.00032490987F, -0.0010420791F, 0.0025682976F, -0.0054165307F,
      0.010317268F, -0.018446798F, 0.032251336F, -0.059104994F, 0.14045326F,
      0.97215384F, -0.10627213F, 0.049974695F, -0.027892588F, 0.015937597F,
      -0.008800221F, 0.004517924F, -0.0020706847F, 0.0007961079F,
      -0.00022370147F, 0.0F, -5.502692E-5F, 0.00033131102F, -0.0010617407F,
      0.0026156006F, -0.0055147368F, 0.010502385F, -0.018775878F, 0.032826975F,
      -0.060174584F, 0.14317024F, 0.97117704F, -0.107793495F, 0.050729167F,
      -0.028318143F, 0.01618034F, -0.00893315F, 0.0045852168F, -0.0021008658F,
      0.0008073028F, -0.00022661594F, 0.0F, -5.6242287E-5F, 0.00033773103F,
      -0.0010814313F, 0.002662934F, -0.0056129536F, 0.010687456F, -0.019104814F,
      0.033402376F, -0.061244316F, 0.1458948F, 0.9701839F, -0.10930262F,
      0.051478855F, -0.028741142F, 0.016421607F, -0.00906523F, 0.0046520443F,
      -0.0021308141F, 0.0008183961F, -0.0002294953F, 0.0F, -5.7466157E-5F,
      0.00034416956F, -0.0011011498F, 0.0027102956F, -0.005711175F, 0.010872469F,
      -0.019433582F, 0.033977512F, -0.06231413F, 0.14862683F, 0.9691744F,
      -0.11079949F, 0.052223742F, -0.029161572F, 0.016661389F, -0.009196456F,
      0.0047184047F, -0.0021605284F, 0.00082938775F, -0.00023233956F, 0.0F,
      -5.8698493E-5F, 0.00035062633F, -0.0011208955F, 0.0027576827F,
      -0.005809396F, 0.011057416F, -0.01976217F, 0.034552354F, -0.06338398F,
      0.1513663F, 0.9681486F, -0.112284094F, 0.052963797F, -0.029579416F,
      0.016899675F, -0.009326822F, 0.0047842953F, -0.0021900085F, 0.0008402775F,
      -0.00023514873F, 0.0F, -5.9939248E-5F, 0.00035710097F, -0.001140667F,
      0.0028050928F, -0.005907611F, 0.011242284F, -0.020090556F, 0.035126865F,
      -0.0644538F, 0.15411314F, 0.9671065F, -0.11375642F, 0.053698998F,
      -0.029994661F, 0.017136458F, -0.009456324F, 0.0048497147F, -0.0022192532F,
      0.00085106527F, -0.00023792287F, 0.0F, -6.118838E-5F, 0.00036359316F,
      -0.0011604634F, 0.0028525235F, -0.006005815F, 0.011427066F, -0.020418724F,
      0.035701018F, -0.06552356F, 0.15686727F, 0.9660482F, -0.11521645F,
      0.054429322F, -0.030407289F, 0.01737173F, -0.009584959F, 0.00491466F,
      -0.0022482618F, 0.00086175074F, -0.00024066198F, 0.0F, -6.244583E-5F,
      0.0003701026F, -0.0011802837F, 0.0028999718F, -0.0061040027F, 0.011611749F,
      -0.020746656F, 0.036274783F, -0.06659318F, 0.15962864F, 0.9649737F,
      -0.11666418F, 0.05515475F, -0.030817287F, 0.017605484F, -0.009712719F,
      0.00497913F, -0.0022770336F, 0.0008723338F, -0.00024336608F, 0.0F,
      -6.371158E-5F, 0.00037662897F, -0.0012001266F, 0.0029474352F,
      -0.0062021683F, 0.011796325F, -0.021074332F, 0.036848128F, -0.06766262F,
      0.16239718F, 0.963883F, -0.11809959F, 0.055875253F, -0.031224638F,
      0.017837707F, -0.009839604F, 0.005043122F, -0.002305568F, 0.0008828144F,
      -0.00024603526F, 0.0F, -6.498556E-5F, 0.0003831719F, -0.0012199912F,
      0.0029949113F, -0.0063003064F, 0.011980783F, -0.021401739F, 0.03742102F,
      -0.06873183F, 0.16517282F, 0.9627762F, -0.11952268F, 0.05659081F,
      -0.03162933F, 0.018068392F, -0.009965606F, 0.005106634F, -0.002333864F,
      0.0008931923F, -0.0002486695F, 0.0F, -6.626772E-5F, 0.00038973102F,
      -0.0012398765F, 0.003042397F, -0.006398412F, 0.012165113F, -0.021728855F,
      0.037993435F, -0.06980074F, 0.16795549F, 0.96165323F, -0.120933436F,
      0.057301402F, -0.03203135F, 0.018297534F, -0.010090723F, 0.0051696645F,
      -0.0023619211F, 0.00090346736F, -0.0002512689F, 0.0F, -6.7558016E-5F,
      0.00039630607F, -0.0012597812F, 0.0030898903F, -0.006496479F, 0.012349305F,
      -0.022055661F, 0.038565334F, -0.07086932F, 0.17074512F, 0.96051425F,
      -0.12233184F, 0.058007006F, -0.032430682F, 0.018525122F, -0.01021495F,
      0.0052322117F, -0.0023897386F, 0.00091363944F, -0.00025383345F, 0.0F,
      -6.88564E-5F, 0.0004028967F, -0.0012797043F, 0.0031373883F, -0.0065945024F,
      0.012533347F, -0.022382142F, 0.039136693F, -0.07193749F, 0.17354165F,
      0.9593592F, -0.12371789F, 0.058707595F, -0.03282731F, 0.018751146F,
      -0.010338282F, 0.005294273F, -0.0024173157F, 0.00092370843F,
      -0.00025636322F, 0.0F, -7.0162816E-5F, 0.0004095025F, -0.0012996447F,
      0.003184888F, -0.006692476F, 0.012717231F, -0.02270828F, 0.039707478F,
      -0.07300521F, 0.17634502F, 0.9581882F, -0.12509158F, 0.059403155F,
      -0.033221222F, 0.018975602F, -0.010460716F, 0.0053558475F, -0.0024446517F,
      0.0009336742F, -0.00025885823F, 0.0F, -7.147721E-5F, 0.00041612316F,
      -0.0013196013F, 0.0032323874F, -0.0067903954F, 0.012900945F, -0.023034055F,
      0.040277656F, -0.07407242F, 0.17915514F, 0.9570012F, -0.1264529F,
      0.060093664F, -0.033612404F, 0.019198481F, -0.010582248F, 0.0054169325F,
      -0.0024717464F, 0.0009435367F, -0.00026131855F, 0.0F, -7.279953E-5F,
      0.00042275834F, -0.0013395731F, 0.0032798832F, -0.006888254F, 0.013084481F,
      -0.02335945F, 0.040847197F, -0.075139076F, 0.18197197F, 0.9557983F,
      -0.12780182F, 0.0607791F, -0.034000844F, 0.019419776F, -0.010702873F,
      0.0054775267F, -0.0024985985F, 0.00095329573F, -0.0002637442F, 0.0F,
      -7.412972E-5F, 0.00042940766F, -0.0013595588F, 0.003327373F, -0.006986047F,
      0.013267825F, -0.023684446F, 0.04141607F, -0.07620511F, 0.1847954F,
      0.95457953F, -0.12913835F, 0.06145944F, -0.034386527F, 0.019639477F,
      -0.010822587F, 0.005537628F, -0.002525208F, 0.0009629513F, -0.0002661353F,
      0.0F, -7.546772E-5F, 0.00043607075F, -0.0013795573F, 0.0033748539F,
      -0.0070837685F, 0.01345097F, -0.024009027F, 0.04198425F, -0.07727047F,
      0.1876254F, 0.95334494F, -0.1304625F, 0.062134665F, -0.034769442F,
      0.019857578F, -0.010941387F, 0.005597235F, -0.0025515743F, 0.0009725032F,
      -0.00026849186F, 0.0F, -7.681347E-5F, 0.00044274732F, -0.0013995676F,
      0.0034223236F, -0.007181413F, 0.013633904F, -0.024333172F, 0.042551696F,
      -0.07833511F, 0.19046187F, 0.9520945F, -0.13177425F, 0.06280476F,
      -0.035149574F, 0.020074071F, -0.011059269F, 0.005656346F, -0.0025776965F,
      0.0009819514F, -0.00027081394F, 0.0F, -7.816692E-5F, 0.00044943692F,
      -0.0014195883F, 0.003469779F, -0.007278975F, 0.013816617F, -0.024656864F,
      0.04311838F, -0.07939896F, 0.19330476F, 0.9508283F, -0.13307357F,
      0.0634697F, -0.03552691F, 0.02028895F, -0.01117623F, 0.0057149595F,
      -0.002603574F, 0.0009912958F, -0.00027310158F, 0.0F, -7.952801E-5F,
      0.00045613924F, -0.0014396186F, 0.0035172175F, -0.0073764487F,
      0.013999099F, -0.024980085F, 0.043684274F, -0.08046198F, 0.196154F,
      0.94954646F, -0.13436049F, 0.064129464F, -0.03590144F, 0.020502206F,
      -0.011292265F, 0.0057730735F, -0.0026292065F, 0.0010005364F,
      -0.0002753549F, 0.0F, -8.0896665E-5F, 0.0004628539F, -0.0014596572F,
      0.0035646365F, -0.007473829F, 0.014181339F, -0.025302816F, 0.044249345F,
      -0.0815241F, 0.19900951F, 0.94824886F, -0.13563497F, 0.06478404F,
      -0.036273144F, 0.020713832F, -0.011407371F, 0.005830686F, -0.0026545934F,
      0.001009673F, -0.00027757388F, 0.0F, -8.227284E-5F, 0.00046958053F,
      -0.001479703F, 0.003612033F, -0.00757111F, 0.014363327F, -0.02562504F,
      0.04481356F, -0.082585275F, 0.20187122F, 0.9469356F, -0.13689704F,
      0.06543341F, -0.03664202F, 0.020923823F, -0.011521543F, 0.0058877966F,
      -0.0026797343F, 0.0010187057F, -0.00027975868F, 0.0F, -8.365646E-5F,
      0.00047631873F, -0.0014997548F, 0.0036594048F, -0.0076682856F,
      0.014545052F, -0.025946738F, 0.045376886F, -0.08364544F, 0.20473906F,
      0.94560677F, -0.13814668F, 0.06607755F, -0.03700805F, 0.021132171F,
      -0.01163478F, 0.0059444034F, -0.0027046285F, 0.0010276344F, -0.0002819093F,
      0.0F, -8.504746E-5F, 0.00048306814F, -0.0015198115F, 0.0037067484F,
      -0.0077653513F, 0.014726505F, -0.026267894F, 0.045939296F, -0.084704556F,
      0.20761296F, 0.94426244F, -0.13938388F, 0.06671645F, -0.037371222F,
      0.021338867F, -0.011747077F, 0.006000504F, -0.0027292757F, 0.0010364589F,
      -0.00028402582F, 0.0F, -8.6445776E-5F, 0.0004898284F, -0.0015398717F,
      0.0037540616F, -0.007862301F, 0.014907674F, -0.026588485F, 0.046500757F,
      -0.085762545F, 0.21049285F, 0.9429025F, -0.14060865F, 0.067350075F,
      -0.03773153F, 0.021543909F, -0.011858432F, 0.0060560983F, -0.0027536757F,
      0.0010451794F, -0.00028610835F, 0.0F, -8.785135E-5F, 0.00049659907F,
      -0.0015599346F, 0.0038013412F, -0.007959127F, 0.015088548F, -0.026908495F,
      0.04706124F, -0.086819366F, 0.21337865F, 0.9415272F, -0.14182098F,
      0.06797843F, -0.038088955F, 0.021747286F, -0.011968839F, 0.0061111837F,
      -0.0027778274F, 0.0010537958F, -0.0002881569F, 0.0F, -8.9264104E-5F,
      0.00050337985F, -0.0015799986F, 0.0038485848F, -0.008055828F, 0.015269118F,
      -0.027227907F, 0.047620706F, -0.087874964F, 0.21627028F, 0.9401364F,
      -0.14302085F, 0.068601474F, -0.038443487F, 0.021948993F, -0.012078296F,
      0.0061657596F, -0.0028017308F, 0.0010623079F, -0.00029017162F, 0.0F,
      -9.068398E-5F, 0.00051017024F, -0.0016000629F, 0.0038957894F,
      -0.008152394F, 0.015449374F, -0.0275467F, 0.04817913F, -0.088929266F,
      0.2191677F, 0.9387302F, -0.1442083F, 0.06921922F, -0.03879512F,
      0.022149025F, -0.012186802F, 0.0062198243F, -0.0028253854F, 0.001070716F,
      -0.00029215254F, 0.0F, -9.211089E-5F, 0.00051696994F, -0.0016201262F,
      0.0039429525F, -0.008248821F, 0.015629305F, -0.027864859F, 0.04873648F,
      -0.089982234F, 0.2220708F, 0.93730867F, -0.14538328F, 0.069831625F,
      -0.039143838F, 0.022347374F, -0.01229435F, 0.0062733768F, -0.002848791F,
      0.0010790197F, -0.00029409974F, 0.0F, -9.3544775E-5F, 0.00052377855F,
      -0.0016401873F, 0.003990071F, -0.008345105F, 0.015808897F, -0.028182363F,
      0.04929272F, -0.09103381F, 0.22497953F, 0.9358719F, -0.14654581F,
      0.07043868F, -0.039489634F, 0.022544034F, -0.01240094F, 0.006326415F,
      -0.002871947F, 0.0010872193F, -0.0002960133F, 0.0F, -9.498556E-5F,
      0.00053059566F, -0.0016602449F, 0.004037142F, -0.008441237F, 0.015988145F,
      -0.028499193F, 0.049847823F, -0.09208392F, 0.2278938F, 0.9344199F,
      -0.1476959F, 0.07104038F, -0.039832495F, 0.022739F, -0.012506568F,
      0.006378939F, -0.002894853F, 0.0010953146F, -0.00029789336F, 0.0F,
      -9.643318E-5F, 0.00053742086F, -0.001680298F, 0.004084163F, -0.008537214F,
      0.016167035F, -0.028815335F, 0.050401755F, -0.093132526F, 0.23081356F,
      0.9329526F, -0.14883354F, 0.0716367F, -0.04017241F, 0.022932265F,
      -0.01261123F, 0.006430946F, -0.0029175088F, 0.0011033058F, -0.00029973994F,
      0.0F, -9.788754E-5F, 0.00054425374F, -0.0017003452F, 0.004131131F,
      -0.008633029F, 0.016345557F, -0.029130766F, 0.050954487F, -0.09417956F,
      0.2337387F, 0.9314702F, -0.14995873F, 0.07222763F, -0.040509365F,
      0.023123825F, -0.012714924F, 0.006482436F, -0.0029399141F, 0.001111193F,
      -0.00030155314F, 0.0F, -9.934858E-5F, 0.0005510939F, -0.0017203854F,
      0.0041780425F, -0.0087286765F, 0.016523702F, -0.029445468F, 0.051505983F,
      -0.09522498F, 0.23666918F, 0.9299727F, -0.15107147F, 0.072813146F,
      -0.04084336F, 0.023313671F, -0.012817648F, 0.0065334076F, -0.0029620684F,
      0.0011189758F, -0.0003033331F, 0.0F, -0.00010081623F, 0.0005579409F,
      -0.0017404173F, 0.0042248964F, -0.008824151F, 0.016701458F, -0.029759424F,
      0.052056216F, -0.096268706F, 0.2396049F, 0.9284601F, -0.15217176F,
      0.07339324F, -0.04117438F, 0.0235018F, -0.012919398F, 0.006583859F,
      -0.0029839715F, 0.0011266546F, -0.00030507983F, 0.0F, -0.00010229039F,
      0.0005647944F, -0.0017604398F, 0.0042716884F, -0.008919447F, 0.016878814F,
      -0.030072616F, 0.05260515F, -0.0973107F, 0.2425458F, 0.9269325F,
      -0.1532596F, 0.0739679F, -0.04150241F, 0.023688206F, -0.013020171F,
      0.00663379F, -0.0030056234F, 0.0011342292F, -0.0003067935F, 0.0F,
      -0.00010377099F, 0.000571654F, -0.0017804516F, 0.0043184157F,
      -0.009014557F, 0.01705576F, -0.030385025F, 0.053152755F, -0.0983509F,
      0.2454918F, 0.92538995F, -0.154335F, 0.074537106F, -0.041827448F,
      0.023872882F, -0.013119966F, 0.006683199F, -0.0030270233F, 0.0011416998F,
      -0.00030847415F, 0.0F, -0.000105257954F, 0.0005785192F, -0.0018004515F,
      0.0043650763F, -0.0091094775F, 0.017232286F, -0.030696632F, 0.053698998F,
      -0.09938924F, 0.24844281F, 0.92383254F, -0.15539797F, 0.07510085F,
      -0.04214948F, 0.024055826F, -0.013218778F, 0.0067320853F, -0.0030481713F,
      0.0011490665F, -0.0003101219F, 0.0F, -0.000106751206F, 0.0005853896F,
      -0.0018204383F, 0.0044116667F, -0.009204202F, 0.01740838F, -0.031007418F,
      0.05424385F, -0.100425676F, 0.2513988F, 0.92226017F, -0.1564485F,
      0.07565911F, -0.0424685F, 0.02423703F, -0.013316606F, 0.006780448F,
      -0.0030690671F, 0.0011563292F, -0.00031173686F, 0.0F, -0.00010825064F,
      0.00059226487F, -0.0018404106F, 0.0044581844F, -0.009298724F, 0.017584033F,
      -0.03131737F, 0.05478728F, -0.10146014F, 0.25435963F, 0.920673F,
      -0.15748657F, 0.076211885F, -0.042784493F, 0.024416488F, -0.013413448F,
      0.0068282853F, -0.0030897104F, 0.0011634879F, -0.00031331912F, 0.0F,
      -0.000109756205F, 0.0005991445F, -0.0018603674F, 0.004504626F,
      -0.009393039F, 0.017759234F, -0.03162646F, 0.055329252F, -0.10249258F,
      0.25732526F, 0.91907114F, -0.15851223F, 0.07675915F, -0.04309746F,
      0.024594197F, -0.013509301F, 0.006875597F, -0.0031101012F, 0.0011705429F,
      -0.00031486875F, 0.0F, -0.000111267786F, 0.000606028F, -0.0018803073F,
      0.004550989F, -0.00948714F, 0.017933972F, -0.031934675F, 0.055869736F,
      -0.103522934F, 0.2602956F, 0.9174545F, -0.15952545F, 0.077300906F,
      -0.043407384F, 0.024770154F, -0.013604162F, 0.0069223824F, -0.0031302392F,
      0.0011774941F, -0.00031638594F, 0.0F, -0.00011278532F, 0.00061291514F,
      -0.001900229F, 0.0045972704F, -0.009581022F, 0.018108238F, -0.032241996F,
      0.0564087F, -0.10455115F, 0.2632706F, 0.9158232F, -0.16052626F,
      0.07783713F, -0.043714263F, 0.02494435F, -0.013698029F, 0.00696864F,
      -0.003150124F, 0.0011843416F, -0.0003178707F, 0.0F, -0.0001143087F,
      0.0006198053F, -0.0019201315F, 0.0046434677F, -0.009674679F, 0.018282017F,
      -0.032548405F, 0.056946114F, -0.10557717F, 0.26625016F, 0.9141773F,
      -0.16151464F, 0.07836782F, -0.04401808F, 0.025116783F, -0.013790901F,
      0.007014369F, -0.003169756F, 0.0011910856F, -0.00031932318F, 0.0F,
      -0.00011583785F, 0.0006266982F, -0.0019400133F, 0.0046895775F,
      -0.009768104F, 0.018455302F, -0.032853883F, 0.057481945F, -0.10660093F,
      0.26923418F, 0.91251683F, -0.1624906F, 0.07889295F, -0.044318832F,
      0.025287446F, -0.013882775F, 0.007059569F, -0.0031891344F, 0.001197726F,
      -0.0003207435F, 0.0F, -0.00011737268F, 0.00063359324F, -0.0019598731F,
      0.004735597F, -0.009861294F, 0.018628083F, -0.033158414F, 0.05801616F,
      -0.107622385F, 0.27222264F, 0.9108419F, -0.16345417F, 0.07941253F,
      -0.044616517F, 0.025456337F, -0.013973648F, 0.0071042394F, -0.0032082596F,
      0.0012042631F, -0.0003221318F, 0.0F, -0.00011891309F, 0.0006404901F,
      -0.0019797098F, 0.0047815233F, -0.00995424F, 0.018800348F, -0.033461977F,
      0.05854873F, -0.10864146F, 0.2752154F, 0.90915245F, -0.16440533F,
      0.07992652F, -0.044911116F, 0.025623452F, -0.0140635185F, 0.007148379F,
      -0.0032271312F, 0.0012106968F, -0.00032348812F, 0.0F, -0.000120459F,
      0.00064738834F, -0.0019995223F, 0.0048273536F, -0.010046938F, 0.018972086F,
      -0.033764552F, 0.05907962F, -0.109658115F, 0.27821243F, 0.90744865F,
      -0.1653441F, 0.08043493F, -0.045202628F, 0.025788784F, -0.014152384F,
      0.007191987F, -0.0032457493F, 0.0012170273F, -0.0003248126F, 0.0F,
      -0.000122010315F, 0.00065428746F, -0.002019309F, 0.004873085F,
      -0.010139383F, 0.019143285F, -0.034066122F, 0.0596088F, -0.11067227F,
      0.2812136F, 0.9057305F, -0.1662705F, 0.08093775F, -0.045491043F,
      0.02595233F, -0.014240244F, 0.0072350632F, -0.0032641136F, 0.0012232547F,
      -0.00032610536F, 0.0F, -0.00012356693F, 0.00066118705F, -0.0020390686F,
      0.004918714F, -0.010231568F, 0.019313939F, -0.03436667F, 0.06013624F,
      -0.11168389F, 0.2842189F, 0.903998F, -0.16718449F, 0.081434965F,
      -0.045776356F, 0.026114088F, -0.014327096F, 0.0072776065F, -0.003282224F,
      0.0012293792F, -0.00032736655F, 0.0F, -0.00012512878F, 0.00066808664F,
      -0.0020588F, 0.004964239F, -0.010323486F, 0.019484032F, -0.034666177F,
      0.060661905F, -0.1126929F, 0.2872282F, 0.9022513F, -0.16808613F,
      0.08192657F, -0.046058558F, 0.026274052F, -0.014412938F, 0.0073196166F,
      -0.0033000808F, 0.0012354009F, -0.00032859627F, 0.0F, -0.00012669573F,
      0.0006749858F, -0.002078502F, 0.005009656F, -0.010415133F, 0.019653559F,
      -0.034964625F, 0.061185762F, -0.11369925F, 0.29024145F, 0.9004904F,
      -0.1689754F, 0.08241254F, -0.04633764F, 0.026432218F, -0.014497768F,
      0.007361093F, -0.0033176837F, 0.0012413198F, -0.00032979462F, 0.0F,
      -0.0001282677F, 0.00068188406F, -0.002098173F, 0.0050549624F,
      -0.010506503F, 0.019822504F, -0.035261992F, 0.061707783F, -0.11470288F,
      0.29325852F, 0.8987154F, -0.16985233F, 0.08289289F, -0.046613604F,
      0.026588583F, -0.014581585F, 0.0074020345F, -0.0033350326F, 0.0012471362F,
      -0.00033096172F, 0.0F, -0.00012984459F, 0.000688781F, -0.002117812F,
      0.005100155F, -0.010597589F, 0.01999086F, -0.035558265F, 0.06222794F,
      -0.11570373F, 0.29627937F, 0.8969263F, -0.17071691F, 0.083367586F,
      -0.046886433F, 0.026743144F, -0.014664386F, 0.007442442F, -0.0033521277F,
      0.0012528502F, -0.00033209773F, 0.0F, -0.0001314263F, 0.00069567614F,
      -0.0021374174F, 0.005145231F, -0.010688387F, 0.020158615F, -0.035853423F,
      0.06274619F, -0.116701744F, 0.29930395F, 0.8951232F, -0.17156915F,
      0.08383664F, -0.047156125F, 0.026895896F, -0.014746171F, 0.007482313F,
      -0.003368969F, 0.0012584619F, -0.00033320277F, 0.0F, -0.00013301274F,
      0.00070256897F, -0.0021569883F, 0.0051901876F, -0.010778889F, 0.020325758F,
      -0.036147445F, 0.06326251F, -0.11769687F, 0.3023321F, 0.89330614F,
      -0.17240907F, 0.08430003F, -0.047422677F, 0.027046835F, -0.0148269385F,
      0.007521649F, -0.0033855566F, 0.0012639714F, -0.00033427693F, 0.0F,
      -0.0001346038F, 0.0007094591F, -0.002176523F, 0.005235022F, -0.010869091F,
      0.02049228F, -0.036440317F, 0.063776866F, -0.11868903F, 0.3053638F,
      0.89147514F, -0.17323668F, 0.08475775F, -0.047686078F, 0.02719596F,
      -0.014906686F, 0.0075604483F, -0.0034018902F, 0.001269379F, -0.0003353204F,
      0.0F, -0.00013619938F, 0.0007163461F, -0.0021960207F, 0.005279731F,
      -0.010958986F, 0.020658167F, -0.036732018F, 0.06428923F, -0.119678184F,
      0.30839896F, 0.8896304F, -0.174052F, 0.08520981F, -0.047946326F,
      0.027343266F, -0.014985411F, 0.0075987107F, -0.0034179701F, 0.0012746848F,
      -0.00033633324F, 0.0F, -0.00013779936F, 0.00072322943F, -0.0022154795F,
      0.0053243116F, -0.011048569F, 0.020823414F, -0.037022535F, 0.064799555F,
      -0.12066427F, 0.3114375F, 0.8877718F, -0.17485502F, 0.08565618F,
      -0.048203412F, 0.027488751F, -0.015063115F, 0.0076364363F, -0.0034337963F,
      0.001279889F, -0.0003373156F, 0.0F, -0.00013940365F, 0.0007301086F,
      -0.0022348985F, 0.005368761F, -0.011137834F, 0.020988004F, -0.03731184F,
      0.06530783F, -0.12164722F, 0.3144793F, 0.8858994F, -0.17564577F,
      0.08609686F, -0.048457336F, 0.027632413F, -0.015139796F, 0.007673625F,
      -0.003449369F, 0.0012849919F, -0.00033826768F, 0.0F, -0.00014101215F,
      0.0007369832F, -0.002254276F, 0.005413076F, -0.011226775F, 0.021151932F,
      -0.03759992F, 0.06581401F, -0.12262698F, 0.3175243F, 0.8840135F,
      -0.17642425F, 0.08653185F, -0.048708085F, 0.027774246F, -0.015215451F,
      0.0077102752F, -0.0034646883F, 0.0012899933F, -0.00033918954F, 0.0F,
      -0.00014262473F, 0.00074385275F, -0.0022736113F, 0.0054572537F,
      -0.011315386F, 0.021315185F, -0.03788676F, 0.06631807F, -0.1236035F,
      0.32057247F, 0.8821139F, -0.17719048F, 0.086961135F, -0.048955657F,
      0.02791425F, -0.015290081F, 0.007746388F, -0.003479754F, 0.0012948938F,
      -0.00034008134F, 0.0F, -0.0001442413F, 0.0007507168F, -0.0022929024F,
      0.0055012912F, -0.011403661F, 0.021477751F, -0.03817234F, 0.06681998F,
      -0.12457672F, 0.32362366F, 0.8802007F, -0.17794448F, 0.087384716F,
      -0.04920005F, 0.028052421F, -0.015363683F, 0.007781963F, -0.0034945665F,
      0.0012996932F, -0.00034094322F, 0.0F, -0.00014586176F, 0.00075757474F,
      -0.0023121485F, 0.005545186F, -0.011491595F, 0.021639623F, -0.038456637F,
      0.067319706F, -0.12554657F, 0.32667783F, 0.8782741F, -0.17868626F,
      0.08780259F, -0.049441256F, 0.028188756F, -0.015436257F, 0.007816999F,
      -0.003509126F, 0.0013043922F, -0.0003417753F, 0.0F, -0.00014748597F,
      0.00076442625F, -0.0023313481F, 0.0055889343F, -0.011579181F, 0.021800788F,
      -0.03873964F, 0.06781721F, -0.126513F, 0.32973486F, 0.876334F,
      -0.17941582F, 0.08821473F, -0.049679272F, 0.028323254F, -0.015507802F,
      0.007851496F, -0.0035234324F, 0.0013089906F, -0.00034257775F, 0.0F,
      -0.00014911384F, 0.0007712708F, -0.0023504996F, 0.0056325337F,
      -0.011666413F, 0.021961236F, -0.039021324F, 0.068312466F, -0.12747595F,
      0.3327947F, 0.8743806F, -0.1801332F, 0.08862116F, -0.04991409F,
      0.028455911F, -0.015578317F, 0.007885456F, -0.003537486F, 0.0013134887F,
      -0.00034335072F, 0.0F, -0.00015074524F, 0.00077810785F, -0.0023696022F,
      0.0056759813F, -0.011753288F, 0.022120956F, -0.039301675F, 0.06880545F,
      -0.12843536F, 0.33585724F, 0.8724138F, -0.18083838F, 0.089021854F,
      -0.050145715F, 0.028586727F, -0.0156478F, 0.007918876F, -0.0035512873F,
      0.0013178869F, -0.00034409433F, 0.0F, -0.00015238007F, 0.00078493694F,
      -0.002388654F, 0.005719274F, -0.011839798F, 0.022279939F, -0.039580673F,
      0.069296114F, -0.12939116F, 0.3389224F, 0.87043387F, -0.1815314F,
      0.08941682F, -0.05037413F, 0.028715698F, -0.015716253F, 0.007951758F,
      -0.003564836F, 0.0013221852F, -0.0003448087F, 0.0F, -0.00015401823F,
      0.00079175766F, -0.0024076542F, 0.0057624085F, -0.011925936F, 0.02243817F,
      -0.0398583F, 0.06978444F, -0.13034332F, 0.34199014F, 0.8684407F,
      -0.18221228F, 0.08980604F, -0.050599344F, 0.028842822F, -0.015783673F,
      0.0079841F, -0.0035781325F, 0.0013263838F, -0.00034549402F, 0.0F,
      -0.00015565957F, 0.0007985694F, -0.002426601F, 0.005805382F, -0.012011698F,
      0.022595646F, -0.040134538F, 0.07027039F, -0.13129175F, 0.34506035F,
      0.8664344F, -0.18288103F, 0.090189524F, -0.050821345F, 0.028968096F,
      -0.01585006F, 0.008015904F, -0.0035911768F, 0.0013304831F, -0.0003461504F,
      0.0F, -0.00015730398F, 0.0008053718F, -0.0024454934F, 0.005848191F,
      -0.012097078F, 0.02275235F, -0.04040937F, 0.07075394F, -0.13223642F,
      0.3481329F, 0.86441505F, -0.18353765F, 0.09056727F, -0.05104013F,
      0.029091522F, -0.015915412F, 0.008047168F, -0.0036039697F, 0.0013344833F,
      -0.00034677802F, 0.0F, -0.00015895136F, 0.0008121643F, -0.0024643298F,
      0.005890834F, -0.01218207F, 0.022908276F, -0.040682778F, 0.07123505F,
      -0.13317725F, 0.3512078F, 0.8623827F, -0.18418218F, 0.09093925F,
      -0.0512557F, 0.029213093F, -0.015979731F, 0.008077894F, -0.0036165111F,
      0.0013383846F, -0.000347377F, 0.0F, -0.00016060157F, 0.00081894634F,
      -0.002483109F, 0.005933307F, -0.012266668F, 0.02306341F, -0.040954746F,
      0.07171369F, -0.13411418F, 0.35428488F, 0.8603375F, -0.18481463F,
      0.091305494F, -0.051468045F, 0.029332813F, -0.016043015F, 0.008108081F,
      -0.003628801F, 0.0013421873F, -0.00034794753F, 0.0F, -0.00016225451F,
      0.0008257175F, -0.0025018295F, 0.005975607F, -0.012350867F, 0.023217745F,
      -0.04122525F, 0.072189845F, -0.13504717F, 0.3573641F, 0.85827935F,
      -0.18543503F, 0.091665976F, -0.05167717F, 0.029450675F, -0.016105263F,
      0.00813773F, -0.0036408403F, 0.0013458915F, -0.00034848973F, 0.0F,
      -0.00016391005F, 0.0008324773F, -0.0025204904F, 0.0060177315F,
      -0.0124346595F, 0.023371268F, -0.041494276F, 0.072663456F, -0.13597615F,
      0.36044535F, 0.85620844F, -0.18604338F, 0.092020705F, -0.051883068F,
      0.029566683F, -0.016166477F, 0.00816684F, -0.0036526287F, 0.0013494977F,
      -0.00034900376F, 0.0F, -0.00016556807F, 0.0008392252F, -0.0025390899F,
      0.006059677F, -0.012518041F, 0.02352397F, -0.041761808F, 0.07313452F,
      -0.13690105F, 0.36352858F, 0.8541247F, -0.1866397F, 0.09236967F,
      -0.052085735F, 0.029680831F, -0.016226653F, 0.008195411F, -0.003664167F,
      0.001353006F, -0.0003494898F, 0.0F, -0.00016722843F, 0.0008459607F,
      -0.0025576265F, 0.00610144F, -0.012601005F, 0.023675838F, -0.042027824F,
      0.07360298F, -0.13782184F, 0.3666137F, 0.8520284F, -0.18722402F,
      0.09271287F, -0.052285172F, 0.029793119F, -0.016285792F, 0.008223445F,
      -0.0036754552F, 0.0013564166F, -0.00034994795F, 0.0F, -0.00016889101F,
      0.0008526833F, -0.0025760992F, 0.006143019F, -0.012683547F, 0.023826865F,
      -0.042292308F, 0.07406883F, -0.13873844F, 0.36970058F, 0.8499195F,
      -0.18779634F, 0.093050316F, -0.052481372F, 0.029903548F, -0.016343895F,
      0.00825094F, -0.0036864937F, 0.0013597299F, -0.0003503784F, 0.0F,
      -0.00017055571F, 0.0008593925F, -0.0025945068F, 0.0061844103F,
      -0.01276566F, 0.02397704F, -0.042555247F, 0.07453202F, -0.13965078F,
      0.37278917F, 0.847798F, -0.18835671F, 0.09338199F, -0.05267434F,
      0.030012114F, -0.016400963F, 0.008277898F, -0.0036972829F, 0.0013629462F,
      -0.0003507813F, 0.0F, -0.00017222238F, 0.0008660878F, -0.0026128476F,
      0.0062256106F, -0.012847339F, 0.02412635F, -0.042816613F, 0.07499252F,
      -0.14055884F, 0.3758794F, 0.845664F, -0.18890513F, 0.093707904F,
      -0.052864067F, 0.03011882F, -0.016456993F, 0.0083043175F, -0.003707823F,
      0.0013660657F, -0.00035115684F, 0.0F, -0.00017389089F, 0.0008727687F,
      -0.0026311202F, 0.006266617F, -0.012928578F, 0.024274789F, -0.043076396F,
      0.075450316F, -0.14146252F, 0.37897116F, 0.84351766F, -0.18944162F,
      0.09402805F, -0.053050555F, 0.03022366F, -0.016511986F, 0.008330201F,
      -0.0037181147F, 0.0013690887F, -0.00035150515F, 0.0F, -0.00017556113F,
      0.0008794346F, -0.0026493235F, 0.0063074273F, -0.01300937F, 0.024422344F,
      -0.043334577F, 0.07590537F, -0.14236179F, 0.38206437F, 0.84135896F,
      -0.18996622F, 0.094342425F, -0.053233802F, 0.030326637F, -0.016565941F,
      0.008355547F, -0.0037281583F, 0.0013720156F, -0.00035182637F, 0.0F,
      -0.00017723294F, 0.0008860851F, -0.002667456F, 0.006348038F, -0.013089712F,
      0.024569005F, -0.043591134F, 0.07635763F, -0.14325657F, 0.38515896F,
      0.83918804F, -0.19047894F, 0.094651036F, -0.053413805F, 0.030427748F,
      -0.01661886F, 0.008380357F, -0.003737954F, 0.0013748464F, -0.0003521207F,
      0.0F, -0.00017890622F, 0.0008927196F, -0.0026855164F, 0.006388446F,
      -0.013169596F, 0.024714762F, -0.043846056F, 0.076807104F, -0.14414683F,
      0.38825482F, 0.83700484F, -0.19097978F, 0.09495388F, -0.053590562F,
      0.030526996F, -0.016670743F, 0.008404631F, -0.003747502F, 0.0013775817F,
      -0.00035238828F, 0.0F, -0.00018058083F, 0.00089933764F, -0.002703503F,
      0.006428648F, -0.013249017F, 0.024859605F, -0.044099323F, 0.07725373F,
      -0.14503248F, 0.39135188F, 0.83480954F, -0.19146879F, 0.09525096F,
      -0.05376408F, 0.030624377F, -0.01672159F, 0.008428369F, -0.0037568035F,
      0.0013802217F, -0.0003526293F, 0.0F, -0.00018225663F, 0.00090593874F,
      -0.0027214151F, 0.0064686416F, -0.013327969F, 0.025003523F, -0.044350915F,
      0.07769749F, -0.14591348F, 0.39445004F, 0.83260214F, -0.191946F,
      0.09554227F, -0.053934347F, 0.030719893F, -0.016771398F, 0.008451572F,
      -0.0037658582F, 0.0013827668F, -0.00035284387F, 0.0F, -0.00018393349F,
      0.00091252226F, -0.0027392507F, 0.006508424F, -0.013406446F, 0.025146507F,
      -0.04460082F, 0.07813836F, -0.14678976F, 0.3975492F, 0.83038276F,
      -0.19241141F, 0.09582781F, -0.054101367F, 0.030813541F, -0.016820172F,
      0.00847424F, -0.003774667F, 0.0013852171F, -0.00035303223F, 0.0F,
      -0.00018561126F, 0.0009190878F, -0.0027570087F, 0.0065479917F,
      -0.0134844445F, 0.025288546F, -0.044849012F, 0.07857629F, -0.14766127F,
      0.40064934F, 0.82815146F, -0.19286506F, 0.096107595F, -0.05426514F,
      0.030905325F, -0.01686791F, 0.008496375F, -0.00378323F, 0.0013875731F,
      -0.00035319448F, 0.0F, -0.00018728983F, 0.00092563475F, -0.0027746877F,
      0.006587342F, -0.013561956F, 0.025429629F, -0.04509548F, 0.07901127F,
      -0.14852796F, 0.4037503F, 0.8259083F, -0.19330695F, 0.09638161F,
      -0.054425664F, 0.030995242F, -0.016914612F, 0.008517975F, -0.0037915478F,
      0.001389835F, -0.00035333083F, 0.0F, -0.00018896903F, 0.0009321626F,
      -0.0027922865F, 0.0066264714F, -0.013638976F, 0.025569748F, -0.04534021F,
      0.07944326F, -0.14938976F, 0.40685204F, 0.8236534F, -0.19373713F,
      0.09664987F, -0.054582942F, 0.031083291F, -0.01696028F, 0.008539042F,
      -0.0037996212F, 0.0013920034F, -0.00035344146F, 0.0F, -0.00019064876F,
      0.00093867094F, -0.0028098035F, 0.006665378F, -0.013715498F, 0.025708893F,
      -0.045583177F, 0.07987223F, -0.1502466F, 0.40995443F, 0.8213867F,
      -0.19415562F, 0.09691237F, -0.05473697F, 0.031169476F, -0.017004913F,
      0.008559578F, -0.0038074504F, 0.0013940783F, -0.0003535265F, 0.0F,
      -0.00019232887F, 0.00094515906F, -0.0028272371F, 0.006704058F,
      -0.013791518F, 0.025847051F, -0.045824368F, 0.080298156F, -0.15109845F,
      0.41305745F, 0.81910837F, -0.19456244F, 0.09716911F, -0.054887753F,
      0.031253796F, -0.017048512F, 0.008579581F, -0.003815036F, 0.0013960601F,
      -0.0003535861F, 0.0F, -0.0001940092F, 0.00095162657F, -0.0028445865F,
      0.0067425086F, -0.01386703F, 0.025984216F, -0.046063762F, 0.080721F,
      -0.15194522F, 0.41616094F, 0.8168185F, -0.19495761F, 0.0974201F,
      -0.055035286F, 0.031336248F, -0.017091077F, 0.008599053F, -0.0038223786F,
      0.0013979493F, -0.0003536205F, 0.0F, -0.00019568962F, 0.0009580729F,
      -0.00286185F, 0.0067807273F, -0.013942027F, 0.026120376F, -0.046301346F,
      0.081140734F, -0.15278688F, 0.41926485F, 0.8145171F, -0.19534118F,
      0.09766533F, -0.05517957F, 0.031416837F, -0.017132612F, 0.008617995F,
      -0.0038294785F, 0.001399746F, -0.00035362985F, 0.0F, -0.00019737F,
      0.0009644975F, -0.0028790263F, 0.006818711F, -0.014016504F, 0.02625552F,
      -0.0465371F, 0.08155733F, -0.15362336F, 0.4223691F, 0.81220424F,
      -0.19571315F, 0.09790482F, -0.05532061F, 0.03149556F, -0.017173113F,
      0.008636407F, -0.0038363363F, 0.0014014508F, -0.00035361428F, 0.0F,
      -0.00019905018F, 0.0009708998F, -0.002896114F, 0.006856456F, -0.014090456F,
      0.026389638F, -0.046771012F, 0.081970766F, -0.1544546F, 0.4254736F,
      0.8098801F, -0.19607355F, 0.09813856F, -0.055458404F, 0.03157242F,
      -0.017212583F, 0.00865429F, -0.003842953F, 0.001403064F, -0.00035357403F,
      0.0F, -0.00020073002F, 0.0009772794F, -0.0029131116F, 0.0068939603F,
      -0.014163878F, 0.026522722F, -0.04700306F, 0.082381F, -0.15528055F,
      0.42857823F, 0.8075445F, -0.19642243F, 0.098366566F, -0.05559295F,
      0.031647418F, -0.017251024F, 0.008671644F, -0.0038493285F, 0.0014045859F,
      -0.0003535092F, 0.0F, -0.00020240938F, 0.0009836357F, -0.002930018F,
      0.00693122F, -0.014236762F, 0.026654761F, -0.04723323F, 0.08278801F,
      -0.15610114F, 0.43168294F, 0.80519783F, -0.19675978F, 0.09858884F,
      -0.055724256F, 0.031720556F, -0.017288435F, 0.008688471F, -0.0038554638F,
      0.0014060169F, -0.00035342F, 0.0F, -0.00020408812F, 0.0009899681F,
      -0.0029468315F, 0.0069682333F, -0.0143091045F, 0.026785746F, -0.047461506F,
      0.08319177F, -0.15691632F, 0.43478763F, 0.80284F, -0.19708566F,
      0.09880537F, -0.055852316F, 0.03179183F, -0.017324818F, 0.008704771F,
      -0.0038613593F, 0.0014073572F, -0.00035330665F, 0.0F, -0.00020576609F,
      0.000996276F, -0.002963551F, 0.0070049968F, -0.014380899F, 0.026915666F,
      -0.047687866F, 0.08359223F, -0.15772602F, 0.4378922F, 0.80047107F,
      -0.19740008F, 0.099016175F, -0.055977136F, 0.031861242F, -0.017360173F,
      0.008720545F, -0.003867016F, 0.0014086073F, -0.00035316928F, 0.0F,
      -0.00020744312F, 0.0010025592F, -0.002980175F, 0.0070415074F, -0.01445214F,
      0.027044512F, -0.047912296F, 0.08398938F, -0.1585302F, 0.44099656F,
      0.7980912F, -0.19770308F, 0.09922126F, -0.056098714F, 0.0319288F,
      -0.017394502F, 0.008735795F, -0.0038724341F, 0.0014097678F,
      -0.00035300804F, 0.0F, -0.0002091191F, 0.0010088168F, -0.0029967022F,
      0.007077762F, -0.014522823F, 0.027172275F, -0.04813478F, 0.0843832F,
      -0.1593288F, 0.44410068F, 0.7957003F, -0.19799468F, 0.09942062F,
      -0.05621706F, 0.031994496F, -0.017427806F, 0.008750521F, -0.0038776144F,
      0.0014108387F, -0.00035282318F, 0.0F, -0.00021079385F, 0.0010150485F,
      -0.0030131312F, 0.007113758F, -0.014592941F, 0.027298944F, -0.048355304F,
      0.08477363F, -0.16012175F, 0.44720438F, 0.7932986F, -0.19827493F,
      0.09961427F, -0.056332164F, 0.03205834F, -0.017460085F, 0.008764722F,
      -0.0038825576F, 0.0014118205F, -0.00035261482F, 0.0F, -0.00021246723F,
      0.0010212535F, -0.0030294603F, 0.007149493F, -0.014662489F, 0.027424509F,
      -0.048573844F, 0.085160665F, -0.16090901F, 0.45030764F, 0.7908861F,
      -0.19854383F, 0.09980222F, -0.056444038F, 0.032120325F, -0.017491342F,
      0.008778403F, -0.0038872643F, 0.0014127137F, -0.00035238318F, 0.0F,
      -0.00021413909F, 0.0010274315F, -0.0030456888F, 0.0071849627F,
      -0.014731462F, 0.027548961F, -0.04879039F, 0.08554427F, -0.1616905F,
      0.45341036F, 0.78846294F, -0.19880141F, 0.09998446F, -0.05655268F,
      0.03218046F, -0.017521577F, 0.008791561F, -0.003891735F, 0.0014135186F,
      -0.0003521284F, 0.0F, -0.00021580927F, 0.0010335819F, -0.0030618147F,
      0.007220166F, -0.014799855F, 0.02767229F, -0.049004927F, 0.08592442F,
      -0.16246618F, 0.45651245F, 0.78602916F, -0.19904774F, 0.10016101F,
      -0.05665809F, 0.03223874F, -0.01755079F, 0.0088042F, -0.0038959708F,
      0.0014142356F, -0.0003518507F, 0.0F, -0.00021747763F, 0.0010397041F,
      -0.003077837F, 0.0072550983F, -0.014867661F, 0.027794488F, -0.049217433F,
      0.08630108F, -0.16323599F, 0.4596138F, 0.7835848F, -0.19928281F,
      0.100331865F, -0.056760274F, 0.032295175F, -0.017578987F, 0.0088163195F,
      -0.003899972F, 0.0014148651F, -0.00035155023F, 0.0F, -0.00021914401F,
      0.0010457976F, -0.0030937542F, 0.0072897575F, -0.014934875F, 0.027915543F,
      -0.049427893F, 0.08667422F, -0.16399987F, 0.46271434F, 0.78112996F,
      -0.19950667F, 0.100497045F, -0.056859236F, 0.032349758F, -0.017606165F,
      0.00882792F, -0.0039037394F, 0.0014154075F, -0.00035122718F, 0.0F,
      -0.00022080824F, 0.0010518618F, -0.0031095648F, 0.007324141F,
      -0.015001493F, 0.028035447F, -0.049636293F, 0.087043814F, -0.16475776F,
      0.46581396F, 0.7786647F, -0.19971934F, 0.10065655F, -0.056954976F,
      0.032402497F, -0.017632328F, 0.008839005F, -0.003907274F, 0.0014158632F,
      -0.00035088175F, 0.0F, -0.00022247019F, 0.0010578962F, -0.0031252676F,
      0.007358245F, -0.0150675075F, 0.02815419F, -0.04984262F, 0.08740984F,
      -0.16550961F, 0.4689126F, 0.77618915F, -0.19992088F, 0.10081038F,
      -0.0570475F, 0.032453388F, -0.017657476F, 0.008849572F, -0.003910576F,
      0.0014162326F, -0.0003505141F, 0.0F, -0.00022412969F, 0.0010639002F,
      -0.0031408612F, 0.007392068F, -0.015132914F, 0.028271765F, -0.05004685F,
      0.087772265F, -0.16625535F, 0.47201017F, 0.7737034F, -0.20011128F,
      0.10095855F, -0.057136808F, 0.032502443F, -0.01768161F, 0.008859626F,
      -0.0039136466F, 0.0014165161F, -0.00035012444F, 0.0F, -0.00022578659F,
      0.0010698733F, -0.0031563442F, 0.007425606F, -0.015197708F, 0.028388157F,
      -0.05024897F, 0.08813106F, -0.16699494F, 0.47510657F, 0.7712074F,
      -0.2002906F, 0.10110107F, -0.057222907F, 0.032549653F, -0.017704733F,
      0.008869166F, -0.003916486F, 0.0014167142F, -0.00034971294F, 0.0F,
      -0.00022744072F, 0.0010758151F, -0.0031717152F, 0.0074588563F,
      -0.015261883F, 0.028503362F, -0.050448965F, 0.088486195F, -0.16772832F,
      0.47820172F, 0.7687013F, -0.20045887F, 0.101237945F, -0.057305794F,
      0.032595027F, -0.017726846F, 0.008878193F, -0.0039190957F, 0.0014168272F,
      -0.00034927976F, 0.0F, -0.00022909192F, 0.0010817248F, -0.003186973F,
      0.0074918163F, -0.0153254345F, 0.028617369F, -0.05064682F, 0.088837646F,
      -0.16845542F, 0.48129553F, 0.7661852F, -0.2006161F, 0.10136918F,
      -0.057385482F, 0.032638565F, -0.017747952F, 0.008886709F, -0.0039214757F,
      0.0014168556F, -0.00034882512F, 0.0F, -0.00023074004F, 0.0010876019F,
      -0.0032021161F, 0.0075244834F, -0.0153883565F, 0.028730167F, -0.050842516F,
      0.08918539F, -0.1691762F, 0.48438787F, 0.76365924F, -0.20076238F,
      0.10149479F, -0.057461966F, 0.032680273F, -0.017768051F, 0.0088947145F,
      -0.0039236275F, 0.0014167998F, -0.0003483492F, 0.0F, -0.00023238492F,
      0.0010934459F, -0.003217143F, 0.007556854F, -0.015450643F, 0.02884175F,
      -0.05103604F, 0.08952939F, -0.1698906F, 0.48747873F, 0.76112336F,
      -0.20089768F, 0.10161478F, -0.057535257F, 0.03272015F, -0.017787145F,
      0.008902211F, -0.003925551F, 0.0014166603F, -0.00034785218F, 0.0F,
      -0.00023402639F, 0.0010992562F, -0.0032320525F, 0.007588926F,
      -0.015512291F, 0.028952107F, -0.05122738F, 0.08986962F, -0.17059854F,
      0.49056795F, 0.7585777F, -0.20102207F, 0.10172916F, -0.057605352F,
      0.0327582F, -0.01780524F, 0.0089092F, -0.003927248F, 0.0014164373F,
      -0.00034733422F, 0.0F, -0.0002356643F, 0.0011050324F, -0.0032468433F,
      0.007620696F, -0.015573293F, 0.029061228F, -0.051416513F, 0.09020605F,
      -0.1713F, 0.49365547F, 0.75602233F, -0.20113558F, 0.10183794F,
      -0.057672262F, 0.032794423F, -0.01782233F, 0.008915684F, -0.003928719F,
      0.0014161315F, -0.00034679557F, 0.0F, -0.00023729846F, 0.0011107738F,
      -0.003261514F, 0.0076521616F, -0.015633645F, 0.029169105F, -0.051603425F,
      0.090538666F, -0.1719949F, 0.49674124F, 0.7534573F, -0.20123823F,
      0.10194113F, -0.05773599F, 0.032828826F, -0.017838422F, 0.008921662F,
      -0.0039299643F, 0.0014157433F, -0.00034623637F, 0.0F, -0.00023892874F,
      0.0011164799F, -0.0032760631F, 0.00768332F, -0.015693342F, 0.029275728F,
      -0.051788107F, 0.09086742F, -0.1726832F, 0.4998251F, 0.7508828F,
      -0.20133008F, 0.10203874F, -0.057796538F, 0.032861408F, -0.017853519F,
      0.008927137F, -0.0039309855F, 0.001415273F, -0.0003456568F, 0.0F,
      -0.00024055495F, 0.0011221501F, -0.0032904895F, 0.007714168F,
      -0.015752377F, 0.029381089F, -0.051970534F, 0.09119231F, -0.17336482F,
      0.502907F, 0.7482988F, -0.20141114F, 0.10213078F, -0.057853915F,
      0.032892175F, -0.017867621F, 0.00893211F, -0.0039317827F, 0.001414721F,
      -0.00034505708F, 0.0F, -0.00024217693F, 0.0011277839F, -0.0033047916F,
      0.0077447034F, -0.015810747F, 0.02948518F, -0.0521507F, 0.09151329F,
      -0.17403974F, 0.5059868F, 0.7457054F, -0.20148146F, 0.10221725F,
      -0.05790812F, 0.03292113F, -0.01788073F, 0.008936581F, -0.0039323573F,
      0.0014140881F, -0.00034443737F, 0.0F, -0.00024379452F, 0.0011333807F,
      -0.0033189682F, 0.007774923F, -0.015868446F, 0.02958799F, -0.052328583F,
      0.09183034F, -0.17470786F, 0.5090645F, 0.7431027F, -0.20154108F,
      0.10229817F, -0.057959165F, 0.032948274F, -0.01789285F, 0.008940554F,
      -0.00393271F, 0.0014133743F, -0.0003437979F, 0.0F, -0.00024540754F,
      0.00113894F, -0.003333018F, 0.007804824F, -0.015925469F, 0.02968951F,
      -0.052504174F, 0.09214344F, -0.17536917F, 0.51214F, 0.7404908F,
      -0.20159003F, 0.102373555F, -0.05800705F, 0.032973614F, -0.017903982F,
      0.008944029F, -0.003932841F, 0.0014125804F, -0.00034313882F, 0.0F,
      -0.00024701585F, 0.0011444612F, -0.003346939F, 0.007834404F, -0.01598181F,
      0.029789733F, -0.052677453F, 0.09245255F, -0.17602359F, 0.5152131F,
      0.7378697F, -0.20162834F, 0.10244341F, -0.05805178F, 0.03299715F,
      -0.017914126F, 0.008947006F, -0.003932752F, 0.0014117067F, -0.00034246032F,
      0.0F, -0.00024861927F, 0.0011499437F, -0.0033607308F, 0.007863659F,
      -0.016037466F, 0.029888649F, -0.052848402F, 0.09275765F, -0.17667106F,
      0.5182838F, 0.73523957F, -0.20165607F, 0.10250775F, -0.058093365F,
      0.033018887F, -0.017923288F, 0.00894949F, -0.003932444F, 0.0014107536F,
      -0.0003417626F, 0.0F, -0.0002502176F, 0.001155387F, -0.0033743917F,
      0.007892588F, -0.016092429F, 0.029986247F, -0.053017017F, 0.09305871F,
      -0.17731154F, 0.52135205F, 0.7326004F, -0.20167324F, 0.10256658F,
      -0.058131807F, 0.03303883F, -0.017931469F, 0.00895148F, -0.0039319177F,
      0.0014097217F, -0.0003410459F, 0.0F, -0.0002518107F, 0.0011607907F,
      -0.0033879203F, 0.007921188F, -0.016146695F, 0.030082524F, -0.053183276F,
      0.09335571F, -0.17794496F, 0.52441764F, 0.7299524F, -0.20167989F,
      0.102619916F, -0.058167115F, 0.033056974F, -0.01793867F, 0.008952978F,
      -0.0039311736F, 0.0014086113F, -0.00034031033F, 0.0F, -0.0002533984F,
      0.0011661539F, -0.003401315F, 0.007949456F, -0.016200261F, 0.030177467F,
      -0.053347163F, 0.09364863F, -0.17857128F, 0.5274806F, 0.7272955F,
      -0.20167604F, 0.10266777F, -0.058199294F, 0.033073336F, -0.017944897F,
      0.008953986F, -0.003930213F, 0.0014074232F, -0.0003395561F, 0.0F,
      -0.00025498052F, 0.0011714763F, -0.003414575F, 0.007977388F, -0.01625312F,
      0.030271068F, -0.053508665F, 0.09393742F, -0.17919044F, 0.53054076F,
      0.7246299F, -0.20166177F, 0.10271015F, -0.058228347F, 0.03308791F,
      -0.017950147F, 0.0089545045F, -0.003929036F, 0.0014061574F,
      -0.00033878343F, 0.0F, -0.00025655687F, 0.0011767573F, -0.0034276985F,
      0.008004982F, -0.016305268F, 0.03036332F, -0.053667773F, 0.09422208F,
      -0.17980237F, 0.53359807F, 0.72195566F, -0.20163707F, 0.102747075F,
      -0.058254283F, 0.033100702F, -0.017954428F, 0.008954536F, -0.0039276453F,
      0.0014048148F, -0.0003379925F, 0.0F, -0.00025812731F, 0.0011819963F,
      -0.0034406846F, 0.008032236F, -0.0163567F, 0.030454213F, -0.053824466F,
      0.094502576F, -0.18040705F, 0.53665245F, 0.7192728F, -0.20160203F,
      0.10277856F, -0.058277108F, 0.033111718F, -0.01795774F, 0.008954083F,
      -0.00392604F, 0.0014033956F, -0.0003371835F, 0.0F, -0.00025969167F,
      0.0011871927F, -0.0034535315F, 0.008059147F, -0.016407408F, 0.030543739F,
      -0.05397873F, 0.09477887F, -0.18100439F, 0.5397038F, 0.7165814F,
      -0.20155665F, 0.10280461F, -0.05829683F, 0.033120964F, -0.017960085F,
      0.008953145F, -0.0039242227F, 0.0014019003F, -0.0003363566F, 0.0F,
      -0.00026124975F, 0.0011923461F, -0.0034662383F, 0.008085713F,
      -0.016457392F, 0.030631889F, -0.054130554F, 0.09505096F, -0.18159437F,
      0.542752F, 0.7138817F, -0.201501F, 0.10282524F, -0.058313455F,
      0.033128437F, -0.017961467F, 0.008951725F, -0.003922193F, 0.0014003296F,
      -0.000335512F, 0.0F, -0.00026280136F, 0.0011974558F, -0.0034788032F,
      0.0081119295F, -0.016506644F, 0.030718656F, -0.054279923F, 0.0953188F,
      -0.1821769F, 0.545797F, 0.71117353F, -0.20143509F, 0.10284047F,
      -0.05832699F, 0.033134148F, -0.01796189F, 0.008949826F, -0.003919952F,
      0.0013986838F, -0.00033464993F, 0.0F, -0.00026434637F, 0.0012025214F,
      -0.0034912254F, 0.008137795F, -0.01655516F, 0.03080403F, -0.054426823F,
      0.09558238F, -0.18275195F, 0.5488387F, 0.7084572F, -0.20135897F,
      0.1028503F, -0.05833744F, 0.0331381F, -0.017961353F, 0.008947446F,
      -0.003917502F, 0.0013969634F, -0.00033377056F, 0.0F, -0.00026588456F,
      0.0012075421F, -0.0035035033F, 0.008163308F, -0.016602937F, 0.030888004F,
      -0.054571237F, 0.09584167F, -0.18331946F, 0.55187696F, 0.7057327F,
      -0.2012727F, 0.102854766F, -0.05834481F, 0.033140294F, -0.017959861F,
      0.008944591F, -0.0039148424F, 0.0013951688F, -0.00033287404F, 0.0F,
      -0.0002674158F, 0.0012125175F, -0.0035156356F, 0.008188463F, -0.016649967F,
      0.030970572F, -0.054713156F, 0.09609664F, -0.18387938F, 0.5549118F,
      0.70300007F, -0.20117629F, 0.10285386F, -0.058349118F, 0.033140738F,
      -0.017957417F, 0.008941259F, -0.003911975F, 0.0013933007F, -0.00033196062F,
      0.0F, -0.00026893985F, 0.001217447F, -0.003527621F, 0.00821326F,
      -0.016696246F, 0.03105172F, -0.05485256F, 0.09634727F, -0.18443166F,
      0.557943F, 0.70025945F, -0.2010698F, 0.102847606F, -0.058350362F,
      0.033139434F, -0.017954024F, 0.008937455F, -0.0039089005F, 0.0013913596F,
      -0.00033103046F, 0.0F, -0.0002704566F, 0.0012223301F, -0.0035394584F,
      0.008237695F, -0.016741771F, 0.031131444F, -0.054989442F, 0.09659354F,
      -0.18497622F, 0.5609706F, 0.6975109F, -0.20095329F, 0.10283601F,
      -0.05834855F, 0.03313639F, -0.017949685F, 0.008933178F, -0.00390562F,
      0.0013893457F, -0.00033008377F, 0.0F, -0.00027196584F, 0.0012271662F,
      -0.003551146F, 0.008261765F, -0.016786536F, 0.031209735F, -0.055123787F,
      0.09683542F, -0.18551305F, 0.5639944F, 0.69475454F, -0.20082676F,
      0.10281911F, -0.058343694F, 0.033131607F, -0.017944403F, 0.008928432F,
      -0.0039021347F, 0.0013872598F, -0.00032912072F, 0.0F, -0.0002734674F,
      0.0012319548F, -0.003562683F, 0.00828547F, -0.016830537F, 0.031286586F,
      -0.055255577F, 0.097072884F, -0.18604207F, 0.5670144F, 0.69199044F,
      -0.20069027F, 0.1027969F, -0.0583358F, 0.03312509F, -0.017938178F,
      0.008923218F, -0.0038984455F, 0.0013851022F, -0.00032814153F, 0.0F,
      -0.00027496106F, 0.0012366952F, -0.003574068F, 0.008308805F, -0.01687377F,
      0.03136199F, -0.055384807F, 0.09730591F, -0.18656322F, 0.57003045F,
      0.68921864F, -0.20054388F, 0.10276939F, -0.058324873F, 0.03311685F,
      -0.017931018F, 0.0089175375F, -0.0038945533F, 0.0013828735F,
      -0.00032714635F, 0.0F, -0.0002764467F, 0.001241387F, -0.0035852995F,
      0.008331767F, -0.016916227F, 0.031435933F, -0.055511456F, 0.09753448F,
      -0.18707646F, 0.5730425F, 0.6864393F, -0.20038761F, 0.102736615F,
      -0.058310926F, 0.033106886F, -0.017922923F, 0.008911393F, -0.0038904594F,
      0.0013805742F, -0.00032613543F, 0.0F, -0.0002779241F, 0.0012460295F,
      -0.0035963764F, 0.008354356F, -0.016957907F, 0.031508416F, -0.055635512F,
      0.09775856F, -0.18758176F, 0.5760504F, 0.6836524F, -0.20022151F,
      0.10269859F, -0.058293965F, 0.0330952F, -0.017913898F, 0.008904786F,
      -0.0038861649F, 0.0013782048F, -0.0003251089F, 0.0F, -0.00027939308F,
      0.0012506223F, -0.0036072973F, 0.008376567F, -0.016998803F, 0.031579424F,
      -0.055756964F, 0.09797814F, -0.18807903F, 0.5790542F, 0.68085814F,
      -0.20004562F, 0.102655314F, -0.058273997F, 0.033081807F, -0.017903944F,
      0.008897718F, -0.0038816705F, 0.0013757658F, -0.00032406702F, 0.0F,
      -0.00028085348F, 0.0012551649F, -0.003618061F, 0.008398399F, -0.017038913F,
      0.031648953F, -0.0558758F, 0.09819319F, -0.18856823F, 0.5820536F,
      0.6780565F, -0.19985999F, 0.10260681F, -0.058251034F, 0.0330667F,
      -0.017893067F, 0.008890192F, -0.0038769774F, 0.0013732576F,
      -0.00032300994F, 0.0F, -0.00028230512F, 0.0012596565F, -0.0036286663F,
      0.008419848F, -0.017078232F, 0.031716995F, -0.055992007F, 0.098403685F,
      -0.18904932F, 0.5850487F, 0.6752476F, -0.19966467F, 0.1025531F,
      -0.05822508F, 0.033049896F, -0.017881267F, 0.00888221F, -0.0038720868F,
      0.001370681F, -0.00032193787F, 0.0F, -0.00028374777F, 0.0012640967F,
      -0.0036391118F, 0.008440913F, -0.017116753F, 0.031783544F, -0.05610557F,
      0.0986096F, -0.18952224F, 0.58803934F, 0.6724316F, -0.19945969F,
      0.1024942F, -0.05819615F, 0.033031397F, -0.017868549F, 0.008873773F,
      -0.0038669999F, 0.0013680363F, -0.00032085096F, 0.0F, -0.00028518128F,
      0.0012684849F, -0.0036493964F, 0.008461591F, -0.017154474F, 0.031848587F,
      -0.056216475F, 0.09881092F, -0.18998694F, 0.5910254F, 0.66960853F,
      -0.19924508F, 0.10243013F, -0.05816425F, 0.0330112F, -0.017854918F,
      0.008864883F, -0.0038617174F, 0.0013653239F, -0.00031974947F, 0.0F,
      -0.00028660547F, 0.0012728205F, -0.0036595184F, 0.008481879F,
      -0.017191388F, 0.031912122F, -0.056324713F, 0.099007614F, -0.19044337F,
      0.59400684F, 0.66677845F, -0.19902092F, 0.10236089F, -0.058129385F,
      0.032989323F, -0.017840374F, 0.008855543F, -0.0038562405F, 0.0013625446F,
      -0.00031863354F, 0.0F, -0.00028802018F, 0.0012771031F, -0.003669477F,
      0.008501776F, -0.017227495F, 0.03197414F, -0.056430273F, 0.09919967F,
      -0.19089147F, 0.59698355F, 0.66394144F, -0.19878724F, 0.10228651F,
      -0.058091573F, 0.032965764F, -0.017824924F, 0.008845754F, -0.0038505706F,
      0.0013596987F, -0.00031750335F, 0.0F, -0.00028942517F, 0.0012813321F,
      -0.0036792709F, 0.008521277F, -0.017262787F, 0.03203463F, -0.05653314F,
      0.09938705F, -0.19133121F, 0.59995544F, 0.66109765F, -0.19854409F,
      0.10220701F, -0.058050815F, 0.032940533F, -0.017808568F, 0.008835519F,
      -0.0038447084F, 0.0013567869F, -0.00031635916F, 0.0F, -0.0002908203F,
      0.0012855069F, -0.0036888986F, 0.008540382F, -0.01729726F, 0.032093592F,
      -0.0566333F, 0.09956975F, -0.19176252F, 0.60292244F, 0.65824705F,
      -0.1982915F, 0.1021224F, -0.058007125F, 0.03291363F, -0.01779131F,
      0.008824839F, -0.0038386555F, 0.0013538096F, -0.0003152011F, 0.0F,
      -0.0002922053F, 0.0012896269F, -0.003698359F, 0.008559087F, -0.017330911F,
      0.032151017F, -0.056730747F, 0.09974774F, -0.19218536F, 0.60588443F,
      0.6553899F, -0.19802952F, 0.102032706F, -0.05796051F, 0.032885067F,
      -0.017773157F, 0.008813717F, -0.0038324127F, 0.0013507673F, -0.0003140294F,
      0.0F, -0.00029358012F, 0.0012936917F, -0.003707651F, 0.0085773915F,
      -0.017363736F, 0.032206893F, -0.056825463F, 0.099920996F, -0.19259967F,
      0.60884136F, 0.65252614F, -0.19775821F, 0.10193794F, -0.057910983F,
      0.032854844F, -0.017754111F, 0.008802155F, -0.0038259812F, 0.0013476606F,
      -0.0003128442F, 0.0F, -0.00029494448F, 0.0012977007F, -0.0037167731F,
      0.0085952915F, -0.01739573F, 0.032261215F, -0.056917436F, 0.100089505F,
      -0.19300541F, 0.6117931F, 0.6496559F, -0.1974776F, 0.10183813F,
      -0.057858553F, 0.03282297F, -0.017734174F, 0.008790155F, -0.0038193618F,
      0.00134449F, -0.00031164577F, 0.0F, -0.0002962982F, 0.0013016532F,
      -0.0037257243F, 0.008612785F, -0.017426888F, 0.032313976F, -0.05700666F,
      0.10025323F, -0.19340253F, 0.61473966F, 0.6467793F, -0.19718774F,
      0.101733275F, -0.05780323F, 0.032789454F, -0.017713351F, 0.008777719F,
      -0.0038125564F, 0.0013412561F, -0.00031043423F, 0.0F, -0.00029764112F,
      0.0013055488F, -0.0037345032F, 0.008629869F, -0.017457208F, 0.032365173F,
      -0.057093117F, 0.10041217F, -0.19379097F, 0.6176808F, 0.64389634F,
      -0.19688869F, 0.10162341F, -0.05774502F, 0.032754295F, -0.017691644F,
      0.008764849F, -0.0038055654F, 0.0013379593F, -0.0003092098F, 0.0F,
      -0.00029897306F, 0.001309387F, -0.0037431088F, 0.008646542F, -0.017486682F,
      0.032414794F, -0.057176802F, 0.10056628F, -0.1941707F, 0.6206165F,
      0.6410072F, -0.19658048F, 0.10150855F, -0.057683937F, 0.032717507F,
      -0.01766906F, 0.008751548F, -0.0037983905F, 0.0013346003F, -0.00030797266F,
      0.0F, -0.0003002938F, 0.0013131673F, -0.0037515396F, 0.008662802F,
      -0.017515311F, 0.03246283F, -0.0572577F, 0.10071557F, -0.19454165F,
      0.6235467F, 0.63811195F, -0.19626316F, 0.101388715F, -0.057619993F,
      0.03267909F, -0.0176456F, 0.008737817F, -0.0037910326F, 0.0013311794F,
      -0.00030672303F, 0.0F, -0.00030160314F, 0.001316889F, -0.0037597946F,
      0.008678646F, -0.017543089F, 0.032509286F, -0.057335798F, 0.10085999F,
      -0.19490378F, 0.62647134F, 0.63521063F, -0.19593678F, 0.10126392F,
      -0.0575532F, 0.032639053F, -0.01762127F, 0.008723659F, -0.0037834928F,
      0.0013276973F, -0.00030546106F, 0.0F, -0.00030290094F, 0.0013205515F,
      -0.0037678727F, 0.008694071F, -0.01757001F, 0.032554146F, -0.05741109F,
      0.10099954F, -0.19525705F, 0.62939024F, 0.63230336F, -0.1956014F,
      0.10113419F, -0.057483558F, 0.032597404F, -0.017596072F, 0.008709077F,
      -0.0037757724F, 0.0013241544F, -0.00030418698F, 0.0F, -0.00030418698F,
      0.0013241544F, -0.0037757724F, 0.008709077F, -0.017596072F, 0.032597404F,
      -0.057483558F, 0.10113419F, -0.1956014F, 0.63230336F, 0.62939024F,
      -0.19525705F, 0.10099954F, -0.05741109F, 0.032554146F, -0.01757001F,
      0.008694071F, -0.0037678727F, 0.0013205515F, -0.00030290094F, 0.0F,
      -0.00030546106F, 0.0013276973F, -0.0037834928F, 0.008723659F, -0.01762127F,
      0.032639053F, -0.0575532F, 0.10126392F, -0.19593678F, 0.63521063F,
      0.62647134F, -0.19490378F, 0.10085999F, -0.057335798F, 0.032509286F,
      -0.017543089F, 0.008678646F, -0.0037597946F, 0.001316889F, -0.00030160314F,
      0.0F, -0.00030672303F, 0.0013311794F, -0.0037910326F, 0.008737817F,
      -0.0176456F, 0.03267909F, -0.057619993F, 0.101388715F, -0.19626316F,
      0.63811195F, 0.6235467F, -0.19454165F, 0.10071557F, -0.0572577F,
      0.03246283F, -0.017515311F, 0.008662802F, -0.0037515396F, 0.0013131673F,
      -0.0003002938F, 0.0F, -0.00030797266F, 0.0013346003F, -0.0037983905F,
      0.008751548F, -0.01766906F, 0.032717507F, -0.057683937F, 0.10150855F,
      -0.19658048F, 0.6410072F, 0.6206165F, -0.1941707F, 0.10056628F,
      -0.057176802F, 0.032414794F, -0.017486682F, 0.008646542F, -0.0037431088F,
      0.001309387F, -0.00029897306F, 0.0F, -0.0003092098F, 0.0013379593F,
      -0.0038055654F, 0.008764849F, -0.017691644F, 0.032754295F, -0.05774502F,
      0.10162341F, -0.19688869F, 0.64389634F, 0.6176808F, -0.19379097F,
      0.10041217F, -0.057093117F, 0.032365173F, -0.017457208F, 0.008629869F,
      -0.0037345032F, 0.0013055488F, -0.00029764112F, 0.0F, -0.00031043423F,
      0.0013412561F, -0.0038125564F, 0.008777719F, -0.017713351F, 0.032789454F,
      -0.05780323F, 0.101733275F, -0.19718774F, 0.6467793F, 0.61473966F,
      -0.19340253F, 0.10025323F, -0.05700666F, 0.032313976F, -0.017426888F,
      0.008612785F, -0.0037257243F, 0.0013016532F, -0.0002962982F, 0.0F,
      -0.00031164577F, 0.00134449F, -0.0038193618F, 0.008790155F, -0.017734174F,
      0.03282297F, -0.057858553F, 0.10183813F, -0.1974776F, 0.6496559F,
      0.6117931F, -0.19300541F, 0.100089505F, -0.056917436F, 0.032261215F,
      -0.01739573F, 0.0085952915F, -0.0037167731F, 0.0012977007F,
      -0.00029494448F, 0.0F, -0.0003128442F, 0.0013476606F, -0.0038259812F,
      0.008802155F, -0.017754111F, 0.032854844F, -0.057910983F, 0.10193794F,
      -0.19775821F, 0.65252614F, 0.60884136F, -0.19259967F, 0.099920996F,
      -0.056825463F, 0.032206893F, -0.017363736F, 0.0085773915F, -0.003707651F,
      0.0012936917F, -0.00029358012F, 0.0F, -0.0003140294F, 0.0013507673F,
      -0.0038324127F, 0.008813717F, -0.017773157F, 0.032885067F, -0.05796051F,
      0.102032706F, -0.19802952F, 0.6553899F, 0.60588443F, -0.19218536F,
      0.09974774F, -0.056730747F, 0.032151017F, -0.017330911F, 0.008559087F,
      -0.003698359F, 0.0012896269F, -0.0002922053F, 0.0F, -0.0003152011F,
      0.0013538096F, -0.0038386555F, 0.008824839F, -0.01779131F, 0.03291363F,
      -0.058007125F, 0.1021224F, -0.1982915F, 0.65824705F, 0.60292244F,
      -0.19176252F, 0.09956975F, -0.0566333F, 0.032093592F, -0.01729726F,
      0.008540382F, -0.0036888986F, 0.0012855069F, -0.0002908203F, 0.0F,
      -0.00031635916F, 0.0013567869F, -0.0038447084F, 0.008835519F,
      -0.017808568F, 0.032940533F, -0.058050815F, 0.10220701F, -0.19854409F,
      0.66109765F, 0.59995544F, -0.19133121F, 0.09938705F, -0.05653314F,
      0.03203463F, -0.017262787F, 0.008521277F, -0.0036792709F, 0.0012813321F,
      -0.00028942517F, 0.0F, -0.00031750335F, 0.0013596987F, -0.0038505706F,
      0.008845754F, -0.017824924F, 0.032965764F, -0.058091573F, 0.10228651F,
      -0.19878724F, 0.66394144F, 0.59698355F, -0.19089147F, 0.09919967F,
      -0.056430273F, 0.03197414F, -0.017227495F, 0.008501776F, -0.003669477F,
      0.0012771031F, -0.00028802018F, 0.0F, -0.00031863354F, 0.0013625446F,
      -0.0038562405F, 0.008855543F, -0.017840374F, 0.032989323F, -0.058129385F,
      0.10236089F, -0.19902092F, 0.66677845F, 0.59400684F, -0.19044337F,
      0.099007614F, -0.056324713F, 0.031912122F, -0.017191388F, 0.008481879F,
      -0.0036595184F, 0.0012728205F, -0.00028660547F, 0.0F, -0.00031974947F,
      0.0013653239F, -0.0038617174F, 0.008864883F, -0.017854918F, 0.0330112F,
      -0.05816425F, 0.10243013F, -0.19924508F, 0.66960853F, 0.5910254F,
      -0.18998694F, 0.09881092F, -0.056216475F, 0.031848587F, -0.017154474F,
      0.008461591F, -0.0036493964F, 0.0012684849F, -0.00028518128F, 0.0F,
      -0.00032085096F, 0.0013680363F, -0.0038669999F, 0.008873773F,
      -0.017868549F, 0.033031397F, -0.05819615F, 0.1024942F, -0.19945969F,
      0.6724316F, 0.58803934F, -0.18952224F, 0.0986096F, -0.05610557F,
      0.031783544F, -0.017116753F, 0.008440913F, -0.0036391118F, 0.0012640967F,
      -0.00028374777F, 0.0F, -0.00032193787F, 0.001370681F, -0.0038720868F,
      0.00888221F, -0.017881267F, 0.033049896F, -0.05822508F, 0.1025531F,
      -0.19966467F, 0.6752476F, 0.5850487F, -0.18904932F, 0.098403685F,
      -0.055992007F, 0.031716995F, -0.017078232F, 0.008419848F, -0.0036286663F,
      0.0012596565F, -0.00028230512F, 0.0F, -0.00032300994F, 0.0013732576F,
      -0.0038769774F, 0.008890192F, -0.017893067F, 0.0330667F, -0.058251034F,
      0.10260681F, -0.19985999F, 0.6780565F, 0.5820536F, -0.18856823F,
      0.09819319F, -0.0558758F, 0.031648953F, -0.017038913F, 0.008398399F,
      -0.003618061F, 0.0012551649F, -0.00028085348F, 0.0F, -0.00032406702F,
      0.0013757658F, -0.0038816705F, 0.008897718F, -0.017903944F, 0.033081807F,
      -0.058273997F, 0.102655314F, -0.20004562F, 0.68085814F, 0.5790542F,
      -0.18807903F, 0.09797814F, -0.055756964F, 0.031579424F, -0.016998803F,
      0.008376567F, -0.0036072973F, 0.0012506223F, -0.00027939308F, 0.0F,
      -0.0003251089F, 0.0013782048F, -0.0038861649F, 0.008904786F, -0.017913898F,
      0.0330952F, -0.058293965F, 0.10269859F, -0.20022151F, 0.6836524F,
      0.5760504F, -0.18758176F, 0.09775856F, -0.055635512F, 0.031508416F,
      -0.016957907F, 0.008354356F, -0.0035963764F, 0.0012460295F, -0.0002779241F,
      0.0F, -0.00032613543F, 0.0013805742F, -0.0038904594F, 0.008911393F,
      -0.017922923F, 0.033106886F, -0.058310926F, 0.102736615F, -0.20038761F,
      0.6864393F, 0.5730425F, -0.18707646F, 0.09753448F, -0.055511456F,
      0.031435933F, -0.016916227F, 0.008331767F, -0.0035852995F, 0.001241387F,
      -0.0002764467F, 0.0F, -0.00032714635F, 0.0013828735F, -0.0038945533F,
      0.0089175375F, -0.017931018F, 0.03311685F, -0.058324873F, 0.10276939F,
      -0.20054388F, 0.68921864F, 0.57003045F, -0.18656322F, 0.09730591F,
      -0.055384807F, 0.03136199F, -0.01687377F, 0.008308805F, -0.003574068F,
      0.0012366952F, -0.00027496106F, 0.0F, -0.00032814153F, 0.0013851022F,
      -0.0038984455F, 0.008923218F, -0.017938178F, 0.03312509F, -0.0583358F,
      0.1027969F, -0.20069027F, 0.69199044F, 0.5670144F, -0.18604207F,
      0.097072884F, -0.055255577F, 0.031286586F, -0.016830537F, 0.00828547F,
      -0.003562683F, 0.0012319548F, -0.0002734674F, 0.0F, -0.00032912072F,
      0.0013872598F, -0.0039021347F, 0.008928432F, -0.017944403F, 0.033131607F,
      -0.058343694F, 0.10281911F, -0.20082676F, 0.69475454F, 0.5639944F,
      -0.18551305F, 0.09683542F, -0.055123787F, 0.031209735F, -0.016786536F,
      0.008261765F, -0.003551146F, 0.0012271662F, -0.00027196584F, 0.0F,
      -0.00033008377F, 0.0013893457F, -0.00390562F, 0.008933178F, -0.017949685F,
      0.03313639F, -0.05834855F, 0.10283601F, -0.20095329F, 0.6975109F,
      0.5609706F, -0.18497622F, 0.09659354F, -0.054989442F, 0.031131444F,
      -0.016741771F, 0.008237695F, -0.0035394584F, 0.0012223301F, -0.0002704566F,
      0.0F, -0.00033103046F, 0.0013913596F, -0.0039089005F, 0.008937455F,
      -0.017954024F, 0.033139434F, -0.058350362F, 0.102847606F, -0.2010698F,
      0.70025945F, 0.557943F, -0.18443166F, 0.09634727F, -0.05485256F,
      0.03105172F, -0.016696246F, 0.00821326F, -0.003527621F, 0.001217447F,
      -0.00026893985F, 0.0F, -0.00033196062F, 0.0013933007F, -0.003911975F,
      0.008941259F, -0.017957417F, 0.033140738F, -0.058349118F, 0.10285386F,
      -0.20117629F, 0.70300007F, 0.5549118F, -0.18387938F, 0.09609664F,
      -0.054713156F, 0.030970572F, -0.016649967F, 0.008188463F, -0.0035156356F,
      0.0012125175F, -0.0002674158F, 0.0F, -0.00033287404F, 0.0013951688F,
      -0.0039148424F, 0.008944591F, -0.017959861F, 0.033140294F, -0.05834481F,
      0.102854766F, -0.2012727F, 0.7057327F, 0.55187696F, -0.18331946F,
      0.09584167F, -0.054571237F, 0.030888004F, -0.016602937F, 0.008163308F,
      -0.0035035033F, 0.0012075421F, -0.00026588456F, 0.0F, -0.00033377056F,
      0.0013969634F, -0.003917502F, 0.008947446F, -0.017961353F, 0.0331381F,
      -0.05833744F, 0.1028503F, -0.20135897F, 0.7084572F, 0.5488387F,
      -0.18275195F, 0.09558238F, -0.054426823F, 0.03080403F, -0.01655516F,
      0.008137795F, -0.0034912254F, 0.0012025214F, -0.00026434637F, 0.0F,
      -0.00033464993F, 0.0013986838F, -0.003919952F, 0.008949826F, -0.01796189F,
      0.033134148F, -0.05832699F, 0.10284047F, -0.20143509F, 0.71117353F,
      0.545797F, -0.1821769F, 0.0953188F, -0.054279923F, 0.030718656F,
      -0.016506644F, 0.0081119295F, -0.0034788032F, 0.0011974558F,
      -0.00026280136F, 0.0F, -0.000335512F, 0.0014003296F, -0.003922193F,
      0.008951725F, -0.017961467F, 0.033128437F, -0.058313455F, 0.10282524F,
      -0.201501F, 0.7138817F, 0.542752F, -0.18159437F, 0.09505096F,
      -0.054130554F, 0.030631889F, -0.016457392F, 0.008085713F, -0.0034662383F,
      0.0011923461F, -0.00026124975F, 0.0F, -0.0003363566F, 0.0014019003F,
      -0.0039242227F, 0.008953145F, -0.017960085F, 0.033120964F, -0.05829683F,
      0.10280461F, -0.20155665F, 0.7165814F, 0.5397038F, -0.18100439F,
      0.09477887F, -0.05397873F, 0.030543739F, -0.016407408F, 0.008059147F,
      -0.0034535315F, 0.0011871927F, -0.00025969167F, 0.0F, -0.0003371835F,
      0.0014033956F, -0.00392604F, 0.008954083F, -0.01795774F, 0.033111718F,
      -0.058277108F, 0.10277856F, -0.20160203F, 0.7192728F, 0.53665245F,
      -0.18040705F, 0.094502576F, -0.053824466F, 0.030454213F, -0.0163567F,
      0.008032236F, -0.0034406846F, 0.0011819963F, -0.00025812731F, 0.0F,
      -0.0003379925F, 0.0014048148F, -0.0039276453F, 0.008954536F, -0.017954428F,
      0.033100702F, -0.058254283F, 0.102747075F, -0.20163707F, 0.72195566F,
      0.53359807F, -0.17980237F, 0.09422208F, -0.053667773F, 0.03036332F,
      -0.016305268F, 0.008004982F, -0.0034276985F, 0.0011767573F,
      -0.00025655687F, 0.0F, -0.00033878343F, 0.0014061574F, -0.003929036F,
      0.0089545045F, -0.017950147F, 0.03308791F, -0.058228347F, 0.10271015F,
      -0.20166177F, 0.7246299F, 0.53054076F, -0.17919044F, 0.09393742F,
      -0.053508665F, 0.030271068F, -0.01625312F, 0.007977388F, -0.003414575F,
      0.0011714763F, -0.00025498052F, 0.0F, -0.0003395561F, 0.0014074232F,
      -0.003930213F, 0.008953986F, -0.017944897F, 0.033073336F, -0.058199294F,
      0.10266777F, -0.20167604F, 0.7272955F, 0.5274806F, -0.17857128F,
      0.09364863F, -0.053347163F, 0.030177467F, -0.016200261F, 0.007949456F,
      -0.003401315F, 0.0011661539F, -0.0002533984F, 0.0F, -0.00034031033F,
      0.0014086113F, -0.0039311736F, 0.008952978F, -0.01793867F, 0.033056974F,
      -0.058167115F, 0.102619916F, -0.20167989F, 0.7299524F, 0.52441764F,
      -0.17794496F, 0.09335571F, -0.053183276F, 0.030082524F, -0.016146695F,
      0.007921188F, -0.0033879203F, 0.0011607907F, -0.0002518107F, 0.0F,
      -0.0003410459F, 0.0014097217F, -0.0039319177F, 0.00895148F, -0.017931469F,
      0.03303883F, -0.058131807F, 0.10256658F, -0.20167324F, 0.7326004F,
      0.52135205F, -0.17731154F, 0.09305871F, -0.053017017F, 0.029986247F,
      -0.016092429F, 0.007892588F, -0.0033743917F, 0.001155387F, -0.0002502176F,
      0.0F, -0.0003417626F, 0.0014107536F, -0.003932444F, 0.00894949F,
      -0.017923288F, 0.033018887F, -0.058093365F, 0.10250775F, -0.20165607F,
      0.73523957F, 0.5182838F, -0.17667106F, 0.09275765F, -0.052848402F,
      0.029888649F, -0.016037466F, 0.007863659F, -0.0033607308F, 0.0011499437F,
      -0.00024861927F, 0.0F, -0.00034246032F, 0.0014117067F, -0.003932752F,
      0.008947006F, -0.017914126F, 0.03299715F, -0.05805178F, 0.10244341F,
      -0.20162834F, 0.7378697F, 0.5152131F, -0.17602359F, 0.09245255F,
      -0.052677453F, 0.029789733F, -0.01598181F, 0.007834404F, -0.003346939F,
      0.0011444612F, -0.00024701585F, 0.0F, -0.00034313882F, 0.0014125804F,
      -0.003932841F, 0.008944029F, -0.017903982F, 0.032973614F, -0.05800705F,
      0.102373555F, -0.20159003F, 0.7404908F, 0.51214F, -0.17536917F,
      0.09214344F, -0.052504174F, 0.02968951F, -0.015925469F, 0.007804824F,
      -0.003333018F, 0.00113894F, -0.00024540754F, 0.0F, -0.0003437979F,
      0.0014133743F, -0.00393271F, 0.008940554F, -0.01789285F, 0.032948274F,
      -0.057959165F, 0.10229817F, -0.20154108F, 0.7431027F, 0.5090645F,
      -0.17470786F, 0.09183034F, -0.052328583F, 0.02958799F, -0.015868446F,
      0.007774923F, -0.0033189682F, 0.0011333807F, -0.00024379452F, 0.0F,
      -0.00034443737F, 0.0014140881F, -0.0039323573F, 0.008936581F, -0.01788073F,
      0.03292113F, -0.05790812F, 0.10221725F, -0.20148146F, 0.7457054F,
      0.5059868F, -0.17403974F, 0.09151329F, -0.0521507F, 0.02948518F,
      -0.015810747F, 0.0077447034F, -0.0033047916F, 0.0011277839F,
      -0.00024217693F, 0.0F, -0.00034505708F, 0.001414721F, -0.0039317827F,
      0.00893211F, -0.017867621F, 0.032892175F, -0.057853915F, 0.10213078F,
      -0.20141114F, 0.7482988F, 0.502907F, -0.17336482F, 0.09119231F,
      -0.051970534F, 0.029381089F, -0.015752377F, 0.007714168F, -0.0032904895F,
      0.0011221501F, -0.00024055495F, 0.0F, -0.0003456568F, 0.001415273F,
      -0.0039309855F, 0.008927137F, -0.017853519F, 0.032861408F, -0.057796538F,
      0.10203874F, -0.20133008F, 0.7508828F, 0.4998251F, -0.1726832F,
      0.09086742F, -0.051788107F, 0.029275728F, -0.015693342F, 0.00768332F,
      -0.0032760631F, 0.0011164799F, -0.00023892874F, 0.0F, -0.00034623637F,
      0.0014157433F, -0.0039299643F, 0.008921662F, -0.017838422F, 0.032828826F,
      -0.05773599F, 0.10194113F, -0.20123823F, 0.7534573F, 0.49674124F,
      -0.1719949F, 0.090538666F, -0.051603425F, 0.029169105F, -0.015633645F,
      0.0076521616F, -0.003261514F, 0.0011107738F, -0.00023729846F, 0.0F,
      -0.00034679557F, 0.0014161315F, -0.003928719F, 0.008915684F, -0.01782233F,
      0.032794423F, -0.057672262F, 0.10183794F, -0.20113558F, 0.75602233F,
      0.49365547F, -0.1713F, 0.09020605F, -0.051416513F, 0.029061228F,
      -0.015573293F, 0.007620696F, -0.0032468433F, 0.0011050324F, -0.0002356643F,
      0.0F, -0.00034733422F, 0.0014164373F, -0.003927248F, 0.0089092F,
      -0.01780524F, 0.0327582F, -0.057605352F, 0.10172916F, -0.20102207F,
      0.7585777F, 0.49056795F, -0.17059854F, 0.08986962F, -0.05122738F,
      0.028952107F, -0.015512291F, 0.007588926F, -0.0032320525F, 0.0010992562F,
      -0.00023402639F, 0.0F, -0.00034785218F, 0.0014166603F, -0.003925551F,
      0.008902211F, -0.017787145F, 0.03272015F, -0.057535257F, 0.10161478F,
      -0.20089768F, 0.76112336F, 0.48747873F, -0.1698906F, 0.08952939F,
      -0.05103604F, 0.02884175F, -0.015450643F, 0.007556854F, -0.003217143F,
      0.0010934459F, -0.00023238492F, 0.0F, -0.0003483492F, 0.0014167998F,
      -0.0039236275F, 0.0088947145F, -0.017768051F, 0.032680273F, -0.057461966F,
      0.10149479F, -0.20076238F, 0.76365924F, 0.48438787F, -0.1691762F,
      0.08918539F, -0.050842516F, 0.028730167F, -0.0153883565F, 0.0075244834F,
      -0.0032021161F, 0.0010876019F, -0.00023074004F, 0.0F, -0.00034882512F,
      0.0014168556F, -0.0039214757F, 0.008886709F, -0.017747952F, 0.032638565F,
      -0.057385482F, 0.10136918F, -0.2006161F, 0.7661852F, 0.48129553F,
      -0.16845542F, 0.088837646F, -0.05064682F, 0.028617369F, -0.0153254345F,
      0.0074918163F, -0.003186973F, 0.0010817248F, -0.00022909192F, 0.0F,
      -0.00034927976F, 0.0014168272F, -0.0039190957F, 0.008878193F,
      -0.017726846F, 0.032595027F, -0.057305794F, 0.101237945F, -0.20045887F,
      0.7687013F, 0.47820172F, -0.16772832F, 0.088486195F, -0.050448965F,
      0.028503362F, -0.015261883F, 0.0074588563F, -0.0031717152F, 0.0010758151F,
      -0.00022744072F, 0.0F, -0.00034971294F, 0.0014167142F, -0.003916486F,
      0.008869166F, -0.017704733F, 0.032549653F, -0.057222907F, 0.10110107F,
      -0.2002906F, 0.7712074F, 0.47510657F, -0.16699494F, 0.08813106F,
      -0.05024897F, 0.028388157F, -0.015197708F, 0.007425606F, -0.0031563442F,
      0.0010698733F, -0.00022578659F, 0.0F, -0.00035012444F, 0.0014165161F,
      -0.0039136466F, 0.008859626F, -0.01768161F, 0.032502443F, -0.057136808F,
      0.10095855F, -0.20011128F, 0.7737034F, 0.47201017F, -0.16625535F,
      0.087772265F, -0.05004685F, 0.028271765F, -0.015132914F, 0.007392068F,
      -0.0031408612F, 0.0010639002F, -0.00022412969F, 0.0F, -0.0003505141F,
      0.0014162326F, -0.003910576F, 0.008849572F, -0.017657476F, 0.032453388F,
      -0.0570475F, 0.10081038F, -0.19992088F, 0.77618915F, 0.4689126F,
      -0.16550961F, 0.08740984F, -0.04984262F, 0.02815419F, -0.0150675075F,
      0.007358245F, -0.0031252676F, 0.0010578962F, -0.00022247019F, 0.0F,
      -0.00035088175F, 0.0014158632F, -0.003907274F, 0.008839005F, -0.017632328F,
      0.032402497F, -0.056954976F, 0.10065655F, -0.19971934F, 0.7786647F,
      0.46581396F, -0.16475776F, 0.087043814F, -0.049636293F, 0.028035447F,
      -0.015001493F, 0.007324141F, -0.0031095648F, 0.0010518618F,
      -0.00022080824F, 0.0F, -0.00035122718F, 0.0014154075F, -0.0039037394F,
      0.00882792F, -0.017606165F, 0.032349758F, -0.056859236F, 0.100497045F,
      -0.19950667F, 0.78112996F, 0.46271434F, -0.16399987F, 0.08667422F,
      -0.049427893F, 0.027915543F, -0.014934875F, 0.0072897575F, -0.0030937542F,
      0.0010457976F, -0.00021914401F, 0.0F, -0.00035155023F, 0.0014148651F,
      -0.003899972F, 0.0088163195F, -0.017578987F, 0.032295175F, -0.056760274F,
      0.100331865F, -0.19928281F, 0.7835848F, 0.4596138F, -0.16323599F,
      0.08630108F, -0.049217433F, 0.027794488F, -0.014867661F, 0.0072550983F,
      -0.003077837F, 0.0010397041F, -0.00021747763F, 0.0F, -0.0003518507F,
      0.0014142356F, -0.0038959708F, 0.0088042F, -0.01755079F, 0.03223874F,
      -0.05665809F, 0.10016101F, -0.19904774F, 0.78602916F, 0.45651245F,
      -0.16246618F, 0.08592442F, -0.049004927F, 0.02767229F, -0.014799855F,
      0.007220166F, -0.0030618147F, 0.0010335819F, -0.00021580927F, 0.0F,
      -0.0003521284F, 0.0014135186F, -0.003891735F, 0.008791561F, -0.017521577F,
      0.03218046F, -0.05655268F, 0.09998446F, -0.19880141F, 0.78846294F,
      0.45341036F, -0.1616905F, 0.08554427F, -0.04879039F, 0.027548961F,
      -0.014731462F, 0.0071849627F, -0.0030456888F, 0.0010274315F,
      -0.00021413909F, 0.0F, -0.00035238318F, 0.0014127137F, -0.0038872643F,
      0.008778403F, -0.017491342F, 0.032120325F, -0.056444038F, 0.09980222F,
      -0.19854383F, 0.7908861F, 0.45030764F, -0.16090901F, 0.085160665F,
      -0.048573844F, 0.027424509F, -0.014662489F, 0.007149493F, -0.0030294603F,
      0.0010212535F, -0.00021246723F, 0.0F, -0.00035261482F, 0.0014118205F,
      -0.0038825576F, 0.008764722F, -0.017460085F, 0.03205834F, -0.056332164F,
      0.09961427F, -0.19827493F, 0.7932986F, 0.44720438F, -0.16012175F,
      0.08477363F, -0.048355304F, 0.027298944F, -0.014592941F, 0.007113758F,
      -0.0030131312F, 0.0010150485F, -0.00021079385F, 0.0F, -0.00035282318F,
      0.0014108387F, -0.0038776144F, 0.008750521F, -0.017427806F, 0.031994496F,
      -0.05621706F, 0.09942062F, -0.19799468F, 0.7957003F, 0.44410068F,
      -0.1593288F, 0.0843832F, -0.04813478F, 0.027172275F, -0.014522823F,
      0.007077762F, -0.0029967022F, 0.0010088168F, -0.0002091191F, 0.0F,
      -0.00035300804F, 0.0014097678F, -0.0038724341F, 0.008735795F,
      -0.017394502F, 0.0319288F, -0.056098714F, 0.09922126F, -0.19770308F,
      0.7980912F, 0.44099656F, -0.1585302F, 0.08398938F, -0.047912296F,
      0.027044512F, -0.01445214F, 0.0070415074F, -0.002980175F, 0.0010025592F,
      -0.00020744312F, 0.0F, -0.00035316928F, 0.0014086073F, -0.003867016F,
      0.008720545F, -0.017360173F, 0.031861242F, -0.055977136F, 0.099016175F,
      -0.19740008F, 0.80047107F, 0.4378922F, -0.15772602F, 0.08359223F,
      -0.047687866F, 0.026915666F, -0.014380899F, 0.0070049968F, -0.002963551F,
      0.000996276F, -0.00020576609F, 0.0F, -0.00035330665F, 0.0014073572F,
      -0.0038613593F, 0.008704771F, -0.017324818F, 0.03179183F, -0.055852316F,
      0.09880537F, -0.19708566F, 0.80284F, 0.43478763F, -0.15691632F,
      0.08319177F, -0.047461506F, 0.026785746F, -0.0143091045F, 0.0069682333F,
      -0.0029468315F, 0.0009899681F, -0.00020408812F, 0.0F, -0.00035342F,
      0.0014060169F, -0.0038554638F, 0.008688471F, -0.017288435F, 0.031720556F,
      -0.055724256F, 0.09858884F, -0.19675978F, 0.80519783F, 0.43168294F,
      -0.15610114F, 0.08278801F, -0.04723323F, 0.026654761F, -0.014236762F,
      0.00693122F, -0.002930018F, 0.0009836357F, -0.00020240938F, 0.0F,
      -0.0003535092F, 0.0014045859F, -0.0038493285F, 0.008671644F, -0.017251024F,
      0.031647418F, -0.05559295F, 0.098366566F, -0.19642243F, 0.8075445F,
      0.42857823F, -0.15528055F, 0.082381F, -0.04700306F, 0.026522722F,
      -0.014163878F, 0.0068939603F, -0.0029131116F, 0.0009772794F,
      -0.00020073002F, 0.0F, -0.00035357403F, 0.001403064F, -0.003842953F,
      0.00865429F, -0.017212583F, 0.03157242F, -0.055458404F, 0.09813856F,
      -0.19607355F, 0.8098801F, 0.4254736F, -0.1544546F, 0.081970766F,
      -0.046771012F, 0.026389638F, -0.014090456F, 0.006856456F, -0.002896114F,
      0.0009708998F, -0.00019905018F, 0.0F, -0.00035361428F, 0.0014014508F,
      -0.0038363363F, 0.008636407F, -0.017173113F, 0.03149556F, -0.05532061F,
      0.09790482F, -0.19571315F, 0.81220424F, 0.4223691F, -0.15362336F,
      0.08155733F, -0.0465371F, 0.02625552F, -0.014016504F, 0.006818711F,
      -0.0028790263F, 0.0009644975F, -0.00019737F, 0.0F, -0.00035362985F,
      0.001399746F, -0.0038294785F, 0.008617995F, -0.017132612F, 0.031416837F,
      -0.05517957F, 0.09766533F, -0.19534118F, 0.8145171F, 0.41926485F,
      -0.15278688F, 0.081140734F, -0.046301346F, 0.026120376F, -0.013942027F,
      0.0067807273F, -0.00286185F, 0.0009580729F, -0.00019568962F, 0.0F,
      -0.0003536205F, 0.0013979493F, -0.0038223786F, 0.008599053F, -0.017091077F,
      0.031336248F, -0.055035286F, 0.0974201F, -0.19495761F, 0.8168185F,
      0.41616094F, -0.15194522F, 0.080721F, -0.046063762F, 0.025984216F,
      -0.01386703F, 0.0067425086F, -0.0028445865F, 0.00095162657F,
      -0.0001940092F, 0.0F, -0.0003535861F, 0.0013960601F, -0.003815036F,
      0.008579581F, -0.017048512F, 0.031253796F, -0.054887753F, 0.09716911F,
      -0.19456244F, 0.81910837F, 0.41305745F, -0.15109845F, 0.080298156F,
      -0.045824368F, 0.025847051F, -0.013791518F, 0.006704058F, -0.0028272371F,
      0.00094515906F, -0.00019232887F, 0.0F, -0.0003535265F, 0.0013940783F,
      -0.0038074504F, 0.008559578F, -0.017004913F, 0.031169476F, -0.05473697F,
      0.09691237F, -0.19415562F, 0.8213867F, 0.40995443F, -0.1502466F,
      0.07987223F, -0.045583177F, 0.025708893F, -0.013715498F, 0.006665378F,
      -0.0028098035F, 0.00093867094F, -0.00019064876F, 0.0F, -0.00035344146F,
      0.0013920034F, -0.0037996212F, 0.008539042F, -0.01696028F, 0.031083291F,
      -0.054582942F, 0.09664987F, -0.19373713F, 0.8236534F, 0.40685204F,
      -0.14938976F, 0.07944326F, -0.04534021F, 0.025569748F, -0.013638976F,
      0.0066264714F, -0.0027922865F, 0.0009321626F, -0.00018896903F, 0.0F,
      -0.00035333083F, 0.001389835F, -0.0037915478F, 0.008517975F, -0.016914612F,
      0.030995242F, -0.054425664F, 0.09638161F, -0.19330695F, 0.8259083F,
      0.4037503F, -0.14852796F, 0.07901127F, -0.04509548F, 0.025429629F,
      -0.013561956F, 0.006587342F, -0.0027746877F, 0.00092563475F,
      -0.00018728983F, 0.0F, -0.00035319448F, 0.0013875731F, -0.00378323F,
      0.008496375F, -0.01686791F, 0.030905325F, -0.05426514F, 0.096107595F,
      -0.19286506F, 0.82815146F, 0.40064934F, -0.14766127F, 0.07857629F,
      -0.044849012F, 0.025288546F, -0.0134844445F, 0.0065479917F, -0.0027570087F,
      0.0009190878F, -0.00018561126F, 0.0F, -0.00035303223F, 0.0013852171F,
      -0.003774667F, 0.00847424F, -0.016820172F, 0.030813541F, -0.054101367F,
      0.09582781F, -0.19241141F, 0.83038276F, 0.3975492F, -0.14678976F,
      0.07813836F, -0.04460082F, 0.025146507F, -0.013406446F, 0.006508424F,
      -0.0027392507F, 0.00091252226F, -0.00018393349F, 0.0F, -0.00035284387F,
      0.0013827668F, -0.0037658582F, 0.008451572F, -0.016771398F, 0.030719893F,
      -0.053934347F, 0.09554227F, -0.191946F, 0.83260214F, 0.39445004F,
      -0.14591348F, 0.07769749F, -0.044350915F, 0.025003523F, -0.013327969F,
      0.0064686416F, -0.0027214151F, 0.00090593874F, -0.00018225663F, 0.0F,
      -0.0003526293F, 0.0013802217F, -0.0037568035F, 0.008428369F, -0.01672159F,
      0.030624377F, -0.05376408F, 0.09525096F, -0.19146879F, 0.83480954F,
      0.39135188F, -0.14503248F, 0.07725373F, -0.044099323F, 0.024859605F,
      -0.013249017F, 0.006428648F, -0.002703503F, 0.00089933764F,
      -0.00018058083F, 0.0F, -0.00035238828F, 0.0013775817F, -0.003747502F,
      0.008404631F, -0.016670743F, 0.030526996F, -0.053590562F, 0.09495388F,
      -0.19097978F, 0.83700484F, 0.38825482F, -0.14414683F, 0.076807104F,
      -0.043846056F, 0.024714762F, -0.013169596F, 0.006388446F, -0.0026855164F,
      0.0008927196F, -0.00017890622F, 0.0F, -0.0003521207F, 0.0013748464F,
      -0.003737954F, 0.008380357F, -0.01661886F, 0.030427748F, -0.053413805F,
      0.094651036F, -0.19047894F, 0.83918804F, 0.38515896F, -0.14325657F,
      0.07635763F, -0.043591134F, 0.024569005F, -0.013089712F, 0.006348038F,
      -0.002667456F, 0.0008860851F, -0.00017723294F, 0.0F, -0.00035182637F,
      0.0013720156F, -0.0037281583F, 0.008355547F, -0.016565941F, 0.030326637F,
      -0.053233802F, 0.094342425F, -0.18996622F, 0.84135896F, 0.38206437F,
      -0.14236179F, 0.07590537F, -0.043334577F, 0.024422344F, -0.01300937F,
      0.0063074273F, -0.0026493235F, 0.0008794346F, -0.00017556113F, 0.0F,
      -0.00035150515F, 0.0013690887F, -0.0037181147F, 0.008330201F,
      -0.016511986F, 0.03022366F, -0.053050555F, 0.09402805F, -0.18944162F,
      0.84351766F, 0.37897116F, -0.14146252F, 0.075450316F, -0.043076396F,
      0.024274789F, -0.012928578F, 0.006266617F, -0.0026311202F, 0.0008727687F,
      -0.00017389089F, 0.0F, -0.00035115684F, 0.0013660657F, -0.003707823F,
      0.0083043175F, -0.016456993F, 0.03011882F, -0.052864067F, 0.093707904F,
      -0.18890513F, 0.845664F, 0.3758794F, -0.14055884F, 0.07499252F,
      -0.042816613F, 0.02412635F, -0.012847339F, 0.0062256106F, -0.0026128476F,
      0.0008660878F, -0.00017222238F, 0.0F, -0.0003507813F, 0.0013629462F,
      -0.0036972829F, 0.008277898F, -0.016400963F, 0.030012114F, -0.05267434F,
      0.09338199F, -0.18835671F, 0.847798F, 0.37278917F, -0.13965078F,
      0.07453202F, -0.042555247F, 0.02397704F, -0.01276566F, 0.0061844103F,
      -0.0025945068F, 0.0008593925F, -0.00017055571F, 0.0F, -0.0003503784F,
      0.0013597299F, -0.0036864937F, 0.00825094F, -0.016343895F, 0.029903548F,
      -0.052481372F, 0.093050316F, -0.18779634F, 0.8499195F, 0.36970058F,
      -0.13873844F, 0.07406883F, -0.042292308F, 0.023826865F, -0.012683547F,
      0.006143019F, -0.0025760992F, 0.0008526833F, -0.00016889101F, 0.0F,
      -0.00034994795F, 0.0013564166F, -0.0036754552F, 0.008223445F,
      -0.016285792F, 0.029793119F, -0.052285172F, 0.09271287F, -0.18722402F,
      0.8520284F, 0.3666137F, -0.13782184F, 0.07360298F, -0.042027824F,
      0.023675838F, -0.012601005F, 0.00610144F, -0.0025576265F, 0.0008459607F,
      -0.00016722843F, 0.0F, -0.0003494898F, 0.001353006F, -0.003664167F,
      0.008195411F, -0.016226653F, 0.029680831F, -0.052085735F, 0.09236967F,
      -0.1866397F, 0.8541247F, 0.36352858F, -0.13690105F, 0.07313452F,
      -0.041761808F, 0.02352397F, -0.012518041F, 0.006059677F, -0.0025390899F,
      0.0008392252F, -0.00016556807F, 0.0F, -0.00034900376F, 0.0013494977F,
      -0.0036526287F, 0.00816684F, -0.016166477F, 0.029566683F, -0.051883068F,
      0.092020705F, -0.18604338F, 0.85620844F, 0.36044535F, -0.13597615F,
      0.072663456F, -0.041494276F, 0.023371268F, -0.0124346595F, 0.0060177315F,
      -0.0025204904F, 0.0008324773F, -0.00016391005F, 0.0F, -0.00034848973F,
      0.0013458915F, -0.0036408403F, 0.00813773F, -0.016105263F, 0.029450675F,
      -0.05167717F, 0.091665976F, -0.18543503F, 0.85827935F, 0.3573641F,
      -0.13504717F, 0.072189845F, -0.04122525F, 0.023217745F, -0.012350867F,
      0.005975607F, -0.0025018295F, 0.0008257175F, -0.00016225451F, 0.0F,
      -0.00034794753F, 0.0013421873F, -0.003628801F, 0.008108081F, -0.016043015F,
      0.029332813F, -0.051468045F, 0.091305494F, -0.18481463F, 0.8603375F,
      0.35428488F, -0.13411418F, 0.07171369F, -0.040954746F, 0.02306341F,
      -0.012266668F, 0.005933307F, -0.002483109F, 0.00081894634F,
      -0.00016060157F, 0.0F, -0.000347377F, 0.0013383846F, -0.0036165111F,
      0.008077894F, -0.015979731F, 0.029213093F, -0.0512557F, 0.09093925F,
      -0.18418218F, 0.8623827F, 0.3512078F, -0.13317725F, 0.07123505F,
      -0.040682778F, 0.022908276F, -0.01218207F, 0.005890834F, -0.0024643298F,
      0.0008121643F, -0.00015895136F, 0.0F, -0.00034677802F, 0.0013344833F,
      -0.0036039697F, 0.008047168F, -0.015915412F, 0.029091522F, -0.05104013F,
      0.09056727F, -0.18353765F, 0.86441505F, 0.3481329F, -0.13223642F,
      0.07075394F, -0.04040937F, 0.02275235F, -0.012097078F, 0.005848191F,
      -0.0024454934F, 0.0008053718F, -0.00015730398F, 0.0F, -0.0003461504F,
      0.0013304831F, -0.0035911768F, 0.008015904F, -0.01585006F, 0.028968096F,
      -0.050821345F, 0.090189524F, -0.18288103F, 0.8664344F, 0.34506035F,
      -0.13129175F, 0.07027039F, -0.040134538F, 0.022595646F, -0.012011698F,
      0.005805382F, -0.002426601F, 0.0007985694F, -0.00015565957F, 0.0F,
      -0.00034549402F, 0.0013263838F, -0.0035781325F, 0.0079841F, -0.015783673F,
      0.028842822F, -0.050599344F, 0.08980604F, -0.18221228F, 0.8684407F,
      0.34199014F, -0.13034332F, 0.06978444F, -0.0398583F, 0.02243817F,
      -0.011925936F, 0.0057624085F, -0.0024076542F, 0.00079175766F,
      -0.00015401823F, 0.0F, -0.0003448087F, 0.0013221852F, -0.003564836F,
      0.007951758F, -0.015716253F, 0.028715698F, -0.05037413F, 0.08941682F,
      -0.1815314F, 0.87043387F, 0.3389224F, -0.12939116F, 0.069296114F,
      -0.039580673F, 0.022279939F, -0.011839798F, 0.005719274F, -0.002388654F,
      0.00078493694F, -0.00015238007F, 0.0F, -0.00034409433F, 0.0013178869F,
      -0.0035512873F, 0.007918876F, -0.0156478F, 0.028586727F, -0.050145715F,
      0.089021854F, -0.18083838F, 0.8724138F, 0.33585724F, -0.12843536F,
      0.06880545F, -0.039301675F, 0.022120956F, -0.011753288F, 0.0056759813F,
      -0.0023696022F, 0.00077810785F, -0.00015074524F, 0.0F, -0.00034335072F,
      0.0013134887F, -0.003537486F, 0.007885456F, -0.015578317F, 0.028455911F,
      -0.04991409F, 0.08862116F, -0.1801332F, 0.8743806F, 0.3327947F,
      -0.12747595F, 0.068312466F, -0.039021324F, 0.021961236F, -0.011666413F,
      0.0056325337F, -0.0023504996F, 0.0007712708F, -0.00014911384F, 0.0F,
      -0.00034257775F, 0.0013089906F, -0.0035234324F, 0.007851496F,
      -0.015507802F, 0.028323254F, -0.049679272F, 0.08821473F, -0.17941582F,
      0.876334F, 0.32973486F, -0.126513F, 0.06781721F, -0.03873964F,
      0.021800788F, -0.011579181F, 0.0055889343F, -0.0023313481F, 0.00076442625F,
      -0.00014748597F, 0.0F, -0.0003417753F, 0.0013043922F, -0.003509126F,
      0.007816999F, -0.015436257F, 0.028188756F, -0.049441256F, 0.08780259F,
      -0.17868626F, 0.8782741F, 0.32667783F, -0.12554657F, 0.067319706F,
      -0.038456637F, 0.021639623F, -0.011491595F, 0.005545186F, -0.0023121485F,
      0.00075757474F, -0.00014586176F, 0.0F, -0.00034094322F, 0.0012996932F,
      -0.0034945665F, 0.007781963F, -0.015363683F, 0.028052421F, -0.04920005F,
      0.087384716F, -0.17794448F, 0.8802007F, 0.32362366F, -0.12457672F,
      0.06681998F, -0.03817234F, 0.021477751F, -0.011403661F, 0.0055012912F,
      -0.0022929024F, 0.0007507168F, -0.0001442413F, 0.0F, -0.00034008134F,
      0.0012948938F, -0.003479754F, 0.007746388F, -0.015290081F, 0.02791425F,
      -0.048955657F, 0.086961135F, -0.17719048F, 0.8821139F, 0.32057247F,
      -0.1236035F, 0.06631807F, -0.03788676F, 0.021315185F, -0.011315386F,
      0.0054572537F, -0.0022736113F, 0.00074385275F, -0.00014262473F, 0.0F,
      -0.00033918954F, 0.0012899933F, -0.0034646883F, 0.0077102752F,
      -0.015215451F, 0.027774246F, -0.048708085F, 0.08653185F, -0.17642425F,
      0.8840135F, 0.3175243F, -0.12262698F, 0.06581401F, -0.03759992F,
      0.021151932F, -0.011226775F, 0.005413076F, -0.002254276F, 0.0007369832F,
      -0.00014101215F, 0.0F, -0.00033826768F, 0.0012849919F, -0.003449369F,
      0.007673625F, -0.015139796F, 0.027632413F, -0.048457336F, 0.08609686F,
      -0.17564577F, 0.8858994F, 0.3144793F, -0.12164722F, 0.06530783F,
      -0.03731184F, 0.020988004F, -0.011137834F, 0.005368761F, -0.0022348985F,
      0.0007301086F, -0.00013940365F, 0.0F, -0.0003373156F, 0.001279889F,
      -0.0034337963F, 0.0076364363F, -0.015063115F, 0.027488751F, -0.048203412F,
      0.08565618F, -0.17485502F, 0.8877718F, 0.3114375F, -0.12066427F,
      0.064799555F, -0.037022535F, 0.020823414F, -0.011048569F, 0.0053243116F,
      -0.0022154795F, 0.00072322943F, -0.00013779936F, 0.0F, -0.00033633324F,
      0.0012746848F, -0.0034179701F, 0.0075987107F, -0.014985411F, 0.027343266F,
      -0.047946326F, 0.08520981F, -0.174052F, 0.8896304F, 0.30839896F,
      -0.119678184F, 0.06428923F, -0.036732018F, 0.020658167F, -0.010958986F,
      0.005279731F, -0.0021960207F, 0.0007163461F, -0.00013619938F, 0.0F,
      -0.0003353204F, 0.001269379F, -0.0034018902F, 0.0075604483F, -0.014906686F,
      0.02719596F, -0.047686078F, 0.08475775F, -0.17323668F, 0.89147514F,
      0.3053638F, -0.11868903F, 0.063776866F, -0.036440317F, 0.02049228F,
      -0.010869091F, 0.005235022F, -0.002176523F, 0.0007094591F, -0.0001346038F,
      0.0F, -0.00033427693F, 0.0012639714F, -0.0033855566F, 0.007521649F,
      -0.0148269385F, 0.027046835F, -0.047422677F, 0.08430003F, -0.17240907F,
      0.89330614F, 0.3023321F, -0.11769687F, 0.06326251F, -0.036147445F,
      0.020325758F, -0.010778889F, 0.0051901876F, -0.0021569883F, 0.00070256897F,
      -0.00013301274F, 0.0F, -0.00033320277F, 0.0012584619F, -0.003368969F,
      0.007482313F, -0.014746171F, 0.026895896F, -0.047156125F, 0.08383664F,
      -0.17156915F, 0.8951232F, 0.29930395F, -0.116701744F, 0.06274619F,
      -0.035853423F, 0.020158615F, -0.010688387F, 0.005145231F, -0.0021374174F,
      0.00069567614F, -0.0001314263F, 0.0F, -0.00033209773F, 0.0012528502F,
      -0.0033521277F, 0.007442442F, -0.014664386F, 0.026743144F, -0.046886433F,
      0.083367586F, -0.17071691F, 0.8969263F, 0.29627937F, -0.11570373F,
      0.06222794F, -0.035558265F, 0.01999086F, -0.010597589F, 0.005100155F,
      -0.002117812F, 0.000688781F, -0.00012984459F, 0.0F, -0.00033096172F,
      0.0012471362F, -0.0033350326F, 0.0074020345F, -0.014581585F, 0.026588583F,
      -0.046613604F, 0.08289289F, -0.16985233F, 0.8987154F, 0.29325852F,
      -0.11470288F, 0.061707783F, -0.035261992F, 0.019822504F, -0.010506503F,
      0.0050549624F, -0.002098173F, 0.00068188406F, -0.0001282677F, 0.0F,
      -0.00032979462F, 0.0012413198F, -0.0033176837F, 0.007361093F,
      -0.014497768F, 0.026432218F, -0.04633764F, 0.08241254F, -0.1689754F,
      0.9004904F, 0.29024145F, -0.11369925F, 0.061185762F, -0.034964625F,
      0.019653559F, -0.010415133F, 0.005009656F, -0.002078502F, 0.0006749858F,
      -0.00012669573F, 0.0F, -0.00032859627F, 0.0012354009F, -0.0033000808F,
      0.0073196166F, -0.014412938F, 0.026274052F, -0.046058558F, 0.08192657F,
      -0.16808613F, 0.9022513F, 0.2872282F, -0.1126929F, 0.060661905F,
      -0.034666177F, 0.019484032F, -0.010323486F, 0.004964239F, -0.0020588F,
      0.00066808664F, -0.00012512878F, 0.0F, -0.00032736655F, 0.0012293792F,
      -0.003282224F, 0.0072776065F, -0.014327096F, 0.026114088F, -0.045776356F,
      0.081434965F, -0.16718449F, 0.903998F, 0.2842189F, -0.11168389F,
      0.06013624F, -0.03436667F, 0.019313939F, -0.010231568F, 0.004918714F,
      -0.0020390686F, 0.00066118705F, -0.00012356693F, 0.0F, -0.00032610536F,
      0.0012232547F, -0.0032641136F, 0.0072350632F, -0.014240244F, 0.02595233F,
      -0.045491043F, 0.08093775F, -0.1662705F, 0.9057305F, 0.2812136F,
      -0.11067227F, 0.0596088F, -0.034066122F, 0.019143285F, -0.010139383F,
      0.004873085F, -0.002019309F, 0.00065428746F, -0.000122010315F, 0.0F,
      -0.0003248126F, 0.0012170273F, -0.0032457493F, 0.007191987F, -0.014152384F,
      0.025788784F, -0.045202628F, 0.08043493F, -0.1653441F, 0.90744865F,
      0.27821243F, -0.109658115F, 0.05907962F, -0.033764552F, 0.018972086F,
      -0.010046938F, 0.0048273536F, -0.0019995223F, 0.00064738834F,
      -0.000120459F, 0.0F, -0.00032348812F, 0.0012106968F, -0.0032271312F,
      0.007148379F, -0.0140635185F, 0.025623452F, -0.044911116F, 0.07992652F,
      -0.16440533F, 0.90915245F, 0.2752154F, -0.10864146F, 0.05854873F,
      -0.033461977F, 0.018800348F, -0.00995424F, 0.0047815233F, -0.0019797098F,
      0.0006404901F, -0.00011891309F, 0.0F, -0.0003221318F, 0.0012042631F,
      -0.0032082596F, 0.0071042394F, -0.013973648F, 0.025456337F, -0.044616517F,
      0.07941253F, -0.16345417F, 0.9108419F, 0.27222264F, -0.107622385F,
      0.05801616F, -0.033158414F, 0.018628083F, -0.009861294F, 0.004735597F,
      -0.0019598731F, 0.00063359324F, -0.00011737268F, 0.0F, -0.0003207435F,
      0.001197726F, -0.0031891344F, 0.007059569F, -0.013882775F, 0.025287446F,
      -0.044318832F, 0.07889295F, -0.1624906F, 0.91251683F, 0.26923418F,
      -0.10660093F, 0.057481945F, -0.032853883F, 0.018455302F, -0.009768104F,
      0.0046895775F, -0.0019400133F, 0.0006266982F, -0.00011583785F, 0.0F,
      -0.00031932318F, 0.0011910856F, -0.003169756F, 0.007014369F, -0.013790901F,
      0.025116783F, -0.04401808F, 0.07836782F, -0.16151464F, 0.9141773F,
      0.26625016F, -0.10557717F, 0.056946114F, -0.032548405F, 0.018282017F,
      -0.009674679F, 0.0046434677F, -0.0019201315F, 0.0006198053F,
      -0.0001143087F, 0.0F, -0.0003178707F, 0.0011843416F, -0.003150124F,
      0.00696864F, -0.013698029F, 0.02494435F, -0.043714263F, 0.07783713F,
      -0.16052626F, 0.9158232F, 0.2632706F, -0.10455115F, 0.0564087F,
      -0.032241996F, 0.018108238F, -0.009581022F, 0.0045972704F, -0.001900229F,
      0.00061291514F, -0.00011278532F, 0.0F, -0.00031638594F, 0.0011774941F,
      -0.0031302392F, 0.0069223824F, -0.013604162F, 0.024770154F, -0.043407384F,
      0.077300906F, -0.15952545F, 0.9174545F, 0.2602956F, -0.103522934F,
      0.055869736F, -0.031934675F, 0.017933972F, -0.00948714F, 0.004550989F,
      -0.0018803073F, 0.000606028F, -0.000111267786F, 0.0F, -0.00031486875F,
      0.0011705429F, -0.0031101012F, 0.006875597F, -0.013509301F, 0.024594197F,
      -0.04309746F, 0.07675915F, -0.15851223F, 0.91907114F, 0.25732526F,
      -0.10249258F, 0.055329252F, -0.03162646F, 0.017759234F, -0.009393039F,
      0.004504626F, -0.0018603674F, 0.0005991445F, -0.000109756205F, 0.0F,
      -0.00031331912F, 0.0011634879F, -0.0030897104F, 0.0068282853F,
      -0.013413448F, 0.024416488F, -0.042784493F, 0.076211885F, -0.15748657F,
      0.920673F, 0.25435963F, -0.10146014F, 0.05478728F, -0.03131737F,
      0.017584033F, -0.009298724F, 0.0044581844F, -0.0018404106F, 0.00059226487F,
      -0.00010825064F, 0.0F, -0.00031173686F, 0.0011563292F, -0.0030690671F,
      0.006780448F, -0.013316606F, 0.02423703F, -0.0424685F, 0.07565911F,
      -0.1564485F, 0.92226017F, 0.2513988F, -0.100425676F, 0.05424385F,
      -0.031007418F, 0.01740838F, -0.009204202F, 0.0044116667F, -0.0018204383F,
      0.0005853896F, -0.000106751206F, 0.0F, -0.0003101219F, 0.0011490665F,
      -0.0030481713F, 0.0067320853F, -0.013218778F, 0.024055826F, -0.04214948F,
      0.07510085F, -0.15539797F, 0.92383254F, 0.24844281F, -0.09938924F,
      0.053698998F, -0.030696632F, 0.017232286F, -0.0091094775F, 0.0043650763F,
      -0.0018004515F, 0.0005785192F, -0.000105257954F, 0.0F, -0.00030847415F,
      0.0011416998F, -0.0030270233F, 0.006683199F, -0.013119966F, 0.023872882F,
      -0.041827448F, 0.074537106F, -0.154335F, 0.92538995F, 0.2454918F,
      -0.0983509F, 0.053152755F, -0.030385025F, 0.01705576F, -0.009014557F,
      0.0043184157F, -0.0017804516F, 0.000571654F, -0.00010377099F, 0.0F,
      -0.0003067935F, 0.0011342292F, -0.0030056234F, 0.00663379F, -0.013020171F,
      0.023688206F, -0.04150241F, 0.0739679F, -0.1532596F, 0.9269325F,
      0.2425458F, -0.0973107F, 0.05260515F, -0.030072616F, 0.016878814F,
      -0.008919447F, 0.0042716884F, -0.0017604398F, 0.0005647944F,
      -0.00010229039F, 0.0F, -0.00030507983F, 0.0011266546F, -0.0029839715F,
      0.006583859F, -0.012919398F, 0.0235018F, -0.04117438F, 0.07339324F,
      -0.15217176F, 0.9284601F, 0.2396049F, -0.096268706F, 0.052056216F,
      -0.029759424F, 0.016701458F, -0.008824151F, 0.0042248964F, -0.0017404173F,
      0.0005579409F, -0.00010081623F, 0.0F, -0.0003033331F, 0.0011189758F,
      -0.0029620684F, 0.0065334076F, -0.012817648F, 0.023313671F, -0.04084336F,
      0.072813146F, -0.15107147F, 0.9299727F, 0.23666918F, -0.09522498F,
      0.051505983F, -0.029445468F, 0.016523702F, -0.0087286765F, 0.0041780425F,
      -0.0017203854F, 0.0005510939F, -9.934858E-5F, 0.0F, -0.00030155314F,
      0.001111193F, -0.0029399141F, 0.006482436F, -0.012714924F, 0.023123825F,
      -0.040509365F, 0.07222763F, -0.14995873F, 0.9314702F, 0.2337387F,
      -0.09417956F, 0.050954487F, -0.029130766F, 0.016345557F, -0.008633029F,
      0.004131131F, -0.0017003452F, 0.00054425374F, -9.788754E-5F, 0.0F,
      -0.00029973994F, 0.0011033058F, -0.0029175088F, 0.006430946F, -0.01261123F,
      0.022932265F, -0.04017241F, 0.0716367F, -0.14883354F, 0.9329526F,
      0.23081356F, -0.093132526F, 0.050401755F, -0.028815335F, 0.016167035F,
      -0.008537214F, 0.004084163F, -0.001680298F, 0.00053742086F, -9.643318E-5F,
      0.0F, -0.00029789336F, 0.0010953146F, -0.002894853F, 0.006378939F,
      -0.012506568F, 0.022739F, -0.039832495F, 0.07104038F, -0.1476959F,
      0.9344199F, 0.2278938F, -0.09208392F, 0.049847823F, -0.028499193F,
      0.015988145F, -0.008441237F, 0.004037142F, -0.0016602449F, 0.00053059566F,
      -9.498556E-5F, 0.0F, -0.0002960133F, 0.0010872193F, -0.002871947F,
      0.006326415F, -0.01240094F, 0.022544034F, -0.039489634F, 0.07043868F,
      -0.14654581F, 0.9358719F, 0.22497953F, -0.09103381F, 0.04929272F,
      -0.028182363F, 0.015808897F, -0.008345105F, 0.003990071F, -0.0016401873F,
      0.00052377855F, -9.3544775E-5F, 0.0F, -0.00029409974F, 0.0010790197F,
      -0.002848791F, 0.0062733768F, -0.01229435F, 0.022347374F, -0.039143838F,
      0.069831625F, -0.14538328F, 0.93730867F, 0.2220708F, -0.089982234F,
      0.04873648F, -0.027864859F, 0.015629305F, -0.008248821F, 0.0039429525F,
      -0.0016201262F, 0.00051696994F, -9.211089E-5F, 0.0F, -0.00029215254F,
      0.001070716F, -0.0028253854F, 0.0062198243F, -0.012186802F, 0.022149025F,
      -0.03879512F, 0.06921922F, -0.1442083F, 0.9387302F, 0.2191677F,
      -0.088929266F, 0.04817913F, -0.0275467F, 0.015449374F, -0.008152394F,
      0.0038957894F, -0.0016000629F, 0.00051017024F, -9.068398E-5F, 0.0F,
      -0.00029017162F, 0.0010623079F, -0.0028017308F, 0.0061657596F,
      -0.012078296F, 0.021948993F, -0.038443487F, 0.068601474F, -0.14302085F,
      0.9401364F, 0.21627028F, -0.087874964F, 0.047620706F, -0.027227907F,
      0.015269118F, -0.008055828F, 0.0038485848F, -0.0015799986F, 0.00050337985F,
      -8.9264104E-5F, 0.0F, -0.0002881569F, 0.0010537958F, -0.0027778274F,
      0.0061111837F, -0.011968839F, 0.021747286F, -0.038088955F, 0.06797843F,
      -0.14182098F, 0.9415272F, 0.21337865F, -0.086819366F, 0.04706124F,
      -0.026908495F, 0.015088548F, -0.007959127F, 0.0038013412F, -0.0015599346F,
      0.00049659907F, -8.785135E-5F, 0.0F, -0.00028610835F, 0.0010451794F,
      -0.0027536757F, 0.0060560983F, -0.011858432F, 0.021543909F, -0.03773153F,
      0.067350075F, -0.14060865F, 0.9429025F, 0.21049285F, -0.085762545F,
      0.046500757F, -0.026588485F, 0.014907674F, -0.007862301F, 0.0037540616F,
      -0.0015398717F, 0.0004898284F, -8.6445776E-5F, 0.0F, -0.00028402582F,
      0.0010364589F, -0.0027292757F, 0.006000504F, -0.011747077F, 0.021338867F,
      -0.037371222F, 0.06671645F, -0.13938388F, 0.94426244F, 0.20761296F,
      -0.084704556F, 0.045939296F, -0.026267894F, 0.014726505F, -0.0077653513F,
      0.0037067484F, -0.0015198115F, 0.00048306814F, -8.504746E-5F, 0.0F,
      -0.0002819093F, 0.0010276344F, -0.0027046285F, 0.0059444034F, -0.01163478F,
      0.021132171F, -0.03700805F, 0.06607755F, -0.13814668F, 0.94560677F,
      0.20473906F, -0.08364544F, 0.045376886F, -0.025946738F, 0.014545052F,
      -0.0076682856F, 0.0036594048F, -0.0014997548F, 0.00047631873F,
      -8.365646E-5F, 0.0F, -0.00027975868F, 0.0010187057F, -0.0026797343F,
      0.0058877966F, -0.011521543F, 0.020923823F, -0.03664202F, 0.06543341F,
      -0.13689704F, 0.9469356F, 0.20187122F, -0.082585275F, 0.04481356F,
      -0.02562504F, 0.014363327F, -0.00757111F, 0.003612033F, -0.001479703F,
      0.00046958053F, -8.227284E-5F, 0.0F, -0.00027757388F, 0.001009673F,
      -0.0026545934F, 0.005830686F, -0.011407371F, 0.020713832F, -0.036273144F,
      0.06478404F, -0.13563497F, 0.94824886F, 0.19900951F, -0.0815241F,
      0.044249345F, -0.025302816F, 0.014181339F, -0.007473829F, 0.0035646365F,
      -0.0014596572F, 0.0004628539F, -8.0896665E-5F, 0.0F, -0.0002753549F,
      0.0010005364F, -0.0026292065F, 0.0057730735F, -0.011292265F, 0.020502206F,
      -0.03590144F, 0.064129464F, -0.13436049F, 0.94954646F, 0.196154F,
      -0.08046198F, 0.043684274F, -0.024980085F, 0.013999099F, -0.0073764487F,
      0.0035172175F, -0.0014396186F, 0.00045613924F, -7.952801E-5F, 0.0F,
      -0.00027310158F, 0.0009912958F, -0.002603574F, 0.0057149595F, -0.01117623F,
      0.02028895F, -0.03552691F, 0.0634697F, -0.13307357F, 0.9508283F,
      0.19330476F, -0.07939896F, 0.04311838F, -0.024656864F, 0.013816617F,
      -0.007278975F, 0.003469779F, -0.0014195883F, 0.00044943692F, -7.816692E-5F,
      0.0F, -0.00027081394F, 0.0009819514F, -0.0025776965F, 0.005656346F,
      -0.011059269F, 0.020074071F, -0.035149574F, 0.06280476F, -0.13177425F,
      0.9520945F, 0.19046187F, -0.07833511F, 0.042551696F, -0.024333172F,
      0.013633904F, -0.007181413F, 0.0034223236F, -0.0013995676F, 0.00044274732F,
      -7.681347E-5F, 0.0F, -0.00026849186F, 0.0009725032F, -0.0025515743F,
      0.005597235F, -0.010941387F, 0.019857578F, -0.034769442F, 0.062134665F,
      -0.1304625F, 0.95334494F, 0.1876254F, -0.07727047F, 0.04198425F,
      -0.024009027F, 0.01345097F, -0.0070837685F, 0.0033748539F, -0.0013795573F,
      0.00043607075F, -7.546772E-5F, 0.0F, -0.0002661353F, 0.0009629513F,
      -0.002525208F, 0.005537628F, -0.010822587F, 0.019639477F, -0.034386527F,
      0.06145944F, -0.12913835F, 0.95457953F, 0.1847954F, -0.07620511F,
      0.04141607F, -0.023684446F, 0.013267825F, -0.006986047F, 0.003327373F,
      -0.0013595588F, 0.00042940766F, -7.412972E-5F, 0.0F, -0.0002637442F,
      0.00095329573F, -0.0024985985F, 0.0054775267F, -0.010702873F, 0.019419776F,
      -0.034000844F, 0.0607791F, -0.12780182F, 0.9557983F, 0.18197197F,
      -0.075139076F, 0.040847197F, -0.02335945F, 0.013084481F, -0.006888254F,
      0.0032798832F, -0.0013395731F, 0.00042275834F, -7.279953E-5F, 0.0F,
      -0.00026131855F, 0.0009435367F, -0.0024717464F, 0.0054169325F,
      -0.010582248F, 0.019198481F, -0.033612404F, 0.060093664F, -0.1264529F,
      0.9570012F, 0.17915514F, -0.07407242F, 0.040277656F, -0.023034055F,
      0.012900945F, -0.0067903954F, 0.0032323874F, -0.0013196013F,
      0.00041612316F, -7.147721E-5F, 0.0F, -0.00025885823F, 0.0009336742F,
      -0.0024446517F, 0.0053558475F, -0.010460716F, 0.018975602F, -0.033221222F,
      0.059403155F, -0.12509158F, 0.9581882F, 0.17634502F, -0.07300521F,
      0.039707478F, -0.02270828F, 0.012717231F, -0.006692476F, 0.003184888F,
      -0.0012996447F, 0.0004095025F, -7.0162816E-5F, 0.0F, -0.00025636322F,
      0.00092370843F, -0.0024173157F, 0.005294273F, -0.010338282F, 0.018751146F,
      -0.03282731F, 0.058707595F, -0.12371789F, 0.9593592F, 0.17354165F,
      -0.07193749F, 0.039136693F, -0.022382142F, 0.012533347F, -0.0065945024F,
      0.0031373883F, -0.0012797043F, 0.0004028967F, -6.88564E-5F, 0.0F,
      -0.00025383345F, 0.00091363944F, -0.0023897386F, 0.0052322117F,
      -0.01021495F, 0.018525122F, -0.032430682F, 0.058007006F, -0.12233184F,
      0.96051425F, 0.17074512F, -0.07086932F, 0.038565334F, -0.022055661F,
      0.012349305F, -0.006496479F, 0.0030898903F, -0.0012597812F, 0.00039630607F,
      -6.7558016E-5F, 0.0F, -0.0002512689F, 0.00090346736F, -0.0023619211F,
      0.0051696645F, -0.010090723F, 0.018297534F, -0.03203135F, 0.057301402F,
      -0.120933436F, 0.96165323F, 0.16795549F, -0.06980074F, 0.037993435F,
      -0.021728855F, 0.012165113F, -0.006398412F, 0.003042397F, -0.0012398765F,
      0.00038973102F, -6.626772E-5F, 0.0F, -0.0002486695F, 0.0008931923F,
      -0.002333864F, 0.005106634F, -0.009965606F, 0.018068392F, -0.03162933F,
      0.05659081F, -0.11952268F, 0.9627762F, 0.16517282F, -0.06873183F,
      0.03742102F, -0.021401739F, 0.011980783F, -0.0063003064F, 0.0029949113F,
      -0.0012199912F, 0.0003831719F, -6.498556E-5F, 0.0F, -0.00024603526F,
      0.0008828144F, -0.002305568F, 0.005043122F, -0.009839604F, 0.017837707F,
      -0.031224638F, 0.055875253F, -0.11809959F, 0.963883F, 0.16239718F,
      -0.06766262F, 0.036848128F, -0.021074332F, 0.011796325F, -0.0062021683F,
      0.0029474352F, -0.0012001266F, 0.00037662897F, -6.371158E-5F, 0.0F,
      -0.00024336608F, 0.0008723338F, -0.0022770336F, 0.00497913F, -0.009712719F,
      0.017605484F, -0.030817287F, 0.05515475F, -0.11666418F, 0.9649737F,
      0.15962864F, -0.06659318F, 0.036274783F, -0.020746656F, 0.011611749F,
      -0.0061040027F, 0.0028999718F, -0.0011802837F, 0.0003701026F,
      -6.244583E-5F, 0.0F, -0.00024066198F, 0.00086175074F, -0.0022482618F,
      0.00491466F, -0.009584959F, 0.01737173F, -0.030407289F, 0.054429322F,
      -0.11521645F, 0.9660482F, 0.15686727F, -0.06552356F, 0.035701018F,
      -0.020418724F, 0.011427066F, -0.006005815F, 0.0028525235F, -0.0011604634F,
      0.00036359316F, -6.118838E-5F, 0.0F, -0.00023792287F, 0.00085106527F,
      -0.0022192532F, 0.0048497147F, -0.009456324F, 0.017136458F, -0.029994661F,
      0.053698998F, -0.11375642F, 0.9671065F, 0.15411314F, -0.0644538F,
      0.035126865F, -0.020090556F, 0.011242284F, -0.005907611F, 0.0028050928F,
      -0.001140667F, 0.00035710097F, -5.9939248E-5F, 0.0F, -0.00023514873F,
      0.0008402775F, -0.0021900085F, 0.0047842953F, -0.009326822F, 0.016899675F,
      -0.029579416F, 0.052963797F, -0.112284094F, 0.9681486F, 0.1513663F,
      -0.06338398F, 0.034552354F, -0.01976217F, 0.011057416F, -0.005809396F,
      0.0027576827F, -0.0011208955F, 0.00035062633F, -5.8698493E-5F, 0.0F,
      -0.00023233956F, 0.00082938775F, -0.0021605284F, 0.0047184047F,
      -0.009196456F, 0.016661389F, -0.029161572F, 0.052223742F, -0.11079949F,
      0.9691744F, 0.14862683F, -0.06231413F, 0.033977512F, -0.019433582F,
      0.010872469F, -0.005711175F, 0.0027102956F, -0.0011011498F, 0.00034416956F,
      -5.7466157E-5F, 0.0F, -0.0002294953F, 0.0008183961F, -0.0021308141F,
      0.0046520443F, -0.00906523F, 0.016421607F, -0.028741142F, 0.051478855F,
      -0.10930262F, 0.9701839F, 0.1458948F, -0.061244316F, 0.033402376F,
      -0.019104814F, 0.010687456F, -0.0056129536F, 0.002662934F, -0.0010814313F,
      0.00033773103F, -5.6242287E-5F, 0.0F, -0.00022661594F, 0.0008073028F,
      -0.0021008658F, 0.0045852168F, -0.00893315F, 0.01618034F, -0.028318143F,
      0.050729167F, -0.107793495F, 0.97117704F, 0.14317024F, -0.060174584F,
      0.032826975F, -0.018775878F, 0.010502385F, -0.0055147368F, 0.0026156006F,
      -0.0010617407F, 0.00033131102F, -5.502692E-5F, 0.0F, -0.00022370147F,
      0.0007961079F, -0.0020706847F, 0.004517924F, -0.008800221F, 0.015937597F,
      -0.027892588F, 0.049974695F, -0.10627213F, 0.97215384F, 0.14045326F,
      -0.059104994F, 0.032251336F, -0.018446798F, 0.010317268F, -0.0054165307F,
      0.0025682976F, -0.0010420791F, 0.00032490987F, -5.3820102E-5F, 0.0F,
      -0.00022075184F, 0.0007848118F, -0.0020402714F, 0.004450168F,
      -0.0086664455F, 0.015693385F, -0.027464496F, 0.04921547F, -0.10473855F,
      0.9731142F, 0.1377439F, -0.05803559F, 0.031675488F, -0.018117586F,
      0.010132113F, -0.0053183404F, 0.002521028F, -0.0010224476F, 0.0003185279F,
      -5.2621872E-5F, 0.0F, -0.00021776704F, 0.00077341456F, -0.002009627F,
      0.004381952F, -0.008531831F, 0.015447717F, -0.02703388F, 0.04845151F,
      -0.103192754F, 0.97405815F, 0.13504224F, -0.05696643F, 0.031099468F,
      -0.017788263F, 0.00994693F, -0.0052201706F, 0.0024737942F, -0.0010028473F,
      0.00031216536F, -5.1432267E-5F, 0.0F, -0.00021474707F, 0.0007619164F,
      -0.0019787522F, 0.004313277F, -0.008396381F, 0.015200599F, -0.026600758F,
      0.047682844F, -0.101634756F, 0.97498566F, 0.13234831F, -0.05589757F,
      0.030523302F, -0.017458845F, 0.009761731F, -0.0051220274F, 0.0024265985F,
      -0.0009832792F, 0.0003058226F, -5.0251325E-5F, 0.0F, -0.00021169189F,
      0.0007503176F, -0.001947648F, 0.004244146F, -0.0082601F, 0.014952041F,
      -0.026165146F, 0.0469095F, -0.10006459F, 0.97589666F, 0.1296622F,
      -0.054829057F, 0.02994702F, -0.017129352F, 0.009576525F, -0.0050239153F,
      0.0023794437F, -0.0009637442F, 0.00029949998F, -4.9079088E-5F, 0.0F,
      -0.00020860152F, 0.0007386184F, -0.0019163153F, 0.0041745612F,
      -0.008122994F, 0.014702054F, -0.02572706F, 0.0461315F, -0.09848225F,
      0.97679114F, 0.12698399F, -0.053760946F, 0.029370654F, -0.016799798F,
      0.009391321F, -0.0049258405F, 0.002332332F, -0.00094424334F, 0.0002931977F,
      -4.791559E-5F, 0.0F, -0.00020547592F, 0.0007268189F, -0.0018847549F,
      0.004104525F, -0.007985068F, 0.014450646F, -0.025286514F, 0.045348868F,
      -0.096887775F, 0.97766906F, 0.1243137F, -0.05269328F, 0.028794233F,
      -0.016470203F, 0.00920613F, -0.004827807F, 0.0022852663F, -0.0009247777F,
      0.00028691613F, -4.6760862E-5F, 0.0F, -0.00020231512F, 0.0007149195F,
      -0.0018529677F, 0.00403404F, -0.007846327F, 0.014197826F, -0.024843529F,
      0.044561636F, -0.09528116F, 0.9785304F, 0.12165142F, -0.051626127F,
      0.028217785F, -0.016140586F, 0.009020962F, -0.0047298213F, 0.0022382487F,
      -0.0009053482F, 0.0002806555F, -4.5614943E-5F, 0.0F, -0.00019911908F,
      0.00070292037F, -0.0018209547F, 0.003963108F, -0.007706775F, 0.013943607F,
      -0.024398122F, 0.04376983F, -0.09366244F, 0.9793752F, 0.1189972F,
      -0.050559524F, 0.027641343F, -0.015810959F, 0.008835825F, -0.004631888F,
      0.0021912819F, -0.0008859559F, 0.00027441618F, -4.447786E-5F, 0.0F,
      -0.00019588781F, 0.00069082173F, -0.0017887169F, 0.0038917325F,
      -0.007566419F, 0.013687995F, -0.023950305F, 0.04297347F, -0.09203162F,
      0.9802033F, 0.11635111F, -0.049493533F, 0.027064936F, -0.015481344F,
      0.008650731F, -0.004534012F, 0.0021443684F, -0.00086660165F, 0.0002681984F,
      -4.334965E-5F, 0.0F, -0.00019262133F, 0.00067862397F, -0.0017562554F,
      0.0038199152F, -0.0074252635F, 0.013431002F, -0.0235001F, 0.042172592F,
      -0.09038873F, 0.9810147F, 0.11371321F, -0.048428196F, 0.026488593F,
      -0.015151757F, 0.00846569F, -0.004436199F, 0.0020975103F, -0.00084728654F,
      0.0002620025F, -4.2230346E-5F, 0.0F, -0.00018931963F, 0.00066632725F,
      -0.001723571F, 0.003747659F, -0.007283314F, 0.013172639F, -0.023047524F,
      0.041367218F, -0.088733785F, 0.9818095F, 0.11108355F, -0.04736357F,
      0.025912344F, -0.014822215F, 0.008280708F, -0.0043384535F, 0.0020507101F,
      -0.00082801154F, 0.0002558287F, -4.111997E-5F, 0.0F, -0.0001859827F,
      0.0006539319F, -0.0016906647F, 0.0036749663F, -0.007140576F, 0.012912914F,
      -0.022592591F, 0.040557377F, -0.0870668F, 0.9825876F, 0.10846221F,
      -0.046299703F, 0.025336217F, -0.014492735F, 0.0080958F, -0.0042407815F,
      0.0020039708F, -0.0008087776F, 0.0002496773F, -4.0018556E-5F, 0.0F,
      -0.00018261059F, 0.0006414381F, -0.0016575378F, 0.0036018395F,
      -0.006997055F, 0.012651838F, -0.022135323F, 0.0397431F, -0.085387796F,
      0.9833489F, 0.10584923F, -0.04523665F, 0.024760244F, -0.014163336F,
      0.007910972F, -0.0041431873F, 0.001957294F, -0.00078958564F, 0.0002435486F,
      -3.892613E-5F, 0.0F, -0.00017920327F, 0.0006288463F, -0.0016241911F,
      0.0035282818F, -0.006852756F, 0.012389422F, -0.021675736F, 0.03892441F,
      -0.0836968F, 0.9840935F, 0.10324468F, -0.04417446F, 0.024184454F,
      -0.013834032F, 0.0077262353F, -0.0040456764F, 0.0019106827F,
      -0.00077043666F, 0.00023744286F, -3.7842718E-5F, 0.0F, -0.00017576078F,
      0.00061615667F, -0.0015906256F, 0.0034542955F, -0.006707685F,
      0.0121256765F, -0.021213848F, 0.038101345F, -0.08199382F, 0.98482126F,
      0.10064861F, -0.04311318F, 0.023608875F, -0.013504843F, 0.0075415988F,
      -0.0039482536F, 0.0018641389F, -0.0007513315F, 0.00023136035F,
      -3.6768346E-5F, 0.0F, -0.00017228312F, 0.00060336967F, -0.0015568427F,
      0.0033798835F, -0.006561848F, 0.011860612F, -0.020749679F, 0.037273925F,
      -0.08027889F, 0.9855323F, 0.098061085F, -0.04205286F, 0.023033537F,
      -0.013175785F, 0.0073570726F, -0.0038509245F, 0.0018176651F,
      -0.00073227123F, 0.00022530134F, -3.5703037E-5F, 0.0F, -0.00016877033F,
      0.00059048546F, -0.0015228433F, 0.0033050482F, -0.00641525F, 0.011594238F,
      -0.020283243F, 0.036442183F, -0.07855202F, 0.98622644F, 0.09548217F,
      -0.040993556F, 0.02245847F, -0.012846874F, 0.0071726656F, -0.0037536935F,
      0.0017712638F, -0.0007132567F, 0.00021926609F, -3.464682E-5F, 0.0F,
      -0.00016522242F, 0.0005775044F, -0.0014886284F, 0.0032297925F,
      -0.006267897F, 0.011326565F, -0.019814564F, 0.035606146F, -0.07681325F,
      0.9869037F, 0.092911914F, -0.039935313F, 0.0218837F, -0.012518129F,
      0.006988388F, -0.003656566F, 0.0017249371F, -0.0006942889F, 0.00021325487F,
      -3.3599714E-5F, 0.0F, -0.0001616394F, 0.0005644269F, -0.0014541993F,
      0.0031541195F, -0.006119795F, 0.011057607F, -0.019343656F, 0.034765847F,
      -0.07506259F, 0.9875642F, 0.090350375F, -0.03887818F, 0.021309258F,
      -0.012189565F, 0.006804249F, -0.0035595465F, 0.0016786875F, -0.0006753686F,
      0.00020726793F, -3.2561737E-5F, 0.0F, -0.00015802131F, 0.0005512532F,
      -0.0014195571F, 0.0030780316F, -0.0059709502F, 0.010787372F, -0.018870542F,
      0.033921316F, -0.07330006F, 0.9882077F, 0.08779761F, -0.03782221F,
      0.020735176F, -0.0118612F, 0.006620258F, -0.0034626406F, 0.0016325173F,
      -0.00065649685F, 0.00020130555F, -3.1532916E-5F, 0.0F, -0.0001543682F,
      0.0005379837F, -0.0013847031F, 0.003001532F, -0.0058213677F, 0.010515871F,
      -0.018395238F, 0.033072583F, -0.07152569F, 0.9888344F, 0.085253686F,
      -0.03676745F, 0.020161478F, -0.011533051F, 0.006436425F, -0.0033658526F,
      0.0015864287F, -0.0006376745F, 0.00019536795F, -3.0513267E-5F, 0.0F,
      -0.00015068008F, 0.0005246187F, -0.0013496383F, 0.0029246234F,
      -0.005671054F, 0.010243117F, -0.017917763F, 0.03221968F, -0.069739506F,
      0.9894441F, 0.08271865F, -0.03571395F, 0.019588195F, -0.011205133F,
      0.006252758F, -0.003269188F, 0.0015404242F, -0.00061890244F,
      0.00018945537F, -2.950281E-5F, 0.0F, -0.00014695698F, 0.00051115867F,
      -0.001314364F, 0.0028473088F, -0.0055200155F, 0.00996912F, -0.01743814F,
      0.031362634F, -0.06794153F, 0.9900368F, 0.08019255F, -0.034661755F,
      0.019015353F, -0.010877465F, 0.0060692686F, -0.0031726514F, 0.0014945059F,
      -0.0006001816F, 0.0001835681F, -2.8501558E-5F, 0.0F, -0.00014319895F,
      0.0004976039F, -0.0012788813F, 0.0027695913F, -0.005368258F, 0.009693891F,
      -0.016956385F, 0.03050148F, -0.066131786F, 0.99061257F, 0.077675454F,
      -0.03361092F, 0.018442985F, -0.010550062F, 0.0058859643F, -0.0030762476F,
      0.0014486762F, -0.00058151275F, 0.00017770636F, -2.7509534E-5F, 0.0F,
      -0.00013940604F, 0.00048395473F, -0.0012431915F, 0.0026914736F,
      -0.005215787F, 0.009417443F, -0.016472518F, 0.029636247F, -0.0643103F,
      0.99117136F, 0.07516742F, -0.03256149F, 0.017871115F, -0.010222941F,
      0.005702855F, -0.0029799817F, 0.0014029372F, -0.00056289695F,
      0.00017187039F, -2.6526748E-5F, 0.0F, -0.00013557827F, 0.00047021158F,
      -0.0012072959F, 0.0026129587F, -0.0050626094F, 0.009139786F, -0.015986562F,
      0.02876697F, -0.062477093F, 0.99171317F, 0.07266849F, -0.031513512F,
      0.017299775F, -0.009896118F, 0.0055199503F, -0.0028838583F, 0.0013572912F,
      -0.0005443349F, 0.00016606042F, -2.555322E-5F, 0.0F, -0.00013171571F,
      0.00045637487F, -0.0011711956F, 0.00253405F, -0.004908731F, 0.008860931F,
      -0.015498534F, 0.02789368F, -0.060632203F, 0.99223787F, 0.070178725F,
      -0.030467035F, 0.016728992F, -0.0095696105F, 0.005337259F, -0.0027878822F,
      0.0013117405F, -0.0005258275F, 0.00016027669F, -2.4588959E-5F, 0.0F,
      -0.00012781839F, 0.00044244496F, -0.0011348922F, 0.0024547505F,
      -0.004754159F, 0.008580891F, -0.015008454F, 0.027016409F, -0.058775645F,
      0.9927456F, 0.06769818F, -0.029422106F, 0.016158793F, -0.009243435F,
      0.00515479F, -0.0026920584F, 0.0012662873F, -0.0005073757F, 0.00015451942F,
      -2.3633978E-5F, 0.0F, -0.00012388638F, 0.00042842227F, -0.0010983867F,
      0.002375063F, -0.0045988993F, 0.008299679F, -0.014516344F, 0.02613519F,
      -0.056907456F, 0.99323624F, 0.06522691F, -0.028378777F, 0.0155892065F,
      -0.008917606F, 0.0049725533F, -0.0025963916F, 0.0012209337F,
      -0.0004889802F, 0.00014878888F, -2.2688291E-5F, 0.0F, -0.00011991971F,
      0.0004143072F, -0.0010616805F, 0.002294991F, -0.004442958F, 0.008017304F,
      -0.014022224F, 0.025250055F, -0.05502766F, 0.9937098F, 0.062764965F,
      -0.02733709F, 0.0150202615F, -0.008592143F, 0.004790557F, -0.0025008863F,
      0.0011756821F, -0.0004706419F, 0.00014308524F, -2.1751908E-5F, 0.0F,
      -0.000115918454F, 0.0004001002F, -0.0010247749F, 0.0022145375F,
      -0.0042863423F, 0.007733781F, -0.013526113F, 0.024361039F, -0.05313628F,
      0.9941663F, 0.060312398F, -0.026297094F, 0.014451984F, -0.008267059F,
      0.0046088113F, -0.0024055475F, 0.0011305343F, -0.0004523617F,
      0.00013740876F, -2.0824838E-5F, 0.0F, -0.00011188267F, 0.00038580166F,
      -0.0009876713F, 0.0021337057F, -0.0041290578F, 0.0074491194F,
      -0.013028034F, 0.023468176F, -0.051233355F, 0.99460566F, 0.05786926F,
      -0.025258837F, 0.013884404F, -0.007942371F, 0.0044273245F, -0.0023103796F,
      0.0010854929F, -0.00043414033F, 0.00013175963F, -1.9907091E-5F, 0.0F,
      -0.00010781242F, 0.00037141202F, -0.00095037103F, 0.0020524987F,
      -0.003971112F, 0.0071633323F, -0.012528006F, 0.022571497F, -0.049318906F,
      0.99502796F, 0.0554356F, -0.024222365F, 0.013317547F, -0.0076180967F,
      0.0042461064F, -0.0022153878F, 0.0010405598F, -0.00041597863F,
      0.00012613808F, -1.8998673E-5F, 0.0F, -0.00010370777F, 0.00035693173F,
      -0.0009128756F, 0.0019709202F, -0.003812511F, 0.006876433F, -0.012026052F,
      0.02167104F, -0.047392968F, 0.9954331F, 0.05301148F, -0.023187723F,
      0.012751441F, -0.0072942507F, 0.004065165F, -0.002120576F, 0.0009957372F,
      -0.00039787745F, 0.000120544326F, -1.8099594E-5F, 0.0F, -9.956879E-5F,
      0.00034236128F, -0.0008751862F, 0.0018889734F, -0.0036532616F,
      0.006588432F, -0.0115221925F, 0.020766838F, -0.045455568F, 0.99582106F,
      0.05059694F, -0.022154959F, 0.012186115F, -0.006970849F, 0.0038845092F,
      -0.0020259495F, 0.0009510271F, -0.00037983755F, 0.000114978575F,
      -1.7209855E-5F, 0.0F, -9.5395546E-5F, 0.00032770107F, -0.00083730434F,
      0.0018066614F, -0.0034933707F, 0.006299343F, -0.011016448F, 0.019858923F,
      -0.043506738F, 0.9961919F, 0.04819204F, -0.021124119F, 0.0116215935F,
      -0.006647908F, 0.0037041486F, -0.0019315125F, 0.0009064317F,
      -0.00036185974F, 0.000109441025F, -1.6329464E-5F, 0.0F, -9.1188114E-5F,
      0.0003129516F, -0.00079923146F, 0.0017239876F, -0.0033328452F,
      0.0060091782F, -0.010508842F, 0.018947335F, -0.041546505F, 0.99654555F,
      0.045796823F, -0.02009525F, 0.011057906F, -0.0063254433F, 0.0035240918F,
      -0.0018372696F, 0.0008619531F, -0.00034394482F, 0.00010393188F,
      -1.5458427E-5F, 0.0F, -8.694657E-5F, 0.00029811333F, -0.00076096895F,
      0.0016409556F, -0.003171692F, 0.00571795F, -0.0099993935F, 0.018032104F,
      -0.03957491F, 0.996882F, 0.04341134F, -0.019068394F, 0.01049508F,
      -0.0060034706F, 0.0033443475F, -0.0017432255F, 0.0008175935F,
      -0.00032609355F, 9.845135E-5F, -1.4596744E-5F, 0.0F, -8.267101E-5F,
      0.00028318673F, -0.00072251837F, 0.0015575686F, -0.0030099174F,
      0.0054256716F, -0.009488126F, 0.01711327F, -0.037591975F, 0.9972013F,
      0.041035645F, -0.0180436F, 0.009933139F, -0.005682006F, 0.0031649244F,
      -0.0016493846F, 0.00077335467F, -0.00030830668F, 9.2999624E-5F,
      -1.3744419E-5F, 0.0F };

    static const int16_T tmp_2[441] = { 0, 160, 320, 39, 199, 359, 78, 238, 398,
      117, 277, 437, 156, 316, 35, 195, 355, 74, 234, 394, 113, 273, 433, 152,
      312, 31, 191, 351, 70, 230, 390, 109, 269, 429, 148, 308, 27, 187, 347, 66,
      226, 386, 105, 265, 425, 144, 304, 23, 183, 343, 62, 222, 382, 101, 261,
      421, 140, 300, 19, 179, 339, 58, 218, 378, 97, 257, 417, 136, 296, 15, 175,
      335, 54, 214, 374, 93, 253, 413, 132, 292, 11, 171, 331, 50, 210, 370, 89,
      249, 409, 128, 288, 7, 167, 327, 46, 206, 366, 85, 245, 405, 124, 284, 3,
      163, 323, 42, 202, 362, 81, 241, 401, 120, 280, 440, 159, 319, 38, 198,
      358, 77, 237, 397, 116, 276, 436, 155, 315, 34, 194, 354, 73, 233, 393,
      112, 272, 432, 151, 311, 30, 190, 350, 69, 229, 389, 108, 268, 428, 147,
      307, 26, 186, 346, 65, 225, 385, 104, 264, 424, 143, 303, 22, 182, 342, 61,
      221, 381, 100, 260, 420, 139, 299, 18, 178, 338, 57, 217, 377, 96, 256,
      416, 135, 295, 14, 174, 334, 53, 213, 373, 92, 252, 412, 131, 291, 10, 170,
      330, 49, 209, 369, 88, 248, 408, 127, 287, 6, 166, 326, 45, 205, 365, 84,
      244, 404, 123, 283, 2, 162, 322, 41, 201, 361, 80, 240, 400, 119, 279, 439,
      158, 318, 37, 197, 357, 76, 236, 396, 115, 275, 435, 154, 314, 33, 193,
      353, 72, 232, 392, 111, 271, 431, 150, 310, 29, 189, 349, 68, 228, 388,
      107, 267, 427, 146, 306, 25, 185, 345, 64, 224, 384, 103, 263, 423, 142,
      302, 21, 181, 341, 60, 220, 380, 99, 259, 419, 138, 298, 17, 177, 337, 56,
      216, 376, 95, 255, 415, 134, 294, 13, 173, 333, 52, 212, 372, 91, 251, 411,
      130, 290, 9, 169, 329, 48, 208, 368, 87, 247, 407, 126, 286, 5, 165, 325,
      44, 204, 364, 83, 243, 403, 122, 282, 1, 161, 321, 40, 200, 360, 79, 239,
      399, 118, 278, 438, 157, 317, 36, 196, 356, 75, 235, 395, 114, 274, 434,
      153, 313, 32, 192, 352, 71, 231, 391, 110, 270, 430, 149, 309, 28, 188,
      348, 67, 227, 387, 106, 266, 426, 145, 305, 24, 184, 344, 63, 223, 383,
      102, 262, 422, 141, 301, 20, 180, 340, 59, 219, 379, 98, 258, 418, 137,
      297, 16, 176, 336, 55, 215, 375, 94, 254, 414, 133, 293, 12, 172, 332, 51,
      211, 371, 90, 250, 410, 129, 289, 8, 168, 328, 47, 207, 367, 86, 246, 406,
      125, 285, 4, 164, 324, 43, 203, 363, 82, 242, 402, 121, 281 };

    static const int16_T tmp_3[160] = { 0, 3, 6, 9, 12, 14, 17, 20, 23, 25, 28,
      31, 34, 36, 39, 42, 45, 47, 50, 53, 56, 58, 61, 64, 67, 69, 72, 75, 78, 80,
      83, 86, 89, 91, 94, 97, 100, 102, 105, 108, 111, 114, 116, 119, 122, 125,
      127, 130, 133, 136, 138, 141, 144, 147, 149, 152, 155, 158, 160, 163, 166,
      169, 171, 174, 177, 180, 182, 185, 188, 191, 193, 196, 199, 202, 204, 207,
      210, 213, 215, 218, 221, 224, 227, 229, 232, 235, 238, 240, 243, 246, 249,
      251, 254, 257, 260, 262, 265, 268, 271, 273, 276, 279, 282, 284, 287, 290,
      293, 295, 298, 301, 304, 306, 309, 312, 315, 317, 320, 323, 326, 328, 331,
      334, 337, 340, 342, 345, 348, 351, 353, 356, 359, 362, 364, 367, 370, 373,
      375, 378, 381, 384, 386, 389, 392, 395, 397, 400, 403, 406, 408, 411, 414,
      417, 419, 422, 425, 428, 430, 433, 436, 439 };

    static const int16_T tmp_4[160] = { 3, 6, 9, 12, 14, 17, 20, 23, 25, 28, 31,
      34, 36, 39, 42, 45, 47, 50, 53, 56, 58, 61, 64, 67, 69, 72, 75, 78, 80, 83,
      86, 89, 91, 94, 97, 100, 102, 105, 108, 111, 114, 116, 119, 122, 125, 127,
      130, 133, 136, 138, 141, 144, 147, 149, 152, 155, 158, 160, 163, 166, 169,
      171, 174, 177, 180, 182, 185, 188, 191, 193, 196, 199, 202, 204, 207, 210,
      213, 215, 218, 221, 224, 227, 229, 232, 235, 238, 240, 243, 246, 249, 251,
      254, 257, 260, 262, 265, 268, 271, 273, 276, 279, 282, 284, 287, 290, 293,
      295, 298, 301, 304, 306, 309, 312, 315, 317, 320, 323, 326, 328, 331, 334,
      337, 340, 342, 345, 348, 351, 353, 356, 359, 362, 364, 367, 370, 373, 375,
      378, 381, 384, 386, 389, 392, 395, 397, 400, 403, 406, 408, 411, 414, 417,
      419, 422, 425, 428, 430, 433, 436, 439, 441 };

    static const uint8_T tmp_5[441] = { 0U, 0U, 0U, 1U, 1U, 1U, 2U, 2U, 2U, 3U,
      3U, 3U, 4U, 4U, 5U, 5U, 5U, 6U, 6U, 6U, 7U, 7U, 7U, 8U, 8U, 9U, 9U, 9U,
      10U, 10U, 10U, 11U, 11U, 11U, 12U, 12U, 13U, 13U, 13U, 14U, 14U, 14U, 15U,
      15U, 15U, 16U, 16U, 17U, 17U, 17U, 18U, 18U, 18U, 19U, 19U, 19U, 20U, 20U,
      21U, 21U, 21U, 22U, 22U, 22U, 23U, 23U, 23U, 24U, 24U, 25U, 25U, 25U, 26U,
      26U, 26U, 27U, 27U, 27U, 28U, 28U, 29U, 29U, 29U, 30U, 30U, 30U, 31U, 31U,
      31U, 32U, 32U, 33U, 33U, 33U, 34U, 34U, 34U, 35U, 35U, 35U, 36U, 36U, 37U,
      37U, 37U, 38U, 38U, 38U, 39U, 39U, 39U, 40U, 40U, 40U, 41U, 41U, 42U, 42U,
      42U, 43U, 43U, 43U, 44U, 44U, 44U, 45U, 45U, 46U, 46U, 46U, 47U, 47U, 47U,
      48U, 48U, 48U, 49U, 49U, 50U, 50U, 50U, 51U, 51U, 51U, 52U, 52U, 52U, 53U,
      53U, 54U, 54U, 54U, 55U, 55U, 55U, 56U, 56U, 56U, 57U, 57U, 58U, 58U, 58U,
      59U, 59U, 59U, 60U, 60U, 60U, 61U, 61U, 62U, 62U, 62U, 63U, 63U, 63U, 64U,
      64U, 64U, 65U, 65U, 66U, 66U, 66U, 67U, 67U, 67U, 68U, 68U, 68U, 69U, 69U,
      70U, 70U, 70U, 71U, 71U, 71U, 72U, 72U, 72U, 73U, 73U, 74U, 74U, 74U, 75U,
      75U, 75U, 76U, 76U, 76U, 77U, 77U, 78U, 78U, 78U, 79U, 79U, 79U, 80U, 80U,
      80U, 81U, 81U, 81U, 82U, 82U, 83U, 83U, 83U, 84U, 84U, 84U, 85U, 85U, 85U,
      86U, 86U, 87U, 87U, 87U, 88U, 88U, 88U, 89U, 89U, 89U, 90U, 90U, 91U, 91U,
      91U, 92U, 92U, 92U, 93U, 93U, 93U, 94U, 94U, 95U, 95U, 95U, 96U, 96U, 96U,
      97U, 97U, 97U, 98U, 98U, 99U, 99U, 99U, 100U, 100U, 100U, 101U, 101U, 101U,
      102U, 102U, 103U, 103U, 103U, 104U, 104U, 104U, 105U, 105U, 105U, 106U,
      106U, 107U, 107U, 107U, 108U, 108U, 108U, 109U, 109U, 109U, 110U, 110U,
      111U, 111U, 111U, 112U, 112U, 112U, 113U, 113U, 113U, 114U, 114U, 115U,
      115U, 115U, 116U, 116U, 116U, 117U, 117U, 117U, 118U, 118U, 119U, 119U,
      119U, 120U, 120U, 120U, 121U, 121U, 121U, 122U, 122U, 122U, 123U, 123U,
      124U, 124U, 124U, 125U, 125U, 125U, 126U, 126U, 126U, 127U, 127U, 128U,
      128U, 128U, 129U, 129U, 129U, 130U, 130U, 130U, 131U, 131U, 132U, 132U,
      132U, 133U, 133U, 133U, 134U, 134U, 134U, 135U, 135U, 136U, 136U, 136U,
      137U, 137U, 137U, 138U, 138U, 138U, 139U, 139U, 140U, 140U, 140U, 141U,
      141U, 141U, 142U, 142U, 142U, 143U, 143U, 144U, 144U, 144U, 145U, 145U,
      145U, 146U, 146U, 146U, 147U, 147U, 148U, 148U, 148U, 149U, 149U, 149U,
      150U, 150U, 150U, 151U, 151U, 152U, 152U, 152U, 153U, 153U, 153U, 154U,
      154U, 154U, 155U, 155U, 156U, 156U, 156U, 157U, 157U, 157U, 158U, 158U,
      158U, 159U, 159U };

    boolean_T exitg1;

    /* InitializeConditions for Buffer: '<S10>/Input Buffer' */
    for (i = 0; i < 3200; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_CircBuf[i] =
        AudioSmartSpeakerOnJetsonNano_P.InputBuffer_ic;
    }

    AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_inBufPtrIdx = 1600;
    AudioSmartSpeakerOnJetsonNano_DW.InputBuffer_outBufPtrIdx = 240;

    /* End of InitializeConditions for Buffer: '<S10>/Input Buffer' */

    /* InitializeConditions for Buffer: '<S10>/Output Buffer' */
    for (i = 0; i < 9800; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_CircBuf[i] =
        AudioSmartSpeakerOnJetsonNano_P.OutputBuffer_ic;
    }

    AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_inBufPtrIdx = 98;
    AudioSmartSpeakerOnJetsonNano_DW.OutputBuffer_outBufPtrIdx = 88;

    /* End of InitializeConditions for Buffer: '<S10>/Output Buffer' */

    /* InitializeConditions for DiscreteFilter: '<S2>/Discrete Filter' */
    AudioSmartSpeakerOnJetsonNano_DW.DiscreteFilter_states =
      AudioSmartSpeakerOnJetsonNano_P.DiscreteFilter_InitialStates;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Speaker Output Processing ' */
    /* Start for MATLABSystem: '<S4>/Audio File Read1' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxInitialized = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.LoopCount = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle = NULL;
    nulHandle = AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle;
    memcpy(&b_2[0], &b_3[0], 123U * sizeof(char_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle = MW_sox_init(&b_2[0]);
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle != nulHandle) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxInitialized = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_l.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S4>/Audio File Read1' */
    MW_sox_seek(AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle, 0);

    /* Start for MATLABSystem: '<S4>/Graphic EQ' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.matlabCodegenIsDeleted
      = true;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.matlabCodegenIsDeleted = true;
    AudioSmartSpeakerOnJetsonNano_GraphicEQ_GraphicEQ
      (&AudioSmartSpeakerOnJetsonNano_DW.obj_e);
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pSampleRateDialog =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_SampleRate;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_31_5;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_63;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_125;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_250;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_500;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_1000;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_2000;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_4000;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_8000;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz =
      AudioSmartSpeakerOnJetsonNano_P.GraphicEQ_Gain_16000;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = true;
    }

    val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_31_5Hz;
    val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_63Hz;
    val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_125Hz;
    val[3] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_250Hz;
    val[4] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_500Hz;
    val[5] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_1000Hz;
    val[6] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_2000Hz;
    val[7] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_4000Hz;
    val[8] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_8000Hz;
    val[9] = AudioSmartSpeakerOnJetsonNano_DW.obj_e.Gain_16000Hz;
    memset(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], 0, 30U * sizeof
           (real_T));
    memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_e.pGains[0], &val[0], 10U *
           sizeof(real_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.isSetupComplete = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.isInitialized = 0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.matlabCodegenIsDeleted
      = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ =
      &AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0;
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->TunablePropsChanged = true;
    }

    Fs = AudioSmartSpeakerOnJetsonNano_DW.obj_e.pSampleRateDialog;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->SampleRate = Fs;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->pIsGainInSync = false;
    AudioSmartSpeakerOnJetsonNano_graphicEQ_setGainsToEQ
      (&AudioSmartSpeakerOnJetsonNano_DW.obj_e);
    AudioSmartSpeakerOnJetsonNano_SystemCore_setup
      (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ);
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pNumChannels = 2.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.isSetupComplete = true;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S4>/Graphic EQ' */
    flag = (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isInitialized == 1);
    if (flag) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->TunablePropsChanged = true;
    }

    Fs = AudioSmartSpeakerOnJetsonNano_DW.obj_e.pSampleRateDialog;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->SampleRate = Fs;
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->pIsGainInSync = false;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isInitialized == 1) {
      obj = AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->pMPEQ1;
      if ((obj->isInitialized == 1) && (obj->SOSFilterObj.isInitialized == 1)) {
        /* System object Initialization function: dsp.SOSFilter */
        AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
          (obj->SOSFilterObj.cSFunObject.U1, obj->SOSFilterObj.cSFunObject.U2,
           tmp);
        for (i = 0; i < 50; i++) {
          obj->SOSFilterObj.cSFunObject.coefficients[i] = tmp[i];
        }

        AudioSmartSpeakerOnJetsonNano_dspSOSFilter_coefficients
          (obj->SOSFilterObj.cSFunObject.U1, obj->SOSFilterObj.cSFunObject.U2,
           tmp);
        for (i = 0; i < 50; i++) {
          obj->SOSFilterObj.cSFunObject.coefficients[i] = tmp[i];
        }

        mw_arm_biquad_cascade_df2T_init_f32(&obj->SOSFilterObj.cSFunObject.S,
          10U, &obj->SOSFilterObj.cSFunObject.coefficients[0],
          &obj->SOSFilterObj.cSFunObject.pState[0], 2U, 2U);
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S4>/Graphic EQ' */

    /* Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[0] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[0];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[0] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[0];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[0] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[0];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[1] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[1];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[1] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[1];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[1] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[1];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[2] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_Frequencies[2];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[2] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_QualityFactors[2];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[2] =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_PeakGains[2];
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pSampleRateDialog =
      AudioSmartSpeakerOnJetsonNano_P.MultibandParametricEQ_SampleRate;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privFrequencies[i] = tmp_0[i];
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privQualityFactors[i] = 1.6;
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privPeakGains[i] = 0.0;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SOSFilterObj.isInitialized = 0;

    /* System object Constructor function: dsp.SOSFilter */
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SOSFilterObj.cSFunObject.P0_ICRTP
      = 0.0F;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SampleRate =
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pSampleRateDialog;
    flag = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privFrequencies[i] ==
            AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[i])) {
        flag = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!flag) {
      memcpy(&val[0],
             &AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privFrequencies[0], 10U
             * sizeof(real_T));
      val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[0];
      val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[1];
      val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.Frequencies[2];
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privFrequencies[0],
             &val[0], 10U * sizeof(real_T));
    }

    flag = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privQualityFactors[i] ==
            AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[i])) {
        flag = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!flag) {
      memcpy(&val[0],
             &AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privQualityFactors[0],
             10U * sizeof(real_T));
      val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[0];
      val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[1];
      val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.QualityFactors[2];
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privQualityFactors[0],
             &val[0], 10U * sizeof(real_T));
    }

    flag = true;
    i = 0;
    exitg1 = false;
    while (!exitg1 && (i < 3)) {
      if (!(AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privPeakGains[i] ==
            AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[i])) {
        flag = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (!flag) {
      memcpy(&val[0], &AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privPeakGains
             [0], 10U * sizeof(real_T));
      val[0] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[0];
      val[1] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[1];
      val[2] = AudioSmartSpeakerOnJetsonNano_DW.obj_p.PeakGains[2];
      memcpy(&AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privPeakGains[0], &val
             [0], 10U * sizeof(real_T));
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.NumChannels = 2.0;
    Nyquist = (real32_T)AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SampleRate /
      2.0F;
    for (i = 0; i < 10; i++) {
      u1 = (real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privFrequencies[i];
      if ((Nyquist <= u1) || rtIsNaNF(u1)) {
        minval[i] = Nyquist;
      } else {
        minval[i] = u1;
      }
    }

    AudioSmartSpeakerOnJetsonNano_multibandParametricEQ_designEQ_du(minval,
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privPeakGains,
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.privQualityFactors, (real32_T)
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SampleRate,
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.NumMatrix,
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.DenMatrix);
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.AreFiltersDesigned = true;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.isSetupComplete = true;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.TunablePropsChanged = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.TunablePropsChanged = false;

    /* End of Start for MATLABSystem: '<S4>/Multiband Parametric EQ' */

    /* Start for MATLABSystem: '<S4>/Limiter' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.pNumChannels = -1.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.pSampleRateInherit = -1.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.Threshold =
      AudioSmartSpeakerOnJetsonNano_P.Limiter_Threshold;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.KneeWidth =
      AudioSmartSpeakerOnJetsonNano_P.Limiter_KneeWidth;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime =
      AudioSmartSpeakerOnJetsonNano_P.Limiter_AttackTime;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime =
      AudioSmartSpeakerOnJetsonNano_P.Limiter_ReleaseTime;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.MakeUpGain =
      AudioSmartSpeakerOnJetsonNano_P.Limiter_MakeUpGain;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_CompressorBase_setupImpl
      (&AudioSmartSpeakerOnJetsonNano_DW.obj_m);
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.isSetupComplete = true;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S4>/Limiter' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.pLevelDetectionState[0] = 0.0F;
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.pLevelDetectionState[1] = 0.0F;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime != 0.0) {
      Nyquist = -2.1972246F / ((real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.AttackTime * (real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.pSampleRateInherit);
      mw_arm_vexp_f32(&Nyquist, &AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaA,
                      1U);
    } else {
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaA = 0.0F;
    }

    if (AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime != 0.0) {
      Nyquist = -2.1972246F / ((real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.ReleaseTime * (real32_T)
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.pSampleRateInherit);
      mw_arm_vexp_f32(&Nyquist, &AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaR,
                      1U);
    } else {
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pAlphaR = 0.0F;
    }

    /* End of InitializeConditions for MATLABSystem: '<S4>/Limiter' */
    for (i = 0; i < 8820; i++) {
      /* SystemInitialize for Product: '<S4>/Product' incorporates:
       *  Outport: '<S4>/Out1'
       */
      AudioSmartSpeakerOnJetsonNano_B.Product[i] =
        AudioSmartSpeakerOnJetsonNano_P.Out1_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/Speaker Output Processing ' */

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
    for (i = 0; i < 10; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.YBuffer[i] = 1.0;
    }

    /* End of SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */

    /* SystemInitialize for Chart: '<Root>/Volume Setting' */
    AudioSmartSpeakerOnJetsonNano_B.Volume = 6.0;

    /* Start for MATLABSystem: '<S3>/MATLAB System' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.Tau =
      AudioSmartSpeakerOnJetsonNano_P.SmoothedMute_tau;
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.SampleRate =
      AudioSmartSpeakerOnJetsonNano_P.MATLABSystem_SampleRate;
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.isInitialized = 1;

    /* InitializeConditions for MATLABSystem: '<S3>/MATLAB System' */
    /*  Initialize discrete-state properties. */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.muteState = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.currentGain = 0.0;

    /*  Calculate timestep */
    AudioSmartSpeakerOnJetsonNano_DW.obj_i.Ts = 1.0 /
      AudioSmartSpeakerOnJetsonNano_DW.obj_i.SampleRate;

    /* Start for MATLABSystem: '<Root>/ALSA Audio Capture1' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_ak.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_ak.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b[i] = b_4[i];
    }

    audioCaptureInit(&b[0], 16000.0, 1.0, 0.5, 1600.0, MW_AUDIO_16);
    AudioSmartSpeakerOnJetsonNano_DW.obj_ak.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/ALSA Audio Capture1' */

    /* Start for MATLABSystem: '<S6>/Audio File Read4' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxInitialized = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.LoopCount = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle = NULL;
    nulHandle = AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle;
    memcpy(&b_0[0], &b_5[0], 161U * sizeof(char_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle = MW_sox_init(&b_0[0]);
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle != nulHandle) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxInitialized = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S6>/Audio File Read4' */
    MW_sox_seek(AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle, 0);

    /* Start for MATLABSystem: '<S6>/Audio File Read' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxInitialized = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.LoopCount = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle = NULL;
    nulHandle = AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle;
    memcpy(&b_1[0], &b_6[0], 163U * sizeof(char_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle = MW_sox_init(&b_1[0]);
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle != nulHandle) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxInitialized = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_k.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S6>/Audio File Read' */
    MW_sox_seek(AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle, 0);

    /* Start for MATLABSystem: '<S6>/Audio File Read5' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxInitialized = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.LoopCount = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle = NULL;
    nulHandle = AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle;
    memcpy(&b_0[0], &b_7[0], 161U * sizeof(char_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle = MW_sox_init(&b_0[0]);
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle != nulHandle) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxInitialized = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_a.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S6>/Audio File Read5' */
    MW_sox_seek(AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle, 0);

    /* Start for MATLABSystem: '<S6>/Audio File Read6' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxInitialized = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.LoopCount = 0.0;
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle = NULL;
    nulHandle = AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle;
    memcpy(&b_1[0], &b_8[0], 163U * sizeof(char_T));
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle = MW_sox_init(&b_1[0]);
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle != nulHandle) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxInitialized = true;
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj_po.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S6>/Audio File Read6' */
    MW_sox_seek(AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle, 0);

    /* Start for MATLABSystem: '<Root>/Sample-Rate Converter' */
    AudioSmartSpeakerOnJetsonNano_DW.obj.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj.isInitialized = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRRateConverter */
    memcpy
      (&AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.cSFunObject.P0_FILTER
       [0], &tmp_1[0], 9261U * sizeof(real32_T));
    for (i = 0; i < 441; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.cSFunObject.P1_PolyphaseSelector
        [i] = tmp_2[i];
    }

    for (i = 0; i < 160; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.cSFunObject.P2_StartIdx
        [i] = tmp_3[i];
    }

    for (i = 0; i < 160; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.cSFunObject.P3_StopIdx
        [i] = tmp_4[i];
    }

    for (i = 0; i < 441; i++) {
      AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0.cSFunObject.P4_IndexSelector
        [i] = tmp_5[i];
    }

    AudioSmartSpeakerOnJetsonNano_DW.obj.filt1 =
      &AudioSmartSpeakerOnJetsonNano_DW.obj.coder_buffer_pobj0;
    AudioSmartSpeakerOnJetsonNano_DW.obj.NumChannels = 1;
    AudioSmartSpeakerOnJetsonNano_DW.obj.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<Root>/Sample-Rate Converter' */
    if (AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRRateConverter */
      AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W1_InBufIdx = 0;
      memset(&AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W0_InBuf[0],
             0, 21U * sizeof(real32_T));
      AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->cSFunObject.W2_ModuloIdx = 0;
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Sample-Rate Converter' */

    /* Start for MATLABSystem: '<Root>/ALSA Audio Playback1' */
    AudioSmartSpeakerOnJetsonNano_DW.obj_lv.matlabCodegenIsDeleted = false;
    AudioSmartSpeakerOnJetsonNano_DW.obj_lv.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b[i] = b_4[i];
    }

    audioPlaybackInit(&b[0], 44100.0, 2.0, 0.5, 4410.0, MW_AUDIO_16);
    AudioSmartSpeakerOnJetsonNano_DW.obj_lv.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/ALSA Audio Playback1' */
  }
}

/* Model terminate function */
void AudioSmartSpeakerOnJetsonNano_terminate(void)
{
  b_multibandParametricEQ_AudioSmartSpeakerOnJetsonNano_T *obj;
  int32_T i;
  char_T b[11];
  static const char_T b_0[11] = "plughw:2,0";

  /* Terminate for Enabled SubSystem: '<Root>/Speaker Output Processing ' */
  /* Terminate for MATLABSystem: '<S4>/Audio File Read1' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_l.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_l.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_l.isSetupComplete) {
      MW_sox_terminate(AudioSmartSpeakerOnJetsonNano_DW.obj_l.SoxFileHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Audio File Read1' */

  /* Terminate for MATLABSystem: '<S4>/Graphic EQ' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_e.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_e.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.isSetupComplete) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.pNumChannels = -1.0;
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isInitialized = 2;
        if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->isSetupComplete) {
          obj = AudioSmartSpeakerOnJetsonNano_DW.obj_e.pEQ->pMPEQ1;
          if (obj->isInitialized == 1) {
            obj->isInitialized = 2;
            if (obj->isSetupComplete) {
              if (obj->SOSFilterObj.isInitialized == 1) {
                obj->SOSFilterObj.isInitialized = 2;
              }

              obj->NumChannels = -1.0;
            }
          }
        }
      }
    }
  }

  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.matlabCodegenIsDeleted)
  {
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.matlabCodegenIsDeleted
      = true;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.isInitialized ==
        1) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.isInitialized =
        2;
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.isSetupComplete
          &&
          (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->isInitialized
           == 1)) {
        AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->isInitialized
          = 2;
        if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->isSetupComplete)
        {
          if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->SOSFilterObj.isInitialized
              == 1) {
            AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->SOSFilterObj.isInitialized
              = 2;
          }

          AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.pMPEQ1->NumChannels
            = -1.0;
        }
      }
    }
  }

  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.matlabCodegenIsDeleted)
  {
    AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.matlabCodegenIsDeleted
      = true;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.isInitialized
        == 1) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.isInitialized
        = 2;
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.isSetupComplete)
      {
        if (AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.SOSFilterObj.isInitialized
            == 1) {
          AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.SOSFilterObj.isInitialized
            = 2;
        }

        AudioSmartSpeakerOnJetsonNano_DW.obj_e.coder_buffer_pobj0.coder_buffer_pobj0.NumChannels
          = -1.0;
      }
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Graphic EQ' */

  /* Terminate for MATLABSystem: '<S4>/Multiband Parametric EQ' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_p.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.matlabCodegenIsDeleted = true;
    if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.isInitialized == 1) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.isInitialized = 2;
      if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.isSetupComplete) {
        if (AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SOSFilterObj.isInitialized
            == 1) {
          AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.SOSFilterObj.isInitialized =
            2;
        }

        AudioSmartSpeakerOnJetsonNano_DW.obj_p.pEQ.NumChannels = -1.0;
      }
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Multiband Parametric EQ' */

  /* Terminate for MATLABSystem: '<S4>/Limiter' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_m.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_m.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_m.isSetupComplete) {
      AudioSmartSpeakerOnJetsonNano_DW.obj_m.pNumChannels = -1.0;
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Limiter' */
  /* End of Terminate for SubSystem: '<Root>/Speaker Output Processing ' */

  /* Terminate for MATLABSystem: '<Root>/ALSA Audio Capture1' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_ak.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_ak.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_ak.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_ak.isSetupComplete) {
      for (i = 0; i < 11; i++) {
        b[i] = b_0[i];
      }

      MW_AudioClose(&b[0], MW_AUDIO_IN);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ALSA Audio Capture1' */

  /* Terminate for MATLABSystem: '<S6>/Audio File Read4' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_ph.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_ph.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_ph.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_ph.isSetupComplete) {
      MW_sox_terminate(AudioSmartSpeakerOnJetsonNano_DW.obj_ph.SoxFileHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Audio File Read4' */

  /* Terminate for MATLABSystem: '<S6>/Audio File Read' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_k.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_k.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_k.isSetupComplete) {
      MW_sox_terminate(AudioSmartSpeakerOnJetsonNano_DW.obj_k.SoxFileHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Audio File Read' */

  /* Terminate for MATLABSystem: '<S6>/Audio File Read5' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_a.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_a.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_a.isSetupComplete) {
      MW_sox_terminate(AudioSmartSpeakerOnJetsonNano_DW.obj_a.SoxFileHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Audio File Read5' */

  /* Terminate for MATLABSystem: '<S6>/Audio File Read6' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_po.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_po.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_po.isSetupComplete) {
      MW_sox_terminate(AudioSmartSpeakerOnJetsonNano_DW.obj_po.SoxFileHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Audio File Read6' */

  /* Terminate for MATLABSystem: '<Root>/Sample-Rate Converter' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj.isSetupComplete) {
      if (AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isInitialized == 1) {
        AudioSmartSpeakerOnJetsonNano_DW.obj.filt1->isInitialized = 2;
      }

      AudioSmartSpeakerOnJetsonNano_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Sample-Rate Converter' */

  /* Terminate for MATLABSystem: '<Root>/ALSA Audio Playback1' */
  if (!AudioSmartSpeakerOnJetsonNano_DW.obj_lv.matlabCodegenIsDeleted) {
    AudioSmartSpeakerOnJetsonNano_DW.obj_lv.matlabCodegenIsDeleted = true;
    if ((AudioSmartSpeakerOnJetsonNano_DW.obj_lv.isInitialized == 1) &&
        AudioSmartSpeakerOnJetsonNano_DW.obj_lv.isSetupComplete) {
      for (i = 0; i < 11; i++) {
        b[i] = b_0[i];
      }

      MW_AudioClose(&b[0], MW_AUDIO_OUT);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ALSA Audio Playback1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
