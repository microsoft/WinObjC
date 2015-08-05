#include "pch.h"
#include "Asteroids.h"
#include "BasicTimer.h"

#define STRINGIFY(str) #str
#define PLAYER_ACCELERATION 100.0f
#define TURN_SPEED 200.0f
#define MAX_ASTEROIDS 32
#define MAX_FALLOUT_PER_ASTEROID 20
#define FALLOUT_INITIAL_VEL 500.0f
#define BULLET_SPEED 300.0f
#define DESTROYED_ASTEROID_SPEED 100.0f
#define REGULAR_WEAPON_COOLDOWN 0.2f
#define SPREAD_WEAPON_COOLDOWN 0.5f
#define LASER_WEAPON_COOLDOWN 2.0f
#define THRUST_OUTPUT_RATE 5
#define MAX_THRUST_PARTICLES 200
#define LASER_LIFETIME 4.0f

#define PLAYER_STATE_W     0x1
#define PLAYER_STATE_A     0x2
#define PLAYER_STATE_S     0x4
#define PLAYER_STATE_D     0x8
#define PLAYER_STATE_SPACE 0x10

#define RENDER_TARGET_WIDTH 1024
#define RENDER_TARGET_HEIGHT 512

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace concurrency;
using namespace DirectX;

Asteroids::Asteroids() :
    m_playerState(0),
    m_regularWeaponTimer(0),
    m_spreadWeaponTimer(0),
    m_laserWeaponTimer(0),
    m_weapon(Weapon::Regular),
    m_asteroidRespawnTime(10),
    m_windowClosed(false),
    m_windowVisible(false)
{
}

void Asteroids::Initialize(CoreApplicationView^ applicationView)
{
    applicationView->Activated +=
        ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &Asteroids::OnActivated);

    CoreApplication::Suspending +=
        ref new EventHandler<SuspendingEventArgs^>(this, &Asteroids::OnSuspending);

    CoreApplication::Resuming +=
        ref new EventHandler<Platform::Object^>(this, &Asteroids::OnResuming);

    //m_renderer = ref new CubeRenderer();
    m_player.m_scale = glm::vec2(40);
    for(int i = 0; i < MAX_ASTEROIDS; ++i)
    {
        GameObject asteroid;
        asteroid.m_pos.x = static_cast<float>(rand() % 10000);
        asteroid.m_pos.y = static_cast<float>(rand() % 10000);
        asteroid.m_angle = (rand() % 1000) / 10.0f - 50;
        asteroid.m_omega = (rand() % 1000) / 10.0f - 50;
        asteroid.m_vel.x = (rand() % 1000) / 10.0f - 50;
        asteroid.m_vel.y = (rand() % 1000) / 10.0f - 50;
        asteroid.m_scale.x = (rand() % 1000) / 20.0f + 50;
        asteroid.m_scale.y = asteroid.m_scale.x;//(rand() % 1000) / 10.0f - 50;
        asteroid.m_lives = 2;
        m_asteroids.push_back(asteroid);
    }
    m_rocketThrust.m_emissionRate = THRUST_OUTPUT_RATE;
    m_rocketThrust.m_maxParticles = MAX_THRUST_PARTICLES;
    m_rocketThrust.m_emissionTimer = 0;
}

