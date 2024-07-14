// 726. Number of Atoms

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<string> eleStack;
        stack<int> countStack;
        int i = 0;
        while ( i < formula.size() ) {
            if ( isupper(formula[i]) ) {
                string eleName = "";
                eleName += formula[i];
                i++;
                while ( i < formula.size() && islower(formula[i]) ) {
                    eleName += formula[i];
                    i++;
                }
                eleStack.push(eleName);
                string eleCount = "";
                if ( i == formula.size() || !isdigit(formula[i]) ) {
                    eleCount += '1';
                } else {
                    while ( i < formula.size() && isdigit(formula[i])) {
                        eleCount += formula[i];
                        i++;
                    }
                }
                countStack.push(stoi(eleCount));
            }
            else {
                if ( formula[i] == ')' ) {
                    stack<string> tempEleStack;
                    stack<int> tempCountStack;
                    while ( eleStack.top() != "(" ) {
                        tempEleStack.push(eleStack.top());
                        tempCountStack.push(countStack.top());
                        eleStack.pop();
                        countStack.pop();
                    }
                    eleStack.pop();
                    countStack.pop();
                    i++;
                    string eleCount = "";
                    if ( i == formula.size() || !isdigit(formula[i]) ) {
                        eleCount += '1';
                    } else {
                        while ( i < formula.size() && isdigit(formula[i])) {
                            eleCount += formula[i];
                            i++;
                        }
                    }
                    int intEleCount = stoi(eleCount);
                    while ( tempEleStack.size() ) {
                        eleStack.push(tempEleStack.top());
                        countStack.push(tempCountStack.top() * intEleCount);
                        tempEleStack.pop();
                        tempCountStack.pop();
                    }
                } else {
                    eleStack.push("(");
                    countStack.push(-1);
                    i++;
                }
            }
        }
        map<string,int> atomCount;
        while ( eleStack.size() ) {
            atomCount[eleStack.top()] += countStack.top();
            eleStack.pop();
            countStack.pop();
        }
        string atomCountString = "";
        for ( auto it = atomCount.begin(); it != atomCount.end(); it++ ) {
            atomCountString += it->first;
            if ( it->second > 1 ) {
                atomCountString += to_string(it->second);
            }

        }
        return atomCountString;
    }
};
