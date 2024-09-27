#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

//Estructuras:
struct Materiales{
    string nombreMaterial;
    int cantidad;
};

struct Fabrica{
    string mombreFabrica;
    vector <Materiales> Material;

};

struct Alimento{
    string nombre;
    double temperatura;
    double humedad;
    int cantidad;
    string ingreso;
};

struct Categorias{
    string nombre;
    vector <Alimento> alimentos;
};

//Declaramos funciones:
void MostrarMenu(vector <Categorias>& categoria );
void MostrarAlimentosCategoria(const Categorias& categoria);
void AgregarAlimentos(Categorias& categoria);
void EliminarAlimentos(Categorias& categoria);
void AgregarCategoria(vector <Categorias>& categoria);
void EliminarCategoria(vector <Categorias>& categoria);
void Almacen(vector <Categorias>& categoria);
void guardarEnArchivoCategorias(const vector<Categorias>& categorias);
void cargarDesdeArchivoCategorias(vector<Categorias>& categorias);
void MenuFabrica(vector <Fabrica>& fabrica);
void MostrarMaterialesFabrica(const Fabrica& fabrica);
void AgregarMateriales(Fabrica& fabrica);
void EliminarMateriales(Fabrica& fabrica);
void AgregarFabrica(vector <Fabrica>& fabrica);
void EliminarFabrica(vector <Fabrica>& fabrica);
void AlmacenFabrica(vector <Fabrica>& fabrica);
void GuardarEnArchivoFabricas(const vector<Fabrica>& fabricas);
void CargarDesdeArchivoFabricas(vector<Fabrica>& fabricas);


int main(){
    vector <Categorias> categoria;
    vector <Fabrica> fabrica;
    int opcion, opcionFabrica;
    bool salirFabrica = false;
    fstream archivo("Categorias.txt");
    cargarDesdeArchivoCategorias(categoria);
    fstream archivo2("Fabrica.txt");
    CargarDesdeArchivoFabricas(fabrica);

    do{
        cout<<"================================================"<<endl;
        cout<<"====BIENVENIDO AL INVENTARIO DE INGREDIENTES===="<<endl;
        cout<<"================================================"<<endl;
        cout<<"1. Categorias"<<endl;
        cout<<"2. Agregar Categoria"<<endl;
        cout<<"3. Eliminar Categoria"<<endl;
        cout<<"4. Almacen"<<endl;
        cout<<"5. Fabrica"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
            MostrarMenu(categoria);
            break;

        case 2:
            AgregarCategoria(categoria);
            break;

        case 3:
            EliminarCategoria(categoria);
            break;

        case 4:
            system("cls");
            Almacen(categoria);
            break;
        
        case 5:
            system("cls");
            salirFabrica=false;
            do{
                cout << "================================================" << endl;
                cout << "============BIENVENIDO A LA FABRICA============" << endl;
                cout << "================================================" << endl;
                cout << "1. Fabrica" << endl;
                cout << "2. Agregar Fabrica" << endl;
                cout << "3. Eliminar Fabrica" << endl;
                cout << "4. Almacen de fabrica" << endl;
                cout << "0. Regresar al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionFabrica;
                switch (opcionFabrica) {
                    case 1:
                        MenuFabrica(fabrica);
                        break;
                    case 2:
                        AgregarFabrica(fabrica);
                        break;
                    case 3:
                        EliminarFabrica(fabrica);
                        break;
                    case 4:
                        system("cls");
                        AlmacenFabrica(fabrica);
                        break;
                    case 0:
                        cout << "Regresando al menu principal...." << endl;
                        system("pause");
                        system("cls");
                        salirFabrica = true;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                        break;
                }
            }while(!salirFabrica);
            break;
            
        case 0:
            guardarEnArchivoCategorias(categoria);
            GuardarEnArchivoFabricas(fabrica);
            cout<<"Gracias por utilizar el programa"<<endl;
            break;
            
        default:
            cout<<"Opcion invalida, vuelva a intentar"<<endl;
        }
    }while(opcion!=0);

    return 0;
}

//=========================================================================================================================

