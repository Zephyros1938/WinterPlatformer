#pragma once

struct GameTime {
    double delta; // Seconds since previous frame
    double total; // Seconds since the start of the program

    GameTime(double deltaSeconds, double totalSeconds)
        : delta(deltaSeconds), total(totalSeconds) {}
};
