// (c) Cheva's Game of Life
#pragma once

#include "core/director/IAction.h"

namespace gol::lib::core::director
{
    class ActionBase : public gol::lib::core::director::IAction
    {
    public:
        ActionBase() = default;
        virtual ~ActionBase() = default;

        virtual void execute() = 0;

        private:
            //IDistributor mIDistributor;
    };
	
} // gol::lib::core::director
