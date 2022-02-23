#include "sfmlgraphic.hpp"

void createBoxes(Graphibox *b)
{
    info my_info;

    b->addBox(20);
    b->addBox(90);
    b->addBox(160);
    b->addBox(230);
    b->addBox(300);
    b->addBox(370);
    b->addBox(440);
    b->addBox(510);
    b->addBox(580);
    b->addBox(650);
    b->addBox(720);

    b->addText(my_info.getUsername(), 25);
    b->addText(my_info.getHostname(), 95);
    b->addText(my_info.getSysname(), 165);
    b->addText(my_info.getKernelver(), 235);
    b->addText(my_info.getDate(), 315);
    b->addText("RAM Usage (in %) ->", 385);
    b->addText("CPU Usage (in %) ->", 455);
    b->addText("CPU Model :\n" + my_info.getCpu().getModel(), 515);
    b->addText("Number of cores :\n" + my_info.getCpu().getNbcore(), 585);
    b->addText("Activity :\n" + my_info.getCpu().getActivity(), 655);
    b->addText("Frequency :\n" + my_info.getCpu().getFrequency(), 725);
}

int my_sfml()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "GCore", sf::Style::Titlebar | sf::Style::Close);
    
    info my_info;
    int change = 0;
    int change2 = 0;

    sf::RectangleShape ramusage(sf::Vector2f(30, 600));
    sf::Color red(222, 82, 82);
    ramusage.setFillColor(red);
    ramusage.setPosition(500, 20);
    sf::RectangleShape ramusage2 = ramusage;
    ramusage2.setFillColor(sf::Color::White);

    sf::RectangleShape cpuusage(sf::Vector2f(30, 600));
    sf::Color blue(129, 184, 239);
    cpuusage.setFillColor(blue);
    cpuusage.setPosition(630, 20);
    sf::RectangleShape cpuusage2 = cpuusage;
    cpuusage2.setFillColor(sf::Color::White);

    Graphibox b;
    createBoxes(&b);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        
        change = (my_info.getRam().reset()) * 6;
        change2 = (my_info.getCpu().reset()) * 6;
        // std::cout << "change2 : " << change2 << std::endl;
        ramusage.setSize(sf::Vector2f(30, change));
        cpuusage.setSize(sf::Vector2f(30, change2));

        window.draw(ramusage2);
        window.draw(ramusage);
        window.draw(cpuusage2);
        window.draw(cpuusage);
        b.my_display(window, my_info);
        window.display();
    }
    return 0;
}