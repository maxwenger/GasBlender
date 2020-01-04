#include "gas.h"
#include "catch.hpp"

double Gas::get_fo2() {
   return fo2;
}

double Gas::get_pressure() {
   return pressure;
}

double Gas::get_ppo2() {
   return fo2 * pressure;
}

TEST_CASE("Pressure provided in ctor is stored.", "[gas]") {
   REQUIRE( Gas(0.21, 3000).get_pressure() == 3000 );
}

TEST_CASE("fo2 provided in ctor is stored.", "[gas]") {
   REQUIRE( Gas(0.21, 3000).get_fo2() == 0.21 );
}

