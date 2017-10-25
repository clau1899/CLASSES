#include <iostream>//PROGRAMA: IMPRIME LA INFO DE UN BOLETO DE CONCIERTO
#include <limits>//para usar cin.ignore
using namespace std;

//PROGRAMA: IMPRIME LA INFO DE UN BOLETO DE CONCIERTO USANDO CLASES, RESOLVIENDO EL PROBLEMA DE HERENCIA MULTIPLE
//Y USANDO LOS 3 TIPOS DE PERMISOS: PUBLIC, PRIVATE, PROTECTED


class concierto//CREAMOS LA CLASE LLAMADA CONCIERTO
{
protected:
    string lugar;//DECLARAMOS LOS ATRIBUTOS
    string banda;
    int duracion;
public:
    concierto(){}//CONSTRUCTOR:
    concierto(string Lugar, string Banda, int Duracion)//INICIALIZAMOS EL CONSTRUCTOR
    {
        lugar= Lugar;//ASINGANDO VARIABLES A LOS ATRIBUTOS ANTERIORMENTE DEFINIDOS
        banda= Banda;
        duracion=Duracion;
    }
    void imprimeConcierto()//METODO:
    {
        cout<<"\nDireccion del lugar: "<<lugar;//SE PIDEN LOS DATOS DE LOS ATRIBUTOS
        cout<<"\nBanda a presentarse: "<<banda;
        cout<<"\nDuracion :"<<duracion;
    }
};

class boleto//SEGUNDA CLASE BOLETO
{
protected:
    float costo;//DECLARAMOS SUS ATRIBUTOS
    string asiento;
public:
    boleto(){}//CONSTRUCTOR
    boleto(float Costo, string Asiento)//INICIALIZAMOS
    {
        costo=Costo;//ASIGNAMOS VARIABLES A NUESTROS ATRIBUTOS
        asiento=Asiento;
    }
    void imprimeBoleto()//METODO ESPECIFICO DE ESTA CLASE
    {
        cout<<"\nCosto del boleto: "<<costo;//pedimos datos
        cout<<"\nNumero del asiento: "<<asiento;

    }
};

class boleteria: public concierto, public boleto//DEFINIMOS NUEVA CLASE QUE HEREDA DE CONCIERTO Y DE BOLETO
{
private:
    string descripcion;//DECLARAMOS ATRIBUTOS EXCLUSIVOS DE ESTA CLASE
    string fecha;
    string hora;
public:
    boleteria(){}//CONSTRUCTOR
    boleteria (string Lugar, string Banda, int Duracion, float Costo, string Asiento, string Descripcion, string Fecha, string Hora): concierto(Lugar,Banda,Duracion),boleto(Costo,Asiento)
    {                   //ATRIB. CLASE CONCIERTO              ATRIB. CLASE BOLETO           ATRIB. CLASE BOLETERIA                         SE INVOCAN CONSTRUCTORE DE LAS CLASES MADRES,HEREDA DE CONCIERTO Y BOLETO CON SUS RESPECTIVAS VARIABLES

        descripcion=Descripcion;//ASIGNAMOS VARIABLES A SUS ATRIB
        fecha=Fecha;
        hora=Hora;
    }
    void imprime()//METODO
    {
        cout<<"\nDescripcion breve: "<<descripcion;//IMPRIME LA DESCRIPCION TOTAL
        cout<<"\Fecha: "<<fecha;
        cout<<"\Hora: "<<hora;
    }

};

boleteria captura()//CAPTURA RETORNARÁ EL MISMO TIPO QUE RETORNA BOLETERIA, TOMAMOS LA CLASE COMO TIPO DE DATO :3
{
    string nombreAu,banda,asiento,descripcion,fecha,hora;//DECLARAMOS LOS ATRIBUTOS A USAR AGRUPANDO POR EL TIPO DE DATO
    int duracion;
    float costo;
    cout<<"\nIngresa la dirección del lugar: ";getline(cin,nombreAu);//getline nos permite guardar cadenas con espacios en blanco, cosa que cin no nos permite
    cout<<"\nBanda que se presentara: ";getline(cin,banda);//repetimos el proceso con los diferentes atributos
    cout<<"\nDuracion del evento: ";cin>>duracion;//usamos un cin simple sin formato
    cin.ignore(numeric_limits <streamsize>::max(),'\n');//sin esta linea, si damos enter se saltará la linea sgte; va ignorar hasta que encuentre el salto de línea
    cout<<"\nDCosto del boleto: ";cin>>costo;//usamos un cin simple sin fromato
    cin.ignore(numeric_limits <streamsize>::max(),'\n');//pasa cuando usamos enrrada con formato como getline y entradas sin formato como cin
    cout<<"\nNro asiento: ";getline(cin,asiento);//repetimos lo mismo con los demas atributos para solicitar la info
    cout<<"\nDescripcion breve del evento: ";getline(cin,descripcion);
    cout<<"\nFecha de evento: ";getline(cin,fecha);
    cout<<"\nHora de evento: ";getline(cin,hora);
    boleteria venta(nombreAu,banda,duracion,costo,asiento,descripcion,fecha,hora);// creamos una instancia de la clase derivada y la inicializamos por medio del constructor con sus parametros
    return venta;//valor de retorno del tipo venta
}
int main()
{
    boleteria venta1;//se crea la instacia venta1
    venta1=captura();//le asigno el valor de retorno de esta funcion
    cout<<"\n\n\t\t\tDetalles de la Venta: "<<endl<<endl;
    venta1.imprime();//se imprime los resultados de la captura
    venta1.imprimeConcierto();
    venta1.imprimeBoleto();
    return 0;
}
