#include <iostream>
using namespace std;

class Shared
{
public:
    int distFromSrc;
    char src;
    int visited;
};

class Djikstra
{
public:
    int NON;
    int k = 0;
    int sourceEntry = 0;
    // char Destination = 'C';
    char Source = 'A';
    Shared *obj;
    int **adjacency;
    char *path;
    char *nodes;

    Djikstra()
    {
        cout << "Enter the number of nodes:- ";
        cin >> NON;
        adjacency = new int *[NON];
        path = new char[NON];
        nodes = new char[NON];
        for (int i = 0; i < NON; i++)
            adjacency[i] = new int[NON];
        obj = new Shared[NON];
    }
    void input();
    void setAttributes();
    void setPath();
    void newSource();
};

void Djikstra::input()
{
    char ch = 'A';
    cout << "Enter the adjacency matrix-" << endl;
    for (int i = 0; i < NON; i++)
    {
        for (int j = 0; j < NON; j++)
        {
            cin >> adjacency[i][j];
        }
    }
    for (int i = 0; i < NON; i++)
    {
        nodes[i] = ch++;
        cout << "Nodes: " << nodes[i] << " ";
    }
}

void Djikstra::setAttributes()
{
    obj[0].distFromSrc = 0;
    obj[0].src = 'A';
    obj[0].visited = 1;
    for (int i = 1; i < NON; i++)
    {
        obj[i].distFromSrc = 9999;
        obj[i].src = '-';
        obj[i].visited = 0;
    }
    return;
}

void Djikstra::setPath()
{
    if (Source == 'B')
    {
        path[k++] = Source;
        return;
    }
    for (int i = sourceEntry; i < NON; i++)
    {
        for (int j = 0; j < NON; j++)
        {
            if (adjacency[i][j] != 0)
            {
                obj[j].distFromSrc = adjacency[i][j];
                obj[j].src = Source;
            }
        }
        path[k++] = Source;
        obj[k++].visited = 1;
        break;
    }
    return;
}

void Djikstra::newSource()
{
    int j;
    char min = obj[0].src;
    int mindist = obj[1].distFromSrc;

    for (j = 0; j < NON; j++)
    {   cout<<"obj dist: "<<obj[j].distFromSrc<<endl;
    cout<<"Min dist:- "<<mindist<<" "<<endl;
        if (obj[j].distFromSrc < mindist && obj[j].visited != 1)
        {   
            cout<<"Hello"<<endl;
            mindist = obj[j].distFromSrc;
            cout<<"J value: "<<j<<" ";
            min = obj[j].src;
        }
        cout << "Min value: " << min << endl;
    }
    Source = min;
    cout << "The new source is: " << Source << endl;
    sourceEntry = j;
    setPath();
    return;
}

int main()
{
    Djikstra ob1;
    ob1.input();
    ob1.setAttributes();
    ob1.setPath();
    while (ob1.NON != 0)
    {
        ob1.newSource();
        ob1.NON--;
    }
    cout << "The path is: ";
    for (int i = 0; i < 5; i++)
    {
        cout << ob1.path[i] << " ";
    }
}