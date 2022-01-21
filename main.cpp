#include <iostream>

using namespace std;

class Persona
{
protected:
    string nombre, apellido, tipo_identificacion;
    int documento;

public:
    Persona()
    {
        nombre = " ";
        apellido = " ";
        tipo_identificacion = " ";
        documento = 0;
    }

    Persona(string nombre, string apellido, string tipo_identificacion, int documento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->tipo_identificacion = tipo_identificacion;
        this->documento = documento;
    }

    string getNombre()
    {
        return nombre;
    }

    string getApellido()
    {
        return apellido;
    }

    string getTipo_identificacion()
    {
        return tipo_identificacion;
    }

    int getDocumento()
    {
        return documento;
    }

    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }

    void setApellido(string apellido)
    {
        this->apellido = apellido;
    }

    void setTipo_identificacion(string tipo_identificacion)
    {
        this->tipo_identificacion = tipo_identificacion;
    }

    void setDocumento(int documento)
    {
        this->documento = documento;
    }

    friend ostream &operator<<(ostream &output, Persona &persona)
    {
        output << "Nombre: " << persona.getNombre() << endl;
        output << "Apellido: " << persona.getApellido() << endl;
        output << "Documento tipo: " << persona.getTipo_identificacion() << endl;
        output << "Numero de documento: " << persona.getDocumento() << endl;
        return output;
    }
};

class Cliente : public Persona
{
protected:
    string direccion, tipo_suscripcion;
    int descuento;

public:
    Cliente() : Persona()
    {
        direccion = " ";
        tipo_suscripcion = " ";
        descuento = 0;
    }

    Cliente(string nombre, string apellido, string tipo_identificacion, int documento, string direccion,
            string tipo_suscripcion, int descuento)
            : Persona(nombre, apellido, tipo_identificacion, documento)
    {

        this->direccion = direccion;
        this->tipo_suscripcion = tipo_suscripcion;
        this->descuento = descuento;
    }

    string getDireccion()
    {
        return direccion;
    }

    string getTipo_suscripcion()
    {
        return tipo_suscripcion;
    }

    int getDescuento()
    {
        return descuento;
    }

    void setDireccion(string direccion)
    {
        this->direccion = direccion;
    }

    void setTipo_suscripcion(string tipo_suscripcion)
    {
        this->tipo_suscripcion = tipo_suscripcion;
    }

    void setDescuento(int descuento)
    {
        this->descuento = descuento;
    }

    float calcularPagosuscripcion()
    {
        float aux=0;
        float total;
        if (tipo_suscripcion == "personal" || tipo_suscripcion == "Personal" || tipo_suscripcion == "PERSONAL")
        {
            total = aux = 10000;
            aux /= descuento;
            total -= aux;
        }

        if (tipo_suscripcion == "grupal" || tipo_suscripcion == "Grupal" || tipo_suscripcion == "GRUPAL")
        {
            total = aux = 15000;
            aux /= descuento;
            total -= aux;
        }

        if (tipo_suscripcion == "empresarial" || tipo_suscripcion == "Empresarial" || tipo_suscripcion == "EMPRESARIAL")
        {
            total = 25000;
            aux = total*descuento/100;
            total -= aux;
        }

        return total;
    }

    friend ostream &operator<<(ostream &output, Cliente &cliente)
    {
        output << "1. Nombre: " << cliente.getNombre() << endl;
        output << "2. Apellido: " << cliente.getApellido() << endl;
        output << "3. Documento tipo " << cliente.getTipo_identificacion() << endl;
        output << "4. Numero de documento: " << cliente.getDocumento() << endl;
        output << "5. Direccion: " << cliente.getDireccion() << endl;
        output << "6. Tipo de suscripcion: " << cliente.getTipo_suscripcion() << endl;
        output << "7. Descuento aplicado: " << cliente.getDescuento() << "%" << endl;
        return output;
    }

    friend istream &operator>>(istream &input, Cliente &cliente)
    {
        cout << "Nombre: ";
        input >> cliente.nombre;
        cout << "Apellido: ";
        input >> cliente.apellido;
        cout << "Tipo de documento (C.C, T.I, C.I): ";
        input >> cliente.tipo_identificacion;
        cout << "Numero de documento: ";
        input >> cliente.documento;
        cout << "Direccion: ";
        cin.ignore();
        getline(input, cliente.direccion);
        cout << "Tipo de suscripcion (Personal, Grupal, Empreasarial): ";
        input >> cliente.tipo_suscripcion;
        cout << "Descuento aplicado: ";
        input >> cliente.descuento;

        return input;
    }
};

