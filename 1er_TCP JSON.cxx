#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;
//clase persona
class persona{
	//atributos de persona
	protected:
	string nombre;
	string apellido;
	string ID;
	string phone;
	
	public:
	//constructor persona
	persona(string nom,string ap,string id,string tel){
		nombre=nom;
		apellido=ap;
		ID=id;
		phone= tel;
	}
	//getters
	string getN(){
		return nombre;
	}
	string getA(){
		return apellido;
	}
	string getID(){
		return ID;
	}
	string getP(){
		return phone;
	}
	//setters
	void setN(string nom1){
		nombre=nom1;
		cout<<"El nuevo nombre es:"<<nom1<<endl;
	}
	void setA(string ap1){
		apellido=ap1;
		cout<<"El nuevo apellido es:"<<ap1<<endl;
	}
	void setID(string id1){
		ID=id1;
		cout<<"El nuevo ID es:"<<id1<<endl;
	}
	void setP(string tel1){
		phone=tel1;
		cout<<"El nuevo telefono es:"<<tel1<<endl;
	}
	// metodo mostrar
	void mostrar(){
		cout<<"Nombre:"<<nombre<<" "<<apellido<<endl;
		cout<<"ID:"<<ID<<endl;
		cout<<"Telefono:"<<phone<<endl;
	}
};

//clase empleado
class empleado : public persona{
	//atributos empleado
	private:
	string cargo;
	int salario;
	public:
	//constructor
	empleado (string nom,string ap,string id, string tel ,string car,int sal):persona(nom,ap,id,tel){
		cargo=car;
		if(sal>=1000){
			salario=sal;
		}else{
			salario=1000;
		}
	}
	//getters
	string getC(){
		return cargo;
	}
	int getS(){
		return salario;
	}
	//setters
	void setC(string car1){
		cargo=car1;
		cout<<"El nuevo cargo es:"<<car1<<endl;
	}
	 
	//metodo mostrar toda la info
	void mostrarEmp(){
		persona::mostrar();
		cout<<"Cargo: "<<cargo<<endl;
		cout<<"Salario: "<<salario<<endl;
	}
	//metodo actualizar salario
	void actualizarEmp(int sal1){
		if(sal1>=1000){
			salario=sal1;
		}
	}
};

