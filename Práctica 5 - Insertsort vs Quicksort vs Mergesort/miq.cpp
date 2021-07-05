#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>

int t0, t1, t2, t3, t4, t5, t6, t7, t2q2, t3q2, t2q, t3q;

class lista
{
private:
	int longitud;
	int *array;

	int *analisis;

public:
	int tamano = longitud;
	int tam()
	{
		return longitud;
	}

	void CrearLista()
	{
		analisis = new int(2);
		for (int j = 0; j < 2; j++)
		{
			analisis[j] = 0;
		}
		int contadorArrayDinamico = 0;
		std::cout << "Ingrese numero de Elementos de la Lista:" << std::endl;
		std::cin >> longitud;
		//SE CREA UNA LISTA DE ALTO NUMERO DE ELEMENTOS
		array = new int[longitud];
		for (int i = 0; i < longitud; i++)
			array[i] = rand();
		//ANALISIS DE CANTIDAD DE ASIGNACION DE MEMORIA
		contadorArrayDinamico = 1;
		std::cout << "Contador de Array dinamico: ";

		std::cout << contadorArrayDinamico * 50 + longitud * 10 << std::endl;
	}
	void mostrar()
	{
		std::cout << "\n\nMostrando lista:\n";
		for (int i = 0; i < longitud; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << "" << std::endl;
	}
	void delet()
	{
		delete[] array;
	}

	//	ORDENA LA MITAD DEL ARREGLO

	void Insert_dos()
	{ //--------Se creara variables para contabilizar las asignaciones y comparaciones
		int i, j, x;
		i = 1;
		while (i < longitud / 2)
		{
			x = array[i];
			j = i - 1;
			while (j >= 0 && array[j] > x)
			{
				array[j + 1] = array[j];
				j = j - 1;
			}
			array[j + 1] = x;
			i = i + 1;
		}
	}
	void Insert()
	{ //--------Se creara variables para contabilizar las asignaciones y comparaciones
		int comparaciones = 0;
		int asignaciones = 1; //se empieza con 1 por la unica y primera asignacion de i =1
		int i, j, x;
		i = 1;
		while (i < longitud)
		{
			comparaciones++; //por cada while se comparara i<logitud
			x = array[i];
			j = i - 1;
			while (j >= 0 && array[j] > x)
			{
				comparaciones = comparaciones + 2; //por cada while se ahra 2 comparaciones en la condicion del while mismo
				array[j + 1] = array[j];
				j = j - 1;
				asignaciones = asignaciones + 2; //por las dos lineas de codigo anteriores
			}
			array[j + 1] = x;
			i = i + 1;
			asignaciones = asignaciones + 4; // 4 son las asignaciones q hace el while principal
		}
		std::cout << "el numero de comparaciones del Insertsort es: " << comparaciones << " y multiplicado x2: " << comparaciones * 2 << std::endl;
		std::cout << "el numero de asignaciones del Insertsort es: " << asignaciones << " y multiplicado x8: " << asignaciones * 8 << std::endl;
	}

	void Merge(int p, int q, int r)
	{
		analisis[0] = analisis[0] + 2;
		int n1, n2, i, j, k;
		n1 = q - p + 1;
		n2 = r - q;
		int L[n1], R[n2];
		analisis[0] = analisis[0] + 1;
		analisis[1] = analisis[1] + 1;
		for (i = 0; i < n1; i++)
		{
			analisis[1] = analisis[1] + 1;
			analisis[0] = analisis[0] + 2;
			L[i] = array[p + i];
		}
		analisis[0] = analisis[0] + 1;
		analisis[1] = analisis[1] + 1;
		for (j = 0; j < n2; j++)
		{
			analisis[1] = analisis[1] + 1;
			analisis[0] = analisis[0] + 2;
			R[j] = array[q + j + 1];
		}
		i = 0, j = 0;
		analisis[0] = analisis[0] + 2;

		analisis[0] = analisis[0] + 1;
		analisis[1] = analisis[1] + 1;
		for (k = p; i < n1 && j < n2; k++)
		{
			analisis[0] = analisis[0] + 2;
			analisis[1] = analisis[1] + 2;

			if (L[i] < R[j])
			{
				array[k] = L[i++];
			}
			else
			{
				array[k] = R[j++];
			}
		}

		analisis[1] = analisis[1] + 1;
		while (i < n1)
		{
			analisis[0] = analisis[0] + 1;
			analisis[1] = analisis[1] + 1;
			array[k++] = L[i++];
		}

		analisis[1] = analisis[1] + 1;
		while (j < n2)
		{
			analisis[0] = analisis[0] + 1;
			analisis[1] = analisis[1] + 1;
			array[k++] = R[j++];
		}
	}
	void split(int p, int r)
	{
		// analisis[0]==asignaciones
		// analisis[1]==comparaciones
		int q;
		analisis[1] = analisis[1] + 1;
		if (p < r)
		{
			analisis[0] = analisis[0] + 1;
			q = (p + r) / 2;
			split(p, q);
			split(q + 1, r);
			Merge(p, q, r);
		}
	}

	void swapp(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int particion(int *A, int p, int r, float &c)
	{
		int x = A[r];
		int i = p - 1;
		for (int j = p; j < r; j++)
		{
			if (A[j] <= x)
			{
				i = i + 1;
				swapp(A[i], A[j]);
				//el contador de las veces promedio que se hara...
				//... una comparacion e intercambio nuevos
				c = c + 1;
			}
		}
		swapp(A[i + 1], A[r]);
		c = c + 1;
		return i + 1;
	}
	void quickk(int p, int r, float &c)
	{
		int q;
		if (p < r)
		{
			q = particion(array, p, r, c);
			quickk(p, q - 1, c);
			quickk(q + 1, r, c);
		}
	}
	void asign()
	{

		// analisis[0]==asignaciones

		std::cout << "numero de asignaciones de merge sort" << std::endl;
		std::cout << analisis[0] << std::endl;
	}

	void com()
	{

		// analisis[1]==comparaciones

		std::cout << "numero de comparaciones merge sort" << std::endl;
		std::cout << analisis[1] << std::endl;
	}
};
int main()
{
	float c = 0;
	//NOTA:
	//LOS CONTADORES DE ASIGNACION Y COMPARACION SE ENCUENTRAN DENTRO DE LAS FUNCIONES DE BUBBLE E INSERTION SORT
	//SE CREA UN ARRAY DINAMICO Y SE LO COPIA EN OTRA CLASE PARA COMPARAR EL RENDIMIENTO DE BUBBLE E INSERTION
	int contadorObjeto = 0;
	lista primera; //creacion del unico objeto a usar en el codigo
	lista segunda;
	lista tercera;
	lista cuarta;
	lista quick_01;
	lista quick_02;

	contadorObjeto = 2;
	std::cout << " Se ha creado 1 objeto que equivaldria a un x200" << std::endl;
	primera.CrearLista();
	segunda = primera;
	tercera = primera;
	cuarta = primera;
	quick_01 = primera;
	quick_02 = primera;
	std::cout << std::endl;
	std::cout << "se ha creado la siguiente lista desordenada...\n";
	//	primera.mostrar();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-------INSERT SORT CRECIENTE------" << std::endl;
	t0 = clock();
	primera.Insert();
	t1 = clock();
	std::cout << "ordenamiento de insert sort...\n";
	//	primera.mostrar();
	float time1 = t1 - t0;
	std::cout << "Execution Time: " << time1 << std::endl;

	std::cout << "-------MERGE SORT------" << std::endl;
	t2 = clock();
	int a = segunda.tam() - 1;
	segunda.split(0, a);
	t3 = clock();
	std::cout << "ordenamiento de MERGE...\n";
	//	segunda.mostrar();
	segunda.asign();
	segunda.com();
	float time2 = t3 - t2;
	std::cout << "Execution Time: " << time2 << std::endl;

	std::cout << "-------QUICK SORT------" << std::endl;
	t2q = clock();
	int aq1 = quick_01.tam() - 1;
	quick_01.quickk(0, aq1, c);
	t3q = clock();
	std::cout << "ordenamiento de QUICK...\n";
	//	segunda.mostrar();
	//quick_01.asign();
	//quick_01.com();
	float time2quieck = t3q - t2q;
	std::cout << "Execution Time: " << time2quieck << std::endl;

	tercera.Insert_dos();
	cuarta = tercera;
	std::cout << "-------Arrays con la mitad de elementos ordenados------" << std::endl;
	c=0;
	std::cout << "-------INSERT SORT CRECIENTE------" << std::endl;
	t4 = clock();
	tercera.Insert();
	t5 = clock();
	std::cout << "ordenamiento de insert sort...\n";
	//	primera.mostrar();
	float time3 = t5 - t4;
	std::cout << "Execution Time: " << time3 << std::endl;

	std::cout << "-------MERGE SORT------" << std::endl;
	t6 = clock();
	int b = cuarta.tam() - 1;
	cuarta.split(0, b);
	t7 = clock();
	std::cout << "ordenamiento de MERGE...\n";
	//	segunda.mostrar();
	cuarta.asign();
	cuarta.com();
	float time4 = t7 - t6;
	std::cout << "Execution Time: " << time4 << std::endl;

	std::cout << "-------QUICK SORT------" << std::endl;
	t2q2 = clock();
	int aq_2 = quick_02.tam() - 1;
	quick_02.quickk(0, aq_2,c);
	t3q2 = clock();
	std::cout << "ordenamiento de QUICK...\n";
	//	segunda.mostrar();
	//quick_02.asign();
	//quick_02.com();
	float time2q = t3q2 - t2q2;
	std::cout << "Execution Time: " << time2q << std::endl;

	//primera.delet();
	//segunda.delet();
	//tercera.delet();
	//cuarta.delet();
	std::cout << "Alumno: Joao Chavez Salas" << std::endl;
	return 0;
}
