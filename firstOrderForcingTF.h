#pragma once

#include "transferFunction.h"

class firstOrderForcingTF : public transferFunction {
    public:
        firstOrderForcingTF();
        firstOrderForcingTF(double TCValue);
};

