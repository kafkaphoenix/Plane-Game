#ifndef PLAYER_H
#define PLAYER_H

#include "Command.h"

#include <SFML/Window/Event.hpp>

#include <map>

class CommandQueue;

class Player
{
    public:
        enum Action
        {
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown,
            ActionCount
        };

    public:
        Player();
        void handleEvent(const sf::Event& , CommandQueue& );
        void handleRealtimeInput(CommandQueue& );
        void assignKey(Action , sf::Keyboard::Key );
        sf::Keyboard::Key getAssignedKey(Action ) const;

    private:
        void initializeActions();
        static bool isRealtimeAction(Action );

    private:
        std::map<sf::Keyboard::Key, Action> mKeyBinding;
        std::map<Action, Command> mActionBinding;
};

#endif // PLAYER_H
