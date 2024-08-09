//
//  schedule_handler.cpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#include <utility>

#include "scheduler/schedule_handler.hpp"
#include "scheduler/scheduler.hpp"

dtor::schedule_handler::schedule_handler(std::shared_ptr<scheduler_impl> impl, const float interval,
                                         const std::function<void()> &callback, const repeat_type repeat) :
    m_impl(std::move(impl)), m_interval(interval), m_callback(callback), m_repeat(repeat) {
    m_impl->schedule(this);
}

dtor::schedule_handler::~schedule_handler() {
    m_impl->unschedule(this);
}

void dtor::schedule_handler::update(const float delta) {
    m_elapsed += delta;

    if (m_elapsed > m_interval) {
        m_elapsed -= m_interval;
        m_callback();

        if (m_repeat == repeat_type::once) {
            m_impl->unschedule(this);
        }
    }
}
