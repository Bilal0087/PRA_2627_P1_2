#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
if(a <= b)
return a;

return b;
}



int cambio(vector<int> monedas, int m){

int tam = monedas.size();
vector<vector<int>> T(tam, vector<int>(m+1,-1));  //definimos la matriz

int i=0;   //índice del vector de monedas
T[i][0]=0;

for(int j = 1; j < m+1; j++){
if(j >= monedas[i] && T[i][j-monedas[i]] != -1 )   //aseguramos que tenemos información sobre el valor j-monedas[i] porque vamos a usarla
       T[i][j]=1+T[i][j-monedas[i]];

}


for (int i = 1; i < tam; i++) {
    T[i][0] = 0;						//rellenar el resto de la columna j=0 con los ceros

    for (int j = 1; j <= m; j++) {

        if (j < monedas[i] || T[i][j-monedas[i]] == -1) {        // si la moneda es más grande que el valor copiamos la casilla de la fila anterior
            T[i][j] = T[i-1][j];
        }
        else if (T[i-1][j] != -1) {				//  puedo usar la moneda y la casilla en la fila anterior no está vacía
            T[i][j] = min(T[i-1][j], 1 + T[i][j-monedas[i]]);   //elijo el minimo de monedas entre , nº de monedas en la fila anterior sin la moneda nueva o uso la moneda nueva y
        }							// sumo el nº de monedas necesarias para devolver lo que queda tras restar el valor de l aneuva moneda
        else {
            T[i][j] = 1 + T[i][j-monedas[i]];			// no te queda remedio que usar la moneda y sumar el nº de monedas que hace falta para devolver el resto de valor que queda
								// tras restar su valor (la nueva moneda) porque el nº de monedas que se usa sin usar esta moneda no la tienes es igual a -1
        }
    }
}

vector<int> sol(tam, 0);

int i = tam - 1;
int j = m;

while (j > 0) {

    if (i > 0 && T[i][j] == T[i-1][j]) {
        i--;
    }
    else {
        sol[i]++;
        j = j - monedas[i];
    }
}


}



int mochila(vector<int> p, vector<int> b, int m, vector<int>& s) {

    int tam = p.size();

    // Creamos la matriz y la inicializamos a 0
    vector<vector<int>> T(tam + 1, vector<int>(m + 1, 0));

    // Rellenamos la matriz
    for (int i = 1; i <= tam; i++) {
        for (int j = 1; j <= m; j++) {

            // Si el objeto pesa demasiado, no lo podemos meter
            if (p[i-1] > j) {
                T[i][j] = T[i-1][j];
            }
            else {
                // Beneficio sin coger el objeto
                int sin = T[i-1][j];

                // Beneficio cogiendo el objeto
                int con = b[i-1] + T[i-1][j-p[i-1]];

                // Nos quedamos con el mayor beneficio
                if (con > sin)
                    T[i][j] = con;
                else
                    T[i][j] = sin;
            }
        }
    }

    // Recuperamos los objetos elegidos
    s.assign(tam, 0);

    int j = m;

    for (int i = tam; i > 0; i--) {

        // Si el beneficio cambia respecto a la fila anterior,
        // significa que hemos cogido este objeto
        if (T[i][j] != T[i-1][j]) {
            s[i-1] = 1;
            j = j - p[i-1];
        }
    }

    return T[tam][m];
}

