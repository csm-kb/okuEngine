#include <SDL2/SDL.h>

#include <okuEngine/input.hpp>
#include <okuEngine/core.hpp>
#include <okuEngine/debug.hpp>

namespace okuEngine {
    // need to map SDL to our internal input system
    
    const std::map<int,Input::Keys> InputHandler::sdlToKeyMap = {
        {SDLK_BACKSPACE, Input::Keys::Backspace},
        {SDLK_TAB, Input::Keys::Tab},
        {SDLK_CLEAR, Input::Keys::Clear},
        {SDLK_RETURN, Input::Keys::Enter},
        {SDLK_LSHIFT | SDLK_RSHIFT, Input::Keys::Shift},
        {SDLK_LCTRL | SDLK_RCTRL, Input::Keys::Control},
        {SDLK_LALT | SDLK_RALT, Input::Keys::Alt},
        {SDLK_PAUSE, Input::Keys::Pause},
        {SDLK_CAPSLOCK, Input::Keys::CapsLock},
        {SDLK_ESCAPE, Input::Keys::Escape},
        {SDLK_SPACE, Input::Keys::Space},
        {SDLK_PAGEUP, Input::Keys::PageUp},
        {SDLK_PAGEDOWN, Input::Keys::PageDown},
        {SDLK_END, Input::Keys::End},
        {SDLK_HOME, Input::Keys::Home},
        {SDLK_LEFT, Input::Keys::Left},
        {SDLK_UP, Input::Keys::Up},
        {SDLK_RIGHT, Input::Keys::Right},
        {SDLK_DOWN, Input::Keys::Down},
        {SDLK_SELECT, Input::Keys::Select},
        {SDLK_EXECUTE, Input::Keys::Execute},
        {SDLK_PRINTSCREEN, Input::Keys::PrintScreen},
        {SDLK_INSERT, Input::Keys::Insert},
        {SDLK_DELETE, Input::Keys::Delete},
        {SDLK_HELP, Input::Keys::Help},
        {SDLK_0, Input::Keys::Alpha0},
        {SDLK_1, Input::Keys::Alpha1},
        {SDLK_2, Input::Keys::Alpha2},
        {SDLK_3, Input::Keys::Alpha3},
        {SDLK_4, Input::Keys::Alpha4},
        {SDLK_5, Input::Keys::Alpha5},
        {SDLK_6, Input::Keys::Alpha6},
        {SDLK_7, Input::Keys::Alpha7},
        {SDLK_8, Input::Keys::Alpha8},
        {SDLK_9, Input::Keys::Alpha9},
        {SDLK_a, Input::Keys::A},
        {SDLK_b, Input::Keys::B},
        {SDLK_c, Input::Keys::C},
        {SDLK_d, Input::Keys::D},
        {SDLK_e, Input::Keys::E},
        {SDLK_f, Input::Keys::F},
        {SDLK_g, Input::Keys::G},
        {SDLK_h, Input::Keys::H},
        {SDLK_i, Input::Keys::I},
        {SDLK_j, Input::Keys::J},
        {SDLK_k, Input::Keys::K},
        {SDLK_l, Input::Keys::L},
        {SDLK_m, Input::Keys::M},
        {SDLK_n, Input::Keys::N},
        {SDLK_o, Input::Keys::O},
        {SDLK_p, Input::Keys::P},
        {SDLK_q, Input::Keys::Q},
        {SDLK_r, Input::Keys::R},
        {SDLK_s, Input::Keys::S},
        {SDLK_t, Input::Keys::T},
        {SDLK_u, Input::Keys::U},
        {SDLK_v, Input::Keys::V},
        {SDLK_w, Input::Keys::W},
        {SDLK_x, Input::Keys::X},
        {SDLK_y, Input::Keys::Y},
        {SDLK_z, Input::Keys::Z},
        {SDLK_LGUI, Input::Keys::LeftWinKey},
        {SDLK_RGUI, Input::Keys::RightWinKey},
        {SDLK_APPLICATION, Input::Keys::AppKey},
        {SDLK_SLEEP, Input::Keys::Sleep},
        {SDLK_KP_0, Input::Keys::NumPad0},
        {SDLK_KP_1, Input::Keys::NumPad1},
        {SDLK_KP_2, Input::Keys::NumPad2},
        {SDLK_KP_3, Input::Keys::NumPad3},
        {SDLK_KP_4, Input::Keys::NumPad4},
        {SDLK_KP_5, Input::Keys::NumPad5},
        {SDLK_KP_6, Input::Keys::NumPad6},
        {SDLK_KP_7, Input::Keys::NumPad7},
        {SDLK_KP_8, Input::Keys::NumPad8},
        {SDLK_KP_9, Input::Keys::NumPad9},
        {SDLK_KP_MULTIPLY, Input::Keys::Multiply},
        {SDLK_KP_MEMADD, Input::Keys::Add},
        {SDLK_SEPARATOR, Input::Keys::Separator},
        {SDLK_KP_MEMSUBTRACT, Input::Keys::Subtract},
        {SDLK_KP_DECIMAL, Input::Keys::Decimal},
        {SDLK_KP_DIVIDE, Input::Keys::Divide},
        {SDLK_F1, Input::Keys::F1},
        {SDLK_F2, Input::Keys::F2},
        {SDLK_F3, Input::Keys::F3},
        {SDLK_F4, Input::Keys::F4},
        {SDLK_F5, Input::Keys::F5},
        {SDLK_F6, Input::Keys::F6},
        {SDLK_F7, Input::Keys::F7},
        {SDLK_F8, Input::Keys::F8},
        {SDLK_F9, Input::Keys::F9},
        {SDLK_F10, Input::Keys::F10},
        {SDLK_F11, Input::Keys::F11},
        {SDLK_F12, Input::Keys::F12},
        {SDLK_F13, Input::Keys::F13},
        {SDLK_F14, Input::Keys::F14},
        {SDLK_F15, Input::Keys::F15},
        {SDLK_F16, Input::Keys::F16},
        {SDLK_F17, Input::Keys::F17},
        {SDLK_F18, Input::Keys::F18},
        {SDLK_F19, Input::Keys::F19},
        {SDLK_F20, Input::Keys::F20},
        {SDLK_F21, Input::Keys::F21},
        {SDLK_F22, Input::Keys::F22},
        {SDLK_F23, Input::Keys::F23},
        {SDLK_F24, Input::Keys::F24},
        {SDLK_NUMLOCKCLEAR, Input::Keys::NumLock},
        {SDLK_SCROLLLOCK, Input::Keys::ScrollLock},
        {SDLK_LSHIFT, Input::Keys::LeftShift},
        {SDLK_RSHIFT, Input::Keys::RightShift},
        {SDLK_LCTRL, Input::Keys::LeftControl},
        {SDLK_RCTRL, Input::Keys::RightContol},
        {SDLK_MENU, Input::Keys::LeftMenu},
        {SDLK_MENU, Input::Keys::RightMenu},
        {SDLK_AUDIOMUTE, Input::Keys::VolumeMute},
        {SDLK_VOLUMEDOWN, Input::Keys::VolumeDown},
        {SDLK_VOLUMEUP, Input::Keys::VolumeUp},
        {SDLK_AUDIONEXT, Input::Keys::NextTrack},
        {SDLK_AUDIOPREV, Input::Keys::PreviousTrack},
        {SDLK_AUDIOSTOP, Input::Keys::StopMedia},
        {SDLK_AUDIOPLAY, Input::Keys::PlayPause},
        {SDLK_MAIL, Input::Keys::LaunchMail},
        {SDLK_MEDIASELECT, Input::Keys::SelectMedia}
    };

