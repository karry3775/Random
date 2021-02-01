#pragma once
/**
 * Template class for all environments
 */
#include "DefaultTypes.h"

namespace pathfinding {

template <typename T>
class Environment {
   public:
    Environment(){};

    Environment(uint32_t size) : size_{size} {};

    // function to add edge to the Environment
    void addEdge(T v, T w) {
        // Bypass if already there
        if (std::find(adj_[v].begin(), adj_[v].end(), w) != adj_[v].end())
            return;

        adj_[v].push_back(w);
        adj_[w].push_back(v);
    }

    const uint32_t getSize() const { return size_; };

   private:
    AdjacencyList<T> adj_;
    uint32_t size_;
};

}  // namespace pathfinding