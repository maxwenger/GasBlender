#include <queue>
#include "gas.h"

class PartialPressureBlend {
   public:
      std::queue<Gas> Blend(Gas currentMix, Gas desiredMix, double fillGasFO2);
};

