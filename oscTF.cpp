#include "oscTF.h"

oscTF::oscTF() : transferFunction(-2) {}
oscTF::oscTF(double TCValue) : transferFunction(-2, TCValue) {}
oscTF::oscTF(double TCValue, double DCValue) : transferFunction(-2, TCValue), dampingCoef(DCValue) {}

double oscTF::getDCValue() const {return dampingCoef;}

void oscTF::setDCValue(double DCValue) {
    return;
}
