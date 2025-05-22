#pragma once

#include "WindowBase.hpp"
#include "Time.hpp"

class Window : public WindowBase {
public:
    explicit Window(WindowHints hints = WindowHints::Default());

    virtual void onInit();
    virtual void onUpdate(double dt);
    virtual void onRender();
    virtual void onInput();

    void run();

protected:
    Time timer;
};
