/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** ecs
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#define MAX_ENTITY 100
#define MAX_COMPONENT 16
// #define Card std::bitset<MAX_COMPONENTS>
#include <SFML/Graphics.hpp>
#include <bitset>
#include <queue>
#include <iostream>
#include <map>
#include <typeinfo>
#include <memory>
#include <set>
#include <thread>
#include <future>

// int Entity; int componentType;

class EntityHandler {
    public:
        EntityHandler();
        ~EntityHandler() {}
        int createEntity()
        {
            int id;

            if (this->_currentNbEntity > MAX_ENTITY) {
                std::cerr << "Too many entities" << std::endl;
                exit(84);
            }
            id = this->_availableEntitySpace.front();
            this->_availableEntitySpace.pop();
            this->_currentNbEntity++;

            return (id);
        }
        void destroyEntity(int entity)
        {
            if (entity > MAX_ENTITY) {
                std::cerr << "Entity out of range" << std::endl;
                exit(84);
            }
            this->_cards[entity].reset(); // Ici on fait disparaître la carte de l'entité
            this->_availableEntitySpace.push(entity);
            this->_currentNbEntity--;
        }
        void setCard(int entity, std::bitset<MAX_COMPONENT> card)
        {
            if (entity > MAX_ENTITY) {
                std::cerr << "Entity out of range" << std::endl;
                exit(84);
            }
            this->_cards[entity] = card;
        }
        std::bitset<MAX_COMPONENT> getCard(int entity)
        {
            if (entity > MAX_ENTITY) {
                std::cerr << "Entity out of range" << std::endl;
                exit(84);
            }
            return (this->_cards[entity]);
        }
    private:
        std::queue<int> _availableEntitySpace;
        // une card est un std::bitset<MAX_COMPONENT> l'array est un array de card
        std::array<std::bitset<MAX_COMPONENT>, MAX_ENTITY> _cards;
        int _currentNbEntity;

};


/**
 * Components
 **/

