#include "catch.hpp"
#include "partial_pressure_blend.h"

#define FO2_AIR 0.209

std::queue<Gas> PartialPressureBlend::Blend(Gas currentMix, Gas desiredMix, double fillGasFO2) {
   std::queue<Gas> fillInstr;
   fillInstr.push(currentMix);

   if(fillGasFO2 < desiredMix.get_fo2()) {
      return fillInstr;
   }

   double fillGasPressure = desiredMix.get_pressure();
   fillGasPressure *= desiredMix.get_fo2() - FO2_AIR - currentMix.get_pressure();
   fillGasPressure *= currentMix.get_fo2() - FO2_AIR;
   fillGasPressure /= fillGasFO2 - FO2_AIR;

   fillInstr.push(Gas(fillGasFO2, fillGasPressure));

   double top_off_pressure = desiredMix.get_pressure();
   top_off_pressure -= currentMix.get_pressure();
   top_off_pressure -= fillGasPressure;

   fillInstr.push(Gas(FO2_AIR, top_off_pressure));

   return fillInstr; 
}

TEST_CASE("EAN32 From Empty Tank", "[PP Mix]") {
   PartialPressureBlend blend = PartialPressureBlend();
   Gas currentMix = Gas(0.21, 0);
   Gas desiredMix = Gas(0.32, 3000);
        
   std::queue<Gas> fillInstr = blend.Blend(currentMix, desiredMix, 1);

   Gas step = fillInstr.front();
   fillInstr.pop();
   REQUIRE(step.get_fo2() == 0.21);
   REQUIRE(step.get_pressure() == 0);

   step = fillInstr.front();
   fillInstr.pop();
   REQUIRE(step.get_fo2() == 1);
   REQUIRE(step.get_pressure() == 600);

   step = fillInstr.front();
   fillInstr.pop();
   REQUIRE(step.get_fo2() == 0.21);
   REQUIRE(step.get_pressure() == 2400);
}
