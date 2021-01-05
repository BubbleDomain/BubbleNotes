#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/5
 * @description: 127.word-ladder
 *
 * 和433题很像，但是会超时
 *
 * 1、思路需要变化 单词表的大小比433题中的基因库容量大很多，再加上valid函数耗时太高 复杂度为 length * size
 * 2、所以反过来直接在原单词上进行变化，每一位最多25种变化可能，复杂度就是 25 * size
 * 总的时间复杂度为 上面这个值的阶乘，所以2比1要快很多很多
 *
 * 放弃，看题解，难受
 *
 *
 */

// 还是超时，剪不了了，还是超时！！！！
int ans = INT_MAX;

void dfs(unordered_map<string, int> &M, string &current, string &end, int &size, int level, int &limit) {
    if (level >= limit || level >= ans) return;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 26; j++) {
            if (current[i] == 'a' + j) continue;
            char temp = current[i];
            current[i] = 'a' + j;
            if (M[current] <= level) {
                current[i] = temp;
                continue;
            }
            M[current] = level;
            cout<<current<<"  "<<end<<"  "<<level<<endl;
            if (current == end) {
                ans = min(ans, level + 1);
                current[i] = temp;
                return;
            }
            dfs(M, current, end, size, level + 1, limit);
            current[i] = temp;
        }
    }
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int limit = wordList.size();
    if (limit == 0) return 0;
    unordered_map<string, int> M;
    for (const auto& i : wordList) {
        if (i == beginWord) continue;
        M[i] = INT_MAX;
    }
    int size = beginWord.length();
    dfs(M, beginWord, endWord, size, 0, limit);
    return ans == INT_MAX ? 0 : ans + 1;
}

int main() {
//    vector<string> bank{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
//    int ans = ladderLength("cet", "ism", bank);

//    vector<string> bank{"hot","dot","dog","lot","log","cog"};
//    int ans = ladderLength("hit", "cog", bank);

    vector<string> bank{"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"};
    int ans = ladderLength("ta", "if", bank);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}