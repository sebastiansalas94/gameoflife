// (c) Cheva's Game of Life
#pragma once
#include "Cell.h"
#include <vector>
#include <algorithm>

namespace gol::lib::core::engine
{
	class Grid
	{
	public:
		Grid(int width, int height);
		~Grid() = default;

		//Move Assign
		Grid& operator=(Grid&& gridRValue) { 
			this->mCells = std::move(gridRValue.mCells);
			return *this; 
		};

		Grid(Grid&& gridRValue)
			: mCells(std::move(gridRValue.mCells)) {};
		
		std::vector<std::vector<Cell>> const& getCells() const { return mCells; };
		void createCell(int row, int col) { mCells[row][col].createCell(); };
		void killCell(int row, int col) { mCells[row][col].killCell(); };
		std::vector<Cell> countNeighbors(int pRow, int pCol);

	private:
		std::vector<std::vector<Cell>> mCells;

		void initCells(int width, int height);
		int processNextGeneration();
		
	};
} // namespace gol::lib::core::engine
