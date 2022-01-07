#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

template <typename T>
inline std::ostream& operator<<(std::ostream& os, std::vector<T> v)
{
  for (int i=0; i<v.size(); ++i)
    os << v[i] << " ";
  return os;
}

class Solution1 {
public:
    vector<long> fmasks;

    int maxStudents(vector<vector<char>>& seats) {
      int m = seats.size();
      int n = seats[0].size();

      // compute valid mask:
      long vmask = 0L;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (seats[i][j] == '.')
            vmask |= (1L<<( i*n+j ));

      // compute forbid mask for each seat:
      // vector<long> fmasks(m*n);
      fmasks.resize(m*n, 0L);
      for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
          long temp = 0L;
          if (j>=1)   temp |= (1L<<(i*n+j-1));
          if (j<=n-2) temp |= (1L<<(i*n+j+1));
          if (i>=1 && j>=1)   temp |= (1L<<( (i-1)*n+j-1 ));
          if (i>=1 && j<=n-2) temp |= (1L<<( (i-1)*n+j+1 ));
          fmasks[i*n + j] = temp & vmask;
        }
      }
      // cout<<"fmasks: "<<fmasks<<endl;
      // cout<<"vmask: "<<vmask<<endl;

      int ans=0;
      int size = m*n;
      int cnt;
      for (long msk=0; msk<(1L<<size); ++msk){
        if ( (msk | vmask) != vmask ) continue;
        if (!check(msk, size)) continue;
        // compute cnt:
        cnt = 0;
        for (int i=0; i<size; ++i)
          if ( msk & (1L<<i) ) 
            ++cnt;
        // cout<<msk<<endl;
        if (cnt > ans) ans = cnt;
      }
      return ans;
    }

    bool check(long mask, int size){
      for (int i=0; i<size; ++i){
        if ( mask & (1L<<i) ){
          if (mask & fmasks[i])
            return false;
        }
      }
      return true;
    }
};


class Solution2 {
public:
    vector<long> fmasks;

    int maxStudents(vector<vector<char>>& seats) {
      int m = seats.size();
      int n = seats[0].size();
      int size = m*n;
      // compute valid mask:
      long vmask = 0L;
      int np = 0;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (seats[i][j] == '.'){
            vmask |= (1L<<( i*n+j ));
            ++np;
          }

      // compute forbid mask for each seat:
      // vector<long> fmasks(m*n);

      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (seats[i][j] == '.'){
            long temp = 0L;
            if (j>=1)   temp |= (1L<<(i*n+j-1));
            if (j<=n-2) temp |= (1L<<(i*n+j+1));
            if (i>=1 && j>=1)   temp |= (1L<<( (i-1)*n+j-1 ));
            if (i>=1 && j<=n-2) temp |= (1L<<( (i-1)*n+j+1 ));
            temp = convert(vmask, temp, size);
            fmasks.push_back(temp);
          }

      int cnt, ans=0;
      for (long msk=0; msk<(1L<<np); ++msk){
        if (!check(msk, np)) continue;
        cnt = 0;
        for (int i=0; i<np; ++i)
          if ( msk & (1L<<i) ) 
            ++cnt;
        if (cnt > ans) ans = cnt;
      } 
      return ans;
    }

    bool check(long mask, int size){
      for (int i=0; i<size; ++i){
        if ( mask & (1L<<i) ){
          if (mask & fmasks[i])
            return false;
        }
      }
      return true;
    }

    long convert(long vm, long fm, int size){
      long new_fm = 0;
      int idx = 0;
      for (int i=0; i<size; ++i){
        if ( vm & (1L<<i) ){
          if ( fm & (1L<<i) )
            new_fm |= (1L<<idx);
          idx++;
        }
      }
      return new_fm;
    }
};


class Solution_ {
public:
  vector<long> fmasks;
  int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();
    int size = m*n;
    // compute valid mask:
    long vmask = 0L;
    int np = 0;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (seats[i][j] == '.'){
          vmask |= (1L<<( i*n+j ));
          ++np;
        }
    // compute forbid mask for each seat:
    // vector<long> fmasks(m*n);
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        if (seats[i][j] == '.'){
          long temp = 0L;
          if (j>=1)   temp |= (1L<<(i*n+j-1));
          if (j<=n-2) temp |= (1L<<(i*n+j+1));
          if (i>=1 && j>=1)   temp |= (1L<<( (i-1)*n+j-1 ));
          if (i>=1 && j<=n-2) temp |= (1L<<( (i-1)*n+j+1 ));
          temp = convert(vmask, temp, size);
          fmasks.push_back(temp);
        }
    // cout<<fmasks<<endl;
    //
    vector<bool> dp(1L<<np, false);
    dp[0] = true;
    vector<bool> isvalid(np);
    
    int ans = 0;
    for (int i=0; i<np; ++i){
      for (long j=0; j<(1L<<np); ++j){
        if (!dp[j]) continue;
        for (int k=0; k<np; ++k){
          if ( j & (1L<<k) ) continue;
          if ( j & fmasks[k] ) continue;
          dp[ j|(1L<<k) ] = true;
          isvalid[i] = true;
        }
      }
      
      if (isvalid[i]) ans = i+1;
    }
    return ans;
  }

  long convert(long vm, long fm, int size){
      long new_fm = 0;
      int idx = 0;
      for (int i=0; i<size; ++i){
        if ( vm & (1L<<i) ){
          if ( fm & (1L<<i) )
            new_fm |= (1L<<idx);
          idx++;
        }
      }
      return new_fm;
    }
};


