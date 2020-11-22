#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "image.h"

class AnimationIterator;

class Animation{
    std::vector<Image*> items;
public:
    friend class AnimationIterator;

    void push(Image* image);
    int size() const;

    AnimationIterator *createIterator() const;
};

class AnimationIterator
{
    const Animation *animation;
    int index;
public:
    AnimationIterator(const Animation *animation);

    Image* first();
    Image* next();
    bool isDone();
    Image* currentItem();
};


#endif // ANIMATION_H
