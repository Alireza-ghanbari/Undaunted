#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>

class Player;
class Unit;

class GameState : public QObject
{
    Q_OBJECT

public:
    explicit GameState(QObject *parent = nullptr);

    void setPlayers(Player *p1, Player *p2);

    Player* currentPlayer() const;
    Player* otherPlayer() const;

    void nextTurn();

    void selectUnit(Unit *unit);
    Unit* selectedUnit() const;

private:
    Player *m_player1 = nullptr;
    Player *m_player2 = nullptr;

    Player *m_currentPlayer = nullptr;
    Unit   *m_selectedUnit  = nullptr;
};

#endif
