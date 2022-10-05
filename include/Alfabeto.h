/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.h
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Contendrá un conjunto de simbolos finito.
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <set>
#include <sstream>
#include <vector>
#include "Symbol.h"
#include "Cadena.h"

class Cadena;

class Alfabeto {
  public:
    Alfabeto(std::string);
    Alfabeto();
    Alfabeto(const Alfabeto&);
    
    void Insert(Symbol);
    std::set<Symbol>& getAlphabet() { return simbolos_alfabeto; };
    
    friend std::ostream& operator<<(std::ostream&, Alfabeto simbolos);

    bool VerificarCadena(Cadena cadena) const;
    int MaxSizeSymbol() const;

  private:
    std::set<Symbol> simbolos_alfabeto;

};