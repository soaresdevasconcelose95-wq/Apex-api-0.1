#include <unistd.h>                                        #include <stdio.h>                                         #include <fcntl.h>                                         #include <string.h>
#include <sys/ioctl.h>                                     #define APX_SUCCESS 0
#define APX_ERROR 1                                        struct {                                                   int fd;
} Apex;                                                    int apexInit() {
Apex.fd = open("/dev/mali0", O_RDWR);
if (Apex.fd > 0) {                                         printf("initialize\n");
return APX_SUCCESS;
} else {
printf("error\n");                                         return APX_ERROR;
}
}
int apexCommand(unsigned long request, void *command) {
if (Apex.fd < 0) {
printf("Apex error!\n");                                   }                                                          int result = ioctl(Apex.fd, request, command);
if (result < 0) {
printf("Apex Ioctl Error!\n");
}                                                          return APX_SUCCESS;
}                                                          void apexTerminate() {
close(Apex.fd);
}