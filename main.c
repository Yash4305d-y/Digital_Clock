#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void fill_time(char *buffer, size_t size, int format);
void fill_date(char *);
int inputformat();
void clear_screen();

int main()
{
    char buffer[50], date[100];
    int format = inputformat();

    while (1)
    {

        fill_time(buffer, sizeof(buffer), format);
        fill_date(date);
        clear_screen();
        printf("Current time: %s \n", buffer);
        printf("Date: %s \n\n", date);
        sleep(1);
    }
    return 0;
}

void clear_screen()
{

#ifdef _WIN32
    system("cls");
#elif
    system("clear");
#endif
}

int inputformat()
{

    int format;
    printf("Choose the time format \n");
    printf("1. 24hr Format \n");
    printf("2. 12hr Format (default)\n");
    printf("Make a choice(1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_date(char *buffer)
{

    time_t rawtime;
    struct tm *currenttime;

    time(&rawtime);
    currenttime = localtime(&rawtime);
    strftime(buffer, 100, "%A %d %B %Y", currenttime);
}

void fill_time(char *buffer, size_t size, int format)
{
    time_t rawtime;
    struct tm *currenttime;

    time(&rawtime);
    currenttime = localtime(&rawtime);
    if (format == 1)
    {
        strftime(buffer, size, "%H:%M:%S ", currenttime);
    }
    else
    {

        strftime(buffer, size, "%I:%M:%S %p", currenttime);
    }
}