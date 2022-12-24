class Solution {

private:
    
    map<string,string>urlEncoder;
    map<string,string>urlDecoder;
    string s = "1";
    
public:

    // Encodes a URL to a shortened URL.
    
    string encode(string longUrl) {
        
        urlEncoder[longUrl] = s;
        urlDecoder[s] = longUrl;
        
        s+="1";
        
        return urlEncoder[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        return urlDecoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));