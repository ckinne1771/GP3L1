/*
==========================================================================
cPyramid.h
==========================================================================
*/

#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "windowOGL.h"
#include "glm\glm.hpp"
#include "glx\glext.h"
#include "wglext.h"
#include <vector>
#include "cColours.h"
#include "cShapes.h"

class cPyramid : public cShapes
{
public:
	cPyramid();
	virtual void render(float rotAngle);
	virtual void initialise();

private:

	glm::vec3 m_top;
	glm::vec3 m_bottomLeftFront;
	glm::vec3 m_bottomRightFront;
	glm::vec3 m_bottomLeftBack;
	glm::vec3 m_bottomRightBack;


	GLuint m_Indices[18];

	std::vector<glm::vec3> m_vertices;
	glm::vec3 m_colourList[16];
	GLuint m_VertexBufferObjects[3];
};

#endif