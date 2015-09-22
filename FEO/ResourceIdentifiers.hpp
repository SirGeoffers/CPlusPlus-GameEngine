
#ifndef RESOURCE_IDENTIFIERS_HPP
#define RESOURCE_IDENTIFIERS_HPP

namespace sf {
	class Texture;
	class Font;
}

namespace Textures {
	enum ID {
		TitleScreen,
		GameBackground,
		Person
	};
}

namespace Fonts {
	enum ID {
		Main
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif // RESOURCE_IDENTIFIERS_HPP