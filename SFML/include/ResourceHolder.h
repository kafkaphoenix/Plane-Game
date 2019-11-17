#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <string>
#include <memory>

template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void load(Identifier , const std::string& );
        template<typename Parameter>
        void load(Identifier , const std::string& , const Parameter& );
        Resource& get(Identifier );
        const Resource& get(Identifier ) const;

    private:
        void insertResource(Identifier , std::unique_ptr<Resource> );

    private:
        std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

};

#include "ResourceHolder.inl"
#endif // RESOURCEHOLDER_H
