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

    class schedule_handler {
    public:
        using callback_t = std::function<void()>;

    public:
        schedule_handler(std::shared_ptr<scheduler_impl> impl, const std::function<void()> &callback, float interval);
        ~schedule_handler();

        void update(float delta);

    private:
        std::shared_ptr<scheduler_impl> m_impl;

        const callback_t m_callback;
        const float m_interval;
        float m_elapsed = 0.0F;
    };
}
