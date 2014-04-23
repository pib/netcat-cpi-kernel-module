#include <stdio.h>

// Brandon's compiler crashes unless we include them in
// this order.
//
//   __                               __   
// _/  |_  ____   ____ _____    _____/  |_ 
// \   __\/ __ \ /    \\__  \ _/ ___\   __\
//  |  | \  ___/|   |  \/ __ \\  \___|  |  
//  |__|  \___  >___|  (____  /\___  >__|  
//            \/     \/     \/     \/      
#include <trk4.h>
#include <trk5.h>
#include <trk6.h>
#include <trk1.h>
#include <trk2.h>
#include <trk3.h>

static char *tracks[] = {netcat_cpi_trk1,
                         netcat_cpi_trk2,
                         netcat_cpi_trk3,
                         netcat_cpi_trk4,
                         netcat_cpi_trk5,
                         netcat_cpi_trk6};

static char *tracknames[] = {"Interrupt 0x7f",
                         "The Internet is an Apt Motherfucker",
                         "Interrupt 0x0d",
                         "netcat",
                         "Interrupt 0xbb",
                         "Approximating the Circumference of the Earth"};

static unsigned long tracklens[] = {NETCAT_CPI_TRK1_LEN,
                                    NETCAT_CPI_TRK2_LEN,
                                    NETCAT_CPI_TRK3_LEN,
                                    NETCAT_CPI_TRK4_LEN,
                                    NETCAT_CPI_TRK5_LEN,
                                    NETCAT_CPI_TRK6_LEN};

play() {
    char *track;
    unsigned int currentTrack = 0;
    while (1) {
        if (currentTrack >= 6){ currentTrack = 0;}
        fprintf(stderr, "[netcat]: Now playing track %d - %s\n",currentTrack + 1,tracknames[currentTrack]);

        fwrite((void *)tracks[currentTrack], 1, tracklens[currentTrack], stdout);

        currentTrack++;
    }
}

int main(int argc, char *argv[]) {
	fprintf(stderr, "[netcat]: netcat - Cycles Per Instruction - Kernel Module Edition - 2014\n[netcat]: netcat is Brandon Lucia, Andrew Olmstead, and David Balatero\n[netcat]: On the web at http://netcat.co\n");

    if (argc >= 2 && strcmp("play", argv[1]) == 0) {
        play();
    } else {
        fprintf(stderr, "[netcat]: './netcat play | ogg123 -' to play.\n");
    }
    return 0;
}
