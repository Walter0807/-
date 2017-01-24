#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <fstream>
#define For(i,a,b) for(int i=a;i<=b;i++)
# define maxN 60000
using namespace std;
char s[50000],ex1[50000],ex2[50000];
string w;
char tmp;
int tot,n;
double Ans;
map < string,   int>   words,P,vis; 
map < string,   double>   f; 
map < string,   long long>   Index; 
map < string,   char>   gr; 
long long totN;
map< string , map<string , int> > A,B,C,D;
bool fin;
int len,N,num;
int maxv,v;
char x;
char Q[20000][1000];
char curr[200];
string cur;
struct item1{
    double f;
    string word;
    char x;
} Neib[1000000];
int CC;

    
struct item{
        double freq;
        string word;
};


bool cmpp(const item &a1,const item &a2)
{
    return a1.freq>a2.freq;
}


bool cmp(const item1 &a1,const item1 &a2)
{
    return a1.f>a2.f;
}



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
    while(tmp==' ' || tmp=='\n') tmp = getchar();
    if (tmp==EOF) {fin=1;return;}
    tot = 0;
    while (tmp!='/')
    {
        s[tot++] = tmp;
        tmp = getchar();    
        if (tmp==EOF) {fin=1;return;}
    }
    x = getchar();
    tmp = getchar();if (tmp==EOF) {fin=1;return;}
    while(tmp!=' ')
    {
        tmp = getchar();
        if (tmp==EOF) {fin=1;return;}
    }
    s[tot] = '\0';
    
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
void Stat1(string p,string q,int cs)
{
    //cout<<p<<" "<<q<<" "<<cs<<endl;
    item N1[maxN],N2[maxN];
    int NN1,NN2;
    NN1 = 0;
    NN2 = 0;
    string w;
    int v;
    map<string,int>::iterator it;
    map < string,   int>   L,Z; 
    L.clear();
    Z.clear();
    if(cs>2) return;
    L = A[p];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N1[++NN1].freq = v/(double)words[w];
        N1[NN1].word = w;
    }
    L = A[q];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N2[++NN2].freq = v/(double)words[w];
        N2[NN2].word = w;
    }
    sort(N1+1,N1+NN1+1,cmpp);
    sort(N2+1,N2+NN2+1,cmpp);
    For(i,1,10) Z[N1[i].word] = i;
    For(i,1,10) 
    if(Z[N2[i].word]>0) 
    {
        string temp = N2[i].word; 
        Ans += (100 * (11-Z[temp]) * (11-i) * N1[Z[temp]].freq * N2[i].freq/(double)cs);
       // Stat1(N1[Z[N2[i].word]].word,N2[i].word,cs+1);
    }
}

void Stat2(string p,string q,int cs)
{
    //cout<<p<<" "<<q<<" "<<cs<<endl;
    item N1[maxN],N2[maxN];
    int NN1,NN2;
    NN1 = 0;
    NN2 = 0;
    string w;
    int v;
    map<string,int>::iterator it;
    map < string,   int>   L,Z; 
    L.clear();
    Z.clear();
    if(cs>2) return;
    L = B[p];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N1[++NN1].freq = v/(double)words[w];
        N1[NN1].word = w;
    }
    L = B[q];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N2[++NN2].freq = v/(double)words[w];
        N2[NN2].word = w;
    }
    sort(N1+1,N1+NN1+1,cmpp);
    sort(N2+1,N2+NN2+1,cmpp);
    For(i,1,10) Z[N1[i].word] = i;
    For(i,1,10) 
    if(Z[N2[i].word]>0) 
    {
        string temp = N2[i].word; 
        Ans += (100 * (11-Z[temp]) * (11-i) * N1[Z[temp]].freq * N2[i].freq/(double)cs);
       // Stat1(N1[Z[N2[i].word]].word,N2[i].word,cs+1);
    }
}

void Stat3(string p,string q,int cs)
{
    //cout<<p<<" "<<q<<" "<<cs<<endl;
    item N1[maxN],N2[maxN];
    int NN1,NN2;
    NN1 = 0;
    NN2 = 0;
    string w;
    int v;
    map<string,int>::iterator it;
    map < string,   int>   L,Z; 
    L.clear();
    Z.clear();
    if(cs>2) return;
    L = C[p];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N1[++NN1].freq = v/(double)words[w];
        N1[NN1].word = w;
    }
    L = C[q];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N2[++NN2].freq = v/(double)words[w];
        N2[NN2].word = w;
    }
    sort(N1+1,N1+NN1+1,cmpp);
    sort(N2+1,N2+NN2+1,cmpp);
    For(i,1,10) Z[N1[i].word] = i;
    For(i,1,10) 
    if(Z[N2[i].word]>0) 
    {
        string temp = N2[i].word; 
        Ans += (100 * (11-Z[temp]) * (11-i) * N1[Z[temp]].freq * N2[i].freq/(double)cs);
       // Stat1(N1[Z[N2[i].word]].word,N2[i].word,cs+1);
    }
}

