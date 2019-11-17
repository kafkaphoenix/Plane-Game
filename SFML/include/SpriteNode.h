#ifndef SPRITENODE_H
#define SPRITENODE_H

#include <SceneNode.h>

#include <SFML/Graphics/Sprite.hpp>

class SpriteNode : public SceneNode
{
    public:
        explicit SpriteNode(const sf::Texture& );
        SpriteNode(const sf::Texture& , const sf::IntRect& );

    private:
        virtual void drawCurrent(sf::RenderTarget& , sf::RenderStates ) const;

    private:
        sf::Sprite mSprite;
};

#endif // SPRITENODE_H
