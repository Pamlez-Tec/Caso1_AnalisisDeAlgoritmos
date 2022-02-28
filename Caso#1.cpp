
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//------------------------------------------------//
/*
ITCR. Semestre I 2022
Curso: Analisis de algoritmos
Estudiante: Pamela Gonzalez Lopez
Caso #1 - 5%
*/
//------------------------------------------------//

/* 
Ejercicio #1 Compare the triplets. Este primera función tiene 3 ciclos for con 6 comparaciones y 6 operaciones
y dos push_back al resultado.
*/
vector<int> compareTheTriplets_1(vector<int> a, vector<int> b){
	vector<int> resultado;
	int a_= 0;
	int b_= 0;
	
	for(int i=0; i < 3; i++){
		if(a[i] > b[i]){
			a_++;
		}
		if(a[i] < b[i]){
			b_++;
		}
	}
	resultado.push_back(a_);
	resultado.push_back(b_);
	return resultado;
}

/*
Ejercicio #1 Compare the triples MEJORADO. A diferencia del anterior cuenta con solo 3 comparaciones,con los if, 11
operaciones en el peor de los casos y dos push_back al resultado. Por lo que considero que esta implementación 
es mejor que la anterior pues evitamos el ciclo for y las comparaciones se reducen a la mitad. 
*/
vector<int> compareTheTriplets_2(vector<int> a, vector<int> b){
	vector<int> resultado;
	int a_= 0;
	int b_= 0;
	
  //3 comparaciones y en el peor de los casos 11 operaciones
  if(a[0]!= b[0]){
    int numero=(a[0]-b[0])/abs(a[0]-b[0]); 
    a_+=numero+1;                   
    b_+=numero-1;                   
  }
  if(a[1]!=b[1]){
    int numero=(a[1]-b[1])/abs(a[1]-b[1]);
    a_+=numero+1;        
    b_+=numero-1;
  }
  if(a[2]!=b[2]){
    int numero=(a[2]-b[2])/abs(a[2]-b[2]);
    a_+=numero+1;
    b_+=numero-1;
  }
  a_=a_/2;      
  b_=abs(b_/2);
  resultado.push_back(a_);
  resultado.push_back(b_);
  
  return resultado;
}

/*
Ejercicio #2 Time Conversion. En este ejercicio se hacen 3 comparaciones if , 2 operaciones y 2 substr.
El primer problema es que tiene varias comparaciones que se podrían evitar.
*/
string timeConversion_1(string formatAP) {	
	string format24h = formatAP.substr(2, 6); 
	int hrs = stoi(formatAP.substr(0,2)); 

	if(hrs==12){
		if(formatAP[8]=='A')
			hrs = 0; 
	}else if(formatAP[8]=='P'){
		hrs += 12; 
	}
	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;
	return format24h;
}

/*
Ejercicio #2, Time conversion MEJORADO. En esta otra version, tiene solo una comparación, por lo que se mejora mucho 
el ejercicio, tiene 4 operaciones y dos substr.
*/
string timeConversion_2(string formatAP) {	
	string format24h = formatAP.substr(2, 6); //:mm:ss
	int hrs = stoi(formatAP.substr(0,2)); //hh
	int factor = ((hrs%12)/hrs); 
	
	if(formatAP[8]=='A')
        factor--; 	
    hrs += (12 * factor);
	format24h = (hrs<10) ? "0"+to_string(hrs)+format24h : to_string(hrs)+format24h;	
	
	return format24h;
}

//Esta funcion la necesito para el ejercicio 3
int sumaArray(int a[], int t){
	int suma = 0;
	
	for(int i=0;i<t;i++){
		suma += a[i];
	}
return suma;
}

/*
Ejercicio 3, Subarray Division. Esta funcion tiene un ciclo while que será del tamaño del arreglo e iniciaría
desde la posicion del mes.Tomando como ejemplo un arreglo de 5 y mes 2, esta funcion haría 4 cilos while, 8 ciclos for
(creando los arreglos auxiliares) hace 4 comparacion y 12 operaciones. Añadiendo la funcion que suma los array auxiliares
que serían 8 ciclos for y 8 operaciones adicionales. Muy ineficiente.
*/
int subarrayDivision_1(int array[], int tamanno,  int mes, int dia){
		
	int posicionFinal = mes;
	int posicionInicial = 0;		
	int arrayNuevo[mes]; 
	int controlNuevoArray = 0;
	int respuesta = 0;	

	while (posicionFinal <= tamanno){
		
		for (int k=0; k < mes; k++){
			arrayNuevo[k] = array[controlNuevoArray];
			controlNuevoArray += 1;
		}		
		posicionFinal += 1;
		posicionInicial +=1; 
		controlNuevoArray = posicionInicial; 
		if(sumaArray(arrayNuevo,mes) == dia){
			respuesta += 1;
		}	
	}
	return respuesta;
}

