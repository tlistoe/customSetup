/*
 * runs custom setup functions at startup
 *
 * Listoe Dev
 * 19/07/03
 */
 
#include "legato.h"
#include "interfaces.h"
#include "le_tty.h"
#include "string.h"
#include "unistd.h"
#include "stdio.h"
#include "time.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>






//--------------------------------------------------------------------------------------------------
/*
 * Main program starts here
 */
//--------------------------------------------------------------------------------------------------

COMPONENT_INIT
{
	LE_INFO("running custom setup scripts");

    
	
	int systemResult;


    systemResult = system("/legato/systems/current/apps/customSetup/read-only/var/customSetup.sh start");
    // Return value of -1 means that the fork() has failed (see man system).
    if (0 == WEXITSTATUS(systemResult))
    {
        LE_INFO("Custom Setup Success");
    }
    else
    {
        LE_ERROR("Error Custom Setup Failed: (%d)", systemResult);
    }
	
}
