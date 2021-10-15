#ifndef OKUENGINE_RENDERER_H
#define OKUENGINE_RENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

/** [REDACTED] */
#define JEFF 0

namespace okuEngine {
    
    /**
     * @brief Interface for the core engine renderer.
     */
    class IRenderer {
    public:
        /** Initializes the renderer. */
        virtual bool Initialize() = 0;
        /** Tells the renderer to shut down and clean up. */
        virtual void Shutdown() = 0;
        /** Main render call for the renderer from the engine. */
        virtual void Render(double deltaTime, bool engineRunning) = 0;
    };

    class Renderer : public IRenderer {
    public:
        Renderer();
        /** Initializes the renderer. */
        bool Initialize();

        /** Tells the renderer to shut down. */
        void Shutdown();

        

        void Render(double deltaTime, bool engineRunning);

    private:
        void InitOpenGL();
        
        SDL_Window *sdlWindow = nullptr;

        SDL_GLContext sdlGLContext;

        // framebuffer handles
        GLuint FBO, RBO, quadVAO, quadVBO;
        /** Called at the beginning of the render stage. */
        void BeginRender();
        /** Called at the end of the render stage. */
        void EndRender();
        /** Tells the renderer to clear its rendering. */
        void Clear();
        /** Tells OpenGL to swap the framebuffer, if supported. */
        void SwapFrameBuffer();
        // REFACTOR --> skybox object handles
        GLuint skyboxVAO, skyboxVBO, skyboxTexId;
        void SetupSkybox();
    };
}

#endif