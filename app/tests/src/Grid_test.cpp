// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include <vector>
#include "core/engine/Grid.h"
#include "core/engine/Cell.h"

using gol::lib::core::engine::Grid;
using gol::lib::core::engine::Cell;

namespace gol::test
{
	TEST(GridTest, EmptyGrid)
	{
		int expectedCells = 0;
		Grid grid(0, 0);
		std::vector<std::vector<Cell>> mCells = grid.getCells();

		int cellsCount = mCells.size();

		EXPECT_EQ(expectedCells, cellsCount);
	}

	TEST(GridTest, CountNeighbors_1_1)
	{
		int expectedNeighbors = 0;
		Grid grid(1, 1);

		grid.createCell(0, 0);

		std::vector<Cell> neighborList = grid.countNeighbors(0, 0);
		int neighborCount = neighborList.size();

		EXPECT_EQ(expectedNeighbors, neighborCount);
	}

	TEST(GridTest, CountNeighbors_2_2)
	{
		int expectedNeighbors = 1;
		Grid grid(2, 2);

		grid.createCell(1, 0);

		std::vector<Cell> neighborList = grid.countNeighbors(0, 0);
		int neighborCount = neighborList.size();

		EXPECT_EQ(expectedNeighbors, neighborCount);
	}

	TEST(GridTest, CountNeighbors_3_3)
	{
		int expectedNeighbors = 2;
		Grid grid(3, 3);

		grid.createCell(1, 0);
		grid.createCell(0, 1); 

		std::vector<Cell> neighborList = grid.countNeighbors(0, 0);
		int neighborCount = neighborList.size();

		EXPECT_EQ(expectedNeighbors, neighborCount);
	}

	TEST(GridTest, CountNeighbors_3_2)
	{
		int expectedNeighbors = 1;
		Grid grid(3, 2);

		grid.createCell(2, 0);

		std::vector<Cell> neighborList = grid.countNeighbors(2, 1);
		int neighborCount = neighborList.size();

		EXPECT_EQ(expectedNeighbors, neighborCount);
	}

	TEST(GridTest, CreateCell)
	{
		Grid grid(3, 2);

		grid.createCell(2, 0);

		std::vector<std::vector<Cell>> const& cells = grid.getCells();

		EXPECT_EQ(cells[2][0].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
	}

	TEST(GridTest, KillCell)
	{
		Grid grid(3, 2);

		grid.createCell(2, 0);
		grid.killCell(2, 0);

		std::vector<std::vector<Cell>> const& cells = grid.getCells();

		EXPECT_EQ(cells[2][0].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
	}
}
