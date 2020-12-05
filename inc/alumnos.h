/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

typedef struct alumno_s {
    char apellidos[30];
    char nombres[30];
    char documento[11];
} const * alumno_t;

/*=====[Definitions of public global variables]==============================*/

/*=====[Prototypes (declarations) of public functions]=======================*/

/**
@brief Convierte una constante de tipo alumno_t en una cadena de caracteres.

@param [in] cadena: puntero a la cadena de caracteres que se va a completar con los datos del alumno.
@param [in] espacio: la longitud de cadena.
@param [in] alumno: la constante de tipo alumno_t que se va a serializar

@return el resultado de snprintf, si el resultado es 0 quiere decir que no hubo errores, si es distinto de 0 quiere decir que hubo algún error durante la ejecución de snprintf.
*/
bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno);


/**
@brief Convierte a todas las constantes de tipo alumno_t que cuyos punteros están almacenadas en el arreglo ALUMNOS[] en una cadena de caracteres. Los datos de todos los alumnos son concatenados en una misma cadena. El formato para serializarlos utilizado es JSON.

@param [in] cadena: puntero a la cadena de caracteres que se va a completar con los datos del alumno.
@param [in] espacio: la longitud de cadena.

@return el resultado de snprintf, si el resultado es 0 quiere decir que no hubo errores, si es distinto de 0 quiere decir que hubo algún error durante la ejecución de snprintf.
*/
bool SerializarAlumnos(char * cadena, size_t espacio);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
