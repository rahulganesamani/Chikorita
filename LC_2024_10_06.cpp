// 1813. Sentence Similarity III

class Solution {
public:
    vector<string> stringToList ( string sentence ) {
        vector<string> listString;
        string word = "";
        for ( int i = 0; i < sentence.size(); i++ ) {
            if ( sentence[i] == ' ' ) {
                listString.push_back( word );
                word = "";            
            } else {
                word += sentence[i];
            }
        }
        listString.push_back( word );  
        return listString;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> list1;
        vector<string> list2;
        if ( sentence1.size() >= sentence2.size() ) {
            list1 = stringToList( sentence1 );
            list2 = stringToList( sentence2 );
        } else {
            list2 = stringToList( sentence1 );
            list1 = stringToList( sentence2 );           
        }
        int count = 0;
        int endCount = 0;
        while ( count < list2.size() && list1[count] == list2[count] ) {
            count++;
        }
        while ( endCount < list2.size() && list1[list1.size()-endCount-1] == list2[list2.size()-endCount-1] ) {
            endCount++;
        }
        if ( count + endCount >= list2.size() ) 
            return true;      
        return false;
    }
};
