#ifndef SOURCEIMAGE_INCLUDED
#define SOURCEIMAGE_INCLUDED
#include <string>
#include <vector>
#include <Misc/FunctionCalls.h>
#include <Geometry/Point.h>
#include <Geometry/Plane.h>
#include <Geometry/Box.h>
#include <Geometry/OrthonormalTransformation.h>
#include <GL/gl.h>
#include <GL/Extensions/GLARBShaderObjects.h>
#include <GL/GLObject.h>
#include <GL/GLContextData.h>

class SourceImage:public GLObject
{
 private:
  struct DataItem:public GLObject::DataItem // Structure holding per-context state
  {
    /* Elements: */
  public:
    GLuint sourceImageTextureObject;
    GLint sourceImageUniformLocation;
    GLhandleARB sourceImageShader;
  };
  
 private:
  GLfloat sourceImageTextureMatrix[16];

 public:
  SourceImage(std::string filename);
  virtual ~SourceImage();
  virtual void initContext(GLContextData& contextData) const;
  void bindTexture(GLContextData& contextData) const; // Binds the image texture
  
  const GLfloat* getTextureMatrix(void) const // Returns the matrix transforming from camera space into image texture space
  {
    return sourceImageTextureMatrix;
  }

  
};
#endif