void addEmp(vector<empleado>&em){
	string n,a,i,t,c;
	int s;
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Apellido:"<<endl;
	cin>>a;
	cout<<"Telefono:"<<endl;
	cin>>t;
	cout<<"Cargo:"<<endl;
	cin>>c;
	cout<<"Salario: (minimo 1000, si se pone una cifra inferior a 1000, se pondra 1000 por defecto)"<<endl;
	cin>>s;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<em.size();j++){
			if(em[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido insertelo de nuevo"<<endl;
		}
	}while(y!=1);
	empleado emp(n,a,i,t,c,s);
	em.push_back(emp);
}
void eliminarEmp(vector<empleado>&em){
	string i1;
	int x=0;
	cout<<"ID del empleado que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<em.size();i++){
		if(em[i].getID()==i1){
			em.erase(em.begin() +i);
			x=1;
			break;
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
void modificarEmp(vector<empleado>&em){
	string i1,i,n,a,d,t,c;
	int x=0;
	int y;
	int s;
	cout<<"ID del empleado que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<em.size();j++){
		if(em[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Apellido:"<<endl;
			cin>>a;
			cout<<"Telefono:"<<endl;
			cin>>t;
			cout<<"Cargo:"<<endl;
			cin>>c;
			cout<<"Salario: (minimo 1000, si se pone una cifra inferior a 1000, se pondra 1000 por defecto)"<<endl;
			cin>>s;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<em.size();j++){
					if(em[j].getID()==i){
						if(i!=i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido insertelo de nuevo"<<endl;
				}
			}while(y!=1);		
			em[j].setN(n);
			em[j].setA(a);
			em[j].setID(i);
			em[j].setP(t);
			em[j].setC(c);
			em[j].actualizarEmp(s);
			x=1;	
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
void consultarEmp(vector<empleado>&em){
	string i1;
	int x=0;
	cout<<"ID del empleado q desea consultar:"<<endl;
	cin>>i1;
	for(int i=0;i<em.size();i++){
		if(em[i].getID()==i1){
			em[i].mostrarEmp();
			x=1;
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
void promedioEmp(vector<empleado>&em){
	double suma=0;
	if(em.empty()){
		cout<<"ERROR: No hay empleados añadidos"<<endl;
	}else{
	for(int i=0;i<em.size();i++){
		suma+=em[i].getS();
	}
	cout<<"Promedio: "<<suma/em.size()<<endl;
	}
}

void mayorEmp(vector<empleado>&em){
	if(em.empty()){
cout<<"ERROR: No hay empleados añadidos"<<endl;
	}else{
map<string,pair<string, int>> salMap;
for(int i=0;i<em.size();i++){
	salMap[em[i].getID()].first=em[i].getN();
	salMap[em[i].getID()].second=em[i].getS();
	  }
int max=0;
	for(auto &p:salMap){
	    if(p.second.second>max){ 
		max=p.second.second;
}
	}
	cout<<"Empleado/s con el mayor salario ("<<max<<"):"<<endl;
cout<<"==============="<<endl;
	for(auto &p:salMap){
if(p.second.second==max){ 
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"ID: "<<p.first<<endl;
}
	}
cout<<"==============="<<endl;
}
}

void conteoEmp(vector<empleado>&em){
	if(em.empty()){
		cout<<"ERROR: No hay empleados añadidos"<<endl;
	}else{
		map<string,int> conteoCargos;
		for(int i=0;i<em.size();i++){
			conteoCargos[em[i].getC()]++;
		}
		cout<<"Cantidad de empleados por cargo:"<<endl;
		for(auto &p:conteoCargos){
			cout<<"==============="<<endl;
			cout<<"Cargo: "<<p.first<<endl;
			cout<<"Cantidad: "<<p.second<<endl;
			cout<<"==============="<<endl;
		}
	}
}


class Producto {
	private :
	string ID;
	string nombre;
	string categoria;
	double precio, costo;
	int stock;
	
	public:
	
	// constructor
	
	 Producto(string id="", string n="", string c="", double p=0, double cos=0, int s=0) {
	 ID = id;
	 nombre = n;
	 categoria = c;
	 precio = p;
	 costo=cos;
	 stock = s;
	 }
	
	 
	 //getters
	 int getStock(){
	 		return stock;
	 }
	 string getID(){
	 return ID;
	 }
	string getNombre(){
	return nombre;
	}
	string getCategoria(){
	return categoria;
	}
	double getPrecio(){
	 return precio;
	} 
	double getCosto(){
	 return costo;
	}
	 //setters
	 void setStock (int nuevoStock) {
	 			stock = nuevoStock;
	 			cout<<"Nuevo stock: "<<stock<<endl;
	 }
	 void setID (string nuevoID) {
	 			ID = nuevoID;
	 			cout<<"Nuevo ID: "<<ID<<endl;
	 }
	 void setNombre (string nuevoNombre) {
	 			nombre = nuevoNombre;
	 			cout<<"Nuevo nombre: "<<nombre<<endl;		
	 }
	 void setCateg (string nuevoCateg) {
	 			categoria= nuevoCateg;
	 			cout<<"Nueva categoria: "<<categoria<<endl;
	 }
	 void setPrecio (double nuevoPrecio) {
	 			precio = nuevoPrecio;
	 			cout<<"Nuevo precio: "<<precio<<endl;
	 }
	 void setCosto (double nuevoCosto) {
	 			costo = nuevoCosto;
	 			cout<<"Nuevo costo: "<<costo<<endl;
	 }
};

void upgStock(vector <Producto>&prod){
	int s=0;
	int aux=0;
	string i1;
	cout<<"ID del producto que desea actualizar su stock:"<<endl;
	cin>>i1;
	for(int j=0;j<prod.size();j++){
		if(prod[j].getID()==i1){
			aux++;
		cout<<"Ingrese el nuevo stock"<<endl;
		cin>>s;
		if(s>0){
			prod[j].setStock(s);
		}else{
		cout<<"ERROR: Stock invalido"<<endl;
		}
		}
	}
	if(aux==0){
	 cout<<"No se encontro el producto"<<endl;
	}
	 }

void addProd(vector<Producto>&prod, vector<string>&categ) {
	string i,n,c;
	double p, cos;
	int s;
	int y=1;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<prod.size();j++){
			if(prod[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido insertelo de nuevo"<<endl;
		}
	}while(y!=1);
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Categoria:"<<endl;
	cin>>c;
	do{
		int y=1;
	cout<<"Costo:"<<endl;
	cin>>cos;
	if(cos<0){
		cout<<"ERROR: Costo invalido"<<endl;
		y=0;
	}
	}while(y==0);
	do{
		y=1;
	cout<<"Precio:"<<endl;
	cin>>p;
	if(p<0){
		cout<<"ERROR: Precio invalido"<<endl;
		y=0;
	}
	}while(y==0);
	y=1;
	do{
	cout<<"Stock:"<<endl;
	cin>>s;
	if(s<0){
		cout<<"ERROR: Stock invalido"<<endl;
		y=0;
	}
	}while(y==0);
	Producto prodaux(i, n, c, p, cos, s);
	prod.push_back(prodaux);
	int cant=0;
	if(categ.empty()){
	categ.push_back(c);	
	}else{
		for(int i=0;i<categ.size();i++){
		if(categ[i]==c){
			cant++;
				}	
		}
		if(cant==0){
			categ.push_back(c);
		}
}
}

void eliminarProd(vector<Producto>&prod){
	 string i1;
	int x=0;
	cout<<"ID del producto que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<prod.size();i++){
		if(prod[i].getID()==i1){
			prod.erase(prod.begin()+i);
			x=1;
			break;
		}
	}
	if(x==0){
		cout<<"Producto no encontrado"<<endl;
	}
}

void modificarProd(vector<Producto>&prod, vector<string>&categ){
	string i, n, c;
	double p, cos;
	int s;
	int x=0;
	int y;
	string i1;
	
	cout<<"ID del producto que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<prod.size();j++){
		if(prod[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Categoria:"<<endl;
			cin>>c;
			cout<<"Costo:"<<endl;
			cin>>cos;
			cout<<"Precio:"<<endl;
			cin>>p;
			cout<<"Stock:"<<endl;
			cin>>s;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<prod.size();j++){
					if(prod[j].getID()==i){
						if(i!=i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido insertelo de nuevo"<<endl;
				}
			}while(y!=1);		
			prod[j].setNombre(n);
			prod[j].setCateg(c);
			prod[j].setID(i);
			prod[j].setPrecio(p);
			prod[j].setCosto(cos);
			prod[j].setStock(s);
			x=1;	
			int cant=0;
	if(categ.empty()){
	categ.push_back(c);	
	}else{
		for(int i=0;i<categ.size();i++){
		if(categ[i]==c){
			cant++;
				}	
		}
		if(cant==0){
			categ.push_back(c);
		}
}
		}
	}
	if(x==0){
		cout<<"Producto no encontrado"<<endl;
	}
}

void stockcritico(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		int cant=0;
		map<string, pair<string,int>> stockMap;
		for(int i=0;i<prod.size();i++){
			stockMap[prod[i].getID()].first=prod[i].getNombre();
			stockMap[prod[i].getID()].second=prod[i].getStock();
		}
		for(auto &p:stockMap){
			if(p.second.second<=10){
				cant++;
				cout<<"Productos con stock critico (10 unidades o menos): "<<endl;
	cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
	cout<<"Stock: "<<p.second.second<<endl;
	cout<<"==============="<<endl;
			}
		}
		if(cant==0){
			cout<<"No hay productos con stock critico"<<endl;
		}
	}
}

void caro_barato(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		double max=0;
		double min=9999999999;
		for(int i=0;i<prod.size();i++){
			if(prod[i].getPrecio()>max){ max=prod[i].getPrecio();
			}
			if(prod[i].getPrecio()<min){ min=prod[i].getPrecio();
			}
		}
	map<string, pair<string, double>> caros;
	map<string, pair<string, double>> baratos;
		for(int i=0;i<prod.size();i++){
			if(prod[i].getPrecio()==max){
caros[prod[i].getID()].first=prod[i].getNombre();
caros[prod[i].getID()].second=prod[i].getPrecio();
			}
			if(prod[i].getPrecio()==min){
baratos[prod[i].getID()].first=prod[i].getNombre();
baratos[prod[i].getID()].second=prod[i].getPrecio();
			}
		}
cout<<"Productos de mayor precio ("<<max<<"$): "<<endl;
		for(auto &p:caros){
		cout<<"==============="<<endl;
		cout<<"Nombre: "<<p.second.first<<endl;
		cout<<"ID: "<<p.first<<endl;
		cout<<"==============="<<endl;
		}
		cout<<""<<endl;
	cout<<"Productos de menor precio ("<<min<<"$): "<<endl;
		for(auto &p:baratos){
		cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
		cout<<"ID: "<<p.first<<endl;
		cout<<"==============="<<endl;
		}
	}
}

void rangoP (vector<Producto> &prod){
 cout<<"Ingrese limite superior"<<endl;
 double max;
 cin>>max;
cout<<"Ingrese limite inferior"<<endl;
 double min;
 cin>>min;
 if(min<0){
 	min=0;
 }
if(max<=min){
	cout<<"ERROR: Rango invalido"<<endl;
}else{
map<string,Producto> prodMap;
for(int i=0;i<prod.size();i++){
	prodMap[prod[i].getNombre()]=prod[i];
	}
cout<<"Productos en el rango:"<<endl;
int cant=0;
for(auto &p:prodMap){
if(p.second.getPrecio()<=max&&p.second.getPrecio()>=min){
	cout<<"==================="<<endl;
cout<<"Nombre: "<<p.first<<endl;
cout<<"ID: "<<p.second.getID()<<endl;
cout<<"Categoria: "<<p.second.getCategoria()<<endl;
cout<<"Precio: "<<p.second.getPrecio()<<endl;
cout<<"==================="<<endl;
	cant++;
	}
	}
if(cant==0){
cout<<"No se encontraron productos"<<endl;
}
}
}

void buscarCateg(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	cout<<"Ingrese la categoria"<<endl;
	string aux;
	int aux2=0;
	cin>>aux;
	map<string,vector<Producto>> categMap;
	for(int i=0;i<prod.size();i++){
		if(prod[i].getCategoria()==aux){
			aux2=1;
		categMap[prod[i].getCategoria()].push_back(prod[i]);
		}
	}
	if(aux2==1){
	cout<<"Productos de la categoria:"<<endl;
	for(auto &p:categMap){
	for(int i=0;i<p.second.size();i++){
		cout<<"==============="<<endl;  
cout<<"Nombre: "<<p.second[i].getNombre()<<endl;
cout<<"ID: "<<p.second[i].getID()<<endl;
cout<<"Precio: "<<p.second[i].getPrecio()<<endl;
	 cout<<"==============="<<endl;
		}
	}
	}else{
		cout<<"ERROR: No se encontraron productos de esa categoria"<<endl;		
	}
}
}


void buscarName (vector <Producto> &prod){
	cout<<"Ingrese el nombre del producto"<<endl;
	string aux;
	cin>>aux;
	map<string,Producto> prodMap;
for(int i=0;i<prod.size();i++){
	prodMap[prod[i].getNombre()]=prod[i];
	}
int cant=0;
cout<<"Productos encontrados: "<<endl;
	for(auto &p:prodMap){
		int pos=p.first.find(aux);
		if(pos!=string::npos){
	cout<<"==============="<<endl;		
	cout<<"Nombre: "<<p.first<<endl;
 cout<<"ID: "<<p.second.getID()<<endl;
cout<<"Categoria: "<<p.second.getCategoria()<<endl;
cout<<"Precio: "<<p.second.getPrecio()<<endl;
 	cout<<"==============="<<endl;
 	cant++;
	}
	}	
if(cant==0){
cout<<"No se encontraron productos"<<endl;
}
}

class cliente : public persona {
	private :
	string correo ;
	vector<string>compras;
	public:
	cliente(string nom,string ap,string id,string tel,string cor):persona (nom,ap,id,tel){
		correo=cor;
	}
	string getCor(){
		return correo;
	}
	vector<string> getCom(){
		return compras;
		}
	
	void setCor(string co){
		correo=co;
	}
	void addCom(string com){
		compras.push_back(com);
	}
	void eliminarCom(string id){
	for (int i=0;i<compras.size();i++){
		if(id==compras[i]){
			compras.erase(compras.begin()+i);
		}
			}	
	}
	void historial(){
		cout<<"historial de compras :"<<endl;
		for(int i=0;i<compras.size();i++){
			cout<<compras[i]<<endl;
		}
	}
};
void addCli(vector<cliente>&cl){
	string n,a,i,t,c;
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Apellido:"<<endl;
	cin>>a;
	cout<<"Telefono:"<<endl;
	cin>>t;
	cout<<"Correo:"<<endl;
	cin>>c;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<cl.size();j++){
			if(cl[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido insertelo de nuevo"<<endl;
		}
	}while(y!=1);
	cliente cli(n,a,i,t,c);
	cl.push_back(cli);
}
void eliminarCli(vector<cliente>&cl){
    string i1;
    int x=0;
    cout<<"ID del cliente que desea eliminar:"<<endl;
    cin>>i1;
    for(int i=0; i<cl.size(); i++){
        if(cl[i].getID()==i1){
            if(cl[i].getCom().empty()){
                cl.erase(cl.begin() + i);
                x=1;
                break; 
            }else{
                cout<<"no se puede eliminar cliente con compras"<<endl;
                x=1;
                break; 
            }
        }
    }
    if(x==0){
        cout<<"Cliente no encontrado"<<endl;
    }
}

void modificarCli(vector<cliente>&cl){
	string i1,i,n,a,d,t,c;
	int x=0;
	int y;
	cout<<"ID del cliente que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<cl.size();j++){
		if(cl[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Apellido:"<<endl;
			cin>>a;
			cout<<"Telefono:"<<endl;
			cin>>t;
			cout<<"Correo:"<<endl;
			cin>>c;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<cl.size();j++){
					if(cl[j].getID()==i){
						if(i!=i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido insertelo de nuevo"<<endl;
				}
			}while(y!=1);		
			cl[j].setN(n);
			cl[j].setA(a);
			cl[j].setID(i);
			cl[j].setP(t);
			cl[j].setCor(c);
			x=1;	
		}
	}
	if(x==0){
		cout<<"Cliente no encontrado"<<endl;
	}
}
void consultarHist(vector<cliente>&cl){
	string i1;
	int x=0;
	cout<<"ID del cliente q desea consultar:"<<endl;
	cin>>i1;
	for(int i=0;i<cl.size();i++){
		if(cl[i].getID()==i1){
			cl[i].historial();
			x=1;
		}
	}
	if(x==0){
		cout<<"Cliente no encontrado"<<endl;
	}
}

//Validar fecha
bool bisiesto(int a){
if ((a%4==0 && a%100!=0)||(a%400==0)){
	return 1;
		}else{
			return 0;
				}	
}
int cantD (int m, int a){
switch (m){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	return 31;
	case 4: case 6: case 9: case 11:
	return 30;
	case 2:
	if (bisiesto(a)){
	return 29;	
	}else{
	return 28;	
	}
	
}

}
bool valida(int d, int m, int a){
if ((d>=1 && d<=cantD(m, a))&&(m>=1 && m<=12)&&(a>=1)){
	return 1;
}else{
return 0;
}
}



class ventas{
	private :
	string ID;
	string cliente;
	int dia, mes, year;
	vector<Producto>productos;
	double total;
	
	public:
	
	// constructor
	
ventas(string id="", string c="", vector<Producto>p={}, double t=0, int d=1, int m=1, int a=1) {
	 ID = id;
	 cliente = c;
	 productos=p;
	 total=t;
	 dia=d;
	 mes=m;
	 year=a;
	 }
	
	 
	 //getters
	 string getID(){
	 return ID;
	 }
	string getCliente(){
	return cliente;
	}
	vector<Producto> getProd(){
	return productos;
	}
	double getTotal(){
	 return total;
	} 
	int getDia(){
		return dia;
	}
	int getMes(){
		return mes;
	}
	int getYear(){
		return year;
	}
	
	 //setters
	 void setID (string nuevoID) {
	 			ID = nuevoID;
	 			cout<<"Nuevo ID: "<<ID<<endl;
	 }
	 void setCliente (string nuevoCl) {
	 			cliente = nuevoCl;
	 			cout<<"Nuevo cliente: "<<cliente<<endl;		
	 }
	 void setTotal(double cantT){
	 	total=cantT;
	 		}
	 
	 void setDia(int d){
	 	dia=d;
	 	}
	 void setMes(int m){
	 	mes=m;
	 	}
	 void setYear(int a){
	 	year=a;;
	 	}			
};

void addVen(vector<ventas>&vent, vector<cliente>&cl, vector<Producto>&pr){
	
	string i, c, p1;
	vector<Producto>p;
	Producto p2;
	double t=0;
	int d, m, a;
	int s, in;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<vent.size();j++){
			if(vent[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido insertelo de nuevo"<<endl;
		}
	}while(y!=1);
	cout<<"Cliente:"<<endl;
	cin>>c;
	int aux=0;
	for(int j=0;j<cl.size();j++){
	if(c==cl[j].getID()){
		aux=1;
		in=j;
	}	
	}
	if(aux!=0){
	int z=0;
	do{
		cout<<"Ingrese la fecha"<<endl;
		cin>>d;
		cin>>m;
		cin>>a;
		if(valida(d, m, a)){
			cout<<"Fecha valida"<<endl;
			z=1;
		}else{
		cout<<"ERROR: Fecha invalida"<<endl;
		}
		}while(z!=1);	
	z=0;
	do{
		cout<<"Ingrese el ID del producto que desea agregar"<<endl;
		cin>>p1;
		int auxc=0;
		for (int j=0;j<pr.size();j++){
	if(p1==pr[j].getID()){
		auxc=1;
		cout<<"Ingrese la cantidad"<<endl;
		cin>>s;
		if(s<=pr[j].getStock()&&s>0){
			string np=pr[j].getNombre();
			string cp=pr[j].getCategoria();
			double pp=pr[j].getPrecio();
			double pcos=pr[j].getCosto();
		Producto p2(p1,np,cp,pp,pcos,s);
	p.push_back(p2);
	t=t+pr[j].getPrecio()*s;
	pr[j].setStock(pr[j].getStock()-s);
	cout<<"Producto añadido"<<endl;
	}else{
		cout<<"Cantidad invalida"<<endl;
		}	
	}
		}
		if(auxc==0){
		cout<<"Producto no encontrado"<<endl;	
		}
		
	cout<<"Desea agregar otro producto (s/n)"<<endl;
	string o;
	int z1=0;
	do{
		cin>>o;
		if(o=="s"){
			z1=1;
		}
		if(o=="n"){
			z1=1;
			z=1;
		}
			
}while(z1!=1);		
}while(z!=1);
if(p.empty()){
	cout<<"Venta cancelada"<<endl;
}else{
ventas v(i,c,p,t,d,m,a);
vent.push_back(v);
cl[in].addCom(i);
}	
}else{
	cout<<"El cliente no existe"<<endl;
}
}

void eliminarVen(vector<ventas>&vent, vector<cliente>&cl,vector<Producto>&pr){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas"<<endl;
	}else{
	string i1;
	int x=0;
	cout<<"ID de la compra que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<vent.size();i++){
		if(vent[i].getID()==i1){
		       int in=i;
	        for (int j=0;j<cl.size();j++){
	       if (vent[i].getCliente()==cl[j].getID()){
	        		cl[j].eliminarCom(i1);
	        		}	
	        }
			x=1;
			cout<<"Desea reestablecer el stock (s/n)"<<endl;
	string o;
	int z1=0;
	do{
		cin>>o;
		if(o=="s"){
			z1=1;
	for(int i=0;i<vent[in].getProd().size();i++){
		for(int k=0;k<pr.size();k++){
			if(pr[k].getID()==vent[in].getProd()[i].getID()){
			pr[k].setStock(pr[k].getStock()+vent[in].getProd()[i].getStock());	
			}
				}		
			}
		}
		if(o=="n"){
			z1=1;
			
		}
			
}while(z1!=1);
vent.erase(vent.begin() +i);		
	
		}
	}
	if(x==0){
		cout<<"Venta no encontrada"<<endl;
	}
}
}

void sbCliente(vector<ventas>&vent, vector<cliente>&cl){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas"<<endl;
	}else{
	string id;
	int aux=0;
	int aux2=0;
	cout<<"Ingrese el ID del cliente"<<endl;
	cin>>id;
	for(int i=0;i<cl.size();i++){
		if(cl[i].getID()==id){
			aux=1;
		}
	}
	if(aux==0){
		cout<<"El cliente no existe"<<endl;
	}else{
	map<string,vector<ventas>> ventMap;
	for(int i=0;i<vent.size();i++){
		if(vent[i].getCliente()==id){
		ventMap[vent[i].getCliente()].push_back(vent[i]);
		aux2=1;
		}
	}
	for(auto &p:ventMap){
	for(int i=0;i<p.second.size();i++){
			aux2=1;
	cout<<"==============="<<endl;
	cout<<"ID: "<<p.second[i].getID()<<endl;
cout<<"Productos:"<<endl;
for(int j=0;j<p.second[i].getProd().size();j++){
	cout<<p.second[i].getProd()[j].getNombre()<<"-"<<p.second[i].getProd()[j].getStock()<<" unidades"<<endl;
			  	}
cout<<"Total: "<<p.second[i].getTotal()<<endl;
cout<<"==============="<<endl;
		}
	}
	if(aux2==0){
		cout<<"El cliente no tiene compras"<<endl;
	}
}
}
}

void rangoFecha(vector<ventas>&vent){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		int d1, m1, a1;
		int d2, m2, a2;
		cout<<"Ingrese fecha inicial (dia mes año):"<<endl;
		cin>>d1;
		cin>>m1;
		cin>>a1;
		cout<<"Ingrese fecha final (dia mes año):"<<endl;
		cin>>d2;
		cin>>m2;
		cin>>a2;
		
		int cant=0;
		if(valida(d1,m1,a1) && valida(d2,m2,a2)){
			map<string,ventas> ventMap;
			for(int i=0;i<vent.size();i++){
				ventMap[vent[i].getID()]=vent[i];
			}
			
			cout<<"Ventas en el rango de fechas:"<<endl;
			
			for(auto &p:ventMap){
				// Verificar si fecha >= fecha_inicial (igual o posterior)
				int esMayorOIgual=0;
				if((p.second.getYear()>a1)||(p.second.getYear()==a1&&p.second.getMes()>m1)||(p.second.getYear()==a1&&p.second.getMes()==m1&&p.second.getDia()>=d1)){
					esMayorOIgual=1;
				}
				
				// Verificar si fecha <= fecha_final (igual o anterior)
				int esMenorOIgual=0;
				if((p.second.getYear()<a2)||(p.second.getYear()==a2&&p.second.getMes()<m2)||(p.second.getYear()==a2&&p.second.getMes()==m2&&p.second.getDia()<=d2)){
					esMenorOIgual=1;
				}
				
				// Si cumple ambas condiciones, está en el rango
				if(esMayorOIgual==1 && esMenorOIgual==1){
					cant++;
					cout<<"==============="<<endl;
					cout<<"ID: "<<p.first<<endl;
					cout<<"Cliente: "<<p.second.getCliente()<<endl;
					cout<<"Fecha: "<<p.second.getDia()<<"/"<<p.second.getMes()<<"/"<<p.second.getYear()<<endl;
					cout<<"Productos:"<<endl;
					for(int j=0;j<p.second.getProd().size();j++){
						cout<<p.second.getProd()[j].getNombre()<<"-"<<p.second.getProd()[j].getStock()<<" unidades"<<endl;
					}
					cout<<"Total: "<<p.second.getTotal()<<endl;
					cout<<"==============="<<endl;
				}
			}
			
			if(cant==0){
				cout<<"No se encontraron ventas en ese rango"<<endl;
			}
		}else{
			cout<<"Fecha invalida"<<endl;
		}
	}
}



