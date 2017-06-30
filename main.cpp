#include <iostream>
#include <pcap.h>

using namespace std;
bool live = false;
pcap_t *handle; // session handle
int BUFSIZE = 100;
char device[] = "lidar"; // device to sniff on
bool promisc = false;
int to_ms = 1000;
string ebuf; // errr string

int main()
{
    cout << "Hello world!" << endl;
    if (live){

        // establish sniffer

        /*

        The first argument is the device
        BUFSIZE is an integer which defines the maximum number of bytes to be captured by pcap
        Third parameter is promisc, when set to false, brings the interface into promiscuous mode
        (however, even if it is set to false, it is possible under specific cases for the interface to be in promiscuous mode, anyway).
        to_ms is the read time out in milliseconds (a value of 0 means no time out;
        on at least some platforms, this means that you may wait until a sufficient number of packets arrive before seeing any packets,
        so you should use a non-zero timeout).
        Lastly, ebuf is a string we can store any error messages within
        The function returns our session handler.
        */
        handle = pcap_open_live(device, BUFSIZE, promisc,  to_ms, )

        if (handle == NULL) {
            fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
            return(2);
        }
    }
    else {
        // using recorded stored pcaps.

    }
    return 0;
}
