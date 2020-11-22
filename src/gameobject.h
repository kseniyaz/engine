#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "animation.h"
#include "render.h"

class GameObject{
public:
    double x;
    double y;
    double scale;

    virtual void Draw(Render*) = 0;
    GameObject(double x, double y, double scale):
        x(x), y(y), scale(scale){}
};

class AnimationGameObject: public GameObject{
    double delay;
    Animation* animation;

public:
    AnimationGameObject(double x, double y, double scale, double delay, Animation* animation);
    void Draw(Render* render);
};

class ImageGameObject: public GameObject{
    Image* image;

public:
    ImageGameObject(double x, double y, double scale, Image* image);
    void Draw(Render* render);
};
#endif // GAMEOBJECT_H
