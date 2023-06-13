// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/Facade.h"
#include "core/engine/Engine.h"

#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"

using namespace gol::lib::core;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	std::vector<std::unique_ptr<IRule>> initRulesForD()
	{
		std::vector<std::unique_ptr<IRule>> rules;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();
		rules.emplace_back(std::move(ruleProx));
		return rules;
	}

	TEST(DirectorTest, DirectorCreation)
	{
		EngineBuilder engineBuilder(2, 2, initRulesForD());
		std::unique_ptr<Engine> engine = engineBuilder.createEngine();
		DirectorBuilder directorBuilder(std::move(engine));
		std::unique_ptr<Director> director = directorBuilder.createDirector();

		EXPECT_TRUE(director != nullptr);
		EXPECT_TRUE(director->getEngine() != nullptr);
	}
}