void totalCat(vector<ventas>&vent, vector<string>&categ){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		map<string,pair<int,double>> totCat;
		for(int j=0;j<vent.size();j++){
			vector<Producto> prods=vent[j].getProd();
	for(int k=0;k<prods.size();k++){
	totCat[prods[k].getCategoria()].first+=prods[k].getStock();
 totCat[prods[k].getCategoria()].second+=prods[k].getPrecio()*prods[k].getStock();
			}
		}
		cout<<"Total vendido por categoria:"<<endl;
		for(auto &p:totCat){
	cout<<"==============="<<endl;
	cout<<"Categoria: "<<p.first<<endl;
cout<<"Cantidad vendida: "<<p.second.first<<endl;
	cout<<"Total dinero: "<<p.second.second<<"$"<<endl;
	cout<<"==============="<<endl;
}
	}
}


void masVendido(vector<ventas>&vent){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
	map<string,pair<string,int>> conteoMap;
		for(int i=0;i<vent.size();i++){
		for(int j=0;j<vent[i].getProd().size();j++){
		string id=vent[i].getProd()[j].getID();
string nom=vent[i].getProd()[j].getNombre();
int cant=vent[i].getProd()[j].getStock();
	conteoMap[id].first=nom;
	conteoMap[id].second+=cant;
		}
		}
		int max=0;	
	for(auto &p:conteoMap){
	if(p.second.second>max){
		max=p.second.second;
	}
		}
		cout<<"Producto/s mas vendido/s ("<<max<<" unidades):"<<endl;
	for(auto &p:conteoMap){
	if(p.second.second==max){
		cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;	
		cout<<"==============="<<endl;
	}
		}
}
}


