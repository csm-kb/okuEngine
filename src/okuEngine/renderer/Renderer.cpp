#include <okuEngine/internal/renderer.hpp>

namespace okuEngine {
    Renderer::Renderer() {

    }

    bool Renderer::Initialize() {
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) { return false; }

        // create a window
        sdlWindow = SDL_CreateWindow("REPLACE", 600, 100,
            // mWindowWidth, mWindowHeight, SDL_WINDOW_OPENGL);
            640, 480, SDL_WINDOW_OPENGL);
        if (!sdlWindow) { return false; }

        // create OpenGL context
        sdlGLContext = SDL_GL_CreateContext(sdlWindow);
        if (sdlGLContext == nullptr) { return false; }

        // init OpenGL
        this->InitOpenGL();

        // initialize GLEW
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) { return false; }

#ifdef GL_DEBUG
//         // debug output, comment as necessary
        glEnable              ( GL_DEBUG_OUTPUT );
//         glDebugMessageCallback( MessageCallback, nullptr );
#endif

        return true;
    }

    void Renderer::Shutdown() {
        if (sdlWindow != nullptr) {
            SDL_DestroyWindow(sdlWindow);
        }
    }

    void Renderer::InitOpenGL() {
        // tell SDL we want to use OpenGL 4.1
        // these attributes must be set before creating the window.
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        // use double buffering
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        // require hardware acceleration.
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

        // we request from OpenGL at least 8-bits per channel for the color buffer
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

        glEnable(GL_DEPTH_TEST);					       // enable depth testing
        glDepthFunc( GL_LESS );							   // use less than depth test

        glEnable(GL_BLEND);								   // enable blending
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // use one minus blending equation

//        glEnable(GL_CULL_FACE);
//        glCullFace(GL_FRONT);
//        glFrontFace(GL_CW);

        glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );	// set the clear color to black
    }

    void Renderer::Render(double deltaTime, bool engineRunning) {
        if (!engineRunning)
            return;
        ////////// ** BEGIN RENDER STAGE ** //////////
        this->BeginRender();
        // get true framebuffer size
        GLint framebufferWidth, framebufferHeight;
        SDL_GetWindowSize( sdlWindow, &framebufferWidth, &framebufferHeight );
        // update viewport
        glViewport(0, 0, framebufferWidth, framebufferHeight);
        
        ////////// ** END RENDER STAGE ** //////////
        this->EndRender();
    }

    void Renderer::BeginRender() {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
        glDrawBuffer(GL_BACK);
        glClearColor(0.0,0.0,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    void Renderer::EndRender() {
        glFlush(); // make sure that OpenGL rendered everything
        glBindFramebuffer(GL_FRAMEBUFFER, 0); // detach fbo
    }

    void Renderer::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::SwapFrameBuffer() {
        SDL_GL_SwapWindow(sdlWindow);
    }
    
    void Renderer::SetupSkybox() {}
}