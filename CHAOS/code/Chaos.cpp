#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>



int main()
{
	//create window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chaos Game");

	//load font 
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");


	//create dialogue for user
	sf::Text text;
	text.setFont(font);
	text.setString("Pick a number 1-3 from keyboard \n|| 1 = Triangle - 3 Vertices|| \n|| 2 = Square - 4 Vertices ||\n|| 3 = Pentagon - 5 Vertices||");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);

	//create shape
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(1, 1));
	shape.setFillColor(sf::Color::White);

	//vector variables used to create 3 vertices ,position and 
	//hold the last position 
	sf::Vector2i a, b, c, d, e, z, position, lastPos;
	int count = 0;
	int i = 0;
	int temp = 0;
	int randX = 3;
	int j = 0;


	while (window.isOpen())
	{
		window.draw(text);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			i = 3;
			temp = 3;
			j = 1;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		{
			i = 4;
			temp = 4;
			j = 1;


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		{
			i = 5;
			temp = 5;
			j = 1;


		}
		if (j == 1)
		{
			window.clear();
			text.setString("Click vertices for you shape chosen then an extra one inside your points to get started");
			window.draw(text);

		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				position = sf::Mouse::getPosition(window);
				shape.setPosition(position.x, position.y);

				if (count == 0)
				{

					//store the position of the first vertex into vector A
					a.x = position.x;
					a.y = position.y;
					shape.setFillColor(sf::Color::Red);

				}
				if (count == 1)
				{
					//store the position of the second vertex into vector B
					b.x = position.x;
					b.y = position.y;
					shape.setFillColor(sf::Color::Red);


				}
				if (count == 2)
				{
					//store the position of the second vertex into vector C
					c.x = position.x;
					c.y = position.y;


				}
				if (i == 4 || i == 5)
				{
					if (count == 3)
					{
						d.x = position.x;
						d.y = position.y;

					}
				}
				if (i == 5)
				{
					if (count == 4)
					{
						e.x = position.x;
						e.y = position.y;

					}
				}
				if (count == temp)
				{
					//the last vertex  will be stored in the vector lastPos to use in the formula
					lastPos.x = position.x;
					lastPos.y = position.y;
					shape.setFillColor(sf::Color::Green);

				}
				count++;
				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		//after initializing the requirements to create the triangle 
		//the 4th count or more clicks will trigger the loop to start
		if (count > temp)
		{
			//sets the color to white 
			shape.setFillColor(sf::Color::White);
			int lastRand = -1;

			if (i == 4) { randX = 4; }
			if (i == 5) { randX = 5; }
			//in this loop, the size is adjustable
			for (size_t i = 0; i < 9999; i++)
			{
				//genRand grabs a random number from 0,1,2
				int genRand = rand() % randX;
				if (genRand != lastRand)
				{
					if (genRand == 0)
					{
						//used the midpoint formula if genRand == 0
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + a.x) / 2;
						z.y = (lastPos.y + a.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						if (randX == 4 || randX == 5) { lastRand = genRand; }


					}
					if (genRand == 1)
					{
						//used the midpoint formula if genRand == 1
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + b.x) / 2;
						z.y = (lastPos.y + b.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						if (randX == 4 || randX == 5) { lastRand = genRand; }
					}
					if (genRand == 2)
					{
						//used the midpoint formula if genRand == 2
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + c.x) / 2;
						z.y = (lastPos.y + c.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						if (randX == 4 || randX == 5) { lastRand = genRand; }
					}
					if (genRand == 3)
					{
						//used the midpoint formula if genRand == 4
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + d.x) / 2;
						z.y = (lastPos.y + d.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
					if (genRand == 4)
					{
						//used the midpoint formula if genRand == 5
						//x1+x2   y1+y2
						//----- , -----
						//	2		2
						z.x = (lastPos.x + e.x) / 2;
						z.y = (lastPos.y + e.y) / 2;
						// using the midpoint to store it in the lastPos to use for further iterations
						lastPos.x = z.x;
						lastPos.y = z.y;
						lastRand = genRand;
					}
				}
				//after genRand picks a vertex and sets the midpoint, the shape is set in that coordinates
				shape.setPosition(z.x, z.y);

			}
		}


		window.draw(shape);

		window.display();




	}
	return 0;
}


