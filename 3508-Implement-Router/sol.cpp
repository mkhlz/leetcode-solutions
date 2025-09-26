#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX_N 10001
#define MOD 1000000007

// small struct for packet
struct Packet {
    int src, dst, ts;
};

// data for each destination
struct DestData {
    vector<int> timestamps; // sorted (timestamps arrive inc)
    int offset = 0;         // index of first alive
};

class Router {
private:
    int size; // memory limit

    unordered_map<ll, vector<int>> packets; // key -> {src,dst,ts}
    queue<ll> q; // FIFO queue
    unordered_map<int, DestData> counts; // dst -> timestamps + offset

    // encode (src,dst,ts) into one ll
    ll encode(int s, int d, int t) {
        return ((ll)s << 40) | ((ll)d << 20) | t;
    }

    // for binary search
    int lowerBound(vector<int>& v, int startIdx, int target) {
        return (int)(lower_bound(v.begin() + startIdx, v.end(), target) - v.begin());
    }
    int upperBound(vector<int>& v, int startIdx, int target) {
        return (int)(upper_bound(v.begin() + startIdx, v.end(), target) - v.begin());
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        ll key = encode(source, destination, timestamp);
        // duplicate? -> just skip
        if (packets.find(key) != packets.end())
            return false;
        // if full -> evict oldest
        if ((int)packets.size() >= size)
            forwardPacket();
        // store packet
        packets[key] = {source, destination, timestamp};
        q.push(key);
        // append timestamp for this dest
        counts[destination].timestamps.push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {}; // nothing left
        ll key = q.front();
        q.pop();
        vector<int> packet = packets[key];
        packets.erase(key);
        int dest = packet[1];
        counts[dest].offset++; // just slide offset
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end()) return 0;
        auto &data = it->second;
        auto &v = data.timestamps;
        int startIdx = data.offset;
        if (startIdx >= (int)v.size()) return 0;
        // binary search within alive slice
        int L = lowerBound(v, startIdx, startTime);
        int R = upperBound(v, startIdx, endTime);
        return R - L;
    }
};