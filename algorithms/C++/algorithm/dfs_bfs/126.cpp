#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_set>

using namespace std;

/**
 * @author: batteria
 * @version: 1.0
 * @since: 2021/1/7
 * @description: 126.word-ladder-ii
 *
 * 难点：使用过的节点还要再使用，需要针对每条路径来做去重
 *
 * ！！！！！！！！！超时的核心剪枝在于：广度遍历的当前层遍历过的，下一层不需要再遍历了！！！！
 */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    vector<vector<string>> ans;
    queue<vector<string>> V;
    queue<unordered_set<string>> SU;
    unordered_set<string> S;
    int flag = -1, cS = 1;
    vector<string> lastD;

    for (auto i : wordList) {
        if (i == beginWord) continue;
        S.insert(i);
    }
    V.push({beginWord});
    while (!V.empty()) {
        auto top = V.front();
        if (top.size() > cS) {
            cS = top.size();
            for (auto i : lastD) S.erase(i);
        }
        if (flag > 0 && top.size() > flag) break;

        V.pop();
        auto frontS = top.back();
        vector<string> t(top);
        for (int i = 0; i < frontS.size(); i++) {
            for (int j = 0; j < 26; j++) {
                if (frontS[i] == 'a' + j) continue;
                string s(frontS);
                s[i] = 'a' + j;
                if (S.find(s) == S.end()) continue;
                vector<string> t1(top);
                t1.push_back(s);
                V.push(t1);
                if (s == endWord) {
                    ans.push_back(t1);
                    flag = top.size();
                }
                lastD.push_back(s);
            }
        }
    }
    return ans;
}

int main() {
    vector<string> bank1{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    auto ans1 = findLadders("cet", "ism", bank1);
//
    vector<string> bank2{"hot","dot","dog","lot","log","cog"};
    auto ans2 = findLadders("hit", "cog", bank2);
//
//    vector<string> bank3{"ts","sc","ph","ca","jr","hf","to","if","ha","is","io","cf","ta"};
//    auto ans3 = findLadders("ta", "if", bank3);
//
//    vector<string> bank4{"hot","dot","dog","lot","log"};
//    auto ans4 = findLadders("hit", "cog", bank4);
//
//    vector<string> bank5{"hot","cog","dog","tot","hog","hop","pot","dot"};
//    auto ans5 = findLadders("hot", "dog", bank5);

    vector<string> bank6{"ted","tex","red","tax","tad","den","rex","pee"};
    auto ans6 = findLadders("red", "tax", bank6);
    return 0;
}