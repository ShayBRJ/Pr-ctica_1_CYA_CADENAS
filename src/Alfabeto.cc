/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.cc
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Implementación de la clase Alfabeto
 * @version 0.1
 * @date 2022-09-14
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/Alfabeto.h"

Alfabeto::Alfabeto(std::string conjunto_simbolos) {
  this->simbolos_alfabeto.clear();
  if(conjunto_simbolos.find(' ') >= conjunto_simbolos.length()) {
    for(int i = 0; i < conjunto_simbolos.length(); i++) {
      this->simbolos_alfabeto.insert(Symbol(conjunto_simbolos.at(i)));
    }
  }
  else {
    std::stringstream conjunto(conjunto_simbolos);
    while(!conjunto.eof()){
      std::string auxiliar;
      conjunto >> auxiliar;
      this->simbolos_alfabeto.emplace(Symbol(auxiliar));
    }
  }
}

Alfabeto::Alfabeto(const Alfabeto& copia) {
  this->simbolos_alfabeto = copia.simbolos_alfabeto;
}

Alfabeto::Alfabeto() {
  this->simbolos_alfabeto.clear();
}

std::ostream& operator<<(std::ostream& os, Alfabeto alphabet) {
  for (auto x : alphabet.getAlphabet()) {
    os << x.getSymbol() << " ";
  }
  return os;
}

void Alfabeto::Insert(Symbol simbolo) {
  this->simbolos_alfabeto.insert(simbolo);
}

int Alfabeto::MaxSizeSymbol() const {
  int max = 0;
  for( auto x : this->simbolos_alfabeto) {
    if(x.getSymbol().length() > max) {
      max = x.getSymbol().length();
    }
  }
  return max;
}

bool Alfabeto::VerificarCadena(Cadena cadena_clase) const {
  std::string cadena = cadena_clase.getSecuencia();
  if(cadena.empty() || (strcmp(cadena.c_str(), "&") == 0)) return true;
  int j{0}, i{0}, iterador{0};
  std::string auxiliar;
  bool bandera;
  std::string divisor;
  while(i <= cadena.length() - 1) {
    auxiliar.clear();
    j = i;
    bandera = false;
    for(int k = 0; k < MaxSizeSymbol() && (j + k) < cadena.length(); k++) {
      auxiliar.push_back(cadena.at(j+k));
      if(simbolos_alfabeto.find(auxiliar) != simbolos_alfabeto.end()) {
        j+=k;
        bandera = true;
        break;
      }
    }
    if(bandera == true) {
      i = j, i++, divisor = auxiliar;
      continue;
    }
    for(int k = 0; k < MaxSizeSymbol(); k++) {
      auxiliar.clear();
      iterador = abs(k - MaxSizeSymbol() ) - 1;
      for(int t = j - (iterador); t <= j; t++) {
        if(t < 0) continue;
        auxiliar.push_back(cadena.at(t));
      }
      if(simbolos_alfabeto.find(auxiliar) != simbolos_alfabeto.end() && strcmp(divisor.c_str(), auxiliar.c_str()) != 0) {
        bandera = true;
        break;
      }
    }
    if(bandera == false) return false; 
    i++;
  }
  return true;
}