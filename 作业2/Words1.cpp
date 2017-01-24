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
char s[50000],ex[50000];
string w;
char tmp;
int tot,n;
map < string,   int>   words; 
map< string , map<string , int> > A;
vector <string> res[8000000];
bool fin;
int len,N,num;
int maxv,v;
char Q[20000][1000];


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
    while(tmp==' ' || (tmp>='a' && tmp<='z')) tmp = getchar();
    if (tmp==EOF) {fin=1;return;}
    tot = 0;
    while (tmp!='/')
    {
        s[tot++] = tmp;
        tmp = getchar();        
        if (tmp==EOF) {fin=1;return;}
    }
    s[tot] = '\0';
    if(s[0]=='\n') removen();
    
}

void read2()
{
    tmp = getchar();
    tot = 0;
    while (tmp!='#')
    {
        s[tot++] = tmp;
        tmp = getchar();        
    }
    s[tot] = '\0';
    if(s[0]=='\n') removen();
    
}

int main()
{
    num = 0;
    printf("后继词频搜索器～请输入查询条目总数\n");
    scanf("%d", &N);
    printf("请输入查询条目，每个词以#结尾\n");
    For(i,1,N)
    {
       read2();
       strcpy(Q[++num],s);
    }
    freopen("data.txt","r",stdin);
    fin = 0;
    while (!fin)
    {
        read();

        if(ex[0]!='\0') A[ex][s] ++;
        
         words[s]++;
         strcpy(ex,s);
     //   printf("%s\n", s);

    }
  For(i,1,num)
   {
         For(i,1,maxv) res[i].clear();
         strcpy(s,Q[i]);
       //  printf("%s\n", s);
         tot = 0;
         maxv = 0;
         if (A.count(s)==0) printf("404 Not Found\n");
         else
         { 
             printf("“%s”后继词的统计结果:\n", s);
             words = A[s];
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
                           cout<<"         "<<res[i][j];
                           printf(" %d\n", i);
                    }
                 tot++;
                 if(tot==8) break;
             }
         }
   }

    return 0;
}


















