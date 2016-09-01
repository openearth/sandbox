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
  

 public:
  SourceImage(std::string filename);
  virtual ~SourceImage();
  virtual void initContext(GLContextData& contextData) const;
  
};
#endif
