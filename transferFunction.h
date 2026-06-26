#pragma once
#include <limits>

// enum transferTypes {AMPLIFYING, INTEGRATOR, DIFFERENTIATING, APERIODIC, FIRST_ORDER_FORCING, OSCILLATORY, SECOND_ORDER_FORCING};

class transferFunction {
    protected:
        short additionalTilt;
        double timeConstValue;
    public:
        transferFunction();
        transferFunction(short tiltValue);
        transferFunction(short tiltValue, double TCValue);

        double getTCValue() const;
        short getAddTilt() const;

        void setTCValue(double TCValue);
};


