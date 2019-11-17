#ifndef SCENENODE_H
#define SCENENODE_H

#include "Category.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>
#include <vector>

struct Command;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;

    public:
        SceneNode();
        void attachChild(Ptr );
        Ptr detachChild(const SceneNode& );
        void update(sf::Time );
        sf::Vector2f getWorldPosition() const;
        sf::Transform getWorldTransform() const;
        virtual unsigned int getCategory() const;
        void onCommand(const Command& , sf::Time );

    private:
        virtual void updateCurrent(sf::Time );
        void updateChildren(sf::Time );
        virtual void draw(sf::RenderTarget& , sf::RenderStates ) const;
        virtual void drawCurrent(sf::RenderTarget& , sf::RenderStates ) const;
        void drawChildren(sf::RenderTarget& , sf::RenderStates ) const;

    private:
        std::vector<Ptr> mChildren;
        SceneNode* mParent;
};

#endif // SCENENODE_H
