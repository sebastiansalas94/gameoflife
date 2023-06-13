// (c) Cheva's Game of Life
#include "core/director/builder/DirectorBuilder.h"

namespace gol::lib::core::director::builder
{
DirectorBuilder::DirectorBuilder(std::unique_ptr<engine::Engine> engine)
	: mEngine (std::move(engine))
{
}

std::unique_ptr<Director> DirectorBuilder::createDirector()
{
	return std::make_unique<Director>(std::move(mEngine)); 
}

} // namespace gol::lib::core::director::builder
