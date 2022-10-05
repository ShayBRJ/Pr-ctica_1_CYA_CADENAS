/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.h
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Implementación de la clase Cadena.
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/Cadena.h"



Cadena::Cadena(std::string chain) {
  this->secuencia = chain;
}


std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.getSecuencia();
  return os;
}

std::string Cadena::getSecuencia() const {  
  return this->secuencia.c_str();
}

int Cadena::length(Alfabeto simbolos) {
  if(strcmp(secuencia.c_str(), "&") == 0) {
    return 0;
  }
  if(simbolos.VerificarCadena(this->secuencia) == false) {
    return -1;
  }
  int max{0}, size{0}, espacio{0};
  std::string auxiliar;
  for(int i = 0; i < this->secuencia.length(); i++) {
    auxiliar.clear();
    for(int j = 0; j <= simbolos.MaxSizeSymbol() && (j + i < secuencia.length()) ; j++) {
      auxiliar.push_back(secuencia.at(j + i));
      if(simbolos.getAlphabet().find(auxiliar) != simbolos.getAlphabet().end() && (auxiliar.size() > max)) {
        max = auxiliar.size();
        espacio = j;
      }
    }
    i+=espacio, size++, max = 0;
  }
  return size;
}


/**
 * @brief Calcula la inversa de una cadena.
 * 
 * @return Un objeto Cadena bajo el mismo alfabeto. 
 */
Cadena Cadena::inversa(Alfabeto simbolos) {
  if(strcmp(secuencia.c_str(), "&") == 0 || secuencia.empty()) {
    return Cadena("&");
  }
  if(!(simbolos.VerificarCadena(this->getSecuencia()))) {
    return Cadena("ERROR");
  }
  std::string auxiliar, cadena_inversa;
  int j, i = this->secuencia.size() - 1;
  int k = simbolos.MaxSizeSymbol() - 1;
  while(i >= 0) {
    auxiliar.clear();
    for(int t = k; t >= 0 && (i - t >= 0); t--) {
      auxiliar.push_back(secuencia.at(i - t));
    }
    if(Cadena(auxiliar).length(simbolos) == 1) {
      i -= k, i--;
      k = simbolos.MaxSizeSymbol() - 1;
      cadena_inversa += auxiliar;
    }
    else {
      k--;
    }
    assert(k >= 0);
  }
  return Cadena(cadena_inversa);
}

std::vector<Cadena> Cadena::Prefijos(Alfabeto simbolos) {
  
  std::vector<Cadena> auxiliar_cadenas;
  if(!(simbolos.VerificarCadena(this->secuencia)))  {
    auxiliar_cadenas.push_back(Cadena("ERROR"));
    return auxiliar_cadenas;
  }
  auxiliar_cadenas.push_back(Cadena("&"));
  std::string auxiliar, cadena_resultado;
  int max = 0, contador_vector = 1;
  for(int i = 0; i < this->secuencia.length(); i++) {
    for(int j = 0; j < simbolos.MaxSizeSymbol() && ((j + i) < this->secuencia.length()); j++) {
      auxiliar.push_back(this->secuencia.at(j + i));
      if(simbolos.getAlphabet().find(auxiliar) != simbolos.getAlphabet().end() && (auxiliar.size()) > max) {
        max = auxiliar.size() - 1;
        cadena_resultado = auxiliar;
      }
    }
    std::string prefijos_previos;
    if(contador_vector != 1) prefijos_previos = auxiliar_cadenas.at(contador_vector - 1).getSecuencia();
    prefijos_previos += cadena_resultado;
    auxiliar_cadenas.push_back(Cadena(prefijos_previos));
    contador_vector++;
    auxiliar.clear();
    cadena_resultado.clear();
    i += max;
    max = 0;
  }
  return auxiliar_cadenas;
}

std::vector<Cadena> Cadena::Sufijos(Alfabeto simbolos) {

  std::vector<Cadena> auxiliar_cadenas;
  if(!(simbolos.VerificarCadena(this->secuencia)))  {
    auxiliar_cadenas.push_back(Cadena("ERROR"));
    return auxiliar_cadenas;
  }
  auxiliar_cadenas.push_back(Cadena("&"));
  std::string auxiliar, cadena_resultado, cadena_resultado_final;
  int max = 0, contador_vector = 1;
  for(int i = this->secuencia.size() - 1; i >= 0; i--) {
    for(int t = 0; t < simbolos.MaxSizeSymbol() && ((i - t) >= 0); t++) {
      auxiliar.clear();
      auxiliar.push_back(this->secuencia.at(i - t));
      cadena_resultado =  auxiliar + cadena_resultado;
      if(simbolos.getAlphabet().find(cadena_resultado) != simbolos.getAlphabet().end() && cadena_resultado.size() > max) {
        cadena_resultado_final = cadena_resultado;
        max = cadena_resultado.size() - 1;
      }
    }
    std::string sufijos_previos;
    if(contador_vector != 1) sufijos_previos = auxiliar_cadenas.at(contador_vector - 1).getSecuencia();
    cadena_resultado_final = cadena_resultado_final +  sufijos_previos;
    auxiliar_cadenas.push_back(Cadena(cadena_resultado_final));
    contador_vector++;
    auxiliar.clear(), cadena_resultado.clear(), cadena_resultado_final.clear();
    i -= max, max = 0;
  }
  return auxiliar_cadenas;
}

std::set<Cadena> Cadena::Subcadenas(Alfabeto simbolos) {
  std::set<Cadena> auxiliar_cadenas;
  if(!(simbolos.VerificarCadena(this->secuencia))) {
    auxiliar_cadenas.insert(Cadena("ERROR"));
    return auxiliar_cadenas;
  }
  auxiliar_cadenas.insert(Cadena("&"));
  for (int i = 0; i < this->secuencia.length(); i++) {
    for(int j = i + 1; j < this->secuencia.length() + 1; j++) {
      std::string auxiliar = this->secuencia.substr(i, j - i);
      if(simbolos.VerificarCadena(auxiliar)) {
        auxiliar_cadenas.insert(Cadena(auxiliar));
      }
    }
  }
  return auxiliar_cadenas;
}