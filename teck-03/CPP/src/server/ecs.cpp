/*
** EPITECH PROJECT, 2021
** B-CPP-501-LIL-5-1-rtype-thomas.gillet
** File description:
** ecs
*/

#include "ecs.hpp"

/**
 * Entity
 **/

EntityHandler::EntityHandler()
{
    for (int entity = 0; entity < MAX_ENTITY; entity++) {
        this->_availableEntitySpace.push(entity);
    }
}

// int EntityHandler::createEntity()
// {
//     int id;

//     if (this->_currentNbEntity > MAX_ENTITY) {
//         std::cerr << "Too many entities" << std::endl;
//         exit(84);
//     }
//     id = this->_availableEntitySpace.front();
//     this->_availableEntitySpace.pop();
//     this->_currentNbEntity++;

//     return (id);/**
//  * Entity
//  **/
// }

// void EntityHandler::destroyEntity(int entity)
// {
//     if (entity > MAX_ENTITY) {
//         std::cerr << "Entity out of range" << std::endl;
//         exit(84);
//     }
//     this->_cards[entity].reset(); // Ici on fait disparaître la carte de l'entité
//     this->_availableEntitySpace.push(entity);
//     this->_currentNbEntity--;
// }

// void EntityHandler::setCard(int entity, std::bitset<MAX_COMPONENT> card)
// {
//     if (entity > MAX_ENTITY) {
//         std::cerr << "Entity out of range" << std::endl;
//         exit(84);
//     }
//     this->_cards[entity] = card;
// }

// std::bitset<MAX_COMPONENT> EntityHandler::getCard(int entity)
// {
//     if (entity > MAX_ENTITY) {
//         std::cerr << "Entity out of range" << std::endl;
//         exit(84);
//     }
//     return (this->_cards[entity]);
// }


/**
 * Component
 **/

// template<typename T>
// void ComponentHandler::newComponent()
// {
//     const char *nameoftype = typeid(T).name();

//     if (this->_componenttypes.find(nameoftype) != this->_componenttypes.end()) {
//         std::cerr << "Component already exists" << std::endl;
//         exit(84);
//     }
//     this->_componenttypes.insert({nameoftype, this->_nextcomtype});
//     this->_componentarray.insert({nameoftype, std::make_shared<ComponentArray<T>>()});
    
//     this->_nextcomtype++;
// }

// template<typename T>
// int ComponentHandler::getComponentType()
// {
//     const char *nameoftype = typeid(T).name();

//     if (this->_componenttypes.find(nameoftype) == this->_componenttypes.end()) {
//         std::cerr << "Component hasn't been created" << std::endl;
//         exit(84);
//     }

//     return (this->_componenttypes[nameoftype]);
// }

// template<typename T>
// void ComponentHandler::addComponent(int entity, T component)
// {
//     getComponentArray<T>()->insertData(entity, component);
// }

// template<typename T>
// void ComponentHandler::removeComponent(int entity)
// {
//     getComponentArray<T>()->removeData(entity);
// }

// template<typename T>
// T &ComponentHandler::getComponent(int entity)
// {
//     return (getComponentArray<T>()->getData(entity));
// }

// void ComponentHandler::entityDestroyed(int entity)
// {
//     for (auto &item : this->_componentarray) {
//         auto &component = item.second;
        
//         component->entityDestroyed(entity);
//     }
// }

// template<typename T>
// std::shared_ptr<ComponentArray<T>> ComponentHandler::getComponentArray()
// {
//     const char *nameoftype = typeid(T).name();

//     if (this->_componenttypes.find(nameoftype) == this->_componenttypes.end()) {
//         std::cerr << "Component hasn't been created" << std::endl;
//         exit(84);
//     }

//     return (std::static_pointer_cast<ComponentArray<T>>(_componentarray[nameoftype]));
// }


/**
 * System
 **/

// template<typename T>
// std::shared_ptr<T> SystemHandler::newSystem()
// {
//     const char *nameoftype = typeid(T).name();

//     if (this->_systems.find(nameoftype) != this->_systems.end()) {
//         std::cerr << "System already exists" << std::endl;
//         exit(84);
//     }
//     auto system = std::make_shared<T>();
//     this->_systems.insert({nameoftype, system});

//     return (system);
// }

// template<typename T>
// void SystemHandler::setCard(std::bitset<MAX_COMPONENT> card)
// {
//     const char *nameoftype = typeid(T).name();

//     if (this->_systems.find(nameoftype) == this->_systems.end()) {
//         std::cerr << "System hasn't been created" << std::endl;
//         exit(84);
//     }

//     this->_cards.insert({nameoftype, card});
// }

// void SystemHandler::entityDestroyed(int entity)
// {
//     for (auto &item : this->_systems) {
//         auto &system = item.second;
//         system->_entities.erase(entity);
//     }
// }

// void SystemHandler::entityCardChanged(int entity, std::bitset<MAX_COMPONENT> entitycard)
// {
//     for (auto &item : this->_systems) {
//         auto &type = item.first;
//         auto &system = item.second;
//         auto &systemcard = this->_cards[type];

//         if ((entitycard & systemcard) == systemcard)
//             system->_entities.insert(entity);
//         else
//             system->_entities.erase(entity);
//     }
// }


/**
 * Engine
 **/

void Engine::init()
{
    std::cout << "Engine initialized" << std::endl;
    this->_componenthandler = std::make_unique<ComponentHandler>();
    this->_entityhandler = std::make_unique<EntityHandler>();
    this->_systemhandler = std::make_unique<SystemHandler>();
}

// int Engine::createEntity()
// {
//     return (this->_entityhandler->createEntity());
// }

// void Engine::destroyEntity(int entity)
// {
//     this->_entityhandler->destroyEntity(entity);
//     this->_systemhandler->entityDestroyed(entity);
//     this->_componenthandler->entityDestroyed(entity);
// }

// template<typename T>
// void Engine::newComponent()
// {
//     this->_componenthandler->newComponent<T>();
// }

// template<typename T>
// void Engine::addComponent(int entity, T component)
// {
//     this->_componenthandler->addComponent<T>(entity, component);
//     auto card = this->_entityhandler->getCard(entity);
// 	card.set(this->_componenthandler->getComponentType<T>(), true);
// 	this->_entityhandler->setCard(entity, card);
//     this->_systemhandler->entityCardChanged(entity, card);
// }

// template<typename T>
// void Engine::removeComponent(int entity)
// {
//     this->_componenthandler->removeComponent<T>(entity);
//     auto card = this->_entityhandler->getCard(entity);
//     card.set(this->_componenthandler->getComponentType<T>(), false);
//     this->_entityhandler->setCard(entity, card);
//     this->_systemhandler->entityCardChanged(entity, card);
// }

// template<typename T>
// T &Engine::getComponent(int entity)
// {
//     return this->_componenthandler->getComponent<T>(entity);
// }

// template<typename T>
// int Engine::getComponentType()
// {
//     return (this->_componenthandler->getComponentType<T>());
// }

// template<typename T>
// std::shared_ptr<T> Engine::newSystem()
// {
//     return (this->_systemhandler->newSystem<T>());
// }

// template<typename T>
// void Engine::setSystemCard(std::bitset<MAX_COMPONENT> card)
// {
//     this->_systemhandler->setCard<T>(card);
// }