void clienteMas(vector<cliente>&cli, vector<ventas>&vent){
	if(vent.empty()){
		cout<<"No hay ventas registradas"<<endl;
	}else{
	map<string,pair<string,int>> comprasMap;
		for(int i=0;i<cli.size();i++){
comprasMap[cli[i].getID()].first=cli[i].getN();
comprasMap[cli[i].getID()].second=cli[i].getCom().size();
		}
		int max=0;
		for(auto &p:comprasMap){
if(p.second.second>max){
		 max=p.second.second;
}
		}
	cout<<"Clientes con mayor numero de compras("<<max<<"):"<<endl;
		for(auto &p:comprasMap){
				if(p.second.second==max){	
cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"==============="<<endl;
			}
		}
		map<string,pair<string,int>> prodMap;
		for(int i=0;i<cli.size();i++){
	prodMap[cli[i].getID()].first=cli[i].getN();
		prodMap[cli[i].getID()].second=0;
		}
	for(int i=0;i<vent.size();i++){
	int aux=0;
		for(auto &p:prodMap){
		if(p.first==vent[i].getCliente()){
			aux=1;
				}
			}
	if(aux==1){
	for(int j=0;j<vent[i].getProd().size();j++){
	prodMap[vent[i].getCliente()].second+=vent[i].getProd()[j].getStock();
		}
			}
		}
	max=0;
	for(auto &p:prodMap){
	if(p.second.second>max){ 
	max=p.second.second;
	}
		}
		cout<<""<<endl;
cout<<"Clientes con mayor numero de productos comprados("<<max<<"):"<<endl;
	for(auto &p:prodMap){
		if(p.second.second==max){
cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"==============="<<endl;
		}
	}
	}
}

