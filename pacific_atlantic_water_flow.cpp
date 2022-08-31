// vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
//         vector<vector<int>>ans;
//         if(matrix.size()<1)return ans;
//         vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
//         vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        
//         for(int col=0;col<matrix[0].size();col++)
//         {
//             fnc(matrix,0,col,INT_MIN,pacific);
//             fnc(matrix,matrix.size()-1,col,INT_MIN,atlantic);
            
//         }
        
//         for(int row = 0;row<matrix.size();row++)
//         {
//              fnc(matrix,row,0,INT_MIN,pacific);
//             fnc(matrix,row,matrix[0].size()-1,INT_MIN,atlantic);
//         }
        
//         for(int i=0;i<matrix.size();i++)
//         {
//             for(int j=0;j<matrix[0].size();j++)
//             {
//                 if(pacific[i][j]==1 && atlantic[i][j]==1)
//                 {
//                     vector<int>v(2);
//                     v[0]=i;
//                     v[1]=j;
//                     ans.push_back(v);
//                 }
//             }
//         }
        
        
        
//         return ans;
//     }
    
//     void fnc(vector<vector<int>>& matrix,int i, int j,int prev,vector<vector<int>>& ocean)
//     {
//         if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
//             return;
//         if(ocean[i][j]==1)
//             return;
//         if(matrix[i][j]<prev)
//             return;
        
//         ocean[i][j]=1;
        
//         fnc(matrix,i+1,j,matrix[i][j],ocean); 
//         fnc(matrix,i-1,j,matrix[i][j],ocean);
//         fnc(matrix,i,j+1,matrix[i][j],ocean);
//         fnc(matrix,i,j-1,matrix[i][j],ocean);
        
        
        
        
        
//     }

class Solution {
public:
     int dx[4] = {0,1,0,-1};
     int dy[4] = {1,0,-1,0};

    void dfs(int i,int j,int z,vector<vector<int>>& heights,vector<vector<vector<int>>>&reach){
        reach[i][j][z]=1;
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && ni<heights.size() && nj>=0 && nj<heights[0].size() && reach[ni][nj][z]==0 && heights[i][j]<=heights[ni][nj])
             {
                 dfs(ni,nj,z,heights,reach);
             }
        }
    }      
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<vector<int>>>reach(n,vector<vector<int>>(m,vector<int>(2,0)));
         vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
             // from Pacific Ocean
            dfs(i,0,0,heights,reach);
             // from Atlantic Ocean
            dfs(i,m-1,1,heights,reach);
        }
      
        for(int j=0;j<m;j++)
        {
            // From Pacific Ocean
            dfs(0,j,0,heights,reach);
            //From Atlantic Ocean
           dfs(n-1,j,1,heights,reach);
        }
        
        //result
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(reach[i][j][0]==1 && reach[i][j][1]==1 )
                 ans.push_back({i,j});
            }
        }
        return ans;
    }
};
