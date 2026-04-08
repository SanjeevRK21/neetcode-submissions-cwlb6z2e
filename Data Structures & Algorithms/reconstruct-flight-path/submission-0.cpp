class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> result;

    void dfs(string src) {
        while (!graph[src].empty()) {
            auto it = graph[src].begin();  // smallest destination
            string next = *it;
            graph[src].erase(it);          // remove edge
            dfs(next);
        }
        result.push_back(src); // post-order
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph
        for (auto& t : tickets) {
            graph[t[0]].insert(t[1]);
        }

        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }
};