void clientNumC(vector<cliente>&cl){
	if(cl.empty()){
		cout<<"ERROR: No hay clientes registrados"<<endl;
	}else{
		int num;
		int aux=0;
		cout<<"Ingrese el numero minimo de compras"<<endl;
		cin>>num;
map<string, pair<string, int>> comprasMap;
		for(int i=0;i<cl.size();i++){
			if(cl[i].getCom().size()>=num){
				aux=1;
	comprasMap[cl[i].getID()].first=cl[i].getN() +" "+ cl[i].getA() ;			
 comprasMap[cl[i].getID()].second=cl[i].getCom().size();
			}
		}
	cout<<"Clientes con "<<num<<" o mas compras:"<<endl;	
for(auto &p:comprasMap){
	cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"ID: "<<p.first<<endl;
cout<<"Compras realizadas: "<<p.second.second<<endl;
cout<<"==============="<<endl;
	}
	if(aux==0){
cout<<"No se encontraron clientes con ese numero de compras"<<endl;
	}
	}
}


void buscarMonto(vector<ventas>&vent, vector<cliente>&cl){
	if(vent.empty()){
cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		double monto;
		int aux=0;
		int aux2=0;
		cout<<"Ingrese el monto minimo gastado"<<endl;
		cin>>monto;
		map<string,double> gastoMap;		
		for(int i=0;i<vent.size();i++){
	gastoMap[vent[i].getCliente()]+=vent[i].getTotal();
		}
		cout<<"Clientes que han gastado "<<monto<<"$ o mas:"<<endl;
	for(int i=0;i<cl.size();i++){
		aux=0;
	string id=cl[i].getID();
	double gasto=0;
	for(auto &p:gastoMap){
		if(p.first==id){
			aux=1;
			gasto=p.second;
				}
			}
			if(aux==1&&gasto>=monto){
	cout<<"==============="<<endl;
	cout<<"Nombre: "<<cl[i].getN()<<" "<<cl[i].getA()<<endl;
	cout<<"ID: "<<id<<endl;
cout<<"Total gastado: "<<gasto<<"$"<<endl;
cout<<"==============="<<endl;
		aux2=1;
		}
		}
	if(aux2==0){
	cout<<"No se encontraron clientes con ese monto de compras"<<endl;
}
}
}


void totalGastado(vector<ventas>&vent, vector<cliente>&cl){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		string id;
		int aux=0;
		string nom;
		cout<<"Ingrese el ID del cliente"<<endl;
		cin>>id;
	for(int i=0;i<cl.size();i++){
		if(cl[i].getID()==id){
			aux=1;
			nom=cl[i].getN();
		}
		}
	if(aux==0){
	cout<<"Cliente no encontrado"<<endl;
		}else{
		map<string,double> gastoMap;
		for(int i=0;i<vent.size();i++){
gastoMap[vent[i].getCliente()]+=vent[i].getTotal();
			}
	double total=0;
	for(auto &p:gastoMap){
		if(p.first==id){
		total=p.second;
}
	}
	cout<<"==============="<<endl;
	cout<<"Nombre: "<<nom<<endl;	
	cout<<"ID: "<<id<<endl;
cout<<"Total gastado: "<<total<<"$"<<endl;
	cout<<"==============="<<endl;
}
	}
}


void costoInv(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		double total=0;
		for(int i=0;i<prod.size();i++){
			total+=prod[i].getCosto()*prod[i].getStock();
		}
		cout<<"==============="<<endl;
		cout<<"Costo total del inventario:"<<endl;
		cout<<total<<"$"<<endl;
		cout<<"==============="<<endl;
	}
}

void promVentCli(vector<ventas>&vent, vector<cliente>&cl){
	double prom, a, b;
	if(vent.empty()){
	cout<<"ERROR: No hay ventas registradas"<<endl;	
	}else{
		a=vent.size();
		b=cl.size();	
	prom=a/b;
	cout<<"Promedio de ventas por cliente: "<<prom<<" ventas"<<endl;
			}	
	}
	
