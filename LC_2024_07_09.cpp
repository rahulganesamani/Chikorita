// 1701. Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWait = 0;
        double chefFree = 0;
        for ( int i = 0; i < customers.size(); i++ ) {
            int orderTime = customers[i][0];
            chefFree = max( chefFree, double(orderTime) );
            chefFree += customers[i][1];
            totalWait += ( chefFree - customers[i][0] );
        }
        return (totalWait / customers.size());
    }
};
