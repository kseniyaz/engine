#ifndef SCENE_H
#define SCENE_H

#include <map>
#include "gameobject.h"

class Scene{
public:
    void addGameObject(GameObject* go, char* id);
    void removeGameObject(char* id);
    GameObject* getGameObject(char* id);
    void Draw(Render* render);

private:
    std::map<char*, GameObject*> gameObjectMap;
};
#endif // SCENE_H
