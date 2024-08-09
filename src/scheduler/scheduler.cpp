//
//  scheduler.cpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#include "scheduler/scheduler.hpp"

void dtor::scheduler_impl::update(const float delta) const {
    for (const auto handler : m_handlers) {
        handler->update(delta);
    }
}

void dtor::scheduler_impl::schedule(dtor::schedule_handler *handler) {
    m_handlers.insert(handler);
}

void dtor::scheduler_impl::unschedule(schedule_handler *handler) {
    m_handlers.erase(handler);
}

std::shared_ptr<dtor::scheduler_impl> dtor::scheduler::s_impl = nullptr;

dtor::scheduler::scheduler() :
    m_impl(s_impl ? s_impl : (s_impl = std::make_unique<scheduler_impl>())) {
}

void dtor::scheduler::update(const float delta) const {
    m_impl->update(delta);
}

std::shared_ptr<dtor::schedule_handler> dtor::scheduler::schedule(const schedule_handler::callback_t &callback,
                                                                  float interval) {
    return std::make_shared<schedule_handler>(m_impl, callback, interval);
}
