// (c) Cheva's Game of Life
#pragma once
#include "IRule.h"
#include "Cell.h"
#include <vector>

namespace gol::lib::core::engine
{
    class RuleProximity: public gol::lib::core::engine::factory::IRule
    {
    public:
        RuleProximity();
        ~RuleProximity() {};

        /*
        //Move Assign
        RuleProximity& operator=(RuleProximity&& ruleProxRValue) {
            return *this;
        };

        //Move Constructor
        RuleProximity(RuleProximity&& ruleProxRValue){};

        RuleProximity(RuleProximity& ruleProxCopy) {};*/

        bool execute(Cell const& cell, std::vector<Cell> const&  neighborsCells);
    };
} // gol::lib::core::engine
