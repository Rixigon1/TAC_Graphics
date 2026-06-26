#pragma once

#include "transferFunction.h"

class oscTF : public transferFunction {
    protected:
        double dampingCoef;
    public:
        oscTF();
        oscTF(double TCValue);
        oscTF(double TCValue, double DCValue);

        double getDCValue() const;
        void setDCValue(double DCValue);
};

