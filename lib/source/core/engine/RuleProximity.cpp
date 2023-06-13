// (c) Cheva's Game of Life
#include "core/engine/RuleProximity.h"

namespace gol::lib::core::engine
{
	RuleProximity::RuleProximity()
	{
	}
	
	bool RuleProximity::execute(Cell const& cell, std::vector<Cell> const& neighborsCells)
	{
		int countN = neighborsCells.size();
		bool result = false;

		//ApplyRule
		if (countN <= 1 || countN >= 4)
		{
			result = false;
		}
		else if ((countN == 2 || countN == 3) && cell.getState() == gol::lib::core::engine::CellState::STATE_ALIVE)
		{
			result = true;
		}
		else if (countN == 3 && cell.getState() == gol::lib::core::engine::CellState::STATE_DEAD)
		{
			result = true;
		}
		return result;
	}
	
} // gol::lib::core::engine
