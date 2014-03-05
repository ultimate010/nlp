#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getInfo(const char *src,const char *tag)
{
    vector<string> infoVec;
    char *p = (char*)src;
    char *pstr = strstr(p,tag);
    while(pstr)
    {
        infoVec.push_back(string(p,pstr-p));
        p = pstr+strlen(tag);
        pstr = strstr(p,tag);
    }
    if(0 != strlen(p))
    {
        infoVec.push_back(p);
    }
    return infoVec;
}

bool getNewLine(set<string> & s,string & lineStr){
    while(getline(cin , lineStr)){
        if(0 == lineStr.size()){
            continue;
        }else{
            vector<string> myv = getInfo(lineStr.c_str()," ");
            for(vector<string>::iterator iter = myv.begin();iter != myv.end();iter++){
                s.insert(*iter);
            }
            return true;
        }
    }
    return false;
}

int main(){
    string lineStr1 = "",lineStr2;
    set<string> s1,s2,s3;
    while(getNewLine(s2,lineStr2)){
        if(lineStr1 == ""){
            s1 = s2;
            lineStr1 = lineStr2;
            cout <<lineStr1 <<endl;
            continue;
        }
        set<string>::iterator iter = s3.begin();
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,iter));
        float pro = (double )(2 * (s3.size())) / (double)(s1.size() + s2.size());
        if(pro <= 0.8){
            cout <<lineStr2 <<endl;
        }
        s1 = s2;
        lineStr1 = lineStr2;
        s2.empty(); s3.empty();
    }
    return 0;
}