void Stat4(string p,string q,int cs)
{
    //cout<<p<<" "<<q<<" "<<cs<<endl;
    item N1[maxN],N2[maxN];
    int NN1,NN2;
    NN1 = 0;
    NN2 = 0;
    string w;
    int v;
    map<string,int>::iterator it;
    map < string,   int>   L,Z; 
    L.clear();
    Z.clear();
    if(cs>2) return;
    L = D[p];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N1[++NN1].freq = v/(double)words[w];
        N1[NN1].word = w;
    }
    L = D[q];
    for(it=L.begin();it!=L.end();++it)
    {
        w = it->first;
        v = it->second;
        N2[++NN2].freq = v/(double)words[w];
        N2[NN2].word = w;
    }
    sort(N1+1,N1+NN1+1,cmpp);
    sort(N2+1,N2+NN2+1,cmpp);
    For(i,1,10) Z[N1[i].word] = i;
    For(i,1,10) 
    if(Z[N2[i].word]>0) 
    {
        string temp = N2[i].word; 
        Ans += (100 * (11-Z[temp]) * (11-i) * N1[Z[temp]].freq * N2[i].freq/(double)cs);
       // Stat1(N1[Z[N2[i].word]].word,N2[i].word,cs+1);
    }
}

double Similar(string p, string q)
{
 //   if(q=="黄河" && p=="学习")  printf("%c %c\n", gr[w], gr[cur]); 
  //  cout<<p<<"++"<<q<<"++"<<endl;
    Ans = 0;
    Stat1(p,q,1);
 //   printf("%lf\n", Ans);
    Stat2(p,q,1);
    Stat3(p,q,2);
 //   printf("%lf\n", Ans);
    Stat4(p,q,2);
 //   cout<<p<<" "<<q<<" "<<Ans<<endl;
    return Ans;
}

int main()
{
    num = 0;
    printf("傻傻的近义词助手=_=请输入查询条目总数\n");
    scanf("%d", &N);
    printf("请输入查询条目，每个词以#结尾\n");
    For(i,1,N)
    {
       read2();
       strcpy(Q[++num],s);
    }
    freopen("1.txt","r",stdin);
   // For(i,1,num) printf("%s\n", Q[i]);
    fin = 0;    
    totN = 0;
    while (!fin)
    {
        read();
     //   if(words[s]==0) Index[s] = ++totN;
        if(ex1[0]!='\0')
        {
             A[ex1][s] ++;
             B[s][ex1] ++;
        }
        if(ex2[0]!='\0')
        {
             C[ex2][s] ++;
             D[s][ex2] ++;
        }
         words[s]++;
         gr[s] = x;
         strcpy(ex2,ex1);
         strcpy(ex1,s);
     //   printf("%s\n", s);

    }

//       printf("%d %lld %c\n", words[cur], Index[cur], gr[cur]);
  /*     
          tot = 0;
          for(itit=words.begin();itit!=words.end();++itit)
          {
            w = itit->first;
            v = itit->second;
            cout<<w<<" "<<gr[w]<<endl;
            tot++;
            if(tot==60) break;

          }*/
   map<string,int>::iterator itit;
   For(i,1,num)
   {
         vis.clear();
         strcpy(curr,Q[i]);
         cur = Q[i];
       //  printf("%s\n", s);
         CC = 0;
         if (words.count(cur)==0) {printf("404 Not Found\n");continue;}
         else printf("“%s”建议的近义词:\n", curr);
         for(itit=words.begin();itit!=words.end();++itit)
         {
            w = itit->first;
            v = itit->second;
           // cout<<w<<" "<<cur<<endl;
         //   if(w=="黄河" && cur=="学习")  printf("%c %c\n", gr[w], gr[cur]); 

            if(gr[w]==gr[cur] && w!=cur && vis.count(w)==0)
            {
                //cout<<w<<" "<<gr[w]<<endl;
                Neib[++CC].f = Similar(cur,w);               
                Neib[CC].word = w;               
                Neib[CC].x = gr[w];              
                vis[w] = 1;
                //cout<<Neib[CC].f<<" "<<w<<" "<<Neib[CC].x<<endl;
            }

         }
         sort(Neib+1,Neib+CC+1,cmp);
         For(j,1,5)
         if(Neib[j].f>0) cout <<j<<":"<<Neib[j].word<<" "<<Neib[j].x<<" "<<Neib[j].f<<endl;
    //     printf("%d:%s\n", j, Neib[j].word);
         printf("\n");
   }
    return 0;
}

















