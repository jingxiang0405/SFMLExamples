#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

const int window_width = 2400;
const int window_height = 1600;

int main()
{
    srand(time(nullptr));
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Sprite and Texture");
    window.setFramerateLimit(60); 
  //Loading a texture
    sf::Texture texture;
    if(texture.loadFromFile("dong.png")){
    std::cout << "Image loaded successfully with size: ";
    std::cout << texture.getSize().x <<", "<<texture.getSize().y<<"\n";
    }else{
        std::cout << "Error at loading image\n";

  }
    sf::Sprite sprite(texture);
    sf::Vector2<float> scale(0.5, 0.5); 
    sprite.setScale(scale);

    int borderX = window_width-(texture.getSize().x*scale.x);
    int borderY = window_height-(texture.getSize().y*scale.y);
    float x = rand()%(borderX+1);
    float y = 0.0F;
    sf::Clock clock;
    float speedX = 10.0F;
    float speedY = 10.0F;
    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        float fps = 1.0/ (currentTime);
        // std::cout<< "fps = "<<fps <<"\n";

      //moving the sprite
        if(x >= borderX || x<0)speedX*=-1;
        if(y >= borderY || y<0)speedY*=-1;
        x+=speedX;
        y+=speedY;
        sprite.setPosition(x, y);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
