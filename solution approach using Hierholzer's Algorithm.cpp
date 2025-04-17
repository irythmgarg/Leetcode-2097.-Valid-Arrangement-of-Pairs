class Solution {
public:
    // Function to find a valid arrangement of pairs such that for every adjacent pair,
    // the second element of the previous pair equals the first of the next pair.
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> mp;       // Adjacency list
        unordered_map<int, int> indegree, outdegree; // In-degree and out-degree of nodes

        // Step 1: Build the graph and track in-degrees and out-degrees
        for (int i = 0; i < pairs.size(); i++) {
            int u = pairs[i][0], v = pairs[i][1];
            mp[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // Step 2: Find the starting point of the Eulerian path
        int starty = -1;
        for (int i = 0; i < pairs.size(); i++) {
            int start = pairs[i][0];
            // Eulerian path starts where out-degree is exactly one more than in-degree
            if (outdegree[start] - indegree[start] == 1) {
                starty = start;
                break;
            }
        }

        // If no special starting point found, start from the first pair
        if (starty == -1) {
            starty = pairs[0][0];
        }

        // Step 3: Hierholzer’s Algorithm to find Eulerian path
        vector<int> ans;  // Stores the ordered nodes
        stack<int> st;
        st.push(starty);

        while (!st.empty()) {
            int top = st.top();
            if (!mp[top].empty()) {
                st.push(mp[top].back());
                mp[top].pop_back();
            } else {
                ans.push_back(top);
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end()); // Final path in correct order

        // Step 4: Convert the path to pair format
        vector<vector<int>> result;
        for (int i = 0; i < ans.size() - 1; i++) {
            result.push_back({ans[i], ans[i + 1]});
        }

        return result;
    }
};
