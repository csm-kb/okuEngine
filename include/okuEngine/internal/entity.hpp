#ifndef OKUENGINE_ENTITY_H
#define OKUENGINE_ENTITY_H

#include <okuEngine/types.hpp>

namespace okuEngine {
    // forward declarations
    class Transform;
    class Component;
    class Entity;

    class Transform {

    };

    class Component {
    public:
        ////////////////////////////////////////////
        //!!**// Per-Instance Functions //**!!//
        ////////////////////////////////////////////

        Component(oString name);

        /////////////////////////////////////////////////////
        //**// Lifecycle Handlers //**//
        /**
         * @brief Called early in the startup stage of the GO lifecycle.
         * This function executes before Start does.
         */
        virtual void Awake() = 0;
        /**
         * @brief Called as part of the startup stage of the GO lifecycle.
         * This function executes after Awake does.
         */
        virtual void Start() = 0;
        /**
         * @brief Called once every frame.
         */
        virtual void Update() = 0;
        /**
         * @brief Called once every frame, but after all Updates have run.
         */
        virtual void LateUpdate() = 0;
        /**
         * @brief Called when the game object is enabled.
         * This function is called after Awake, but before Start when initialized.
         */
        virtual void OnEnable() = 0;
        /**
         * @brief Called when the game object is disabled.
         */
        virtual void OnDisable() = 0;
        /**
         * @brief Called before the game object is destroyed.
         */
        virtual void OnDestroy() = 0;

        ~Component();
    };

    class Entity {
        friend class std::hash<Entity>;
    public:
        /////////////////////////////////////////////////////
        //**// Public members //**//
        oString name;

        ////////////////////////////////////////////
        //!!**// Global Static Functions //**!!//
        ////////////////////////////////////////////
        /**
         * @brief Returns the first entity with the given name, or `null` if none exists.
         */
        static Entity Find(oString name);
        /**
         * @brief Returns a list of Entities with the given tag. List may return empty.
         */
        static oList<Entity> FindAllWithTag(oString tag);
        /**
         * @brief Returns a clone of the original entity.
         */
        static Entity Instantiate(Entity const& original);
        static Entity Instantiate(Entity const& original, Transform& parent);
        static Entity Instantiate(Entity const& original, Transform& parent, bool inWorldSpace);
        // TODO: overload with parent transform (becomes parent of entity)
        // TODO: overload with parent transform, world-space instantiation
        // TODO: overload with vector3 position, quaternion rotation
        // TODO: overload with vector3 position, quaternion rotation
        // TODO: overload with vector3 position, rotation, parent transform

        ////////////////////////////////////////////
        //!!**// Per-Instance Functions //**!!//
        ////////////////////////////////////////////

        Entity(oString name);

        /////////////////////////////////////////////////////
        //**// Lifecycle Handlers //**//
        /**
         * @brief Called early in the startup stage of the GO lifecycle.
         * This function executes before Start does.
         */
        void Awake();
        /**
         * @brief Called as part of the startup stage of the GO lifecycle.
         * This function executes after Awake does.
         */
        void Start();
        /**
         * @brief Called once every frame.
         */
        void Update();
        /**
         * @brief Called once every frame, but after all Updates have run.
         */
        void LateUpdate();
        /**
         * @brief Called when the game object is enabled.
         * This function is called after Awake, but before Start when initialized.
         */
        void OnEnable();
        /**
         * @brief Called when the game object is disabled.
         */
        void OnDisable();
        /**
         * @brief Called before the game object is destroyed.
         */
        void OnDestroy();

        ~Entity();
        /////////////////////////////////////////////////////
        //**// Component Handlers //**//

        template <class T>
        T GetComponent();

        /////////////////////////////////////////////////////
        //**// Operators //**//
        bool operator==(Entity const& rhs) {
            return instanceId == rhs.instanceId;
        }
        operator oString() const { return name; }
        friend std::ostream & operator <<(std::ostream &out, const Entity &obj) {
            return out << static_cast<std::string>(obj);
        }
    private:
        unsigned long instanceId;
    };
}
/**
 * @brief Hash function for `Entity` objects.
 */
template<> struct std::hash<okuEngine::Entity> {
    std::size_t operator()(okuEngine::Entity const& s) const noexcept {
        std::size_t h1 = std::hash<unsigned long>{}(s.instanceId);
        std::size_t h2 = std::hash<std::string>{}(s.name);
        return h1 ^ (h2 << 1); //0x60000005
    }
};

#endif //OKUENGINE_ENTITY_H