void Asteroids::SetWindow(CoreWindow^ window)
{
    window->SizeChanged += 
        ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &Asteroids::OnWindowSizeChanged);

    window->VisibilityChanged +=
        ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &Asteroids::OnVisibilityChanged);

    window->Closed += 
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &Asteroids::OnWindowClosed);

    window->PointerCursor = ref new CoreCursor(CoreCursorType::Arrow, 0);

    window->PointerPressed +=
        ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &Asteroids::OnPointerPressed);

    window->PointerMoved +=
        ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &Asteroids::OnPointerMoved);

    window->KeyDown +=
        ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &Asteroids::OnKeyDown);

    window->KeyUp +=
        ref new TypedEventHandler<CoreWindow^, KeyEventArgs^>(this, &Asteroids::OnKeyUp);

    //m_renderer->Initialize(CoreWindow::GetForCurrentThread());
    m_orientation = DisplayProperties::CurrentOrientation;
    m_windowBounds = window->Bounds;

    esInitContext ( &m_esContext );
    m_esContext.hWnd.window = CoreWindow::GetForCurrentThread();
    esCreateWindow ( &m_esContext, TEXT("Simple Instancing"), 320, 240, ES_WINDOW_RGB );

    const char *vs = STRINGIFY(
        attribute vec3 a_position;
    attribute vec4 a_color;
    varying vec4 v_color;
    uniform mat4 u_mvp;
    void main(void)
    {
        v_color = a_color;
        v_color.rgb *= a_color.a;
        gl_Position = u_mvp * vec4(a_position, 1);
    }
    );

    const char *fs = STRINGIFY(
        precision mediump float;
    varying vec4 v_color;
    void main(void)
    {
        gl_FragColor = v_color;
    }
    );

    m_drawProgram = esLoadProgram(vs, fs);
    m_uMvpDraw = glGetUniformLocation(m_drawProgram, "u_mvp");
    m_aPositionDraw = glGetAttribLocation(m_drawProgram, "a_position");
    m_aColorDraw = glGetAttribLocation(m_drawProgram, "a_color");

    vs = STRINGIFY(
        attribute vec2 a_position;
    varying vec2 v_uv;
    void main(void)
    {
        gl_Position = vec4(a_position, 0, 1);
        v_uv = a_position * 0.5 + 0.5;
    }
    );

    fs = STRINGIFY(
        precision mediump float;
    varying vec2 v_uv;
    uniform sampler2D u_texture;
    uniform vec2 u_offset;
    void main(void)
    {
        vec4 color;
        const int radius = 1;
        const float gaussianOffset = 1.4;
        int divisor = 0;
        for(int i = -radius; i <= radius; ++i)
        {
            vec2 uv = v_uv + u_offset * float(i) * gaussianOffset;
            color += texture2D(u_texture, uv);
            ++divisor;
        }
        gl_FragColor = color / float(divisor);
    }
    );

    m_blurProgram = esLoadProgram(vs, fs);
    m_uTextureBlur = glGetUniformLocation(m_blurProgram, "u_texture");
    m_uOffsetBlur = glGetUniformLocation(m_blurProgram, "u_offset");
    m_aPositionBlur = glGetAttribLocation(m_blurProgram, "a_position");

    fs = STRINGIFY(
        precision mediump float;
    varying vec2 v_uv;
    uniform sampler2D u_texture;
    void main(void)
    {
        gl_FragColor = texture2D(u_texture, v_uv);
    }
    );

    m_texturePassThruProgram = esLoadProgram(vs, fs);
    m_uTextureTexturePassThru = glGetUniformLocation(m_texturePassThruProgram, "u_texture");
    m_aPositionTexturePassThru = glGetAttribLocation(m_texturePassThruProgram, "a_position");

    fs = STRINGIFY(
        precision mediump float;
    varying vec2 v_uv;
    uniform sampler2D u_texture[4];
    void main(void)
    {
        vec4 color;
        for(int i = 0; i < 4; ++i)
            color += texture2D(u_texture[i], v_uv);
        const float bloomPower = 3.0;
        gl_FragColor.r = (color.r + (max(color.g - 1.0, 0.0) + max(color.b - 1.0, 0.0)) * 0.5 * bloomPower) * color.a;
        gl_FragColor.g = (color.g + (max(color.r - 1.0, 0.0) + max(color.b - 1.0, 0.0)) * 0.5 * bloomPower) * color.a;
        gl_FragColor.b = (color.b + (max(color.r - 1.0, 0.0) + max(color.g - 1.0, 0.0)) * 0.5 * bloomPower) * color.a;
        gl_FragColor.a = color.a;
    }
    );

    m_bloomProgram = esLoadProgram(vs, fs);
    for(int i = 0; i < 4; ++i)
    {
        char buffer[] = "u_texture[0]";
        sprintf(buffer, "u_texture[%i]", i);
        m_uTextureBloom[i] = glGetUniformLocation(m_bloomProgram, buffer);
    }
    m_aPositionBloom = glGetAttribLocation(m_bloomProgram, "a_position");

    //setup the FBO
    CreateFBO();

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}

void Asteroids::Load(Platform::String^ entryPoint)
{
}

void Asteroids::Run()
{
    BasicTimer^ timer = ref new BasicTimer();
    while (!m_windowClosed)
    {
        if (m_windowVisible)
        {
            timer->Update();
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
            Update();
            Draw();



            //m_renderer->Update(timer->Total, timer->Delta);
            //m_renderer->Render();
            //m_renderer->Present(); // This call is synchronized to the display frame rate.
        }
        else
        {
            CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
        }
    }
}

void Asteroids::Uninitialize()
{
}

void Asteroids::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
    //m_renderer->UpdateForWindowSizeChange();
    if (sender->Bounds.Width  != m_windowBounds.Width ||
        sender->Bounds.Height != m_windowBounds.Height ||
        m_orientation != DisplayProperties::CurrentOrientation)
    {
        // Internally calls DX11's version of flush
        glFlush();

        // Store the window bounds so the next time we get a SizeChanged event we can
        // avoid rebuilding everything if the size is identical.
        m_windowBounds = sender->Bounds;

        // Calculate the necessary swap chain and render target size in pixels.
        float windowWidth = ConvertDipsToPixels(m_windowBounds.Width);
        float windowHeight = ConvertDipsToPixels(m_windowBounds.Height);

        // The width and height of the swap chain must be based on the window's
        // landscape-oriented width and height. If the window is in a portrait
        // orientation, the dimensions must be reversed.
        m_orientation = DisplayProperties::CurrentOrientation;
        bool swapDimensions =
            m_orientation == DisplayOrientations::Portrait ||
            m_orientation == DisplayOrientations::PortraitFlipped;
        m_renderTargetSize.Width = swapDimensions ? windowHeight : windowWidth;
        m_renderTargetSize.Height = swapDimensions ? windowWidth : windowHeight;

        // Actually resize the underlying swapchain
        //esResizeWindow(&m_esContext, static_cast<UINT>(m_renderTargetSize.Width), static_cast<UINT>(m_renderTargetSize.Height));
        glViewport(0, 0, static_cast<UINT>(m_renderTargetSize.Width), static_cast<UINT>(m_renderTargetSize.Height));

        // Recreate the FBO with the new dimensions
        glDeleteFramebuffers(8, m_offscreenFBO);
        glDeleteTextures(8, m_offscreenTex);

        //setup the FBO
        CreateFBO();
    }
}

void Asteroids::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
    m_windowVisible = args->Visible;
}

