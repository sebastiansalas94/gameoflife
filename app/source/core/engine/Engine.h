// (c) Cheva's Game of Life
#pragma once
#include "Grid.h"

namespace gol
{
namespace app
{

class Engine
{
public:
    Engine(int width, int height);
    ~Engine() override = default;

	void createCell(int i, int j);
	
private:
	Grid grid;
	Grid nextGenerationGrid;
	//List<IRule> rules;
	int width;	
	int height;
	
	void init();
	void processNextGeneration();

} // namespace app
} // namespace gol
