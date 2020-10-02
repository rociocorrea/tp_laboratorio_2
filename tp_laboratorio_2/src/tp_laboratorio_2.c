/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define LEN 1000

int main(void)
{
	eEmployee employeeList[LEN];
	char exit = 'n';
	int id = 0;

	initEmployees(employeeList, LEN);

	do{
	  switch(menu())
	  {
	     case 1:
	    	 printf("HOLA");
	    	 if(addEmployee(employeeList, LEN, id))
	         {
	             id++;
	         }
	     break;

	     case 2:
	    	 printEmployees(employeeList, LEN);
	    	 modifyEmployee(employeeList, LEN, id);
	     break;

	     case 3:
	    	 //removeEmployee(employeeList, LEN, id);
	     break;

	     case 4:
	          //sortEmployees(employeeList, LEN);
	     break;

	     case 5:
	          printf("SALIR");
	          printf("\nCorfirma Salida?");
	          fflush(stdin);
	          exit = getchar();
	     break;

	     default:
	          printf("OPCION INVALIDA. Intente nuevamente.\n\n");
	     break;
	  }

	}while( exit == 'n');

	 return 0;
}
