#include<stdio.h>
#include <syslog.h>



int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);

    // Check argument count
    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file_path> <string_to_write>", argv[0]);
        closelog();
        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];

    // printf("%s\n", writefile);
    // printf("%s\n", writestr);

    FILE *fp = fopen(writefile, "w");
    if(fp == NULL)
    {
        syslog(LOG_ERR, "Error opening file : %s", writefile);
        closelog();
        return 1;
    }

    if(fprintf(fp, "%s", writestr) <0)
    {
        syslog(LOG_ERR, "Error writing file : %s", writefile);
        fclose(fp);
        closelog();
        return 1;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    

    fclose(fp);
    closelog();
    return 0;
}