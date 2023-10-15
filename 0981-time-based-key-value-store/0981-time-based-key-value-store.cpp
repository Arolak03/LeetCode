class TimeMap {
public:
     unordered_map<string, vector<pair<int, string>> > mpp;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mpp.count(key)) {
            return "";
        }

        vector<pair<int, string>>& values = mpp[key];
        int left = 0;
        int right = values.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first == timestamp) {
                return values[mid].second;
            } else if (values[mid].first < timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (right >= 0) {
            return values[right].second;
        }

        return "";
    }
};
