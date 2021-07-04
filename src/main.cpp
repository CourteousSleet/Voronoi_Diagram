#include <SFML/Graphics.hpp>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

double const eps = 0.2;

struct less
{
  bool operator () (double l, double r) const { return l < r; }
  using is_transparent = void;
  bool operator () (int l, double r) const { return l + eps < r; }
  bool operator () (double l, int r) const { return l + eps < r; }
};

int main() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Voronoi Diagram");

  // Limit the framerate to 60 frames per second (this step is optional)
  window.setFramerateLimit(120);

  // Load a sprite to display
  sf::Texture texture;
#ifdef unix
  if (!texture.loadFromFile("(../images/visualization.png)"))
#else
  if (!texture.loadFromFile(R"(..\images\visualization.png)"))
#endif //unix
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);




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

    /* Here is the main code of drawing with OpenGL
     *
     */

    // Clear screen
    window.clear();
    // Draw the sprite
    window.draw(sprite);
    // Update the window
    window.display();
  }
  return EXIT_SUCCESS;
}