void promCateg(vector<Producto>&prod, vector<string>&categ){
	if(prod.empty()){
cout<<"ERROR: No hay productos registrados"<<endl;
	}else{	
map<string,pair<double,int>> promCat;
	for(int j=0;j<prod.size();j++){
promCat[prod[j].getCategoria()].first+=prod[j].getPrecio();
promCat[prod[j].getCategoria()].second++;
		}
	cout<<"Promedio de precios por categoria:"<<endl;	
for(auto &p:promCat){
	cout<<"==============="<<endl;
	cout<<"Categoria: "<<p.first<<endl;
double promedio=p.second.first/p.second.second;
cout<<"Promedio: "<<promedio<<"$"<<endl;
	cout<<"==============="<<endl;
}
	}
}
	
	
	
void ganancia(vector<Producto>&prod){
if(prod.empty()){
	cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	double margenMin;
	int aux=0;
cout<<"Ingrese el margen de ganancia minimo"<<endl;
	cin>>margenMin;
 map<string, pair <string, double>> margenMap;
for(int i=0;i<prod.size();i++){
if(margenMin<=prod[i].getPrecio()-prod[i].getCosto()){	
margenMap[prod[i].getID()].first=prod[i].getNombre();
margenMap[prod[i].getID()].second=prod[i].getPrecio()-prod[i].getCosto();
}
		}
	cout<<"Productos con margen igual o superior a "<<margenMin<<"$:"<<endl;
	for(auto &p:margenMap){
cout<<"==============="<<endl;
cout<<"ID: "<<p.first<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"Margen de ganancia: "<<p.second.second<<"$"<<endl;
cout<<"==============="<<endl;
	aux=1;
	}
if(aux==0){
	cout<<"No se encontraron productos con ese margen de ganancia"<<endl;
		}			
	}
    }






// ============================================================
//  FUNCIONES JSON  —  guardar y cargar datos en archivos
// ============================================================

// ── Funciones auxiliares de parseo ───────────────────────────
// Estas funciones saben buscar un valor dentro de una línea JSON
// como: {"ID":"P01","nombre":"Laptop","precio":1200.5,"stock":5}

// Extrae el valor de tipo STRING de una clave dada
// Ejemplo: extraerStr(linea, "nombre") en {"nombre":"Laptop"} devuelve "Laptop"
string extraerStr(string obj, string clave){
    string buscar = "\"" + clave + "\":\""; // arma el patrón "clave":"  (con las comillas)
    int pos = obj.find(buscar);             // busca ese patrón dentro del objeto
    if(pos==string::npos) return "";        // si no lo encuentra devuelve vacío
    pos += buscar.size();                   // avanza la posición hasta el primer carácter del valor
    int fin = obj.find("\"", pos);          // busca la comilla de cierre del valor
    return obj.substr(pos, fin - pos);      // devuelve el texto entre las dos comillas
}

// Extrae el valor de tipo DOUBLE (número con decimales) de una clave dada
// Ejemplo: extraerDouble(linea, "precio") en {"precio":1200.5} devuelve 1200.5
double extraerDouble(string obj, string clave){
    string buscar = "\"" + clave + "\":";  // arma el patrón "clave":  (sin comilla de valor, es número)
    int pos = obj.find(buscar);
    if(pos==string::npos) return 0;
    pos += buscar.size();                   // avanza hasta el primer dígito del número
    int fin = obj.find_first_of(",}]", pos);// el número termina cuando encuentra , o } o ]
    return stod(obj.substr(pos, fin - pos));// stod convierte el texto "1200.5" al número 1200.5
}

// Extrae el valor de tipo INT de una clave dada
// Reutiliza extraerDouble y convierte el resultado a entero
int extraerInt(string obj, string clave){
    return (int)extraerDouble(obj, clave);  // (int) trunca la parte decimal
}

// Extrae el vector de IDs de compras de un cliente
// Formato en JSON: "compras":["V01","V02","V03"]
vector<string> extraerCompras(string linea){
    vector<string> res;
    string buscar = "\"compras\":[";
    int pos = linea.find(buscar);
    if(pos==string::npos) return res;       // si no hay compras devuelve vector vacío
    pos += buscar.size();                   // avanza hasta el primer elemento del array
    int fin = linea.find("]", pos);         // busca el cierre del array de compras
    if(fin==string::npos) return res;
    string arr = linea.substr(pos, fin-pos);// arr contiene: "V01","V02","V03"
    int i=0;
    while(i<(int)arr.size()){
        if(arr[i]=='"'){                    // cada ID empieza con comilla abre
            int inicio = i+1;
            int ffin = arr.find("\"", inicio);// busca la comilla cierre del ID
            if(ffin==string::npos) break;
            res.push_back(arr.substr(inicio, ffin-inicio));// guarda el ID
            i = ffin+2;                     // salta la comilla cierre y la coma que sigue
        }else{
            i++;
        }
    }
    return res;
}

// Extrae el vector de Productos que están dentro de una venta
// Formato en JSON: "productos":[{"ID":"P01","nombre":"Laptop",...},{...}]
vector<Producto> extraerProductos(string linea){
    vector<Producto> res;
    string buscar = "\"productos\":[";
    int pos = linea.find(buscar);
    if(pos==string::npos) return res;
    pos += buscar.size();                   // avanza hasta el primer { del primer producto
    int fin = linea.rfind("]");             // rfind busca el ÚLTIMO ] de la línea, que cierra el array
    if(fin==string::npos || fin<=pos) return res;
    string arr = linea.substr(pos, fin-pos);// arr contiene: {obj1},{obj2},...
    int i=0;
    while(i<(int)arr.size()){
        if(arr[i]=='{'){                    // inicio de un objeto producto
            int ffin = arr.find("}", i);   // busca el } de cierre de ese producto
            if(ffin==string::npos) break;
            string pobj = arr.substr(i, ffin-i+1);// extrae el objeto completo {ID:... stock:5}
            // construye el Producto directo con el constructor para no imprimir mensajes
            Producto p(
                extraerStr(pobj,"ID"),
                extraerStr(pobj,"nombre"),
                extraerStr(pobj,"categoria"),
                extraerDouble(pobj,"precio"),
                extraerDouble(pobj,"costo"),
                extraerInt(pobj,"stock")
            );
            res.push_back(p);
            i = ffin+1;                     // avanza después del } para buscar el siguiente
        }else{
            i++;
        }
    }
    return res;
}

// ── Funciones de GUARDADO ─────────────────────────────────────
// Cada función abre un archivo, escribe todos los datos en formato JSON y lo cierra.
// ofstream es el tipo de C++ para escribir archivos (output file stream)

void guardarProductos(vector<Producto>&prod){
    ofstream f("productos.json");           // crea o sobreescribe el archivo productos.json
    f << "[\n";                             // [ abre el array JSON, \n es salto de línea
    for(int i=0;i<(int)prod.size();i++){
        f << "{";                           // { abre el objeto JSON
        f << "\"ID\":\""        << prod[i].getID()        << "\",";
        f << "\"nombre\":\""    << prod[i].getNombre()    << "\",";
        f << "\"categoria\":\"" << prod[i].getCategoria() << "\",";
        f << "\"precio\":"      << prod[i].getPrecio()    << ",";// número sin comillas
        f << "\"costo\":"       << prod[i].getCosto()     << ",";
        f << "\"stock\":"       << prod[i].getStock();
        f << "}";                           // } cierra el objeto
        if(i<(int)prod.size()-1) f << ","; // coma entre objetos, NO en el último
        f << "\n";
    }
    f << "]";                               // ] cierra el array
    f.close();                              // cierra el archivo correctamente
    cout<<"Productos guardados"<<endl;
}

