// 592. Fraction Addition and Subtraction

class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> nums;
        vector<int> dens;
        string num = "";
        string den = "";
        bool numNow = true;
        for ( int i = 0; i < expression.size(); i++ ) {
            if ( numNow ) {
                if ( expression[i] != '/' ) {
                    num += expression[i];
                } else {
                    nums.push_back(stoi(num));
                    num = "";
                    numNow = false;
                }
            } else {
                if ( expression[i] != '+' && expression[i] != '-' ) {
                    den += expression[i];
                } else {
                    dens.push_back(stoi(den));
                    den = "";
                    num += expression[i];
                    numNow = true;                    
                }
            }
        }
        dens.push_back(stoi(den));
        int denFinal = dens[0];
        for ( int i = 1; i < dens.size(); i++ ) {
            denFinal *= dens[i];
        }
        int numFinal = 0;
        for ( int i = 0; i < nums.size(); i++ ) {
            numFinal += ( nums[i]*(denFinal/dens[i]) );
        }
        if ( numFinal == 0 )
            return "0/1";
        for ( int i = denFinal; i > 0; i-- ) {
            if ( numFinal%i == 0 && denFinal%i == 0 ) {
                numFinal /= i;
                denFinal /= i;
            }
        }
        return ( to_string(numFinal) + "/" + to_string(denFinal));
    }
};
