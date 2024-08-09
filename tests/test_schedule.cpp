//
//  test_schedule.hpp
//  scheduler
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 09.08.2024.
//  Copyright © 2024 Dmitrii Torkhov. All rights reserved.
//

#include <cassert>

#include <scheduler/scheduler.hpp>

int main() {
    // Once
    {
        std::vector<size_t> values;

        auto handler = dtor::scheduler{}.once(5.0F, [&values]() {
            values.push_back(2);
        });

        // Not enough
        dtor::scheduler{}.update(4.0F);
        assert(values.empty());

        // Call
        dtor::scheduler{}.update(4.0F);
        assert(values.size() == 1);

        // Call
        dtor::scheduler{}.update(4.0F);
        assert(values.size() == 1);

        // No handler
        handler = nullptr;
        dtor::scheduler{}.update(5.0F);
        assert(values.size() == 1);
    }

    // Not once
    {
        std::vector<size_t> values;

        auto handler = dtor::scheduler{}.once(5.0F, [&values]() {
            values.push_back(2);
        });

        // Not enough
        dtor::scheduler{}.update(4.0F);
        assert(values.empty());

        // No handler
        handler = nullptr;
        dtor::scheduler{}.update(5.0F);
        assert(values.empty());
    }

    // Endlessly
    {
        std::vector<size_t> values;

        auto handler = dtor::scheduler{}.repeat(5.0F, [&values]() {
            values.push_back(2);
        });

        // Not enough
        dtor::scheduler{}.update(4.0F);
        assert(values.empty());

        // Call
        dtor::scheduler{}.update(4.0F);
        assert(values.size() == 1);

        // Call
        dtor::scheduler{}.update(4.0F);
        assert(values.size() == 2);

        // No handler
        handler = nullptr;
        dtor::scheduler{}.update(5.0F);
        assert(values.size() == 2);
    }

    return 0;
}
