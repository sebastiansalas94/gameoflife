// (c) Cheva's Game of Life
#include "core/engine/Grid.h"
#include <algorithm>

namespace gol::lib::core::engine
{
Grid::Grid(int width, int height)
	: mCells(width, std::vector<Cell>(height))
{
}

std::vector<Cell> Grid::countNeighbors(int pRow, int pCol)
{
	std::vector<Cell> neighborList;
	int pRowClamp = std::clamp(pRow - 1, 0, pRow + 1);
	int pColClamp = std::clamp(pCol - 1, 0, pCol + 1);

	for (int i = pRowClamp; i <= (mCells.size()-1) && i <= (pRow+1); ++i)
	{
		for (int j = pColClamp; j <= (mCells[i].size()-1) && j <= (pCol+1); ++j)
		{
			if (!(pRow == i && pCol == j) && mCells[i][j].getState() == CellState::STATE_ALIVE)
			{
				neighborList.push_back(mCells[i][j]); //Acá se está creando una copia
			}
		}
	}
	return neighborList;
}

} // namespace gol::lib::core::engine
