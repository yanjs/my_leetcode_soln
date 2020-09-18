class Solution {
    public:
        Solution(){
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
        }
        string countAndSay(int n) {
            string *a = new string("1");
            string *b;
            char curr;
            int count;
            while(n > 1){
                curr = a->at(0);
                b = new string();
                count = 1;
                for(size_t i=1;i<a->size();i++){
                    if(curr == a->at(i)){
                        count++;
                    } else {
                        b->append(1, count + 48);
                        b->append(1, curr);
                        curr = a->at(i);
                        count = 1;
                    }
                }
                b->append(1, count + 48);
                b->append(1, curr);
                delete a;
                a = b;
                n--;
            }
            return *a;
        }
};
