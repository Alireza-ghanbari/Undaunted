#include "GameController.h"
#include "GameState.h"
#include "GameRules.h"
#include "Cell.h"
#include "Unit.h"
#include "Player.h"

GameController::GameController(GameState *state, QObject *parent)
    : QObject(parent), m_state(state)
{}

void GameController::onCellClicked(Cell *cell)
{
    if (!cell) return;

    Unit *selected = m_state->selectedUnit();

    if (!selected) {
        if (cell->unit() && cell->unit()->owner() == m_state->currentPlayer()->name()) {
            m_state->selectUnit(cell->unit());
            emit boardUpdated();
        }
    }
    else if (selected == cell->unit()) {
        m_state->selectUnit(nullptr);
        emit boardUpdated();
    }
    else if (GameRules::canMove(selected, cell)) {
        if (selected->cell()) {
            selected->cell()->setUnit(nullptr);
        }

        selected->setCell(cell);
        cell->setUnit(selected);

        m_state->selectUnit(nullptr);
        m_state->nextTurn();
        emit boardUpdated();
    }
    else {
        m_state->selectUnit(nullptr);
        emit boardUpdated();
    }
}
