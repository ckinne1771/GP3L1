/*
==========================================================================
cShapes.h
==========================================================================
*/

#ifndef _SHAPES_H
#define _SHAPES_H

#include "windowOGL.h"
#include "glm\glm.hpp"
#include "glx\glext.h"
#include "wglext.h"
#include <vector>
#include "cColours.h"

class cShapes : public windowOGL
{
public:
	cShapes();
	virtual void render(float rotAngle) = 0;
	float getRotAngle();
	void setRotAngle(float rotAngle);
	void prepare(float rAngle);
	virtual void initialise() = 0;
	void rotate(float angle);
	void translate(glm::vec3 &translation);

	PFNGLGENBUFFERSARBPROC glGenBuffers = NULL;
	PFNGLBINDBUFFERPROC glBindBuffer = NULL;
	PFNGLBUFFERDATAPROC glBufferData = NULL;

protected:
	float m_rotAngle;
	glm::vec3 m_translation;

};

#endif