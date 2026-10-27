#include <iostream>
#include <vector>

using namespace std;
template <typename T>

int BusquedaBinaria(const vector<T>& X,T x, int ini, int fin){
if (ini > fin)
	return -1;

int m = (ini+fin)/2; //la pos media

if(X[m] == x)
	return m;

else if(X[m] < x)
	return BusquedaBinaria(X,x,m+1,fin); // m+1 y m-1 es para descartar el m ya sabemos que no es el valor que buscamos

return BusquedaBinaria(X,x,ini,m-1);
}


/*template <typename T>
int particion(vector<T>& v, int ini, int fin){
T aux;
int pos = fin; // posición del pivote
for(int i=fin-1; i >= ini; i--){

if(v[pos] < v[i]){
aux = v[i];
for(int j=i+1; j <= fin ;j++){
v[j-1]=v[j];
}
v[fin] = aux;
pos--;
}

}
return pos;

}*/ //esta versión es propia antes de buscar como se implementa la función de la mejor manera


template <typename T>
int particion(vector<T>& v, int ini, int fin){
int i=ini;
T pivote = v[fin];
T aux;
for(int j=ini; j < fin; j++){
if(pivote >= v[j]){
aux=v[i];
v[i]=v[j]
v[j]=aux;
i++}

}
aux = v[i];
v[i] = v[fin];
v[fin]=aux;

return i;

}



template <typename T>
void quickSort(vector<T>& v, int ini, int fin){
if(ini >= fin)
	return;

int pos = particion(v,ini,fin);

quickSort(v,ini,pos-1);
quickSort(v,pos+1,fin);
}

