class Solution {
public:
    int f(string s, int n,string t,int m, vector<vector<int>>&d){
        if(m==0){return 1;}//string mil gyi
        if(n==0){return 0;}
       
        if(d[n][m]!=-1){return d[n][m];}
        if(s[n-1]==t[m-1]){
            return d[n][m]=f(s,n-1,t,m-1,d)+f(s,n-1,t,m,d);
        }
        else{
            return d[n][m]=f(s,n-1,t,m,d);
        }
    }
    int numDistinct(string s, string t) {
         
        int n = s.size(),m=t.size();
        // vector<vector<int>>d(n+1,vector<int>(m+1,-1));
         vector<vector<double>>d(n+1,vector<double>(m+1,0));
         
         for(int i =0; i<=n ;i++){d[i][0]=1; }
         for(int i  =1; i<=m;i++){d[0][i]=0;}


         for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
             if(s[i-1]==t[j-1]){
                d[i][j]=d[i-1][j-1]+d[i-1][j];
             }
             else{
                d[i][j]=d[i-1][j];
             }
           }
         } 

        
        
        return (int)d[n][m];
    }
};