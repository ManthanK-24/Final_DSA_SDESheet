class Solution {
public:
    string sumOfDigits(string s){
        int sum = 0;
        for(auto x:s)sum += (x-'0');
      //  cout<<s<<"@"<<sum<<"sum\n";
        return to_string(sum);
    }
    string convertAlphaToNum(string s){
      string num;
      for(auto x:s){
          num+= to_string((x-'a'+1));
      }
        return num;
    }
    int getLucky(string s, int k) {
        
        int ans = 0;
        string tmp = convertAlphaToNum(s);
      //  cout<<tmp<<"tmp#\n";
        for(int i=0;i<k;i++){
            tmp = sumOfDigits(tmp);
           // cout<<tmp<<"tmp$ ";
        }
     //   cout<<"\n";
        return stoi(tmp);
    }
};