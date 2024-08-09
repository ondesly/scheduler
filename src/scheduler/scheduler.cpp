//
//  scheduler.cpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#include "scheduler/scheduler.hpp"

void dtor::scheduler_impl::update(const float delta) {
    if (!m_handlers_to_add.empty()) {
        for (const auto handler : m_handlers_to_add) {
            m_handlers.insert(handler);
        }
        m_handlers_to_add.clear();
    }
    if (!m_handlers_to_remove.empty()) {
        for (const auto handler : m_handlers_to_remove) {
            m_handlers.erase(handler);
        }
        m_handlers_to_remove.clear();
    }

    for (const auto handler : m_handlers) {
        handler->update(delta);
    }
}

void dtor::scheduler_impl::schedule(dtor::schedule_handler *handler) {
    m_handlers_to_add.push_back(handler);
}

void dtor::scheduler_impl::unschedule(schedule_handler *handler) {
    m_handlers_to_remove.push_back(handler);
}

std::shared_ptr<dtor::scheduler_impl> dtor::scheduler::s_impl = nullptr;

dtor::scheduler::scheduler() :
    m_impl(s_impl ? s_impl : (s_impl = std::make_unique<scheduler_impl>())) {
}

void dtor::scheduler::update(const float delta) const {
    m_impl->update(delta);
}

dtor::schedule_handler_ptr dtor::scheduler::once(float interval,
                                                 const schedule_handler::callback_t &callback) {
    return std::make_unique<schedule_handler>(m_impl, interval, callback, repeat_type::once);
}

dtor::schedule_handler_ptr dtor::scheduler::repeat(float interval,
                                                      const schedule_handler::callback_t &callback) {
    return std::make_unique<schedule_handler>(m_impl, interval, callback, repeat_type::repeat);
}
