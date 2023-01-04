// (c) Cheva's Game of Life
#include "Cell.h"

namespace gol::app::core::engine
{
Cell::Cell()
{
	state = CellState::STATE_DEAD;
}

void Cell::createCell()
{	
	state = CellState::STATE_ALIVE;
}

void Cell::killCell()
{
	state = CellState::STATE_DEAD;
}

} // namespace gol::app::core::engine