    enum class Mouse {
        LeftButton, CenterButton, RightButton
    };

    void InputHandler::ProcessInput() {
        for (int i = 0; i < (int)Input::Keys::_MAXVALUE; i++) {
            // reset state for all keys from previous frame
            _KEYS_DOWN[i] = false;
            _KEYS_UP[i] = false;
        }
        // now poll for an input event from SDL
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    Engine::Quit();
                    return;
                }
                // sent when the key is first pressed
                case SDL_KEYDOWN:{
                    // handle key down input
                    if (auto it{sdlToKeyMap.find( event.key.keysym.sym )}; it != std::end(sdlToKeyMap)) {
                        // if key exists in our map, then mark that key
                        // it was also pressed this frame
                        _KEYS_HELD[(int)it->second] = _KEYS_DOWN[(int)it->second] = true;
                    }

                    // for (const auto& listener : keyInputListeners) {
                    //     listener->update(true, event.key);
                    // }
                    break;
                }
                // sent when the key is released
                case SDL_KEYUP: {
                    // handle key up input
                    if (auto it{sdlToKeyMap.find( event.key.keysym.sym )}; it != std::end(sdlToKeyMap)) {
                        // if key exists in our map, then unmark that key
                        this->_KEYS_HELD[(int)it->second] = false;
                        // but mark that it has been released this frame
                        this->_KEYS_UP[(int)it->second] = true;
                    }

                    // for (const auto& listener : keyInputListeners) {
                    //     listener->update(false, event.key);
                    // }
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    // handle mouse button down
                    // mark mouse as down + pressed this frame
                    this->_MOUSE_HELD[event.button.button] =
                    this->_MOUSE_DOWN[event.button.button] = true;
                    // for (const auto& listener : mouseButtonListeners) {
                    //     listener->update(event.button);
                    // }
                    break;
                }
                case SDL_MOUSEBUTTONUP: {
                    // handle mouse button up
                    this->_MOUSE_HELD[event.button.button] = false;
                    // mark that it was released this frame
                    this->_MOUSE_UP[event.button.button] = true;
                    // for (const auto& listener : mouseButtonListeners) {
                    //     listener->update(event.button);
                    // }
                    break;
                }
                case SDL_MOUSEMOTION: {
                    // handle mouse motion
                    // for (const auto& listener : mouseMotionListeners) {
                    //     listener->update(event.motion);
                    // }
                    break;
                }
            }
        }
    }

    bool InputHandler::GetKey(Input::Keys key) { return _KEYS_HELD[(int)key]; }
    bool InputHandler::GetKeyDown(Input::Keys key) { return _KEYS_DOWN[(int)key]; }
    bool InputHandler::GetKeyUp(Input::Keys key) { return _KEYS_UP[(int)key]; }

    bool InputHandler::GetMouseButton(Input::Mouse btn) { return _MOUSE_HELD[(int)btn]; }
    bool InputHandler::GetMouseButtonDown(Input::Mouse btn) { return _MOUSE_DOWN[(int)btn]; }
    bool InputHandler::GetMouseButtonUp(Input::Mouse btn) { return _MOUSE_UP[(int)btn]; }

    float InputHandler::GetAxis(std::string axis) {
        // TODO
    }

    void InputHandler::RegisterKeyInputListener() {
        
    }
    void InputHandler::RegisterMouseButtonListener() {
        
    }
    void InputHandler::RegisterMouseMotionListener() {
        
    }
    void InputHandler::UnregisterKeyInputListener() {
        
    }
    void InputHandler::UnregisterMouseButtonListener() {
        
    }
    void InputHandler::UnregisterMouseMotionListener() {
        
    }
}