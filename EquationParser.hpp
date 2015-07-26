#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include "EquationItem.hpp"

namespace EquationParser
{
  EquationItem* parseExpression(const QString& a_Eqn, int& a_Pos);
  EquationItem* parseTerm(const QString& a_Eqn, int& a_Pos, EquationItem* a_Parent);
  EquationItem* parseFactor(const QString& a_Eqn, int& a_Pos, EquationItem* a_Parent);
}

#endif // EQUATIONPARSER_H
