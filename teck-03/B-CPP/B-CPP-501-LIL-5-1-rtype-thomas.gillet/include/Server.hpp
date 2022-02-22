/*
** EPITECH PROJECT, 2021
** RType
** File description:
** Class for Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <asio.hpp>
#include <iostream>
#include <functional>
#include <thread>
#include <map>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "LockedQueue.hpp"
#include "ecs.hpp"
#include "components.hpp"
#include "drawsystem.hpp"
#include "movesystem.hpp"
#include "spawnersystem.hpp"
#include "playersystem.hpp"
#include "collisionsystem.hpp"
#include "shootsystem.hpp"
#include "backgroundsystem.hpp"
#include "powerupsystem.hpp"

using namespace std;
using namespace asio::ip;

typedef map<uint32_t, udp::endpoint> ClientsList;
typedef ClientsList::value_type Client;
typedef pair<string, int> ClientMessage;

class Server {
public:
    Server(unsigned short port);
    ~Server();

    void start();
    void init();
    void engineInit();
	void setCard();
	void setPlayer();
    void run();
    void draw();
    void update();
    void handleMessage(const asio::error_code& error, size_t bytes_transferred);


    void start_receive();
    void handle_receive(const error_code &, size_t bytes_transferred);
    void send(const string& msg, udp::endpoint client_endpoint);
    void send_all_client(const std::string& msg);
    void send_one_client(const std::string &msg, int id);
    
    int handle_client_id(udp::endpoint endpoint);
    const int get_client_number(void);

    std::array<int, 4> _input;

    asio::io_service io_service;
    udp::socket _socket;
    udp::endpoint _remote_endpoint;

    thread service_thread;
    size_t bytes_send;
    array<char, 4096> recv_buffer;

    ClientsList clients;
    int nextClientID;

    LockedQueue<ClientMessage> incMessages;

    shared_ptr<DrawSystem> drawSystem;// = moteur.newSystem<DrawSystem>();
	shared_ptr<MoveSystem> moveSystem;// = moteur.newSystem<MoveSystem>();
	shared_ptr<SpawnerSystem> spawner;// = moteur.newSystem<SpawnerSystem>();
	shared_ptr<PlayerSystem> player;// = moteur.newSystem<PlayerSystem>();
	shared_ptr<CollisionSystem> collider;// = moteur.newSystem<CollisionSystem>();
	shared_ptr<ShootSystem> shooter;// = moteur.newSystem<ShootSystem>();
	shared_ptr<PowerupSystem> powerupsys;// = moteur.newSystem<PowerupSystem>();
    shared_ptr<BackgroundSystem> backgroundSystem;

    float delta;
	sf::Clock clock;
    std::array<int, 4> playerentity;
    int backgroundentity;
    float totaltime;
	sf::Time elapsed;
};

#endif