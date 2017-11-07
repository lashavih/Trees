/*
Problem link- "https://www.interviewbit.com/problems/hotel-reviews/".

Solution:
    We can maintain a trie data structure and put all distinct good words in it.
    Now , we can count and sort the R according to count value and their original
    index. Please refer to the solution for clear understanding .
*/

const int N=10002;

int trie[N][26];
bool vis[N];
int last[N];
int sz=0;

bool cmp(pair<int,int>a, pair<int,int> b) {
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

void insert_trie(string s) {
    int st=0;
    for(int i=0;i<s.size();i++) {
        int c=s[i]-'a';
        if(!vis[trie[st][c]]) {
            trie[st][c]=++sz;
            vis[sz]=true;
        }
        st=trie[st][c];
    }
    last[st]++;
}

bool search_trie(string s) {
    int st=0;
    for(int i=0;i<s.size();i++) {
        int c=s[i]-'a';
        if(!vis[trie[st][c]]) return false;
        st=trie[st][c];
    }
    return last[st]>0;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    sz=0;
    memset(vis,0,sizeof(vis));
    memset(trie,0,sizeof(trie));
    memset(last,0,sizeof(last));
    int tot=A.size();
    int q=B.size();
    string temp="";
    for(int i=0;i<tot;i++) {
        if(A[i]=='_') {
            insert_trie(temp);
            temp="";
        }
        else temp=temp+A[i];
    }
    if(temp.size()>0) insert_trie(temp);

    temp="";
    vector< pair<int,int> >vec;
    for(int i=0;i<q;i++) {
        string x=B[i];
        temp="";
        int cnt=0;
        for(int j=0;j<x.size();j++) {
            if(x[j]=='_') {
                cnt+=search_trie(temp);
                temp="";
            }
            else temp=temp+x[j];
        }
        if(temp.size()>0) cnt+=search_trie(temp);
        vec.push_back(make_pair(cnt,i));
    }

    vector<int>res;
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++) {
        res.push_back(vec[i].second);
    }
    return res;
}