void MostrarMenu(vector <Categorias> &categoria){
    system("cls");
    cout<<"=============================="<<endl;
    cout<<"====Categorias disponibles===="<<endl;
    cout<<"=============================="<<endl;
    for(size_t i=0; i<categoria.size();i++){
        cout<<i+1<<"."<<categoria[i].nombre<<endl;
    }

    if(categoria.empty()){
        cout<<"No hay categorias disponibles"<<endl;
        system("pause");
        system("cls");
        return;
    }

    int OpcionCategoria;
    cout<<"Selencione el numero de una categoria: ";
    cin >> OpcionCategoria;
    if(OpcionCategoria>=1 && OpcionCategoria<=categoria.size()){
        Categorias& categoriaSeleccion= categoria[OpcionCategoria-1];
        int opcionCategoriaDetallado;
        system("cls");
        do{
            cout<<"==================================================="<<endl;
            cout<<"===="<<"\t"<<categoriaSeleccion.nombre<<"\t"<<"===="<<endl;
            cout<<"==================================================="<<endl;
            cout<<"1. Mostrar alimentos"<<endl;
            cout<<"2. Agregar alimentos"<<endl;
            cout<<"3. Eliminar alimento"<<endl;
            cout<<"0. regresar al inicio"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcionCategoriaDetallado;

            switch(opcionCategoriaDetallado){
                case 1:
                    system("cls");
                    MostrarAlimentosCategoria(categoriaSeleccion);
                    break;
                case 2:
                    AgregarAlimentos(categoriaSeleccion);
                    break;
                case 3:
                    EliminarAlimentos(categoriaSeleccion);
                case 0:
                    system("cls");
                    break;
                default:
                    cout<<"Opcion invalida"<<endl;  
            }
        }while(opcionCategoriaDetallado !=0);
    }
    else if(OpcionCategoria==0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void MostrarAlimentosCategoria(const Categorias& categoria){
    int i=0;
    cout<<"======================================================="<<endl;
    cout<<"====Alimentos en "<<"\t"<<categoria.nombre<<"\t"<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(const Alimento& alimento:categoria.alimentos){
        cout<<i+1<<". "<<alimento.nombre<<" : "<<alimento.cantidad<<" unidades"<<endl;
        i++;
    }
    system("pause");
    system("cls");
}

//=========================================================================================================================

void AgregarAlimentos(Categorias& categoria){
    Alimento nuevoAlimento;
    cout<<"Ingrese el nombre del nuevo alimento: ";
    cin>>nuevoAlimento.nombre;
    cout<<"Ingrese las unidades disponibles: ";
    cin>>nuevoAlimento.cantidad;
    cout<<"Ingrese la temperatura a guardar: ";
    cin>>nuevoAlimento.temperatura;
    cout<<"Ingrese a cuanta humedad debe de estar expuesta: ";
    cin>>nuevoAlimento.humedad;
    cout<<"Fecha de ingreso (colocar --/--/--): ";
    cin>>nuevoAlimento.ingreso;
    categoria.alimentos.push_back(nuevoAlimento);
    cout<<"Nuevo alimento agregado con exito"<<endl;
    system("pause");
    system("cls");
}

//=========================================================================================================================

void EliminarAlimentos(Categorias& categoria){
    if(categoria.alimentos.empty()){
        cout<<"No hay Alimentos para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"======================================================="<<endl;
    cout<<"====\tAlimentos disponibles en"<<categoria.nombre<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(size_t i=0; i<categoria.alimentos.size(); i++){
        cout<<i+1<<". "<<categoria.alimentos[i].nombre<<endl;
    }

    int opcionEliminar;
    cout<<"Ingrese el numero de un alimento para eliminar (0 para cancelar la accion): ";
    cin>>opcionEliminar;

    if(opcionEliminar>=1 && opcionEliminar<=categoria.alimentos.size()){
        categoria.alimentos.erase(categoria.alimentos.begin()+ opcionEliminar-1);
        cout<<"El alimento ha sido eliminado con exito"<<endl;
    }
    else if(opcionEliminar==0){
        return;
    }
    else{
        cout<<"Opcion invalidad"<<endl;
    }    
}

//=========================================================================================================================

void AgregarCategoria(vector<Categorias>& categoria){
    Categorias NuevaCategoria;
    cout<<"Ingrese el nombre de la nueva categoria: ";
    cin>>NuevaCategoria.nombre;
    categoria.push_back(NuevaCategoria);
    cout<<"La categoria ha sido agregado con exito"<<endl;
    system("pause");
    system("cls");
}

//=========================================================================================================================

void EliminarCategoria(vector<Categorias>& categoria){
    if(categoria.empty()){
        cout<<"No hay categorias para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }
    system("cls");
    cout<<"================================"<<endl;
    cout<<"==== Categorias disponibles ===="<<endl;
    cout<<"================================"<<endl;
    for(size_t i=0; i<categoria.size(); i++){
        cout<<i+1<<". "<<categoria[i].nombre<<endl;
    }

    int opcionEliminar;
    cout<<"Seleccione el numero de la categoria a eliminar (0 para cancelar la accion): ";
    cin >> opcionEliminar;

    if(opcionEliminar >=1 && opcionEliminar<=categoria.size()){
        categoria.erase(categoria.begin()+opcionEliminar-1);
        cout<<"Categoria eliminada con exito"<<endl;
        system("pause");
        system("cls");
    }
    else if(opcionEliminar == 0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void Almacen(vector<Categorias>& categoria){
    cout<<"================="<<endl;
    cout<<"==== Almacen ===="<<endl;
    cout<<"================="<<endl;

    if(categoria.empty()){
        cout<<"El Almacen esta vacio"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"Categorias disponibles en almacen: "<<endl;
    for(size_t i=0; i<categoria.size(); i++){
        cout<<i+1<<". "<<categoria[i].nombre<<endl;
    }

    int opcionCategoria;
    cout<<"Ingrese la opcion de una categoria (0 para volver al menu principal): ";
    cin>> opcionCategoria;
     if(opcionCategoria>=1 && opcionCategoria<=categoria.size()){
        const Categorias& categoriaSeleccion = categoria[opcionCategoria-1];
        system("cls");
        cout<<"====Alimentos en la categoria "<<categoriaSeleccion.nombre<<"===="<<endl;
        cout<<"\n";
        cout<<"Nombre\t\tCantidad\tFecha Ingreso\tTemperatura\tHumedad"<<endl;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        for(const Alimento& alimento: categoriaSeleccion.alimentos){
            cout<<alimento.nombre<<"\t"<<alimento.cantidad<<" unidades\t"<<alimento.ingreso<<"\t"<<alimento.temperatura<<"\t"<<"\t"<<alimento.humedad<<endl;
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
        }
        system("pause");
        system("cls");
     }
     else if(opcionCategoria == 0){
        return;
     }
     else{
        cout<<"Opncion Invalida"<<endl;
     }
}

//=========================================================================================================================

void guardarEnArchivoCategorias(const vector<Categorias>& categorias) {
    ofstream archivo("Categorias.txt", ios::out);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    for (const auto& categoria : categorias) {
        archivo << categoria.nombre << "\n";
        for (const auto& alimento : categoria.alimentos) {
            archivo << alimento.nombre << " " << alimento.cantidad <<" "<<alimento.ingreso<<" "<<alimento.temperatura<<" "<<alimento.humedad<<"\n";
        }
        archivo << "#FIN#\n";
    }
}

//=========================================================================================================================

void cargarDesdeArchivoCategorias(vector<Categorias>& categorias) {
    ifstream archivo("Categorias.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo Categorias.txt\n";
        return;
    }

    string nombreCategoria;
    while (archivo >> nombreCategoria) {
        Categorias categoria;
        categoria.nombre = nombreCategoria;
        while (true) {
            Alimento alimento;
            archivo >> alimento.nombre;
            if (alimento.nombre == "#FIN#") break;
            archivo >> alimento.cantidad;
            archivo >> alimento.ingreso;
            archivo >> alimento.temperatura;
            archivo >> alimento.humedad;
            categoria.alimentos.push_back(alimento);
        }
        categorias.push_back(categoria);
    }
}

//=========================================================================================================================

void MenuFabrica(vector <Fabrica>& fabrica){
    system("cls");
    cout<<"=============================="<<endl;
    cout<<"=====Fabricas disponibles====="<<endl;
    cout<<"=============================="<<endl;
    for(size_t i=0; i<fabrica.size();i++){
        cout<<i+1<<"."<<fabrica[i].mombreFabrica<<endl;
    }

    if(fabrica.empty()){
        cout<<"No hay fabricas disponibles"<<endl;
        system("pause");
        system("cls");
        return;
    }

    int OpcionFabrica;
    cout<<"Selencione el numero de una fabrica: ";
    cin >> OpcionFabrica;
    if(OpcionFabrica>=1 && OpcionFabrica<=fabrica.size()){
        Fabrica& FabricaSeleccion= fabrica[OpcionFabrica-1];
        int opcionFabricaDetallado;
        system("cls");
        do{
            cout<<"==================================================="<<endl;
            cout<<"===="<<"\t"<<FabricaSeleccion.mombreFabrica<<"\t"<<"===="<<endl;
            cout<<"==================================================="<<endl;
            cout<<"1. Mostrar materiales"<<endl;
            cout<<"2. Agregar materiales"<<endl;
            cout<<"3. Eliminar materiales"<<endl;
            cout<<"0. regresar al inicio"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>opcionFabricaDetallado;

            switch(opcionFabricaDetallado){
                case 1:
                    system("cls");
                    MostrarMaterialesFabrica(FabricaSeleccion);
                    break;
                case 2:
                    AgregarMateriales(FabricaSeleccion);
                    break;
                case 3:
                    EliminarMateriales(FabricaSeleccion);
                case 0:
                    system("cls");
                    break;
                default:
                    cout<<"Opcion invalida"<<endl;  
            }
        }while(opcionFabricaDetallado !=0);
    }
    else if(OpcionFabrica==0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void MostrarMaterialesFabrica(const Fabrica& Fabrica){
    int i=0;
    cout<<"======================================================="<<endl;
    cout<<"====Materiales en "<<"\t"<<Fabrica.mombreFabrica<<"\t"<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(const Materiales& material:Fabrica.Material){
        cout<<i+1<<". "<<material.nombreMaterial<<" : "<<material.cantidad<<" unidades"<<endl;
        i++;
    }
    system("pause");
    system("cls");
}

//=========================================================================================================================

void AgregarMateriales(Fabrica& fabrica){
    Materiales nuevoMaterial;
    cout<<"Ingrese el nombre del material: ";
    cin>>nuevoMaterial.nombreMaterial;
    cout<<"Ingrese la cantidad: ";
    cin>>nuevoMaterial.cantidad;
    fabrica.Material.push_back(nuevoMaterial);
    cout<<"Nuevo material agregado con exito"<<endl;
    system("pause");
    system("cls");
}

//=========================================================================================================================

void EliminarMateriales(Fabrica& fabrica){
    if(fabrica.Material.empty()){
        cout<<"No hay materiales para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"======================================================="<<endl;
    cout<<"====\tMateriales disponibles en"<<fabrica.mombreFabrica<<"===="<<endl;
    cout<<"======================================================="<<endl;
    for(size_t i=0; i<fabrica.Material.size(); i++){
        cout<<i+1<<". "<<fabrica.Material[i].nombreMaterial<<endl;
    }

    int opcionEliminarMaterial;
    cout<<"Ingrese el numero de un material para eliminar (0 para cancelar la accion): ";
    cin>>opcionEliminarMaterial;

    if(opcionEliminarMaterial>=1 && opcionEliminarMaterial<=fabrica.Material.size()){
        fabrica.Material.erase(fabrica.Material.begin()+ opcionEliminarMaterial-1);
        cout<<"El material ha sido eliminado con exito"<<endl;
    }
    else if(opcionEliminarMaterial==0){
        return;
    }
    else{
        cout<<"Opcion invalidad"<<endl;
    }    
}

//=========================================================================================================================

void AgregarFabrica(vector<Fabrica>& fabrica){
    Fabrica nuevaFabrica;
    cout<<"Ingrese el nombre de la nueva fabrica: ";
    cin>>nuevaFabrica.mombreFabrica;
    fabrica.push_back(nuevaFabrica);
    cout<<"La fabrica ha sido agregado con exito"<<endl;
    system("pause");
    system("cls");
}

//=========================================================================================================================

void EliminarFabrica(vector<Fabrica>& fabrica){
    if(fabrica.empty()){
        cout<<"No hay fabricas para eliminar"<<endl;
        system("pause");
        system("cls");
        return;
    }
    system("cls");
    cout<<"================================"<<endl;
    cout<<"===== Fabricas disponibles ====="<<endl;
    cout<<"================================"<<endl;
    for(size_t i=0; i<fabrica.size(); i++){
        cout<<i+1<<". "<<fabrica[i].mombreFabrica<<endl;
    }

    int opcionEliminarFabrica;
    cout<<"Seleccione el numero de la fabrica a eliminar (0 para cancelar la accion): ";
    cin >> opcionEliminarFabrica;

    if(opcionEliminarFabrica >=1 && opcionEliminarFabrica<=fabrica.size()){
        fabrica.erase(fabrica.begin()+opcionEliminarFabrica-1);
        cout<<"Fabrica eliminada con exito"<<endl;
        system("pause");
        system("cls");
    }
    else if(opcionEliminarFabrica == 0){
        return;
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
}

//=========================================================================================================================

void AlmacenFabrica(vector<Fabrica>& fabrica){
    cout<<"==============================="<<endl;
    cout<<"==== Almacen de la fabrica ===="<<endl;
    cout<<"==============================="<<endl;

    if(fabrica.empty()){
        cout<<"El Almacen esta vacio"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"Fabricas disponibles: "<<endl;
    for(size_t i=0; i<fabrica.size(); i++){
        cout<<i+1<<". "<<fabrica[i].mombreFabrica<<endl;
    }

    int opcionFabrica;
    cout<<"Ingrese la opcion de una fabrica (0 para volver al menu principal): ";
    cin>> opcionFabrica;
     if(opcionFabrica>=1 && opcionFabrica<=fabrica.size()){
        const Fabrica& fabricaSeleccion = fabrica[opcionFabrica-1];
        system("cls");
        cout<<"====Materiales en la fabrica de "<<fabricaSeleccion.mombreFabrica<<"===="<<endl;
        cout<<"\n";
        cout<<"Nombre\t\tCantidad"<<endl;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        for(const Materiales& material: fabricaSeleccion.Material){
            cout<<material.nombreMaterial<<"\t"<<material.cantidad<<" unidades"<<endl;
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
        }
        system("pause");
        system("cls");
     }
     else if(opcionFabrica == 0){
        return;
     }
     else{
        cout<<"Opncion Invalida"<<endl;
     }
}

//=========================================================================================================================

void GuardarEnArchivoFabricas(const vector<Fabrica>& fabricas) {
    ofstream archivo2("Fabricas.txt", ios::out);
    if(archivo2.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    for (const auto& fabrica : fabricas) {
        archivo2 << fabrica.mombreFabrica << "\n";
        for (const auto& Materiales : fabrica.Material) {
            archivo2 << Materiales.nombreMaterial << " " << Materiales.cantidad<<"\n";
        }
        archivo2 << "#FIN#\n";
    }
}
//=========================================================================================================================

void CargarDesdeArchivoFabricas(vector<Fabrica>& fabricas) {
    ifstream archivo2("Fabricas.txt");
    if (!archivo2.is_open()) {
        cout << "Error al abrir archivo Fabricas.txt\n";
        return;
    }
    string nombreFabrica;
    while (archivo2 >> nombreFabrica) {
        Fabrica fabrica;
        fabrica.mombreFabrica = nombreFabrica;
        while (true) {
            Materiales material;
            archivo2 >> material.nombreMaterial;
            if (material.nombreMaterial == "#FIN#") break;
            archivo2 >> material.cantidad;
            fabrica.Material.push_back(material);
        }
        fabricas.push_back(fabrica);
    }
}