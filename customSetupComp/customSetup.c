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

    system("/etc/init.d/customSetup.sh start");
	
}
