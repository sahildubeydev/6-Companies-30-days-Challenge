// 688. Knight Probability in Chessboard

#include  <bits/stdc++.h>
using namespace std;

// DP
class Solution {
public:
    
    double knightProbability(int N, int K, int r, int c){
        
        // no moves so probability 1
        if(K==0) return 1.0;
        
        // parent chess board
        vector<vector<double>> parentBoard(N,vector<double>(N,0.0));
        
        // child chess board
        vector<vector<double>> childBoard(N,vector<double>(N,0.0));
        
        // row and col offset for generating next move or child positions
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        
        // initial position probability 1
        parentBoard[r][c] = 1.0;
        
        // Run K steps
        // Each step update the child position probability from parent position 
        // After each step assign child as parent board and create new child board
        for(int i=0;i<K;i++)
        {
            for(int p=0;p<N;p++)
            {
                for(int q=0;q<N;q++)
                { 
                    // calculate child position proabilty once from parent position probability
                    double moveProb = parentBoard[p][q]/8.0;
                    
                    // generate valid child positions
                    for(int w=0;w<8;w++)
                    {
                        cx = p + rowoffset[w];
                        cy = q + coloffset[w];

                        // update child position probability
                        if(cx>=0 && cx<N && cy>=0 && cy<N)
                            childBoard[cx][cy] += moveProb;
                    }                    
                }
            }
            
            parentBoard = childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(N,0.0));
        }
        

        
        double knightProb = 0.0;
        
        // Loop through parent board after K steps and sum up all probability
        for(int p=0;p<N;p++)
            for(int q=0;q<N;q++)
                   knightProb+=parentBoard[p][q];

        return knightProb;
    }
};


// Memoization

class Solution {
public:

   double dp[26][26][101];
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    double solve(int i, int j, int n, int k) {
        // out of boundary
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        
        if(k == 0) return 1;
        
        if(dp[i][j][k]) return dp[i][j][k];
        
        double sum = 0;
        
        for(int x=0;x<8;x++) {
            sum += solve(i+dx[x], j+dy[x], n, k-1);
        }
        
        return dp[i][j][k] = sum/8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        return solve(row, column, n, k);
    }
};