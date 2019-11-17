#ifndef WORLD_H
#define WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Aircraft.h"
#include "Command.h"
#include "CommandQueue.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time );
        void draw();
        CommandQueue& getCommandQueue();

    private:
        void loadTextures();
        void buildScene();
        void adaptPlayerPosition();
        void adaptPlayerVelocity();

    private:
        enum Layer
        {
            Background,
            Air,
            LayerCount
        };

    private:
        sf::RenderWindow& mWindow;
        sf::View mWorldView;
        TextureHolder mTextures;
        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;
        CommandQueue mCommandQueue;
        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;
        float mScrollSpeed;
        Aircraft* mPlayerAircraft;
};

#endif // WORLD_H