void Asteroids::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
    m_windowClosed = true;
    glDeleteProgram(m_drawProgram);
    glDeleteProgram(m_blurProgram);
    glDeleteProgram(m_texturePassThruProgram);
    glDeleteProgram(m_bloomProgram);
    glDeleteTextures(8, m_offscreenTex);
    glDeleteFramebuffers(8, m_offscreenFBO);
}

void Asteroids::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
    // Insert your code here.
}

void Asteroids::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
    // Insert your code here.
}

void Asteroids::OnKeyDown(CoreWindow^ sender, KeyEventArgs ^args)
{
    switch(args->VirtualKey)
    {
    case VirtualKey::W:
    case VirtualKey::Up:
        m_playerState |= PLAYER_STATE_W;
        break;

    case VirtualKey::S:
    case VirtualKey::Down:
        m_playerState |= PLAYER_STATE_S;
        break;

    case VirtualKey::A:
    case VirtualKey::Left:
        m_playerState |= PLAYER_STATE_A;
        break;

    case VirtualKey::D:
    case VirtualKey::Right:
        m_playerState |= PLAYER_STATE_D;
        break;

    case VirtualKey::Space:
        m_playerState |= PLAYER_STATE_SPACE;
        break;

    case VirtualKey::Number1:
        m_weapon = Weapon::Regular;
        break;

    case VirtualKey::Number2:
        m_weapon = Weapon::Spread;
        break;

    case VirtualKey::Number3:
        m_weapon = Weapon::LaserWeapon;
        break;
    }
}

void Asteroids::OnKeyUp(CoreWindow^ sender, KeyEventArgs ^args)
{
    switch(args->VirtualKey)
    {
    case VirtualKey::W:
    case VirtualKey::Up:
        m_playerState &= ~PLAYER_STATE_W;
        break;

    case VirtualKey::S:
    case VirtualKey::Down:
        m_playerState &= ~PLAYER_STATE_S;
        break;

    case VirtualKey::A:
    case VirtualKey::Left:
        m_playerState &= ~PLAYER_STATE_A;
        break;

    case VirtualKey::D:
    case VirtualKey::Right:
        m_playerState &= ~PLAYER_STATE_D;
        break;

    case VirtualKey::Space:
        m_playerState &= ~PLAYER_STATE_SPACE;
        break;
    }
}

float Asteroids::ConvertDipsToPixels(float dips)
{
    static const float dipsPerInch = 96.0f;
    return floor(dips * DisplayProperties::LogicalDpi / dipsPerInch + 0.5f); // Round to nearest integer.
}

void Asteroids::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
    CoreWindow::GetForCurrentThread()->Activate();
}

void Asteroids::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
    // Save app state asynchronously after requesting a deferral. Holding a deferral
    // indicates that the application is busy performing suspending operations. Be
    // aware that a deferral may not be held indefinitely. After about five seconds,
    // the app will be forced to exit.
    SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();

    create_task([this, deferral]()
    {
        // Insert your code here.

        deferral->Complete();
    });
}

void Asteroids::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
    // Restore any data or state that was unloaded on suspend. By default, data
    // and state are persisted when resuming from suspend. Note that this event
    // does not occur if the app was previously terminated.
}

Asteroids::GameObject::GameObject(void) : m_angle(0), m_omega(0), m_scale(1, 1), m_lives(1), m_lifeTime(0.2f)
{
}

void Asteroids::GameObject::Update(float dt)
{
    //do semi-implicit euler
    m_vel += m_acc * dt;
    m_pos += m_vel * dt;
    m_angle += m_omega * dt;
    m_lifeTime -= dt;
}

glm::mat4 Asteroids::GameObject::TransformMatrix(void) const
{
    return glm::translate(glm::vec3(m_pos, 0)) * glm::rotate(m_angle, glm::vec3(0, 0, 1)) * glm::scale(glm::vec3(m_scale, 0));
}

static float MagnitudeSquared(float x, float y)
{
    return x * x + y * y;
}

static float MagnitudeSquared(const glm::vec2 &v)
{
    return MagnitudeSquared(v.x, v.y);
}

