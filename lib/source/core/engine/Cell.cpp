// (c) Cheva's Game of Life
#include "core/engine/Cell.h"

namespace gol::lib::core::engine
{
Cell::Cell()
{
	mState = CellState::STATE_DEAD;
}

void Cell::createCell()
{	
	mState = CellState::STATE_ALIVE;
}

void Cell::killCell()
{
	mState = CellState::STATE_DEAD;
}

} // namespace gol::lib::core::engine
