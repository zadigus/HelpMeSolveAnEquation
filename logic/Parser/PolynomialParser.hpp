#ifndef POLYNOMIALPARSER_H
#define POLYNOMIALPARSER_H

#include "EqnItems/PolynomialItem.hpp"

namespace PolynomialParser
{
  PolynomialItem* parseExpression(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent = 0);
  PolynomialItem* parseTerm(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent);
  PolynomialItem* parseFactor(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent);
}

#endif // POLYNOMIALPARSER_H
