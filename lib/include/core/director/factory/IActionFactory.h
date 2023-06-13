// (c) Cheva's Game of Life
#pragma once

#include <memory>

#include "core/director/ActionStart.h"
#include "core/director/ActionStop.h"

namespace gol::app::core::director::factory
{
    class IActionFactory
    {
    public:
        virtual ~IActionFactory() = default;
        virtual void execute();

        std::unique_ptr<gol::lib::core::director::ActionStart> createActionStart();
        std::unique_ptr<gol::lib::core::director::ActionStop> createActionStop();
    };
} // gol::app::core::director::factory