class Empleado : public Persona
{
protected:
    string tipo_contrato;
    float salario;
    int hora_t, horas_extra_d, horas_extra_n, horas_extra_dom_d, horas_extra_dom_n;

public:
    Empleado() : Persona()
    {
        tipo_contrato = "";
        salario = hora_t = horas_extra_d = horas_extra_n = horas_extra_dom_d = horas_extra_dom_n = 0;
    }
    Empleado(string nombre, string apellido, string tipo_identificacion, int documento, string tipo_contrato, float salario, int hora_t, int horas_extra_d, int horas_extra_n, int horas_extra_dom_d, int horas_extra_dom_n) : Persona(nombre, apellido, tipo_identificacion, documento)
    {
        this->nombre = nombre;
        this->apellido = apellido;
        this->tipo_identificacion = tipo_identificacion;
        this->documento = documento;
        this->tipo_contrato = tipo_contrato;
        this->salario = salario;
        this->hora_t = hora_t;
        this->horas_extra_d = horas_extra_d;
        this->horas_extra_n = horas_extra_n;
        this->horas_extra_dom_d = horas_extra_dom_d;
        this->horas_extra_dom_n = horas_extra_dom_n;
    }
    string getTipoContrato()
    {
        return tipo_contrato;
    }
    float getSalario()
    {
        return salario;
    }
    int getHoraT()
    {
        return hora_t;
    }
    int getHorasExtraD()
    {
        return horas_extra_d;
    }
    int getHorasExtraN()
    {
        return horas_extra_n;
    }
    int getHorasExtraDomD()
    {
        return horas_extra_dom_d;
    }
    int getHorasExtraDomN()
    {
        return horas_extra_dom_n;
    }
    void setTipoContrato(string tipo_contrato)
    {
        this->tipo_contrato = tipo_contrato;
    }
    void setSalario(float salario)
    {
        this->salario = salario;
    }
    void setHoraT(int hora_t)
    {
        this->hora_t = hora_t;
    }
    void setHorasExtraD(int horas_extra_d)
    {
        this->horas_extra_d = horas_extra_d;
    }
    void setHorasExtraN(int horas_extra_n)
    {
        this->horas_extra_n = horas_extra_n;
    }
    void setHorasExtraDomN(int horas_extra_dom_n)
    {
        this->horas_extra_dom_n = horas_extra_dom_n;
    }
    void setHorasExtraDOmD(int horas_extra_dom_d)
    {
        this->horas_extra_dom_d = horas_extra_dom_d;
    }
    float calcularSalario()
    {
        return 0;
    }
    friend ostream &operator<<(ostream &output, Empleado &empleado)
    {

        output << "1. Nombre" << empleado.getNombre() << endl;
        output << "2. Apellido" << empleado.getApellido() << endl;
        output << "3. Tipo de Identificación" << empleado.getTipo_identificacion() << endl;
        output << "4. Documento" << empleado.getDocumento() << endl;
        output << "5. Tipo de Contrato" << empleado.getTipoContrato() << endl;
        output << "6. Salario" << empleado.getSalario() << endl;
        output << "7. Horas Trabajadas" << empleado.getHoraT() << endl;
        output << "8. Horas Extra Diurnas" << empleado.getHorasExtraD() << endl;
        output << "9. Horas Extra Nocturnas" << empleado.getHorasExtraN() << endl;
        output << "10. Horas Extra Dominicales Diurnas" << empleado.getHorasExtraDomD() << endl;
        output << "11. Horas Extra Dominicales Nocturnas" << empleado.getHorasExtraDomN() << endl;
        return output;
    }
};

