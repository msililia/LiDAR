#include <iostream>
#include <pcap.h>

using namespace std;
bool live = false;
pcap_t *handle; // session handle
int BUFSIZE = 100;
const char* device = "lidar"; // device to sniff on
bool promisc = false;
int to_ms = 1000;
char errbuf[PCAP_ERRBUF_SIZE];  // errr string
const char* file_name = "Highway.pcap"; // filename for offline mode
/*When pcap_loop(..) is called it will grab cnt packets (
it will loop infinitely when cnt is -1) and pass them to
the callback function
*/
int cnt = 8;

/* callback function that is passed to pcap_loop(..) and called each time
 * a packet is recieved                                                    */
void my_callback(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char*
        packet)
{
    // In here every cnt packets
    // This is where we begin to detect objects.
    printf("Hello there");
}


int main()
{
    cout << "Hello world!" << endl;
    if (live){
        /*
       Device - device name
       BUFSIZE - maximum size of packets to capture in bytes
       promisc - set card in promiscuous mode
       to_ms   - time to wait for packets in miliseconds before read
       times out
       errbuf  - if something happens, place error string here

        */

        // establish sniffer
        handle = pcap_open_live(device, BUFSIZE, promisc,  to_ms, errbuf);
    }
    else {
        // using recorded stored pcaps.
        handle = pcap_open_offline(file_name,errbuf);
    }

    if (handle == NULL) {
        fprintf(stderr, "Couldn't open  %s: \n", errbuf);
        return(2);
    }

    // loop through every packet, calling the callback function when cnt packets accumlated.
    if (pcap_loop(handle, cnt, my_callback, NULL) < 0) {
        cout << "pcap_loop() failed: " << pcap_geterr(handle);
        return 1;
    }

      cout << "capture finished" << endl;

    /* And close the session */
    pcap_close(handle);


    return 0;
}
