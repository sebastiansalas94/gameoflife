// (c) Cheva's Game of Life
#pragma once

#include "IActionFactory.h"
#include "core/director/IAction.h"
#include "core/director/ActionStart.h"
#include "core/director/ActionStop.h"
#include <memory>

namespace gol::lib::core::director::factory
{
    class ActionFactory
    {
    public:
        ActionFactory() = default;
        ~ActionFactory() = default;

        std::unique_ptr<IAction> createActionStart();
        std::unique_ptr<IAction> createActionStop();
    };
} // gol::lib::core::engine::factory
