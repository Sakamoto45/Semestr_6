#ifndef MOVABLE_LABLE_H
#define MOVABLE_LABLE_H

#include <QObject>

class movable_lable : public QObject
{
    Q_OBJECT
public:
    explicit movable_lable(QObject *parent = nullptr);

signals:

};

#endif // MOVABLE_LABLE_H
