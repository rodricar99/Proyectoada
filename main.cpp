#include "librerias.h"

void imprimirMatriz(int** ma,int n,int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cout<<ma[i][j]<<" ";
    cout<<endl;
  }
}

void crear_matriz(int** ma,int n,int m){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>ma[i][j]; 
}


int main(){
    int n,m;
    cout << "Ingrese el número de filas: ";
    cin >> n;
    cout << "Ingrese el número de columnas: ";
    cin >> m;

    while(n <1 && m >1000){
        cout << "Ingrese el número de filas: ";
        cin >> n;
        cout << "Ingrese el número de columnas: ";
        cin >> m;
    }

    int** matriz_especial = new int*[n];
    for(int i=0; i<n; i++)
         matriz_especial[i] = new int[m];
    crear_matriz(matriz_especial,n,m);

    int minimo = matriz_especial[0][0];

    vector<int>array_de_min;
    int indice;
    for(int i=0;i<m;i++){
          for(int j=0; j<m;j++){
            if(minimo>= matriz_especial[0][j]){
                minimo=matriz_especial[0][j];
                indice=i;
        }
    }
    array_de_min.push_back(indice);
    }

    return 0;   
}