#ifndef OKUENGINE_CORE_H
#define OKUENGINE_CORE_H

#include <okuEngine/exceptions.hpp>

#include <memory>
#include <string_view>

template <typename T>
constexpr auto type_name() {
	std::string_view name, prefix, suffix;
#ifdef __clang__
	name = __PRETTY_FUNCTION__;
	prefix = "auto type_name() [T = ";
	suffix = "]";
#elif defined(__GNUC__)
	name = __PRETTY_FUNCTION__;
	prefix = "constexpr auto type_name() [with T = ";
	suffix = "]";
#elif defined(_MSC_VER)
	name = __FUNCSIG__;
	prefix = "auto __cdecl type_name<";
	suffix = ">(void)";
#endif
	name.remove_prefix(prefix.size());
	name.remove_suffix(suffix.size());
	return name;
}

/**
 * @brief All-encompassing namespace for okuEngine.
 * 
 * All namespaces, functions, and classes relating to okuEngine
 * will appear in this one.
 */
namespace okuEngine {
	// pre-declarations
	class Engine;
	typedef std::unique_ptr<Engine> Engine_t;

	/**
	 * Engine service locator. Helps bind IService types to their actual
	 * implementations at runtime as opposed to compile-time.
	 */
	template<class T>
	class ServiceLocator final {
	private:
		ServiceLocator() {}
		inline static std::unique_ptr<T> currGlobalInstance;
	public:
		static void Bind(std::unique_ptr<T> value) { currGlobalInstance = std::move(value); }
		static T& Get() {
			if (currGlobalInstance == nullptr) {
				throw ServiceNotBoundException(
					std::string("ServiceLocator"),
					std::string("No service bound for type ")
					+ std::string(type_name<T>()));
			}
			return *currGlobalInstance;
		}
	};

	/**
	 * @brief Says hello.
	 */
	void say_hello();

	/**
	 * The core engine instance.
	 * Responsible for a lot, but the engine should be so modular that it doesn't matter much.
	 */
	class Engine final {
	public:
		// static Engine& Instance() {
		// 	if (engine == nullptr)
		// 		engine.reset(new Engine());
		// 	return *engine;
		// }
		// Engine(Engine const&)           = delete;
		// void operator=(Engine const&)   = delete;

		/**
		 * Initializes the engine and all of its services.
		 */
		static bool Initialize();
		/**
		 * Once ready, the engine will call into the core loop.
		 */
		static void CoreLoop();

	private:
		// static Engine_t engine;
		Engine() {}

		inline static bool isRunning;
	};
}

namespace okuEngine {
	/* Engine service interfaces and initializers */

	/**
	 * @brief Helper function for initializing an engine service.
	 * 
	 * @tparam T The service class type. Should NOT be the interface.
	 * @return std::unique_ptr<T> A unique pointer for the service instance.
	 */
	template<class T>
	std::unique_ptr<T> InitService () {
		return std::make_unique<T>(T());
	}

	namespace Renderer {
		class IRenderer;
	}

	namespace Audio {
		class IAudio;
	}

	namespace Physics {
		class IPhysics;
	}

	class IResourceHandler;
}

#endif