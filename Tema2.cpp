#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
ifstream fin("input.txt");
int n = 0;
struct nod
{
    int nr_vecini = 0;
    int nr_culori = 0;
    char nume[10];
    char vecini[1024][10];
    int culori[1024] = {'0'};
 
}lista[1024];

int StringToInt(char a[])
{
    int nr = 0;
    int lg = strlen(a);
    for (int i = 0; i < lg; i++)
    {
        if (!isdigit(a[i]))
            return 0;
        nr = nr * 10 + (a[i] - '0');
    }
    return nr;
}

void citire() 
{
    char aux[1024];
    int nr=-1;
    while (fin.getline(aux, 1024))
    {
        nr++;
        int job = -1;
        char* p = strtok(aux, " ");
        for (int i = 0; i < 1024; i++)
        {
            if (strcmp(lista[i].nume, p) == 0)
                job = i;
        }
        if (job == -1)
        {
            strcpy(lista[nr].nume, p);
        }
        int pos = 0;
        p = strtok(NULL, " ");
        while (p != NULL)
        {
            if (job == -1)
            {
                strcpy(lista[nr].vecini[pos], p);
                lista[nr].nr_vecini++;
            }
            else {
                lista[job].culori[pos] = StringToInt(p);
                lista[job].nr_culori++;
            }
            pos++;
            p = strtok(NULL, " ");

        }
        
    }
    n = nr / 2;
}

void afisare()
{
    for(int i=0;i<=n;i++)
    {
        cout << lista[i].nume << " are vecinii: ";
        for(int j = 0; j < lista[i].nr_vecini; j++)
        {
            cout << lista[i].vecini[j] << " ";
        }
        cout << " si culorile: ";

        for(int k = 0; k < lista[i].nr_culori; k++)
        {
            cout << lista[i].culori[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    citire();
    afisare();
}