void Asteroids::Update()
{
    const float dt = 1.0f / 60;

    //handle input
    float radians = glm::radians(m_player.m_angle);
    if((m_playerState & PLAYER_STATE_W) && !(m_playerState & PLAYER_STATE_S))
        m_player.m_acc = glm::vec2(cos(radians), sin(radians)) * PLAYER_ACCELERATION;
    if((m_playerState & PLAYER_STATE_S) && !(m_playerState &PLAYER_STATE_W))
        m_player.m_acc = glm::vec2(cos(radians), sin(radians)) * -PLAYER_ACCELERATION;
    else if(!(m_playerState & PLAYER_STATE_S) && !(m_playerState &PLAYER_STATE_W))
        m_player.m_acc = glm::vec2();
    if(m_playerState & PLAYER_STATE_A)
        m_player.m_omega = TURN_SPEED;
    if(m_playerState & PLAYER_STATE_D)
        m_player.m_omega = -TURN_SPEED;
    if(!(m_playerState & PLAYER_STATE_A) && !(m_playerState & PLAYER_STATE_D))
        m_player.m_omega = 0;
    m_regularWeaponTimer -= dt;
    m_spreadWeaponTimer -= dt;
    m_laserWeaponTimer -= dt;
    if(m_playerState & PLAYER_STATE_SPACE)
        FireBullet();

    //move everything around
    m_player.Update(dt);
    GameObjectIter end = m_asteroids.end();
    for(GameObjectIter it = m_asteroids.begin(); it != end; ++it)
        it->Update(dt);
    end = m_bullets.end();
    for(GameObjectIter it = m_bullets.begin(); it != end; ++it)
        it->Update(dt);
    end = m_asteroidFallout.end();
    for(GameObjectIter it = m_asteroidFallout.begin(); it != end; ++it)
        it->Update(dt);

    //update the thrust particles
    end = m_rocketThrustParticles.end();
    for(GameObjectIter it = m_rocketThrustParticles.begin(); it != end;)
    {
        it->Update(dt);
        if(it->m_lifeTime <= 0)
        {
            it = m_rocketThrustParticles.erase(it);
            end = m_rocketThrustParticles.end();
        }
        else
            ++it;
    }
    if(m_rocketThrustParticles.size() < MAX_THRUST_PARTICLES)
    {
        --m_rocketThrust.m_emissionTimer;
        if(m_rocketThrust.m_emissionTimer <= 0)
        {
            GameObject particle;
            particle.m_color = glm::vec4(1, 0.4f, 0, 1);
            particle.m_lifeTime = (rand() % 1000) / 3000.0f + 0.1f;
            float radians = glm::radians(m_player.m_angle);
            glm::vec2 rearEnd = m_player.m_pos - glm::vec2(cos(radians), sin(radians)) * m_player.m_scale.x * 0.5f;
            particle.m_pos = rearEnd;
            radians = glm::radians(m_player.m_angle + (rand() % 6000) / 200.0f - 15);
            float velScale;
            if(m_playerState & PLAYER_STATE_W)
                velScale = (rand() % 1000) / 50.0f + 200.0f;
            else if(m_playerState & PLAYER_STATE_S)
                velScale = -((rand() % 1000) / 50.0f + 200.0f);
            else
                velScale = (rand() % 1000) / 50.0f + 50.0f;
            particle.m_vel = m_player.m_vel + -glm::vec2(cos(radians), sin(radians)) * velScale;
            particle.m_scale = glm::vec2(5);
            particle.m_omega = (rand() % 1000) / 5.0f - 100;
            m_rocketThrustParticles.push_back(particle);
            if(m_rocketThrustParticles.size() == MAX_THRUST_PARTICLES)
                m_rocketThrust.m_emissionTimer = THRUST_OUTPUT_RATE;
        }
    }

    //update the lasers
    for(LaserIter it = m_lasers.begin(); it != m_lasers.end();)
    {
        it->m_lifeTime -= dt;
        if(it->m_lifeTime <= 0)
            it = m_lasers.erase(it);
        else
            ++it;
    }

    //wrap player and asteroids to the other side of the universe if out of bounds
    WrapAround(m_player);
    end = m_asteroids.end();
    for(GameObjectIter it = m_asteroids.begin(); it != end; ++it)
        WrapAround(*it);

    //collide the asteroids and bullets using circles
    end = m_bullets.end();
    for(GameObjectIter it = m_bullets.begin(); it != end; )
    {
        GameObjectIter end2 = m_asteroids.end();
        for(GameObjectIter it2 = m_asteroids.begin(); it2 != end2;)
        {
            float radius1 = MagnitudeSquared(it->m_scale * 0.5f);
            float radius2 = MagnitudeSquared(it2->m_scale * 0.5f);
            float distance = MagnitudeSquared(it->m_pos - it2->m_pos);

            //they've collided so delete them
            if(radius1 + radius2 > distance)
            {
                it = m_bullets.erase(it);
                end = m_bullets.end();

                //split the asteroid into 4 smaller ones
                if(it2->m_lives == 2)
                {
                    int position = it2 - m_asteroids.begin();
                    GameObject asteroid;
                    float radians = glm::radians(glm::radians(it2->m_angle + 45));
                    glm::vec2 vel = it2->m_vel;
                    glm::vec2 pos = it2->m_pos;
                    glm::vec2 dir1(cos(radians), sin(radians));
                    glm::vec2 dir2(dir1.y, -dir1.x);
                    float scale = it2->m_scale.x;
                    float angle = it2->m_angle;
                    float omega = it2->m_omega;

                    asteroid.m_scale.x = asteroid.m_scale.y = scale * 0.5f;
                    asteroid.m_pos = pos + dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos + dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    it2 = m_asteroids.begin() + position;
                }
                else
                {
                    GameObject fallout;
                    fallout.m_pos = it2->m_pos;
                    fallout.m_scale = glm::vec2(5);
                    for(int i = 0; i < MAX_FALLOUT_PER_ASTEROID; ++i)
                    {
                        fallout.m_angle = static_cast<float>(rand() % 10000);
                        fallout.m_omega = (rand() % 1000) - 500.0f;
                        float radians = glm::radians(static_cast<float>(rand() % 10000));
                        fallout.m_vel = it2->m_vel + glm::vec2(cos(radians), sin(radians)) * (rand() % 100 + FALLOUT_INITIAL_VEL);
                        m_asteroidFallout.push_back(fallout);
                    }
                }
                it2 = m_asteroids.erase(it2);
                end2 = m_asteroids.end();
                if(it == end)
                    break;
            }
            else
                ++it2;
        }
        if(it != end)
            ++it;
    }

    //collide asteroid fallout and asteroids
    end = m_asteroidFallout.end();
    for(GameObjectIter it = m_asteroidFallout.begin(); it != end; )
    {
        if(it->m_lifeTime <= 0)
        {
            it = m_asteroidFallout.erase(it);
            end = m_asteroidFallout.end();
            continue;
        }
        GameObjectIter end2 = m_asteroids.end();
        for(GameObjectIter it2 = m_asteroids.begin(); it2 != end2;)
        {
            float radius1 = MagnitudeSquared(it->m_scale * 0.5f);
            float radius2 = MagnitudeSquared(it2->m_scale * 0.5f);
            float distance = MagnitudeSquared(it->m_pos - it2->m_pos);

            //they've collided so delete them
            if(radius1 + radius2 > distance)
            {
                it = m_asteroidFallout.erase(it);
                end = m_asteroidFallout.end();

                //split the asteroid into 4 smaller ones
                if(it2->m_lives == 2)
                {
                    int position = it2 - m_asteroids.begin();
                    GameObject asteroid;
                    float radians = glm::radians(glm::radians(it2->m_angle + 45));
                    glm::vec2 vel = it2->m_vel;
                    glm::vec2 pos = it2->m_pos;
                    glm::vec2 dir1(cos(radians), sin(radians));
                    glm::vec2 dir2(dir1.y, -dir1.x);
                    float scale = it2->m_scale.x;
                    float angle = it2->m_angle;
                    float omega = it2->m_omega;

                    asteroid.m_scale.x = asteroid.m_scale.y = scale * 0.5f;
                    asteroid.m_pos = pos + dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos + dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    it2 = m_asteroids.begin() + position;
                }
                else
                {
                    int index = it - m_asteroidFallout.begin();
                    GameObject fallout;
                    fallout.m_pos = it2->m_pos;
                    fallout.m_scale = glm::vec2(5);
                    for(int i = 0; i < MAX_FALLOUT_PER_ASTEROID; ++i)
                    {
                        fallout.m_angle = static_cast<float>(rand() % 10000);
                        fallout.m_omega = (rand() % 1000) - 500.0f;
                        float radians = glm::radians(static_cast<float>(rand() % 10000));
                        fallout.m_vel = it2->m_vel + glm::vec2(cos(radians), sin(radians)) * (rand() % 100 + FALLOUT_INITIAL_VEL);
                        m_asteroidFallout.push_back(fallout);
                    }
                    it = m_asteroidFallout.begin() + index;
                    end = m_asteroidFallout.end();
                }
                it2 = m_asteroids.erase(it2);
                end2 = m_asteroids.end();
                if(it == end)
                    break;
            }
            else
                ++it2;
        }
        if(it != end)
            ++it;
    }

    //collide the asteroids and lasers
    for(LaserIter it = m_lasers.begin(); it != m_lasers.end(); ++it)
    {
        if(!it->m_lethal)
            continue;
        for(GameObjectIter it2 = m_asteroids.begin(); it2 != m_asteroids.end();)
        {
            //project asteroid to laser direction
            glm::vec2 projectedPos = it->m_pos + glm::dot(it2->m_pos - it->m_pos, it->m_dir) / MagnitudeSquared(it->m_dir) * it->m_dir;
            if(it2->m_scale.x > glm::length(it2->m_pos - projectedPos) && glm::dot(projectedPos - it->m_pos, it->m_dir) >= 0)
            {
                //split the asteroid into 4 smaller ones
                if(it2->m_lives == 2)
                {
                    int position = it2 - m_asteroids.begin();
                    GameObject asteroid;
                    float radians = glm::radians(glm::radians(it2->m_angle + 45));
                    glm::vec2 vel = it2->m_vel;
                    glm::vec2 pos = it2->m_pos;
                    glm::vec2 dir1(cos(radians), sin(radians));
                    glm::vec2 dir2(dir1.y, -dir1.x);
                    float scale = it2->m_scale.x;
                    float angle = it2->m_angle;
                    float omega = it2->m_omega;

                    asteroid.m_scale.x = asteroid.m_scale.y = scale * 0.5f;
                    asteroid.m_pos = pos + dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir1 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir1 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos + dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel + dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    asteroid.m_pos = pos - dir2 * scale * 0.25f;
                    asteroid.m_angle = angle;
                    asteroid.m_omega = omega + (rand() % 1000) / 10.0f - 50;
                    asteroid.m_vel = vel - dir2 * DESTROYED_ASTEROID_SPEED;
                    m_asteroids.push_back(asteroid);

                    it2 = m_asteroids.begin() + position;
                }
                else
                {
                    GameObject fallout;
                    fallout.m_pos = it2->m_pos;
                    fallout.m_scale = glm::vec2(5);
                    for(int i = 0; i < MAX_FALLOUT_PER_ASTEROID; ++i)
                    {
                        fallout.m_angle = static_cast<float>(rand() % 10000);
                        fallout.m_omega = (rand() % 1000) - 500.0f;
                        float radians = glm::radians(static_cast<float>(rand() % 10000));
                        fallout.m_vel = it2->m_vel + glm::vec2(cos(radians), sin(radians)) * (rand() % 100 + FALLOUT_INITIAL_VEL);
                        m_asteroidFallout.push_back(fallout);
                    }
                }
                it2 = m_asteroids.erase(it2);
            }
            else
                ++it2;
        }
        it->m_lethal = false;
    }

    //keep the asteroids coming when the universe runs low
    if(m_asteroids.size() < MAX_ASTEROIDS)
    {
        --m_asteroidRespawnTime;
        if(m_asteroidRespawnTime <= 0)
        {
            for(unsigned i = m_asteroids.size(); i < MAX_ASTEROIDS; ++i)
            {
                GameObject asteroid;
                asteroid.m_pos.x = static_cast<float>(rand() % 10000);
                asteroid.m_pos.y = static_cast<float>(rand() % 10000);
                asteroid.m_angle = (rand() % 1000) / 10.0f - 50;
                asteroid.m_omega = (rand() % 1000) / 10.0f - 50;
                asteroid.m_vel.x = (rand() % 1000) / 10.0f - 50;
                asteroid.m_vel.y = (rand() % 1000) / 10.0f - 50;
                asteroid.m_scale = glm::vec2((rand() % 1000) / 20.0f + 50);
                asteroid.m_lives = 2;
                m_asteroids.push_back(asteroid);
            }
            m_asteroidRespawnTime = 30;
        }
    }
}

