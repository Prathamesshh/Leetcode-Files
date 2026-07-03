class Solution {
public:
    int n;

    bool find(int limit, unordered_map<int, vector<pair<int,int>>>& adj,
              vector<bool>& online, long long k){

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        pq.push({0,0});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            long long currCost = curr.first;
            int node = curr.second;

            if(currCost > dist[node]) continue;

            for(auto &nxt : adj[node]){
                int nxtNode = nxt.first;
                int cst = nxt.second;

                if(cst < limit) continue;
                if(nxtNode != n-1 && !online[nxtNode]) continue;

                long long newCost = currCost + cst;

                if(newCost < dist[nxtNode]){
                    dist[nxtNode] = newCost;
                    pq.push({newCost, nxtNode});
                }
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        unordered_map<int, vector<pair<int,int>>> adj;

        int low = INT_MAX;
        int high = 0;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int cst = e[2];

            adj[u].push_back({v,cst});

            low = min(low,cst);
            high = max(high,cst);
        }

        int res = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(find(mid,adj,online,k)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return res;
    }
};