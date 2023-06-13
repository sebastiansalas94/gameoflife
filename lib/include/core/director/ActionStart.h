// (c) Cheva's Game of Life
#pragma once

#include "ActionBase.h"

namespace gol::lib::core::director
{
    class ActionStart : public ActionBase
    {
    public:
        ActionStart();
        ~ActionStart() {};

        void execute();
    };
	
} // gol::lib::core::director
