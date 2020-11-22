#include "animation.h"


void Animation::push(Image* image)
{
    items.push_back(image);
}

int Animation::size() const
{
    return  items.size();
}

AnimationIterator *Animation::createIterator() const
{
    return new AnimationIterator(this);
}


AnimationIterator::AnimationIterator(const Animation *animation):
     animation(animation), index(0){}

Image* AnimationIterator::first()
{
    index = 0;
    return currentItem();
}

Image* AnimationIterator::next()
{
    if(!isDone()) index++;
    return currentItem();
}

bool AnimationIterator::isDone()
{
    return index >= animation->size();
}

Image* AnimationIterator::currentItem()
{
    return animation->items[index];
}
