#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <okuEngine/core.hpp>
#include <okuEngine/debug.hpp>
#include <okuEngine/time.hpp>
#include <okuEngine/internal/renderer.hpp>

namespace okuEngine {
    void say_hello() {
        Debug::Log("Hello, from okuEngine!");
    }

    template <typename T>
    void ServiceLocator<T>::Shutdown() {
        // TODO
    }

    bool Engine::Initialize() {
        // first step: initialize the renderer
        ServiceLocator<IRenderer>::Bind(InitService<Renderer>());
        if (!ServiceLocator<IRenderer>::Get().Initialize()) {
            return false;
        }

        // next, initialize input
        ServiceLocator<IInputHandler>::Bind(InitService<InputHandler>());

        // TODO: call Awake() on all registered game objects
        // TODO: call OnEnable() on all enabled game objects

        isRunning = true;

        return isRunning;
    }

    void Engine::CoreLoop() {
        // TODO: call Start() on all registered game objects before loop

        IRenderer& renderer = ServiceLocator<IRenderer>::Get();
        IInputHandler& inputHandler = ServiceLocator<IInputHandler>::Get();
        while (isRunning) {
            // TODO: call physics update events

            // TODO: work input events
            inputHandler.ProcessInput();

            // TODO: call Update()
            // TODO: call LateUpdate()

            // TODO: call renderer
            renderer.Render(Time::deltaTime, isRunning);

            // TODO: call OnGUI() once per UI event

            // TODO: if pause then call OnApplicationPause(bool)

            // TODO: if stop then call to Shutdown
            if (!isRunning) break;
            // else, we loop again
        }
        Engine::Shutdown();
    }

    void Engine::Shutdown() {
        // TODO: if stop then call OnApplicationQuit() on all game objects
            // then call OnDisable() <-- disable all game objects
            // then call OnDestroy() <-- before destroying them all >:D

        // TODO: clean up inputs
        // TODO: clean up renderer
        ServiceLocator<IRenderer>::Get().Shutdown();
        // TODO: clean up ServiceLocator (all services)
        SDL_Quit();
    }

    void Engine::Quit() {
        isRunning = false;
    }
}

/*
    Object/Component calling order:
// initialization //
- Awake()       // called once in lifecycle
- OnEnable()
- Start()       // called once in lifecycle
// physics //
- FixedUpdate()
- <internal animation update .1>
- <internal physics update>
- <internal animation update .2>
- OnTriggerXXX()
- OnCollisionXXX()
- yield WaitForFixedUpdate
// input events //
- OnMouseXXX()
// game logic //
- Update()
- yield null
- yield WaitForSeconds
- yield WWW
- yield StartCoroutine
- <internal animation update>
- LateUpdate()
// scene rendering //
- OnPreCull()
- OnWillRenderObject()
- OnBecameVisible()
- OnBecameInvisible()
- OnPreRender()
- OnRenderObject()
- OnPostRender()
- OnRenderImage()
// GUI rendering (multiple times per frame update) //
- OnGUI() <-->
// end of frame //
- yield WaitForEndOfFrame |---> back to FixedUpdate()
// pausing //
- OnApplicationPause() (called after frame where pause occurs)
// decommissioning //
- OnApplicationQuit()
- OnDisable()
- OnDestroy()
*/