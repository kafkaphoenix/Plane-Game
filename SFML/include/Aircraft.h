#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity
{
    public:
        enum Type
        {
            Eagle,
            Raptor,
        };

    public:
        Aircraft(Type, const TextureHolder& );
        virtual unsigned int getCategory() const;

    private:
        virtual void drawCurrent(sf::RenderTarget& ,
                                 sf::RenderStates ) const;

    private:
        Type mType;
        sf::Sprite mSprite;
};

#endif // AIRCRAFT_H
