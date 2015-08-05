#pragma once

#include "pch.h"
#include "CubeRenderer.h"
#include "esUtil.h"
#include <GLES2/gl2ext.h>
#include <vector>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

class FBOIncompleteException : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Offscreen FBO for post-process effects can't be created";
    }
};

ref class Asteroids sealed : public Windows::ApplicationModel::Core::IFrameworkView
{
public:
	Asteroids();
	
	// IFrameworkView Methods.
	virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView);
	virtual void SetWindow(Windows::UI::Core::CoreWindow^ window);
	virtual void Load(Platform::String^ entryPoint);
	virtual void Run();
	virtual void Uninitialize();

protected:
	// Event Handlers.
	void OnWindowSizeChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::WindowSizeChangedEventArgs^ args);
	void OnLogicalDpiChanged(Platform::Object^ sender);
	void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ applicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args);
	void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args);
	void OnResuming(Platform::Object^ sender, Platform::Object^ args);
	void OnWindowClosed(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::CoreWindowEventArgs^ args);
	void OnVisibilityChanged(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args);
	void OnPointerPressed(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::PointerEventArgs^ args);
	void OnPointerMoved(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::PointerEventArgs^ args);
    void OnKeyDown(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::KeyEventArgs^ args);
    void OnKeyUp(Windows::UI::Core::CoreWindow^ sender, Windows::UI::Core::KeyEventArgs^ args);
    float ConvertDipsToPixels(float dips);

private:
    ////////////////////////////////////////////////////////////////////////////
    //game simulation methods
    struct GameObject
    {
        GameObject(void);
        void Update(float dt);
        glm::mat4 TransformMatrix(void) const;

        float m_angle;
        float m_omega;
        glm::vec2 m_acc;
        glm::vec2 m_vel;
        glm::vec2 m_pos;
        glm::vec2 m_scale;
        int m_lives;
        float m_lifeTime;
        glm::vec4 m_color;
    };

    struct Laser
    {
        float m_lifeTime;
        glm::vec2 m_pos;
        glm::vec2 m_dir;
        bool m_lethal;
    };

    struct ParticleEffect
    {
        unsigned m_maxParticles;
        int m_emissionRate;
        int m_emissionTimer;
    };

    typedef std::vector<GameObject> GameObjectList;
    typedef GameObjectList::iterator GameObjectIter;
    typedef std::vector<Laser> LaserList;
    typedef LaserList::iterator LaserIter;
    
    void Update();
    void Draw();
    void WrapAround(GameObject &object);
    void FireBullet();
    void RemoveOutOfBoundsBullets();
    void DrawPlayer(void);
    void DrawAsteroids(void);
    void DrawBullets(void);
    void DrawRocket(void);
    void DrawLasers(void);
    void CreateFBO(void);
    
    ////////////////////////////////////////////////////////////////////////////
    //game stuff
    enum Weapon
    {
        Regular,
        Spread,
        LaserWeapon,
    };
    GameObject m_player;
    ParticleEffect m_rocketThrust;
    GameObjectList m_asteroids;
    GameObjectList m_bullets;
    GameObjectList m_asteroidFallout;
    GameObjectList m_rocketThrustParticles;
    LaserList m_lasers;
    unsigned m_playerState;
    float m_regularWeaponTimer;
    float m_spreadWeaponTimer;
    float m_laserWeaponTimer;
    Weapon m_weapon;
    int m_asteroidRespawnTime;

    ////////////////////////////////////////////////////////////////////////////
    //the fake OpenGL DirectX context thing
    ESContext m_esContext;
    
    ////////////////////////////////////////////////////////////////////////////
    //graphics stuff
    std::vector<float> m_vertexBuffer;
    GLuint m_offscreenFBO[8];
    GLuint m_offscreenTex[8];

    ////////////////////////////////////////////////////////////////////////////
    //the shaders
    GLuint m_drawProgram;
    GLint m_uMvpDraw;
    GLint m_aPositionDraw;
    GLint m_aColorDraw;
    
    GLuint m_blurProgram;
    GLint m_aPositionBlur;
    GLint m_uTextureBlur;
    GLint m_uOffsetBlur;

    GLuint m_texturePassThruProgram;
    GLint m_uTextureTexturePassThru;
    GLint m_aPositionTexturePassThru;

    GLuint m_bloomProgram;
    GLint m_uTextureBloom[4];
    GLint m_aPositionBloom;

    ////////////////////////////////////////////////////////////////////////////
    //windows store stuff
	//CubeRenderer^ m_renderer;
	Windows::Foundation::Rect m_windowBounds;
	Windows::Foundation::Size m_renderTargetSize;
	Windows::Graphics::Display::DisplayOrientations m_orientation;
	bool m_windowClosed;
	bool m_windowVisible;
};

ref class Direct3DApplicationSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public:
	virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView();
};
