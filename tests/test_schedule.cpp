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
    std::vector<size_t> values;
    auto handler = dtor::scheduler{}.schedule([&values]() {
        values.push_back(2);
    }, 5.0F);

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

    return 0;
}
