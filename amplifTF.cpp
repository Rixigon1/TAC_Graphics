#include "amplifTF.h"


amplifTF::amplifTF() : transferFunction(0), amplifCoeff(std::numeric_limits<double>::quiet_NaN()) {}
amplifTF::amplifTF(double ACValue) : transferFunction(0), amplifCoeff(ACValue) {}

double amplifTF::getACCoef() const {return amplifCoeff;}

void amplifTF::setACCoef(double ACValue) {
    return;
}