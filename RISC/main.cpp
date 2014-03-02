/*
#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gtk/gtk.h>

void on_destroy(GtkWidget *widget G_GNUC_UNUSED, gpointer user_data G_GNUC_UNUSED)
{
	gtk_main_quit();
}

int main(int argc, char *argv[])
{
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/
#include <SFML/Graphics.hpp>
#include "GUI\UnitPainter.h"

using namespace sf;

int main()
{
	UnitPainter* up = new UnitPainter();

	sf::RenderWindow window(sf::VideoMode(1024, 650), "RISC");
	
	sf::Texture bg;
	bg.loadFromFile("C:\\map.jpg");
	sf::Sprite sprite;
	sprite.setTexture(bg);

	Vector2f vec(20,20);
	RectangleShape rect(vec);
	rect.setFillColor(up->getMoney());
	//rect.setFillColor(Color::Red);
	rect.setPosition(50, 50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sprite);
		window.draw(rect);
		window.display();
	}

	return 0;
}