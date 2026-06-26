#pragma once

#include "transferFunction.h"

class secondOrderForcingTF : public transferFunction {
    protected:
        double dampingCoef;
    public:
        secondOrderForcingTF();
        secondOrderForcingTF(double TCValue);
        secondOrderForcingTF(double TCValue, double DCValue);

        double getDCValue() const;
        void setDCValue(double DCValue);
};

