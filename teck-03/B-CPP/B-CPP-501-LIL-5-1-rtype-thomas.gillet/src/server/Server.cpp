/*
** EPITECH PROJECT, 2021
** RType
** File description:
** Main for server
*/

#include "Server.hpp"
#include "ecs.hpp"
#include <unistd.h>

Engine moteur;

Server::Server(unsigned short port) : totaltime(0), delta(0), _socket(io_service, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), service_thread(&Server::start, this), nextClientID(0)
{
	for (int i = 0; i < 4; i++)
		_input[i] = -1;
	this->init();
    std::cout << "Starting server on : " << _remote_endpoint << " at port" << port << std::endl;
    service_thread.join();

}

Server::~Server()
{
    io_service.stop();
}

void Server::engineInit()
{
	moteur.init();
	moteur.newComponent<Drawable>();
	moteur.newComponent<Movable>();
	moteur.newComponent<Bullet>();
	moteur.newComponent<Ennemy>();
	moteur.newComponent<Player>();
	moteur.newComponent<Powerup>();
	drawSystem = moteur.newSystem<DrawSystem>();
	moveSystem = moteur.newSystem<MoveSystem>();
	spawner = moteur.newSystem<SpawnerSystem>();
	player = moteur.newSystem<PlayerSystem>();
	collider = moteur.newSystem<CollisionSystem>();
	shooter = moteur.newSystem<ShootSystem>();
	powerupsys = moteur.newSystem<PowerupSystem>();
	backgroundSystem = moteur.newSystem<BackgroundSystem>();
}

void Server::setCard()
{
	std::bitset<MAX_COMPONENT> card;
	std::bitset<MAX_COMPONENT> cardbullet;
	std::bitset<MAX_COMPONENT> cardennemy;
	std::bitset<MAX_COMPONENT> cardplayer;
	std::bitset<MAX_COMPONENT> cardpowerup;
	card.set(moteur.getComponentType<Drawable>());
	card.set(moteur.getComponentType<Movable>());
	cardbullet.set(moteur.getComponentType<Movable>());
	cardbullet.set(moteur.getComponentType<Drawable>());
	cardbullet.set(moteur.getComponentType<Bullet>());
	cardennemy.set(moteur.getComponentType<Movable>());
	cardennemy.set(moteur.getComponentType<Drawable>());
	cardennemy.set(moteur.getComponentType<Ennemy>());
	cardplayer.set(moteur.getComponentType<Movable>());
	cardplayer.set(moteur.getComponentType<Drawable>());
	cardplayer.set(moteur.getComponentType<Player>());
	cardpowerup.set(moteur.getComponentType<Movable>());
	cardpowerup.set(moteur.getComponentType<Drawable>());
	cardpowerup.set(moteur.getComponentType<Powerup>());
	moteur.setSystemCard<DrawSystem>(card);
	moteur.setSystemCard<MoveSystem>(card);
	moteur.setSystemCard<BackgroundSystem>(card);
	moteur.setSystemCard<SpawnerSystem>(cardennemy);
	moteur.setSystemCard<PlayerSystem>(cardplayer);
	moteur.setSystemCard<CollisionSystem>(card);
	moteur.setSystemCard<ShootSystem>(cardbullet);
	moteur.setSystemCard<PowerupSystem>(cardpowerup);
}

void Server::setPlayer()
{
	sf::Texture textureback;
	if (!textureback.loadFromFile("resources/mountainback.png"))
				exit(84);

	sf::Sprite backsprite;
	backsprite.setTexture(textureback);
	backgroundentity = moteur.createEntity();
	moteur.addComponent(backgroundentity, Drawable{
		.position = sf::Vector2f(0, 0),
		.size = sf::Vector2f(WINDOW_WIDTH * 2, WINDOW_HEIGHT),
		.texture = textureback,
		.bulletsprite = backsprite
	});
	moteur.addComponent(backgroundentity, Movable{
		.speed = 3,
		.direction = "left",
		.typeent = TypeEnt::BACKGROUND
	});

	sf::Texture textureplayer;
	sf::Sprite playsprite;
	
	for (int i = 0; i < 4; i++) {
		if (!textureplayer.loadFromFile("resources/ship" + std::to_string(i) + ".gif"))
			exit(84);
		playsprite.setTexture(textureplayer);
		playsprite.setScale(160 / playsprite.getLocalBounds().width, 80 / playsprite.getLocalBounds().height);
		playerentity[i] = moteur.createEntity();
		moteur.addComponent(playerentity[i], Drawable{
			.position = sf::Vector2f(70, 170), 
			.size = sf::Vector2f(160, 80),
			.texture = textureplayer,
			.bulletsprite = playsprite,
			.id = i
		});
		moteur.addComponent(playerentity[i], Movable{
			.speed = 10,
			.direction = "",
			.typeent = TypeEnt::PLAYER
		});
		moteur.addComponent(playerentity[i], Player{
			.isplayer = 0
		});
	}
}