void guardarEmpleados(vector<empleado>&em){
    ofstream f("empleados.json");
    f << "[\n";
    for(int i=0;i<(int)em.size();i++){
        f << "{";
        f << "\"ID\":\""       << em[i].getID() << "\",";
        f << "\"nombre\":\""   << em[i].getN()  << "\",";
        f << "\"apellido\":\"" << em[i].getA()  << "\",";
        f << "\"telefono\":\"" << em[i].getP()  << "\",";
        f << "\"cargo\":\""    << em[i].getC()  << "\",";
        f << "\"salario\":"    << em[i].getS();  // salario es int, sin comillas
        f << "}";
        if(i<(int)em.size()-1) f << ",";
        f << "\n";
    }
    f << "]";
    f.close();
    cout<<"Empleados guardados"<<endl;
}

void guardarClientes(vector<cliente>&cl){
    ofstream f("clientes.json");
    f << "[\n";
    for(int i=0;i<(int)cl.size();i++){
        f << "{";
        f << "\"ID\":\""       << cl[i].getID()  << "\",";
        f << "\"nombre\":\""   << cl[i].getN()   << "\",";
        f << "\"apellido\":\"" << cl[i].getA()   << "\",";
        f << "\"telefono\":\"" << cl[i].getP()   << "\",";
        f << "\"correo\":\""   << cl[i].getCor() << "\",";
        f << "\"compras\":[";               // array de IDs de compras
        vector<string> coms = cl[i].getCom();
        for(int j=0;j<(int)coms.size();j++){
            f << "\"" << coms[j] << "\"";  // cada ID va entre comillas
            if(j<(int)coms.size()-1) f << ",";
        }
        f << "]";                           // cierra el array de compras
        f << "}";
        if(i<(int)cl.size()-1) f << ",";
        f << "\n";
    }
    f << "]";
    f.close();
    cout<<"Clientes guardados"<<endl;
}

void guardarVentas(vector<ventas>&vent){
    ofstream f("ventas.json");
    f << "[\n";
    for(int i=0;i<(int)vent.size();i++){
        f << "{";
        f << "\"ID\":\""      << vent[i].getID()      << "\",";
        f << "\"cliente\":\"" << vent[i].getCliente() << "\",";
        f << "\"dia\":"       << vent[i].getDia()      << ",";// números sin comillas
        f << "\"mes\":"       << vent[i].getMes()      << ",";
        f << "\"year\":"      << vent[i].getYear()     << ",";
        f << "\"total\":"     << vent[i].getTotal()    << ",";
        f << "\"productos\":[";             // array de productos de esta venta
        vector<Producto> prods = vent[i].getProd();
        for(int j=0;j<(int)prods.size();j++){
            f << "{";
            f << "\"ID\":\""        << prods[j].getID()        << "\",";
            f << "\"nombre\":\""    << prods[j].getNombre()    << "\",";
            f << "\"categoria\":\"" << prods[j].getCategoria() << "\",";
            f << "\"precio\":"      << prods[j].getPrecio()    << ",";
            f << "\"costo\":"       << prods[j].getCosto()     << ",";
            f << "\"stock\":"       << prods[j].getStock();
            f << "}";
            if(j<(int)prods.size()-1) f << ",";
        }
        f << "]";                           // cierra el array de productos
        f << "}";
        if(i<(int)vent.size()-1) f << ",";
        f << "\n";
    }
    f << "]";
    f.close();
    cout<<"Ventas guardadas"<<endl;
}

// ── Funciones de CARGA ────────────────────────────────────────
// Cada función abre el archivo, lee línea por línea y reconstruye los vectores.
// ifstream es el tipo de C++ para leer archivos (input file stream)
// getline(f, linea) lee una línea completa incluyendo espacios

void cargarProductos(vector<Producto>&prod, vector<string>&categ){
    ifstream f("productos.json");           // intenta abrir el archivo
    if(!f) return;                          // si no existe (primera ejecución) no hace nada
    string linea;
    while(getline(f, linea)){               // lee el archivo línea por línea
        if(linea.find("{")==string::npos) continue;// salta las líneas [ ] que no son objetos
        if(!linea.empty()&&linea.back()==',') linea.pop_back();// quita la , del final si existe
        string id     = extraerStr(linea,"ID");
        string nom    = extraerStr(linea,"nombre");
        string cat    = extraerStr(linea,"categoria");
        double precio = extraerDouble(linea,"precio");
        double costo  = extraerDouble(linea,"costo");
        int stock     = extraerInt(linea,"stock");
        Producto p(id,nom,cat,precio,costo,stock);// usa el constructor, no los setters (no imprime)
        prod.push_back(p);
        int y=1;                            // también reconstruye el vector de categorías
        for(int i=0;i<(int)categ.size();i++){
            if(categ[i]==cat) y=0;
        }
        if(y==1) categ.push_back(cat);
    }
    f.close();
    cout<<"Productos cargados: "<<prod.size()<<endl;
}

void cargarEmpleados(vector<empleado>&em){
    ifstream f("empleados.json");
    if(!f) return;
    string linea;
    while(getline(f,linea)){
        if(linea.find("{")==string::npos) continue;
        if(!linea.empty()&&linea.back()==',') linea.pop_back();
        string id  = extraerStr(linea,"ID");
        string nom = extraerStr(linea,"nombre");
        string ap  = extraerStr(linea,"apellido");
        string tel = extraerStr(linea,"telefono");
        string car = extraerStr(linea,"cargo");
        int sal    = extraerInt(linea,"salario");
        empleado e(nom,ap,id,tel,car,sal);  // constructor: (nombre, apellido, id, tel, cargo, salario)
        em.push_back(e);
    }
    f.close();
    cout<<"Empleados cargados: "<<em.size()<<endl;
}

void cargarClientes(vector<cliente>&cl){
    ifstream f("clientes.json");
    if(!f) return;
    string linea;
    while(getline(f,linea)){
        if(linea.find("{")==string::npos) continue;
        if(!linea.empty()&&linea.back()==',') linea.pop_back();
        string id  = extraerStr(linea,"ID");
        string nom = extraerStr(linea,"nombre");
        string ap  = extraerStr(linea,"apellido");
        string tel = extraerStr(linea,"telefono");
        string cor = extraerStr(linea,"correo");
        cliente c(nom,ap,id,tel,cor);       // crea el cliente sin historial
        vector<string> coms = extraerCompras(linea);// extrae el array de compras
        for(int i=0;i<(int)coms.size();i++){
            c.addCom(coms[i]);              // restaura cada ID de compra en el historial
        }
        cl.push_back(c);
    }
    f.close();
    cout<<"Clientes cargados: "<<cl.size()<<endl;
}

