#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <signal.h>
 
#define FICHERO_PID "/var/run/Tarea3SO2.pid"
 
volatile char bandera_ejecucion = 0;
 

void salir( int signum )
{
    bandera_ejecucion = 1;
}
 
int main( void )
{
    struct stat st;
    FILE *fichero_pid;
    FILE *fichero_prueba;
    pid_t pid;
    pid_t sid;
    if( stat( FICHERO_PID, &st ) == 0 )
    {
        exit( EXIT_FAILURE );
    }
    fichero_pid = fopen( FICHERO_PID, "w" );
    pid = fork();
 if( pid > 0 )
    {
        fprintf( fichero_pid , "%d\n", pid );
        fclose( fichero_pid );
        exit( EXIT_SUCCESS );
    }
    umask( 0 );
    sid = setsid();
int cambio_directorio=chdir( "/" );
    close( STDIN_FILENO );
    close( STDOUT_FILENO );
    close( STDERR_FILENO );
    fichero_prueba = fopen( "/tmp/Tarea3SO2.txt", "w" );
    signal( SIGTERM, salir );
    while ( bandera_ejecucion == 0 )
    {
FILE *cmd = popen ( "ping -c 3 google.com | grep icmp", "r" );
    char *s = malloc ( sizeof ( char ) * 200 );
    fgets ( s, sizeof ( char )*200, cmd );
    fprintf( fichero_prueba,  "%s", s);
    fflush( fichero_prueba );
    pclose ( cmd );
    sleep( 1 );}
    fprintf( fichero_prueba, "Fin del servicio\n" );
    fclose( fichero_prueba );
    unlink( FICHERO_PID );
}