void Asteroids::Draw()
{
    glUseProgram(m_drawProgram);

    CoreWindow ^window = CoreWindow::GetForCurrentThread();
    float halfWindowWidth = window->Bounds.Width * 0.5f;
    float halfWindowHeight = window->Bounds.Height * 0.5f;
    glm::mat4 ortho = glm::ortho(-halfWindowWidth, halfWindowWidth, -halfWindowHeight, halfWindowHeight, -1.0f, 1.0f);

    glUniformMatrix4fv(m_uMvpDraw, 1, GL_FALSE, &ortho[0][0]);

    DrawPlayer();
    DrawAsteroids();
    DrawBullets();
    DrawRocket();

    const int stride = sizeof(glm::vec3) + sizeof(glm::vec4);
    glEnableVertexAttribArray(m_aPositionDraw);
    glEnableVertexAttribArray(m_aColorDraw);
    glVertexAttribPointer(m_aPositionDraw, 3, GL_FLOAT, GL_FALSE, stride, &m_vertexBuffer[0]);
    glVertexAttribPointer(m_aColorDraw, 4, GL_FLOAT, GL_FALSE, stride, &m_vertexBuffer[3]);

    bool swapDimensions =
        m_orientation == Windows::Graphics::Display::DisplayOrientations::Portrait ||
        m_orientation == Windows::Graphics::Display::DisplayOrientations::PortraitFlipped;

    for(int i = 0; i < 4; ++i)
    {
        if(swapDimensions)
            glViewport(0, 0, RENDER_TARGET_HEIGHT >> i, RENDER_TARGET_WIDTH >> i);
        else
            glViewport(0, 0, RENDER_TARGET_WIDTH >> i, RENDER_TARGET_HEIGHT >> i);
        glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i]);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_LINES, 0, m_vertexBuffer.size() / 7);
    }
    m_vertexBuffer.clear();
    DrawLasers();
    if(m_lasers.size())
    {
        glVertexAttribPointer(m_aPositionDraw, 3, GL_FLOAT, GL_FALSE, stride, &m_vertexBuffer[0]);
        glVertexAttribPointer(m_aColorDraw, 4, GL_FLOAT, GL_FALSE, stride, &m_vertexBuffer[3]);
        for(int i = 0; i < 4; ++i)
        {
            if(swapDimensions)
                glViewport(0, 0, RENDER_TARGET_HEIGHT >> i, RENDER_TARGET_WIDTH >> i);
            else
                glViewport(0, 0, RENDER_TARGET_WIDTH >> i, RENDER_TARGET_HEIGHT >> i);
            glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i]);
            glDrawArrays(GL_TRIANGLES, 0, m_vertexBuffer.size() / 7);
        }
    }
    m_vertexBuffer.clear();
    glDisableVertexAttribArray(m_aPositionDraw);
    glDisableVertexAttribArray(m_aColorDraw);

    float fullScreen[] = {
        -1, 1,
        -1, -1,
        1, 1,
        1, -1
    };

    glDisable(GL_BLEND);
    glUseProgram(m_blurProgram);
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(m_uTextureBlur, 0);
    glEnableVertexAttribArray(m_aPositionBlur);
    glVertexAttribPointer(m_aPositionBlur, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), fullScreen);
    for(int i = 0; i < 4; ++i)
    {
        int width = (swapDimensions) ? RENDER_TARGET_HEIGHT >> i : RENDER_TARGET_WIDTH >> i;
        int height = (swapDimensions) ? RENDER_TARGET_WIDTH >> i : RENDER_TARGET_HEIGHT >> i;
        glViewport(0, 0, width, height);

        glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i + 4]);
        glBindTexture(GL_TEXTURE_2D, m_offscreenTex[i]);
        glm::vec2 horiOffset(1.0f / width, 0.0f);
        glUniform2f(m_uOffsetBlur, horiOffset.x, horiOffset.y);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i]);
        glBindTexture(GL_TEXTURE_2D, m_offscreenTex[i + 4]);
        glm::vec2 vertOffset = glm::vec2(0.0f, 1.0f / height);
        glUniform2f(m_uOffsetBlur, vertOffset.x, vertOffset.y);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
    glDisableVertexAttribArray(m_aPositionBlur);
    glEnable(GL_BLEND);

    glViewport(0, 0, static_cast<int>(ConvertDipsToPixels(window->Bounds.Width)), static_cast<int>(ConvertDipsToPixels(window->Bounds.Height)));
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(m_bloomProgram);
    for(int i = 0; i < 4; ++i)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, m_offscreenTex[i]);
        glUniform1i(m_uTextureBloom[i], i);
    }
    glUniform1i(m_uTextureTexturePassThru, 0);
    glEnableVertexAttribArray(m_aPositionBloom);
    glVertexAttribPointer(m_aPositionBloom, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), fullScreen);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisableVertexAttribArray(m_aPositionBloom);

    eglSwapBuffers(m_esContext.eglDisplay, m_esContext.eglSurface);  
}

