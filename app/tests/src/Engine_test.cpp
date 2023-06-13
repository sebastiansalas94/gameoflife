// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/Facade.h"
#include "core/engine/Engine.h"
#include "core/engine/Grid.h"
#include "core/engine/Cell.h"
#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"

using namespace gol::lib::core;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	std::vector<std::unique_ptr<IRule>> initRules()
	{
		std::vector<std::unique_ptr<IRule>> rules;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();
		rules.emplace_back(std::move(ruleProx));
		return rules;
	}

	TEST(EngineTest, ProcessNextGen)
	{
		gol::lib::core::engine::Engine engine(1, 1, initRules());
		engine.printGrid();
		engine.processNextGeneration();
		engine.printGrid();
		gol::lib::core::engine::Grid const& grid = engine.getGrid();
		std::vector<std::vector<gol::lib::core::engine::Cell>> cells = grid.getCells();
		EXPECT_EQ(cells[0][0].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
	}

	TEST(EngineTest, ProcessNextGen_2_2)
	{
		gol::lib::core::engine::Engine engine(2, 2, initRules());
		gol::lib::core::engine::Grid& grid = engine.getGrid();
		grid.createCell(1, 1);
		grid.createCell(0, 0);
		grid.createCell(1, 0);

		engine.printGrid();
		engine.processNextGeneration();
		engine.printGrid();
		gol::lib::core::engine::Grid& gridNextGen = engine.getGrid();
		std::vector<std::vector<gol::lib::core::engine::Cell>> cells = gridNextGen.getCells();
		EXPECT_EQ(cells[0][1].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
	}

	TEST(EngineTest, ProcessNextGen_9_6)
	{
		gol::lib::core::engine::Engine engine(9, 6, initRules());
		gol::lib::core::engine::Grid& grid = engine.getGrid();
		grid.createCell(8, 0);
		grid.createCell(3, 1);
		grid.createCell(7, 1);
		grid.createCell(1, 2);
		grid.createCell(6, 2);
		grid.createCell(2, 3);
		grid.createCell(5, 3);
		grid.createCell(7, 3);
		grid.createCell(6, 4);

		engine.printGrid();
		engine.processNextGeneration();
		engine.printGrid();
		gol::lib::core::engine::Grid& gridNextGen = engine.getGrid();
		std::vector<std::vector<gol::lib::core::engine::Cell>> cells = gridNextGen.getCells();
		EXPECT_EQ(cells[2][2].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
		EXPECT_EQ(cells[7][2].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
		EXPECT_EQ(cells[8][0].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
	}

	TEST(EngineTest, Process2NextGen_9_6)
	{
		gol::lib::core::engine::Engine engine(9, 6, initRules());
		gol::lib::core::engine::Grid& grid = engine.getGrid();
		grid.createCell(8, 0);
		grid.createCell(3, 1);
		grid.createCell(7, 1);
		grid.createCell(1, 2);
		grid.createCell(6, 2);
		grid.createCell(2, 3);
		grid.createCell(5, 3);
		grid.createCell(7, 3);
		grid.createCell(6, 4);

		engine.printGrid();
		engine.processNextGeneration();
		engine.printGrid();
		engine.processNextGeneration();
		engine.printGrid();
		gol::lib::core::engine::Grid& gridNextGen = engine.getGrid();
		std::vector<std::vector<gol::lib::core::engine::Cell>> cells = gridNextGen.getCells();
		EXPECT_EQ(cells[1][2].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
		EXPECT_EQ(cells[2][2].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
		EXPECT_EQ(cells[2][3].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
		EXPECT_EQ(cells[3][1].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
		EXPECT_EQ(cells[6][1].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
		EXPECT_EQ(cells[6][2].getState(), gol::lib::core::engine::CellState::STATE_DEAD);
		EXPECT_EQ(cells[7][2].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
		EXPECT_EQ(cells[8][2].getState(), gol::lib::core::engine::CellState::STATE_ALIVE);
	}
}