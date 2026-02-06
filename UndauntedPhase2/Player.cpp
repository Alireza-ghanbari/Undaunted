#include "Player.h"
#include "Unit.h"

Player::Player(const QString &name)
    : m_name(name)
{}

QString Player::name() const {
    return m_name;
}

void Player::addUnit(Unit *unit) {
    m_units.append(unit);
}

const QVector<Unit*>& Player::units() const {
    return m_units;
}
