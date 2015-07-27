#ifndef POLYNOM_H
#define POLYNOM_H

#include <QObject>

class Polynom : public QObject
{
    Q_OBJECT
  public:
    explicit Polynom(QObject *parent = 0);
    ~Polynom();

  signals:

  public slots:
};

#endif // POLYNOM_H
