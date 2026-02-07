#include "GameController.h"
#include "GameState.h"
#include "GameRules.h"
#include "Cell.h"
#include "Unit.h"

GameController::GameController(GameState *state, QObject *parent)
    : QObject(parent), m_state(state)
{}

void GameController::onCellClicked(Cell *cell)
{
    if (!cell)
        return;

    Unit *selected = m_state->selectedUnit();

    if (!selected && cell->unit() &&
        cell->unit()->owner() == m_state->currentPlayer()) {

        m_state->selectUnit(cell->unit());
        emit boardUpdated();
        return;
    }

    if (selected && GameRules::canMove(selected, cell)) {
        selected->cell()->setUnit(nullptr);
        selected->setCell(cell);
        cell->setUnit(selected);

        m_state->nextTurn();
        emit boardUpdated();
    }
}
