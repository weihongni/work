#include <unistd.h>
#include "daemon.h"


int main (void)
{
	int i = 0;
	daemon_init ();
	
	while (1) {
		syslog (LOG_DAEMON, "I am daemonAAA!, times=%d\n", i++);
		sleep (1);
	}

	return 0;
}
