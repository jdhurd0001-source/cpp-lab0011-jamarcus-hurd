# Map Analysis Laboratory

## Core goal
Students must implement a dictionary-like `Map` structure that stores key-value pairs and supports lookup, insertion, deletion, and updates.

## Required operations
Students must implement the following behavior:

- insert a new key-value pair;
- reject duplicate keys;
- find whether a key exists;
- update an existing value;
- remove an existing key;
- retrieve a value by key;
- list keys and values;
- maintain sorted order if appropriate for the design.

## Analysis expectations
Students should discuss:

- average-case time complexity of insertion, lookup, and deletion;
- best-case and worst-case behavior;
- why duplicate-key handling matters;
- the difference between a search by key and scanning all entries;
- trade-offs between sorted vectors and hash-based maps;
- memory overhead and performance of `keys()` and `values()`.

## Implemented design
`Map` uses a `std::vector` of `KeyValuePair` entries kept in ascending key order. Duplicate keys are rejected before insertion, and all public operations preserve this invariant.

## Big-O analysis

- `insert`: $O(n)$ worst case because insertion at the correct position may shift entries; duplicate detection takes $O(\log n)$ with binary search.
- `contains`: $O(\log n)$ using binary search.
- `update`: $O(\log n)$ to locate the key and $O(1)$ to change its value.
- `erase`: $O(n)$ worst case because removing an entry may shift later entries.
- `at`: $O(\log n)$ to locate the key.
- `keys`: $O(n)$ to copy every key.
- `values`: $O(n)$ to copy every value.

This design provides predictable sorted iteration and fast key lookup. It also avoids hash-table memory overhead, but insertion and erasure are slower for large maps than a hash-based implementation.
