// (c) Cheva's Game of Life
#pragma once

#include "Cell.h"
#include <vector>

namespace gol::app::core::engine::factory
{
    class IRule
    {
    public:
        virtual ~IRule() = default;
        virtual void execute(Cell cell, std::vector<Cell> neighborsCells);
    };
} // gol::app::core::engine::factory
