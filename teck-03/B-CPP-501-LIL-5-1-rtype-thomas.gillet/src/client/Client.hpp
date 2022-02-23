#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using boost::asio::ip::udp;
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

enum TypeEnt {
        PLAYER,
        ENNEMY,
        BULLET,
        BACKGROUND,
        POWERUP
};

class Client
{
public:
	Client(boost::asio::io_service& io_service, const std::string& host, const std::string& port);
	~Client();

	void init();
	void send(const std::string& msg);
	void receive();
	void wait();
	void handle_receive(const boost::system::error_code& error, size_t bytes_transferred);
	void handleKeyboard();
	void handleCommand(const boost::system::error_code& error, size_t bytes_transferred);
	void draw(const std::string &msg);

	boost::asio::io_service& io_service;
	udp::socket socket;
	udp::endpoint endpoint;
	boost::array<char, 1024> recv_buffer;
	unsigned short id;

	std::array<sf::Texture, 4> playerTexture;
	std::array<sf::Sprite, 4> playerSprite;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::Texture powerUpTexture;
	sf::Sprite powerUpSprite;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::RenderWindow window;
	sf::Event event;
};