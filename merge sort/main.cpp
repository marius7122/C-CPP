#include <stdio.h>

int v[] = {21, 3, 51, 34, 1, 4, 51, 4};     ///vectorul de sortat
int i,n;

void merge(int l,int m,int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i,j,k;

    int L[n1],R[n2];

    ///copiem in vectori auxiliari
    for(i=0;i<n1;i++)
        L[i] = v[i + l];
    for(i=0;i<n2;i++)
        R[i] = v[i + m + 1];


    ///interclasam
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
        if(L[i] <= R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];

    ///adaugam ce a mai ramas
    while(i<n1)
        v[k++] = L[i++];
    while(j<n2)
        v[k++] = R[j++];
}

///minsort
void mergeSort(int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;

        mergeSort(l,m);
        mergeSort(m+1,r);
        merge(l,m,r);
    }
}

void afis()
{
    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    printf("\n");
}

int main()
{

    n = sizeof(v) / sizeof(v[0]);

    afis();

    mergeSort(0,n-1);

    afis();

    return 0;
}
