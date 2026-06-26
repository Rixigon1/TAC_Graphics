#include "transferFunction.h"

transferFunction::transferFunction() : additionalTilt(std::numeric_limits<short>::quiet_NaN()), timeConstValue(std::numeric_limits<double>::quiet_NaN()) {}

transferFunction::transferFunction(short tiltValue) : additionalTilt(tiltValue), timeConstValue(std::numeric_limits<double>::quiet_NaN()) {}

transferFunction::transferFunction(short tiltValue, double TCValue) : additionalTilt(tiltValue), timeConstValue(TCValue) {}

double transferFunction::getTCValue() const {return timeConstValue;}

short transferFunction::getAddTilt() const {return additionalTilt;}
