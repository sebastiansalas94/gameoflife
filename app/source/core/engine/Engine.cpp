// (c) Cheva's Game of Life
#include "Engine.h"

namespace gol
{
namespace app
{
Engine::Engine(int width, int height)
{
	init(width, height);
}

void init()
{
	grid = new Grid(width, height)
}

int processNextGeneration()
{
	int counterNeighbors = 0;
	

}

} // namespace app
} // namespace gol
