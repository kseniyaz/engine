#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <png.h>
#include "image.h"
#include "animation.h"

class RenderStrategy{
public:
    virtual void drawImage(Image*, double, double, double) = 0;
    virtual void drawAnimation(Animation*, double, double, double, double) = 0;
    virtual Image* loadImage(const char * imageName) = 0;
    virtual void Init(int*, char*) = 0;
    virtual void Draw() = 0;
    virtual void setWindowSize(int, int) = 0;
    virtual void setWindowPosition(int, int) = 0;
    virtual void createWindow() = 0;
    virtual ~RenderStrategy(){};
protected:
    void loadPng(const char*, unsigned int*, unsigned int*, png_byte**);
};

class Render{
public:
    Image* loadImage(const char*);
    void drawImage(Image* image, double, double, double);
    void drawAnimation(Animation*, double, double, double, double);
    void setStrategy(RenderStrategy* strategy);
    void Init(int*, char*);
    void Draw();
    void setWindowSize(int, int);
    void setWindowPosition(int, int);
    void createWindow();
private:
    RenderStrategy* renderStrategy = 0;
};

#endif // RENDER_H
