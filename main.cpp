#include <iostream>
#include <vector>
using namespace std;

class Matriz_Especial{
private:
    vector<int> minimuns;
    int **matriz;
    int n;
    int m;
public:
    Matriz_Especial(int **matriz_, int n_, int m_){
        this->matriz = matriz_;
        this->n = n_;
        this->m = m_;
        this->minimuns.resize(n_);
    }

    int searchMinorValue(int** ma, int fila, int start, int end){
        int pos = start;
        int initial = ma[fila][start];
        for(int i = start; i < end; i++){
            if (ma[fila][i] < initial){
                initial = ma[fila][i];
                pos = i;
            }
        }
        this->minimuns[fila] = pos + 1;
        return pos;
    }

    void binaryMatrix(int** ma,int start_n,int end_n, int start_m, int end_m){
        if (start_n < end_n){
            int middle_n = start_n + (end_n - start_n)/2;
            int pos = searchMinorValue(ma, middle_n, start_m, end_m);
            binaryMatrix(ma, start_n, middle_n, start_m, pos + 1);
            binaryMatrix(ma, middle_n + 1, end_n, pos, end_m);
        }
    }

    void displayVector(){
        for(int minimun : this->minimuns){
            cout << minimun << " ";
        }
    }

};

int** crear_matriz(int n, int m){
    int** matriz_especial = new int*[n];
    for(int i=0; i<n; i++)
        matriz_especial[i] = new int[m];
    return matriz_especial;
}

void ingresar_matriz(int** ma,int n,int m){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>ma[i][j];
}

int main(){
    int n, m;
    cin >> n >> m;

    while(n < 1 && m > 1000){
        cin >> n >> m;
    }

    int **matriz_especial = crear_matriz(n, m);

    ingresar_matriz(matriz_especial, n, m);

    auto matriz = new Matriz_Especial(matriz_especial, n, m);

    matriz->binaryMatrix(matriz_especial, 0, n, 0 , m);

    matriz->displayVector();

    return 0;   
}