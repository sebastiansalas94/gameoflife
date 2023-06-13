// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"
#include "core/engine/Cell.h"

using gol::lib::core::engine::Cell;

using namespace gol::lib::core;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	TEST(RuleProximityTest, Execute_0)
	{
		bool expectedResult = false;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		std::vector<Cell> cells;

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_1)
	{
		bool expectedResult = false;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		std::vector<Cell> cells;
		cells.push_back(originalCell);

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_2_DEAD)
	{
		bool expectedResult = false;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		std::vector<Cell> cells;
		cells.push_back(originalCell);
		cells.push_back(originalCell);

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_2_ALIVE)
	{
		bool expectedResult = true;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		originalCell.createCell();
		std::vector<Cell> cells;
		cells.push_back(originalCell);
		cells.push_back(originalCell);

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_3_ALIVE)
	{
		bool expectedResult = true;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		originalCell.createCell();
		std::vector<Cell> cells;
		cells.push_back(originalCell);
		cells.push_back(originalCell);
		cells.push_back(originalCell);

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_3_DEAD)
	{
		bool expectedResult = true;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		std::vector<Cell> cells;
		cells.push_back(originalCell);
		cells.push_back(originalCell);
		cells.push_back(originalCell);

		bool ruleResult = ruleProx->execute(originalCell, cells);
		EXPECT_EQ(expectedResult, ruleResult);
	}

	TEST(RuleProximityTest, Execute_More_Than_4)
	{
		bool expectedResult = false;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();

		Cell originalCell = Cell();
		std::vector<Cell> cells;
		for (int i = 0; i < 10; ++i)
		{
			cells.push_back(originalCell);

			if (cells.size() >= 4)
			{
				bool ruleResult = ruleProx->execute(originalCell, cells);
				EXPECT_EQ(expectedResult, ruleResult);
			}
		}
	}
}