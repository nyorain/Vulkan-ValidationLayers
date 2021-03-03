#pragma once
#include <unordered_map>
#include <unordered_set>

namespace layers {
template <typename Key, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_set = std::unordered_set<Key, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_map = std::unordered_map<Key, T, Hash, KeyEqual>;
};