void Server::init()
{
    engineInit();
	setCard();
	setPlayer();
}

void Server::start()
{
	start_receive();
    io_service.run();
    asio::io_service::work work(io_service);
}

void Server::start_receive()
{
    _socket.async_receive_from(asio::buffer(recv_buffer), _remote_endpoint, [this](const asio::error_code& error, size_t bytes_transferred) {
        if (!error) {
            handle_receive(error, bytes_transferred);
        } else
            cout << "Error" << endl;
        start_receive();
    });
}

void Server::draw()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::string msg_player;
	std::string msg_ennemy;
	std::string msg_bullet;
	int old_ent = -1;
	
	send_all_client("221");
	for (auto &ent : drawSystem->update()) {
		if (old_ent == ent)
			continue;
		old_ent = ent;
    	auto &drawable = moteur.getComponent<Drawable>(ent);
    	auto &movable = moteur.getComponent<Movable>(ent);
		if (movable.typeent == TypeEnt::PLAYER)
			if (drawable.id < nextClientID)
				send_all_client("222 " + std::to_string(drawable.id + 5) + " " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y));
    	else if (movable.typeent == TypeEnt::ENNEMY)
			msg_ennemy += " " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y);
    	else if (movable.typeent == TypeEnt::BULLET)
			msg_bullet += " " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y);
    	else if (movable.typeent == TypeEnt::BACKGROUND)
			send_all_client("222 3 " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y));
		else if (movable.typeent == TypeEnt::POWERUP)
			send_all_client("222 4 " + std::to_string((int)drawable.position.x) + " " + std::to_string((int)drawable.position.y));
	}
	if (msg_ennemy.length() > 0)
		send_all_client("222 1" + msg_ennemy);
	if (msg_bullet.length() > 0)
		send_all_client("222 2" + msg_bullet);
	send_all_client("223");
}

void Server::update()
{
	draw();
    moveSystem->update(delta);
	spawner->update(delta);
	for (int i = 0; i < 4; i++)
		player->update(0, playerentity[i], _input[i]);
	if (collider->update(delta) == 42)
		send_all_client("666");
	//TODO Change code for RFC && send at one client
	for (int i = 0; i < 4; i++)
		shooter->update(delta, playerentity[i], _input[i]);
	powerupsys->update(delta);
	backgroundSystem->update(backgroundentity);
}

void Server::handleMessage(const asio::error_code& error, std::size_t bytes_transferred)
{
    std::string msg = incMessages.pop().first;
    if (msg.size() >= 3 && msg.substr(0, 3) == "111") {
        send_one_client("121 " + std::to_string(nextClientID), nextClientID);
    }
    if (msg.size() >= 7)
		if (msg.substr(0, 3) == "211") {
    		std::cout << "Received: '" << msg << "' (" << error.message() << ")\n";
        	_input[stoi(msg.substr(4, 5))] = stoi(msg.substr(6, 7));
		}
}

void Server::handle_receive(const asio::error_code& error, size_t bytes_transferred)
{
    if (!error) {
        try {
            auto message = ClientMessage(string(recv_buffer.data(), recv_buffer.data() + bytes_transferred), handle_client_id(_remote_endpoint));
            if (!message.first.empty())
                incMessages.push(message);
        }
        catch (std::exception exept) {
            cout << exept.what() << endl;
        }
		handleMessage(error, bytes_transferred);
		if (nextClientID > 0) {
			delta = clock.restart().asSeconds();
			totaltime += delta;
    		if (totaltime > 0.1) {
    		    std::cout << "1 second" << std::endl;
    		    totaltime -= 0.1;
    			update();
    		}
			send_all_client("000");
		}
	}
    start_receive();
}

void Server::send(const string& msg, udp::endpoint client_endpoint)
{
    _socket.send_to(asio::buffer(msg), client_endpoint);
}

void Server::send_one_client(const string& msg, int id)
{
    for (auto client : clients)
        if (client.first == id)
            send(msg, clients.at(id));
}
void Server::send_all_client(const string& msg)
{
    for (auto client : clients)
        send(msg, client.second);
}

int Server::handle_client_id(asio::ip::udp::endpoint endpoint)
{
    for (const auto& client : clients) {
        if (client.second == endpoint) {
			std::cout << "Client => " << client.first << std::endl;
            return client.first;
		}
	}
    auto id = ++nextClientID;
    clients.insert(Client(id, endpoint));
    return id;
}