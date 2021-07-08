#include <SFML/Graphics.hpp>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

double const eps = 0.2;

struct less {
  bool operator()(double l, double r) const { return l < r; }
  using is_transparent = void;
  bool operator()(int l, double r) const { return l + eps < r; }
  bool operator()(double l, int r) const { return l + eps < r; }
};

int main() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Voronoi Diagram");

  auto icon = sf::Image();
#ifdef unix
  if (!icon.loadFromFile("(../images/icon.png)"))
#else
  if (!icon.loadFromFile(R"(..\images\icon.png)"))
#endif //unix
    return EXIT_FAILURE;
  window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

  // Limit the framerate to 60 frames per second (this step is optional)
  window.setFramerateLimit(120);

  window.setVerticalSyncEnabled(true);

  sf::RectangleShape sweep_line(sf::Vector2f(150.f, 5.f));
  sweep_line.rotate(90.f);
  sweep_line.setPosition(window.getSize().x / 2, window.getSize().y / 2);
  sweep_line.setFillColor(sf::Color::Red);
  sweep_line.setOutlineThickness(2);

  /*
  // Load a sprite to display
  sf::Texture texture;
#ifdef unix
  if (!texture.loadFromFile("(../images/visualization.png)"))
#else
  if (!texture.loadFromFile(R"(..\images\visualization.png)"))
#endif //unix
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);
  */



  // Start the game loop
  while (window.isOpen()) {
    // Process events
    sf::Event event{};
    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Activate the window for OpenGL rendering
    window.setActive();

    // Here is the main code of drawing

    // Clear screen
    window.clear(sf::Color(255, 255, 255, 0));
    window.draw(sweep_line);

    // Draw the sprite
    //window.draw(sprite);

    // Update the window
    window.display();
  }
  return EXIT_SUCCESS;
}
