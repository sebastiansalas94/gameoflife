// (c) Cheva's Game of Life
#include "core/director/factory/ActionFactory.h"

namespace gol::lib::core::director::factory
{

std::unique_ptr<IAction> ActionFactory::createActionStart()
{
	return std::make_unique<ActionStart>();
}

std::unique_ptr<IAction> ActionFactory::createActionStop()
{
	return std::make_unique<ActionStop>();
}

} // gol::lib::core::director::factory
