#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayEmployees.h"

int menu()
{
	printf("HOLA");
    int option;
    printf("Menu de Opciones\n\n");
    printf("1- ALTAS empleados\n");
    printf("2- MODIFICAR empleados\n");
    printf("3- BAJA empleados\n");
    printf("4- INFORMAR empleados\n");
    printf("5- SALIR\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int initEmployees(eEmployee employees[], int lenght)
{
    int ok;
    int i;

    ok = -1;

    for(i=0 ; i<lenght ; i++)
    {
        employees[i].isEmpty = 1;
        ok=0;
    }

    return ok;
}

int emptySpace(eEmployee employees[], int lenght)
{

    int element = -1;
    int i;

    for(i=0; i < lenght; i++)
    {
        if( employees[i].isEmpty == 1)
        {
            element = i;
            break;
        }
    }

    return element;
}

int findEmployeeById(eEmployee employees[], int lenght, int id)
{
    int element;
    int i;

    element= -1;

    for(i=0; i< lenght ;i++)
    {
        if( employees[i].isEmpty == 0 && employees[i].id == id)
        {
            element = i;
            break;
        }
    }

    return element;
}

int addEmployee(eEmployee employees[], int lenght, int id)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int ok;
    int element;

    ok=-1;

    printf("ALTA de Empleados.\n\n");

    printf("ID: %d", id);
    printf("\n\n");

    element= emptySpace(employees, lenght);

    if(element == -1)
    {
        printf("NO HAY ESPACIO, NO PUEDE CARGARSE EL EMPLEADO.\n\n");

    }else
    {
        verifyNames("Ingrese nombre: ", name);
        verifyNames("Ingrese apellido: ", lastName);

        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector: ");
        scanf("%d", &sector);

        employees[element]= newEmployee(id, name, lastName, salary, sector);
        ok=1;
        printf("Alta de empleado exitosa.");
    }

     return ok;
}


eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector)
{
    eEmployee x;

    x.id = id;
    strcpy(x.name, name);
    strcpy(x.lastName, lastName);
    x.salary = salary;
    x.sector = sector;
    x.isEmpty = 0;

    return x;
}

void verifyNames(char *message, char names[])
{
    char auxNames[100];

    printf("%s", message);
    fflush(stdin);
    gets(auxNames);

    while(strlen(auxNames)> 50)
    {
        printf("ERROR. Ingresar nuevamente: ");
        fflush(stdin);
        gets(auxNames);
    }

    strcpy(names, auxNames);

    names[0] = toupper(names[0]);

}

void printEmployees(eEmployee employees[], int lenght)
{
    int flag;
    int i;

    flag=0;

    if(employees != NULL && lenght > 0)
    {
    	printf("LISTADO DE EMPLEADOS.\n\n");

    	printf("ID  NAME  LAST NAME  SALARY  SECTOR\n");

    	for(i=0; i< lenght;i++)
    	{
    		if( employees[i].isEmpty == 0)
    		{
    			printEmployee(employees[i]);
    			flag = 1;
    		}
    	}
    }

    if( flag == 0)
    {
        printf("\n NO HAY EMPLEADOS PARA MOSTRAR.");
    }

    printf("\n\n");

}

void printEmployee(eEmployee employee)
{
    printf("%d  %s  %s  %f  %d \n\n",
           employee.id,
           employee.name,
           employee.lastName,
           employee.salary,
           employee.sector);
}

