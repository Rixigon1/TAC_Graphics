#pragma once

#include "transferFunction.h"

class amplifTF : public transferFunction {
    protected:
        double amplifCoeff;
    public:
        amplifTF();
        amplifTF(double ACValue);

        double getACCoef() const;
        void setACCoef(double ACValue);
};


