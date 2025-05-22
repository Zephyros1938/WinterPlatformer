#pragma once
#include <functional>
#include "GameTime.hpp"

class Time {
public:
    using ClockFunction = std::function<double()>;

    explicit Time(ClockFunction clockFunc)
        : _clock(clockFunc), _start(_clock()), _last(_start),
          delta(0.0), total(0.0) {}

    GameTime tick() {
        double now = _clock();
        delta = now - _last;
        total = now - _start;
        _last = now;
        return GameTime(delta, total);
    }

    double getDelta() const { return delta; }
    double getTotal() const { return total; }

private:
    ClockFunction _clock;
    double _start;
    double _last;
    double delta;
    double total;
};
