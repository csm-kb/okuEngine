#ifndef OKUENGINE_INPUT_H
#define OKUENGINE_INPUT_H

#include <okuEngine/types.hpp>

namespace okuEngine {
    namespace Input {
    /**
     * @brief Enum containing all pressable keys on the keyboard.
     */
    enum class Keys {
        Backspace = 0x00,
        Tab,Clear,Enter,
        // modifier keys
        Shift,Control,Alt,
        Pause,
        CapsLock,
        Escape,
        // spacebar
        Space,
        // the six-stack above the arrow keys
        PageUp,PageDown,End,
        Home,Insert,Delete,
        // arrow keys
        Left,Up,Right,Down,
        Select,
        Execute,
        PrintScreen,
        Help,
        // numbers above the letters
        Alpha0,Alpha1,Alpha2,
        Alpha3,Alpha4,Alpha5,
        Alpha6,Alpha7,Alpha8,Alpha9,
        // letters
        A,B,C,D,E,F,G,H,I,J,K,L,M,
        N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
        // other keys
        LeftWinKey,
        RightWinKey,
        AppKey,
        Sleep,
        // numpad keys
        NumPad0,NumPad1,NumPad2,
        NumPad3,NumPad4,NumPad5,
        NumPad6,NumPad7,NumPad8,NumPad9,
        Multiply,Add,Separator,Subtract,Decimal,Divide,
        // function keys
        F1,F2,F3,F4,F5,F6,
        F7,F8,F9,F10,F11,F12,
        F13,F14,F15,F16,F17,F18,
        F19,F20,F21,F22,F23,F24,
        // more keys
        NumLock,
        ScrollLock,
        LeftShift,
        RightShift,
        LeftControl,
        RightContol,
        LeftMenu,
        RightMenu,
        VolumeMute,
        VolumeDown,
        VolumeUp,
        NextTrack,
        PreviousTrack,
        StopMedia,
        PlayPause,
        LaunchMail,
        SelectMedia,
        _MAXVALUE // used for array allocation -- DO NOT TOUCH, will not trigger
    };

    enum class Mouse {
        LeftButton = 0x01, MiddleButton, RightButton,
        X1, X2,
        _MAXVALUE // used for array allocation -- DO NOT TOUCH, will not trigger
    };
    }

    class IInputHandler {
    public:
        virtual void ProcessInput() = 0;

        // TODO: use an input manager to:
            // name buttons and map them to keys
            // name axes and map them to keys or variable inputs (mouse)

        /**
         * @brief Get whether the given Key is currently pressed down (held).
         * @param key the Input::Keys enum corresponding to a keyboard key.
         */
        virtual bool GetKey(Input::Keys key) = 0;
        /**
         * @brief Returns true the frame that a key is pressed.
         * The state resets internally after every frame.
         * @param key the Input::Keys enum corresponding to a keyboard key.
         */
        virtual bool GetKeyDown(Input::Keys key) = 0;
        /**
         * @brief Returns true the frame that a key is released.
         * The state resets internally after every frame.
         * @param key the Input::Keys enum corresponding to a keyboard key.
         */
        virtual bool GetKeyUp(Input::Keys key) = 0;
        /**
         * @brief Get whether the given mouse button is currently pressed down (held).
         * @param btn the Input::Mouse enum corresponding to a keyboard key.
         */
        virtual bool GetMouseButton(Input::Mouse btn) = 0;
        /**
         * @brief Returns true the frame that a mouse button is pressed.
         * @param btn the Input::Mouse enum corresponding to a mouse button.
         */
        virtual bool GetMouseButtonDown(Input::Mouse btn) = 0;
        /**
         * @brief Returns true the frame that a mouse button is released.
         * @param btn the Input::Mouse enum corresponding to a keyboard key.
         */
        virtual bool GetMouseButtonUp(Input::Mouse btn) = 0;
        /**
         * @brief Returns true the frame that a mouse button is released.
         * @param axis the name of a labeled axis.
         * @return a float in the range [-1,1] for non-mouse axes, or a mouse delta.
         */
        virtual float GetAxis(std::string axis) = 0;

        virtual void RegisterKeyInputListener() = 0;
        virtual void RegisterMouseButtonListener() = 0;
        virtual void RegisterMouseMotionListener() = 0;
        virtual void UnregisterKeyInputListener() = 0;
        virtual void UnregisterMouseButtonListener() = 0;
        virtual void UnregisterMouseMotionListener() = 0;
    };

    class InputHandler final : public IInputHandler {
    public:
        void ProcessInput() override;

        bool GetKey(Input::Keys key) override;
        bool GetKeyDown(Input::Keys key) override;
        bool GetKeyUp(Input::Keys key) override;

        bool GetMouseButton(Input::Mouse btn) override;
        bool GetMouseButtonDown(Input::Mouse btn) override;
        bool GetMouseButtonUp(Input::Mouse btn) override;

        float GetAxis(std::string axis) override;

        void RegisterKeyInputListener() override;
        void RegisterMouseButtonListener() override;
        void RegisterMouseMotionListener() override;
        void UnregisterKeyInputListener() override;
        void UnregisterMouseButtonListener() override;
        void UnregisterMouseMotionListener() override;
    private:
        static const oMap<int,Input::Keys> sdlToKeyMap;
        /** Flags in this array are set while a key is held. */
        oArray<bool,(int)Input::Keys::_MAXVALUE> _KEYS_HELD;
        /** Flags in this array are set only for the frame a key is pressed. */
        oArray<bool,(int)Input::Keys::_MAXVALUE> _KEYS_DOWN;
        /** Flags in this array are set only for the frame a key is released. */
        oArray<bool,(int)Input::Keys::_MAXVALUE> _KEYS_UP;
        /** Flags in this array are set while a mouse button is held. */
        oArray<bool,(int)Input::Mouse::_MAXVALUE> _MOUSE_HELD;
        /** Flags in this array are set only for the frame a mouse button is pressed. */
        oArray<bool,(int)Input::Mouse::_MAXVALUE> _MOUSE_DOWN;
        /** Flags in this array are set only for the frame a mouse button is released. */
        oArray<bool,(int)Input::Mouse::_MAXVALUE> _MOUSE_UP;
    };

}

#endif