/*
TODO
simple ball with graphics
    * dynamic ball 
    * grapgic window

walls for the playground
*/
#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#define SCALE 100

//Creating a world (global)
b2Vec2 gravity(0.0f, 0.0f);     //no gravity in x or y
b2World world(gravity);

void walls(){
    //Creating walls
    b2BodyDef body1;    
    b2BodyDef body2;    
    b2BodyDef body3;    
    b2BodyDef body4;    
    body1.position.Set(3.5f, 0.25f); //playground
    body2.position.Set(6.75f, 2.0f); //playground 
    body3.position.Set(3.5f, 3.75f); //playground 
    body4.position.Set(0.25f, 2.0f); //playground  

    b2Body* wall1 = world.CreateBody(&body1);  //create the body
    b2Body* wall2 = world.CreateBody(&body2);  //create the body
    b2Body* wall3 = world.CreateBody(&body3);  //create the body
    b2Body* wall4 = world.CreateBody(&body4);  //create the body

    b2PolygonShape groundBox1;   //create the shape
    groundBox1.SetAsBox(3.5f, 0.25f);   //

    b2PolygonShape groundBox2;   //create the shape
    groundBox2.SetAsBox(0.25f, 1.5f);   //

    //fixture
    b2FixtureDef wall_fix1;
    b2FixtureDef wall_fix2;
    wall_fix1.shape = &groundBox1;
    wall_fix1.restitution = 1;
    wall_fix2.shape = &groundBox2;
    wall_fix2.restitution = 1;
    
    wall1->CreateFixture(&wall_fix1);
    wall2->CreateFixture(&wall_fix2);
    wall3->CreateFixture(&wall_fix1);
    wall4->CreateFixture(&wall_fix2);
}

int main() {
    walls();
    //Create dynamic body (ball)
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(3.5f, 2.0f);
    
    b2Body* body = world.CreateBody(&bodyDef);  //Create the body
    
    //shape
    b2CircleShape player;
    player.m_p.Set(0.0f, 0.0f); //Position with respect to centre of shape
    player.m_radius = 0.1f;     //10 pixel
    
    //fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &player;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 1;
    
    body->CreateFixture(&fixtureDef);
    b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 0.0f));
    b2Vec2 f (0.0f, 2.0f);
    body->ApplyForce(f, p, true);

    //simulation
    //Let's start simulation
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    // The GUI 
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");    //Window
    // The ball
    sf::CircleShape ball(10.f);
    ball.setFillColor(sf::Color::Green);
    
    
    // The walls
    sf::RectangleShape rectangle1(sf::Vector2f(700.f, 50.f));
    sf::RectangleShape rectangle2(sf::Vector2f(50.f, 300.f));
    sf::RectangleShape rectangle3(sf::Vector2f(700.f, 50.f));
    sf::RectangleShape rectangle4(sf::Vector2f(50.f, 300.f));
    
    rectangle1.setPosition(0,0);
    rectangle2.setPosition(650, 50);
    rectangle3.setPosition(0,350);
    rectangle4.setPosition(0,50);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f  %4.2f\n", position.x, position.y);
        
        ball.setPosition(position.x*SCALE, position.y*SCALE);
        
        window.clear();
        window.draw(ball);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.display();
    }
    //clean the world
    //world->DestroyBody(body);
    return 0;
}
