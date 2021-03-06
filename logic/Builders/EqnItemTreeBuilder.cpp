#include "Builders/EqnItemTreeBuilder.hpp"

#include <QDebug>

namespace N_Builders {

  namespace EqnItemTreeBuilder {

    //------------------------------------------------------------------------------------------------------
    PolynomialItem* parseExpression(const QString& a_Eqn, int& a_Pos, QQuickItem* a_Parent) // a_Pos is usually 0, but can be bigger in the case of complex expressions (with nested parentheses)
    {
      qInfo() << "Parsing expression";

      PolynomialItem* exprItem = new PolynomialItem(a_Parent);
      exprItem->setExprType(QString("Expression"));
      exprItem->setZ(-1);
      exprItem->setBorderColor(QColor("blue"));
      exprItem->setOp('+');

      // the first item has default operation + (any '-' sign should be read by the parseFactor method and would then update the EquationItem accordingly)
      PolynomialItem* termItem(parseTerm(a_Eqn, a_Pos, exprItem));
      termItem->setOp('+');

      while(a_Pos < a_Eqn.size() && a_Eqn[a_Pos] != QChar::Null)
      {
        QChar op(a_Eqn[a_Pos]);
        qInfo() << "parseExpression::Operator " << op.toLatin1();
        if(op != '+' && op != '-')
        {
          return exprItem;
        }
        ++a_Pos;

        termItem = parseTerm(a_Eqn, a_Pos, exprItem);
        termItem->setOp(op);
      }

      return exprItem;
    }

    //------------------------------------------------------------------------------------------------------
    PolynomialItem* parseTerm(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent)
    {
      qInfo() << "Parsing term";

      PolynomialItem* termItem = new PolynomialItem(a_Parent);
      termItem->setExprType(QString("Term"));
      termItem->setZ(0);
      termItem->setBorderColor(QColor("green"));

      // the first item has default operation *
      PolynomialItem* factorItem(parseFactor(a_Eqn, a_Pos, termItem));
      factorItem->setOp('*');

      while(a_Pos < a_Eqn.size() && a_Eqn[a_Pos] != QChar::Null)
      {
        QChar op(a_Eqn[a_Pos]);
        qInfo() << "parseTerm::Operator " << op.toLatin1();
        if(op != '*' && op != '/')
        {
          return termItem;
        }
        ++a_Pos;

        factorItem = parseFactor(a_Eqn, a_Pos, termItem);
        factorItem->setOp(op);
      }

      return termItem;
    }

    //------------------------------------------------------------------------------------------------------
    PolynomialItem* parseFactor(const QString& a_Eqn, int& a_Pos, PolynomialItem* a_Parent)
    {
      qInfo() << "Parsing factor";

      PolynomialItem* eqnItem = new PolynomialItem(a_Parent); // TODO: deal with the possibility that there is no factor ==> null pointer
      eqnItem->setExprType(QString("Factor"));
      eqnItem->setZ(1);
      eqnItem->setBorderColor(QColor("red"));

      if(a_Eqn[a_Pos] == 'x')
      {
        qInfo() << "Read symbol x";
        eqnItem->setText("x");
        ++a_Pos;
      }
      else
      {
        QString result;
        while(a_Pos < a_Eqn.size() && (a_Eqn[a_Pos].isDigit() || a_Eqn[a_Pos] == '.'))
        {
          qInfo() << a_Eqn[a_Pos].toLatin1();
          result += a_Eqn[a_Pos++];
        }
        eqnItem->setText(result);
      }

      // TODO: update the parent's sign if the factor is of the form (-x) or (-5) because the term's default sign is '+'
      return eqnItem;
    }

  }

}
