#include <iostream>

using namespace std;

class Persona{
protected:
    string nombre, apellido, tipo_identificacion;
    int documento;


public:
    Persona(){
        nombre = " ";
        apellido = " ";
        tipo_identificacion= " ";
        documento = 0;
    }

    Persona(string nombre, string apellido, string tipo_identificacion, int documento){
        this->nombre=nombre;
        this->apellido=apellido;
        this->tipo_identificacion=tipo_identificacion;
        this->documento=documento;
    }

    string getNombre() const{
        return nombre;
    }

    string  getApellido() const{
        return apellido;
    }

    string getTipo_identificacion() const{
        return tipo_identificacion;
    }

    int getDocumento() const{
        return documento;
    }

    void setNombre(string nombre){
        this->nombre=nombre;
    }

    void setApellido(string apellido){
        this->apellido=apellido;
    }

    void setTipo_identificacion(string tipo_identificacion){
        this->tipo_identificacion=tipo_identificacion;
    }

    void setDocumento(int documento){
        this->documento=documento;
    }

    friend ostream &operator<<(ostream &output, const Persona &persona){
        output << "Nombre: " << persona.getNombre() << endl;
        output << "Apellido: " << persona.getApellido() << endl;
        output << "Documento tipo: " << persona.getTipo_identificacion() << endl;
        output << "Numero de documento: " << persona.getDocumento() << endl;
        return output;
    }
};

class Cliente: public Persona{
protected:
    string direccion, tipo_suscripcion;
    int descuento;

public:

    Cliente():Persona(){
        direccion = " ";
        tipo_suscripcion = " ";
        descuento = 0;
    }

    Cliente(string nombre, string apellido, string tipo_identificacion, int documento, string direccion,
            string tipo_suscripcion, int descuento)
            :Persona(nombre,apellido, tipo_identificacion, documento){

        this->direccion=direccion;
        this->tipo_suscripcion=tipo_suscripcion;
        this->descuento=descuento;
    }

    string getDireccion() const{
        return direccion;
    }

    string getTipo_suscripcion() const{
        return tipo_suscripcion;
    }

    int getDescuento() const{
        return descuento;
    }

    void setDireccion(string direccion){
        this->direccion=direccion;
    }

    void setTipo_suscripcion(string tipo_suscripcion){
        this->tipo_suscripcion=tipo_suscripcion;
    }

    void setDescuento(int descuento){
        this->descuento=descuento;
    }

    float calcularPagosuscripcion(){
        int aux;
        float total;
        if (tipo_suscripcion=="personal" || tipo_suscripcion=="Personal"){
            total=aux=10000;
            aux%=descuento;
            total-=aux;

        }

        if (tipo_suscripcion=="grupal" || tipo_suscripcion=="Grupal"){
            total=aux=15000;
            aux%=descuento;
            total-=aux;

        }

        if (tipo_suscripcion=="empresarial" || tipo_suscripcion=="Empresarial"){
            total=aux=25000;
            aux%=descuento;
            total-=aux;

        }

        return total;
    }

    friend ostream &operator<<(ostream &output, const Cliente &cliente){
        output << "Nombre: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
        output << "Documento tipo " << cliente.getTipo_identificacion() <<": " << cliente.getDocumento() << endl;
        output << "Direccion: " << cliente.getDireccion() << endl;
        output << "Tipo de suscripcion: " << cliente.getTipo_suscripcion() << endl;
        output << "Descuento aplicado: " << cliente.getDescuento() << "%" << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Cliente &cliente){
        cout << "Nombre: ";
        input >> cliente.nombre;
        cout << "Apellido: ";
        input >> cliente.apellido;
        cout << "Tipo de documento (c.c, t.i, c.i): ";
        input >> cliente.tipo_identificacion;
        cout << "Numero de documento: ";
        input >> cliente.documento;
        cout << "Direccion";
        input >> cliente.direccion;
        cout << "Tipo de suscripcion (Personal, Grupal, Empreasarial: ";
        input >> cliente.tipo_suscripcion;
        cout << "Descuento aplicado: ";
        input >> cliente.descuento;

        return input;
    }

    };

int main() {
    Cliente cliente[2];

    int op, op1, i=0;
    bool rep = true;
    do {
        cout << "################################################"
                "###   Sistema de planificacion de recursos   ###"
                "################################################\n \n"
                "Menu: \n"
                "1. Clientes \n"
                "2. Empleados \n"
                "3. Salir \n \n"
                "Que desea realizar? " << endl;
        cout << ">>  ";
        cin >> op;

        switch (op) {

            case 1:

                cout << "################################################"
                        "###   Sistema de planificacion de recursos   ###"
                        "################################################\n \n"
                        "Gestion de clientes \n"
                        "Menu: \n"
                        "1. Crear clientes \n"
                        "2. Modificar clientes \n"
                        "3. Ver clientes \n"
                        "4. Generar facturas \n"
                        "5. Regresar \n \n"
                        "Que desea realizar? " << endl;
                cout << ">>  ";
                cin >> op1;

                switch (op1) {

                    case 1:
                        while(i<3){
                            cin >> cliente[i];
                            i++;
                            break;
                        }
                        break;
                }


            case 3:
                rep = false;
        }


    }while(rep = false);
    return 0;
}