#include "aperTF.h"

aperTF::aperTF() : transferFunction(-1) {}

aperTF::aperTF(double TCValue) : transferFunction(-1, TCValue) {}