class IComponentArray {
    public:
        virtual ~IComponentArray() = default;
        virtual void entityDestroyed(int entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray // Ici les fonctions sont écrites ici car j'ai pas réussi à les mettre dans un fichier cpp
{
    public:
        ComponentArray() {}
        ~ComponentArray() {}
        void insertData(int entity, T component)
        {
            int newindex;

            if (_entityToIndex.find(entity) != _entityToIndex.end()) {
                std::cout << "Component already added to entity" << std::endl;
                exit(84);
            }
            newindex = _size;
            _entityToIndex[entity] = newindex;
            _indexToEntity[newindex] = entity;
            _componentArray[newindex] = component;
            _size++;
        }                                                                                                                                                                                                                                                                                                                                                           

        void removeData(int entity)
        {
            int indexofremoved;
            int indexoflast;
            int entityOfLastElem;

            if (_entityToIndex.find(entity) == _entityToIndex.end()) {
                std::cout << "Component in remove data doesn't exist" << std::endl;
                exit(84);
            }
            indexofremoved = _entityToIndex[entity];
            indexoflast = _size - 1;
            _componentArray[indexofremoved] = _componentArray[indexoflast];

            entityOfLastElem = _indexToEntity[indexoflast];
            _entityToIndex[entityOfLastElem] = indexofremoved;
            _indexToEntity[indexofremoved] = entityOfLastElem;

            _entityToIndex.erase(entity);
            _indexToEntity.erase(indexoflast);
            _size--;
        }

        T &getData(int entity)
        {
            if (_entityToIndex.find(entity) == _entityToIndex.end()) {  
                std::cout << "Component in get data doesn't exist " << entity << std::endl;
                exit(84);
            }
            return (_componentArray[_entityToIndex[entity]]);
        }

        void entityDestroyed(int entity) override
        {
            if (_entityToIndex.find(entity) != _entityToIndex.end())
                removeData(entity);
        }

    private:
        std::array<T, MAX_ENTITY> _componentArray{};
        std::map<int, int> _entityToIndex;
        std::map<int, int> _indexToEntity;
        int _size{};
};

class ComponentHandler {
    public:
        ComponentHandler() {}
        ~ComponentHandler() {}
        template<typename T>
        void newComponent()
        {
            const char *nameoftype = typeid(T).name();

            if (this->_componenttypes.find(nameoftype) != this->_componenttypes.end()) {
                std::cerr << "Component already exists" << std::endl;
                exit(84);
            }
            this->_componenttypes.insert({nameoftype, this->_nextcomtype});
            this->_componentarray.insert({nameoftype, std::make_shared<ComponentArray<T>>()});
            
            this->_nextcomtype++;
        }

        template<typename T>
        int getComponentType()
        {
            const char *nameoftype = typeid(T).name();

            if (this->_componenttypes.find(nameoftype) == this->_componenttypes.end()) {
                std::cerr << "Component hasn't been created: " << std::endl;
                exit(84);
            }

            return (this->_componenttypes[nameoftype]);
        }

        template<typename T>
        void addComponent(int entity, T component)
        {
            getComponentArray<T>()->insertData(entity, component);
        }

        template<typename T>
        void removeComponent(int entity)
        {
            getComponentArray<T>()->removeData(entity);
        }

        template<typename T>
        T &getComponent(int entity) {
            return (getComponentArray<T>()->getData(entity));
        }

        void entityDestroyed(int entity)
        {
            for (auto &item : this->_componentarray) {                
                auto &component = item.second;

                component->entityDestroyed(entity);
            }
        }

    private:
        std::map<const char *, int> _componenttypes;
        std::map<const char *, std::shared_ptr<IComponentArray>> _componentarray;
        int _nextcomtype{}; // les {} equivallent à faire nextcomtype = 0

        template<typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray()
        {
            const char *nameoftype = typeid(T).name();

            if (this->_componenttypes.find(nameoftype) == this->_componenttypes.end()) {
                std::cerr << "Component hasn't been created" << std::endl;
                exit(84);
            }

            return (std::static_pointer_cast<ComponentArray<T>>(_componentarray[nameoftype]));
        }
};


/**
 * System
 **/

class System { // Classe de base pour créer des systèmes qui vont hériter de cette classe
    public:
        System() {}
        ~System() {}
        std::set<int> _entities;
    private:
};

class SystemHandler {
    public:
        SystemHandler() {}
        ~SystemHandler() {}
        template<typename T>
        std::shared_ptr<T> newSystem()
        {
            const char *nameoftype = typeid(T).name();

            if (this->_systems.find(nameoftype) != this->_systems.end()) {
                std::cerr << "System already exists" << std::endl;
                exit(84);
            }
            auto system = std::make_shared<T>();
            this->_systems.insert({nameoftype, system});

            return (system);
        }

        template<typename T>
        void setCard(std::bitset<MAX_COMPONENT> card)
        {
            const char *nameoftype = typeid(T).name();

            if (this->_systems.find(nameoftype) == this->_systems.end()) {
                std::cerr << "System hasn't been created" << std::endl;
                exit(84);
            }

            this->_cards.insert({nameoftype, card});
        }

        void entityDestroyed(int entity)
        {
            for (auto &item : this->_systems) {
                auto &system = item.second;
                system->_entities.erase(entity);
            }
        }
        void entityCardChanged(int entity, std::bitset<MAX_COMPONENT> entitycard)
        {
            for (auto &item : this->_systems) {
                auto &type = item.first;
                auto &system = item.second;
                auto &systemcard = this->_cards[type];

                if ((entitycard & systemcard) == systemcard)
                    system->_entities.insert(entity);
                else
                    system->_entities.erase(entity);
            }
        }
    private:
        std::map<const char *, std::bitset<MAX_COMPONENT>> _cards;
        std::map<const char *, std::shared_ptr<System>> _systems;
};


/**
 * Engine
 **/

class Engine {
    public:

        Engine() {}
        ~Engine() {}

        void init();

        // Creation d'entité
        int createEntity()
        {
            return (this->_entityhandler->createEntity());
        }
        void destroyEntity(int entity)
        {
            this->_entityhandler->destroyEntity(entity);
            this->_systemhandler->entityDestroyed(entity);
            this->_componenthandler->entityDestroyed(entity);
        }

        // Pour les components
        template<typename T>
        void newComponent() 
        { 
            this->_componenthandler->newComponent<T>();
        }

        template<typename T>
        void addComponent(int entity, T component)
        {
            this->_componenthandler->addComponent<T>(entity, component);
            auto card = this->_entityhandler->getCard(entity);
            card.set(this->_componenthandler->getComponentType<T>(), true);
            this->_entityhandler->setCard(entity, card);
            this->_systemhandler->entityCardChanged(entity, card);
        }

        template<typename T>
        void removeComponent(int entity)
        {
            this->_componenthandler->removeComponent<T>(entity);
            auto card = this->_entityhandler->getCard(entity);
            card.set(this->_componenthandler->getComponentType<T>(), false);
            this->_entityhandler->setCard(entity, card);
            this->_systemhandler->entityCardChanged(entity, card);
        }

        template<typename T>
        T &getComponent(int entity)
        {
            return this->_componenthandler->getComponent<T>(entity);
        }

        template<typename T>
        int getComponentType()
        {
            return (this->_componenthandler->getComponentType<T>());
        }

        // Pour les sytèmes
        template<typename T>
        std::shared_ptr<T> newSystem()
        {
            return (this->_systemhandler->newSystem<T>());
        }

        template<typename T>
        void setSystemCard(std::bitset<MAX_COMPONENT> card)
        {
            this->_systemhandler->setCard<T>(card);
        }
    private:
        std::unique_ptr<ComponentHandler> _componenthandler;
        std::unique_ptr<EntityHandler> _entityhandler;
        std::unique_ptr<SystemHandler> _systemhandler;
};
#endif /* !ECS_HPP_ */
