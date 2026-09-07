class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank=0,total=0,start=0;
        for(int i=0;i<n;i++){
            int gain = gas[i]-cost[i];
            tank+=gain;
            total+=gain;
            if(tank<0){
                tank=0;
                start=i+1;
            }
        }
        if(total<0) return -1;
        return start;
    }
};