// CifradoPlayfair.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<conio.h>
#include<stdio.h>>
#include<iostream>
#include<string.h>
#include<windows.h>
#include<Math.h>

using namespace std;
char alf[] = {'a','b','c','d','e',
			  'f','g','h','i','j',
			  'k','l','m','n','o',
			  'p','q','r','s','t',
			  'u','v','w','x','y','z'};
//Agregar la ñ y letras acentuadas
//Clave se permite cualquier caracter, espacios, todo en mayúscula o en minúsculas. caracteres especiales
int esta_matriz (char letra, char matriz[5][5]){
    for(int i = 0; i < 5; i++){
       for(int j = 0; j < 5; j++){
            if(letra == matriz[i][j]){
                return 1;
            }
       }
    }
    return -1;
}

void llenar_matriz(char clave[], char matriz[5][5]){
    int fila = 0;
    int columna = 0;
    int aux;
    for(int i = 0; i < strlen(clave); i++){
         aux = esta_matriz(clave[i], matriz);
        if(aux == -1 && clave[i] != 106){
            if(columna == 5){
                fila++;
                columna = 0;
            }
		    matriz[fila][columna] = clave[i];
		    columna++;
        }            
    }
    for(int j = 0; j < strlen(alf); j++){
        aux = esta_matriz(alf[j], matriz); 
        if(aux == -1 && alf[j] != 106){
            if(columna == 5){
                fila++;
                columna = 0;
            }
		    matriz[fila][columna] = alf[j];
		    columna++;
         }   
    } 
}

void acomodar_mensaje (char m2[], char m[]){
	int j = 0;
	for(int i = 0; i < strlen(m); i++){		
		if(m[i] != 32){
		   m2[j] = m[i];
		   j++;
		}
	}
	m2[j] = '\0';
	//cout<<m2<<endl;
		
	int i = 0;
	j = 1;
	while(j <= strlen(m2)){
		if(m2[i] == m2[j]){
			for(int k = strlen(m2)+1; k > j; k--){
				m2[k] = m2[k-1];
			}
			m2[j] = 'x';
		}
		i = i+2;
		j = j+2;
	}
	
	if(strlen(m2)%2 != 0){
		m2[strlen(m2)+1] = '\0';
		m2[strlen(m2)] = 'x';		
	}
	//cout<<m2<<endl;
	//cout<<strlen(m2)<<endl;
}


void cifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i = 0; i < 5; i++)
	 for(int j = 0; j < 5; j++)
	   matriz[i][j] = '\0';
	
	llenar_matriz(clave, matriz);
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout<<matriz[i][j];
			if(j == 4){
				cout<<endl;
			}
		}
	}
	
	fflush(stdin);
	char m2[100];
	acomodar_mensaje(m2, m);
		
	int i = 0;
	int j = 1;
	while(j <= strlen(m2)){	
		int fila1, fila2, columna1, columna2;
		if(m2[i] == 'j'){
			m2[i] = 'i';
		}
		if(m2[j] == 'j'){
			m2[j] = 'i';
		}
		for(int x = 0; x < 5; x++){
			for(int y = 0; y < 5; y++){
				if(m2[i] == matriz[x][y]){
					fila1 = x;
					columna1 = y;
				}
				if(m2[j] == matriz[x][y]){
					fila2 = x;
					columna2 = y;
				}
			}
		}
		if(fila1 == fila2){
			m2[i] = matriz[fila1][(columna1+1)%5];
			m2[j] = matriz[fila1][(columna2+1)%5];
		}
		else if(columna1 == columna2){
			m2[i] = matriz[(fila1+1)%5][columna1];
			m2[j] = matriz[(fila2+1)%5][columna1];
		}
		else{
			m2[i] = matriz[fila1][columna2];
			m2[j] = matriz[fila2][columna1];
		}
		i = i+2;
		j = j+2;
	}
	cout<<"El mensaje cifrado es:";
	for(int i = 0; i < strlen(m2); i++){
		cout<<m2[i];
		if(i%2 != 0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
}

void descifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i=0;i<5;i++)
	 	for(int j=0;j<5;j++)
	   		matriz[i][j]='\0';
	
	llenar_matriz(clave, matriz);
	
	fflush(stdin);
	char m2[100];
	
	int p = 0;
	for(int q = 0; q < strlen(m); q++){		
		if(m[q] != 32){
		   m2[p] = m[q];
		   p++;
		}
	}
	m2[p] = '\0';
	
	int i = 0;
	int j = 1;
	while(j <= strlen(m2)){	
		int fila1, fila2, columna1, columna2;
		/*if(m2[i] == 'j'){
			m2[i] = 'i';
		}*/
		if(m2[j] == 'j'){
			m2[j] = 'i';
		}
		for(int x = 0; x < 5; x++){
			for(int y = 0; y < 5; y++){
				if(m2[i] == matriz[x][y]){
					fila1 = x;
					columna1 = y;
				}
				if(m2[j] == matriz[x][y]){
					fila2 = x;
					columna2 = y;
				}
			}
		}
		if(fila1 == fila2){
			if((columna1-1) < 0){
				m2[i] = matriz[fila1][4];
			}
			else{
				m2[i] = matriz[fila1][columna1-1];
			}
			if((columna2-1) < 0){
				m2[j] = matriz[fila1][4];
			}
			else{
				m2[j] = matriz[fila1][columna2-1];
			}		
		}
		else if(columna1 == columna2){
			if((fila1-1) < 0){
				m2[i] = matriz[4][columna1];
			}
			else{
				m2[i] = matriz[fila1-1][columna1];	
			}
			if((fila2-1) < 0){
				m2[j] = matriz[4][columna2];
			}
			else{
				m2[j] = matriz[fila2-1][columna2];	
			}
		}
		else{
			m2[i] = matriz[fila1][columna2];
			m2[j] = matriz[fila2][columna1];
		}
		i = i+2;
		j = j+2;
	}
	cout<<"El mensaje descifrado es:";
	for(int i = 0; i < strlen(m2); i++){
		cout<<m2[i];
		if(i%2 != 0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
}


void main(){
	int opc2;
	do{
		cout<<"Cifrado Playfair:"<<endl;
		//system("cls");
		cout<<"Menu"<<endl;
		cout<<"1.- Cifrar"<<endl;
		cout<<"2.- Descrifrar"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Ingrese Opcion:";
		cin>>opc2;
			switch(opc2){
				case 1: cifrado_playfair(); 
					break;
				case 2: descifrado_playfair(); 
					break;
			}
		//system("cls");
	}while(opc2 != 3);
	_getch();
	//return 0;
}

