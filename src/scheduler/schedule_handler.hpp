//
//  schedule_handler.hpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#pragma once

#include <functional>
#include <memory>

namespace dtor {
    class scheduler_impl;

    enum class repeat_type {
        once,
        repeat,
    };

    class schedule_handler {
    public:
        using callback_t = std::function<void()>;

    public:
        schedule_handler(std::shared_ptr<scheduler_impl> impl, float interval, const std::function<void()> &callback,
                         repeat_type repeat);
        ~schedule_handler();

        void update(float delta);

    private:
        std::shared_ptr<scheduler_impl> m_impl;

        const float m_interval;
        const callback_t m_callback;
        const repeat_type m_repeat;
        float m_elapsed = 0.0F;
    };

    using schedule_handler_ptr = std::unique_ptr<schedule_handler>;
}