void Asteroids::WrapAround(GameObject &object)
{
    CoreWindow ^window = CoreWindow::GetForCurrentThread();
    float halfWindowWidth = window->Bounds.Width * 0.5f;
    float halfWindowHeight = window->Bounds.Height * 0.5f;

    if(object.m_pos.x - object.m_scale.x > halfWindowWidth)
        object.m_pos.x = -halfWindowWidth - object.m_scale.x * 0.5f;
    if(object.m_pos.x + object.m_scale.x < -halfWindowWidth)
        object.m_pos.x = halfWindowWidth + object.m_scale.x * 0.5f;

    if(object.m_pos.y - object.m_scale.y > halfWindowHeight)
        object.m_pos.y = -halfWindowHeight - object.m_scale.y * 0.5f;
    if(object.m_pos.y + object.m_scale.y < -halfWindowHeight)
        object.m_pos.y = halfWindowHeight + object.m_scale.y * 0.5f;
}

void Asteroids::FireBullet()
{
    if(m_weapon == Weapon::Regular)
    {
        if(m_regularWeaponTimer <= 0)
        {
            GameObject bullet;
            float radians = glm::radians(m_player.m_angle);
            glm::vec2 dir(cos(radians), sin(radians));
            bullet.m_pos = m_player.m_pos + dir * m_player.m_scale.x * 0.5f;
            bullet.m_scale = glm::vec2(10, 10);
            bullet.m_angle = m_player.m_angle;
            bullet.m_vel = dir * BULLET_SPEED + m_player.m_vel;
            m_bullets.push_back(bullet);
            m_regularWeaponTimer = REGULAR_WEAPON_COOLDOWN;
        }
    }
    else if(m_weapon == Weapon::Spread)
    {
        if(m_spreadWeaponTimer <= 0)
        {
            GameObject bullet;
            bullet.m_scale = glm::vec2(10, 10);
            bullet.m_angle = m_player.m_angle;
            for(int i = -2; i <= 2; ++i)
            {
                float radians = glm::radians(m_player.m_angle + i * 10);
                glm::vec2 dir(cos(radians), sin(radians));
                bullet.m_vel = dir * BULLET_SPEED + m_player.m_vel;
                bullet.m_pos = m_player.m_pos + dir * m_player.m_scale.x * 0.5f;
                m_bullets.push_back(bullet);
            }
            m_spreadWeaponTimer = SPREAD_WEAPON_COOLDOWN;
        }
    }
    else if(m_weapon == Weapon::LaserWeapon)
    {
        if(m_laserWeaponTimer <= 0)
        {
            Laser laser;
            laser.m_lifeTime = 2;
            float radians = glm::radians(m_player.m_angle);
            laser.m_dir = glm::vec2(cos(radians), sin(radians));
            laser.m_pos = m_player.m_pos + laser.m_dir * m_player.m_scale * 0.5f;
            laser.m_lethal = true;
            m_lasers.push_back(laser);
            m_laserWeaponTimer = LASER_WEAPON_COOLDOWN;
        }
    }
}

