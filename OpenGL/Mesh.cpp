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

	m_vertexData = {
		/*  Position  */ /*     RGBA Color     */
		20.0f, 20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		30.f, 110.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		40.0f, 50.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		70.0f, 80.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		80.0f, 40.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		100.0f, 60.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		100.0f, 20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		150.0f, 60.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	};

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);
}

void Mesh::Cleanup()
{
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
	_wvp *= m_world;
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);
	//glDrawArrays(GL_LINES, 0, m_vertexData.size() / 7); // Draw the triangle
	//glDrawArrays(GL_LINE_STRIP, 0, m_vertexData.size() / 7);
	glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, m_vertexData.size() / 7);
	glDisableVertexAttribArray(m_shader->GetAttrColors());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());



	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	//glVertexAttribPointer(0, 3/*size*/, GL_FLOAT/*type*/, GL_FALSE/*normalized*/, 0/*stride*/, (void*)0/*offset*/);
	// Draw the triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3); // starting from vertex 0, 3 vertices = 1 triangle
	//glDisableVertexAttribArray(0);
}