// 2491. Divide Players Into Teams of Equal Skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if ( n%2 != 0 || n < 2 )
            return -1;
        sort( skill.begin(), skill.end() );
        int sum = skill[0] + skill[n-1];
        long long result = 0;
        for ( int i = 0; i < n/2; i++ ) {
            if ( sum != ( skill[i] + skill[n-i-1] ) )
                return -1;
            result += ( skill[i] * skill[n-i-1] );
        } 
        return result;
    }
};
