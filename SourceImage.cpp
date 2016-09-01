#include <iostream>
#include "SourceImage.h"
#include <Images/RGBImage.h>
#include <Images/ReadImageFile.h>

SourceImage::SourceImage(std::string filename)
{
  Images::RGBAImage dti;
  std::string name = "source.png";
  dti = Images::readTransparentImageFile(name.c_str());
  std::cout << &dti;
};
SourceImage::~SourceImage()
{
};
void SourceImage::initContext(GLContextData& contextData) const
{
  DataItem* dataItem=new DataItem;
  contextData.addDataItem(this,dataItem);
  dataItem->sourceImageUniformLocation=glGetUniformLocationARB(dataItem->sourceImageShader,"sourceImageSampler");
  
};

