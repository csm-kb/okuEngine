#ifndef OKUENGINE_TYPES_H
#define OKUENGINE_TYPES_H

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace okuEngine {
    /**Equivalent to std::string.*/
    using oString = std::string;
    /**Equivalent to std::vector.*/
    template<typename T>            using oList = std::vector<T>;
    /**Equivalent to std::list.*/
    template<typename T>            using oLinkedList = std::list<T>;
    /**Equivalent to std::map.*/
    template<typename K,typename V> using oMap = std::map<K,V>;
    /**Equivalent to std::set.*/
    template<typename T>            using oSet = std::set<T>;
    /**Equivalent to std::stack.*/
    template<typename T>            using oStack = std::stack<T>;
    /**Equivalent to std::queue.*/
    template<typename T>            using oQueue = std::queue<T>;
    /**Equivalent to std::unordered_map.*/
    template<typename K,typename V> using oUnorderedMap = std::unordered_map<K,V>;
    /**Equivalent to std::unordered_set.*/
    template<typename T>            using oUnorderedSet = std::unordered_set<T>;
    /**Equivalent to std::array.*/
    template<typename T, size_t N>  using oArray = std::array<T,N>;
}

namespace okuEngine {
    /// Abstraction types for vectors ///
    using oVec2f = glm::vec2;
    using oVec2i = glm::ivec2;
    using oVec2u = glm::uvec2;
    using oVec2d = glm::dvec2;
    using oVec2b = glm::bvec2;
    using oVec2 = oVec2f;

    using oVec3f = glm::vec3;
    using oVec3i = glm::ivec3;
    using oVec3u = glm::uvec3;
    using oVec3d = glm::dvec3;
    using oVec3b = glm::bvec3;
    using oVec3 = oVec3f;
    
    using oVec4f = glm::vec4;
    using oVec4i = glm::ivec4;
    using oVec4u = glm::uvec4;
    using oVec4d = glm::dvec4;
    using oVec4b = glm::bvec4;
    using oVec4 = oVec4f;
}

#endif //OKUENGINE_TYPES_H