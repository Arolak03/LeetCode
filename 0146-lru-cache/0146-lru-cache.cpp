class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> mpp;
    list<pair<int, int>> lrulist;  // key-value pairs
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            auto lrulistIterator = mpp[key];
            lrulist.splice(lrulist.begin(), lrulist, lrulistIterator);
            return lrulistIterator->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            auto lrulistIterator = mpp[key];
            lrulistIterator->second = value;  // Update the value
            lrulist.splice(lrulist.begin(), lrulist, lrulistIterator);
        } else {
            if (lrulist.size() >= size) {
                int toRemove = lrulist.back().first;
                lrulist.pop_back();
                mpp.erase(toRemove);
            }
            lrulist.push_front({key, value});
            mpp[key] = lrulist.begin();
        }
    }
};
