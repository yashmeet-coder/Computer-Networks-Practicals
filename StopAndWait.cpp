#include <iostream>
#include <ctime>
using namespace std;

class stopAndwait
{
public:
    int frameReceived;
    int ackReceived;
    int frame_num;
    
    void sender()
    {
        cout << "Enter the frame to be sent:- ";
        cin >> frame_num;
        cout << "Sending Frame " << frame_num << endl;
    }

    void receiver()
    {
        if(!frameReceived)
            resendFrame();
        cout << "Received Frame " << frame_num << endl;
        cout << "Sending Acknowledgement" << endl;
    }

    void resendFrame()
    {
        cout<<"Resending Frame "<<frame_num<<" because acknowledgement or frame lost"<<endl;
        frameReceived = 1;
        ackReceived = 1;
    }

    void ACKReceived()
    {
        if (!ackReceived)
        {
            resendFrame();
            receiver();
        }
        cout << "Recieved ACK sending next frame" << endl;
    }

    void simulate(int count)
    {
        while (count > 0)
        {
            frameReceived = rand()%2;
            ackReceived = rand()%2;

            sender();
            receiver();
            ACKReceived();
            count--;
        }
    }
};

int main()
{   srand(time(0));
    int num;
    stopAndwait obj;
    cout << "Enter the number of frames to be sent: ";
    cin >> num;
    obj.simulate(num);
}