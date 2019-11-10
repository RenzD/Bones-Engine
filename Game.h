#pragma once
#include <SDL.h>
#include <unordered_map>
#include <string>
#include <vector>
#include "Math.h"
#include "InputSystem.h"
#include "AudioEngine.h"
#include "PlayerCombatSystem.h"
#include "EnemyCombatSystem.h"
#include "LevelUpSystem.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	enum GameState {
		gameplay,
		paused,
		quit
	};

	class Renderer* GetRenderer() { 
		return renderer; 
	}

	class CameraTargetActor* GetPlayer() {
		return cameraTargetActor;
	}

	GameState GetState() const {
		return gameState;
	}

	void SetState(GameState state) {
		gameState = state;
	}

	int IsWalkable(int row, int col);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void CreatePointLights(Actor*& a, Vector3& pos, int z);
	void UnloadData();
	
	std::vector<class Actor*> actors;
	std::vector<class Actor*> pendingActors;

	class InputSystem* inputSystem;
	class AudioEngine* AE;
	class Renderer* renderer;
	Uint32 ticksCount;
	int scene;
	GameState gameState;
	bool isRunning;
	bool isLoading;
	bool updatingActors;
	std::vector<class enemy*> enemies;

	int exit_posX;
	int exit_posY;
	int start_posX;
	int start_posY;

	int** map2D;

	//Game Specific
	class CameraTargetActor* cameraTargetActor;
	class CubeActor* cubeActor;
	class PlayerCombatSystem* playerCombat;
	class LevelUpSystem* playerLevels;
	class EnemyCombatSystem* enemyCombat;

	bool isReturning;
	Vector3 savedPlayerPosition;
};
