#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include "Pago.h"
#include "Fecha.h"
#define DIMP 5

class Prestamo{
    public:
        Prestamo();
        Prestamo(int np, Cliente *cli, Fecha *f1, float ma);
        virtual ~Prestamo();
        int getNumeroPrestamo();
        void setNumeroPrestamo(int np);
        Cliente *getCliente();
        void setCliente(Cliente *cli);
        void setFechaAprobacion(Fecha *f1);
        Fecha *getFechaAprobacion();
        void setMontoAprobado(float ma);
        float getMontoAprobado();
        bool hacerPago(Pago *pg);
        Pago **getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();

    protected:

    private:
        int numeroPrestamo;
        Cliente *cliente;
        Fecha *fechaAprobacion;
        float montoAprobado;
        Pago *lstPagos[DIMP];
        float saldoPendiente;
        int contadorPagos;
};
#endif // PRESTAMO_H
