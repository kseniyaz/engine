#include "render.h"


void RenderStrategy::loadPng(const char* file_name, unsigned int* width, unsigned int* height, png_byte** image_data)
{
    png_byte header[8];

    FILE *fp = fopen(file_name, "rb");
    if (fp == 0)
    {
        perror(file_name);
        return;
    }

    fread(header, 1, 8, fp);

    if (png_sig_cmp(header, 0, 8))
    {
        fclose(fp);
        return;
    }

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr)
    {
        fclose(fp);
        return;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        fclose(fp);
        return;
    }

    png_infop end_info = png_create_info_struct(png_ptr);
    if (!end_info)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return;
    }

    png_init_io(png_ptr, fp);

    png_set_sig_bytes(png_ptr, 8);

    png_read_info(png_ptr, info_ptr);

    int bit_depth, color_type;
    png_uint_32 temp_width, temp_height;

    png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type, NULL, NULL, NULL);

    if (width){ *width = temp_width; }
    if (height){ *height = temp_height; }

    png_read_update_info(png_ptr, info_ptr);

    int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    rowbytes += 3 - ((rowbytes-1) % 4);

    *image_data = (png_byte*)malloc(rowbytes * temp_height * sizeof(png_byte)+15);
    if (*image_data == NULL)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return;
    }

    png_bytep* row_pointers = (png_bytep*)malloc(temp_height * sizeof(png_bytep));
    if (row_pointers == NULL)
    {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(*image_data);
        fclose(fp);
        return;
    }

    for (int i = 0; i < temp_height; i++)
    {
        row_pointers[temp_height - 1 - i] = *image_data + i * rowbytes;
    }

    png_read_image(png_ptr, row_pointers);

    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);

    free(row_pointers);
    fclose(fp);
}


void Render::Init(int* argc, char* argv)
{
    renderStrategy->Init(argc, argv);
}

void Render::Draw()
{
    renderStrategy->Draw();
}

Image* Render::loadImage(const char* imagePath)
{
    return renderStrategy->loadImage(imagePath);
}

void  Render::drawImage(Image* image, double x, double y, double scale)
{
    renderStrategy->drawImage(image, x, y, scale);
}

void Render::drawAnimation(Animation* animation, double x, double y, double scale, double duration){
    renderStrategy->drawAnimation(animation, x, y, scale, duration);
};

void  Render::setStrategy(RenderStrategy* strategy)
{
    renderStrategy = strategy;
}

void Render::setWindowSize(int width, int height)
{
    renderStrategy->setWindowSize(width, height);
}

void Render::setWindowPosition(int x, int y)
{
    renderStrategy->setWindowPosition(x, y);
}

void Render::createWindow()
{
    renderStrategy->createWindow();
}

