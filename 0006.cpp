class Solution {
public:
    string convert(string s, int numRows) {
        size_t size=s.size();
        if(size<=1||numRows==1){
            return s;
        }
        size_t period=numRows-1<<1;
        size_t numRowsInside=numRows-1;
        size_t i;
        size_t index=0;
        size_t line;
        size_t nextIndex;
        string out(size,0);
        for(i=0;i<size;i+=period){
            out[index]=s[i];
            index++;
        }
        for(line=1;line<numRowsInside;line++){
            nextIndex=index+1;
            for(i=line;i<size;i+=period){
                out[index]=s[i];
                index+=2;
            }
            index^=nextIndex;
            nextIndex^=index;
            index^=nextIndex;
            for(i=period-line;i<size;i+=period){
                out[index]=s[i];
                index+=2;
            }
            if(nextIndex<index){
                index--;
            }
        }
        for(i=numRowsInside;i<size;i+=period){
            out[index]=s[i];
            index++;
        }
        return out;
    }
};
