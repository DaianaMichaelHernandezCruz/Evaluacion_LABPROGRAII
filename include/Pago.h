#ifndef PAGO_H
#define PAGO_H
#include <iostream>
using namespace std;
#include "Fecha.h"

class Pago{
    public:
        Pago(Fecha *f1, float montopg);
        virtual ~Pago();
        Fecha *getFechaPago();
        float getMontoPago();

    protected:

    private:
        Fecha *fechaPago;
        float montoPago;
};
#endif // PAGO_H
