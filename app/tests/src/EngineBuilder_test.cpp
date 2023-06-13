// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/engine/builder/EngineBuilder.h"
#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"


using namespace gol::lib::core::engine::builder;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	std::vector<std::unique_ptr<IRule>> initRulesForEB()
	{
		std::vector<std::unique_ptr<IRule>> rules;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();
		rules.emplace_back(std::move(ruleProx));
		return rules;
	}

	TEST(EngineBuilderTest, EngineBuilderCreation)
	{
		int expectedWidth = 2;
		int expectedHeight = 2;
		int expectedRulesSize = 1;
		EngineBuilder engineBuilder(2, 2, initRulesForEB());
		EXPECT_EQ(engineBuilder.getWidth(), expectedWidth);
		EXPECT_EQ(engineBuilder.getHeight(), expectedHeight);
		EXPECT_EQ(engineBuilder.getRules().size(), expectedRulesSize);
		//EXPECT_TRUE(engineBuilder != NULL);
	}

	TEST(EngineBuilderTest, CreateEngine)
	{
		EngineBuilder engineBuilder(2, 2, initRulesForEB());
		std::unique_ptr<Engine> engine = engineBuilder.createEngine();
		EXPECT_TRUE(engine != nullptr);
	}
}
