class Solution {
public:
    int maximum69Number (int num) {
        string nu=to_string(num) ;int ind_first_6=-1 ,ind_last_9=-1 ;
        for (int i=0 ;i<nu.size();i++){
            if(nu[i]=='6'){
ind_first_6=i ;
            break ;
            } 
        }
          for (int i=nu.size()-1 ;i>0;i--){
            if(nu[i]=='9') {
                ind_last_9=i ; break ;
            }
        }
        if( ind_first_6!=-1){
          nu[ind_first_6]='9' ;
          return stoi(nu);
        }
    return num ;
    }
};