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

//-----

class amplifTF : public transferFunction {
protected:
    double amplifCoeff;
public:
    amplifTF();
    amplifTF(double ACValue);

    double getACCoef() const;
    void setACCoef(double ACValue);
};

//------

class aperTF : public transferFunction {
public:
    aperTF();
    aperTF(double TCValue);
};

//------

class difEq {
public:
    difEq();
};

//------

class diffTF : public transferFunction {
public:
    diffTF();
};

//------

class firstOrderForcingTF : public transferFunction {
public:
    firstOrderForcingTF();
    firstOrderForcingTF(double TCValue);
};

//------

class integrTF : public transferFunction {
public:
    integrTF();
};

//------

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

//------

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

//-----
