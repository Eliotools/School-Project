#include "Server.hpp"

int main(void)
{
    unsigned short port = 4242;

    try {
        Server *_server = new Server(port);
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}