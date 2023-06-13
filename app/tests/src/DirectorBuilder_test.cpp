// (c) Cheva's Game of Life
#include <gtest/gtest.h>
#include "core/director/builder/DirectorBuilder.h"
#include "core/engine/builder/EngineBuilder.h"
#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"

using namespace gol::lib::core::director::builder;
using namespace gol::lib::core::engine::builder;
using namespace gol::lib::core::engine::factory;

namespace gol::test
{
	std::vector<std::unique_ptr<IRule>> initRulesForDB()
	{
		std::vector<std::unique_ptr<IRule>> rules;
		RulesFactory rulesFactory;
		std::unique_ptr<gol::lib::core::engine::RuleProximity> ruleProx = rulesFactory.createProximityRule();
		rules.emplace_back(std::move(ruleProx));
		return rules;
	}

	TEST(DirectorBuilderTest, DirectorBuilderCreation)
	{
		EngineBuilder engineBuilder(2, 2, initRulesForDB());
		std::unique_ptr<Engine> engine = engineBuilder.createEngine();
		DirectorBuilder directorBuilder(std::move(engine));

		EXPECT_TRUE(directorBuilder.getEngine() != nullptr);
	}

	TEST(DirectorBuilderTest, CreateDirector)
	{
		EngineBuilder engineBuilder(2, 2, initRulesForDB());
		std::unique_ptr<Engine> engine = engineBuilder.createEngine();
		DirectorBuilder directorBuilder(std::move(engine));
		std::unique_ptr<Director> director = directorBuilder.createDirector();
		EXPECT_TRUE(director != nullptr);
		EXPECT_TRUE(directorBuilder.getEngine() == nullptr);
	}
}
