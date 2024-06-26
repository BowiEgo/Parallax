#pragma once

#include "Parallax/Input.h"

namespace Parallax {
    class MacInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual bool GetMouseXImpl() override;
        virtual bool GetMouseYImpl() override;
    };
}