/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** create
*/

#include "server.h"

void create_team(char *team_name, char *team_description, char *uuid)
{
    FILE *fp;
    char *line = malloc(256);

    sprintf(line, "%s>name:%s,desc:%s,channel:\n", uuid,
    team_name, team_description);
    fp = fopen(open_file("teams"), "a+" );
    fprintf(fp, "%s", line);
    printf(INFOG "team %s added" RESET "\n", team_name);
    free(line);
    fclose(fp);
}

void create_channel(char *channel_name, char *channel_description, char *uuid)
{
    FILE *fp;
    char *line = malloc(256);

    sprintf(line, "%s>name:%s,desc:%s,thread:\n", uuid, channel_name,
    channel_description);
    fp = fopen(open_file("channel"), "a+" );
    fprintf(fp, "%s", line);
    printf(INFOG "channel %s added" RESET "\n", channel_name);
    free(line);
    fclose(fp);
}

int create_thread(char *thread_name, char *thread_description, char *uuid,
char *user)
{
    FILE *fp;
    char *line = malloc(512);
    int times = (int)time(NULL);

    sprintf(line, "%s>name:%s,desc:%s,user:%s,timestamp:\"%d\",replies:\n",
    uuid, thread_name, thread_description, user, times);
    fp = fopen(open_file("thread"), "a+" );
    fprintf(fp, "%s", line);
    printf(INFOG "thread %s added" RESET "\n", thread_name);
    free(line);
    fclose(fp);
    return (times);
}

int create_replies(char *replies_name, char *uuid, char *user)
{
    FILE *fp;
    char *li = malloc(256);
    int times = (int)time(NULL);

    sprintf(li, "%s>reply:%s,user:%s,timestamp:\"%d\"\n", uuid, replies_name,
    user, times);

    fp = fopen(open_file("replies"), "a+" );
    fprintf(fp, "%s", li);
    printf(INFOG "replies %s added" RESET "\n", replies_name);
    free(li);
    fclose(fp);
    return (times);
}

void create_user(char *user_name, char *uuid)
{
    FILE *fp;
    char *line = malloc(256);

    sprintf(line, "%s>name:%s,status:0,teams:\n", uuid, user_name);

    fp = fopen(open_file("user"), "a+" );
    fprintf(fp, "%s", line);
    free(line);
    fclose(fp);
}