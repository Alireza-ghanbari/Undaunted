#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QVector>

class Unit;

class Player
{
public:
    Player(const QString &name);

    QString name() const;

    void addUnit(Unit *unit);
    const QVector<Unit*>& units() const;

private:
    QString m_name;
    QVector<Unit*> m_units;
};

#endif
