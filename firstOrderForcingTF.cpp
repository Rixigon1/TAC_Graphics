#include "firstOrderForcingTF.h"

firstOrderForcingTF::firstOrderForcingTF() : transferFunction(1) {}
firstOrderForcingTF::firstOrderForcingTF(double TCValue) : transferFunction(1, TCValue) {}
