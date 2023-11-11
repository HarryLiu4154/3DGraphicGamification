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
		Camera m_camera;
		vector<Mesh> m_meshBoxes;
		Mesh m_meshLight;
};

#endif // !GAME_CONTROLLER_H