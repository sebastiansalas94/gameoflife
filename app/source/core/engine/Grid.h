// (c) Cheva's Game of Life
#pragma once
#include "Cell.h"
#include <vector>

namespace gol::app::core::engine
{
	class Grid
	{
	public:
		Grid(int width, int height);
		~Grid() = default;

		std::vector<std::vector<Cell>> getCells() const { return cells; };

	private:

		std::vector<std::vector<Cell>> cells;

		void initCells();
		int countNeighbors(int pRow, int pCol);
	};
} // namespace gol::app::core::engine
