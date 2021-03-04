#pragma once
#include "robin_hood.h"

namespace layers {
template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_set = robin_hood::unordered_set<Key, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_map = robin_hood::unordered_map<Key, T, Hash, KeyEqual>;
};
