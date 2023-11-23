//#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "Singleton.h"
#include "Shader.h"
#include "Mesh.h"
#include "WindowController.h"
#include "Camera.h"

class GameController : public Singleton<GameController>
{
	public:
		// Constructors / Destructors
		GameController();
		virtual ~GameController();

		// Methods
		void Initialize();
		void RunGame();

	private:
		Shader m_shaderColor;
		Shader m_shaderDiffuse;
		Shader m_shaderFont;
		Camera m_camera;
		vector<Mesh> m_meshes;
};

#endif // !GAME_CONTROLLER_H