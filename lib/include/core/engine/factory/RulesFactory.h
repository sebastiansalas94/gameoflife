// (c) Cheva's Game of Life
#pragma once

#include "core/engine/IRule.h"
#include "core/engine/RuleProximity.h"
#include <memory>

namespace gol::lib::core::engine::factory
{
    class RulesFactory
    {
    public:
        RulesFactory() = default;
        ~RulesFactory() = default;

        std::unique_ptr<RuleProximity> createProximityRule();
    };
} // gol::lib::core::engine::factory
