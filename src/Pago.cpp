#include "Pago.h"

Pago::Pago(Fecha *f1, float montopg){
    fechaPago = f1;
    montoPago = montopg;
}
Pago::~Pago(){
    //dtor
}
Fecha *Pago::getFechaPago(){
    return this->fechaPago;
}
float Pago::getMontoPago(){
    return this->montoPago;
}
