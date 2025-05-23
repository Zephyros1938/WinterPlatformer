#pragma once

#include "WindowBase.hpp"
#include "Time.hpp"

class Window : public WindowBase {
public:
    explicit Window(WindowHints hints = WindowHints::Default());

    virtual void onInit();
    virtual void onUpdate(double dt);
    virtual void processInput(double dt);
    virtual void onRender();
    virtual void onInput();

    virtual void onResize(int width, int height);

    void run();

protected:
    Time timer;
};
