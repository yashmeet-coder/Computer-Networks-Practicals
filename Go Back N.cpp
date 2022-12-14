#include <iostream>
#include <time.h>
using namespace std;

class Frame
{
public:
    int frame_num = 0;
    int isFrameRcd;
    int isAckRcd;
};

class GoBackN
{
public:
    int NOF;
    int count = 1;
    int lastRcd = 0;
    int n = NOF;
    Frame *f1;
    GoBackN()
    {
        cout << "Enter the number of frames to send:- ";
        cin >> NOF;
        f1 = new Frame[NOF];
    }

    void sender();
    int receiver();
};

void GoBackN::sender()
{
    int counter = 1;
    int n1 = NOF;
    int lastAck = 1;
    int lostAck;
    int w1 = 0;
    int ws;
    cout << "Enter the window size:- ";
    cin >> ws;
    w1 = ws;
    lastRcd = ws;
    for (int i = 1; i <= NOF; i++)
    {
        f1[i].frame_num = i;
    }
    while (NOF != 0)
    {
        while (counter <= ws)
        {
            cout << "Sending Frame " << f1[counter].frame_num << endl;
            counter++;
        }
        if (receiver())
        {
            f1[count].isAckRcd = rand() % 2;
        }
        else
        {
            cout << "Frame " << f1[count].frame_num << " was not received." << endl;
            f1[count].isAckRcd = 0;
        }

        if (f1[count].isAckRcd == 1)
        {
            cout << "Received Acknowledgement for Frame " << f1[count].frame_num << endl;
            lastAck = f1[count].frame_num;
            if (lastRcd == n1)
            {
                // cout << "No more frames to send." << endl;
            }
            else
            {
                cout << "Sending Frame " << lastAck + ws << endl;
                lastRcd = lastAck + ws;
            }
            count++;
            NOF--;
        }
        else
        {
            cout << "Timer expired for acknowldgement of " << f1[count].frame_num << endl;
            lostAck = f1[count].frame_num;
            for (int i = 1; i <= ws; i++)
            {
                if (lostAck <= n1)
                {
                    cout << "Resending frame " << f1[lostAck].frame_num << endl;
                    lostAck++;
                }
            }
        }
    }
}

int GoBackN::receiver()
{
    f1[count].isFrameRcd = rand() % 2;
    if (f1[count].isFrameRcd == 1)
    {
        cout << "Received Frame " << f1[count].frame_num << endl;
        cout << "Sending Acknowledgement." << endl;
    }
    return f1[count].isFrameRcd;
}

int main()
{
    srand(time(0));
    GoBackN obj;
    obj.sender();
}
