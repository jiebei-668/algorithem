class Solution {
public:
    bool canChange(string start, string target) {
		int p1 = 0;
        int p2 = 0;
        while(true){
            while(p1 < start.size() && start[p1] == '_') p1++;
            while(p2 < target.size() && target[p2] == '_') p2++;
            if(p1 >= start.size() || p2 >= target.size()) break;
            if(start[p1] != target[p2]){
                return false;
            }
            else if(start[p1] == 'L'){
                if(p1 < p2) return false;
            }
            else if(start[p1] == 'R'){
                if( p1 > p2) return false;
            }
            p1++;
            p2++;
        }
        while(p1 < start.size()){
            if(start[p1] != '_'){
                return false;
            }
            p1++;
        }
        while(p2 < target.size()){
            if(target[p2] != '_'){
                return false;
            }
            p2++;
        }
        return true;
    }
};

