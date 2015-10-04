/*
==================================================================================
cPyamid.cpp
==================================================================================
*/

#include "cPyramid.h"


cPyramid::cPyramid()
{
	setRotAngle(0.0f);
}

void cPyramid::render(float rotAngle)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VertexBufferObjects[1]);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[2]);
	glColorPointer(3, GL_FLOAT, 0, 0);

	glLoadIdentity();
	//glRotatef(rotAngle, 0.0f, 1.0f, 0.0f); 

	glTranslatef(-2.0f, 0.0f, -6.0f);
	glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);


}

void cPyramid::initialise()
{
	m_top = glm::vec3(0.0f, 1.0f, 0.0f);
	m_bottomLeftFront = glm::vec3(-1.0f, -1.0f, 1.0f);
	m_bottomRightFront = glm::vec3(1.0f, -1.0f, 1.0f);
	m_bottomLeftBack = glm::vec3(-1.0f, -1.0f, -1.0f);
	m_bottomRightBack = glm::vec3(1.0f, -1.0f, -1.0f);

	//Push back 8 vertices that make up a cube 
	for (int i = 0; i < 3; i++){
		m_vertices.push_back(m_bottomLeftFront);
		m_vertices.push_back(m_bottomLeftBack);
		m_vertices.push_back(m_bottomRightBack);
		m_vertices.push_back(m_bottomRightFront);


		m_vertices.push_back(m_top);
	}
	m_vertices.push_back(m_top);


	m_Indices[0] = 0; // red front face 
	m_Indices[1] = 2;
	m_Indices[2] = 3;
	m_Indices[3] = 0;
	m_Indices[4] = 1;
	m_Indices[5] = 2;

	m_Indices[6] = 4; // orange back face
	m_Indices[7] = 0+5;
	m_Indices[8] = 3+5;


	m_Indices[9] = 4+5;
	m_Indices[10] = 1+5;
	m_Indices[11] = 2+5;

	m_Indices[12] = 4 + 5; // yellow top face 
	m_Indices[13] = 0 + 5;
	m_Indices[14] = 1 + 5;


	m_Indices[15] = 15;
	m_Indices[16] = 2 + 10;
	m_Indices[17] = 1 + 10;

	

	// Create Colour list 
	cColours theColour;
	m_colourList[0] = theColour.getColour(theColour.BLUE);
	m_colourList[1] = theColour.getColour(theColour.BLUE);
	m_colourList[2] = theColour.getColour(theColour.BLUE);
	m_colourList[3] = theColour.getColour(theColour.BLUE);

	m_colourList[4] = theColour.getColour(theColour.RED);
	m_colourList[5] = theColour.getColour(theColour.RED);
	m_colourList[6] = theColour.getColour(theColour.RED);
	m_colourList[7] = theColour.getColour(theColour.RED);

	m_colourList[8] = theColour.getColour(theColour.BLUE);
	m_colourList[9] = theColour.getColour(theColour.BLUE);
	m_colourList[12] = theColour.getColour(theColour.BLUE);
	m_colourList[13] = theColour.getColour(theColour.BLUE);

	m_colourList[10] = theColour.getColour(theColour.BLUE);
	m_colourList[11] = theColour.getColour(theColour.BLUE);
	m_colourList[14] = theColour.getColour(theColour.BLUE);
	m_colourList[15] = theColour.getColour(theColour.BLUE);

	//++ COMPLETE THE REST OF THESE LATER! YOU SCRUB!!!" ++

	// Assign variables that will be used to store the unique object ID’s that will be used to refer to the two buffers. 

	glGenBuffers = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");



	glGenBuffers(3, &m_VertexBufferObjects[0]);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]); //Bind the vertex buffer 
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VertexBufferObjects[1]); //Bind the vertex buffer 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * sizeof(m_Indices), &m_Indices[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * sizeof(m_colourList), &m_colourList[0], GL_STATIC_DRAW); //Send the data to OpenGL 

	//Bind the colour array, and set the color pointer to point at it 
	/*glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[3]);
	glColorPointer(3, GL_FLOAT, 0, 0);

	//Bind the vertex array and set the vertex pointer to point at it
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObjects[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);*/


}
