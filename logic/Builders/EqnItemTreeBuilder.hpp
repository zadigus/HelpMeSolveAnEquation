#ifndef EQNTREEBUILDER_H
#define EQNTREEBUILDER_H

#include "EqnItems/PolynomialItem.hpp"

using namespace N_EqnItems;

namespace EqnItemTreeBuilder
{
  PolynomialItem* parseExpression(const QString& a_Eqn, int& a_Pos, QQuickItem* a_Parent = 0);
  PolynomialItem* parseTerm(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent);
  PolynomialItem* parseFactor(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent);
}

#endif // EQNTREEBUILDER_H
