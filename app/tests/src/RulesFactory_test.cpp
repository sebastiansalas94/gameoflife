// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/engine/factory/RulesFactory.h"

using namespace gol::lib::core::engine;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	TEST(RulesFactoryTest, CreateProximityRule)
	{
		RulesFactory rulesFactory;
		std::unique_ptr<RuleProximity> ruleProx = rulesFactory.createProximityRule();
		EXPECT_TRUE(ruleProx != nullptr);
	}
}
