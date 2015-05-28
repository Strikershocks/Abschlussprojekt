#ifndef STRINGHELPERS_HPP
#define STRINGHELPERS_HPP

#include <sstream>

//Eigene to_string Methode f�r einfaches Umwandeln in String.
template <typename T>
std::string toString(const T& value);

#include "StringHelpers.inl"
#endif // STRINGHELPERS_HPP
