#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh()
{
	m_shader = nullptr;
	m_vertexBuffer = 0;
	m_world = glm::mat4(1.0f);
}

Mesh::~Mesh()
{
}

void Mesh::Create(Shader* _shader)
{
	m_shader = _shader;

	//m_vertexData = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };

	float a = 26.0f;
	float b = 42.0f;
	m_vertexData = {
		-a, 0.0f, b, 1.0f, 0.0f, 0.0f, 1.0f,
		a, 0.0f, b, 1.0f, 0.549f, 0.0f, 1.0f,
		-a, 0.0f, -b, 1.0f, 1.0f, 0.0f, 1.0f,
		a, 0.0f, -b, 1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, b, a, 0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, b, -a, 0.294f, 0.0f, 0.51f, 1.0f,
		0.0f, -b, a, 0.502f, 0.0f, 0.502f, 1.0f,
		0.0f, -b, -a, 1.0f, 1.0f, 1.0f, 1.0f,
		b, a, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-b, a, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		b, -a, 0.0f, 0.118f, 0.565f, 1.0f, 1.0f,
		-b, -a , 0.0f, 0.863f, 0.078f, 0.235f, 1.0f,
	};
	
	/*  Position  */ /*     RGBA Color     */
	/* m_vertexData = {
		20.0f, 20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		30.f, 110.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		40.0f, 50.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		70.0f, 80.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		80.0f, 40.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		100.0f, 60.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		100.0f, 20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		150.0f, 60.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	};*/

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	m_indexData = {
		0, 6, 1, 0, 11, 6, 1, 4, 0, 1, 8, 4,
		1, 10, 8, 2, 5, 3, 2, 9, 5, 2, 11, 9,
		3, 7, 2, 3, 10, 7, 4, 8, 5, 4, 9, 0,
		5, 8, 3, 5, 9, 4, 6, 10, 1, 6, 11, 7,
		7, 10, 6, 7, 11, 2, 8, 10, 3, 9, 11, 0
	};

	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);
}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_indexBuffer);
	glDeleteBuffers(1, &m_vertexBuffer);
}

void Mesh::Render(glm::mat4 _wvp)
{
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	// First attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3, //size
		GL_FLOAT, // type
		GL_FALSE, // normalized
		7 * sizeof(float), // stride (7 floats per vertex definition)
		(void*)0); // offset

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(
		m_shader->GetAttrColors(), // The attribute we want to configure
		4, // size (4 components per color value
		GL_FLOAT, // type
		GL_FALSE, // normalized
		7 * sizeof(float), // stride (7 floats per vertex definition)
		(void*)(3 * sizeof(float)) // array buffer offset
	);

	// 3rd attribute : WVP
	m_world = glm::rotate(m_world, 0.001f, { 0, 1, 0 });
	_wvp *= m_world;
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // Bind the vertex buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); // Bind the index buffer
	//glDrawArrays(GL_LINES, 0, m_vertexData.size() / 7); // Draw the triangle
	//glDrawArrays(GL_LINE_STRIP, 0, m_vertexData.size() / 7);
	//glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vertexData.size() / 7);

	glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0);

	glDisableVertexAttribArray(m_shader->GetAttrColors());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());



	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	//glVertexAttribPointer(0, 3/*size*/, GL_FLOAT/*type*/, GL_FALSE/*normalized*/, 0/*stride*/, (void*)0/*offset*/);
	// Draw the triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3); // starting from vertex 0, 3 vertices = 1 triangle
	//glDisableVertexAttribArray(0);
}