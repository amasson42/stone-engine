#include "config.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Core/Image/ImageSource.hpp"
#include "Scene.hpp"
#include "Window.hpp"

class RotatingNode : public Stone::Scene::PivotNode {
public:
	STONE_NODE(RotatingNode)

	RotatingNode(const std::string &name = "rotating_node") : PivotNode(name) {
	}

	void update(float deltaTime) override {
		getTransform().rotate(deltaTime * rotationSpeeds);
	}

	void setRotationSpeed(glm::vec3 speeds) {
		rotationSpeeds = speeds;
	}

private:
	glm::vec3 rotationSpeeds = {0.0f, 0.4f, 0.0f};
};

STONE_NODE_IMPLEMENTATION(RotatingNode)

int main() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	int retCode;
	{
		auto app = std::make_shared<Stone::Window::App>();

		Stone::Window::WindowSettings win_settings;
		win_settings.title = "Scop";
		auto window = app->createWindow(win_settings);

		auto meshNode = window->getWorld()->addChild<Stone::Scene::MeshNode>();

		auto mesh = std::make_shared<Stone::Scene::Mesh>();
		mesh->indicesRef() = {0, 1, 2, 0, 2, 3};
		mesh->verticesRef().emplace_back();
		mesh->verticesRef().back().position = {-0.5f, -0.5f, 0.0f};
		mesh->verticesRef().back().uv = {0.0f, 0.0f};
		mesh->verticesRef().emplace_back();
		mesh->verticesRef().back().position = {0.5f, -0.5f, 0.0f};
		mesh->verticesRef().back().uv = {1.0f, 0.0f};
		mesh->verticesRef().emplace_back();
		mesh->verticesRef().back().position = {0.5f, 0.5f, 0.0f};
		mesh->verticesRef().back().uv = {1.0f, 1.0f};
		mesh->verticesRef().emplace_back();
		mesh->verticesRef().back().position = {-0.5f, 0.5f, 0.0f};
		mesh->verticesRef().back().uv = {0.0f, 1.0f};

		meshNode->setMesh(mesh);

		auto stone_image_source =
			std::make_shared<Stone::Image::ImageSource>("docs/img/stone-engine.png", Stone::Image::Channel::RGBA);

		auto stone_texture = std::make_shared<Stone::Scene::Texture>();
		stone_texture->setImage(stone_image_source);

		auto stone_material = std::make_shared<Stone::Scene::Material>();
		stone_material->setTextureParameter("diffuse", stone_texture);
		meshNode->setMaterial(stone_material);

		auto meshRotatingNode = window->getWorld()->addChild<RotatingNode>();
		meshRotatingNode->getTransform().setPosition({0.0f, 1.0f, 0.0f});
		auto secondMeshNode = meshRotatingNode->addChild<Stone::Scene::MeshNode>();
		meshRotatingNode->setRotationSpeed({0.0f, 0.4f, 0.0f});
		secondMeshNode->setMesh(mesh);
		secondMeshNode->setMaterial(stone_material);

		auto rotatingNode = window->getWorld()->addChild<RotatingNode>();
		auto cameraNode = rotatingNode->addChild<Stone::Scene::PerspectiveCameraNode>();
		cameraNode->getTransform().setPosition({0.0f, 3.0f, 3.0f});
		cameraNode->getTransform().rotate({-0.6f, 0.0f, 0.0f});

		window->getWorld()->setActiveCamera(cameraNode);

		retCode = app->run();
	}

	std::cout << "Bye!" << std::endl;

#if STONE_ENGINE_USE_SYSTEM_PAUSE
	system("pause");
#endif

	return retCode;
}
