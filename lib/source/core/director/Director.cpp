// (c) Cheva's Game of Life
#include "core/director/Director.h"

namespace gol::lib::core::director
{
	Director::Director(std::unique_ptr<engine::Engine> engine)
		: mEngine(std::move(engine))
	{
	}
} // namespace gol::lib::core::director
