/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO 
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.h
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Contendrá la cadena y operará según un alfabeto dado
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Alfabeto.h"
#include <vector>

class Alfabeto;

class Cadena {
  public:
  Cadena(std::string);
  std::string getSecuencia() const;
  friend bool operator<(const Cadena& simb1, const Cadena& simb2);
  friend std::ostream& operator<<(std::ostream&, const Cadena&);
  std::vector<Cadena> Prefijos(Alfabeto);
  std::vector<Cadena> Sufijos(Alfabeto);
  std::set<Cadena> Subcadenas(Alfabeto);
  Cadena inversa(Alfabeto);
  int length(Alfabeto);
  bool VerificacionAlfabeto();
  private:
    std::string secuencia;
    bool verificacion;
};

bool operator<(const Cadena& simb1, const Cadena& simb2);