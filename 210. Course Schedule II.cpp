class Solution {
  enum class State { kInit, kVisiting, kVisited };  

public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> states(numCourses, State::kInit);

    for (const auto& p : prerequisites) {
      int u = p[1];
      int v = p[0];
      graph[u].push_back(v);
    }

    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, states, ans))
        return {};

    std::reverse(ans.begin(), ans.end());  
    return ans;
  }

private:
  bool hasCycle(const vector<vector<int>>& graph, int u,
                vector<State>& states, vector<int>& ans) {
    if (states[u] == State::kVisiting) return true;   // cycle
    if (states[u] == State::kVisited)  return false;  // already done

    states[u] = State::kVisiting;
    for (int v : graph[u])
      if (hasCycle(graph, v, states, ans))
        return true;

    states[u] = State::kVisited;
    ans.push_back(u);
    return false;
  }
};
