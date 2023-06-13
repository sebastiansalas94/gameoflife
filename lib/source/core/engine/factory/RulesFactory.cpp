// (c) Cheva's Game of Life
#include "core/engine/factory/RulesFactory.h"

namespace gol::lib::core::engine::factory
{

std::unique_ptr<RuleProximity> RulesFactory::createProximityRule()
{
	return std::make_unique<RuleProximity>();
}

} // gol::lib::core::engine::factory
