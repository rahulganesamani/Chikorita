// 2751. Robot Collisions

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> healthStack;
        stack<char> dirStack;
        stack<int> posStack;

        vector<int> posIdx(positions.size());
        iota(posIdx.begin(), posIdx.end(), 0);
        stable_sort(posIdx.begin(), posIdx.end(),
             [&positions](size_t i1, size_t i2) {return positions[i1] < positions[i2];});
        
        for ( int i = 0; i < posIdx.size(); i++ ) {
            int newHealth = healths[posIdx[i]];
            int newPos = positions[posIdx[i]];
            char newDir = directions[posIdx[i]];
            if ( healthStack.size() == 0 ) { // Initialisation
                healthStack.push(newHealth);
                dirStack.push(newDir);
                posStack.push(newPos);
            } else { // No empty Stack
                int oldHealth = healthStack.top();
                int oldPos = posStack.top();
                char oldDir = dirStack.top();
                if ( oldDir == 'L' || ( oldDir == newDir ) ) { // No collission
                    healthStack.push(newHealth);
                    dirStack.push(newDir);
                    posStack.push(newPos);        
                } else { // Collision
                    if ( oldHealth > newHealth ) { // Older is stronger
                        healthStack.pop();
                        healthStack.push(oldHealth-1);
                    } else if ( oldHealth == newHealth ) { // Both equal
                        healthStack.pop();
                        dirStack.pop();
                        posStack.pop();
                    } else { // New stronger
                        while ( oldDir == 'R' ) {
                            if ( newHealth > oldHealth ) {
                                healthStack.pop();
                                dirStack.pop();
                                posStack.pop();
                                newHealth -= 1;
                                if ( healthStack.size() == 0 ) {
                                    healthStack.push(newHealth);
                                    dirStack.push(newDir);
                                    posStack.push(newPos);    
                                    break;
                                }
                                oldHealth = healthStack.top();
                                oldPos = posStack.top();
                                oldDir = dirStack.top();
                                if ( oldDir == 'L' ) {
                                    healthStack.push(newHealth);
                                    dirStack.push(newDir);
                                    posStack.push(newPos);    
                                    break;
                                }
                            } else if ( newHealth == oldHealth ) {
                                healthStack.pop();
                                dirStack.pop();
                                posStack.pop();    
                                break;                           
                            } else {
                                healthStack.pop();
                                healthStack.push(oldHealth-1);
                                break;
                            }
                        }
                    }
                }
            }
        }
        vector<int> answer;
        map<int,int> posHealthMap;
        while ( healthStack.size() ) {
            posHealthMap[posStack.top()] = healthStack.top();
            healthStack.pop();
            posStack.pop();
        }
        for ( int i : positions ) {
            if ( posHealthMap[i] != 0 ) 
                answer.push_back(posHealthMap[i]);
        }
        return answer;
    }
};
