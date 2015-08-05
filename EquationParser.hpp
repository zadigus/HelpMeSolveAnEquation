#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include "MonomialItem.hpp"

namespace EquationParser
{
  MonomialItem* parseExpression(const QString& a_Eqn, int& a_Pos, MonomialItem* a_Parent = 0);
  MonomialItem* parseTerm(const QString& a_Eqn, int& a_Pos, MonomialItem* a_Parent);
  MonomialItem* parseFactor(const QString& a_Eqn, int& a_Pos, MonomialItem* a_Parent);
}

#endif // EQUATIONPARSER_H
