#include "elemUnits.h"

#include <limits>

transferFunction::transferFunction() : additionalTilt(std::numeric_limits<short>::quiet_NaN()), timeConstValue(std::numeric_limits<double>::quiet_NaN()) {}

transferFunction::transferFunction(short tiltValue) : additionalTilt(tiltValue), timeConstValue(std::numeric_limits<double>::quiet_NaN()) {}

transferFunction::transferFunction(short tiltValue, double TCValue) : additionalTilt(tiltValue), timeConstValue(TCValue) {}

double transferFunction::getTCValue() const {return timeConstValue;}

short transferFunction::getAddTilt() const {return additionalTilt;}

//------

amplifTF::amplifTF() : transferFunction(0), amplifCoeff(std::numeric_limits<double>::quiet_NaN()) {}
amplifTF::amplifTF(double ACValue) : transferFunction(0), amplifCoeff(ACValue) {}

double amplifTF::getACCoef() const {return amplifCoeff;}

void amplifTF::setACCoef(double ACValue) {
    return;
}
//------

aperTF::aperTF() : transferFunction(-1) {}

aperTF::aperTF(double TCValue) : transferFunction(-1, TCValue) {}

//------

difEq::difEq() {}

//------

diffTF::diffTF() : transferFunction(1) {}

//------

firstOrderForcingTF::firstOrderForcingTF() : transferFunction(1) {}
firstOrderForcingTF::firstOrderForcingTF(double TCValue) : transferFunction(1, TCValue) {}

//------

integrTF::integrTF() : transferFunction(-1) {}

//------

oscTF::oscTF() : transferFunction(-2) {}
oscTF::oscTF(double TCValue) : transferFunction(-2, TCValue) {}
oscTF::oscTF(double TCValue, double DCValue) : transferFunction(-2, TCValue), dampingCoef(DCValue) {}

double oscTF::getDCValue() const {return dampingCoef;}

void oscTF::setDCValue(double DCValue) {
    return;
}

//------

secondOrderForcingTF::secondOrderForcingTF() : transferFunction(2) {}
secondOrderForcingTF::secondOrderForcingTF(double TCValue) : transferFunction(2, TCValue) {}
secondOrderForcingTF::secondOrderForcingTF(double TCValue, double DCValue) : transferFunction(2, TCValue), dampingCoef(DCValue) {}

double secondOrderForcingTF::getDCValue() const {return dampingCoef;}

void secondOrderForcingTF::setDCValue(double DCValue) {
    return;
}

//-------