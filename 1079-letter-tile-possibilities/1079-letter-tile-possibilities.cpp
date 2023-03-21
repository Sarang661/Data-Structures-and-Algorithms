class Solution {
public:
    int numTilePossibilities(string tiles) {
	    // counts represents the number of occurences of given character in input string "tiles"
		// counts[0] is the number of occurences of char 'A'
		// counts[1] is the number of occurences of char 'B'
		// ...
		// counts[25] is the number of occurences of char 'Z'
        int counts[26] {}; 
        for (const auto &c :  tiles) {  // count the number of occurences of each character in the alphabet
            counts[c - 'A']++;
        }
        int result = 0;
        rec(counts, result);
        return result;
    }
    
	// rec stands for "recursive function". It is a pretty straightforward backtracking approach
	// both arguments are "modifiable", because they are passed by reference.
	// for non-c++ programmers -> it means that rec function modifies `counts` array and `result` integer passed `from numTilePossibilities` function. it also means that no cycles / memory is used for copying.
    void rec(int counts[26], int &result) {
        for(int i = 0; i < 26; ++i) {
            if (counts[i]){
                counts[i]--;
                result++;
                rec(counts, result);
                counts[i]++;
            }
        }
    }
};