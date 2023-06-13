// (c) Cheva's Game of Life
#include "core/engine/Engine.h"

namespace gol::lib::core::engine
{
Engine::Engine(int pWidth, int pHeight, std::vector<std::unique_ptr<IRule>> pRules)
	: mWidth(pWidth),
	mHeight(pHeight),
	mGrid(pWidth, pHeight),
	mNextGenerationGrid(pWidth, pHeight),
	mRules(std::move(pRules))
{
}

void Engine::processNextGeneration()
{
	int counterNeighbors = 0;
	std::vector<std::vector<Cell>> const& cells = mGrid.getCells();

	for (int i = 0; i < mWidth; ++i)
	{
		for (int j = 0; j < mHeight; ++j)
		{	
			std::vector<Cell> neighborList = mGrid.countNeighbors(i, j);
			
			for (std::unique_ptr<IRule>& r : mRules)
			{
				bool shouldLive = r->execute(cells[i][j], neighborList);
				if (shouldLive)
				{
					mNextGenerationGrid.createCell(i, j);
				}
				else
				{
					mNextGenerationGrid.killCell(i, j);
				}
			}			
		}
	}

	mGrid = std::move(mNextGenerationGrid);
	mNextGenerationGrid = Grid(mWidth, mHeight);
}

void Engine::printGrid()
{
	std::vector<std::vector<Cell>> const& cells = mGrid.getCells();
	for (int i = 0; i < mWidth; ++i)
	{
		for (int j = 0; j < mHeight; ++j)
		{
			int state = cells[i][j].getState() == gol::lib::core::engine::CellState::STATE_ALIVE ? 1 : 0 ;
			printf("%d", state);
		}
		printf("\n");
	}
	printf("------------\n");
}

} // namespace gol::lib::core::engine