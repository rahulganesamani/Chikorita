1518. Water Bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drankBottles = numBottles;
        int emptyBottles = numBottles;
        while ( emptyBottles >= numExchange ) {
            int exchangedBottles = emptyBottles / numExchange;
            drankBottles += exchangedBottles;
            emptyBottles = exchangedBottles + (emptyBottles % numExchange);
        }
        return drankBottles;
    }
};
