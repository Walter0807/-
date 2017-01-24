#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <fstream>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char s[50000];
string w;
char tmp;
int tot;
map < string,   int>   words; 
vector <string> res[8000000];
bool fin;
int len;
int maxv,v;



void removen()
{
    len = strlen(s);
    For(i,0,len-2)
    s[i] = s[i+1];
    s[len-1] = '\0';
}


void read()
{
    tmp = getchar();
    while(tmp==' ') tmp = getchar();
    if (tmp==EOF) {fin=1;return;}
    tot = 0;
    while (tmp!=' ')
    {
        s[tot++] = tmp;
        tmp = getchar();        
        if (tmp==EOF) {fin=1;return;}
    }
    s[tot] = '\0';
    
}

int main()
{
    freopen("data.txt","r",stdin); 
    freopen("stat.txt","w",stdout);
    fin = 0;
    while (fin!=1)
    {
        read();
        if(s[0]=='\n') removen();
         words[s]++;
     //   printf("%s\n", s);

    }
    map<string,int>::iterator it;
 //   vector<string>::iterator vIt;
    for(it=words.begin();it!=words.end();++it)
    {
        w = it->first;
        v = it->second;
        if(v>maxv) maxv = v;
        res[v].push_back(w);

    }
    for(int i=maxv;i>=1;i--)
    {
        if(res[i].empty()) continue;
     //   for (vIt = res[i].begin(); veIterator < res[i].end(); veIterator++)
        For(j,0,(res[i].size()-1))
        {
            cout<<res[i][j];
            printf(" %d\n", i);
        }
    }
  // file1.close();
    return 0;
}


















