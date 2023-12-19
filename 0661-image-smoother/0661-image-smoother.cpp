class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       int n=img.size();
       int m=img[0].size();
       vector<vector<int>>ans=img;
       int dx[8]={0,1,1,1,0,-1,-1,-1};
       int dy[8]={1,1,0,-1,-1,-1,0,1};
       for(int row=0;row<n;row++)
       {   
           for(int col=0;col<m;col++)
           {   
               int count=1;
               int sum=img[row][col];
               for(int k=0;k<8;k++)
               {
                   int nrow=row+dx[k];
                   int ncol=col+dy[k];

                   if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                   {   
                       sum+=img[nrow][ncol];
                       count++;
                   }
               }
               ans[row][col]=sum/count;
           }
       }
       return ans; 
    }
};