int main()
{
    Cliente cliente[2];
    string modOp;
    int intmodOp, op,opTemp, i_cliente;
    bool rep;
    rep = true;

    do
    {
        cout << "################################################\n"
                "###   Sistema de planificacion de recursos   ###\n"
                "################################################\n \n"
                "Menu: \n"
                "1. Clientes \n"
                "2. Empleados \n"
                "3. Salir \n \n"
                "Que desea realizar? \n"
                ">>  ";
        cin >> op;

        switch (op)
        {

            case 1:
                do
                {

                    cout << "################################################\n"
                            "###   Sistema de planificacion de recursos   ###\n"
                            "################################################\n \n"
                            "Gestion de clientes \n"
                            "Menu: \n"
                            "1. Crear clientes \n"
                            "2. Modificar clientes \n"
                            "3. Ver clientes \n"
                            "4. Generar facturas \n"
                            "5. Regresar \n \n"
                            "Que desea realizar? \n"
                            ">>  ";
                    cin >> op;

                    switch (op)
                    {

                        case 1:

                            while (i_cliente < 2)
                            {
                                cin >> cliente[i_cliente];
                                i_cliente++;
                                break;
                            }
                            break;

                        case 2:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> opTemp;
                            opTemp--;
                            do {


                                cout << cliente[opTemp];
                                cout << "8. Regresar" << endl;
                                cout << ">> ";
                                cin >> op;
                                switch (op) {

                                    case 1:
                                        cout << "Ingerese nuevo nombre: ";
                                        cin >> modOp;
                                        cliente[opTemp].setNombre(modOp);
                                        break;

                                    case 2:
                                        cout << "Ingerese nuevo apellido: ";
                                        cin >> modOp;
                                        cliente[opTemp].setApellido(modOp);
                                        break;

                                    case 3:
                                        cout << "Ingerese nuevo tipo de documento (C.C, C.I T.I): ";
                                        cin >> modOp;
                                        cliente[opTemp].setTipo_identificacion(modOp);
                                        break;

                                    case 4:
                                        cout << "Ingerese nuevo documento: ";
                                        cin >> intmodOp;
                                        cliente[opTemp].setDocumento(intmodOp);
                                        break;

                                    case 5:
                                        cout << "Ingerese nueva direccion: ";
                                        cin.ignore();
                                        getline(cin, modOp);
                                        cliente[opTemp].setDireccion(modOp);
                                        break;

                                    case 6:
                                        cout << "Ingerese nuevo tipo de suscripcion (Personal, Grupal, Empresarial: ";
                                        cin >> modOp;
                                        cliente[opTemp].setTipo_suscripcion(modOp);
                                        break;

                                    case 7:
                                        cout << "Ingerese nuevo descuento: ";
                                        cin >> intmodOp;
                                        cliente[opTemp].setDescuento(intmodOp);
                                        break;

                                    case 8:
                                        rep= false;
                                        break;

                                    default:
                                        break;
                                }
                            } while (rep==true);
                            rep=true;
                            break;

                        case 3:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> op;
                            cout << cliente[op - 1];
                            system("pause");
                            break;
                        case 4:
                            for (int i = 0; i < 2; i++)
                            {
                                cout << i + 1 << "." << cliente[i].getNombre() << "\n";
                            }
                            cout << ">> ";
                            cin >> op;
                            cout << "Villavicencio                     Factrura  #00"<<op << endl;
                            cout << "Km via Acacias, anillo vial \n"
                                    "(8) 6823030 / Cel: 3103689660 \n"
                                    "-----------------------------------------------------\n\n"
                                    "FACTURA A \n"
                                 << cliente[op-1].getNombre() << " " << cliente[op-1].getApellido() << "\n"
                                 << cliente[op-1].getTipo_identificacion() << ": " << cliente[op-1].getDocumento()
                                 << "\n" << "Direccion: " << cliente[op-1].getDireccion() << "\n \n \n"
                                 << "DESCRIPCION                     |  CANT |    VALOR\n"
                                    "Pago de suscripcion " << cliente[op-1].getTipo_suscripcion()
                                 << "  |  1  |  $" << cliente[op-1].calcularPagosuscripcion() << "COP"
                                 << "                                           $"
                                 <<cliente[op-1].calcularPagosuscripcion() << "COP \n\n\n"
                                 << "VALOR A PAGAR  $" << cliente[op-1].calcularPagosuscripcion() << "COP\n\n\n"
                                 << "            GRACIAS POR TU COMPRA";

                            break;
                        case 5:
                            rep = false;
                            break;
                        default:
                            break;
                    }
                } while (rep == true);
                rep = true;
                break;


            case 3:
                rep = false;
                break;

            default:
                break;
        }
    } while (rep == true);
    return 0;
}
