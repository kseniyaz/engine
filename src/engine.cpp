#include "engine.h"


Engine::Engine(RenderStrategy* strategy, int* argc, char *arg)
{
    render = new Render();
    render->setStrategy(strategy);
    render->Init(argc, arg);
    scene = new Scene();
}

Engine::~Engine(){
    delete render;
    delete scene;
}

Image* Engine::loadImage(const char* imagePath)
{
    return render->loadImage(imagePath);
}

void Engine::setWindowSize(int width, int height)
{
    render->setWindowSize(width, height);
}

void Engine::setWindowPosition(int x, int y)
{
    render->setWindowPosition(x, y);
}

void Engine::Draw()
{
    scene->Draw(render);
    render->Draw();
}

void Engine::addGameObject(GameObject* go, char* id)
{
    scene->addGameObject(go, id);
}

void Engine::removeGameObject(char* id)
{
    scene->removeGameObject(id);
}

GameObject* Engine::getGameObject(char* id)
{
    return scene->getGameObject(id);
}

void Engine::createWindow()
{
    render->createWindow();
}

