#include "scene.h"


void Scene::addGameObject(GameObject* go, char* id)
{
    gameObjectMap[id] = go;
}

void Scene::removeGameObject(char* id)
{
    gameObjectMap.erase(id);
}

GameObject* Scene::getGameObject(char* id)
{
    return gameObjectMap[id];
}

void Scene::Draw(Render* render)
{
    for(auto gameObject: gameObjectMap)
    {
        gameObject.second->Draw(render);
    }
}
