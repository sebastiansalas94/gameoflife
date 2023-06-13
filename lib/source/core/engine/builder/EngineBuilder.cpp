// (c) Cheva's Game of Life
#include "core/engine/builder/EngineBuilder.h"
#include <core/engine/Engine.h>

namespace gol::lib::core::engine::builder
{

//TODO: Definir como pasarle las reglas
EngineBuilder::EngineBuilder(int pWidth, int pHeight, std::vector<std::unique_ptr<IRule>> pRules)
	: mWidth(pWidth),
	  mHeight(pHeight),
	  mRules(std::move(pRules))
{
}

std::unique_ptr<Engine> EngineBuilder::createEngine()
{
	return std::make_unique<Engine>(mWidth, mHeight, std::move(mRules));
}

} // namespace gol::app::core::engine::builder
