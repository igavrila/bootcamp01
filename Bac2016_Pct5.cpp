#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
#define NUME_IN "bac.in"
#define STOP 999
#define START 100
void eroare(int conditie, const char*mesaj)
{
    if(conditie)
    {
        cerr<<mesaj<<endl;
        exit(EXIT_FAILURE);
    }
}
char vFrecvente[STOP-START+1];
int ultimele3Cifre(int nr)
{
    assert(nr>=0);
    return nr%1000;
}
void citire(void)
{
    ifstream fin(NUME_IN, ios::in);
    bool goOn=true;
    int nrCrt,ult3;
    eroare(!fin.is_open(), "eroare la deschiderea fisierului de intrare!");
    do{
        fin>>nrCrt;
        if(fin.good())
        {
            if(nrCrt>=START)
            {
                ult3=ultimele3Cifre(nrCrt);
                if(nrCrt<=STOP)
                {
                    vFrecvente[ult3-START]=vFrecvente[ult3-START]|1;
                }
                else{
                    vFrecvente[ult3-START]=vFrecvente[ult3-START]|2;
                }
            }
        }
        else{
            goOn=false;
        }
    }while(goOn);
    fin.close();
}

void prelucrareVectorFrecvente(void)
{
    bool exista=false;
    int i;
    for(i=START;i<=STOP;i++)
    {
        if(vFrecvente[i-START]==3)
        {
            cout<<i<<endl;
            exista=true;
        }
    }
    if(!exista)
    {
        cout<<"Nu exista"<<endl;
    }
}

int main()
{
    citire();
    prelucrareVectorFrecvente();
    return 0;
}
