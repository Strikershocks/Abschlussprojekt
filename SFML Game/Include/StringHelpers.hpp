#ifndef STRINGHELPERS_HPP
#define STRINGHELPERS_HPP

#include <sstream>

//Eigene to_string Methode für einfaches Umwandeln in String.
template <typename T>
std::string toString(const T& value);

#include "StringHelpers.inl"
#endif // STRINGHELPERS_HPP
