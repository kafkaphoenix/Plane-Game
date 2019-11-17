#include "MenuState.h"
#include "Utility.h"
#include "ResourceHolder.h"
#include "Foreach.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

MenuState::MenuState(StateStack& stack, Context context)
: State(stack, context)
, mOptions()
, mOptionIndex(0)
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    sf::Font& font = context.fonts->get(Fonts::Main);

    mBackgroundSprite.setTexture(texture);

    sf::Text playOption;
    playOption.setFont(font);
    playOption.setString("Play");
    centerOrigin(playOption);
    playOption.setPosition(context.window->getView().getSize() / 2.f);
    mOptions.push_back(playOption);

    sf::Text exitOption;
    exitOption.setFont(font);
    exitOption.setString("Exit");
    centerOrigin(exitOption);
    exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
    mOptions.push_back(exitOption);

    updateOptionText();
}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);

    FOREACH(const sf::Text& text, mOptions)
    {
        window.draw(text);
    }
}

bool MenuState::update(sf::Time dt)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    if(event.type != sf::Event::KeyPressed)
    {
        return false;
    }

    switch (event.key.code)
    {
    case sf::Keyboard::Return:
        switch (mOptionIndex)
        {
        case Play:
            requestStackPop();
            requestStackPush(States::Game);
            break;
        case Exit:
            requestStackPop();
            break;
        }
        break;
    case sf::Keyboard::Up:
         if(mOptionIndex > 0)
         {
             mOptionIndex--;
         }
         else
         {
             mOptionIndex = mOptions.size() - 1;
         }
         updateOptionText();
         break;
    case sf::Keyboard::Down:
        if(mOptionIndex < mOptions.size() - 1)
        {
            mOptionIndex++;
        }
        else
        {
            mOptionIndex = 0;
        }
        updateOptionText();
        break;
    }

    return true;
}

void MenuState::updateOptionText()
{
    if(mOptions.empty()){
        return;
    }

    FOREACH(sf::Text& text, mOptions)
    {
        text.setColor(sf::Color::White);
    }

     mOptions[mOptionIndex].setColor(sf::Color::Blue);
}