void cargarVentas(vector<ventas>&vent){
    ifstream f("ventas.json");
    if(!f) return;
    string linea;
    while(getline(f,linea)){
        if(linea.find("{")==string::npos) continue;
        if(!linea.empty()&&linea.back()==',') linea.pop_back();
        string id  = extraerStr(linea,"ID");
        string cli = extraerStr(linea,"cliente");
        int dia    = extraerInt(linea,"dia");
        int mes    = extraerInt(linea,"mes");
        int year   = extraerInt(linea,"year");
        double tot = extraerDouble(linea,"total");
        vector<Producto> prods = extraerProductos(linea);// extrae los productos del array
        ventas v(id,cli,prods,tot,dia,mes,year);
        vent.push_back(v);
    }
    f.close();
    cout<<"Ventas cargadas: "<<vent.size()<<endl;
}

int main(){
char op;
vector <empleado> empleados;
vector <Producto> productos;
vector <cliente> clientes;
vector <ventas> ventas;
vector<string> categorias;

// Al iniciar el programa carga los datos guardados de la sesión anterior
// Si los archivos no existen (primera ejecución) estas funciones simplemente no hacen nada
cargarProductos(productos, categorias);
cargarEmpleados(empleados);
cargarClientes(clientes);
cargarVentas(ventas);
    
do{
  cout<<"MENU"<<endl;
  cout<<"Seleccione el numero de la opcion deseada"<<endl;
  cout<<"1- Gestion de productos"<<endl;
  cout<<"2- Gestion de empleados"<<endl;
  cout<<"3- Gestion de clientes"<<endl;
  cout<<"4- Gestion de ventas"<<endl;
  cout<<"5- Estadisticas"<<endl;
  cout<<"0- Salir"<<endl;
  cin>>op;
  switch (op){
   case '1': {  
   char opProd;
    do{
     cout<<"1- Agregar producto"<<endl;
     cout<<"2- Eliminar producto"<<endl;
     cout<<"3- Modificar producto"<<endl;
     cout<<"4- Actualizar stock"<<endl;
     cout<<"5- Productos de stock critico"<<endl;
     cout<<"6- Productos de mayor y menor precio"<<endl;
      cout<<"7- Buscar producto por nombre"<<endl;
      cout<<"8- Buscar producto por precio"<<endl;
      cout<<"9- Buscar producto por categoria"<<endl;
      cout<<"0- Atras"<<endl;
      cin>>opProd;
   switch(opProd){
    case '1':
       addProd(productos, categorias);
       break;
     case '2':
    eliminarProd(productos);
      break;
    case '3':
   modificarProd(productos, categorias);
     break;
    case '4':
    upgStock(productos);
     break;
     case '5':
     stockcritico(productos);
      break;
    case '6':
    caro_barato(productos);
    break;
    case '7':
     buscarName(productos);
      break;
  case '8':
    rangoP(productos);
      break;
    case '9':
    buscarCateg(productos);
    break;
   case '0':
    break;
   default:
    cout<<"Opcion invalida"<<endl;
       }
    }while(opProd!='0');
        break;
    }  
            
  case '2': { 
    char opEmp;
   do{
    cout<<"1- Agregar empleado"<<endl;
   cout<<"2- Eliminar empleado"<<endl;
  cout<<"3- Modificar empleado"<<endl;      
  cout<<"4- Consultar empleado"<<endl;
 cout<<"5- Promedio salarios"<<endl;
    cout<<"6- Mayor salario"<<endl;
    cout<<"7- Conteo por cargo"<<endl;
    cout<<"0- Atras"<<endl;
       cin>>opEmp;
                    
     switch(opEmp){
      case '1':
         addEmp(empleados);
       break;
      case '2':
      eliminarEmp(empleados);
        break;
       case '3':
        modificarEmp(empleados);
        break;
       case '4':
      consultarEmp(empleados);        
      break;
      case '5':
       promedioEmp(empleados);
           break;
          case '6':
         mayorEmp(empleados);
       break;
       case '7':
       conteoEmp(empleados);
            break;
     case '0':
        break;
       default:
     cout<<"Opcion invalida"<<endl;
         }
      }while(opEmp!='0');
      break;
     }  
            
   case '3': {  
      char opCli;
      do{
         cout<<"1- Agregar cliente"<<endl;
         cout<<"2- Eliminar cliente"<<endl;
         cout<<"3- Modificar cliente"<<endl;
       cout<<"4- Consultar historial"<<endl;
       cout<<"5- Total gastado por cliente"<<endl;
cout<<"6- Buscar clientes por numero de compras"<<endl;
cout<<"7- Buscar clientes por total gastado"<<endl;
       cout<<"0- Atras"<<endl;
          cin>>opCli;           
         switch(opCli){
          case '1':
           addCli(clientes);
            break;
         case '2':
           eliminarCli(clientes);
          break;
       case '3':
         modificarCli(clientes);
         break;
        case '4':
       consultarHist(clientes);
         break;
         case '5':
         totalGastado(ventas, clientes);
         break;
         case '6':
         clientNumC(clientes);
         break;
         case '7':
         buscarMonto(ventas, clientes);
         break;
      case '0':
       break;
       default:
       cout<<"Opcion invalida"<<endl;
       }
   }while(opCli!='0');
    break;
    }  
            
 case '4': {
     char opVen;
      do{
      cout<<"1- Agregar venta"<<endl;
      cout<<"2- Eliminar venta"<<endl;
      cout<<"3- Buscar por cliente"<<endl;
      cout<<"4- Buscar por fecha"<<endl;
      cout<<"5- Total por categorias"<<endl;
   cout<<"6- Productos mas vendidos"<<endl;
cout<<"7- Clientes que mas compran"<<endl;
         cout<<"0- Atras"<<endl;
         cin>>opVen;
             
       switch(opVen){
      case '1':
       addVen(ventas, clientes, productos);
              break;
       case '2':
     eliminarVen(ventas, clientes, productos);
               break;
           case '3':
        sbCliente(ventas, clientes);
             break;
          case '4':
        rangoFecha(ventas);           
        break;
        case '5':
       totalCat(ventas, categorias);
        break;
        case '6':
        masVendido(ventas);
        break;
        case '7':
        clienteMas(clientes, ventas);
        break;
        case '0':
          break;
       default:
      cout<<"Opcion invalida"<<endl;
        }
      }while(opVen!='0');
      break;
         }
            
     case '5': {
       char opE;
       do{
  cout<<"1- Costo total de inventario"<<endl;
  cout<<"2- Promedio de ventas por clientes"<<endl;
  cout<<"3- Promedio de precios por categoria"<<endl;
  cout<<"4- Buscar producto segun margen de ganancia"<<endl;
  cout<<"0- Atras"<<endl;
  cin>>opE;
  switch(opE){         
          case '1':
          costoInv(productos);
            break;
            case '2':
            promVentCli(ventas, clientes);
              break;
              case '3':
              promCateg(productos, categorias);
                break;
                case '4':
                ganancia(productos);
                  break;
                  case '0':
                 break;
                 default:
                 cout<<"Opcion invalida"<<endl;
                 break;
            
  }
       }while(opE!='0');
            break;
          }
            
       case '0':
      // Al salir guarda todos los datos en los archivos JSON
      guardarProductos(productos);
      guardarEmpleados(empleados);
      guardarClientes(clientes);
      guardarVentas(ventas);
      cout<<"Saliendo..."<<endl;
       break;
                
   default:
        cout<<"Opcion invalida"<<endl;
       }
    }while(op!='0');
    
    return 0;
}