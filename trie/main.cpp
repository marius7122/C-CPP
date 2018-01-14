#include <stdio.h>

FILE *f1 = fopen("trie.in","r");
FILE *f2 = fopen("trie.out","w");

const int sigma = 26;

struct nod
{
    int aparitii,nrFii;
    nod *fii[sigma];

    nod()
    {
        aparitii = nrFii = 0;
        for(int i=0;i<sigma;i++)
            fii[i] = 0;
    }
};

int op,lPrefix;
char s[sigma + 10];

nod *trie = new nod;


inline void add(nod* n,char* s)
{
    ///am ajuns la ultima litera
    if(s[0] == 0)
    {
        n->aparitii ++;
        return;
    }

    int i = s[0] - 'a';

    ///nu avem muchie cu litera s[0]
    if(n->fii[i] == 0)
    {
        n->fii[i] = new nod;
        n->nrFii ++;
    }

    add(n->fii[i] , s+1);
}

inline bool del(nod* n,char* s)
{
    if(s[0] == 0)
    {
        n->aparitii--;
    }

    else if(del(n->fii[s[0] - 'a'] , s+1))
    {
        n->nrFii--;
        n->fii[s[0] - 'a'] = 0;
    }

    if(n->nrFii == 0 && n->aparitii == 0 && n != trie)
    {
        delete n;
        return true;
    }

    return false;
}

inline int ap(nod* n,char* s)
{
    if(s[0] == 0)
        return n->aparitii;

    if(n->fii[s[0] - 'a'] != 0)
        return ap(n->fii[s[0] - 'a'] , s+1);

    return 0;
}

inline void prefix(nod* n,char* s)
{
    if(s[0] == 0)
        return;

    if(n->fii[s[0] - 'a'] != 0)
    {
        lPrefix++;
        prefix(n->fii[s[0] - 'a'] , s+1);
    }
}

int main()
{
    do
    {
        fscanf(f1,"%d %s\n",&op,s);

        if(op == 0)
            add(trie,s);

        if(op == 1)
            del(trie,s);

        if(op == 2)
            fprintf(f2,"%d\n",ap(trie,s));

        if(op == 3)
        {
            lPrefix = 0;

            prefix(trie,s);

            fprintf(f2,"%d\n",lPrefix);
        }

    }while(!feof(f1));


    return 0;
}
