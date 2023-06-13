// (c) Cheva's Game of Life
#pragma once

#include "ActionBase.h"

namespace gol::lib::core::director
{
    class ActionStop : public ActionBase
    {
    public:
        ActionStop();
        ~ActionStop() {};

        void execute();
    };

} // gol::lib::core::director