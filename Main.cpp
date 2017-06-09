#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{
	sf::Vector2f shapePos;
	sf::Vector2u windowSize;
	float Lungime, Latime, va = 0, vd = 0, vs = 0, vw = 0;
	int max1 = 0, max2 = 0, max3 = 0, max4 = 0;
	/* cout << "dimensiuni dreptunghi "; cout <<endl<< "Lungime = "; cin >> Lungime; cout << endl; cout << "Latime = "; cin >> Latime; cout << endl; */
	Lungime = 10; Latime = 10;
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	sf::RectangleShape player(sf::Vector2f(Lungime, Latime));

	windowSize = window.getSize();
	
	sf::RectangleShape bg(sf::Vector2f(windowSize.x, windowSize.y));
	player.setFillColor(sf::Color(0, 0, 200, 255));
	bg.setFillColor(sf::Color::White);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition(mousePos.x, mousePos.y);

		}

		shapePos = player.getPosition();

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && (shapePos.x > 0))
		{
			player.move(-0.08f - va / 100000, 0.0f); va += 15;  if (int(va / 1000) > max1) { max1 = va / 1000; cout << "VA = " << max1 << endl; }
		}
		else { va = 0; max1 = 0; }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && (shapePos.x < windowSize.x - Lungime))
		{
			player.move(0.08f + vd / 100000, 0.0f); vd += 15;  if (int(vd / 1000) > max2) { max2 = vd / 1000; cout << "VD = " << max2 << endl; };
		}
		else { vd = 0; max2 = 0; }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && (shapePos.y > 0))
		{
			player.move(0.0f, -0.08f - vw / 100000); vw += 15; if (int(vw / 1000) > max3) { max3 = vw / 1000; cout << "VW = " << max3 << endl; }
		}
		else { vw = 0; max3 = 0; }
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && (shapePos.y<windowSize.y - Latime))
		{
			player.move(0.0f, 0.08f + vs / 100000); vs += 15;
			if (int(vs / 1000) > max4) { max4 = vs / 1000; cout << "VS = " << max4 << endl; }
		}
		else { vs = 0; max4 = 0; }


		window.clear();
		window.draw(bg);
		window.draw(player);
		window.display();
	}

	return 0;
}