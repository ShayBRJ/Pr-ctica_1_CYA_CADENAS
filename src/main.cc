/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file main.cc
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Programa principal que leerá un archivo por comando junto a una opción opcode que
 * determinará la operación a realizar y mostrará en un fichero de salida dichas operaciones.
 * @version 0.1
 * @date 2022-09-14
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */

#include "main_analysis.h"

int main(int argc, char** argv) {
  
  int verificado_comandos = main_protected(argc, argv);

  if(verificado_comandos > 0) return verificado_comandos;
  
  std::ifstream archivo_entrada(argv[1]); //Archivo de lectura

  if(!archivo_entrada.is_open()) {
    std::cerr << "Error en el manejo de archivo" << std::endl;
    return 2;
  }

  std::ofstream archivo_salida(argv[2]); //Archivo de escritura
  
  std::vector<Cadena> vector_de_cadenas; //Contendrá cada cadena del archivo de lectura
  std::vector<Alfabeto> vector_de_alfabetos;
  std::string cadena_auxiliar_del_fichero;

  while(!archivo_entrada.eof()) {
    std::getline(archivo_entrada, cadena_auxiliar_del_fichero);
    std::stringstream cadena_alfabeto(cadena_auxiliar_del_fichero); //Cada linea
    Alfabeto alfabeto;
    std::string auxiliar_alfabeto;
    int iterador{0}; //Determina si se le ha pasado directamente la cadena.
    while(!cadena_alfabeto.eof()) {
      cadena_alfabeto >> auxiliar_alfabeto;
      if(cadena_alfabeto.eof()) break;
      alfabeto.Insert(auxiliar_alfabeto);
      iterador++;
    }
    if(cadena_auxiliar_del_fichero.empty()) continue;
    cadena_alfabeto >> auxiliar_alfabeto;
    if(iterador == 0) alfabeto = Alfabeto(auxiliar_alfabeto);
    vector_de_alfabetos.push_back(alfabeto);
    vector_de_cadenas.push_back(Cadena(auxiliar_alfabeto));
  }


  int opcode = atoi(argv[3]); //Opción elegida por el usuario.

  switch(opcode) {
    case 1:
    for(long unsigned int i = 0; i < vector_de_cadenas.size(); i++) {
      archivo_salida << vector_de_cadenas.at(i).length(vector_de_alfabetos.at(i)) << std::endl;
    }
    break;
    case 2:
    for(long unsigned int i = 0; i < vector_de_cadenas.size(); i++) {
      archivo_salida << vector_de_cadenas.at(i).inversa(vector_de_alfabetos.at(i)) << std::endl;
    }
    break;

    case 3:
    for(long unsigned int i = 0; i < vector_de_cadenas.size(); i++) {
      std::vector<Cadena> prefijos = vector_de_cadenas.at(i).Prefijos(vector_de_alfabetos.at(i));
      for(long unsigned int j = 0; j < prefijos.size(); j++) {
        archivo_salida << prefijos.at(j) << " ";
      }
      archivo_salida << "\n";
    }
    break;

    case 4:
    for(long unsigned int i = 0; i < vector_de_cadenas.size(); i++) {
      std::vector<Cadena> prefijos = vector_de_cadenas.at(i).Sufijos(vector_de_alfabetos.at(i));
      for(long unsigned int j = 0; j < prefijos.size(); j++) {
        archivo_salida << prefijos.at(j) << " ";
      }
      archivo_salida << "\n";
      
    }
    break;
    case 5:
    for(long unsigned int i = 0; i < vector_de_cadenas.size(); i++) {
      std::set<Cadena> subcadenas = vector_de_cadenas.at(i).Subcadenas(vector_de_alfabetos.at(i));
      for(auto x : subcadenas) {
        archivo_salida << x << " ";
      }
      archivo_salida << "\n";
    }
  }
  return 0;
}