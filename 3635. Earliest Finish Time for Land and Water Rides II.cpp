/*
You are given two categories of theme park attractions: land rides and water rides.

Land rides
landStartTime[i] – the earliest time the ith land ride can be boarded.
landDuration[i] – how long the ith land ride lasts.
Water rides
waterStartTime[j] – the earliest time the jth water ride can be boarded.
waterDuration[j] – how long the jth water ride lasts.
A tourist must experience exactly one ride from each category, in either order.

A ride may be started at its opening time or any later moment.
If a ride is started at time t, it finishes at time t + duration.
Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
Return the earliest possible time at which the tourist can finish both rides.
  */

class Solution {
public:
    static int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        const int n=landStartTime.size(), m=waterStartTime.size();
        int minLandEnd=1e6, minWaterEnd=1e6;
        for(int i=0; i<n; i++) 
            minLandEnd=min(minLandEnd, landStartTime[i]+landDuration[i]);
        for(int i=0; i<m; i++) 
            minWaterEnd=min(minWaterEnd, waterStartTime[i]+waterDuration[i]);
        int ans=1e9;
        for(int i=0; i<m; i++){
            if (waterStartTime[i]<minLandEnd) 
                ans=min(ans, minLandEnd+waterDuration[i]);
            else ans=min(ans,  waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0; i<n; i++){
            if (landStartTime[i]<minWaterEnd)
                ans=min(ans, minWaterEnd+landDuration[i]);
            else ans=min(ans,  landStartTime[i]+landDuration[i]);
        }
        return ans;
    }
};
