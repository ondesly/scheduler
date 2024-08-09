//
//  scheduler.hpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#pragma once

#include <memory>
#include <unordered_set>

#include "scheduler/schedule_handler.hpp"

namespace dtor {
    class scheduler;

    class scheduler_impl {
        friend schedule_handler;
        friend scheduler;

    private:
        void update(float delta) const;

        void schedule(schedule_handler *handler);
        void unschedule(schedule_handler *handler);

    private:
        std::unordered_set<schedule_handler *> m_handlers;

    };
}

namespace dtor {

    class scheduler {
    public:
        scheduler();

        void update(float delta) const;

        std::shared_ptr<schedule_handler> schedule(const schedule_handler::callback_t &callback, float interval);

    private:
        static std::shared_ptr<scheduler_impl> s_impl;
        std::shared_ptr<scheduler_impl> m_impl;

    };
}
