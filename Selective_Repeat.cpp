#include <iostream>
#include <time.h>
using namespace std;

class Frame
{

public:
    int frameSequenceNum;
    bool frameReceivedStatus;

    Frame()
    {
        frameSequenceNum = 0;
        frameReceivedStatus = true;
    }
};

class selectiveRepeat
{
public:
    int windowSize;
    int totalFrame;
    Frame *A;
    Frame *senderWindow;
    Frame *receiverWindow;
    int z = 0;    // stores succesfully received frames.
    int temp = 0; // stores count of frames that appeared in window.

    // constructor
    selectiveRepeat(int windowSize, int totalFrame)
    {
        this->windowSize = windowSize;
        this->totalFrame = totalFrame;
        senderWindow = new Frame[windowSize];
        receiverWindow = new Frame[windowSize];

        // Storing frames in an array
         A = new Frame[totalFrame];
        for (int i = 0; i < totalFrame; i++)
        {
            A[i].frameSequenceNum = i;
        }

        // initialise sender's window to send first frames
        for (int i = z; i < windowSize; i++)
        {
            senderWindow[i] = A[i];
            temp++;
        }
    }

    // Sender
    void sender(Frame x)
    {
        cout << "Sending Frame Number : " << x.frameSequenceNum << endl;
    }

    // Implementation
    void implement()
    {
        while (z < totalFrame)
        {

            // checks if less frames are left to send than windowSize.
            if (windowSize > (totalFrame - z))
            {
                windowSize = totalFrame - z;
            }

            for (int i = 0; i < windowSize; i++)
            {
                sender(senderWindow[i]);
                receiverWindow[i] = senderWindow[i];
                // Receiver's side
                int x = rand() % 2;
                if (x == 1)
                {
                    cout << "Frame " << receiverWindow[i].frameSequenceNum << " is not reached." << endl;
                    receiverWindow[i].frameReceivedStatus = false;
                }
                else
                {
                    cout << "Frame number " << receiverWindow[i].frameSequenceNum << " is reached and acknowledged." << endl;
                    receiverWindow[i].frameReceivedStatus = true;
                }
            }

            // check received status

            int a = 0; // a stores no of frames not received or ack not received
            for (int i = 0; i < windowSize; i++)
            {
                if (receiverWindow[i].frameReceivedStatus == false)
                {
                    senderWindow[a] = receiverWindow[i];
                    a++;
                }
                else
                {
                    z++;
                }
            }

            for (int i = a; i < windowSize and temp < totalFrame; i++)
            {
                senderWindow[i] = A[temp];
                temp++;
            }
        }
    }
};

int main()
{
    int totalFrame;
    int windowSize;

    srand(time(0));

    cout << "Enter the Total number of frames to Send : ";
    cin >> totalFrame;

    cout << "Enter the window size : ";
    cin >> windowSize;

    cout << "Considering Frame Number start from 0.\n";

    selectiveRepeat obj(windowSize, totalFrame);
    obj.implement();

    return 0;
}