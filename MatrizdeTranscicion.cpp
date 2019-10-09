//Crear una funcion que determine las coordenadas de un vector v en una base B de Rn
//Crear una funcion para construir la matriz de cambio de base en Rn

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void crear_matriz(float M[][10], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<<"Ingrese los vectores de la base: ";
            cin>>M[i][j];
        }
    }
}

 void mostrar_matriz(float M[][10], int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<<setw(5)<<M[i][j]<<setw(3);
        }

        cout<<endl;
    }
 }

 void crear_vector(float v[], int n){
    for(int i=0;i<n;i++){
        cout<<"Ingrese los elementos del vector: ";
        cin>>v[i];
    }
 }

 void mostrar_vector(float v[], int n){
    for(int i=0;i<n;i++){
        cout<<setw(3)<<v[i];
    }
 }

 void gauss_jordan(float M[10][10],int n){
    float may;//variable para almacenar el mayor de la columna k
    int ind;//indice del mayor-->indice de may
    float aux;
    float pivote;

    for(int k=0;k<n;k++){//recorrer columnas de la matriz reducida
        may=abs(M[k][k]);
        ind=k;
        //recorrer filas de la columna k para buscar el indice del mayor
        for(int l=k+1;l<n;l++){
            if(may<abs(M[l][k])){
                may=abs(M[l][k]);
                ind=l;
            }

        }

        //cambiar filas
        if(k!=ind){
            for(int i=0;i<n+1;i++){
                aux=M[k][i];
                M[k][i]=M[ind][i];
                M[ind][i]=aux;
            }

        }
        if(M[k][k]==0){
            cout<<"no tiene solucion";
            break;
        }
        else{

            for(int i=0;i<n;i++){//recorrer fila
                if(i!=k){
                    pivote=-M[i][k];
                    for(int j=k;j<n+1;j++){//recorrer elementos de una fila

                        M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k];
                    }
                }
                else{
                    pivote=M[k][k];
                    for(int j=k;j<n+1;j++){
                        M[i][j]=M[i][j]/pivote;
                    }
                }
            }
        }


}
}

void base_vector(float M[][10], int n, int c)
{
    float v[10];
    gauss_jordan(M,n);
    for(int i=0;i<n;i++){
        v[i]=M[i][c-1];
    }
    cout<<"Vector de la base: ";
    mostrar_vector(v,n);

}

void matriz_transicion(float M[][10], float N[][10], int f, int c)
{
    float R[10][10];
    float C[10][10];



    for(int i=0;i<f;i++){
            for(int i=0;i<f;i++)
            {
                for(int j=0;j<c;j++){
                    C[i][j]=M[i][j];
                }
            }
        for(int j=0;j<f;j++){
            M[j][c]=N[j][i];
            C[j][c]=N[j][i];
        }
        gauss_jordan(C,f);
        for(int k=0;k<f;k++){
            R[k][i]=C[k][c];
        }
    }

    mostrar_matriz(R,f,c);
}



 int main(){

    int f,c,n;
    float M[10][10];
    float N[10][10];
     cout<<"Opcion 1: Matriz escalonada reducida por filas...."<<endl;
     cout<<"Opcion 2: Coordenadas de vector 'x' en la base 'b'....."<<endl;
     cout<<"Opcion 3: Matriz de transición de 2 vectores: "<<endl;
     int opcion;
     cout<<"Ingrese la opcion elegida: ";
     cin>>opcion;
     switch(opcion)
     {
     case 1:
         cout<<"numero de ecuaciones: ";
         cin>>f;
         cout<<"numero de elementos: ";
         cin>>c;
         crear_matriz(M,f,c);
         mostrar_matriz(M,f,c);
         gauss_jordan(M,f);
         cout<<endl;
         cout<<"MATRIZ SOLUCION"<<endl;
         mostrar_matriz(M,f,c);
         break;
     case 2:
         cout<<"numero de ecuaciones: ";
         cin>>f;
         cout<<"numero de elementos: ";
         cin>>c;
         crear_matriz(M,f,c);
         mostrar_matriz(M,f,c);
         cout<<"COORDENADAS DEL VECTOR CON RESPECTO A LA BASE: ";
         base_vector(M,f,c);
         break;
     case 3:
          cout<<"numero de ecuaciones: ";
          cin>>f;
          cout<<"numero de elementos: ";
          cin>>c;
          crear_matriz(M,f,c);
          mostrar_matriz(M,f,c);
          cout<<endl;
          crear_matriz(N,f,c);
          mostrar_matriz(N,f,c);
          cout<<endl;
          cout<<"MATRIZ DE TRANSICION: "<<endl;
          matriz_transicion(M,N,f,c);
     }
 }
