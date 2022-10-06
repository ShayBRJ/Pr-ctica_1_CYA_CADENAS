/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file main_analysis.cc
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Implementación de la clase Alfabeto
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al
 * verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/Cadena.h"
#include <fstream>

#define ERROR_ARGUMENTOS 1
#define OPCION_AYUDA 2
#define ERROR_OPCODE 3
#define SIN_ERROR 0


int main_protected(int argc, char** argv) {
  if(argc == 2 && (strcmp(argv[1], "--help") == 0)) {
    std::cout << "\tINFORMACIÓN DE AYUDA" << std::endl;
    std::cout << "El programa necesita de 3 argumentos fundamentales:\n";
    std::cout << "1) Nombre del archivo que contiene las líneas con los alfabetos y sus respectivas cadenas.\n";
    std::cout << "2) Nombre del archivo de salida donde se mostrará el resultado de la opción seleccionada.\n";
    std::cout << "3) Opcode: 1-5";
    std::cout << "\n1.Longitud \n2.Inversa\n3.Prefijos\n4.Sufijos\n5.Subcadenas\n";
    std::cout << "Ejemplo: " << argv[0] << " fichero_entrada.txt fichero_salida.txt 2" << std::endl;
    return OPCION_AYUDA;
  }
  if(argc != 4) {
    std::cerr << "Número de parámetros incorrectos" << std::endl;
    return ERROR_ARGUMENTOS;
  }
  if(!isdigit(argv[3][0]) || (atoi(argv[3]) > 5 || atoi(argv[3]) < 1)){
    std::cerr << "Error producido en el opcode." << std::endl;
    return ERROR_OPCODE;
  }
  return SIN_ERROR;
}