class Solution3 {
public:

  int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();
    int np = m*n;
    // compute valid mask:
    long vmask = 0L;
      for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
          if (seats[i][j] == '.')
            vmask |= (1L<<( i*n+j ));
    // compute forbid mask for each seat:
    vector<long> fmasks(np, 0L);
    for (int i=0; i<m; ++i){
      for (int j=0; j<n; ++j){
        long temp = 0L;
        if (j>=1)   temp |= (1L<<(i*n+j-1));
        if (j<=n-2) temp |= (1L<<(i*n+j+1));
        if (i>=1 && j>=1)   temp |= (1L<<( (i-1)*n+j-1 ));
        if (i>=1 && j<=n-2) temp |= (1L<<( (i-1)*n+j+1 ));
        fmasks[i*n + j] = temp & vmask;
      }
    }
    // cout<<fmasks<<endl;
    //
    vector<bool> dp(1L<<np);
    dp[0] = true;
    vector<bool> isvalid(np, false);
    int ans = 0;
    for (int i=0; i<np; ++i){
      for (long j=0; j<(1L<<np); ++j){
        if (!dp[j]) continue;
        if (j|vmask != vmask) continue;
        
        for (int k=0; k<np; ++k){
          if ( j & (1L<<k) ) continue;
          if ( j & fmasks[k] ) continue;
          dp[ j|(1L<<k) ] = true;
          isvalid[i] = true;
        }
      }
      if (isvalid[i]) ans = i+1;
    }
    return ans;
  }
};

class Solution {
public:
  int maxStudents(vector<vector<char>>& seats) {
    int m = seats.size();
    int n = seats[0].size();
    int nc = 1<<n;
    vector<uint8_t> temp_sz(nc);
    vector<uint8_t> prev_sz(nc);
    vector<uint8_t> sz(nc);
    vector<bool> prev_dp(nc, false);
    vector<bool> dp(nc, false);

    vector<int> inv_mask(m, 0);
    for (int row=0; row<m; ++row)
      for (int col=0; col<n; ++col)
        if (seats[row][col] == '#')
          inv_mask[row] |= (1<<col);    
    
    dp[0] = true;
    for (int row=0; row<m; ++row){
      if (row == 0){
        for (int step=0; step<n; ++n){
          for (int bmask=0; bmask<nc; ++bmask){
            if (bmask & inv_mask[row]) continue;
            if (!dp[bmask]) continue;
            for (int k=0; k<n; ++k){
              if (bmask & (1<<k)) continue;
              int new_mask = bmask | (1<<k);
              if (dp[new_mask]) continue;
              if ((new_mask & new_mask<<1) || (new_mask & new_mask>>1)) 
                continue;
              dp[new_mask] = true;
              sz[new_mask] = sz[bmask] + 1;
            }
          }
        }
      }
      else{ // from second row
        prev_dp = dp;
        prev_sz = sz;
        dp = vector<bool>(nc, false);
        sz = vector<uint8_t>(nc);
        temp_sz = vector<uint8_t>(nc);

        dp[0] = true;
        
        for (int step=0; step<n; ++n){
          for (int bmask=0; bmask<nc; ++bmask){
            if (bmask & inv_mask[row]) continue;
            if (!dp[bmask]) continue;
            for (int k=0; k<n; ++k){
              if (bmask & (1<<k)) continue;
              int new_mask = bmask | (1<<k);
              if (dp[new_mask]) continue;
              if ((new_mask & new_mask<<1) || (new_mask & new_mask>>1)) 
                continue;
              ///
              int max_sz = -1;
              for (int prm=0; prm<nc; ++prm){
                if (!prev_dp[prm]) continue;
                int fmask = (prm<<1)|(prm>>1);
                if (new_mask & fmask) continue;
                if (max_sz < prev_sz[prm]) 
                  max_sz = prev_sz[prm];
              }
              if (max_sz<0) continue; // never true
              ///
              dp[new_mask] = true;
              temp_sz[new_mask] = temp_sz[bmask] + 1;
              sz[new_mask] = temp_sz[new_mask] + max_sz;
            }
          }
        }
        //
        int max_prev_sz = 0;
        for (int prm=0; prm<nc; ++prm){
          if (!prev_dp[prm]) continue;
          if (max_prev_sz < prev_sz[prm])
            max_prev_sz = prev_sz[prm];
        }
        sz[0] = max_prev_sz;
      }
    } // end row

  }
};


int main(){
  Solution sl;
  vector<vector<char>> st;
  int ans;

  // st = {{'#','.','.','.','#'},{'.','#','.','#','.'},{'.','.','#','.','.'},{'.','#','.','#','.'},{'#','.','.','.','#'}};
  // ans = sl.maxStudents(st);
  // cout<<"ans: "<<ans<<endl;
  
  st = {{'.','#','#','.','#','#','.'},{'.','#','#','#','.','.','#'},{'#','#','#','#','#','#','.'},{'#','#','#','.','#','#','.'},{'#','.','.','#','#','#','#'}};
  ans = sl.maxStudents(st);
  cout<<"ans: "<<ans<<endl;

  st = {{'.','.','.','.','#','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','#','.'},{'.','.','.','.','.','.','.','.'},{'.','.','#','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','#','.','.','#','.'}};
  ans = sl.maxStudents(st);
  cout<<"ans: "<<ans<<endl;

  return 0;
}





