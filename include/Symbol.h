/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.h
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Representa la unidad mínima o carácter de un alfabeto.
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string.h>
#include <string>
#include <cassert>
#include <iostream>
class Symbol {

  public:
    Symbol(const std::string& simbol);
    Symbol(const char& simbol);
    std::string getSymbol() const;
    friend bool operator<(const Symbol&, const Symbol&);

  private:
    std::string unique_symbol;

};

bool operator<(const Symbol&, const Symbol&);