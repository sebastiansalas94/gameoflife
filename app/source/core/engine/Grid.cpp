// (c) Cheva's Game of Life
#include "Grid.h"

namespace gol::app::core::engine
{
Grid::Grid(int width, int height)
{
	cells = Cell[width][height];
	initCells(width, height);
}

void initCells(int width, int height)
{
	for(int i = 0; i < width - 1; ++i)
	{
		for(int j = 0; j < height - 1; ++j)
		{
			cell.createCell();
		}
	}	
}

int countNeighbors(int pRow, int pCol)
{
	int counterNeighbors = 0;
	int pRow, pCol = 0;
	for (int i = pRow - 1; i < pRow + 1; ++i)
	{
		for (int j = pCol - 1; j < pCol + 1; ++j)
		{
			if (cells[i][j].getState() == CellState::ALIVE)
			{
				counterNeighbors++;
			}
			
		}
	}

}
} // namespace gol::app::core::engine
