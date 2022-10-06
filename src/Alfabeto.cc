/**
 * INGENIERIA INFORMATICA
 * SEGUNDO CURSO
 * COMPUTABILIDAD Y ALGORITMIA
 * Universidad de La Laguna
 * @file Alfabeto.cc
 * @author Borja Medina Ramos (alu0101337609@ull.edu.es)
 * @brief  Implementación de la clase Alfabeto
 * @version 0.1
 * @date 2022-09-30
 * @bug La clase alfabeto no operaba correctamente con los simbolos dados al
 * verificar una cadena (CORREGIDO)
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Alfabeto.h"


/**
 * @brief  Constructor de la clase alfabeto donde se les pasa símbolos con espacios entre sí.
 * @note   Se tomará como símbolos aquellas elementos separados por ' '.
 * @param  conjunto_simbolos: Todos los simbolos de ese alfabeto.
 */
Alfabeto::Alfabeto(std::string conjunto_simbolos) {
  this->simbolos_alfabeto.clear();
  if (conjunto_simbolos.find(' ') >= conjunto_simbolos.length()) {
    for (int i = 0; i < conjunto_simbolos.length(); i++) {
      this->simbolos_alfabeto.insert(Symbol(conjunto_simbolos.at(i)));
    }
  } else {
    std::stringstream conjunto(conjunto_simbolos);
    while (!conjunto.eof()) {
      std::string auxiliar;
      conjunto >> auxiliar;
      this->simbolos_alfabeto.emplace(Symbol(auxiliar));
    }
  }
}
/**
 * @brief  Constructor de copia
 * @note   Para construir un objeto en base a otro.
 * @param  &copia: 
 */
Alfabeto::Alfabeto(const Alfabeto &copia) {
  this->simbolos_alfabeto = copia.simbolos_alfabeto;
}
/**
 * @brief  Crea un alfabeto con la cadena vacía como único elemento.
 * @note   Por definición un alfabeto debe ser no vacío, por lo tanto, se agrega la cadena vacía.
 *         y así poder operar correctamente.
 * @retval 
 */
Alfabeto::Alfabeto() { 
  this->simbolos_alfabeto.clear();
  this->simbolos_alfabeto.insert(Symbol("&")); 
}
/**
 * @brief  Operador de flujo de salida.
 * @note   Inserta todos los elementos del alfabeto por el flujo de salida.
 * @param  &os: 
 * @param  alphabet: 
 * @retval 
 */
std::ostream &operator<<(std::ostream &os, Alfabeto alphabet) {
  for (auto x : alphabet.getAlphabet()) {
    os << x.getSymbol() << " ";
  }
  return os;
}
/**
 * @brief  Método para insertar símbolos al alfabeto.
 * @note   
 * @param  simbolo: 
 * @retval None
 */
void Alfabeto::Insert(Symbol simbolo) {
  this->simbolos_alfabeto.insert(simbolo);
}
/**
 * @brief  Determina el tamaño máximo de los símbolos.
 * @note   Esto sirve a la hora de obtener subcadenas ya que trocearemos y
 *         analizaremos la cadena dada con un máximo del valor devuelto.
 * @retval int: Tamaño máximo de la cadena.
 */
int Alfabeto::MaxSizeSymbol() const {
  int max = 0;
  for (auto x : this->simbolos_alfabeto) {
    if (x.getSymbol().length() > max) {
      max = x.getSymbol().length();
    }
  }
  return max;
}
/**
 * @brief  Método que indica si dicha cadena pueda pertenecer al alfabeto correspondiente.
 * @note   
 * @param  cadena_a_verificar: 
 * @retval bool: Si la pueda ser construida mediante una secuencia de los símbolos de un alfabeto.
 */
bool Alfabeto::VerificarCadena(Cadena cadena_a_verificar) const {
  std::string cadena = cadena_a_verificar.getSecuencia();
  if (cadena.empty() || (strcmp(cadena.c_str(), "&") == 0))
    return true;
  int j{0}, i{0}, iterador{0};
  std::string auxiliar;
  bool bandera;
  std::string divisor;
  while (i <= cadena.length() - 1) {
    auxiliar.clear();
    j = i;
    bandera = false;
    for (int k = 0; k < MaxSizeSymbol() && (j + k) < cadena.length(); k++) {
      auxiliar.push_back(cadena.at(j + k));
      if (simbolos_alfabeto.find(auxiliar) != simbolos_alfabeto.end()) {
        j += k;
        bandera = true;
        break;
      }
    }
    if (bandera == true) {
      i = j, i++, divisor = auxiliar;
      continue;
    }
    for (int k = 0; k < MaxSizeSymbol(); k++) {
      auxiliar.clear();
      iterador = abs(k - MaxSizeSymbol()) - 1;
      for (int t = j - (iterador); t <= j; t++) {
        if (t < 0)
          continue;
        auxiliar.push_back(cadena.at(t));
      }
      if (simbolos_alfabeto.find(auxiliar) != simbolos_alfabeto.end() &&
          strcmp(divisor.c_str(), auxiliar.c_str()) != 0) {
        bandera = true;
        break;
      }
    }
    if (bandera == false)
      return false;
    i++;
  }
  return true;
}