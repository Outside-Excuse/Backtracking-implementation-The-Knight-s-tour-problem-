/*
Backtracking implementation: The Knight's tour problem
Alejandro Hidalgo Badillo A01423412
fecha de inicio: 21 de noviembre del 2022
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//guardamos en dos arreglos los movimentos que el caballo puede realizar
int MovimientosX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int MovimientosY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

//esta funcion nos sirve para decirnos si a la casilla seleccionada se puede mover
bool isSafe(int i, int j, int n,
			vector<vector<int> >& Tablero)
//tiene una complejidad de O(n)
{
	return (i >= 0 and j >= 0 and i < n and j < n
			and Tablero[i][j] == 0);
}

//los dos status nos sirven para terminar el programa y que no haya ningun error de programacion
bool status1 = false;
bool status = false;

//la funcion principal, donde se realiza la recursion y por ende el backtracking
void knight_Tour(vector<vector<int> >& Tablero, int n,
				int x, int y, int visited = 1)
{	
	Tablero[x][y] = visited;

//preguntamos si el tablero fue recorrido en su totalidad para imprimir
	if (visited == n * n && status == false ) {
		status1 = true;
		status = true;

		// imprimimos el tablero recorrido
		//tiene una complejidad de O(n x n) debido a los dos for anidados 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << Tablero[i][j]-1<<' ';
			}
			cout <<"\n";
			}
			

		//regrsamos al anterior paso
		Tablero[x][y] = 0;
		return;
	}

//recorremos todos los posibles movimientos del caballo
	for (int i = 0; i < 8; i++) {

	
	
		int Xpos = x + MovimientosX[i];
		int Ypos = y + MovimientosY[i];

	
		if (isSafe(Xpos, Ypos, n, Tablero)
			&& !Tablero[Xpos][Ypos] && status == false) {
			knight_Tour(Tablero, n, Xpos, Ypos,
					visited + 1);
		}
	}

	//regresamos al anterior paso
	Tablero[x][y] = 0;
	/*
	tiene una complejidad N*N debido a que recorre todos los puntos de la  matriz o mejor dicho el tablero.

		*/
}

//inicio del main
int main()
{
	int n;
	cin>>n;
	int cont1,cont2;
	vector<vector<string>> puntos;
	string line;
	int cont = 0;
	//contq es el contador de lineas de entrada existentes
	int largo;
	getline(cin, line);
	 while (getline(cin, line)) {
		stringstream ss(line);
		puntos.push_back(vector<string>());
		while (ss.good()) {
        string substr;
        getline(ss, substr,' ');
        puntos[cont].push_back(substr);
    }
		 cont++;
  }//guardar matriz
	
	vector<vector<int>> Tablero(n, vector<int>(n, 0));

	int X = stoi(puntos[0][0]);
	int Y = stoi(puntos[0][1]);

	knight_Tour(Tablero, n, X, Y);

	//condicional para que no salte error de ejecucion por una mala entrada de datos
	//if (!status1) {
	//	cout <<"Error en la ejecucion\n";
	//}
	return 0;
	//el main tiene una complejidad de O(n x n) debido a los ciclos while anidados 
}
/*
la complejidad de este programa es de O(n*n) por que tiene que recorrer todos los elementos de la matriz.
*/