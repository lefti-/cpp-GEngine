#pragma once

#include <glm/glm.hpp>

#include <cpp-GEngine/SpriteBatch.h>
#include <cpp-GEngine/ResourceManager.h>


class Entity
{
public:
    Entity();
    virtual ~Entity();

    void draw(GEngine::SpriteBatch& spriteBatch);

    glm::fvec2 getPosition() const { return m_position; }

	bool collideWithLevel(const std::vector<std::string>& levelData);
	void checkTilePosition(const std::vector<std::string>& levelData,
		std::vector<glm::vec2>& collideTilePositions,
		float x,
		float y);

	void collideWithTile(glm::vec2 tilePos);

    float width;
    float height;

protected:
	bool collideWithEntity(int width, int height, Entity* entity);

    GLuint m_textureID;
	GLuint m_debugTextureID = GEngine::ResourceManager::getTexture("../assets/textures/aabb.png").id;

    glm::fvec2 m_position;
	glm::vec2 m_direction = glm::vec2(1.0f, 0.0f);
    GEngine::ColorRGBA8 m_color;
    glm::fvec2 m_speed;
};