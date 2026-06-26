#include "secondOrderForcingTF.h"

secondOrderForcingTF::secondOrderForcingTF() : transferFunction(2) {}
secondOrderForcingTF::secondOrderForcingTF(double TCValue) : transferFunction(2, TCValue) {}
secondOrderForcingTF::secondOrderForcingTF(double TCValue, double DCValue) : transferFunction(2, TCValue), dampingCoef(DCValue) {}

double secondOrderForcingTF::getDCValue() const {return dampingCoef;}

void secondOrderForcingTF::setDCValue(double DCValue) {
    return;
}
