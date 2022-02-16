#ifndef RENDERLOOP_H
#define RENDERLOOP_H
#include <QObject>

#include "ImageBuffer.h"
#include "Model.h"
#include "utils.h"

class RenderLoop : public QObject {
    Q_OBJECT
public:
    RenderLoop(int w, int h);
    ~RenderLoop();
    void Resize(int w, int h);

private:
    int width_;
    int height_;
    ImageBuffer* render_buffer_;

    // model1
    Model* model1_;

    // camera
    vec3 camera_pos_ = vec3(0, 0, 2);
    vec3 camera_lookat_ = vec3(0, 0, -1);
    vec3 camera_up_ = vec3(0, 1, 0);

    // view
    float near_ = 2;
    float far_ = 12;
    float fov_ = 2;
    float aspect_;
    mat4 view_matrix_;
    mat4 perspective_matrix_;

signals:
    void FrameReady(unsigned char* data);
public slots:
    void MainLoop();
};

#endif  // RENDERLOOP_H