void Asteroids::RemoveOutOfBoundsBullets()
{
    CoreWindow ^window = CoreWindow::GetForCurrentThread();
    float halfWindowWidth = window->Bounds.Width * 0.5f;
    float halfWindowHeight = window->Bounds.Height * 0.5f;

    GameObjectIter end = m_bullets.end();
    for(GameObjectIter it = m_bullets.begin(); it != end;)
    {
        if(it->m_pos.x - it->m_scale.x > halfWindowWidth || it->m_pos.x + it->m_scale.x < halfWindowWidth ||
            it->m_pos.y - it->m_scale.y > halfWindowHeight || it->m_pos.y + it->m_scale.y < halfWindowHeight)
            it = m_bullets.erase(it);
        else
            ++it;
    }
}

static void FillVertexBuffer(std::vector<float> &buffer, const glm::vec3 &position, const glm::vec4 &color)
{
    buffer.insert(buffer.end(), &position.x, &position.x + 3);
    buffer.insert(buffer.end(), &color.x, &color.x + 4);
}

void Asteroids::DrawPlayer(void)
{
    glm::mat4 transform = m_player.TransformMatrix();
    glm::vec4 verts[] = {
        glm::vec4(0.5f, 0, 0, 1),
        glm::vec4(-0.5f, 0.3f, 0, 1),
        glm::vec4(-0.5f, 0.3f, 0, 1),
        glm::vec4(-0.2f, 0, 0, 1),
        glm::vec4(-0.2f, 0, 0, 1),
        glm::vec4(-0.5f, -0.3f, 0, 1),
        glm::vec4(-0.5f, -0.3f, 0, 1),
        glm::vec4(0.5f, 0, 0, 1),
    };
    for(int i = 0; i < sizeof(verts) / sizeof(*verts); ++i)
        FillVertexBuffer(m_vertexBuffer, glm::vec3(transform * verts[i]), glm::vec4(0, 1, 0, 1));
}

