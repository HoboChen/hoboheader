#include <bits/stdc++.h>

#ifndef pr
#define pr(x) cout << #x << " = " << x << " % ";
#endif
#ifndef pn
#define pn cout << endl;
#endif
namespace hobo {

using namespace std;

// file_system_helper
vector<string> ReadFile(const string & fileName) noexcept {
    vector<string> ret;
    ifstream t;
    t.open(fileName);
    if (t.is_open()) {
        string x;
        getline(t, x);
        while (t.good()) {
            ret.push_back(x);
            getline(t, x);
        }
    }
    t.close();
    return ret;
}

int WriteFile(const vector<string> & s, const string & fileName) {
    ofstream t;
    t.open(fileName);
    if (t.is_open()) {
        for (auto x : s) {
            t << x << endl;
        }
    }
    t.close();
    return 0; // todo
}

//debug_helper
template<typename _t>
void ContainerPrint(const _t & x, string deli = " ",
                    bool printSize = 1, bool printNextLine = 1 ) {
    int cnt = 0;
    for (auto & t : x) {
        if (!cnt++) cout << t;
        else cout << deli << t;
    }
    if (printSize) cout << " | size = " << cnt ;
    if (printNextLine) cout << endl;
}

// string_helper
template<typename _t>
inline _t StringToInt(string src)
{
    _t x = 0;
    for (int i = 0; i < src.size(); i++)
    {
        x *= 10;
        x += src[i] - '0';
    }
    return x;
}

template<typename _t>
string AnythingToString(const _t & x) {
    ostringstream t;
    t << x;
    return t.str();
}

pair<bitset<64>, bitset<64>> Int128ToPairBitset(const __int128 x) {
    static_assert(sizeof(unsigned long long) == 8, "sizeof unsigned long long too small!");
    unsigned long long ff = 18446744073709551615ULL;
    bitset<64> bret1(x & ff), bret2((x >> 64) & ff);
    return make_pair(bret1, bret2);
}

vector<int> StringFind(const string & src, const string & pat) noexcept {
    vector<int> ret;
    if (pat.size() == 0 || src.size() == 0) return ret;
    int bpos = 0;
    while (1) {
        int t = src.find(pat, bpos);
        if (t == string::npos) break;
        ret.push_back(t);
        bpos = t + 1;
    }
    return ret;
}

vector<string> StringSplit(const string & src, const string & deli) {
    vector<int> deliPos = StringFind(src, deli);
    if (deliPos.size() == 0) {
        vector<string> t(1, src);
        return t;
    }
    deliPos.push_back(src.size());
    vector<string> ret;
    ret.push_back(src.substr(0, deliPos[0]));
    for (int i = 0; i < deliPos.size() - 1; i++) {
        ret.push_back(src.substr(deliPos[i] + 1, deliPos[i + 1] - 1 - deliPos[i]));
    }
    return ret;
}

inline bool IsUTF8CharBegin(char x) {
    return !((x & (1 << 7)) && !(x & (1 << 6)));
}

inline vector<string> StringSplitUTF8(const string & src) {
    vector<string> ret;
    for (int i = 0; i < src.size(); i++) {
        string t;
        if (IsUTF8CharBegin(src[i])) {
            t.push_back(src[i]);
            i++;
            while (!IsUTF8CharBegin(src[i])) {
                t.push_back(src[i]);
                i++;
            }
        }
        i--;
        ret.push_back(t);
    }
    return ret;
}

string GetFileNameWithoutExt(const string & src) {
    vector<int> pos = StringFind(src, ".");
    pos.insert(pos.begin(), src.size());
    return src.substr(0, pos[pos.size() - 1]);
}

string StringReplace(const string & src, const string & f, const string & t) {
    auto pos = StringFind(src, f);
    if (pos.size() == 0) return src;
    string ret;
    for (int i = 0; i < pos[0]; i++)
        ret.push_back(src[i]);
    for (int i = 0; i < t.size(); i++)
        ret.push_back(t[i]);
    for (int i = pos[0] + f.size(); i < src.size(); i++)
        ret.push_back(src[i]);
    return ret;
}

};
