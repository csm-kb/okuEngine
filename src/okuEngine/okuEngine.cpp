#include <iostream>

#include <okuEngine/core.hpp>

namespace okuEngine {
    void say_hello() {
        std::cout << "Hello, from okuEngine!" << std::endl;
    }

    bool Engine::Initialize() {
        isRunning = true;

        return isRunning;
    }

    void Engine::CoreLoop() {

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