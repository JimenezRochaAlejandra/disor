#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

// variables globales
string mensaje="alejandra";
string xor="";
char clave[4];
int  potenciasDeDos[8] = {128,64,32,16,8,4,2,1};
string claveEnBinario[4];
string mensajeEncriptado;
string letraCifradaEnBinario = "";
string cadenaCifrada="";
string claveBinariaFinal="";


void GenerarClaveAleatoria(){
	srand(time(NULL));
	clave[0] = 97 + rand() % (123-97);
	clave[1] = 97 + rand() % (123-97);
	clave[2] = 97 + rand() % (123-97);
	clave[3] = 97 + rand() % (123-97);
	printf("\nClave: ");
	printf("%c%c%c%c", clave[0], clave[1], clave[2], clave[3],"\n");
}


void convertirClave(char n[4], string claves[4], int posicion) {
	if (posicion < 4){
		for (int i = 7; i >= 0; i--) {
			if (n[posicion] & (1 << i))
				claveEnBinario[posicion] = claveEnBinario[posicion] + '1';
			else
				claveEnBinario[posicion] = claveEnBinario[posicion] + '0';
		}
		posicion++;
		return convertirClave(n,claves,posicion);
	}
	return;
}

//Convierte letra a letra del mensaje a su código en biario/
string convertirMensajeABinario(char n) {
	string letraEnBinario="";

	for (int i = 7; i >= 0; i--){
		if (n & (1 << i))
			letraEnBinario += '1';
		else
			letraEnBinario += '0';
	}

	return letraEnBinario;
}

//Cifrar/
void cifrar(string letraParaCifrar, string letraClave, int indice){
	//Comparación de ambas letras a nivel de bits:/
	if (indice < 8){
		(letraParaCifrar[indice] == letraClave[indice] ? letraCifradaEnBinario += '0' : letraCifradaEnBinario += '1');
		indice++;
		return cifrar(letraParaCifrar,letraClave,indice);
	}
	return;
}

int binarioDecimal(string LetraCodificada, int NumeroIteracion, int valorDecimal){
	if (NumeroIteracion <8 )	{
		if( (int)LetraCodificada[NumeroIteracion]-48==1) 
			valorDecimal+=potenciasDeDos[NumeroIteracion];

		NumeroIteracion++;
		return binarioDecimal(LetraCodificada,NumeroIteracion,valorDecimal);
	}
	return valorDecimal;

}

void CifradoVernam(){
	int j = 0;
	for (int i = 0; i < mensaje.length(); i++){
		char letraACifrar = mensaje[i];

		if (letraACifrar != ' ' && letraACifrar != '.' && letraACifrar != '!' && letraACifrar != '\n' && letraACifrar != '-' && letraACifrar != ':'	&& letraACifrar != '_' && letraACifrar != '/')	{
			string letraBinaria = convertirMensajeABinario(letraACifrar);
			string claveBinario = claveEnBinario[j];

			cifrar(letraBinaria, claveBinario,0);
			int valorletraCifrada = binarioDecimal(letraCifradaEnBinario, 3, 0);

			if (valorletraCifrada < 97){ 
				valorletraCifrada = valorletraCifrada;
			}

			//std::string invertida(letraCifradaEnBinario.rbegin(), letraCifradaEnBinario.rend());
			
			cadenaCifrada+=letraCifradaEnBinario;
			claveBinariaFinal+=claveBinario;
			

			mensajeEncriptado += /*(char)*/valorletraCifrada;
			letraCifradaEnBinario = "";
			j++;

			if (j > 3)
				j = 0;
		}
		else
			mensajeEncriptado += letraACifrar;
	}
	//cout << "\nMensaje Cifrado:" << cadenaCifrada<<endl;
		//cout << "\nMensaje Cifrado:" << claveBinariaFinal<<endl;

}
void separaOctetos(){
	string octetos[20];	string cad=""; 
	for(int i=0;i<xor.length();i++){
		cad+=xor[i];
		if((i+1)%8==0){
		 int valor= binarioDecimal(cad,0,0);
			cout << "\nvalor:" <<(char) valor<<endl;
			cad="";
		}
	}
}

void descifrado(){
	for (int i = 0; i < cadenaCifrada.length(); i++){
		if(cadenaCifrada[i]==claveBinariaFinal[i])
			xor+='0';
		else
			xor+='1';
	}
	separaOctetos();
}



int main() {	
	GenerarClaveAleatoria();
	convertirClave(clave, claveEnBinario, 0);
	CifradoVernam();
	descifrado();

	system("pause");
	return 0;
}
