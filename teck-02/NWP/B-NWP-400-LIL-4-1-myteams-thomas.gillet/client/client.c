/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** client side of my_teams
*/

#include "client.h"

int send_commands_2(client_t *cli, char buffer[])
{
    if (strncmp("10", buffer, 2) == 0)
        send_create(buffer, cli);
    if (strncmp("26", buffer, 2) == 0)
        send_list(buffer);
    if (strncmp("28", buffer, 2) == 0)
        send_info(buffer);
    if (strncmp("55", buffer, 2) == 0)
        client_error_already_exist();
    if (strncmp("56", buffer, 2) == 0)
        send_use(buffer);
    send_sub(cli, buffer);
    return (0);
}

int send_commands(client_t *cli, char buffer[], char *cmd)
{
    if (strncmp("203", buffer, 3) == 0) {
        client_event_private_message_received(get_second_word_noq(cmd),
            get_third_word_noq(buffer));
        write(cli->socketfd, "Message_received", 16);
        return (1);
    } if (strncmp("404", buffer, 3) == 0)
        client_error_unknown_user(get_second_word_noq(cmd));
    if (strncmp(buffer, "231", 3) == 0) {
        parse_one_user(buffer);
        return (0);
    } if (strncmp("502", buffer, 3) == 0)
        client_error_unauthorized();
    if (strncmp(buffer, "240", 3) == 0) {
        parse_user_infos(buffer);
        return (0);
    }
    return (send_commands_2(cli, buffer));
}

int login_logout(client_t *cli, char buffer[], char *cmd)
{
    if (strncmp("221", buffer, 3) == 0) {
        client_event_logged_out(cli->uuid, cli->username);
        printf(INFOG "Disconnected from server" RESET "\n");
        return (1);
    } if (strncmp("331", buffer, 3) == 0) {
        strcpy(cli->uuid, get_second_word_noq(cmd));
        strcpy(cli->username, get_third_word_noq(buffer));
        client_event_logged_in(cli->uuid, cli->username);
        return (0);
    }
    return (0);
}

void message_com(client_t *cli, char input[])
{
    char *otheruuid = malloc(37);

    if (strncmp("/messages", input, 9) == 0) {
        otheruuid = get_second_word(input);
        if (check_uuid(otheruuid) == NULL)
            client_error_unknown_user(remove_chars(otheruuid, '\"'));
        else {
            printf(INFOG "otheruuid: %s" RESET "\n", otheruuid);
            send_msg(cli, otheruuid);
        }
    }
}

void send_inputs(client_t *cli)
{
    char input[256] = {0};

    fgets(input, 256, stdin);
    message_com(cli, input);
    write(cli->socketfd, input, 256);
    fflush(stdin);
}