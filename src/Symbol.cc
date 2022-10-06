/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.h
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Implementación de la clase Symbol
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al
 * verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Symbol.h"

Symbol::Symbol(const char &simbol) { this->unique_symbol.push_back(simbol); }

Symbol::Symbol(const std::string &simbolo_) : unique_symbol(simbolo_) {
  assert(!simbolo_.empty());
}

std::string Symbol::getSymbol() const { 
  return this->unique_symbol; 
}

bool operator<(const Symbol &simb1, const Symbol &simb2) {
  return simb1.getSymbol() < simb2.getSymbol();
}