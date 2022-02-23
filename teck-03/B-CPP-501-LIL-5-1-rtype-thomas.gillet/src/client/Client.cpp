/*
** EPITECH PROJECT, 2021
** client [WSL: Ubuntu]
** File description:
** Client
*/

#include "Client.hpp"


Client::Client(boost::asio::io_service& io_service, const std::string& host, const std::string& port) : id(-1), io_service(io_service), socket(io_service, udp::endpoint(udp::v4(), 0)) {
	udp::resolver resolver(io_service);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint = *iter;

	boost::asio::ip::address remote_ad = endpoint.address();
	std::string s = remote_ad.to_string();
	std::cout << "Connecting client to " << s <<  std::endl;
}

Client::~Client()
{
	socket.close();
}

void Client::send(const std::string& msg)
{
	socket.send_to(boost::asio::buffer(msg, msg.size()), endpoint);
}

void Client::handleKeyboard()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    	send("211 " + std::to_string(id) + " 0");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    	send("211 " + std::to_string(id) + " 1");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    	send("211 " + std::to_string(id) + " 2");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    	send("211 " + std::to_string(id) + " 3");
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    	send("211 " + std::to_string(id) + " 4");
}

void Client::draw(const std::string &msg)
{
	int pos_x = 0;
	int pos_y = 0;
	std::size_t start;
	std::size_t end = 0;
	std::vector<std::string> out;
	int input;

	while ((start = msg.find_first_not_of(' ', end)) != std::string::npos) {
		end = msg.find(' ', start);
		out.push_back(msg.substr(start, end - start));
	}
		pos_x = stof(out[2]);
		pos_y = stof(out[3]);
		input = stoi(out[1]);
		for (int i = 2; i < out.size() - 1; i += 2)
		{
			pos_x = stof(out[i]);
			pos_y = stof(out[i + 1]);
			switch (input)
			{
			case 5:
				playerSprite[0].setPosition(pos_x, pos_y);
				window.draw(playerSprite[0]);
				break;
			case 6:
				playerSprite[1].setPosition(pos_x, pos_y);
				window.draw(playerSprite[1]);
				break;
			case 7:
				playerSprite[2].setPosition(pos_x, pos_y);
				window.draw(playerSprite[2]);
				break;
			case 8:
				playerSprite[3].setPosition(pos_x, pos_y);
				window.draw(playerSprite[3]);
				break;
			case TypeEnt::ENNEMY:
				enemySprite.setPosition(pos_x, pos_y);
				window.draw(enemySprite);
				break;
			case TypeEnt::BULLET:
				bulletSprite.setPosition(pos_x, pos_y);
				window.draw(bulletSprite);
				break;
			case TypeEnt::BACKGROUND:
				backgroundSprite.setPosition(pos_x, pos_y);
				window.draw(backgroundSprite);
				break;
			case TypeEnt::POWERUP:
				powerUpSprite.setPosition(pos_x, pos_y);
				window.draw(powerUpSprite);
				break;
			default:
				break;
			}
		}
}

void Client::handleCommand(const boost::system::error_code& error, size_t bytes_transferred)
{
    std::string msg;
	
	msg = std::string(recv_buffer.begin(), recv_buffer.begin() + bytes_transferred);
	if (msg.substr(0, 3) != "000") 
		std::cout << "Received: '" << msg << "' (" << error.message() << ")\n";
	
	if (msg.length() >= 3 && msg.substr(0, 3) == "121") {
		id = stoi(msg.substr(4, 5));
		std::cout << "ID of Client is " << id << std::endl;
		send("112 " + std::to_string(id));
		init();
	} else if (msg.length() >= 3 && msg.substr(0, 3) == "221")
		window.clear();
	else if (msg.length() >= 3 && msg.substr(0, 3) == "223")
		window.display();
	else if (msg.length() >= 3 && msg.substr(0, 3) == "666") {
		window.close();
		std::cout << "Game Over !" << std::endl;
		exit (0);
	}
	else if (msg.length() >= 3 && msg.substr(0, 3) == "222") {
		draw(msg);
	}
	else if (msg.length() >= 3 && msg.substr(0, 3) == "000") {
		send("000");
	}
}

void Client::handle_receive(const boost::system::error_code& error, size_t bytes_transferred) 
{
	while(window.pollEvent(event)) {
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
			exit(0);
		}
	}
	handleKeyboard();
	if (error) {
        std::cout << "Receive failed: " << error.message() << "\n";
        return;
    }
	handleCommand(error, bytes_transferred);
	wait();
}

void Client::wait() {
    socket.async_receive_from(boost::asio::buffer(recv_buffer),
    						  endpoint,
                              boost::bind(&Client::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Client::receive()
{
    wait();

    std::cout << "Receiving\n";
    io_service.run();
    std::cout << "Receiver exit\n";
}

void Client::init()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "R-Type");
    window.setFramerateLimit(60);

	for (int i = 0; i < 4; i++) {
		if (!playerTexture[i].loadFromFile("resources/ship" + std::to_string(i) + ".gif"))
				exit(84);
		playerSprite[i].setTexture(playerTexture[i]);
		playerSprite[i].setScale(160 / playerSprite[i].getLocalBounds().width, 80 / playerSprite[i].getLocalBounds().height);
	}
	if (!bulletTexture.loadFromFile("resources/bullet.gif"))
			exit(84);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(20 / bulletSprite.getLocalBounds().width, 20 / bulletSprite.getLocalBounds().height);

	if (!enemyTexture.loadFromFile("resources/bydos.gif"))
			exit(84);
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(100 / enemySprite.getLocalBounds().width, 100 / enemySprite.getLocalBounds().height);

	if (!powerUpTexture.loadFromFile("resources/belette.png"))
			exit(84);
	powerUpSprite.setTexture(powerUpTexture);
	powerUpSprite.setScale(100 / powerUpSprite.getLocalBounds().width, 100 / powerUpSprite.getLocalBounds().height);

	if (!backgroundTexture.loadFromFile("resources/mountainback.png"))
			exit(84);
	backgroundSprite.setTexture(backgroundTexture);
}

int main()
{
	boost::asio::io_service io_service;
	Client client(io_service, "10.26.107.251", "4242");
	std::thread r([&] { client.receive(); });
	bool start = true;
	
    client.send("111");

 	r.join();
	return 0;
}
