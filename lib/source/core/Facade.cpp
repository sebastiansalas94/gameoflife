// (c) Cheva's Game of Life
#include "core/Facade.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

namespace gol::lib::core
{
Facade::Facade()
{
    readConfig();
	createRules();
	createEngineBuilder();
	createEngine();
    createDirectorBuilder();
}

void Facade::createEngineBuilder()
{
	mEngineBuilder = std::make_unique<EngineBuilder>(mHeight, mWidth, std::move(mRules));
}

void Facade::createEngine()
{
	mEngine = mEngineBuilder->createEngine();
}

void Facade::createRules()
{
	mRules.emplace_back(mRulesFactory.createProximityRule());
}

void Facade::createDirectorBuilder()
{
    mDirectorBuilder = std::make_unique<DirectorBuilder>(std::move(mEngine));
}

void Facade::readConfig() 
{
    //TODO: Reemplazar a constante
    std::ifstream cFile("config.txt");

    if (cFile.is_open())
    {
        std::string line;
        while (std::getline(cFile, line))
        {
            auto equalPosition = line.find("=");
            auto name = line.substr(0, equalPosition);
            auto value = line.substr(equalPosition + 1);
            if (name == "grid.height")
            {
                mHeight = stoi(value);
            }
            else if (name == "grid.width")
            {
                mWidth = stoi(value);
            }
        }
    }
}

} // namespace gol::lib::core
