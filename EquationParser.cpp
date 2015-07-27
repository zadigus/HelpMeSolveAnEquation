#include "EquationParser.hpp"

#include <QDebug>

namespace EquationParser {

  EquationItem* parseExpression(const QString& a_Eqn, int& a_Pos, EquationItem* a_Parent) // a_Pos is usually 0, but can be bigger in the case of complex expressions (with nested parentheses)
  {
    EquationItem* exprItem = new EquationItem(a_Parent);

    // the first item has default operation + (any '-' sign should be read by the parseFactor method and would then update the EquationItem accordingly)
    EquationItem* termItem(parseTerm(a_Eqn, a_Pos, exprItem));
    termItem->setOp('+');

    while(a_Eqn[a_Pos] != QChar::Null)
    {
      QChar op(a_Eqn[a_Pos]);
      qWarning() << "parseExpression::Operator " << op.toLatin1();
      if(op != '+' && op != '-')
      {
        return exprItem;
      }
      ++a_Pos;

      termItem = parseTerm(a_Eqn, a_Pos, exprItem);
      termItem->setOp(op);
    }

    // TODO: set the expression's m_Text somehow; maybe here or maybe in the EquationItem itself (it can deduce that text from its children)
    // this may also not be necessary, since the text can be deduced from the children
    return exprItem;
  }

  EquationItem* parseTerm(const QString& a_Eqn, int& a_Pos, EquationItem* a_Parent)
  {
    EquationItem* termItem = new EquationItem(a_Parent);

    // the first item has default operation *
    EquationItem* factorItem(parseFactor(a_Eqn, a_Pos, termItem));
    factorItem->setOp('*');

    while(a_Eqn[a_Pos] != QChar::Null)
    {
      QChar op(a_Eqn[a_Pos]);
      qWarning() << "parseTerm::Operator " << op.toLatin1();
      if(op != '*' && op != '/')
      {
        return termItem;
      }
      ++a_Pos;

      factorItem = parseFactor(a_Eqn, a_Pos, termItem);
      factorItem->setOp(op);
    }

    // TODO: set the term's m_Text somehow; maybe here or maybe in the EquationItem itself (it can deduce that text from its children)
    // this may also not be necessary, since the text can be deduced from the children
    return termItem;
  }

  EquationItem* parseFactor(const QString& a_Eqn, int& a_Pos, EquationItem* a_Parent)
  {
    EquationItem* eqnItem = new EquationItem(a_Parent); // TODO: deal with the possibility that there is no factor ==> null pointer

    if(a_Eqn[a_Pos] == 'x')
    {
      qWarning() << "Read symbol x";
      eqnItem->setText("x");
      ++a_Pos;
    }
    else
    {
      QString result;
      while(a_Eqn[a_Pos].isDigit() || a_Eqn[a_Pos] == '.')
      {
        qWarning() << a_Eqn[a_Pos].toLatin1();
        result += a_Eqn[a_Pos++];
      }
      eqnItem->setText(result);
    }

//    a_Parent->

    // TODO: update the parent's sign if the factor is of the form (-x) or (-5) because the term's default sign is '+'
    return eqnItem;
  }

}
