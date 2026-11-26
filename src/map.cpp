#include "project/map.h"

#include <algorithm>
#include <stdexcept>

// Default constructor
Map::Map() = default;

// Check whether the map is empty
bool Map::empty() const noexcept {
    return entries_.empty();
}

// Return the number of entries
std::size_t Map::size() const noexcept {
    return entries_.size();
}

// Find the index of a given key using binary search
std::size_t Map::findIndex(
    const std::string& key) const {

    auto it = std::lower_bound(
        entries_.begin(), entries_.end(), key,
        [](const KeyValuePair& entry,
           const std::string& searchKey) {
            return entry.key < searchKey;
        });

    if (it != entries_.end() && it->key == key) {
        return static_cast<std::size_t>(it - entries_.begin());
    }

    return entries_.size();
}

// Sort entries alphabetically by key
void Map::sortEntries() {
    std::sort(entries_.begin(), entries_.end(),
              [](const KeyValuePair& a,
                 const KeyValuePair& b) {
                  return a.key < b.key;
              });
}

// Check whether a key exists
bool Map::contains(const std::string& key) const {
    return findIndex(key) != entries_.size();
}

// Insert a new key-value pair
bool Map::insert(const std::string& key, int value) {

    // Prevent duplicate keys
    if (contains(key)) {
        return false;
    }

    // Insert directly in alphabetical position
    auto position = std::lower_bound(
        entries_.begin(), entries_.end(), key,
        [](const KeyValuePair& entry,
           const std::string& searchKey) {
            return entry.key < searchKey;
        });
    entries_.insert(position, KeyValuePair{key, value});

    return true;
}

// Update the value of an existing key
bool Map::update(
    const std::string& key, int newValue) {

    std::size_t index = findIndex(key);

    // Return false if the key does not exist
    if (index == entries_.size()) {
        return false;
    }

    entries_[index].value = newValue;

    return true;
}

// Remove an existing key-value pair
bool Map::erase(const std::string& key) {
    std::size_t index = findIndex(key);

    // Return false if the key does not exist
    if (index == entries_.size()) {
        return false;
    }

    entries_.erase(entries_.begin() + index);

    return true;
}

// Retrieve a value from a const map
int Map::at(const std::string& key) const {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        throw std::out_of_range("Key not found");
    }

    return entries_[index].value;
}

// Retrieve a modifiable reference to a value
int& Map::at(const std::string& key) {
    std::size_t index = findIndex(key);

    if (index == entries_.size()) {
        throw std::out_of_range("Key not found");
    }

    return entries_[index].value;
}

// Return all keys in sorted order
std::vector<std::string> Map::keys() const {
    std::vector<std::string> result;
    result.reserve(entries_.size());

    for (const auto& entry : entries_) {
        result.push_back(entry.key);
    }

    return result;
}

// Return all corresponding values
std::vector<int> Map::values() const {
    std::vector<int> result;
    result.reserve(entries_.size());

    for (const auto& entry : entries_) {
        result.push_back(entry.value);
    }

    return result;
}

// Verify that entries are sorted by key
bool Map::isSorted() const noexcept {
    for (std::size_t i = 1;
         i < entries_.size(); ++i) {

        if (entries_[i - 1].key > entries_[i].key) {
            return false;
        }
    }

    return true;
}
