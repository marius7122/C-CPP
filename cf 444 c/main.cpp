#include <iostream>

using namespace std;

int c[25];
int i;

bool verificaFata(int f)
{
    int st = (f-1) * 4;
    return (c[st+1] == c[st+2]) && (c[st+2] == c[st+3]) && (c[st+3] == c[st+4]);
}

bool verificaCub()
{
    bool v = true;
    for(int i=1;i<=6 && v;i++)
        v = v & verificaFata(i);
}

void rotFata(int f)
{
    int st = (f-1) * 4;
    int aux = c[st+2];
    c[st+2] = c[st+1];
    c[st+1] = c[st+3];
    c[st+3] = c[st+4];
    c[st+4] = aux;
}

void rotInvFata(int f)
{
    int st = (f-1) * 4;
    int aux = c[st+1];
    c[st+1] = c[st+2];
    c[st+2] = c[st+4];
    c[st+4] = c[st+1];
    c[st+1] = aux;
}

void rotMarg(int marg[])
{
    int aux1,aux2;
    aux1 = c[marg[0]]; aux2 = c[marg[1]];
    for(int i=0;i<6;i++)
        c[marg[i]] = c[marg[i+2]];
    c[marg[6]] = aux1;
    c[marg[7]] = aux2;
}

void rot1()
{
    int marg[] = {13,14,5,6,17,18,21,22};

    rotMarg(marg);

    rotFata(1);
}

void rot2()
{
    int marg[] = {16,14,3,4,17,19,10,9};

    rotMarg(marg);

    rotFata(2);
}

void rot3()
{
    int marg[] = {15,16,7,8,19,20,23,24};

    rotMarg(marg);

    rotFata(3);
}

void rot4()
{
    int marg[] = {1,3,5,7,9,11,24,22};

    rotMarg(marg);

    rotFata(4);
}

void rot5()
{
    int marg[] = {4,2,21,23,10,12,8,6};

    rotMarg(marg);

    rotFata(5);
}

void rot6()
{
    int marg[] = {2,1,13,15,11,12,20,18};

    rotMarg(marg);

    rotFata(6);
}

bool verificaToateRotatiile()
{
    bool rez = false;

    rot1();
    rez = rez | verificaCub();
    rot1();
    rot1();
    rez = rez | verificaCub();
    rot1();

    rot2();
    rez = rez | verificaCub();
    rot2();
    rot2();
    rez = rez | verificaCub();
    rot2();

    rot3();
    rez = rez | verificaCub();
    rot3();
    rot3();
    rez = rez | verificaCub();
    rot3();

    rot4();
    rez = rez | verificaCub();
    rot4();
    rot4();
    rez = rez | verificaCub();
    rot4();

    rot5();
    rez = rez | verificaCub();
    rot5();
    rot5();
    rez = rez | verificaCub();
    rot5();

    rot6();
    rez = rez | verificaCub();
    rot6();
    rot6();
    rez = rez | verificaCub();
    rot6();

    return rez;
}

void afis()
{
    for(int i=1;i<=24;i++)
    {
        cout<<c[i]<<' ';
        if(i%4 == 0)
            cout<<'\n';
    }
    cout<<'\n';
}

int main()
{
    for(i=1;i<=24;i++)
        cin>>c[i];

    if(verificaToateRotatiile())
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
