/*
 * arrayEmployees.h
 *
 *  Created on: 1 oct. 2020
 *      Author: lenovo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

/** \brief Menu de opciones que se despliega para la ALTA, BAJA, MODIFICACION e INFORMES de empleados.
 *
 * \param sin parámetros.
 * \param sin parámetros.

 * \return opción elgida por el usuario.
 *
 */
int menu();


/** \brief Inicializa el vector de empleados, poniendo el campo isEmpty en 1.
 *
 * \param vector de empleados.
 * \param tamaño del vector de empleados.

 * \return Variable ok, con valor -1 si hubo error, con valor 0 si funcionó correctamente.
 *
 */
int initEmployees(eEmployee employees[], int lenght);


/** \brief Busca espacio libre en el vector, si el campo isEmpty tiene valor 1.
 *
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.

 * \return Variable element, con valor -1 si hubo error, o con valor del índice que tiene espacio.
 *
 */
int emptySpace(eEmployee employees[], int lenght);


/** \brief Busca un empleado según ID.
 *
 * \param Vector de empleados.

 * \param Tamaño del vector de empleados.

 * \param ID para buscar el empleado.

 * \return Valor de la variable element, devuelve -1 si hubo error o posición del empleado en el vector.
 *
 */
int findEmployeeById(eEmployee employees[], int lenght, int id);


/** \brief Da de alta un empleado en la primera posición libre.
 *
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.
 * \param ID del empleado.
 * \param Nombre del empleado.
 * \param Apellido del empleado.
 * \param Salario del empleado.
 * \param Sector del empleado.

 * \return Variable ok, devuelve -1 si hubo un error, o 1 si se dio de ALTA el empleado
 *
 */
int addEmployee(eEmployee employees[], int lenght, int id);

/** \brief Muestra un empleado con sus campos.
 *
 * \param Vector de empleados.

 * \return No retorna nada.
 *
 */
void printEmployee(eEmployee employee);


/** \brief Muestra el listado de empleados.
 *
 * \param Vector de empleados.

 * \param Tamaño del vector de empleados.

 * \return No retorna nada.
 *
 */
void printEmployees(eEmployee employees[], int lenght);


/** \brief Verifica que el nombre y el apellido del empleado sean válidos.
 *
 * \param Mensaje para el usuario.

 * \param Nombre o apellido del empleado.

 * \return No retorna nada.
 *
 */
void verifyNames(char *message, char names[]);


/** \brief Nueva estructura para dar alta empleados.
 *
 * \param ID del empleado.
 * \param Nombre del empleado.
 * \param Apellido del empleado.
 * \param Salario del empleado.
 * \param Sector del empleado.

 * \return Un nuevo empleado.
 *
 */
eEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector);


/** \brief Despliega menu para modificar campos del empleado.
 *
 * \param sin parámetros.

 * \return Opción elegida por el usuario en variable option.
 *
 */
int modifyMenu();


/** \brief Le da opción al usuario para modificar campos del empleado.
 *
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.
 * \param ID del empleado a modificar.

 * \return No retorna nada.
 *
 */
void modifyEmployee(eEmployee employees[], int lenght, int id);


/** \brief Cambia una cadena de char por otra
 *
 * \param Mensaje por puntero.
 * \param ID del empleado.
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.

 * \return No retorna nada.
 *
 */
void changeChar(char *message, int id, eEmployee employees[], int lenght);


/** \brief Cambia un salario(float) por otro(float)
 *
 * \param ID del empleado.
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.

 * \return No retorna nada.
 *
 */
void changeSalary(int id, eEmployee employees[], int lenght);


/** \brief Cambia un sector(int) por otro (int)
 *
 * \param ID del empleado.
 * \param Vector de empleados.
 * \param Tamaño del vector de empleados.

 * \return No retorna nada.
 *
 */
void changeSector(int id, eEmployee employees[], int lenght);


/** \brief Despliega menu para ordenar empleados.
 *
 * \param Sin parámetros.

 * \return Opción para ordenar empleados.
 *
 */
int sortingMenu();


/** \brief Ordena empleados según opción del usuario.
 *
 * \param Vector de empleados.

 * \param Tamaño del vector de empleados.

 * \return Variable ok, devuelve -1 si hubo error, 0 si funcionó.
 *
 */
int sortEmployees(eEmployee employees[], int lenght);


/** \brief Calcula el promedio de salarios de los empleados.
 *
 * \param Vector de empleados.
 * \param Tamaño de vector de empleados.
 * \return No retorna nada.
 *
 */
void bestSalaries(eEmployee employees[], int lenght);


#endif /* ARRAYEMPLOYEES_H_ */
