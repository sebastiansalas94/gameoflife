// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/engine/Cell.h"

using gol::lib::core::engine::Cell;

namespace gol::test
{
	TEST(CellTest, CellCreation)
	{
		Cell cell = Cell();

		EXPECT_EQ(cell.getState(), gol::lib::core::engine::CellState::STATE_DEAD);
	}

	TEST(CellTest, CreateCell)
	{
		Cell cell = Cell();
		cell.createCell();

		EXPECT_EQ(cell.getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
	}

	TEST(CellTest, KillCell)
	{
		Cell cell = Cell();
		cell.createCell();
		cell.killCell();

		EXPECT_EQ(cell.getState(), gol::lib::core::engine::CellState::STATE_DEAD);
	}

	TEST(CellTest, CreateKillCreateCell)
	{
		Cell cell = Cell();
		cell.createCell();
		cell.killCell();
		cell.createCell();

		EXPECT_EQ(cell.getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
	}
}
