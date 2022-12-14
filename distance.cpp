#include <iostream>
using namespace std;

class Nodes
{
public:
    int dist[4];
    int nexthop[4];
};

class distanceVectorRouting
{
public:
    int NON;
    int **adjacency;
    Nodes *obj;

    distanceVectorRouting()
    {
        cout << "Enter the number of nodes:- ";
        cin >> NON;
        adjacency = new int *[NON];
        obj = new Nodes[NON];

        for (int i = 0; i < NON; i++)
        {
            adjacency[i] = new int[NON];
        }
    }

    void dvr();
    void init();
    void update(int i, int k, int j);
    void display();
};

void distanceVectorRouting::init()
{
    for (int i = 0; i < NON; i++)
    {
        for (int j = 0; j < NON; j++)
        {
            if (i != j && adjacency[i][j] != -1)
            {
                obj[i].dist[j] = adjacency[i][j];
                obj[i].nexthop[j] = -20;
            }
            if (i == j)
                obj[i].dist[j] = 0;
            if (adjacency[i][j] == -1)
            {
                obj[i].dist[j] = 999;
                obj[i].nexthop[j] = -20;
            }
        }
    }
}

void distanceVectorRouting::dvr()
{
    for (int i = 0; i < NON; i++)
    {
        for (int k = 0; k < NON; k++)
        {
            for (int j = 0; j < NON; j++)
            {
                if (obj[i].dist[j] > (obj[i].dist[k] + obj[k].dist[j]))
                    update(i, j, k);
            }
        }
    }
    return;
}

void distanceVectorRouting::update(int i, int j, int k)
{
    obj[i].nexthop[j] = k;
    obj[i].dist[j] = obj[i].dist[k] + obj[k].dist[j];
}

void distanceVectorRouting::display()
{
    printf("Updated tables:- \n");
    for (int i = 0; i < NON; i++)
    {
        printf("Updated node %c table\n", 65 + i);
        printf("\t DEST\tDIST\tHOP\n");
        for (int j = 0; j < NON; j++)
        {
            if (i != j)
                printf("\t%c\t%d\t%c\n", 65 + j, obj[i].dist[j], 65 + obj[i].nexthop[j]);
        }
    }
}

int main()
{
    distanceVectorRouting ob1;
    cout << "Enter the adjacency matrix:- " << endl;
    for (int i = 0; i < ob1.NON; i++)
    {
        for (int j = 0; j < ob1.NON; j++)
            cin >> ob1.adjacency[i][j];
    }
    ob1.init();
    ob1.dvr();
    ob1.display();
}