void Asteroids::DrawAsteroids(void)
{
    glm::vec4 verts[] = {
        glm::vec4(0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(0.5f, -0.5f, 0, 1),
        glm::vec4(0.5f, -0.5f, 0, 1),
        glm::vec4(0.5f, 0.5f, 0, 1),
    };
    GameObjectIter end = m_asteroids.end();
    for(GameObjectIter it = m_asteroids.begin(); it != end; ++it)
    {
        glm::mat4 transform = it->TransformMatrix();
        for(int i = 0; i < sizeof(verts) / sizeof(*verts); ++i)
            FillVertexBuffer(m_vertexBuffer, glm::vec3(transform * verts[i]), glm::vec4(1, 0, 0, 1));
    }

    end = m_asteroidFallout.end();
    for(GameObjectIter it = m_asteroidFallout.begin(); it != end; ++it)
    {
        glm::mat4 transform = it->TransformMatrix();
        for(int i = 0; i < sizeof(verts) / sizeof(*verts); ++i)
            FillVertexBuffer(m_vertexBuffer, glm::vec3(transform * verts[i]), glm::vec4(1, 0.7f, 0, 1));
    }
}

void Asteroids::DrawBullets(void)
{
    glm::vec4 verts[] = {
        glm::vec4(0.5f, 0, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(0.5f, 0, 0, 1),
    };
    GameObjectIter end = m_bullets.end();
    for(GameObjectIter it = m_bullets.begin(); it != end; ++it)
    {
        glm::mat4 transform = it->TransformMatrix();
        for(int i = 0; i < sizeof(verts) / sizeof(*verts); ++i)
            FillVertexBuffer(m_vertexBuffer, glm::vec3(transform * verts[i]), glm::vec4(0, 0.5f, 1, 1));
    }
}

void Asteroids::DrawRocket(void)
{
    glm::vec4 verts[] = {
        glm::vec4(0.5f, 0, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, 0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(-0.5f, -0.5f, 0, 1),
        glm::vec4(0.5f, 0, 0, 1),
    };
    GameObjectIter end = m_rocketThrustParticles.end();
    for(GameObjectIter it = m_rocketThrustParticles.begin(); it != end; ++it)
    {
        glm::mat4 transform = it->TransformMatrix();
        for(int i = 0; i < sizeof(verts) / sizeof(*verts); ++i)
            FillVertexBuffer(m_vertexBuffer, glm::vec3(transform * verts[i]), it->m_color);
    }
}

void Asteroids::DrawLasers(void)
{
    for(LaserIter it = m_lasers.begin(); it != m_lasers.end(); ++it)
    {
        glm::vec2 dir2(it->m_dir.y, -it->m_dir.x);
        glm::vec2 lowerRight(it->m_pos + dir2 * 10.0f);
        glm::vec2 upperRight(it->m_pos - dir2 * 10.0f);
        glm::vec2 lowerLeft(lowerRight + it->m_dir * 100000.0f); 
        glm::vec2 upperLeft(upperRight + it->m_dir * 100000.0f);
        float alpha = 1;
        if(it->m_lifeTime < 1)
            alpha = it->m_lifeTime;
        FillVertexBuffer(m_vertexBuffer, glm::vec3(lowerRight, 0), glm::vec4(0, 1, 1, alpha));
        FillVertexBuffer(m_vertexBuffer, glm::vec3(upperRight, 0), glm::vec4(0, 1, 1, alpha));
        FillVertexBuffer(m_vertexBuffer, glm::vec3(lowerLeft, 0), glm::vec4(0, 1, 1, alpha));
        FillVertexBuffer(m_vertexBuffer, glm::vec3(upperRight, 0), glm::vec4(0, 1, 1, alpha));
        FillVertexBuffer(m_vertexBuffer, glm::vec3(upperLeft, 0), glm::vec4(0, 1, 1, alpha));
        FillVertexBuffer(m_vertexBuffer, glm::vec3(lowerLeft, 0), glm::vec4(0, 1, 1, alpha));
    }
}

void Asteroids::CreateFBO(void)
{
    bool swapDimensions =
        m_orientation == DisplayOrientations::Portrait ||
        m_orientation == DisplayOrientations::PortraitFlipped;

    glGenFramebuffers(8, m_offscreenFBO);
    glGenTextures(8, m_offscreenTex);
    for(int i = 0; i < 4; ++i)
    {
        int width = (swapDimensions) ? RENDER_TARGET_HEIGHT >> i : RENDER_TARGET_WIDTH >> i;
        int height = (swapDimensions) ? RENDER_TARGET_WIDTH >> i : RENDER_TARGET_HEIGHT >> i;
        glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i]);
        glBindTexture(GL_TEXTURE_2D, m_offscreenTex[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_offscreenTex[i], 0);
        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            throw FBOIncompleteException();

        glBindFramebuffer(GL_FRAMEBUFFER, m_offscreenFBO[i + 4]);
        glBindTexture(GL_TEXTURE_2D, m_offscreenTex[i + 4]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_offscreenTex[i + 4], 0);
        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            throw FBOIncompleteException();
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
    return ref new Asteroids();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
    auto direct3DApplicationSource = ref new Direct3DApplicationSource();
    CoreApplication::Run(direct3DApplicationSource);
    return 0;
}
