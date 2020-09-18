class Solution {
public:
    bool differ(const char* s, const char* p) {
        const char *si = s, *pi = p;
        while (*si != '\0' || *pi != '\0') {
            switch (*pi) {
                case '?':
                    if (*si == '\0') {
                        return false;
                    }
                    break;
                case '*':
                    while (1) {
                        pi++;
                        switch (*pi) {
                            case '\0':
                                return true;
                            case '*':
                                break;
                            default:
                                goto break2;
                        }
                    } break2:

                    if (*si ==

                    switch (*si) {
                        case '\0':
                            return false;
                        default:


                    while (*pi == '?') {
                        si++; pi++;
                        if (*si == '\0') {
                            switch (*pi) {
                                case '*':
                                    do {
                                        pi++;
                                    } while (*pi != '\0');
                                    return *(pi-1) == '*';
                                case '\0':
                                    return true;
                                default:
                                    return false;
                            }
                        }
                    }
                    while (*si != '\0') {
                        while (*si != *pi) si++;
                        if (differ(si+1, pi+1)) {
                            return true;
                        }
                        si++;
                    }
                    
                    return false;
                default:
                    if (*si != *pi) {
                        return false;
                    }
            }
            si++; pi++;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        return differ(s.c_str(), p.c_str());
    }
};
