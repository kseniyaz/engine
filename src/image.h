#ifndef IMAGE_H
#define IMAGE_H

#include <GL/freeglut.h>

class Image
{
public:    
    GLuint texture;
    Image(GLuint, unsigned int ,unsigned int);
    unsigned int width;
    unsigned int height;
};


#endif // IMAGE_H
