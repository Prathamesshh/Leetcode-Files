class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);

        for(auto pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:graph[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return cnt==numCourses;
    }
};
