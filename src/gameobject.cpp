#include "gameobject.h"

AnimationGameObject::AnimationGameObject(double x, double y, double scale, double delay, Animation* animation):
    GameObject(x, y, scale), delay(delay), animation(animation){};

void AnimationGameObject::Draw(Render* render)
{
     render->drawAnimation(animation, x, y, scale, delay);
}


ImageGameObject::ImageGameObject(double x, double y, double scale, Image* image):
    GameObject(x,y,scale), image(image){};

void ImageGameObject::Draw(Render* render)
{
    render->drawImage(image, x, y, scale);
}