/*
Ejercicio #3 Subarray Division MEJORADO. En esta versión, tomando el ejemplo anterior. Se harían solo 5 ciclos for
dos comparaciones  y 10 operaciones. Por lo que estaría mejor implementado que el anterior.
*/
int subarrayDivision_2(int a[], int t,  int mes, int dia){
	
	int inicial = 0; 
	int respuesta = 0;	
	int suma = 0;
	int control = 1;
	
	for (int i=0 ;i<t; i++){
		suma += a[i];
			
		if(control == mes && suma == dia){
			respuesta += 1;
			suma -= a[inicial];
			inicial += 1;
		}else if(control == dia){
			suma -= a[inicial];
			inicial += 1;
		}else
			control +=1;
	}
	return respuesta;
}

/*
Tomando en cuenta los nombres del aparecen en el ejercicio de HackerRank. No se hace explicaciones de los ejercicios siguientes 
porque en el enunciado del caso #1 no indica que se deban comentar.
*/

//Ejercicio #4
void theMinionGame(string palabra){
	
    int jugador1 = 0;
    int jugador2 = 0;

    for(int contador=0;contador<palabra.length();contador++){
    	if(palabra[contador]=='A'||palabra[contador]=='E'||palabra[contador]=='I'||palabra[contador]=='O'||palabra[contador]=='U'){
			jugador1 += palabra.length()-contador;
		}else{
			jugador2 += palabra.length()-contador;
		}
    }

    if(jugador1 > jugador2){
        cout<<"Kevin "<<jugador1<<endl;
    }
    else if(jugador1 < jugador2){
        cout<<"Stuart "<<jugador2<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
}

//Ejercicio #5
string cipher_(int n, int k, string entrada) {
	
    string respuestaFinal;
    respuestaFinal.append(n,0);
    int xor_;
    int controlador;
    
    for (int i = 0; i < n; i++) {
        if (i - k >= 0) {
        	controlador = respuestaFinal[i - k] - 48;
        	xor_ = xor_ ^ controlador;
        }
        int siguiente = xor_ ^ (entrada[i] - 48);
        xor_ = xor_ ^ siguiente;
        respuestaFinal[i] = siguiente + 48;
        
    }
    return respuestaFinal;
}

//Ejercicio #6
int pairs(int k, vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    
    int pointers[] = {1, 0, 0};
    int result = 0;
    int valueDif = 0;
    
    while (pointers[0] < arr.size()) {
        
        valueDif = arr[pointers[0]] - arr[pointers[2]];

        if (valueDif == k) {
            result++;
            pointers[0]++;
            continue;
        }
        
        pointers[ ((valueDif - k)/abs(valueDif - k)) + 1 ]++;
    }   
    return result;
}


int main(int argc, char *argv[])
{

cout<<"Ejercicio #1 - COMPARE THE TRIPLETS - "<<endl;

vector<int> a_1({5,6,7});
vector<int> b_1({3,6,10});
vector<int> c_1({17,28,30});
vector<int> d_1({99,16,8});

cout<<"-Version #1"<<endl;
vector<int> result = compareTheTriplets_1(a_1, b_1);
vector<int> result_ = compareTheTriplets_1(c_1, d_1);
cout<<result[0]<<" - "<<result[1]<<endl;
cout<<result_[0]<<" - "<<result_[1]<<endl;

cout<<"-Version #2"<<endl;
vector<int> result2 = compareTheTriplets_2(a_1, b_1);
vector<int> result2_ = compareTheTriplets_2(c_1, d_1);
cout<<result2[0]<<" - "<<result2[1]<<endl;
cout<<result2_[0]<<" - "<<result2_[1]<<endl;
cout<<endl;

cout<<"Ejercicio #2 - TIME CONVERSION - "<<endl;

cout<<"-Version #1"<<endl;
cout << timeConversion_1("12:30:20AM") << endl;
cout << timeConversion_1("05:11:15PM") << endl;
cout<<"-Version #2"<<endl;
cout << timeConversion_2("12:30:20AM") << endl;
cout << timeConversion_2("05:11:15PM") << endl;
cout<<endl;

cout<<"Ejercicio #3 - Subarray Division - "<<endl;

int a[] = {1,2,1,3,2};
int b[] = {4};
cout<<"-Version #1"<<endl;
cout<<subarrayDivision_1(a,5,2,3)<<endl;
cout<<subarrayDivision_1(b,1,1,4)<<endl;
cout<<"-Version #2"<<endl;
cout<<subarrayDivision_2(a,5,2,3)<<endl;
cout<<subarrayDivision_2(b,1,1,4)<<endl;
cout<<endl;

cout<<"Ejercicio #4 - The Minion Game - "<<endl;
string palabra1="BANANA";
string palabra2="ARIAL";
theMinionGame(palabra1);
theMinionGame(palabra2);
cout<<endl;

cout<<"Ejercicio #5 - Cipher - "<<endl;
cout<<cipher_(7,4,"1110100110")<<endl;
cout<<cipher_(6,2,"1110001")<<endl;
cout<<endl;

cout<<"Ejercicio #6 - Pairs - "<<endl;
vector<int> arr1 = {1,2,3,4};
vector<int> arr2 = {2,5,3,4,2};
cout<<pairs(1,arr1)<<endl;
cout<<pairs(2,arr2)<<endl;
cout<<endl;

    return 0;
}
