// (c) Cheva's Game of Life
#pragma once

#include "Cell.h"
#include <vector>

namespace gol::lib::core::engine::factory
{
    class IRule
    {
    public:
        IRule() = default;
        virtual ~IRule() = default;

        virtual bool execute(Cell const& cell, std::vector<Cell> const& neighborsCells) = 0;
    };
} // gol::lib::core::engine::factory
