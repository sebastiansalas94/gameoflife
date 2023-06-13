// (c) Cheva's Game of Life
#pragma once
#include "Grid.h"
#include "IRule.h"
#include "RuleProximity.h"
#include <vector>
#include <memory>

using gol::lib::core::engine::factory::IRule;

namespace gol::lib::core::engine
{
	class Engine
	{
	public:
		Engine(int width, int height, std::vector<std::unique_ptr<IRule>> rules);
		//Engine(Engine const& engine);
		~Engine() = default;

		
		//Move Assign
		Engine& operator=(Engine&& engineRValue) {
			this->mWidth = engineRValue.mWidth;
			this->mHeight = engineRValue.mHeight;
			this->mGrid = std::move(engineRValue.mGrid);
			this->mNextGenerationGrid = std::move(engineRValue.mNextGenerationGrid);
			this->mRules = std::move(engineRValue.mRules);
			return *this;
		};
		
		//Move Constructor
		Engine(Engine&& engineRValue)
			: mWidth(engineRValue.mWidth),
			  mHeight(engineRValue.mHeight),
			  mGrid(std::move(engineRValue.mGrid)),
			  mNextGenerationGrid(std::move(engineRValue.mNextGenerationGrid)),
			  mRules(std::move(engineRValue.mRules)){};
		
		void createCell(int i, int j);
		void processNextGeneration();
		Grid& getGrid() { return mGrid; };
		void printGrid();

	private:
		int mWidth;
		int mHeight;
		Grid mGrid;
		Grid mNextGenerationGrid;
		std::vector<std::unique_ptr<IRule>> mRules;
	
		//void processNextGeneration();	
	};
} // namespace gol::lib::core::engine
