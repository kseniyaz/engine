#ifndef ENGINE_H
#define ENGINE_H

#include "render.h"
#include "scene.h"

class Engine{
public:
    Engine(RenderStrategy*, int*, char*);
    ~Engine();

    Image* loadImage(const char*);
    void Draw();
    void addGameObject(GameObject*, char*);
    void removeGameObject(char*);
    GameObject* getGameObject(char*);
    void setWindowSize(int, int);
    void setWindowPosition(int, int);
    void createWindow();
private:
    Render* render;
    Scene* scene;
};

#endif // ENGINE_H
