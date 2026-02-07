#include "GameState.h"
#include "Player.h"
#include "Unit.h"

GameState::GameState(QObject *parent)
    : QObject(parent)
{}

void GameState::setPlayers(Player *p1, Player *p2)
{
    m_player1 = p1;
    m_player2 = p2;
    m_currentPlayer = p1;
}

Player* GameState::currentPlayer() const
{
    return m_currentPlayer;
}

Player* GameState::otherPlayer() const
{
    return (m_currentPlayer == m_player1) ? m_player2 : m_player1;
}

void GameState::nextTurn()
{
    m_currentPlayer = otherPlayer();
    m_selectedUnit = nullptr;
}

void GameState::selectUnit(Unit *unit)
{
    m_selectedUnit = unit;
}

Unit* GameState::selectedUnit() const
{
    return m_selectedUnit;
}