int modifyMenu()
{
    int option;

    printf("1-Modificar NOMBRE.\n");
    printf("2-Modificar APELLIDO.\n");
    printf("3-Modificar SALARIO.\n");
    printf("4-Modificar SECTOR.\n");
    printf("5-SALIR.\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;

}

void changeChar(char *message, int id, eEmployee employees[], int lenght)
{
    char names[51];
    char auxNames[100];
    char change;
    int i;

    change = 's';

    printf("%s", message);
    fflush(stdin);
    gets(auxNames);

    while(strlen(auxNames)> 50)
    {
        printf("ERROR. Ingresar nuevamente: ");
        fflush(stdin);
        gets(auxNames);
    }

    strcpy(names, auxNames);

    names[0] = toupper(names[0]);

    printf("Comfirma cambio realizado? ");

    if(change== 's')
    {
        strcpy(names, auxNames);

        for(i=0; i<lenght; i++)
        {
            if(id == employees[i].id)
            {
                strcpy(employees[i].name, names);
            }
        }

    }else
    {
        printf("Se cancelo la modificacion.\n\n");
    }
}

void changeSalary(int id, eEmployee employees[], int lenght)
{
    float salary;
    float auxSalary;
    char change;
    int i;

    change = 's';

    printf("Ingrese el NUEVO salario: ");
    scanf("%f", &auxSalary);

    printf("Comfirma cambio realizado? ");

    if(change== 's')
    {
        salary= auxSalary;

        for(i=0; i<lenght; i++)
        {
            if(id == employees[i].id)
            {
                employees[i].salary = salary;
            }
        }

    }else
    {
        printf("Se cancelo la modificacion.\n\n");
    }
}

void changeSector(int id, eEmployee employees[], int lenght)
{
    int sector;
    int auxSector;
    char change;
    int i;

    change = 's';

    printf("Ingrese el NUEVO numero de sector: ");
    scanf("%d", &auxSector);

    printf("Comfirma cambio realizado? ");

    if(change== 's')
    {
        sector=auxSector;

        for(i=0; i<lenght; i++)
        {
            if(id == employees[i].id)
            {
               employees[i].sector = sector;

            }
        }
    }else
    {
        printf("Se cancelo la modificacion.\n\n");
    }
}


void modifyEmployee(eEmployee employees[], int lenght, int id)
{
    int idFound;
    char modify;
    char exit;

    modify= 's';

    printf("*****MODIFICACIONES*****\n\n");

    printf("Ingrese numero de ID del empleado a modificar:");
    scanf("%d", &id);

    idFound = findEmployeeById(employees, lenght, id);

    if(idFound != -1)
    {
        printf("Desea modificar campos de este empleado? \n\n");
        printEmployee(employees[idFound]);
        fflush(stdin);
        modify= getchar();

        if(modify=='s')
        {
            do
            {
                switch(modifyMenu())
                {
                    case 1:
                        changeChar("Ingrese NUEVO nombre: ", idFound, employees, lenght);
                        break;
                    case 2:
                        changeChar("Ingrese NUEVO apellido: ", idFound, employees, lenght);
                        break;
                    case 3:
                        changeSalary(idFound, employees, lenght);
                        break;
                    case 4:
                        changeSector(idFound, employees, lenght);
                        break;
                    case 5:
                        printf("SALIR");
                        printf("\nConfirma Salida?");
                        fflush(stdin);
                        exit = getchar();
                        break;

                    default:
                        printf("OPCION INVALIDA. Intente nuevamente.\n\n");
                        break;
                }

            }while(exit == 'n');
        }
    }else
    {
        printf("No existe empleado con ese ID.");
    }
}

int removeEmployee(eEmployee employees[], int lenght, int id)
{
    int ok;
    int idFound;
    char change;

    ok=-1;
    change= 's';

    printf("*****BAJAS*****\n\n");

    printf("Ingrese numero de ID del empleado para realizar baja:");
    scanf("%d", &id);

    idFound = findEmployeeById(employees, lenght, id);

    if(idFound != -1)
    {
        printEmployee(employees[idFound]);

        printf("Desea dar de baja a este empleado?");
        fflush(stdin);
        scanf("%c", &change);

        if(change == 's')
        {
            employees[idFound].isEmpty = 1;
            ok= 0;
            printf("Baja de empleado exitosa.");

        }else
        {
            printf("Se cancelo la baja del empleado.");
            system("pause");
        }

    }else
    {
        printf("No existe un empleado con ese ID.");
    }

    return ok;
}

int sortingMenu()
{
    int option;

    printf("Menu de opciones.\n\n");

    printf("0- Listar empleados de manera DESCENDIENTE");
    printf("1- Listar empleados de manera ASCENDIENTE");
    printf("2- Listar total y promedio de los salarios, y empleados que superan el salario promedio.");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int sortEmployees(eEmployee employees[], int lenght)
{
    int ok;
    char exit;
    eEmployee auxEmployee;

    ok=-1;
    exit = 's';

    printf("*****LISTADO DE EMPLEADOS*****\n\n");

    do{
        switch(sortingMenu())
        {
            case 0:
                for(int i= 0; i < lenght-1 ; i++)
                {
                    for(int j= i+1; j <lenght; j++)
                    {
                        if( employees[i].sector > employees[j].sector && (strcmp(employees[i].lastName, employees[j].lastName) > 0))
                        {
                            auxEmployee = employees[i];
                            employees[i] = employees[j];
                            employees[j] = auxEmployee;
                        }
                    }
                }
        break;

        case 1:
            for(int i= 0; i < lenght-1 ; i++)
            {
                for(int j= i+1; j <lenght; j++)
                {
                    if( employees[i].sector < employees[j].sector && (strcmp(employees[i].lastName, employees[j].lastName) < 0))
                    {
                        auxEmployee = employees[i];
                        employees[i] = employees[j];
                        employees[j] = auxEmployee;
                    }
                }
            }
        break;

        case 2:
            bestSalaries(employees, lenght);
        break;

        case 3:
            printf("SALIR");
            printf("\nCorfirma Salida?");
            fflush(stdin);
            exit = getchar();
        break;

        default:
            printf("ERROR. Vuelva a ingresar una opcion.");
        break;
    }
    }while(exit == 'n');

    return ok;
}

void bestSalaries(eEmployee employees[], int lenght)
{
    float averageSalary;
    float higherSalary;
    int flag = 0;

    printf("***Mejores Salarios***\n\n");

    for( int i=0; i < lenght; i++)
    {
        for(int j=0; j < lenght ; j++)
        {
            if(averageSalary < employees[j].salary && employees[j].isEmpty == 0)
            {
                averageSalary += employees[j].salary / lenght;
                flag = 1;
            }
        }

        printf("Promedio de salarios: %.2f\n\n", averageSalary);

        for(int i= 0; i< lenght ; i++)
        {
            if(higherSalary > averageSalary)
            {
                printEmployee(employees[i]);
            }
        }

        averageSalary = 0;
        flag = 0;
    }
}
