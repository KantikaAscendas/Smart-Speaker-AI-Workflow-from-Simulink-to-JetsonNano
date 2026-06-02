/* Include files */

#include "AudioSmartSpeakerOnJetsonNano_cgxe.h"
#include "m_KDwX9EsWGnc16Iuc3hY4E.h"

unsigned int cgxe_AudioSmartSpeakerOnJetsonNano_method_dispatcher(SimStruct* S,
  int_T method, void* data)
{
  if (ssGetChecksum0(S) == 1849643150 &&
      ssGetChecksum1(S) == 3725739914 &&
      ssGetChecksum2(S) == 4273104024 &&
      ssGetChecksum3(S) == 1292728756) {
    method_dispatcher_KDwX9EsWGnc16Iuc3hY4E(S, method, data);
    return 1;
  }

  return 0;
}
